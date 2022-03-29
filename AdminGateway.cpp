//
// Created by Vsevolod Klushev on 25.04.2021.
//

#include "AdminGateway.h"

void AdminGateway::login(Admin &admin, string userID, string userPassword) {
    if (admin.isLogin) {
        cout<<admin.name<<": you are already in logged in"<<endl;
        return;
    }
    int hasAcc=-1;
    for (int i=0; i<notLoggedAdmins.size();i++) {
        if (notLoggedAdmins[i].id==admin.id) {
            hasAcc=i;
        }
    }
    if (hasAcc!=-1) {
        if (notLoggedAdmins[hasAcc].id==userID && notLoggedAdmins[hasAcc].password==userPassword) {
            admin.isLogin= true;
            loggedAdmins.push_back(&admin);
            notLoggedAdmins.erase(notLoggedAdmins.begin()+hasAcc);
            cout<<"Admin "<<admin.name<<" logged in"<<endl;
        } else {
            cout<<admin.name<<": Wrong ID or password"<<endl;
        }
    } else {
        if (admin.id==userID && admin.password==userPassword) {
            admin.isLogin= true;
            loggedAdmins.push_back(&admin);
            cout<<"Admin "<<admin.name<<" logged in with new account"<<endl;
        } else {
            cout<<admin.name<<": Wrong ID or password"<<endl;
        }
    }
}

void AdminGateway::validateAllCars(Admin &admin, Driver &driver) {
    for (int i=0; i<driver.cars.size(); i++) {
        admin.validateCar(driver.cars[i]);
    }
    cout<<"All cars for current moment are validated for driver "<<driver.name<<endl;
}

void AdminGateway::blockPassenger(Admin &admin, Passenger &passenger) {
    admin.blockPassenger(passenger);
}

void AdminGateway::blockDriver(Admin &admin, Driver& driver) {
    admin.blockDriver(driver);
}

void AdminGateway::unblockPassenger(Admin &admin, Passenger &passenger) {
    admin.unblockPassenger(passenger);
}

void AdminGateway::unblockDriver(Admin &admin, Driver &driver) {
    admin.unblockDriver(driver);
}

void AdminGateway::printNumberOfUsers(Admin& admin) {
    admin.printNumberOfUsers();
}

void AdminGateway::printAllUsers(Admin &admin) {
    admin.printAllUsers();
}

void AdminGateway::printAllCars(Admin &admin) {
    admin.printAllCars();
}

void AdminGateway::printAllHistory(Admin &admin) {
    admin.printAllHistoryForUsers();
}
