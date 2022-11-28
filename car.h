#ifndef CAR_H
#define CAR_H

class Car
{
private:
	double arrivalTime{};
	double departureTime{};
	double waitingTime{};
    double serviceTime{};

public:
	Car();
	Car(double arrivalT,double ServiceT);

	double getArrivalTime() const;
	double getDepartureTime() const;
	double getWaitingTime() const;
    double getServiceTime() const;

	void setDepartAndWaitTime(double currTime);
	void printCarDeparture() const;
	void printCarArrival() const;

};


#endif
