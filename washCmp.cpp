#include "washCmp.h"
#include <iostream>
#include <ctime>
#include <cmath>


WashCmp::WashCmp() {};

WashCmp::WashCmp(int amountofCars, double arrivalRate, double serviceRate) {
    srand((unsigned) time(0));
    this->amountofCars = amountofCars;
    this->arrivalRate = arrivalRate;
    this->serviceRate = serviceRate;
}

void WashCmp::simulation() //here is the deter of in or out
{
    double arrivalTime = getNextArrival(); //get the next arrival time from keyboard input

    /************* to be changed ****************/
    while (arrivalTime != 999) {
        if (carQueue.empty()) //queue empty, process arrival
        {
            processArrivalEmptyQ(arrivalTime, getNextServiceTime());
            arrivalTime = getNextArrival(); //get next arrival
        } else if (arrivalTime < carQueue.front().getDepartureTime()) //arrival first, process arrival
        {
            processArrivalNonEmptyQ(arrivalTime, getNextServiceTime());
            arrivalTime = getNextArrival(); //get next arrival
        } else //departure first or of the same time, process departure
        {
            processDeparture(); //no need to get next arrival
        }
    }

    //no more arrival, process the remaining cars in the queue
    processRemain();
}

double WashCmp::getNextArrival()  //get next arrival time
{
    numServedCars++;
    if (this->numServedCars != this->amountofCars) {
        double p = rand() / double(RAND_MAX + 1); //generate a number between 0 and 1
        double gap = - (1 / this->arrivalRate) * log(1 - p) ;
        lastArrivalTime = lastArrivalTime + gap;
        return lastArrivalTime;
    } else {
        return 999;
    }
}

double WashCmp::getNextServiceTime() {
    double s = rand() / double(RAND_MAX + 1);   //generate a number between 0 and 1
    double result = - (1 / this->serviceRate) * log(1 - s);
    return result;
}

void WashCmp::processArrivalEmptyQ(double arrivalTime, double serviceTime) {
    Car arrivedCar = Car(arrivalTime, serviceTime);
    arrivedCar.setDepartAndWaitTime(arrivalTime); //set the departure and waiting time of the arrived car
    arrivedCar.printCarArrival(); //print the arrival information of the arrived car
    carQueue.push(arrivedCar); //set the arrival time of the arrived car
}

void WashCmp::processArrivalNonEmptyQ(double arrivalTime, double serviceTime) {
    Car arrivedCar = Car(arrivalTime, serviceTime);
    arrivedCar.printCarArrival(); //print the arrival information of the arrived car
    carQueue.push(arrivedCar); //set the arrival time of the arrived car
}

void WashCmp::processDeparture() {
    double currTime = carQueue.front().getDepartureTime(); //get the current time

    totalWaitingTime += carQueue.front().getWaitingTime(); //update statistics

    carQueue.front().printCarDeparture(); //print departure information
    carQueue.pop(); //departs

    if (!carQueue.empty())                                 //set the departure and waiting time of
        carQueue.front().setDepartAndWaitTime(currTime);   //the current front car in the queue
}

void WashCmp::processRemain() //wash the remaining cars in the queue
{
    while (!carQueue.empty())
        processDeparture();
}

void WashCmp::printCmpStatistic() {
    std::cout << "Number of served cars: " << numServedCars << std::endl;
    std::cout << "Total waiting time: " << totalWaitingTime << std::endl;
    std::cout << "The average waiting time is: " << (double) totalWaitingTime / numServedCars << std::endl;
}


