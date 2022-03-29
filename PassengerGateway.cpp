#include "PassengerGateway.h"
#include "DriverGateway.h"
#include "System.h"

#include <utility>

void PassengerGateway::login(Passenger &passenger, string userID, string userPassword) {
    if (passenger.isLogin) {
        cout<<passenger.name<<": you are already in logged in"<<endl;
        return;
    }
    int hasAcc=-1;
    for (int i=0; i<notLoggedPassengers.size();i++) {
        if (notLoggedPassengers[i].id==passenger.id) {
            hasAcc=i;
        }
    }
    if (hasAcc!=-1) {
        if (notLoggedPassengers[hasAcc].id==userID && notLoggedPassengers[hasAcc].password==userPassword) {
            for (int i=0; i<notLoggedPassengers[hasAcc].orderHistory.size();i++) {
                passenger.orderHistory.push_back(notLoggedPassengers[hasAcc].orderHistory[i]);
            }
            for (int i=0; i<notLoggedPassengers[hasAcc].pinnedAddresses.size();i++) {
                passenger.pinnedAddresses.push_back(notLoggedPassengers[hasAcc].pinnedAddresses[i]);
            }
            passenger.isLogin= true;
            passenger.pay=notLoggedPassengers[hasAcc].pay;
            passenger.endOfLastOrder=notLoggedPassengers[hasAcc].endOfLastOrder;
            passenger.isBlocked=notLoggedPassengers[hasAcc].isBlocked;
            passenger.lastAdrInTrip=notLoggedPassengers[hasAcc].lastAdrInTrip;
            loggedPassengers.push_back(&passenger);
            notLoggedPassengers.erase(notLoggedPassengers.begin()+hasAcc);
            cout<<"Passenger "<<passenger.name<<" logged in"<<endl;
        } else {
            cout<<passenger.name<<": Wrong ID or password"<<endl;
        }
    } else {
        if (passenger.id==userID && passenger.password==userPassword) {
            passenger.isLogin= true;
            loggedPassengers.push_back(&passenger);
            cout<<"Passenger "<<passenger.name<<" logged in with new account"<<endl;
        } else {
            cout<<passenger.name<<": Wrong ID or password"<<endl;
        }
    }
}

void PassengerGateway::changePaymentMethod(Passenger& passenger, paymentMethod method) {
    try {
        if (!passenger.isBlocked) {
            passenger.changePaymentMethod(method);
        } else {
            cout<<"Passenger "<<passenger.name<<" is blocked"<<endl;
            throw -1;
        }
    }  catch (int a) {
        if (a==-1) {
            cout<<"It's example of thrown and caught exception in function changePaymentMethod"<<endl;
        }
    }
}

void PassengerGateway::addPin(Passenger &passenger, CoordinateSystem address) {
    try {
        if (!passenger.isBlocked) {
            passenger.addPin(std::move(address));
        } else {
            cout<<"Passenger "<<passenger.name<<" is blocked"<<endl;
            throw -1;
        }
    }  catch (int a) {
        if (a==-1) {
            cout<<"It's example of thrown and caught exception in function addPin"<<endl;
        }
    }

}

void PassengerGateway::printPinnedAddresses(Passenger &passenger) {
    try {
        if (!passenger.isBlocked) {
            passenger.printPinnedAddresses();
        } else {
            cout<<"Passenger "<<passenger.name<<" is blocked"<<endl;
            throw -1;
        }
    }  catch (int a) {
        if (a==-1) {
            cout<<"It's example of thrown and caught exception in function printPinnedAddresses"<<endl;
        }
    }
}

void PassengerGateway::deletePinnedAddress(Passenger &passenger, int index) {
    try {
        if (!passenger.isBlocked) {
            passenger.deletePinnedAddress(index);
        } else {
            cout<<"Passenger "<<passenger.name<<" is blocked"<<endl;
            throw -1;
        }
    }  catch (int a) {
        if (a==-1) {
            cout<<"It's example of thrown and caught exception in function deletePinnedAddress"<<endl;
        }
    }
}

