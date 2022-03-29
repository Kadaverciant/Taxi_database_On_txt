//
// Created by Vsevolod Klushev on 04.04.2021.
//

#include "Users.h"
#include "DriverGateway.h"
#include "PassengerGateway.h"

#include <utility>
#include <sstream>

Users::Users(string personName, double personRating, string personID, string personPassword) {
    name=std::move(personName);
    rating=personRating;
    id=std::move(personID);
    password=std::move(personPassword);
    isLogin=false;
    isBlocked= false;
}

void Users::printHistoryAtIndex(int index) {
    string tempString=orderHistory[index];
    stringstream stream(tempString);
    string pasID;
    string driID;
    string temp;
    string from;
    string to;
    int startYear;
    int startMonth;
    int startDay;
    int startHour;
    int startMin;
    int endYear;
    int endMonth;
    int endDay;
    int endHour;
    int endMin;
    string color;
    string model;
    string number;
    int carType;
    int payMethod;
    int cost;

    stream>>pasID>>driID>>temp>>temp>>from>>temp>>temp>>to>>startYear>>startMonth>>startDay>>startHour>>startMin
          >>endYear>>endMonth>>endDay>>endHour>>endMin>>color>>model>>number>>carType>>payMethod>>cost;

    string sMonth;
    if (startMonth<10) {
        sMonth='0'+to_string(startMonth);
    } else {
        sMonth=to_string(startMonth);
    }
    string sDay;
    if (startDay<10) {
        sDay='0'+to_string(startDay);
    } else {
        sDay=to_string(startDay);
    }
    string sHour;
    if (startHour<10) {
        sHour='0'+to_string(startHour);
    } else {
        sHour=to_string(startHour);
    }
    string sMin;
    if (startMin<10) {
        sMin='0'+to_string(startMin);
    } else {
        sMin=to_string(startMin);
    }

    string eMonth;
    if (endMonth<10) {
        eMonth='0'+to_string(endMonth);
    } else {
        eMonth=to_string(endMonth);
    }
    string eDay;
    if (endDay<10) {
        eDay='0'+to_string(endDay);
    } else {
        eDay=to_string(endDay);
    }
    string eHour;
    if (endHour<10) {
        eHour='0'+to_string(endHour);
    } else {
        eHour=to_string(endHour);
    }
    string eMin;
    if (endMin<10) {
        eMin='0'+to_string(endMin);
    } else {
        eMin=to_string(endMin);
    }
    cout<<"From: "<<from<<" To: "<<to<<endl;
    cout<<"Start: "<<startYear<<'/'<<sMonth<<'/'<<sDay<<' '<<sHour<<':'<<sMin<<endl;
    cout<<"End: "<<startYear<<'/'<<eMonth<<'/'<<eDay<<' '<<eHour<<':'<<eMin<<endl;
    cout<<"Details: "<<endl;
    cout<<"Passenger ID: "<<pasID<<endl;
    cout<<"Driver ID: "<<driID<<endl;
    cout<<"Car info: "<<color<<' '<<model<<' '<<number<<' ';

    if (carType==1)
        cout<<"economy";
    if (carType==2)
        cout<<"comfort";
    if (carType==3)
        cout<<"comfort plus";
    if (carType==4)
        cout<<"business";
    cout<<endl;
    cout<<"Payment details: "<<cost<<" rub paid by ";

    if (payMethod==0)
        cout<<"card";
    if (payMethod==1)
        cout<<"cash";
    cout<<endl;
}

void Users::printAllHistory() {
    if(!orderHistory.empty()) {
        for (int i=0;i<orderHistory.size();i++) {
            printHistoryAtIndex(i);
        }
    } else {
        cout<<name<<": "<<"Your history is empty"<<endl;
    }
}

void Users::printLastOrder() {
    if(!orderHistory.empty()) {
        printHistoryAtIndex(orderHistory.size() - 1);
    } else {
        cout<<name<<": "<<"Your history is empty"<<endl;
    }

}

void Users::askBillForLastOrder() {
    if(!orderHistory.empty()) {
        cout<<"Wendex bank present your bill: "<<endl;
        printHistoryAtIndex(orderHistory.size()-1);
    } else {
        cout<<name<<": "<<"Your history is empty"<<endl;
    }

}

Passenger::Passenger(string personName, double personRating, string personID, string personPassword, paymentMethod personPaymentMethod) : Users(
        std::move(personName), personRating, std::move(personID), std::move(personPassword)) {
    pay=personPaymentMethod;
    endOfLastOrder=time(0);
}

Passenger::Passenger(string personName, double personRating, string personID, string personPassword) : Users(std::move(personName),
                                                                                                             personRating,
                                                                                                             std::move(personID),
                                                                                                             std::move(personPassword)) {
    pay=cash;//payment method by default;
    endOfLastOrder=time(0);
}

