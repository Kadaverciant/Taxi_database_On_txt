/*
 * This static class implements Gateway for admins, which helps to work with database, system and admins.
 */
#ifndef TAXI_ADMINGATEWAY_H
#define TAXI_ADMINGATEWAY_H
#include <iostream>
#include "Users.h"
#include <cmath>
using namespace std;
class Users;
class DataBase;

class AdminGateway {
    friend DataBase;
    static inline vector<Admin*> loggedAdmins = vector<Admin*>();
    static inline vector<Admin> notLoggedAdmins = vector<Admin>();
public:
    static void login(Admin& admin, string userID, string userPassword);
    static void validateAllCars(Admin& admin, Driver& driver);
    static void blockPassenger(Admin& admin, Passenger& passenger);
    static void blockDriver(Admin& admin, Driver& driver);
    static void unblockPassenger(Admin& admin, Passenger& passenger);
    static void unblockDriver(Admin& admin, Driver& driver);
    static void printNumberOfUsers(Admin& admin);
    static void printAllUsers(Admin& admin);
    static void printAllCars(Admin& admin);
    static void printAllHistory(Admin& admin);
};


#endif //TAXI_ADMINGATEWAY_H
