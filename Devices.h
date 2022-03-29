/*
 * This class implements devices for passengers, which helps to work with PassengerGateway through it.
 */
#ifndef TAXI_DEVICES_H
#define TAXI_DEVICES_H
#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#include "CoordinateSystem.h"
#include "Car.h"
#include "CarTypes.h"
#include "Users.h"
#include "PassengerGateway.h"
using namespace std;

class Devices {
    string name;
    Passenger* passenger;
    bool inUse;
public:
    Devices(string deviceName);
    void connectToUser(Passenger* pas);
    void login(string userID, string userPassword);
    void changePaymentMethod(paymentMethod method);
    void addPin(CoordinateSystem address);
    void printPinnedAddresses();
    CoordinateSystem getPinnedAddress(int index);
    void deletePinnedAddress(int index);
    pair<int,int> preorder(CoordinateSystem from, CoordinateSystem to, CarTypes carType);
    void order(CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime);
    void order(CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime, paymentMethod method);
    void order(CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime, bool specialOption);
    void order(CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime, paymentMethod method, bool specialOption);
    void printLastOrder();
    void printAllOrders();
    void askBillForLastOrder();
    void printCoordinatesInTrip();
};


#endif //TAXI_DEVICES_H
