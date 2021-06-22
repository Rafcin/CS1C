//
// Created by raf on 6/21/21.
//

#ifndef HW03_PROGRAMMER_H
#define HW03_PROGRAMMER_H


#include "Employee.h"
#include "external/tabulate/tabulate.hpp"
using namespace tabulate;

/**
 * @name Programmer
 * @brief This class inherits from Employee and adds dep num, supervisor name,
 * salary increase and two bools for knowledge in Java & C++
 *
 *
 */

class Programmer: public Employee {
private:
    int departmentNumber;
    std::string supervisorName;
    float lastSalaryIncrease;
    bool knowsCPP;
    bool knowsJAVA;
public:
    Programmer();

    Programmer(int departmentNumber, const std::string &supervisorName, float lastSalaryIncrease, bool knowsCpp,
               bool knowsJava);

    Programmer(const std::string &name, const std::string &id, const std::string &phone, int age,
               const std::string &gender, const std::string &title, float salary, const Date &hired,
               int departmentNumber, const std::string &supervisorName, float lastSalaryIncrease, bool knowsCpp,
               bool knowsJava);

    int getDepartmentNumber() const;

    void setDepartmentNumber(int departmentNumber);

    const std::string &getSupervisorName() const;

    void setSupervisorName(const std::string &supervisorName);

    float getLastSalaryIncrease() const;

    void setLastSalaryIncrease(float lastSalaryIncrease);

    bool isKnowsCpp() const;

    void setKnowsCpp(bool knowsCpp);

    bool isKnowsJava() const;

    void setKnowsJava(bool knowsJava);

    //Move this to the utils class from CS1B and move that to it's own repo.
    std::string boolAsString(bool _bool);

    void print(Color color);
};


#endif //HW03_PROGRAMMER_H

