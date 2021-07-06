//
// Created by raf on 7/1/21.
//

#include "Widget.h"

Widget::Widget(Widget &&w) : i{w.i}, s{std::move(w.s)}, pi{std::exchange(w.pi, nullptr)} {

}