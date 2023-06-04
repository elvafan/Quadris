//
//  Tblock.hpp
//  block
//
//  Created by Elva on 2018/7/22.
//  Copyright © 2018年 Elva. All rights reserved.
//

#ifndef Tblock_hpp
#define Tblock_hpp
#include "block.hpp"
#include <stdio.h>
#include<vector>

class Tblock :public Block {
public:
    Tblock(char type, int level);
    ~Tblock();
    void clockwise();
    void counterclock();
};
#endif /* Tblock_hpp */
