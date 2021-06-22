#include "Employee.h"
#include "external/tabulate/tabulate.hpp"
using namespace tabulate;

Employee::Employee() {

}

Employee::Employee(const std::string &name, const std::string &id, const std::string &phone, int age,
                   const std::string &gender, const std::string &title, float salary, const Date &hired) : name(name),
                                                                                                           id(id),
                                                                                                           phone(phone),
                                                                                                           age(age),
                                                                                                           gender(gender),
                                                                                                           title(title),
                                                                                                           salary(salary),
                                                                                                           hired(hired) {}

Employee::~Employee() {

}
/**
 * @name getName()
 * @return name
 * @brief Getter | Get's Employee Name.
 */
const std::string &Employee::getName() const {
    return name;
}

/**
 * @name setName()
 * @return void
 * @brief Setter | Set's Employee Name.
 */
void Employee::setName(const std::string &name) {
    Employee::name = name;
}

/**
 * @name getId()
 * @return id
 * @brief Getter | Get's Employee Id.
 */
const std::string &Employee::getId() const {
    return id;
}

/**
 * @name setId()
 * @return void
 * @brief Setter | Set's Employee Id.
 */
void Employee::setId(const std::string &id) {
    Employee::id = id;
}

/**
 * @name getPhone()
 * @return phone
 * @brief Getter | Get's Employee Phone.
 */
const std::string &Employee::getPhone() const {
    return phone;
}

/**
 * @name setPhone()
 * @return void
 * @brief Setter | Set's Employee Phone.
 */
void Employee::setPhone(const std::string &phone) {
    Employee::phone = phone;
}

/**
 * @name getAge()
 * @return phone
 * @brief Getter | Get's Employee Age.
 */
int Employee::getAge() const {
    return age;
}

/**
 * @name setAge()
 * @return void
 * @brief Setter | Set's Employee Age.
 */
void Employee::setAge(int age) {
    Employee::age = age;
}

/**
 * @name getGender()
 * @return gender
 * @brief Getter | Get's Employee Gender.
 */
const std::string &Employee::getGender() const {
    return gender;
}

/**
 * @name setGender()
 * @return void
 * @brief Setter | Set's Employee Gender.
 */
void Employee::setGender(const std::string &gender) {
    Employee::gender = gender;
}

/**
 * @name getTitle()
 * @return title
 * @brief Getter | Get's Employee Title.
 */
const std::string &Employee::getTitle() const {
    return title;
}

/**
 * @name setTitle()
 * @return void
 * @brief Setter | Set's Employee Title.
 */
void Employee::setTitle(const std::string &title) {
    Employee::title = title;
}

/**
 * @name getSalary()
 * @return salary
 * @brief Getter | Get's Employee Salary.
 */
float Employee::getSalary() const {
    return salary;
}

/**
 * @name setSalary()
 * @return void
 * @brief Setter | Set's Employee Salary.
 */
void Employee::setSalary(float salary) {
    Employee::salary = salary;
}

/**
 * @name getHired()
 * @return hired
 * @brief Getter | Get's Employee Hired.
 */
const Date Employee::getHired() const {
    return hired;
}

/**
 * @name setHired()
 * @return void
 * @brief Setter | Set's Employee Hired.
 */
void Employee::setHired(const Date &hired) {
    Employee::hired = hired;
}

/**
 * @name print()
 * @return Employee
 * @brief Returns a table of the employee data.
 */
void Employee::print(Color color) {
    Table employee;
    employee.add_row({"Name", "ID", "Age", "Gender", "Job Title", "Salary", "Hired", "Phone Number"});
    employee.add_row({name, id, std::to_string(age), gender, title, std::to_string(salary), hired.asString(), phone});

    for (size_t i = 0; i < 8; ++i) {
        employee[0][i].format()
                .font_color(color)
                .font_align(FontAlign::center)
                .font_style({FontStyle::bold});
    }

    std::cout << employee << std::endl;
}