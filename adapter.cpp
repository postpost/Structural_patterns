//
//  adapter.cpp
//  Stuctural_paterns
//
//  Created by Polina on 06.12.2023.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
#include "geometry.hpp"

struct PolarPoint{
    float r_;
    float phi_;
    
    //constructor
    PolarPoint (float r, float phi) noexcept: r_(r), phi_(phi){};
};

//create adapter to CartesianPoint
//переопределяем конструктор у того класса, к которому подсоединяем адаптер
struct PointAdapter:public CartesianPoint{
    explicit PointAdapter(const PolarPoint& p) noexcept: CartesianPoint(){
        x = p.r_*cos(p.phi_);
        y = p.r_*sin(p.phi_);
    }
};

int main_01 (){
    std::cout << "Cartesian coordinates:\n";
    //создаем указатели на объекты
    auto cp1 = new CartesianPoint(11.04, 45.5);
    auto cp2 = new CartesianPoint(17.44, 25.09);
    std::cout << GetDistance(cp1, cp2) << std::endl;
   
    delete cp1;
    delete cp2;
    
    std::cout << "Polar coordinates:\n";
    //создаем объекты (не указатели!!!)
    PolarPoint pp1(35.12, M_PI);
    PolarPoint pp2(35.12, M_PI/2);
    
    //create adapter to Polar Coordinates
    PointAdapter ad_pp1(pp1);
    PointAdapter ad_pp2(pp2);
    std::cout << GetDistance(std::addressof(ad_pp1), std::addressof(ad_pp2))<< std::endl;
        
    return 0;
}



