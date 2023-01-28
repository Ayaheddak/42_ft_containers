// #define red(str) "\033[1;31m"#str"\033[0m"
// #define green(str) "\033[1;32m"#str"\033[0m"
// #define default(str) "\033[0m"#str"\033[0m"
#include "random_acess_iterator.hpp"
#define blue "\e[0;34m"
#define red "\e[0;31m"
#define Green "\e[0;32m"
#define Default "\e[0m"
#include <iostream>
#include <iterator>
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ft::iterator<int> it1(arr);
    ft::iterator<int> it2(arr + 3);

    if (it1 == it2)
        std::cout << Green <<"it1 and it2 are equal" << Default << std::endl;
    std::cout << red << "it1 and it2 are not equal" << Default << std::endl;
    
    if (it1 < it2)
        std::cout << blue << "it1 is less than it2" << Default << std::endl;
    else
        std::cout << blue << "it1 is not less than it2" << Default << std::endl;

    if (it1 > it2)
        std::cout << blue << "it1 is greater than it2" << Default << std::endl;
    else
        std::cout << blue << "it1 is not greater than it2" << Default << std::endl;

    if (it1 <= it2)
        std::cout << blue << "it1 is less than or equal to it2" << Default << std::endl;
    else 
        std::cout << blue << "it1 is not less than or equal to it2" << Default << std::endl;

    if (it1 >= it2)
        std::cout << blue << "it1 is greater than or equal to it2" << Default << std::endl;
    else 
        std::cout << blue << "it1 is not greater than or equal to it2" << Default << std::endl;
    std::cout << red << *it1 << Default << std::endl;
    std::cout << red << *it2 << Default << std::endl;
    it1 += 2;
    std::cout << red << *it1 << Default <<std::endl;
    it2 -= 1;
    std::cout << red << *it2 << Default <<std::endl;
    it1++;
    std::cout << red << *it1 << Default <<std::endl;
    ++it1;
    std::cout << red << *it1 << Default <<std::endl;
    it2--;
    std::cout << red << *it2 << Default <<std::endl;
    --it2;
    std::cout << red << *it2 << Default <<std::endl;
    it2 = it1 - 2;
    std::cout << red << *it2 << Default <<std::endl;
    it2 = it1 + 1;
    std::cout << red << *it2 << Default <<std::endl;
    it2 += 1;
    std::cout << red << *it2 << Default <<std::endl;
    it2 -= 1;
    std::cout << red << *it2 << Default <<std::endl;
    ft::iterator<int> it3(arr);
    std::cout << blue << it3[4] << Default << std::endl;
    return 0;
}

