//
//  info.h
//  block
//
//  Created by Elva on 2018/7/19.
//  Copyright © 2018年 Elva. All rights reserved.
//

#ifndef info_h
#define info_h
#include "Posn.h"

struct Info {
    char type; // I; J; L; O; S; Z; T; all capital letters
    int level;
    int size = 4;
    std::vector<Posn> pos; // a vector with 4 posn initialized to (0,0);
};

#endif /* info_h */
