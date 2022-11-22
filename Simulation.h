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
    vector<Intersection*> intersections;
    vector<Car*> cars;
    vector<Street*> streets;
    map<string,Street*> nameToStreet;
    vector<vector<int>> state;//of traffic lights

    int simulationTime, currentTime;
public:
    Simulation(int a_simulationTime);
    ~Simulation();
    void Start(vector<vector<int>> a_state);
    void Update();
    void ParseInput();
    int FitnessFunction(vector<vector<int>> a_state);
};

#endif