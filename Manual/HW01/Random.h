//
// Created by raf on 6/15/21.
//

#ifndef HW01_RANDOM_H
#define HW01_RANDOM_H


#include <vector>

class Random {
public:
    int m_rand;

    Random();
    ~Random();

    int getRand() const;

    void random();
    int sum();
    int reverse();
    int trip();
    int sort();

    void print();
    void saveToFile();
    int readFromFile();
private:
    std::vector<int> intToVec();
    int vecToInt(std::vector<int> input);
};


#endif //HW01_RANDOM_H
