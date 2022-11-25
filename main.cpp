#include "car.h"
#include "washCmp.h"
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int main()
{
    WashCmp cmp;
    cmp.simulation();
    cmp.printCmpStatistic();

    //srand((unsigned int)time(0));
    //cout << RAND_MAX << endl; //32767
    //double p1 = rand() / double(RAND_MAX + 1);
    //double p2 = rand() / double(RAND_MAX + 1);
    //double p3 = rand() / double(RAND_MAX + 1);

    //cout << p1 << " " << p2 << " " << p3 << endl;

    //cout << log(2.71828) << endl;
    //cout << exp(1.000) << endl;

    ///*
    //mean waiting time is 1.5 hour
    //lambda = 1 / 1.5 = 0.667
    //1 - exp(- 0.667 * t) = p
    //log(1 - p) = - 0.667 * t
    //t = - 1.5 * log(1 - p)
    //*/

    //double p = rand() / double(RAND_MAX + 1);
    //cout << "waiting time: " << -1.5 * log(1 - p) << endl;

    return 0;
}