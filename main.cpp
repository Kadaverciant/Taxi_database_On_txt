#include <iostream>
#include <ctime>
#include <windows.h>
#include "CoordinateSystem.h"
#include "PassengerGateway.h"
#include "DriverGateway.h"
#include "DataBase.h"
#include "Devices.h"
using namespace std;

int main() {

    //use local time in order to generate orders online)
    time_t now = time(0);
    now=time(0);

    //import data
    DataBase::importUsers();
    DataBase::importPinnedAddresses();
    DataBase::importOrders();

    //initialise admin
    Admin admin1("Vsevolod","Kiaver","123qwe123");
    AdminGateway::login(admin1,"Kiaver","123qwe123");

    //initialise some coordinates, that we'll work with
    CoordinateSystem from(12,34,"Metro");
    CoordinateSystem to (206, 159,"Ozon");

    //initialise some cars and drivers
    Car tempCar1("volvo", "123", from, "white", economy);
    Driver driver1("Munir", 4.5, "munir", "mmunir");
    Car tempCar2("BMW", "777", from, "black", business);
    Car tempCar3("Nissan","666",from,"yellow",comfortPlus);
    Driver driver2("Ivan", 5.0, "iivan", "12331");

    //initialise some passengers, some of them with special payment method
    Passenger passenger1("Petr", 3.5, "petr", "ppetr");
    Passenger passenger2("Mike", 5.0, "mmedved", "111", card);
    Passenger passenger3("Lida", 2.0, "chsv", "666");



    //now using gateways lets login our users. If they login 1st time a new accaunt would be created
    //try wrong password
    PassengerGateway::login(passenger1, "petr", "petr");
    //and correct one
    PassengerGateway::login(passenger1, "petr", "ppetr");
    PassengerGateway::login(passenger2, "mmedved", "111");
    DriverGateway::login(driver1, "munir", "mmunir");
    DriverGateway::login(driver2, "iivan", "12331");
    //try to login 2nd time
    DriverGateway::login(driver2, "iivan", "12331");
    cout<<endl;

    //try to print coordinates in trip (if it is first run, you'll see that passenger1 is not in trip)
    PassengerGateway::printCoordinatesInTrip(passenger1);
    cout<<endl;

    //connect car and driver (needed only at first time, later we may comment this line, or leave ir, because only cars with new numbers would be accepted)
    DriverGateway::addCar(driver1,&tempCar1);
    DriverGateway::addCar(driver2,&tempCar3);
    //add second car to driver2. Information about all cars would be stored in data-base
    DriverGateway::addCar(driver2,&tempCar2);

    //now we need to validate that cars for driver, without it car won't be found by system when it generate an order.
    AdminGateway::validateAllCars(admin1,driver1);
    AdminGateway::validateAllCars(admin1,driver2);
    cout<<endl;

    //adding pin address to a user
    PassengerGateway::addPin(passenger1, from);
    PassengerGateway::printPinnedAddresses(passenger1);
    cout<<endl;

    //changing default payment method
    PassengerGateway::changePaymentMethod(passenger1, card);
    cout<<endl;

    //check preorder function. On fist we will have time in min, at 2nd cost of trip
    cout << PassengerGateway::preorder(passenger1, from, to, economy).first << ' ' << PassengerGateway::preorder(passenger1, from, to, economy).second << endl;
    cout << PassengerGateway::preorder(passenger1, from, to, economy).first << ' ' << PassengerGateway::preorder(passenger1, from, to, business).second << endl;
    cout<<endl;

    //check blocking abilities (information about blocked users would be stored with all info about user)
    AdminGateway::blockPassenger(admin1,passenger1);
    cout<<endl;

    //try to order an economy car with special function
    PassengerGateway::order(passenger1, from, to, economy, now, true);

    //unblock user and try again
    AdminGateway::unblockPassenger(admin1,passenger1);
    PassengerGateway::order(passenger1, from, to, economy, now, true);
    cout<<endl;

    //check blocking abilities on drivers (their cars won't be found)
    AdminGateway::blockDriver(admin1,driver2);
    cout<<endl;

    //try to order an business car with special function, but we know, that our driver with business car is blocked
    PassengerGateway::order(passenger2, from, to, business, now, true);
    AdminGateway::unblockDriver(admin1,driver2);
    //try to order an business car with special function, now all will be ok
    PassengerGateway::order(passenger2, from, to, business, now, true);
    cout<<endl;

    //make order with pin address
    CoordinateSystem c=PassengerGateway::getPinnedAddress(passenger1, 0);
    PassengerGateway::order(passenger1, c, to, economy, now);
    cout<<endl;

    //try to make order with our knowledge that all economy drivers are busy + check if we can use special pay method for that trip
    PassengerGateway::order(passenger1, from, to, economy, now, cash);
    cout<<endl;

    //try to make order later, when driver would be free
    PassengerGateway::order(passenger1, from, to, economy, now + 319 * 60 + 1);
    cout<<endl;

    //look last order and all history of some users
    cout<<endl;
    passenger1.printLastOrder();
    cout<<endl;
    passenger2.printLastOrder();
    cout<<endl;
    passenger1.printAllHistory();
    cout<<endl;
    //try to see order history of user without orders at all
    passenger3.printAllHistory();
    cout<<endl;
    cout<<endl;

    //now lets check how devices for passengers works
    Devices device1("Phone 1");
    device1.connectToUser(&passenger1);

    //try to make order with our knowledge that all economy drivers are busy using device
    device1.order(from, to, economy, now);
    cout<<endl;

    //try to make order later, when driver would be free using device
    device1.order(from, to, economy, now + 700 * 60 + 1);
    cout<<endl;

    //try to use any commant for unconnected device
    Devices device2("Phone 2");
    device2.printLastOrder();
    cout<<endl;

    //now connect device to same passenger as for Phone 1 and ask the same commands
    device2.connectToUser(&passenger1);
    device2.order(from, to, economy, now);
    cout<<endl;

    //check coordinates in trip
    device2.printCoordinatesInTrip();
    device2.printLastOrder();
    cout<<endl;

    //check ask of bill
    device2.askBillForLastOrder();
    cout<<endl;

    //check reconnection and call to same function ask bill for person without orders
    device2.connectToUser(&passenger3);
    device2.askBillForLastOrder();

    //Show the possibility of admin to get data
    AdminGateway::printNumberOfUsers(admin1);
    AdminGateway::printAllUsers(admin1);
    AdminGateway::printAllCars(admin1);
    AdminGateway::printAllHistory(admin1);

    //export data
    DataBase::exportOrders();
    DataBase::exportUsers();
    DataBase::exportPinnedAddresses();

}
