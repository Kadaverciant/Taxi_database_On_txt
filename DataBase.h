/*
 * This static class implements database that import and export data.
 * It uses files:
 * Users.txt to store users
 * Database.txt to store orders
 * Pinned.txt to store pinned addresses
 */

#ifndef TAXI_DATABASE_H
#define TAXI_DATABASE_H

#include <iostream>
#include <ctime>
#include <windows.h>
#include "CoordinateSystem.h"
#include "PassengerGateway.h"
#include "DriverGateway.h"
#include "AdminGateway.h"
using namespace std;

class DataBase {
public:
    static void importUsers();
    static void importOrders();
    static void importPinnedAddresses();
    static void exportOrders();
    static void exportUsers();
    static void exportPinnedAddresses();
};


#endif //TAXI_DATABASE_H
