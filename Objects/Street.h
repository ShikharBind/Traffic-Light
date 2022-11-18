#ifndef STREET_H
#define STREET_H

#include "Car.h"
#include <string>
#include <queue>

using namespace std;


class Street
{
private:
    int id, startIntersection, endIntersection;
    int length;
    bool isSignalGreen;
    string name;
    queue<Car> carsQueue;

public:
    Street();
    Street(int a_id, int a_start, int a_end, int a_length, string a_name);
    ~Street();
    void AddToQueue(Car a_car);
    Car ExitFromStreet();
};



#endif