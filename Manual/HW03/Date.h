#ifndef HW03_DATE_H
#define HW03_DATE_H

//IGNORE TOP COMMENTS/NOTES//
#include <string>

/*
 * Hahahahah imagine getting a cylinder misfire followed by another misfire, taking apart the engine and then doing it Fri-Sun
 * and then at 3am on Sunday or I guess now Monday writing C++ code.. oh wait.
 *
 * Notes to me from me:
 * 1. Me you are still alive sanitize the god damn inputs, the thing you do with formik , that. I know what I mean just don't let the program shit itself due to an
 * input issues.
 *
 * 2. How do you wanna handle the dates? DD/MM/YY? Huh ok the date in the ex is 8/31/2014
 * so just when I fetch the value just construct a string and return that shit.
 *
 * 3. Now how do I deal with the god damn table, OAHSHDAHS HAHHA vector complex object. Wait no, although no I
 * don't want to write the fucking print over and over I want 1 print function from the base class and it should just
 * read the headers and values and print them. Idk i'll figure it out.
 *
 */

class Date {

private:
    int month;
    int day;
    int year;
public:
    Date();
    Date(int month, int day, int year);
    virtual ~Date();

    void setDate(int month, int day, int year);
    std::string getDate();

    int getMonth() const;

    void setMonth(int month);

    int getDay() const;

    void setDay(int day);

    int getYear() const;

    void setYear(int year);

    std::string asString() const;
};

#endif //HW03_DATE_H
