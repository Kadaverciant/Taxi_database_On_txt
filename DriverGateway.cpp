#include "DriverGateway.h"
#include "Users.h"

void DriverGateway::login(Driver &driver, string userID, string userPassword) {
    if (driver.isLogin) {
        cout<<driver.name<<": you are already logged in"<<endl;
        return;
    }
    int hasAcc=-1;
    for (int i=0; i<notLoggedDrivers.size();i++) {
        if (notLoggedDrivers[i].id==driver.id) {
            hasAcc=i;
        }
    }
    if (hasAcc!=-1) {
        if (notLoggedDrivers[hasAcc].id==userID && notLoggedDrivers[hasAcc].password==userPassword) {
            for (int i=0; i<notLoggedDrivers[hasAcc].orderHistory.size();i++) {
                driver.orderHistory.push_back(notLoggedDrivers[hasAcc].orderHistory[i]);
            }
            driver.isLogin= true;
            driver.lastWork=notLoggedDrivers[hasAcc].lastWork;
            driver.cars=notLoggedDrivers[hasAcc].cars;
            driver.isBlocked=notLoggedDrivers[hasAcc].isBlocked;
            loggedDrivers.push_back(&driver);
            notLoggedDrivers.erase(notLoggedDrivers.begin()+hasAcc);
            cout<<"Driver "<<driver.name<<" logged in"<<endl;
        } else {
            cout<<driver.name<<": Wrong ID or password"<<endl;
        }
    } else {
        if (driver.id==userID && driver.password==userPassword) {
            driver.isLogin= true;
            loggedDrivers.push_back(&driver);
            cout<<"Driver "<<driver.name<<" logged in with new account"<<endl;
        } else {
            cout<<driver.name<<": Wrong ID or password"<<endl;
        }
    }
}

Driver* DriverGateway::findFreeDriver(CarTypes carType, time_t callTime) {\
    for (int i=0; i<loggedDrivers.size(); i++) {
        if (loggedDrivers[i]->getDriverStatusAtTime(callTime) == working  && !loggedDrivers[i]->isBlocked) {
            for (int j=0; j<loggedDrivers[i]->cars.size(); j++) {
                if (carType == loggedDrivers[i]->cars[j]->getCarType() && loggedDrivers[i]->cars[j]->getValidity()) {
                    return loggedDrivers[i];
                }
            }
        }
    }
}

bool DriverGateway::thereIsFreeDriver(CarTypes carType, time_t callTime) {
    for (int i=0; i<loggedDrivers.size(); i++) {
        if (loggedDrivers[i]->getDriverStatusAtTime(callTime) == working  && !loggedDrivers[i]->isBlocked) {
            for (int j=0; j<loggedDrivers[i]->cars.size(); j++) {
                if (carType == loggedDrivers[i]->cars[j]->getCarType() && loggedDrivers[i]->cars[j]->getValidity()) {
                    return true;
                }
            }
        }
    }
    return false;
}

void DriverGateway::addCar(Driver &driver, Car* tempCar) {
    if (driver.isLogin && !driver.isBlocked) {
        driver.addCar(tempCar);
    } else {
        cout<<"Driver "<<driver.name<<" is not logged in or is blocked"<<endl;
    }

}
