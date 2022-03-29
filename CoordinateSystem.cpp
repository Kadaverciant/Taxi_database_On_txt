#include "CoordinateSystem.h"

#include <utility>

CoordinateSystem::CoordinateSystem() {
    x=0;
    y=0;
    name="Base";
}

CoordinateSystem::CoordinateSystem(int first, int second, string address) {
    x=first;
    y=second;
    name=std::move(address);
}

void CoordinateSystem::setCoordinates(int first, int second, string address) {
    x=first;
    y=second;
    name=std::move(address);
}

pair<int, int> CoordinateSystem::getCurrentCoordinates() {
    return make_pair(x,y);
}

string CoordinateSystem::getCurrentAddress() {
    return name;
}

void CoordinateSystem::printLocation() {
    string s="";
    s+=to_string(x)+' '+to_string(y)+' '+name+" \n";
    cout<< s;
}


