//
//  Iblock.hpp
//  block
//
//  Created by Elva on 2018/7/22.
//  Copyright © 2018年 Elva. All rights reserved.
//

#ifndef Iblock_hpp
#define Iblock_hpp
#include "block.hpp"
#include <stdio.h>
#include<vector>
class Iblock :public Block {
public:
    Iblock(char type, int level);
    ~Iblock();
    void clockwise();
    void counterclock();
};

#endif /* Iblock_hpp */
