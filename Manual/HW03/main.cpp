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
    Employee user("Raf", "IM9071", "(949)-700-1000", 20, "M", "Head of Research", 50000, hired);
    user.print(Color::yellow);
    user.setId("IM9003");
    user.setPhone("(949)-221-8760");
    user.setName("Rafael");
    user.setHired(newHired);
    user.print(Color::green);

    Employee blankUser;
    blankUser.print(Color::red);
    blankUser.setName("Not Raf");
    blankUser.setId("IM0001");
    blankUser.setPhone("(909)-553-5109");
    blankUser.setAge(21);
    blankUser.setGender("M");
    blankUser.setTitle("Jr Developer");
    blankUser.setSalary(3000);
    blankUser.setHired(hired);
    blankUser.print(Color::green);

    Programmer blankprogrammer;
    blankprogrammer.print(Color::red);
    blankprogrammer.setName("Not Raf");
    blankprogrammer.setId("IM0001");
    blankprogrammer.setPhone("(909)-553-5109");
    blankprogrammer.setAge(21);
    blankprogrammer.setGender("M");
    blankprogrammer.setTitle("Jr Developer");
    blankprogrammer.setSalary(3000);
    blankprogrammer.setHired(hired);
    blankprogrammer.setLastSalaryIncrease(5);
    blankprogrammer.setDepartmentNumber(601);
    blankprogrammer.setKnowsCpp(true);
    blankprogrammer.setSupervisorName("Leandro");
    blankprogrammer.print(Color::green);

    Programmer programmer("Raf", "IM9071", "(949)-700-1000", 20, "M", "Software Engineer", 90000, hired, 60, "Ivan", 5, true, true);
    programmer.print(Color::yellow);
    programmer.setDepartmentNumber(23);
    programmer.print(Color::green);

    SoftwareArchitect softwareArchitect("Raf", "IM9071", "(949)-700-1000", 20, "M", "Lead Developer", 100001, hired, 10, "Alex", 9, 19);
    softwareArchitect.print(Color::yellow);
    softwareArchitect.setLastSalaryIncrease(3);
    softwareArchitect.print(Color::green);
    return 0;
}
