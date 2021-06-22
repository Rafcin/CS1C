#include "Date.h"

Date::Date() {

}

Date::Date(int month, int day, int year) : month(month), day(day), year(year) {

}

Date::~Date() {

}

std::string Date::getDate() {
    return std::to_string(month)+"/"+std::to_string(day)+"/"+std::to_string(year);
}

void Date::setDate(int month, int day, int year) {
    setMonth(month),setDay(day),setYear(year);
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

std::string Date::asString() const {
    return std::to_string(month)+"/"+std::to_string(day)+"/"+std::to_string(year);
}