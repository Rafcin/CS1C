//
// Created by raf on 6/21/21.
//

#ifndef HW03_SOFTWAREARCHITECT_H
#define HW03_SOFTWAREARCHITECT_H


#include <string>
#include "Employee.h"
#include "external/tabulate/tabulate.hpp"
using namespace tabulate;

/**
 * @name SoftwareArchitect
 * @brief This class inherits from Employee and adds the paramaters dep num, supervisor name, salary increase and years of experience.
 *
 */

class SoftwareArchitect: public Employee {
private:
    int departmentNumber;
    std::string supervisorName;
    float lastSalaryIncrease;
    int yearsOfExperience;
public:
    SoftwareArchitect();

    SoftwareArchitect(const std::string &name, const std::string &id, const std::string &phone, int age,
                      const std::string &gender, const std::string &title, float salary, const Date &hired,
                      int departmentNumber, const std::string &supervisorName, float lastSalaryIncrease,
                      int yearsOfExperience);

    SoftwareArchitect(int departmentNumber, const std::string &supervisorName, float lastSalaryIncrease,
                      int yearsOfExperience);

    virtual ~SoftwareArchitect();

    int getDepartmentNumber() const;

    void setDepartmentNumber(int departmentNumber);

    const std::string &getSupervisorName() const;

    void setSupervisorName(const std::string &supervisorName);

    float getLastSalaryIncrease() const;

    void setLastSalaryIncrease(float lastSalaryIncrease);

    int getYearsOfExperience() const;

    void setYearsOfExperience(int yearsOfExperience);

    //Move this to the utils class from CS1B and move that to it's own repo.
    std::string boolAsString(bool _bool);

    void print(Color color);
};



#endif //HW03_SOFTWAREARCHITECT_H
