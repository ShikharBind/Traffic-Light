#include "Intersection.h"

using namespace std;


Intersection::Intersection(int a_id)
{
    id = a_id;
}

Intersection::~Intersection()
{
}

void Intersection::Update(){ 
    return;
}

void Intersection::AddStartStreets(Street* a_street){
    streetsStart.push_back(a_street);
    return;
}

void Intersection::AddEndStreets(Street* a_street)
{
    streetsEnd.push_back(a_street);
    return;
}