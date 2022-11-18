#include "Street.h"

using namespace std;

Street::Street() { }

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


void Street::AddToQueue(Car a_car)
{
    carsQueue.push(a_car);
}
Car Street::ExitFromStreet(){
    Car exitingCar = carsQueue.front();
    exitingCar.MoveToNextStreet();
    carsQueue.pop();
    return exitingCar;
}