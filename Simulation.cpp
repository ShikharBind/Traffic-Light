#include "Simulation.h"
#include <iostream>

using namespace std;

Simulation::Simulation(int a_simulationTime)
{
    simulationTime = a_simulationTime;
    ParseInput();
}

Simulation::~Simulation()
{
}

void Simulation::Start(vector<vector<int>> a_state)
{
    state = a_state;
    currentTime = 0;

    for(auto x : streets){
        (*x).Start();
    }

    for(auto x : cars){
        (*x).Start();
    }
    return;
}
void Simulation::Update()
{
    for(int i=0; i<streets.size(); i++){
        (*streets[i]).SetSignalState(state[currentTime][i]);
    }

    for(auto x : streets){
        (*x).Update();
    }

    for(auto x : cars){
        (*x).Update();
    }

    return;
}

int Simulation::FitnessFunction(vector<vector<int>> a_state)
{
    Start(a_state);

    for(int i=0; i<simulationTime; i++){
        Update();
    }
}

void Simulation::ParseInput()
{
    freopen("input.txt", "r", stdin);
    string s;

    int numberOfIntersections;
    cin >> numberOfIntersections;
    for (int i = 0; i < numberOfIntersections; i++)
    {
        intersections.push_back(new Intersection(i));
    }

    int numberofStreets;
    int streetId, streetStart, streetEnd, streetLength;
    string streetName;
    cin >> numberofStreets;
    for (int i = 0; i < numberofStreets; i++)
    {
        cin >> streetId >> streetStart >> streetEnd >> streetLength >> streetName;
        streets.push_back(new Street(streetId, streetStart, streetEnd, streetLength, streetName));
        (*intersections[streetStart]).AddStartStreets(streets[i]);
        (*intersections[streetEnd]).AddEndStreets(streets[i]);
        nameToStreet[streetName] = streets[i];
    }

    int numberofCars;
    int streetId, carPathSize;
    cin >> numberofStreets;
    for (int i = 0; i < numberofCars; i++)
    {
        cin >> streetId >> carPathSize;
        queue<Street *> path;
        for (int j = 0; j < carPathSize; j++)
        {
            cin >> streetName;
            path.push(nameToStreet[streetName]);
        }

        cars.push_back(new Car(streetId, path));
    }

    return;
}
