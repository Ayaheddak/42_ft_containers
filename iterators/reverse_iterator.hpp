#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
#include "iterator_traits.hpp"
#include "../containers/vector/vector.hpp"
#include <iterator>
/*
**A reverse iterator is an iterator that can be used to traverse a container in reverse order
**The typedefs are used to define type aliases
*/
namespace ft
{
    template <typename Iterator>
    //The class is declared as a template, which means that it can work with any type of iterator, as specified by the Iterator template parameter.
    class reverse_iterator
    {
        public :
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;
        /* ============================== MEMBER ATTRIBUTES ============================== */
        private :
            //is used to store the underlying iterator
            iterator_type _it;

        public :
        /* ============================== CONSTRUCTOR/DESTRUCTOR ============================== */
            //Constructs a reverse iterator that points to no object
            reverse_iterator():_it(){}
            /*
                the explicit keyword is used in constructor declarations
                to indicate that the constructor can only be used for explicit type conversion. 
                Explicit type conversion (also known as type casting)
                in C++ is a way to convert a value of one data type to another
            */
            explicit reverse_iterator (iterator_type it):_it(it){}
            /*
                The third constructor takes a const reference to another reverse_iterator object of type Iter,
                rev_it, and initializes _it with the result of calling rev_it.base()
            */
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it)
            {
                this->_it = rev_it.base();
            }
        /* ============================== MEMBER FUNCTION ============================== */
            /*
               Returns a copy of the base iterator.
            */
            iterator_type base() const
            {
                return (this->_it);
            }
        /* ============================== OPERATORS OVERLOADING ============================== */
            /*
                Dereference iterator "*""
                Returns a reference to the element pointed to by the iterator.
                --tmp cuz reverse iterator points to the element before the current one
            */
            reference operator*() const
            {
                iterator_type tmp;

                tmp = this->_it;
                return (*--tmp);
            }
            /*
                Returns a pointer to the element pointed to by the iterator (in order to access one of its members)
            */
            pointer operator->() const
            {
                return (&(operator*()));
            }
            /*
                Increment iterator position
                the pre-increment decrements the base iterator kept by the object
            */
            reverse_iterator& operator++()
            {
                --_it;
                return (*this);
            }
            /*
                the post-increment 
            */
            reverse_iterator operator++(int)
            {
                reverse_iterator tmp;
                
                tmp = *this;
                --_it;
                return (tmp);
            }
            reverse_iterator& operator--()
            {
                ++(this->_it);
                return (*this);
            }
            
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp;
                
                tmp = *this;
                ++(this->_it);
                return (tmp);
            }
            /*
                Returns a reverse iterator pointing to the element located n positions
                away from the element the iterator currently points to.
                Internally, the function applies the binary operator- on the base iterator and returns
                a reverse iterator constructed with the resulting iterator value.
            */
            reverse_iterator operator+(difference_type n) const//prb
            {
                return (reverse_iterator(this->_it - n));
            }

            reverse_iterator& operator+=(difference_type n)
            {
                this->_it -= n;
                return (*this);
            }
            /*
                
            */
            reverse_iterator operator-(difference_type n) const
            {
                return (reverse_iterator(this->_it + n));
            }

            reverse_iterator& operator-=(difference_type n)
            {
                this->_it += n;
                return (*this);
            }

            reference operator[](difference_type n) const
            {
                return (this->_it- n - 1);
            }
    };
    /*
        ============================== relational operators ===================================
    */

    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    
    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
    {
        return (reverse_iterator<Iterator>(rev_it.base() - n));
    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return (rhs.base() - lhs.base());
    }
}
#endif
/*
 const keyword at the end of the function signature means that the function will not modify the object on which it is called.
==========================================================================================================================
A reverse iterator in C++ is an iterator that iterates over a range of elements in reverse order,
from the last element to the first.It is used to traverse the elements of a container,
such as an array or a list, in a backward direction.Reverse iterators are useful in various scenarios, such as:
When you need to process the elements of a container in reverse order, for example, when you want to search for an
element from the end of a container.
When you want to access the elements of a container in reverse order, for example, when you want to reverse a string or when
you want to reverse a sequence of characters in a list.
When you need to make a reverse copy of a container, for example, when you want to make a backup of a list in reverse order.
Overall, reverse iterators provide a convenient and efficient way to traverse and manipulate the elements of a container in reverse order.
==========================================================================================================================
A reverse iterator in C++ allows you to traverse the elements of a container backwards. 
it is useful for processing elements in reverse order, accessing elements in reverse, and making a reverse copy of a container.

==========================================================================================================================
A reverse iterator works by starting from the last element of a container and moving backwards through the elements, towards the first element.
It does this by decrementing the position of the iterator instead of incrementing it.
When using a reverse iterator, you can use the same operations as you would with a regular iterator,
such as dereferencing the iterator to access the current element, incrementing or decrementing the iterator to move to the next or previous element, etc. However,
the behavior of these operations is slightly different when using a reverse iterator, as they are performed in the opposite direction.
For example, when incrementing a reverse iterator, the iterator will move to the previous element in the container,
rather than the next element. Similarly, when dereferencing a reverse iterator, it will give you access to the element before the current position,
rather than the element at the current position.
==========================================================================================================================

when the reverse_iterator is pointing to an element in the container,
that element is actually the next one that would be visited if the reverse_iterator were to be incremented
*/

/*

Dereferencing an iterator means accessing the element that the iterator is pointing to

*/