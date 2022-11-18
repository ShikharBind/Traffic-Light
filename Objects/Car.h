#ifndef CAR_H
#define CAR_H

#include "Street.h"
#include <queue>
using namespace std;

class Car
{
private:
    int id, speed = 1;
    queue<Street> path;
    // running variables
    Street currentStreet;
    int currentStreetTime, totalDrivingTime, totalTimeatRedLight;

public:
    Car();
    Car(int a_id, queue<Street> a_path);
    ~Car();
    void MoveToNextStreet();
};

#endif