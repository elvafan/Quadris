//
//  Jblock.hpp
//  block
//
//  Created by Elva on 2018/7/22.
//  Copyright © 2018年 Elva. All rights reserved.
//

#ifndef Jblock_hpp
#define Jblock_hpp
#include "block.hpp"
#include <stdio.h>
#include<vector>
class Jblock :public Block {
public:
    Jblock(char type,int level);
    ~Jblock();
    void clockwise();
    void counterclock();
};
#endif /* Jblock_hpp */
