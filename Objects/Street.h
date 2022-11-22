#ifndef STREET_H
#define STREET_H

#include "Car.h"
#include <string>
#include <queue>

using namespace std;
// class Car;

class Street
{
private:
    //config
    int id, startIntersection, endIntersection;
    int length;
    string name;
    //field
    int isSignalGreen;
    queue<Car*> carsQueue;

public:
    Street();
    Street(int a_id, int a_start, int a_end, int a_length, string a_name);
    ~Street();
    void Start();
    void Update();
    void AddToQueue(Car * a_car);
    void ExitFromStreet();
    int GetLength();
    void SetSignalState(int a_isSignalGreen);
    int GetSignalState();
};



#endif