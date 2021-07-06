//
// Created by raf on 7/1/21.
//

#ifndef SANDBOX_WIDGET_H
#define SANDBOX_WIDGET_H


#include <string>
#include <memory>

class Widget {
private:
    int i { 0 };
    std::string s{};
    int* pi{ nullptr };
public:
    Widget(Widget&& w);
};


#endif //SANDBOX_WIDGET_H
