#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP
namespace ft
{
        template <class Iterator>
    struct iterator_traits
    {
            typedef typename Iterator::difference_type     difference_type; // type of distance between two iterators
            typedef typename Iterator::value_type           value_type; //type of element pointed by the iterator
            typedef typename Iterator::pointer              pointer; // type of pointer to the element pointed by the iterator
            typedef typename Iterator::reference            reference; // type of reference to the element pointed by the iterator
            typedef typename Iterator::iterator_category    iterator_category;//random or output or input or forward or bidirectional ....
    };
    
        template <class T>
    struct iterator_traits<T*>
    {
            typedef std::ptrdiff_t                      difference_type;
            typedef T                                   value_type;
            typedef T*                                  pointer;
            typedef T&                                  reference;
            typedef std::random_access_iterator_tag     iterator_category;
    };

        template <class T>
    struct iterator_traits<const T*>
    {
            typedef std::ptrdiff_t                              difference_type;
            typedef T                                           value_type; 
            typedef const T*                                    pointer; 
            typedef const T&                                    reference; 
            typedef std::random_access_iterator_tag             iterator_category;
    };
}
#endif
/*
Iterator traits are templates that allow you to customize the behavior of iterators based on their characteristics. They provide
a way to determine the properties of an iterator, such as its category and the type of elements it can access.
Reverse iterators are a type of iterator that allow you to iterate through a container in reverse order.
They are typically implemented as a wrapper around another iterator that provides the opposite traversal order.
*/