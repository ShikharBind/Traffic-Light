#ifndef SIMULATION_H
#define SIMULATION_H

#include "Objects/Street.h"
#include "Objects/Car.h"
#include "Objects/Intersection.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class Simulation
{
private:
    vector<Intersection> intersections;
    vector<Car> cars;
    vector<Street> streets;
    map<string,Street> nameToStreet;

    int simulationTime;
public:
    Simulation(/* args */);
    ~Simulation();
};

#endif