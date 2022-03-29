/*
 * This class implements coordinate system.
 * The coordinate system has values for the x and y axes and the name of the address.
 */
#ifndef TAXI_COORDINATESYSTEM_H
#define TAXI_COORDINATESYSTEM_H
#include <iostream>
using namespace std;

class CoordinateSystem {
private:
    string name;
    int x;
    int y;
public:
    CoordinateSystem();
    CoordinateSystem(int first, int second, string address);
    void setCoordinates(int first, int second, string address);
    pair<int,int> getCurrentCoordinates();
    string getCurrentAddress();
    void printLocation();
};


#endif //TAXI_COORDINATESYSTEM_H
