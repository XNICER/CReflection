#include <iostream>

#include "CReflection.hpp"

void add(int a, int b)
{
    std::cout << a + b << std::endl;
}

void add_double(double a, double b)
{
    std::cout << a + b << std::endl;
}

void add_string(std::string a, std::string b, std::string c)
{
    std::cout << a + b + c<< std::endl;
}

void print(std::string a, int b)
{
    std::cout << "string: " << a << " int:" << b << std::endl;
}

int main()
{
    creflection Ins;
    Ins.regist_func("add", add);
    // Ins.regist_func("add_double", std::function(add));
    // Ins.regist_func("add_string", std::function<void(std::string, std::string, std::string)>(add_string));
    // Ins.regist_func("print", std::function<void(std::string, int)>(print));
    Ins.reflection_call("add", 1, 2);
    Ins.reflection_call("add", 1.1, 2);
    return 0;
}