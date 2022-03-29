#include "DataBase.h"
using namespace std;

void DataBase::exportOrders() {
    fclose(stdout);
    freopen("Database.txt", "wt", stdout);
    for (int i=0; i<PassengerGateway::loggedPassengers.size(); i++) {
        for (int j=0; j<PassengerGateway::loggedPassengers[i]->orderHistory.size(); j++) {
            cout<<PassengerGateway::loggedPassengers[i]->orderHistory[j]<<endl;
        }
    }
    for (int i=0; i<PassengerGateway::notLoggedPassengers.size(); i++) {
        for (int j=0; j<PassengerGateway::notLoggedPassengers[i].orderHistory.size(); j++) {
            cout<<PassengerGateway::notLoggedPassengers[i].orderHistory[j]<<endl;
        }
    }
}

void DataBase::exportUsers() {
    fclose(stdout);
    freopen("Users.txt", "wt", stdout);
    int sSize=PassengerGateway::loggedPassengers.size()+PassengerGateway::notLoggedPassengers.size()+
            DriverGateway::loggedDrivers.size()+DriverGateway::notLoggedDrivers.size()+
            AdminGateway::loggedAdmins.size()+AdminGateway::notLoggedAdmins.size();
    cout<<sSize<<endl;
    for (int i=0; i<PassengerGateway::loggedPassengers.size(); i++) {
        cout<<1<<' ';
        cout<<PassengerGateway::loggedPassengers[i]->name<<' ';
        cout<<PassengerGateway::loggedPassengers[i]->rating<<' ';
        cout<<PassengerGateway::loggedPassengers[i]->id<<' ';
        cout<<PassengerGateway::loggedPassengers[i]->password<<' ';

        int pay=0;
        if (PassengerGateway::loggedPassengers[i]->pay==card)
            pay=1;
        if (PassengerGateway::loggedPassengers[i]->pay==cash)
            pay=2;
        cout<<pay<<' ';

        cout<<PassengerGateway::loggedPassengers[i]->endOfLastOrder<<' ';

        cout<<PassengerGateway::loggedPassengers[i]->isBlocked<<' ';

        cout<<PassengerGateway::loggedPassengers[i]->lastAdrInTrip.getCurrentCoordinates().first<<' ';
        cout<<PassengerGateway::loggedPassengers[i]->lastAdrInTrip.getCurrentCoordinates().second<<' ';
        cout<<PassengerGateway::loggedPassengers[i]->lastAdrInTrip.getCurrentAddress()<<' ';

        cout<<endl;
    }
    for (int i=0; i<PassengerGateway::notLoggedPassengers.size(); i++) {
        cout<<1<<' ';
        cout<<PassengerGateway::notLoggedPassengers[i].name<<' ';
        cout<<PassengerGateway::notLoggedPassengers[i].rating<<' ';
        cout<<PassengerGateway::notLoggedPassengers[i].id<<' ';
        cout<<PassengerGateway::notLoggedPassengers[i].password<<' ';

        int pay=0;
        if (PassengerGateway::notLoggedPassengers[i].pay==card)
            pay=1;
        if (PassengerGateway::notLoggedPassengers[i].pay==cash)
            pay=2;
        cout<<pay<<' ';

        cout<<PassengerGateway::notLoggedPassengers[i].endOfLastOrder<<' ';

        cout<<PassengerGateway::notLoggedPassengers[i].isBlocked<<' ';

        cout<<PassengerGateway::notLoggedPassengers[i].lastAdrInTrip.getCurrentCoordinates().first<<' ';
        cout<<PassengerGateway::notLoggedPassengers[i].lastAdrInTrip.getCurrentCoordinates().second<<' ';
        cout<<PassengerGateway::notLoggedPassengers[i].lastAdrInTrip.getCurrentAddress()<<' ';

        cout<<endl;
    }
    for (int i=0; i<DriverGateway::loggedDrivers.size(); i++) {
        cout<<2<<' ';
        cout<<DriverGateway::loggedDrivers[i]->name<<' ';
        cout<<DriverGateway::loggedDrivers[i]->rating<<' ';
        cout<<DriverGateway::loggedDrivers[i]->id<<' ';
        cout<<DriverGateway::loggedDrivers[i]->password<<' ';
        cout<<DriverGateway::loggedDrivers[i]->lastWork<<' ';

        cout<<DriverGateway::loggedDrivers[i]->isBlocked<<' ';

        cout<<DriverGateway::loggedDrivers[i]->cars.size()<<' ';
        for (int j=0; j<DriverGateway::loggedDrivers[i]->cars.size(); j++) {
            cout<<DriverGateway::loggedDrivers[i]->cars[j]->getModel()<<' ';
            cout<<DriverGateway::loggedDrivers[i]->cars[j]->getNumber()<<' ';

            CoordinateSystem c= DriverGateway::loggedDrivers[i]->cars[j]->getCurrentAddressOfCar();
            cout<<c.getCurrentCoordinates().first<<' '<<c.getCurrentCoordinates().second<<' '<<c.getCurrentAddress()<<' ';

            cout<<DriverGateway::loggedDrivers[i]->cars[j]->getColor()<<' ';
            CarTypes type=DriverGateway::loggedDrivers[i]->cars[j]->getCarType();
            int typeOfCar=0;
            if (type==economy)
                typeOfCar=1;
            if (type==comfort)
                typeOfCar=2;
            if (type==comfortPlus)
                typeOfCar=3;
            if (type==business)
                typeOfCar=4;
            cout<<typeOfCar<<' ';
        }
        cout<<endl;

    }
    for (int i=0; i<DriverGateway::notLoggedDrivers.size(); i++) {
        cout<<2<<' ';
        cout<<DriverGateway::notLoggedDrivers[i].name<<' ';
        cout<<DriverGateway::notLoggedDrivers[i].rating<<' ';
        cout<<DriverGateway::notLoggedDrivers[i].id<<' ';
        cout<<DriverGateway::notLoggedDrivers[i].password<<' ';
        cout<<DriverGateway::notLoggedDrivers[i].lastWork<<' ';

        cout<<DriverGateway::notLoggedDrivers[i].isBlocked<<' ';


        cout<<DriverGateway::notLoggedDrivers[i].cars.size()<<' ';
        for (int j=0; j<DriverGateway::notLoggedDrivers[i].cars.size(); j++) {

            cout<<DriverGateway::notLoggedDrivers[i].cars[j]->getModel()<<' ';
            cout<<DriverGateway::notLoggedDrivers[i].cars[j]->getNumber()<<' ';
            CoordinateSystem c= DriverGateway::notLoggedDrivers[i].cars[j]->getCurrentAddressOfCar();
            cout<<c.getCurrentCoordinates().first<<' '<<c.getCurrentCoordinates().second<<' '<<c.getCurrentAddress()<<' ';

            cout<<DriverGateway::notLoggedDrivers[i].cars[j]->getColor()<<' ';
            CarTypes type=DriverGateway::notLoggedDrivers[i].cars[j]->getCarType();
            int typeOfCar=0;
            if (type==economy)
                typeOfCar=1;
            if (type==comfort)
                typeOfCar=2;
            if (type==comfortPlus)
                typeOfCar=3;
            if (type==business)
                typeOfCar=4;
            cout<<typeOfCar<<' ';
        }
        cout<<endl;
    }
    for (int i=0; i<AdminGateway::loggedAdmins.size(); i++) {
        cout<<3<<' ';
        cout<<AdminGateway::loggedAdmins[i]->name<<' ';
        cout<<AdminGateway::loggedAdmins[i]->id<<' ';
        cout<<AdminGateway::loggedAdmins[i]->password<<' ';
        cout<<endl;
    }
    for (int i=0; i<AdminGateway::notLoggedAdmins.size(); i++) {
        cout<<3<<' ';
        cout<<AdminGateway::notLoggedAdmins[i].name<<' ';
        cout<<AdminGateway::notLoggedAdmins[i].id<<' ';
        cout<<AdminGateway::notLoggedAdmins[i].password<<' ';
        cout<<endl;
    }
}

