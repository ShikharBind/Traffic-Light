#include "Car.h"

using namespace std;

Car::Car() {}

Car::Car(int a_id, queue<Street*> a_path)
{
    id = a_id;
    path_config = a_path;
}

Car::~Car()
{
}

void Car::Start(){
    path = path_config;
    MoveToNextStreet();
    currentStreetLengthTravelled = currentStreetLength;
    Move();
    totalDrivingTime = 0;
    totalTimeatRedLight = 0;
    return;
}

void Car::Update()
{
    TimeUpdate();
    Move();
    return;
}

void Car::MoveToNextStreet()
{
    currentStreet = path.front();
    currentStreetLengthTravelled = 0;
    currentStreetLength = (*currentStreet).GetLength();
    isMoving = true;
    path.pop();
    return;
}

void Car::Move()
{
    if (isMoving)
    {
        currentStreetLengthTravelled++;
    }

    if(currentStreetLengthTravelled >= currentStreetLength && isMoving){
        (*currentStreet).AddToQueue(this);
        isMoving = false;
    }

    return;
}

void Car::TimeUpdate()
{
    if (isMoving)
    {
        totalDrivingTime++;
    }
    else
    {
        totalTimeatRedLight++;
    }
    return;
}