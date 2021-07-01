//
// Created by raf on 6/28/21.
//

#include "Lottery.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "external/tabulate/tabulate.hpp"

const std::vector<int> &Lottery::getKey() const {
    return key;
}

/**
 * @name setKey
 * @brief sets key
 * @param key
 */

void Lottery::setKey(const std::vector<int> &key) {
    Lottery::key = key;
}

/**
 * @name getRange
 * @brief returns the range
 * @return vector<int>
 */

const std::vector<int> &Lottery::getRange() const {
    return range;
}

/**
 * @name setRange
 * @brief sets range
 * @param range
 */

void Lottery::setRange(const std::vector<int> &range) {
    Lottery::range = range;
}

/**
 * @name keygen
 * @brief creates a random key based on the range size and key size. The range size determines what range of numbers to use
 * and key determines the set of numbers needed.
 * @param rsize
 * @param ksize
 */

void Lottery::keygen(int rsize, int ksize) {
    try{
        if(ksize <= rsize){
            for(size_t i=1; i<=rsize;i++){
                range.push_back(i);
            }
            std::random_shuffle(range.begin(), range.end());
            //Wanna see a trick? Copy constructors are kinda cool. We slice from start to size.
            //Note Next apparently only works on C++ 11+
            key = std::vector<int>(range.begin(), std::next(range.begin(), ksize));
            //And now we sort with ease.
            std::sort(key.begin(), key.end());
        }
    }catch(std::exception const& e){
        std::cout << "Key size can not be greater than Range size." << e.what() << std::endl;
    }
}

bool Lottery::operator==(const Lottery &rhs) const {
    return key == rhs.key &&
           range == rhs.range;
}

bool Lottery::operator!=(const Lottery &rhs) const {
    return !(rhs == *this);
}

/**
 * @name print
 * @brief Prints the values in a table.
 */

void Lottery::print() {
    tabulate::Table card;
    card.add_row({"Keygen Table"});
    card.row(0).format()
            .font_color(tabulate::Color::green)
            .font_align(tabulate::FontAlign::center)
            .font_style({tabulate::FontStyle::bold});
    std::stringstream ss;
    for(size_t i=0; i<key.size();i++){
        if(i != 0){
            ss << ", ";
        }
        ss << key[i];
    }
    std::string list = ss.str();
    card.add_row({list});
    std::cout << card << std::endl;

    tabulate::Table info;
    info.add_row({"⚠ Debug | Notes ⚠"});
    info.add_row({"If you want you can use the getters and setters to access the key value. Key can be retrieved via getKey() \n"
                  "And should you want to regen the key, you can always do keygen()"});

    info.row(1).format()
            .font_align(tabulate::FontAlign::center);

    info.row(0).format()
            .font_color(tabulate::Color::yellow)
            .font_align(tabulate::FontAlign::center)
            .font_style({tabulate::FontStyle::bold});

    std::cout << info << std::endl;
}

Lottery::Lottery() {
    Lottery::keygen(rand()%10+1, rand()%10+1);
}

Lottery::Lottery(int rsize, int ksize) {
    Lottery::keygen(rsize, ksize);
}

Lottery::~Lottery() {

}


