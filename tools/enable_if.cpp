#include <iostream>
#include <cmath>
#include "enable_if.hpp"
template<typename T>
typename ft::enable_if<std::is_integral<T>::value, T>::type
square(T x)
{
    return x * x;
}

int main()
{
    std::cout << square(5) << std::endl;
    return 0;
}
/*
    In this example, the square function template is defined to return the square of its argument,
    but it is only enabled (i.e. can be instantiated) if its argument type is an integral type (as determined by std::is_integral).
    The use of typename std::enable_if<...>::type specifies the return type of the function,
    and it is only defined if the std::is_integral expression is true.
*/