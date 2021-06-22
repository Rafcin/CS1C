#include <iostream>
#include "Date.h"
#include "Employee.h"
#include "Programmer.h"
#include "SoftwareArchitect.h"
#include "external/tabulate/tabulate.hpp"
#include "Header.h"

using namespace tabulate;

int main() {
    Header header;
    header.start();

    Date hired( 12, 11, 2020);
    Date newHired(9, 5,2021);

    Programmer programmer("Raf", "IM9071", "(949)-700-1000", 20, "M", "Software Engineer", 90000, hired, 60, "Ivan", 5, true, true);
    SoftwareArchitect softwareArchitect("Raf", "IM9071", "(949)-700-1000", 20, "M", "Lead Developer", 100001, hired, 10, "Alex", 9, 19);

    Employee userA("Raf", "IM9071", "(949)-700-1000", 20, "M", "Head of Research", 50000, hired);
    userA.print(Color::green);


    Employee userB("Raf", "IM9076", "(949)-700-2000", 20, "M", "Head of UX/UI Design", 90000, hired);
    userB.print(Color::green);

    if(userA.operator==(userB)){
        std::cout<<"Phone Numbers are equal"<<std::endl;
    }else{
        std::cout<<"Phone Numbers are not equal"<<std::endl;
    }

    userA.setPhone("(949)-551-1125");
    userB.setPhone("(949)-551-1125");
    userA.print(Color::yellow);
    userB.print(Color::yellow);

    if(userA.operator==(userB)){
        std::cout<<"Phone Numbers are equal"<<std::endl;
    }else{
        std::cout<<"Phone Numbers are not equal"<<std::endl;
    }

    programmer.print(Color::blue);
    userA.print(Color::green);

    if(userA.operator==(programmer)){
        std::cout<<"Phone Numbers are equal"<<std::endl;
    }else{
        std::cout<<"Phone Numbers are not equal"<<std::endl;
    }

    std::cout << userA <<std::endl;

    return 0;
}
