/*
 * This static class implements system, which perform all orders.
 */

#ifndef TAXI_SYSTEM_H
#define TAXI_SYSTEM_H
#include "PassengerGateway.h"
#include "DriverGateway.h"

class System {
    friend PassengerGateway;
    friend DriverGateway;
    public:
    static void order(Passenger &passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime);
    static void order(Passenger &passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime, paymentMethod method);
    static void vipOrder(Passenger &passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime, bool specialOption);
    static void vipOrder(Passenger &passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime, paymentMethod method, bool specialOption);
};


#endif //TAXI_SYSTEM_H
