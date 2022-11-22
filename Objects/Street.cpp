#include "Street.h"

using namespace std;

Street::Street() {}

Street::Street(int a_id, int a_start, int a_end, int a_length, string a_name)
{
    id = a_id;
    startIntersection = a_start;
    endIntersection = a_end;
    length = a_length;
    name = a_name;
}

Street::~Street()
{
}

void Street::Start()
{
    queue<Car*> empty;
    carsQueue = empty;
    return;
}

void Street::Update()
{
    ExitFromStreet();
    return;
}

void Street::AddToQueue(Car *a_car)
{
    carsQueue.push(a_car);
    return;
}

void Street::ExitFromStreet()
{
    if (carsQueue.size() && isSignalGreen)
    {
        Car* exitingCar = carsQueue.front();
        (*exitingCar).MoveToNextStreet();
        carsQueue.pop();
        return;
    }
}

int Street::GetLength()
{
    return length;
}

void Street::SetSignalState(int a_isSignalGreen)
{
    isSignalGreen = a_isSignalGreen;
}


int Street::GetSignalState(){
    return isSignalGreen;
}
