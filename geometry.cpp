//
//  geometry.cpp
//  Stuctural_paterns
//
//  Created by Polina on 06.12.2023.
//

#include "geometry.hpp"
#include <cmath>

double GetDistance(CartesianPoint* p1, CartesianPoint* p2)noexcept{
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y,2));
}
