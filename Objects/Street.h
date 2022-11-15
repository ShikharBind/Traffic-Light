#ifndef STREET_H
#define STREET_H

#include "Car.h"
#include <queue>

using namespace std;


class Street
{
private:
    /* data */
    int id;
    int duration;
    queue<Car> queue;

public:
    Street(/* args */);
    ~Street();
};



#endif