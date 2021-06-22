//
// Created by raf on 6/21/21.
//

#include "SoftwareArchitect.h"
#include "external/tabulate/tabulate.hpp"
using namespace tabulate;

SoftwareArchitect::SoftwareArchitect() {

}

SoftwareArchitect::SoftwareArchitect(const std::string &name, const std::string &id, const std::string &phone, int age,
                                     const std::string &gender, const std::string &title, float salary,
                                     const Date &hired, int departmentNumber, const std::string &supervisorName,
                                     float lastSalaryIncrease, int yearsOfExperience) : Employee(name, id, phone, age,
                                                                                                 gender, title, salary,
                                                                                                 hired),
                                                                                        departmentNumber(
                                                                                                departmentNumber),
                                                                                        supervisorName(supervisorName),
                                                                                        lastSalaryIncrease(
                                                                                                lastSalaryIncrease),
                                                                                        yearsOfExperience(
                                                                                                yearsOfExperience) {}

SoftwareArchitect::SoftwareArchitect(int departmentNumber, const std::string &supervisorName, float lastSalaryIncrease,
                                     int yearsOfExperience) : departmentNumber(departmentNumber),
                                                              supervisorName(supervisorName),
                                                              lastSalaryIncrease(lastSalaryIncrease),
                                                              yearsOfExperience(yearsOfExperience) {}
SoftwareArchitect::~SoftwareArchitect() {

}

int SoftwareArchitect::getDepartmentNumber() const {
    return departmentNumber;
}

void SoftwareArchitect::setDepartmentNumber(int departmentNumber) {
    SoftwareArchitect::departmentNumber = departmentNumber;
}

const std::string &SoftwareArchitect::getSupervisorName() const {
    return supervisorName;
}

void SoftwareArchitect::setSupervisorName(const std::string &supervisorName) {
    SoftwareArchitect::supervisorName = supervisorName;
}

float SoftwareArchitect::getLastSalaryIncrease() const {
    return lastSalaryIncrease;
}

void SoftwareArchitect::setLastSalaryIncrease(float lastSalaryIncrease) {
    SoftwareArchitect::lastSalaryIncrease = lastSalaryIncrease;
}

int SoftwareArchitect::getYearsOfExperience() const {
    return yearsOfExperience;
}

void SoftwareArchitect::setYearsOfExperience(int yearsOfExperience) {
    SoftwareArchitect::yearsOfExperience = yearsOfExperience;
}

std::string SoftwareArchitect::boolAsString(bool _bool) {
    return _bool ? "true" : "false";
}

/**
 * @name print()
 * @return Employee
 * @brief Returns a table of the programmer data.
 */
void SoftwareArchitect::print(Color color) {
    Table programmer;
    programmer.add_row({"Name", "Department", "Supervisor", "Salary Increase", "Years of Experience"});
    programmer.add_row({
        getName(), std::to_string(departmentNumber), supervisorName, std::to_string(lastSalaryIncrease), std::to_string(yearsOfExperience)
    });

    for (size_t i = 0; i < 5; ++i) {
        programmer[0][i].format()
                .font_color(color)
                .font_align(FontAlign::center)
                .font_style({FontStyle::bold});
    }

    std::cout << programmer << std::endl;
}
