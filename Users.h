/*
 * This class implements Users, and such derived classes as drivers passengers that we are working with.
 */
#ifndef TAXI_USERS_H
#define TAXI_USERS_H
#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#include "CoordinateSystem.h"
#include "Car.h"
#include "CarTypes.h"
using namespace std;

class System;
class AdminGateway;
class PassengerGateway;
class DriverGateway;
class Passenger;
class DataBase;
class Admin;

enum paymentMethod{
    card,
    cash
};

enum status{
    working,
    not_working,
    in_ride
};

class Users {
private:
    friend DataBase;
    friend System;
    friend PassengerGateway;
    friend DriverGateway;
    friend AdminGateway;
    friend Passenger;
    friend Admin;
    string name;
    double rating;
    string id;
    string password;
    vector<string> orderHistory;
    bool isLogin;
    bool isBlocked;
    void printHistoryAtIndex(int index);
protected:
    Users(string personName, double personRating, string personID, string personPassword);
public:
    void printAllHistory();
    void printLastOrder();
    void askBillForLastOrder();
};

class Passenger : public Users {
    friend DataBase;
    friend System;
    friend PassengerGateway;
    friend Admin;
    paymentMethod pay;
    time_t endOfLastOrder;
    vector<CoordinateSystem> pinnedAddresses;
    void changePaymentMethod(paymentMethod method);
    void addPin(CoordinateSystem address);
    void printPinnedAddresses();
    CoordinateSystem getPinnedAddress(int index);
    CoordinateSystem lastAdrInTrip;
    void deletePinnedAddress(int index);
    void getCoordinatesDuringTrip();
public:
    Passenger(string personName, double personRating, string personID, string personPassword, paymentMethod personPaymentMethod);
    Passenger(string personName, double personRating, string personID, string personPassword);
};

class Driver : public Users {
    friend DataBase;
    friend System;
    friend DriverGateway;
    friend AdminGateway;
    friend Admin;
    time_t lastWork;
    status driverStatus;
    vector<Car*> cars;
    Car *car;
    void addCar(Car* tempCar);
public:
    time_t getlastWork() {
        return lastWork;
    }
    status getDriverStatusAtTime(time_t callTime);
    Driver(string personName, double personRating, string personID, string personPassword, Car &tempCar);
    Driver(string personName, double personRating, string personID, string personPassword, time_t time, Car &tempCar);
    Driver(string personName, double personRating, string personID, string personPassword);
    Driver(string personName, double personRating, string personID, string personPassword, time_t time);
};

class Admin : public Users {
    friend DataBase;
    friend System;
    friend AdminGateway;
    void blockPassenger(Passenger& passenger);
    void blockDriver(Driver& driver);
    void unblockPassenger(Passenger& passenger);
    void unblockDriver(Driver& driver);
    void validateCar(Car* car);
    void printNumberOfUsers();
    void printAllUsers();
    void printAllCars();
    void printAllHistoryForUsers();
public:
    Admin(string personName, string personID, string personPassword);
};


#endif //TAXI_USERS_H
