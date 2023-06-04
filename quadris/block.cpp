//
//  block.cpp
//  block
//
//  Created by Elva on 2018/7/19.
//  Copyright © 2018年 Elva. All rights reserved.
//

#include "block.hpp"
#include <vector>
using namespace std;
Block::~Block() {};

void Block::setblock(char type) {
    settype(type);
    vector<Posn> pos = info.pos;
    int l = pos.at(0).x; //the most left x of the block
    int r = pos.at(0).x; //the most right x of the block
    int b = pos.at(0).y; //the bottom y of the block
    for(unsigned int i = 0; i<pos.size(); i++) {
        if (pos.at(i).x < l) {
            l = pos.at(i).x;
        }
        if (pos.at(i).x > r) {
            r = pos.at(i).x;
        }
        if (pos.at(i).y < b) {
            b = pos.at(i).y;
        }
    }
    vector<Posn> n;
    if (type == 'L') {
        n.push_back({l+2, b+1});
        n.push_back({l,b});
        n.push_back({l+1,b});
        n.push_back({l+2,b});
    } else if (type == 'J') {
        n.push_back({l,b+1});
        n.push_back({l,b});
        n.push_back({l+1,b});
        n.push_back({l+2,b});
    } else if (type == 'T') {
        n.push_back({l,b+1});
        n.push_back({l+1,b+1});
        n.push_back({l+2,b+1});
        n.push_back({l+1, b});
    } else if (type == 'O') {
        n.push_back({l,b+1});
        n.push_back({l+1,b+1});
        n.push_back({l,b});
        n.push_back({l+1,b+1});
    } else if (type == 'Z') {
        n.push_back({l,b+1});
        n.push_back({l+1,b+1});
        n.push_back({l+1,b});
        n.push_back({l+2,b});
    } else if (type == 'S') {
        n.push_back({l+1,b+1});
        n.push_back({l+2,b+1});
        n.push_back({l,b});
        n.push_back({l+1,b});
    } else {
        n.push_back({l,b});
        n.push_back({l+1,b});
        n.push_back({l+2,b});
        n.push_back({l+3,b});
    }
    setpos(n);
}
void Block::settype(char type) {
    this->info.type = type;
}

void Block::setlevel(int level) {
    this->info.level = level;
}

void Block::setpos(std::vector<Posn> p){
    this->info.pos = p;
}

char Block::gettype() {
    return this->info.type;
}

Info Block::getinfo() {
    return this->info;
}
void Block::left() {
    for(unsigned int i = 0; i<info.pos.size(); i++) {
        Posn* p = &(info.pos).at(i);
        p->x = p->x -1;
    }
}

void Block::right() {
    for(unsigned int i = 0; i<info.pos.size(); i++) {
        Posn* p = &(info.pos).at(i);
        p->x = p->x + 1;
    }
}
void Block::down() {
    for(unsigned int i = 0; i<info.pos.size(); i++) {
        Posn* p = &(info.pos).at(i);
        p->y = p->y-1;
    }
}
void Block::drop(int distance) {
    for (int i = 0; i< 4; i ++){
        info.pos[i].y -= distance;
    }
}

void Block::clear(int y) {
    for(unsigned int i = 0; i<info.pos.size(); i++) {
        Posn* p = &(info.pos).at(i);
        if (p->y==y) {
            p->y = - 2;
        }
        if (p->y > y) {
            p->y = p->y -1;
        }
    }
}


