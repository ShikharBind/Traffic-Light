#include "Car.h"

using namespace std;

Car::Car() { }

Car::Car(int a_id, queue<Street> a_path)
{
    id = a_id;
    path = a_path;
}

Car::~Car()
{
}


void Car::MoveToNextStreet()
{
    currentStreet = path.front();
    path.pop();
}