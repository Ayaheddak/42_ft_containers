# ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP
namespace ft
{
    /*
        - the function compares two sequences [first1, last1) and [first2, last2) using the operator< for the element type
    */
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,InputIterator2 first2, InputIterator2 last2 typename ft::enable_if<!ft::is_integral<InputIterator1>::value, InputIterator1>::type = InputIterator1(), typename ft::enable_if<!ft::is_integral<InputIterator2>::value, InputIterator2>::type = InputIterator2())
    {
        while (first1 != last1) 
        {
            if (*first1 < *first2)
                return true;
            else if (*first2 < *first1)
                return false;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }
    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2,Compare comp  typename ft::enable_if<!ft::is_integral<InputIterator1>::value, InputIterator1>::type = InputIterator1(), typename ft::enable_if<!ft::is_integral<InputIterator2>::value, InputIterator2>::type = InputIterator2())
    {
        while (first1 != last1) 
        {
            if (comp(*first1, *first2))
                return true;
            else if (comp(*first2,*first1))
                return false;
            ++first1;
            ++first2;
        }
        return (first2!=last2);
    }
}
#endif

/*
    - std::lexicographical_compare is a function in C++ that compares the elements of two sequences lexicographically.
    In other words, it determines whether one sequence is less than another sequence when the sequences are ordered
    alphabetically or based on their position in the ASCII table.The function returns true if the first sequence
    is less than the second sequence, and false otherwise.
*/