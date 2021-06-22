//
// Created by raf on 6/21/21.
//

#include "Header.h"
#include "external/tabulate/tabulate.hpp"
using namespace tabulate;

void Header::start() {
    Table table;

    table.add_row({
        "HW03 – Class Constructors, Inheritance & Init",
        "Raf Szuminski"
    });

    table.format()
        .multi_byte_characters(true)
        .font_style({FontStyle::bold, FontStyle::dark})
        .font_align(FontAlign::center)
        .font_color(Color::white)
        .font_background_color(Color::none);
    std::cout << table << std::endl;
}