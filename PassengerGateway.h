/*
 * This static class implements Gateway for passengers, which helps to work with database, system and passengers.
 */
#ifndef TAXI_PASSENGERGATEWAY_H
#define TAXI_PASSENGERGATEWAY_H
#include <iostream>
#include "Users.h"
#include <cmath>
using namespace std;
class Admin;
class Users;
class DataBase;

class PassengerGateway {
    friend Admin;
    friend DataBase;
    static inline vector<Passenger*> loggedPassengers = vector<Passenger*>();
    static inline vector<Passenger> notLoggedPassengers = vector<Passenger>();
public:

    static void login(Passenger& passenger, string userID, string userPassword);
    static void changePaymentMethod(Passenger& passenger, paymentMethod method);
    static void addPin(Passenger& passenger, CoordinateSystem address);
    static void printPinnedAddresses(Passenger& passenger);
    static CoordinateSystem getPinnedAddress(Passenger& passenger, int index);
    static void deletePinnedAddress(Passenger& passenger, int index);
    static pair<int,int> preorder(Passenger& passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType);
    static void order(Passenger& passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime);
    static void order(Passenger& passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime, paymentMethod method);
    static void order(Passenger& passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime, bool specialOption);
    static void order(Passenger& passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime, paymentMethod method, bool specialOption);
    static void printCoordinatesInTrip(Passenger& passenger);
};


#endif //TAXI_PASSENGERGATEWAY_H