void DataBase::exportPinnedAddresses() {
    fclose(stdout);
    freopen("Pinned.txt", "wt", stdout);
    int sSize=0;
    for (int i=0; i<PassengerGateway::loggedPassengers.size(); i++) {
        for (int j=0; j<PassengerGateway::loggedPassengers[i]->pinnedAddresses.size();j++) {
            sSize++;
        }
    }
    for (int i=0; i<PassengerGateway::notLoggedPassengers.size(); i++) {
        for (int j=0; j<PassengerGateway::notLoggedPassengers[i].pinnedAddresses.size();j++) {
            sSize++;
        }
    }
    cout<<sSize<<endl;
    for (int i=0; i<PassengerGateway::loggedPassengers.size(); i++) {
        for (int j=0; j<PassengerGateway::loggedPassengers[i]->pinnedAddresses.size();j++) {
            cout<<PassengerGateway::loggedPassengers[i]->id<<' ';

            CoordinateSystem c= PassengerGateway::loggedPassengers[i]->pinnedAddresses[j];
            cout<<c.getCurrentCoordinates().first<<' '<<c.getCurrentCoordinates().second<<' '<<c.getCurrentAddress()<<' ';

            cout<<endl;
        }
    }
    for (int i=0; i<PassengerGateway::notLoggedPassengers.size(); i++) {
        for (int j=0; j<PassengerGateway::notLoggedPassengers[i].pinnedAddresses.size();j++) {
            cout<<PassengerGateway::notLoggedPassengers[i].id<<' ';

            CoordinateSystem c= PassengerGateway::notLoggedPassengers[i].pinnedAddresses[j];
            cout<<c.getCurrentCoordinates().first<<' '<<c.getCurrentCoordinates().second<<' '<<c.getCurrentAddress()<<' ';

            cout<<endl;
        }
    }
}