pair<int, int>
PassengerGateway::preorder(Passenger &passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType) {
        int x=from.getCurrentCoordinates().first-to.getCurrentCoordinates().first;
        int y=from.getCurrentCoordinates().second-to.getCurrentCoordinates().second;
        int dist=abs(x)+abs(y);
        return make_pair(dist, dist*carType);
}

void PassengerGateway::order(Passenger &passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime) {
    try {
        if (!passenger.isBlocked) {
            if (startTime>passenger.endOfLastOrder) {
                System::order( passenger,  from,  to,  carType, startTime);
            } else {
                cout<<"Passenger "<<passenger.name<<" is in trip at that moment"<<endl;
            }
        } else {
            cout<<"Passenger "<<passenger.name<<" is blocked"<<endl;
            throw -1;
        }
    }  catch (int a) {
        if (a==-1) {
            cout<<"It's example of thrown and caught exception in function order"<<endl;
        }
    }
}

CoordinateSystem PassengerGateway::getPinnedAddress(Passenger &passenger, int index) {
    try {
        if (!passenger.isBlocked) {
            if (passenger.pinnedAddresses.size()>=index&&index>=0&&passenger.isLogin)
                return passenger.getPinnedAddress(index);
            else
                cout<<"ask for not existing index"<<endl;
                throw -1;
        } else {
            cout<<"Passenger "<<passenger.name<<" is blocked"<<endl;
            throw -1;
        }
    }  catch (int a) {
        if (a==-1) {
            cout<<"It's example of thrown and caught exception in function getPinnedAddress"<<endl;
        }
    }
}

void PassengerGateway::order(Passenger &passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType,
                             time_t startTime, paymentMethod method) {
    try {
        if (!passenger.isBlocked) {
            System::order( passenger,  from,  to,  carType, startTime, method);
        } else {
            cout<<"Passenger "<<passenger.name<<" is blocked"<<endl;
            throw -1;
        }
    }  catch (int a) {
        if (a==-1) {
            cout<<"It's example of thrown and caught exception in function order"<<endl;
        }
    }
}

void PassengerGateway::order(Passenger &passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType,
                             time_t startTime, bool specialOption) {
    try {
        if (!passenger.isBlocked) {
            System::vipOrder( passenger,  from,  to,  carType, startTime, specialOption);
        } else {
            cout<<"Passenger "<<passenger.name<<" is blocked"<<endl;
            throw -1;
        }
    }  catch (int a) {
        if (a==-1) {
            cout<<"It's example of thrown and caught exception in function order"<<endl;
        }
    }
}

void PassengerGateway::order(Passenger &passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType,
                             time_t startTime, paymentMethod method, bool specialOption) {
    try {
        if (!passenger.isBlocked) {
            System::vipOrder( passenger,  from,  to,  carType, startTime, method, specialOption);
        } else {
            cout<<"Passenger "<<passenger.name<<" is blocked"<<endl;
            throw -1;
        }
    }  catch (int a) {
        if (a==-1) {
            cout<<"It's example of thrown and caught exception in function order"<<endl;
        }
    }
}

void PassengerGateway::printCoordinatesInTrip(Passenger& passenger) {
    try {
        if (!passenger.isBlocked) {
            time_t t=time(0)+5;
            if (t<=passenger.endOfLastOrder)
                passenger.getCoordinatesDuringTrip();
            else
                cout<<passenger.name<<" you are not in trip"<<endl;
        } else {
            cout<<"Passenger "<<passenger.name<<" is blocked"<<endl;
            throw -1;
        }
    }  catch (int a) {
        if (a==-1) {
            cout<<"It's example of thrown and caught exception in function printCoordinatesInTrip"<<endl;
        }
    }

}



