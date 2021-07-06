//
// Created by raf on 7/6/21.
//

#include <iostream>
#include "DB.h"


DB::DB() {
    storage = new std::vector<Item>();
    history = new std::vector<History>();
}
DB::~DB() {

}

//puts item in DB
void DB::put(Item item) {
    storage->push_back(item);
    history->push_back({"ADD", item, quantity(item.type)});
}

//pops item from DB
void DB::pop(int index) {
    //sshhhhhh
    Item temp = storage->at(index);
    storage->erase(storage->begin() + index);
    history->push_back({"REMOVE", temp, quantity(temp.type)});
}

//get item by index
Item DB::fetch(int index){
    return storage->at(index);
}

//getters for storage and history
std::vector<Item> *DB::getStorage() const {
    return storage;
}

std::vector<History> *DB::getHistory() const {
    return history;
}

//get item by key
Item DB::fetch(std::string key){
    auto it = find_if(storage->begin(), storage->end(), [key](const Item& obj) {return obj.key == key;});
    if (it != storage->end()){
        auto index = std::distance(storage->begin(), it);
        return storage->at(index);
    }
}

//gets DB size (honestly dunno why I wrote this, I blame the pain)
const unsigned long DB::size() const {
    return storage->size();
}

//gets # of items by type
int DB::quantity(std::string type) {
    int count = std::count_if(storage->begin(), storage->end(), [type](const Item& obj) {return obj.type == type;});
    return count;
}

void DB::transactions() {
    for(History h : *history) {
        std::cout << h.action << " | " << h.item.name << " | " << h.quantity << std::endl;
    }
}