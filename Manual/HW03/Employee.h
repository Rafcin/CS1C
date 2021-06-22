//
// Created by raf on 6/21/21.
//

#ifndef HW03_EMPLOYEE_H
#define HW03_EMPLOYEE_H


#include <string>
#include "Date.h"
#include "external/tabulate/tabulate.hpp"
using namespace tabulate;

/**
 * @name Employee
 * @brief the base class for all the other classes, defines the name, id, gender and all
 * other basic details of the employee.
 */

class Employee {
private:
    std::string name;
    std::string id;
    std::string phone;
    int age;
    std::string gender;
    std::string title;
    float salary;
    Date hired;
public:
    Employee();
    Employee(const std::string &name, const std::string &id, const std::string &phone, int age,
             const std::string &gender, const std::string &title, float salary, const Date &hired);
    virtual ~Employee();

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getPhone() const;

    void setPhone(const std::string &phone);

    int getAge() const;

    void setAge(int age);

    const std::string &getGender() const;

    void setGender(const std::string &gender);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    float getSalary() const;

    void setSalary(float salary);

    const Date getHired() const;

    void setHired(const Date &hired);

    void print(Color color);
};



#endif //HW03_EMPLOYEE_H
