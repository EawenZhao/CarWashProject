#ifndef WASH_H
#define WASH_H

#include <queue>
#include "car.h"

class WashCmp
{
private:
	std::queue<Car> carQueue;

    int amountofCars{};
	int numServedCars{};
    double lastArrivalTime{};
	double totalWaitingTime{};
    double arrivalRate{};
    double serviceRate{};

	double getNextArrival();
    double getNextServiceTime();
	void processArrivalNonEmptyQ(double currTime,double serviceTime); //a car arrives and the waiting queue is not empty
	void processArrivalEmptyQ(double currTime, double serviceTime); //a car arrives and the waiting queue is empty
	void processDeparture();
	void processRemain(); //no more arriving cars, process the remaining cars in the waiting queue

public:
	WashCmp();
    WashCmp(int amountofCars, double arrivalRate, double serviceRate);
    void simulation();
	void printCmpStatistic();
};


#endif