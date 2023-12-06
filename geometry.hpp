//
//  geometry.hpp
//  Stuctural_paterns
//
//  Created by Polina on 06.12.2023.
//

#ifndef geometry_hpp
#define geometry_hpp

#include <stdio.h>

#endif /* geometry_hpp */

struct CartesianPoint{
    float x,y;
    CartesianPoint() = default;
    CartesianPoint(float x, float y): x(x), y(y){};
};

double GetDistance(CartesianPoint* p1, CartesianPoint* p2) noexcept;
