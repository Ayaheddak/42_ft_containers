# ifndef EQUAL_HPP
#define EQUAL_HPP
#include "enable_if.hpp"
#include "../iterators/iterator_traits.hpp"
#include "is_integral.hpp"
namespace ft
{
    template <class InputIterator1, class InputIterator2>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, typename ft::enable_if<!ft::is_integral<InputIterator1>::value, InputIterator1>::type = InputIterator1(), typename ft::enable_if<!ft::is_integral<InputIterator2>::value, InputIterator2>::type = InputIterator2())
    {
        while (first1!=last1) 
        {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred, typename ft::enable_if<!ft::is_integral<InputIterator1>::value, InputIterator1>::type = InputIterator1(), typename ft::enable_if<!ft::is_integral<InputIterator2>::value, InputIterator2>::type = InputIterator2())
    {
        while (first1!=last1) 
        {
            if (!pred(*first1,*first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }
}
#endif

/*
    - std::equal is a function in C++ that compares two ranges of elements and returns true if the elements in the two ranges are equal
    - first1 and last1 represent the range of elements in the first sequence, and first2 represents the beginning of the second sequence.
    - The function returns true if both sequences have the same number of elements and if the corresponding elements in both sequences are equal.

    when we use them :
    - The std::equal function is useful in many scenarios, such as comparing two containers or verifying if a range of elements matches a given pattern
    and The function uses the == operator to compare elements in the sequences. If the element types do not have an == operator defined,
    the function will not compile. If you need to compare elements based on a custom criteria,
    you can use the std::equal overload that takes a comparison function as an argument.

    - and the std::equal function also has another overload that takes a binary predicate as the fourth argument


    - you can use std::equal to compare any type of data that supports the == operator, including integers,
    floating-point numbers, booleans, and strings. When you compare two containers that contain elements of different types,
    the std::equal function will use the == operator of the element type to perform the comparison.

    - The BinaryPredicate is a function object that takes two arguments of the same type as the elements in the ranges, and returns a bool.
    The function object is used to compare the corresponding elements in the ranges instead of using the == operator.
    - This overload is useful when you need to compare elements based on a custom comparison criteria,
    such as comparing elements using a case-insensitive comparison or comparing elements by their absolute value.


*/