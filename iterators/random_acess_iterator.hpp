#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP
#include <iostream>
namespace ft
{
    template <typename T>
    class iterator
    {
        public :

            typedef T value_type; //type of the value
            typedef std::ptrdiff_t difference_type; //difference between two iterators(distance)
            typedef T* pointer; //pointer to the value_type
            typedef T& reference; //reference to the value_type
            typedef std::random_access_iterator_tag iterator_category;//type of iterator

        public :
        /*
            ======================= Canonical Form =============================
        */
            iterator():_ptr(NULL){}
            iterator(pointer ptr):_ptr(ptr){}//done
            iterator(const iterator& other):_ptr(other._ptr) {}
            template <class U>
            iterator& operator=(const iterator<U>& other)
            {
                this->_base = other._base;
                return (*this);
            }
            ~iterator() {}
        /* 
            ==============================getter and setter ===================================
        */
            pointer base() const
            {
                return (this->_ptr);
            }
        /*
            ============================== comparision ===================================
        */
            //TODO: template bcz we need to check if the other iterator is of the same type
            template <class U>
            bool operator==(const iterator<U> &other) const
            {
                std::cout << "iterator == operator" << std::endl;
                return (this->_ptr == other.base());
            }
        
            template <class U>
            bool operator!=(const iterator<U> & other) const
            {
                std::cout << "iterator != operator" << std::endl;
                return (this->_ptr != other.base());
            }

            template <class U>
            bool operator<(const iterator<U> & other) const
            {
                std::cout << "iterator < operator" << std::endl;
                return (this->_ptr < other.base());
            }

            template <class U>
            bool operator>(const iterator<U> & other) const
            {
                std::cout << "iterator > operator" << std::endl;
                return (this->_ptr > other.base());
            }

            template <class U>
            bool operator<=(const iterator<U> & other) const
            {
                std::cout << "iterator <= operator" << std::endl;
                return (this->_ptr <= other.base());
            }

            template <class U>
            bool operator>=(const iterator<U> & other) const
            {
                std::cout << "iterator >= operator" << std::endl;
                return (this->_ptr >= other.base());
            }
        /*
            ============================= Arithmitics ====================================
        */
            iterator& operator++()
            {
                std::cout << "iterator ++ operator" << std::endl;
                this->_ptr++;
                return (*this);
            }

            iterator operator++(int)
            {  
                std::cout << "iterator ++(int) operator" << std::endl;
                iterator tmp(*this);
                this->_ptr++;
                return (tmp);
            }

            iterator& operator--()
            {
                std::cout << "iterator -- operator" << std::endl;
                this->_ptr--;
                return (*this);
            }

            iterator operator--(int)
            {
                std::cout << "iterator --(int) operator" << std::endl;
                iterator tmp(*this);
                this->_ptr--;
                return (tmp);
            }
           
            iterator operator+(difference_type n) const
            {
                std::cout << "iterator + operator" << std::endl;
                return (iterator(this->_ptr + n));
            }

            iterator operator-(difference_type n) const
            {
                std::cout << "iterator - operator" << std::endl;
                return (iterator(this->_ptr - n));
            }

            difference_type operator-(const iterator &other) const
            {
                std::cout << " - operator" << std::endl;
                return (iterator(this->_ptr - other.base()));
            }
           // TODO:difference_type or int !
            iterator& operator+=(difference_type n)//done += operator to increment an iterator
            {
                std::cout << "iterator += operator" << std::endl;
                this->_ptr += n;
                return (*this);
            }
            iterator& operator-=(difference_type n) //done -= operator to decrement an iterator
            {
                std::cout << "iterator -= operator" << std::endl;
                this->_ptr -= n;
                return (*this);
            }
            /*
                =================================================================
            */
            reference operator*() const
            {
                /*
                    return the value of the current object
                */
                std::cout << "iterator * operator" << std::endl;
                return (*this->_ptr);
            }

            reference operator[](difference_type n) const
            {
                std::cout << "iterator [] operator" << std::endl;
                return (*(this->_ptr + n));
            }

            pointer operator->() const // is used to access a member variable "m" of an object "a"
            {
                /*
                    return the address of the object
                */
                std::cout << "iterator -> operator" << std::endl;
                return (this->_ptr);
            }
            /*
                ============================= Member variables =============================
            */
            private :
            pointer _ptr;

    };
}
#endif
/*
An rvalue can be thought of as a temporary value that is created during the execution
of an expression, and it does not have a memory address that can be used to access it.

*a++ ==> In C++, the notation "a++" is used to dereference a pointer "a" and then increment the pointer.
The "" operator is used to dereference the pointer, which means to access the value that the pointer is pointing to. The "++" operator is used to increment the pointer,
which means to make it point to the next memory location.
The type of return would be the type that the pointer is pointing to,
for example if pointer a is pointing to an int, the return would be int.
It is important to note that the order of the operators * and ++ matters
Using *a++ you get the value that a pointer is pointing and then increment it,
but using *++a first increments the pointer and then get the value that it is pointing to. 

*a = t ==> n C++, the notation "*a = t" is used to assign the value "t" to the memory
location pointed to by the pointer "a". This notation is used to modify the value of an element 
in an array or other container through a pointer.


template<class Category, class T, class Distance = ptrdiff_t,
         class Pointer = T*, class Reference = T&>
struct iterator                                            // deprecated in C++17
{
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
};
*/