//
//  Sblock.hpp
//  block
//
//  Created by Elva on 2018/7/22.
//  Copyright © 2018年 Elva. All rights reserved.
//

#ifndef Sblock_hpp
#define Sblock_hpp
#include "block.hpp"
#include <stdio.h>
#include<vector>
class Sblock :public Block {
public:
    Sblock(char type,int level);
    ~Sblock();
    void clockwise();
    void counterclock();
};
#endif /* Sblock_hpp */
