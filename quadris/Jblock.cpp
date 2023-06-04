//
//  Jblock.cpp
//  block
//
//  Created by Elva on 2018/7/22.
//  Copyright © 2018年 Elva. All rights reserved.
//

#include "Jblock.hpp"
using namespace std;
Jblock::Jblock(char type, int level) {
    settype(type);
    vector<Posn> pos;
    pos.push_back({0,14});
    pos.push_back({0,13});
    pos.push_back({1,13});
    pos.push_back({2,13});
    setpos(pos);
    setlevel(level);
}

void Jblock::clockwise(){
    vector<Posn> pos = getinfo().pos;
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
    if ((r - l) == 2) {
        int num = 0;
        for(unsigned int i = 0; i<pos.size(); i++) {
            if (pos.at(i).y == b) {
                num++;
            }
        }
        if (num == 3) {
            n.push_back({l,b+2});
            n.push_back({l+1,b+2});
            n.push_back({l,b+1});
            n.push_back({l,b});
        } else {
            n.push_back({l+1,b+2});
            n.push_back({l+1,b+1});
            n.push_back({l,b});
            n.push_back({l+1,b});
        }
        setpos(n);
    } else {
        int num = 0;
        for(unsigned int i = 0; i<pos.size(); i++) {
            if (pos.at(i).x == l) {
                num++;
            }
        }
        if (num == 3) {
            n.push_back({l,b+1});
            n.push_back({l+1,b+1});
            n.push_back({l+2,b+1});
            n.push_back({l+2,b});
        } else {
            n.push_back({l,b+1});
            n.push_back({l,b});
            n.push_back({l+1,b});
            n.push_back({l+2,b});
        }
        setpos(n);
    }
}

Jblock::~Jblock() {}

void Jblock::counterclock() {
    vector<Posn> pos = getinfo().pos;
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
    if ((r - l) == 2) {
        int num = 0;
        for(unsigned int i = 0; i<pos.size(); i++) {
            if (pos.at(i).y == b) {
                num++;
            }
        }
        if (num == 3) {
            n.push_back({l+1,b+2});
            n.push_back({l+1,b+1});
            n.push_back({l,b});
            n.push_back({l+1,b});
        } else {
            n.push_back({l,b+2});
            n.push_back({l+1,b+2});
            n.push_back({l,b+1});
            n.push_back({l,b});
        }
        setpos(n);
    } else {
        int num = 0;
        for(unsigned int i = 0; i<pos.size(); i++) {
            if (pos.at(i).x == l) {
                num++;
            }
        }
        if (num == 3) {
            n.push_back({l,b+1});
            n.push_back({l,b});
            n.push_back({l+1,b});
            n.push_back({l+2,b});
        } else {
            n.push_back({l,b+1});
            n.push_back({l+1,b+1});
            n.push_back({l+2,b+1});
            n.push_back({l+2,b});
        }
        setpos(n);
    }
}
