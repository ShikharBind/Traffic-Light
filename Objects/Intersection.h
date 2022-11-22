#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "Street.h"
#include <vector>

using namespace std;
// class Street;

class Intersection
{
private:
    int id;
    vector<Street*> streetsStart, streetsEnd;

public:
    Intersection(int a_id);
    ~Intersection();
    void Update();
    void AddStartStreets(Street* a_street);
    void AddEndStreets(Street* a_street);
};



#endif