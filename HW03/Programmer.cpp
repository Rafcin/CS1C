//
// Created by raf on 6/21/21.
//

#include "Programmer.h"
#include "external/tabulate/tabulate.hpp"
using namespace tabulate;

Programmer::Programmer() {}

Programmer::Programmer(const std::string &name, const std::string &id, const std::string &phone, int age,
                       const std::string &gender, const std::string &title, float salary, const Date &hired,
                       int departmentNumber, const std::string &supervisorName, float lastSalaryIncrease, bool knowsCpp,
                       bool knowsJava) : Employee(name, id, phone, age, gender, title, salary, hired),
                                         departmentNumber(departmentNumber), supervisorName(supervisorName),
                                         lastSalaryIncrease(lastSalaryIncrease), knowsCPP(knowsCpp),
                                         knowsJAVA(knowsJava) {}

Programmer::Programmer(int departmentNumber, const std::string &supervisorName, float lastSalaryIncrease, bool knowsCpp,
                       bool knowsJava) : departmentNumber(departmentNumber), supervisorName(supervisorName),
                                         lastSalaryIncrease(lastSalaryIncrease), knowsCPP(knowsCpp),
                                         knowsJAVA(knowsJava) {}
/**
 * @name Getters & Setters
 * @brief I have to fix my car and take apart my entire engine today & deploy a new website so
 * i'm going to keep the comments short and to the point. These are the getter and setters, they get values and set values.
 */

int Programmer::getDepartmentNumber() const {
    return departmentNumber;
}

void Programmer::setDepartmentNumber(int departmentNumber) {
    Programmer::departmentNumber = departmentNumber;
}

const std::string &Programmer::getSupervisorName() const {
    return supervisorName;
}

void Programmer::setSupervisorName(const std::string &supervisorName) {
    Programmer::supervisorName = supervisorName;
}

float Programmer::getLastSalaryIncrease() const {
    return lastSalaryIncrease;
}

void Programmer::setLastSalaryIncrease(float lastSalaryIncrease) {
    Programmer::lastSalaryIncrease = lastSalaryIncrease;
}

bool Programmer::isKnowsCpp() const {
    return knowsCPP;
}

void Programmer::setKnowsCpp(bool knowsCpp) {
    knowsCPP = knowsCpp;
}

bool Programmer::isKnowsJava() const {
    return knowsJAVA;
}

void Programmer::setKnowsJava(bool knowsJava) {
    knowsJAVA = knowsJava;
}

std::string Programmer::boolAsString(bool _bool) {
    return _bool ? "true" : "false";
}

/**
 * @name print()
 * @return Employee
 * @brief Returns a table of the programmer data.
 */

void Programmer::print(Color color) {
    Table programmer;
    programmer.add_row({"Name", "Department", "Supervisor", "Salary Increase", "Knows Java", "Knows C++"});
    programmer.add_row({
        getName(), std::to_string(departmentNumber), supervisorName, std::to_string(lastSalaryIncrease), boolAsString(knowsJAVA), boolAsString(knowsCPP)
    });

    for (size_t i = 0; i < 6; ++i) {
        programmer[0][i].format()
                .font_color(color)
                .font_align(FontAlign::center)
                .font_style({FontStyle::bold});
    }

    std::cout << programmer << std::endl;
}