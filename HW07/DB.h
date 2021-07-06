//
// Created by raf on 7/6/21.
//

#ifndef HW07_DB_H
#define HW07_DB_H


#include <vector>
#include <memory>
#include "Item/Item.h"
#include "History/History.h"

class DB {
private:
   std::vector<Item> *storage;
   std::vector<History> *history;
public:
    DB();
    virtual ~DB();
    void put(Item item);
    void pop(int index);
    Item fetch(int index);
    Item fetch(std::string key);

    std::vector<Item> *getStorage() const;
    std::vector<History> *getHistory() const;
    const unsigned long size() const;
    int quantity(std::string type);
    void transactions();
};




#endif //HW07_DB_H
