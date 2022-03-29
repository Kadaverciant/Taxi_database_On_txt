/*
 * This static class implements Gateway for drivers, which helps to work with database, system and drivers.
 */
#ifndef TAXI_DRIVERGATEWAY_H
#define TAXI_DRIVERGATEWAY_H
#include <iostream>
#include "Users.h"
using namespace std;
class System;
class DataBase;
class Admin;

class DriverGateway {
public:
    friend Admin;
    friend DataBase;
    friend PassengerGateway;
    static inline vector<Driver*> loggedDrivers = vector<Driver*>();
    static inline vector<Driver> notLoggedDrivers = vector<Driver>();
public:
    static void login(Driver& driver, string userID, string userPassword);
    static void addCar(Driver& driver, Car* tempCar);
    static Driver* findFreeDriver(CarTypes carType, time_t callTime);
    static bool thereIsFreeDriver(CarTypes carType, time_t callTime);
};


#endif //TAXI_DRIVERGATEWAY_H
