#ifndef CAR_H
#define CAR_H

#include "Street.h"
#include <queue>

using namespace std;
class Street;

class Car
{
private:
    //config
    int id, speed = 1;
    queue<Street*> path_config;
    //fields
    queue<Street*> path;
    Street* currentStreet;
    int currentStreetLengthTravelled, currentStreetLength, totalDrivingTime, totalTimeatRedLight;
    bool isMoving;

public:
    Car();
    Car(int a_id, queue<Street*> a_path);
    ~Car();
    void Start();
    void Update();
    void MoveToNextStreet();
    void Move();
    void TimeUpdate();
};

#endif