#include <iostream>
#include "DB.h"

int main() {
    DB database;
    database.put({"NKS001", "Nike Sport Shoes", 145.99, "NKS"});
    std::cout << database.fetch(0).name << std::endl;
    std:: cout << database.quantity("NKS") << std::endl;
    database.pop(0);
    database.transactions();
    return 0;
}
