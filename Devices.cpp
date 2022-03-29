//
// Created by Vsevolod Klushev on 25.04.2021.
//

#include "Devices.h"

#include <utility>

Devices::Devices(string deviceName) {
    name=std::move(deviceName);
    inUse= false;
}

void Devices::connectToUser(Passenger *pas) {
    passenger=pas;
    inUse= true;
}

void Devices::login(string userID, string userPassword) {
    if (inUse) {
        PassengerGateway::login(*passenger,std::move(userID),std::move(userPassword));
    } else {
        cout<<"Device "<<name<<" id not connected to any user!"<<endl;
    }
}

void Devices::changePaymentMethod(paymentMethod method) {
    if (inUse) {
        PassengerGateway::changePaymentMethod(*passenger,method);
    } else {
        cout<<"Device "<<name<<" id not connected to any user!"<<endl;
    }
}

void Devices::addPin(CoordinateSystem address) {
    if (inUse) {
        PassengerGateway::addPin(*passenger,std::move(address));
    } else {
        cout<<"Device "<<name<<" id not connected to any user!"<<endl;
    }
}

void Devices::printPinnedAddresses() {
    if (inUse) {
        PassengerGateway::printPinnedAddresses(*passenger);
    } else {
        cout<<"Device "<<name<<" id not connected to any user!"<<endl;
    }
}

CoordinateSystem Devices::getPinnedAddress(int index) {
    if (inUse) {
        return PassengerGateway::getPinnedAddress(*passenger,index);
    } else {
        cout<<"Device "<<name<<" id not connected to any user!"<<endl;
    }
}

void Devices::deletePinnedAddress(int index) {
    if (inUse) {
        PassengerGateway::deletePinnedAddress(*passenger,index);
    } else {
        cout<<"Device "<<name<<" id not connected to any user!"<<endl;
    }
}

pair<int, int> Devices::preorder(CoordinateSystem from, CoordinateSystem to, CarTypes carType) {
    if (inUse) {
        return  PassengerGateway::preorder(*passenger,std::move(from),std::move(to),carType);
    } else {
        cout<<"Device "<<name<<" id not connected to any user!"<<endl;
    }
}

void Devices::order(CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime) {
    if (inUse) {
        PassengerGateway::order(*passenger,std::move(from),std::move(to),carType,startTime);
    } else {
        cout<<"Device "<<name<<" id not connected to any user!"<<endl;
    }
}

void
Devices::order(CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime, paymentMethod method) {
    if (inUse) {
        PassengerGateway::order(*passenger,std::move(from),std::move(to),carType,startTime,method);
    } else {
        cout<<"Device "<<name<<" id not connected to any user!"<<endl;
    }
}

void
Devices::order(CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime, bool specialOption) {
    if (inUse) {
        PassengerGateway::order(*passenger,std::move(from),std::move(to),carType,startTime,specialOption);
    } else {
        cout<<"Device "<<name<<" id not connected to any user!"<<endl;
    }
}

void
Devices::order(CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime, paymentMethod method,
               bool specialOption) {
    if (inUse) {
        PassengerGateway::order(*passenger,std::move(from),std::move(to),carType,startTime,method,specialOption);
    } else {
        cout<<"Device "<<name<<" id not connected to any user!"<<endl;
    }
}

void Devices::printLastOrder() {
    if (inUse) {
        passenger->printLastOrder();
    } else {
        cout<<"Device "<<name<<" id not connected to any user!"<<endl;
    }
}

void Devices::printAllOrders() {
    if (inUse) {
        passenger->printAllHistory();
    } else {
        cout<<"Device "<<name<<" id not connected to any user!"<<endl;
    }
}

void Devices::askBillForLastOrder() {
    if (inUse) {
        passenger->askBillForLastOrder();
    } else {
        cout<<"Device "<<name<<" id not connected to any user!"<<endl;
    }
}

void Devices::printCoordinatesInTrip() {
    if (inUse) {
        PassengerGateway::printCoordinatesInTrip(*passenger);
    } else {
        cout<<"Device "<<name<<" id not connected to any user!"<<endl;
    }
}
