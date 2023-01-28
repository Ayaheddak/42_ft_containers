#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP
#include <iterator>
namespace ft
{
    template<typename Category, typename T, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&>
    struct iterator
    {
        typedef value_type = T;
        typedef difference_type = Distance;
        typedef T* = Pointer;
        typedef T& = Reference;
        typedef random_access_iterator = Category;
    };
    class MyIterator : public std::iterator<std::random_access_iterator, int>
    {};
}
#endif