/*
 * This class implements car, it works with coordinates as well.
 * Car has model, number, color, type, coordinates and number of bottles.
 */
#ifndef TAXI_CAR_H
#define TAXI_CAR_H
#include <iostream>
#include "CoordinateSystem.h"
#include "CarTypes.h"
using namespace std;

class Admin;

class Car {
    friend Admin;
private:
    string model;
    string number;
    string color;
    CoordinateSystem currentAddress;
    CarTypes carType;
    int freeBottles;
    bool isValid;
public:
    Car(string carModel, string carNumber, CoordinateSystem carAddress, string carColor, CarTypes typeOfCar);
    string getModel();
    string getNumber();
    string getColor();
    bool getValidity();
    CoordinateSystem getCurrentAddressOfCar();
    void setCurrentAddressOfCar(CoordinateSystem address);
    CarTypes getCarType();
    int getNumberOfBottles();
    void useBottles();
};

class Economy : public Car{
public:
    Economy(string carModel, string carNumber, CoordinateSystem carAddress, string carColor);
};

class Comfort : public Car{
    int freeBottles;
public:
    Comfort(string carModel, string carNumber, CoordinateSystem carAddress, string carColor);
    int getNumberOfBottles();
    void useBottles();
};

class ComfortPlus : public Car{
    int freeBottles;
public:
    ComfortPlus(string carModel, string carNumber, CoordinateSystem carAddress, string carColor);
    int getNumberOfBottles();
    void useBottles();
};

class Business : public Car{
    int freeBottles;
public:
    Business(string carModel, string carNumber, CoordinateSystem carAddress, string carColor);
    int getNumberOfBottles();
    void useBottles();
    void parkRightInFrontOfTheEntrance();
};

#endif //TAXI_CAR_H
