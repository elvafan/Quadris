//
//  Zblock.hpp
//  block
//
//  Created by Elva on 2018/7/22.
//  Copyright © 2018年 Elva. All rights reserved.
//

#ifndef Zblock_hpp
#define Zblock_hpp
#include "block.hpp"
#include <stdio.h>
#include<vector>
class Zblock :public Block {
public:
    Zblock(char type, int level);
    ~Zblock();
    void clockwise();
    void counterclock();
};
#endif /* Zblock_hpp */
