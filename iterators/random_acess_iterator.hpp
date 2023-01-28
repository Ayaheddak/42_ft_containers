#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP
// #include <iterator>
#include <iostream>
namespace ft
{
    template <class T>
    class iterator
    {
        public :
            typedef T value_type;
            typedef std::ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;
            typedef std::random_access_iterator_tag iterator_category;

        private:
            pointer _ptr;

        public :
        /*
            ======================= Canonical Form =============================
        */
            iterator():_ptr(NULL)
            {
                std::cout << "iterator constructor" << std::endl;
            }
            iterator(pointer ptr):_ptr(ptr)//done
            {
                std::cout << "iterator constructor(args)" << std::endl;
            }
            iterator(const iterator& other):_ptr(other._ptr)
            {
                std::cout << "iterator copy constructor" << std::endl;
            }
            iterator& operator=(const iterator& other)
            {
                std::cout << "iterator assignation operator" << std::endl;
                this->_ptr = other._ptr;//get the pointer of the other iterator
                return (*this);
            }
            ~iterator()
            {
                std::cout << "iterator destructor" << std::endl;
            }
            pointer getptr() const
            {
                return (this->_ptr);
            }
            /*
                =============================jsp====================================
            */
            bool operator==(const iterator& other) const//done
            {
                std::cout << "iterator == operator" << std::endl;
                return (this->_ptr == other._ptr);
            }
            bool operator!=(const iterator& other) const//done
            {
                std::cout << "iterator != operator" << std::endl;
                return (this->_ptr != other._ptr);
            }
            /*
                ==============================jsp===================================
            */
            bool operator<(const iterator& other) const //done
            {
                std::cout << "iterator < operator" << std::endl;
                return (this->_ptr < other._ptr);
            }
            bool operator>(const iterator& other) const //done
            {
                std::cout << "iterator > operator" << std::endl;
                return (this->_ptr > other._ptr);
            }
            bool operator<=(const iterator& other) const //done
            {
                std::cout << "iterator <= operator" << std::endl;
                return (this->_ptr <= other._ptr);
            }
            bool operator>=(const iterator& other) const //done
            {
                std::cout << "iterator >= operator" << std::endl;
                return (this->_ptr >= other._ptr);
            }
            /*
                =================================================================
            */
            iterator& operator++() //done
            {
                std::cout << "iterator ++ operator" << std::endl;
                this->_ptr++;
                return (*this);
            }
            iterator operator++(int) //done
            {  
                std::cout << "iterator ++(int) operator" << std::endl;
                iterator tmp(*this);
                this->_ptr++;
                return (tmp);
            }
            iterator& operator--() //done
            {
                std::cout << "iterator -- operator" << std::endl;
                this->_ptr--;
                return (*this);
            }
            iterator operator--(int) //done
            {
                std::cout << "iterator --(int) operator" << std::endl;
                iterator tmp(*this);
                this->_ptr--;
                return (tmp);
            }
            /*
                =================================================================
            */
            iterator operator+(difference_type n) const //done
            {
                std::cout << "iterator + operator" << std::endl;
                return (iterator(this->_ptr + n));
            }
            iterator operator-(difference_type n) const //done
            {
                std::cout << "iterator - operator" << std::endl;
                return (iterator(this->_ptr - n));
            }
            difference_type operator-(const iterator &other) const //done
            {
                std::cout << " - operator" << std::endl;
                return (iterator(this->_ptr - other.getptr()));
            }
            /*
                =================================================================
            */
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
            // pointer operator *--() const // not sure
            // {
            //     std::cout << "iterator *-- operator" << std::endl;
            //     return (--this->_ptr);
            // }
            // pointer operator *++() const//not sure 
            // {
            //     std::cout << "iterator *++ operator" << std::endl;
            //     return (++this->_ptr);
            // }
            // pointer operator +(difference_type n) const // not sure
            // {
            //     std::cout << "iterator + operator" << std::endl;
            //     return (this->_ptr + n);
            // }
            // void operator =(difference_type n) const
            // {
            //     std::cout << "iterator = operator" << std::endl;
            //     this->_ptr = n;
            // }
            // pointer operator -(difference_type n) const//m not sure
            // {
            //     std::cout << "iterator - operator" << std::endl;
            //     return (this->_ptr - n);
            //}
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



*/