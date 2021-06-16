//
// Created by raf on 6/15/21.
//

#include "Random.h"
#include <cstdlib>
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

Random::Random() {
    m_rand = rand() % 1000;
}

Random::~Random() {

}

int Random::getRand() const {
    return m_rand;
}

void Random::random() {
    m_rand = rand() % 1000;
}

int Random::sum() {
    std::vector<int> t = intToVec();
    int sum = 0;
    for(int i : t){
        sum += i;
    }
    return sum;
}

int Random::reverse() {
    std::vector<int> t = intToVec();
    std::reverse(t.begin(), t.end());
    return vecToInt(t);
}

int Random::trip() {
    std::vector<int> t = intToVec();
    for (int i = 0; i < t.size(); i++){
        t.at(i) = t[i] * 3;
    }
    return vecToInt(t);
}

int Random::sort(){
    std::vector<int> t = intToVec();
    std::sort(t.begin(),t.end());
    return vecToInt(t);
}

void Random::print() {
    std::vector<int> t = intToVec();
    std::cout<<"Random Number Array"<<std::endl;
    for(int i : t) {
        std::cout << i << std::endl;
    }
}

void Random::saveToFile() {
    std::vector<int> t = intToVec();
    std::ofstream file("output.txt");
    std::ostream_iterator<int> iterator(file, "\n");
    std::copy(t.begin(), t.end(), iterator);
}

int Random::readFromFile() {
    std::ifstream in("output.txt");
    std::string value;
    std::vector<int> t;
    while(std::getline(in, value)){
        if(value.size() > 0){
            t.push_back(std::stoi(value));
        }
    }
    return vecToInt(t);
}

std::vector<int> Random::intToVec() {
    std::vector<int> output;
    for (int i = log10(m_rand); i >= 0; i--) {
        output.push_back(m_rand / int(std::pow(10, i)) % 10);
    }
    return output;
}

int Random::vecToInt(std::vector<int> input) {
    int decimal = 1;
    int output = 0;
    std::reverse(input.begin(), input.end());
    for (auto& it : input){
        output += it * decimal;
        decimal *= 10;
    }
    return output;
}
