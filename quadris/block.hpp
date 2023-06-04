//
//  block.hpp
//  block
//
//  Created by Elva on 2018/7/19.
//  Copyright © 2018年 Elva. All rights reserved.
//

#ifndef block_hpp
#define block_hpp
#include <vector>
#include <stdio.h>
#include <iostream>
#include "Posn.h"
#include "info.h"


class Block {
    Info info;// a vector with 4 posn initialized to (0,0);
public:
    virtual ~Block();
    void settype(char type);
    void setlevel(int level);
    void setsize(int n){info.size = n;}
    void setpos(std::vector<Posn> p);
    void setblock(char type);
    char gettype();
    Info getinfo();
    void left();
    void right();
    void down();
    void drop(int distance);
    virtual void clockwise() = 0;
    virtual void counterclock() =0;
    void clear(int y);
};
#endif /* block_hpp */