void Passenger::addPin(CoordinateSystem address) {
    if (isLogin) {
        bool need= true;
        for (int i=0; i<pinnedAddresses.size(); i++) {
            if (pinnedAddresses[i].getCurrentAddress()==address.getCurrentAddress())
                need=false;
        }
        if (need) {
            pinnedAddresses.push_back(address);
            cout<<name<<": "<<"new pinned address was added."<<endl;
        } else {
            cout<<name<<": address already pinned"<<endl;
        }
    } else {
        cout<<name<<": "<<"You are not login"<<endl;
    }
}

void Passenger::changePaymentMethod(paymentMethod method) {
    if (isLogin) {
        if (pay==method) {
            cout<<name<<": "<<"This payment method is already default"<<endl;
        } else {
            pay=method;
            cout<<name<<": "<<"Default payment method was changed"<<endl;
        }
    } else {
        cout<<name<<": "<<"You are not login"<<endl;
    }

}

void Passenger::printPinnedAddresses() {
    if (isLogin) {
        cout<<name<<"'s pinned addresses"<<endl;
        cout<<"Number of addresses "<<pinnedAddresses.size()<<endl;
        for (int i=0; i<pinnedAddresses.size();i++) {
            cout << i + 1 << ": ";
            pinnedAddresses[i].printLocation();
            cout<<endl;
        }
    } else {
        cout<<name<<": "<<"You are not login"<<endl;
    }
}

void Passenger::deletePinnedAddress(int index) {
    if (isLogin) {
        if (index<=pinnedAddresses.size()) {
            pinnedAddresses.erase(pinnedAddresses.begin()+index-1);
        }
        cout<<name<<": "<<" Pinned address deleted successfully"<<endl;
    }   else {
        cout<<name<<": "<<"You are not login"<<endl;
    }
}

CoordinateSystem Passenger::getPinnedAddress(int index) {
    return pinnedAddresses[index];
}

void Passenger::getCoordinatesDuringTrip() {
    if (isLogin) {
        cout<<name<<" your location is: ";
        lastAdrInTrip.printLocation();
    }   else {
        cout<<name<<": "<<"You are not login"<<endl;
    }
}


Driver::Driver(string personName, double personRating, string personID, string personPassword,  Car &tempCar) : Users(
        std::move(personName), personRating, std::move(personID), std::move(personPassword)){
    lastWork=time(0);
    car = &tempCar;
}

Driver::Driver(string personName, double personRating, string personID, string personPassword) : Users(
        std::move(personName), personRating, std::move(personID), std::move(personPassword)){
    lastWork=time(0);
}

status Driver::getDriverStatusAtTime(time_t callTime) {
    if (callTime<lastWork)
        return in_ride;
    return working;
}

Driver::Driver(string personName, double personRating, string personID, string personPassword, time_t time,
               Car &tempCar) : Users(
        std::move(personName), personRating, std::move(personID), std::move(personPassword)){
    lastWork=time;
    car = &tempCar;
}
Driver::Driver(string personName, double personRating, string personID, string personPassword, time_t time
               ) : Users(
        std::move(personName), personRating, std::move(personID), std::move(personPassword)){
    lastWork=time;
}

void Driver::addCar(Car* tempCar) {
    bool need=true;
    for (int i=0; i<cars.size(); i++) {
        if (cars[i]->getNumber()==tempCar->getNumber())
            need=false;
    }
    if (need)
        cars.push_back(tempCar);
}


void Admin::blockPassenger(Passenger &passenger) {
    if (isLogin) {
        passenger.isBlocked= true;
    } else {
        cout<<name<<": "<<"You are not login"<<endl;
    }
}



void Admin::blockDriver(Driver &driver) {
    if (isLogin) {
        driver.isBlocked=true;
    } else {
        cout<<name<<": "<<"You are not login"<<endl;
    }
}

void Admin::validateCar(Car* car) {
    if (isLogin) {
        car->isValid= true;
    } else {
        cout<<name<<": "<<"You are not login"<<endl;
    }
}

Admin::Admin(string personName, string personID, string personPassword) : Users(std::move(personName),
                                                                                                     10,
                                                                                                     std::move(personID),
                                                                                                     std::move(personPassword)) {

}

void Admin::unblockPassenger(Passenger &passenger) {
    if (isLogin) {
        passenger.isBlocked= false;
    } else {
        cout<<name<<": "<<"You are not login"<<endl;
    }
}

void Admin::unblockDriver(Driver &driver) {
    if (isLogin) {
        driver.isBlocked=false;
    } else {
        cout<<name<<": "<<"You are not login"<<endl;
    }
}

void Admin::printNumberOfUsers() {
    if (isLogin) {
        cout<<name<<": Number of users that are using WEndex taxi - "<<DriverGateway::loggedDrivers.size() +
                    DriverGateway::notLoggedDrivers.size() + PassengerGateway::loggedPassengers.size() +
                    PassengerGateway::notLoggedPassengers.size()<<endl;
    } else {
        cout<<name<<": "<<"You are not login"<<endl;
    }
}

