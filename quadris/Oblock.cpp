//
//  Oblock.cpp
//  block
//
//  Created by Elva on 2018/7/22.
//  Copyright © 2018年 Elva. All rights reserved.
///Users/fanxinyuan/Desktop/block/block/info.h

#include "Oblock.hpp"
using namespace std;
Oblock::Oblock(char type, int level){
    settype(type);
    vector<Posn> pos;
    pos.push_back({0,14});
    pos.push_back({1,14});
    pos.push_back({0,13});
    pos.push_back({1,13});
    setpos(pos);
    setlevel(level);
}

Oblock::~Oblock() {}

void Oblock::clockwise(){}

void Oblock::counterclock(){}
