//
// Created by raf on 6/28/21.
//

#ifndef HW05_LOTTERY_H
#define HW05_LOTTERY_H

#include <vector>
#include "external/tabulate/tabulate.hpp"

class Lottery {
private:
    std::vector<int> key;
    std::vector<int> range;
public:
    Lottery();

    Lottery(int rsize, int ksize);
    virtual ~Lottery();

    const std::vector<int> &getKey() const;

    void setKey(const std::vector<int> &key);

    const std::vector<int> &getRange() const;

    void setRange(const std::vector<int> &range);

    void keygen(int rsize, int ksize);

    void print();

    bool operator==(const Lottery &rhs) const;

    bool operator!=(const Lottery &rhs) const;
};

#endif //HW05_LOTTERY_H