void DataBase::importUsers() {
    fclose(stdin);
    freopen("Users.txt", "rt", stdin);
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        string s;
        cin>>s;
        if (s=="1") {
            string name;
            cin>>name;
            double rating;
            cin>>rating;
            string id;
            cin>>id;
            string password;
            cin>>password;

            paymentMethod method;
            int pay=0;
            cin>>pay;
            if  (pay==1) {
                method=card;
            }
            if  (pay==2) {
                method=cash;
            }

            Passenger passenger(name,rating,id,password,method);
            time_t t;
            cin>>t;
            passenger.endOfLastOrder=t;
            bool block;
            cin>>block;
            passenger.isBlocked=block;

            int first;
            cin>>first;
            int second;
            cin>>second;
            string address;
            cin>>address;
            CoordinateSystem coordinateSystem(first,second,address);

            passenger.lastAdrInTrip=coordinateSystem;


            PassengerGateway::notLoggedPassengers.push_back(passenger);
        }
        if (s=="2") {
            string name;
            cin>>name;
            double rating;
            cin>>rating;
            string id;
            cin>>id;
            string password;
            cin>>password;
            time_t time;
            cin>>time;

            Driver driver(name,rating,id,password,time);

            bool block;
            cin>>block;


            int numberOfCars;
            cin>>numberOfCars;
            for (int j=0; j<numberOfCars; j++) {
                string model;
                cin>>model;
                string number;
                cin>>number;
                int first;
                cin>>first;
                int second;
                cin>>second;
                string address;
                cin>>address;
                CoordinateSystem coordinateSystem(first,second,address);

                string color;
                cin>>color;
                CarTypes type;
                int t=0;
                cin>>t;
                if (t==1)
                    type=economy;
                if (t==2)
                    type=comfort;
                if (t==3)
                    type=comfortPlus;
                if (t==4)
                    type=business;
                Car* someCar = new Car(model,number,coordinateSystem,color,type);
                driver.addCar(someCar);
            }
            driver.isBlocked=block;
            DriverGateway::notLoggedDrivers.push_back(driver);
        }
        if (s=="3") {
            string name;
            cin>>name;
            string id;
            cin>>id;
            string password;
            cin>>password;

            Admin admin(name,id,password);
            AdminGateway::notLoggedAdmins.push_back(admin);
        }
    }
}

void DataBase::importOrders() {
    fclose(stdin);
    freopen("DataBase.txt", "rt", stdin);
    string pasID;
    while(cin>>pasID) {
        string drivID;
        cin>>drivID;
        string order="";
        order+=pasID+' '+drivID+' ';
        string temp;
        for (int i=0; i<22; i++) {
            cin>>temp;
            order+=temp+' ';
        }
        for (int i=0; i<PassengerGateway::notLoggedPassengers.size();i++) {
            if (PassengerGateway::notLoggedPassengers[i].id==pasID) {
                PassengerGateway::notLoggedPassengers[i].orderHistory.push_back(order);
            }
        }
        for (int i=0; i<DriverGateway::notLoggedDrivers.size();i++) {
            if (DriverGateway::notLoggedDrivers[i].id==drivID) {
                DriverGateway::notLoggedDrivers[i].orderHistory.push_back(order);
            }
        }
    }
}

void DataBase::importPinnedAddresses() {
    fclose(stdin);
    freopen("Pinned.txt", "rt", stdin);
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        string pasID;
        cin>>pasID;
        int first;
        cin>>first;
        int second;
        cin>>second;
        string address;
        cin>>address;
        CoordinateSystem c(first,second,address);
        for (int j=0; j<PassengerGateway::notLoggedPassengers.size();j++) {
            if (PassengerGateway::notLoggedPassengers[j].id==pasID) {
                PassengerGateway::notLoggedPassengers[j].pinnedAddresses.push_back(c);
            }
        }
    }
}

