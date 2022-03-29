#include "Car.h"

#include <utility>

Car::Car(string carModel, string carNumber, CoordinateSystem carAddress, string carColor, CarTypes typeOfCar) {
    model=std::move(carModel);
    number=std::move(carNumber);
    currentAddress=std::move(carAddress);
    color=std::move(carColor);
    carType=typeOfCar;
    isValid= false;

    if (carType==business) {
        freeBottles=30;
    } else if (carType==comfortPlus) {
        freeBottles=24;
    } else if (carType==comfort) {
        freeBottles=15;
    } else {
        freeBottles=0;
    }
}

string Car::getModel()  {
    return model;
}

string Car::getNumber()  {
    return number;
}

string Car::getColor()  {
    return color;
}

CoordinateSystem Car::getCurrentAddressOfCar()  {
    return currentAddress;
}

CarTypes Car::getCarType()  {
    return carType;
}

int Car::getNumberOfBottles() {
    return freeBottles;
}

void Car::useBottles() {
    if (freeBottles>0)
        freeBottles-=rand() % freeBottles;
}



void Car::setCurrentAddressOfCar(CoordinateSystem address) {
    currentAddress=std::move(address);
}

bool Car::getValidity() {
    return isValid;
}

Economy::Economy(string carModel, string carNumber, CoordinateSystem carAddress, string carColor) : Car(std::move(carModel), std::move(carNumber), std::move(carAddress), std::move(carColor), economy) {
}

Comfort::Comfort(string carModel, string carNumber, CoordinateSystem carAddress, string carColor) : Car(std::move(carModel), std::move(carNumber), std::move(carAddress), std::move(carColor), comfort){
    freeBottles=10;
}

int Comfort::getNumberOfBottles() {
    return freeBottles;
}

void Comfort::useBottles() {
    if (freeBottles>0)
        freeBottles-=rand() % freeBottles;
}

ComfortPlus::ComfortPlus(string carModel, string carNumber, CoordinateSystem carAddress, string carColor) : Car(std::move(carModel), std::move(carNumber), std::move(carAddress), std::move(carColor), comfortPlus) {
    freeBottles=15;
}

int ComfortPlus::getNumberOfBottles() {
    return freeBottles;
}

void ComfortPlus::useBottles() {
    if (freeBottles>0)
        freeBottles-=rand() % freeBottles;
}

Business::Business(string carModel, string carNumber, CoordinateSystem carAddress, string carColor) : Car(std::move(carModel), std::move(carNumber), std::move(carAddress), std::move(carColor), business) {
    freeBottles=30;
}

int Business::getNumberOfBottles() {
    return freeBottles;
}

void Business::useBottles() {
    if (freeBottles>0)
        freeBottles-=rand() % freeBottles;
}

void Business::parkRightInFrontOfTheEntrance() {
    cout<<"Very rich person appeared";
}
