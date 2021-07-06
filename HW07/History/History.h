//
// Created by raf on 7/6/21.
//

#ifndef HW07_HISTORY_H
#define HW07_HISTORY_H


#include <string>
#include "../Item/Item.h"

struct History {
    std::string action;
    Item item;
    int quantity;
};


#endif //HW07_HISTORY_H
