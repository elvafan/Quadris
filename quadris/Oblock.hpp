//
//  Oblock.hpp
//  block
//
//  Created by Elva on 2018/7/22.
//  Copyright © 2018年 Elva. All rights reserved.
//

#ifndef Oblock_hpp
#define Oblock_hpp
#include "block.hpp"
#include<vector>
class Oblock :public Block {
public:
    Oblock(char type, int level);
    ~Oblock();
    void clockwise();
    void counterclock();
};

#include <stdio.h>

#endif /* Oblock_hpp */