void Admin::printAllUsers() {
    if (isLogin) {
        cout<<endl<<name<<": users in system are: "<<endl;
        for (int i=0; i<DriverGateway::loggedDrivers.size(); i++) {
            cout<<DriverGateway::loggedDrivers[i]->name<<' '<<DriverGateway::loggedDrivers[i]->id<<endl;
        }
        for (int i=0; i<DriverGateway::notLoggedDrivers.size(); i++) {
            cout<<DriverGateway::notLoggedDrivers[i].name<<' '<<DriverGateway::notLoggedDrivers[i].id<<endl;
        }
        for (int i=0; i<PassengerGateway::loggedPassengers.size(); i++) {
            cout<<PassengerGateway::loggedPassengers[i]->name<<' '<<PassengerGateway::loggedPassengers[i]->id<<endl;
        }
        for (int i=0; i<PassengerGateway::notLoggedPassengers.size(); i++) {
            cout<<PassengerGateway::notLoggedPassengers[i].name<<' '<<PassengerGateway::notLoggedPassengers[i].id<<endl;
        }
    } else {
        cout<<name<<": "<<"You are not login"<<endl;
    }
}

void Admin::printAllCars() {
    if (isLogin) {
        cout<<endl<<name<<": cars in system are: "<<endl;
        for (int i=0; i<DriverGateway::loggedDrivers.size(); i++) {
            for (int j=0; j<DriverGateway::loggedDrivers[i]->cars.size(); j++) {
                cout<<DriverGateway::loggedDrivers[i]->cars[j]->getModel()<<' '<<DriverGateway::loggedDrivers[i]->cars[j]->getNumber()<<' ';
                if (DriverGateway::loggedDrivers[i]->cars[j]->getCarType()==economy)
                    cout<<"economy"<<endl;
                if (DriverGateway::loggedDrivers[i]->cars[j]->getCarType()==comfort)
                    cout<<"comfort"<<endl;
                if (DriverGateway::loggedDrivers[i]->cars[j]->getCarType()==comfortPlus)
                    cout<<"comfort Plus"<<endl;
                if (DriverGateway::loggedDrivers[i]->cars[j]->getCarType()==business)
                    cout<<"business;"<<endl;
            }
        }
        for (int i=0; i<DriverGateway::notLoggedDrivers.size(); i++) {
            for (int j=0; j<DriverGateway::notLoggedDrivers[i].cars.size(); j++) {
                cout<<DriverGateway::notLoggedDrivers[i].cars[j]->getModel()<<' '<<DriverGateway::notLoggedDrivers[i].cars[j]->getNumber()<<' ';
                if (DriverGateway::notLoggedDrivers[i].cars[j]->getCarType()==economy)
                    cout<<"economy"<<endl;
                if (DriverGateway::notLoggedDrivers[i].cars[j]->getCarType()==comfort)
                    cout<<"comfort"<<endl;
                if (DriverGateway::notLoggedDrivers[i].cars[j]->getCarType()==comfortPlus)
                    cout<<"comfort Plus"<<endl;
                if (DriverGateway::notLoggedDrivers[i].cars[j]->getCarType()==business)
                    cout<<"business;"<<endl;
            }
        }
    } else {
        cout<<name<<": "<<"You are not login"<<endl;
    }
}

void Admin::printAllHistoryForUsers() {
    if (isLogin) {
        cout<<endl<<name<<": all orders in system are: "<<endl;
        for (int i=0; i<DriverGateway::loggedDrivers.size(); i++) {
            cout<<DriverGateway::loggedDrivers[i]->name<<' '<<DriverGateway::loggedDrivers[i]->id<<endl;
            DriverGateway::loggedDrivers[i]->printAllHistory();
        }
        for (int i=0; i<DriverGateway::notLoggedDrivers.size(); i++) {
            cout<<DriverGateway::notLoggedDrivers[i].name<<' '<<DriverGateway::notLoggedDrivers[i].id<<endl;
            DriverGateway::notLoggedDrivers[i].printAllHistory();
        }
        for (int i=0; i<PassengerGateway::loggedPassengers.size(); i++) {
            cout<<PassengerGateway::loggedPassengers[i]->name<<' '<<PassengerGateway::loggedPassengers[i]->id<<endl;
            PassengerGateway::loggedPassengers[i]->printAllHistory();
        }
        for (int i=0; i<PassengerGateway::notLoggedPassengers.size(); i++) {
            cout<<PassengerGateway::notLoggedPassengers[i].name<<' '<<PassengerGateway::notLoggedPassengers[i].id<<endl;
            PassengerGateway::notLoggedPassengers[i].printAllHistory();
        }
    } else {
        cout<<name<<": "<<"You are not login"<<endl;
    }
}

