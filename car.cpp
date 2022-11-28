#include "car.h"
#include <iostream>

Car::Car() {};

Car::Car(double arrivalT, double serviceT) {
    arrivalTime = arrivalT;
    serviceTime = serviceT;
}

double Car::getArrivalTime() const {
    return arrivalTime;
}

double Car::getDepartureTime() const {
    return this->departureTime;
}

double Car::getWaitingTime() const {
    return this->waitingTime;
}

double Car::getServiceTime() const {
    return this->serviceTime;
}

void Car::setDepartAndWaitTime(double startServiceTime) {
    departureTime = startServiceTime + serviceTime;
    waitingTime = startServiceTime - arrivalTime;
}

void Car::printCarDeparture() const {
    std::cout << "A car is washed and departs!\n";
    std::cout << "\tArrival time: " << arrivalTime << std::endl;
    std::cout << "\tDeparture time: " << departureTime << std::endl;
    std::cout << "\tWaiting time: " << waitingTime << std::endl;
}

void Car::printCarArrival() const {
    std::cout << "A car arrives!\n";
    std::cout << "\tArrival time: " << arrivalTime << std::endl;
}