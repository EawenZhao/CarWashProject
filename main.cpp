#include "washCmp.h"
#include <iostream>


using namespace std;

int main() {
    double ArrivalRate, ServiceRate;
    int CarNum;
    cout << "Please enter the mean arrival rate :" << endl;
    cin >> ArrivalRate;
    cout << "Please enter the mean service rate :" << endl;
    cin >> ServiceRate;
    cout << "Please enter the total number of cars serviced :" << endl;
    cin >> CarNum;
    WashCmp cmp(CarNum, ArrivalRate, ServiceRate);
    cmp.simulation();
    cmp.printCmpStatistic();
    cout << "The standard waiting time is : " << ArrivalRate / (ServiceRate * (ServiceRate - ArrivalRate));

    return 0;
}