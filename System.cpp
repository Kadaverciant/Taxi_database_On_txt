#include "System.h"

void System::order(Passenger &passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime,
                   paymentMethod method) {
    if (DriverGateway::thereIsFreeDriver(carType, startTime)) {
        Driver *driver=DriverGateway::findFreeDriver(carType, startTime);
        int index;
        for (int i=0; i<driver->cars.size(); i++) {
            if (carType==driver->cars[i]->getCarType())
                index=i;
        }
        driver->cars[index]->setCurrentAddressOfCar(from);
        passenger.lastAdrInTrip=from;

        string carModel=driver->cars[index]->getModel();
        string carNumber=driver->cars[index]->getNumber();
        string carColor=driver->cars[index]->getColor();

        string answer="";
        answer+=passenger.id+" "+driver->id+" "+to_string(from.getCurrentCoordinates().first)+' '+to_string(from.getCurrentCoordinates().second)+' '+from.getCurrentAddress()+' ';
        answer+=to_string(to.getCurrentCoordinates().first)+' '+to_string(to.getCurrentCoordinates().second)+' '+to.getCurrentAddress()+' ';

        tm *ltm = localtime(&startTime);
        answer+=to_string(ltm->tm_year+1900)+' '+to_string(ltm->tm_mon+1)+' '+to_string(ltm->tm_mday)+' '+to_string(ltm->tm_hour)+' '+to_string(ltm->tm_min)+' ';

        time_t endTime=startTime+PassengerGateway::preorder(passenger,from,to,carType).first*60;
        ltm = localtime(&(endTime));
        answer+=to_string(ltm->tm_year+1900)+' '+to_string(ltm->tm_mon+1)+' '+to_string(ltm->tm_mday)+' '+to_string(ltm->tm_hour)+' '+to_string(ltm->tm_min)+' ';

        answer+=carColor+' '+carModel+' '+carNumber+' ';

        int typeOfCar=0;
        if (carType==economy)
            typeOfCar=1;
        if (carType==comfort)
            typeOfCar=2;
        if (carType==comfortPlus)
            typeOfCar=3;
        if (carType==business)
            typeOfCar=4;
        answer+=std::to_string(typeOfCar)+' ';

        int pay=0;
        if (method==card)
            pay=1;
        if (method==cash)
            pay=2;
        answer+=to_string(pay)+' ';

        int cost=PassengerGateway::preorder(passenger,from,to,carType).second;
        answer+=to_string(cost)+" \n";
//        cout<<answer;
        cout<<driver->name<<" and "<<passenger.name<<" in trip"<<endl;
        driver->lastWork=endTime;
        passenger.endOfLastOrder=endTime;

        driver->cars[index]->setCurrentAddressOfCar(to);
        passenger.lastAdrInTrip=to;
        driver->cars[index]->useBottles();

        driver->orderHistory.push_back(answer);
        passenger.orderHistory.push_back(answer);
    } else {
        cout<<"There is no free cars"<<endl;
    }
}

void
System::order(Passenger &passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime) {
    System::order(passenger, from, to,  carType,  startTime, passenger.pay);
}

void
System::vipOrder(Passenger &passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime,
                 bool specialOption) {
    vipOrder(passenger, from, to, carType, startTime, passenger.pay, specialOption);
}

void
System::vipOrder(Passenger &passenger, CoordinateSystem from, CoordinateSystem to, CarTypes carType, time_t startTime,
                 paymentMethod method, bool specialOption) {
    if (DriverGateway::thereIsFreeDriver(carType, startTime)) {
        if (carType == business) {
            if (specialOption)
                cout << "Very rich person appeared" << endl;
            System::order(passenger, from, to,  carType,  startTime, method);
        } else {
            cout << "Type of car is too low, so if you want that function change it)" << endl;
        }
    } else {
        cout<<"There is no free cars"<<endl;
    }
}
