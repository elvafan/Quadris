//
//  Lblock.hpp
//  block
//
//  Created by Elva on 2018/7/22.
//  Copyright © 2018年 Elva. All rights reserved.
//

#ifndef Lblock_hpp
#define Lblock_hpp
#include "block.hpp"
#include <stdio.h>
#include<vector>
class Lblock :public Block {
public:
    Lblock(char type,int level);
    ~Lblock();
    void clockwise();
    void counterclock();
};
#endif /* Lblock_hpp */
