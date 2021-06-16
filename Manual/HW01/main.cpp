#include <iostream>
#include "Random.h"

int main() {
    Random random;
    random.random();
    std::cout << "Random Number: " << random.getRand() << std::endl;
    std::cout << "Sum: " << random.sum() << std::endl;
    std::cout << "Reverse: " << random.reverse() << std::endl;
    std::cout << "Triple: " << random.trip() << std::endl;
    std::cout << "Sort: " << random.sort() << std::endl;
    random.print();
    random.saveToFile();
    std::cout << "From File: " << random.readFromFile() << std::endl;
    return 0;
}
