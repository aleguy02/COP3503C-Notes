#pragma once
#include <iostream>
#define NONTEMPLATE
#define TEMPLATE

#ifdef TEMPLATE
template<typename T>
class TemplateClass {
    public:
    T data;

    TemplateClass(const T& data) : data(data) {}
    TemplateClass(T&& data) : data(std::move(data)) {}

    // void printData() {
    //     std::cout << data << std::endl;
    // }
    void printData()
    {
        std::cout << data << std::endl;
    };
};
#endif

#ifdef NONTEMPLATE
class NonTemplateClass {
    public:
    int data;

    NonTemplateClass(const int& data) : data(data) {}

    // void printData() {
    //     std::cout << data << std::endl;
    // }
    void printData();
};
#endif