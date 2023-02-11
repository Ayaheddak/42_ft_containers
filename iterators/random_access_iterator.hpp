# ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"
namespace ft
{
   template <class T>
   class random_access_iterator
   {
    public:
            typedef T                                                               iterator_type;
		    typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
		    typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
		    typedef typename ft::iterator_traits<iterator_type>::reference			reference;
		    typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
		    typedef typename ft::iterator_traits<iterator_type>::iterator_category  iterator_category;
    
    private:
        iterator_type _iter;

    public:
        random_access_iterator()
        {
            _iter = NULL;
        }
        random_access_iterator(iterator_type iter):_iter(iter){}
        template <class _Iter2>
        random_access_iterator(const random_access_iterator<_Iter2>& other):_iter(other.base()){}
        random_access_iterator& operator=(const random_access_iterator& other)
        {
            this->_iter = other._iter;
            return (*this);
        }
        ~random_access_iterator(){}

        iterator_type base() const
        {
            return (this->_iter);
        }

        reference operator*() const
        {
            return (*this->_iter);
        }

        pointer operator->() const
        {
            return (&(operator*()));
        }

        random_access_iterator& operator++()
        {
            this->_iter++;
            return (*this);
        }

        random_access_iterator operator++(int)
        {
            random_access_iterator tmp(*this);
            this->_iter++;
            return (tmp);
        }

        random_access_iterator& operator--()
        {
            this->_iter--;
            return (*this);
        }

        random_access_iterator operator--(int)
        {
            random_access_iterator tmp(*this);
            this->_iter--;
            return (tmp);
        }

        random_access_iterator operator+(difference_type n) const
        {
            random_access_iterator tmp(*this);
            tmp._iter += n;
            return (tmp);
        }

        random_access_iterator operator-(difference_type n) const
        {
            random_access_iterator tmp(*this);
            tmp._iter -= n;
            return (tmp);
        }

        random_access_iterator& operator+=(difference_type n) 
        {
            this->_iter += n;
            return (*this);
        }

        random_access_iterator& operator-=(difference_type n)
        {
            this->_iter -= n;
            return (*this);
        }

        difference_type operator-(const random_access_iterator &other) const
        {
            return (this->_iter - other.base());
        }

        reference operator[](difference_type n) const
        {
            return (this->_iter[n]);
        }
    };

    /*
        ============================= Non-member functions =============================
    */
    template <class T>
    bool operator==(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
    {
        return lhs.base() == rhs.base();
    }

    template <class T, class U>
    bool operator==(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
    {
        return lhs.base() == rhs.base();
    }

    template <class T>
    bool operator<(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <class T, class U>
    bool operator<(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <class T>
    bool operator!=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <class T, class U>
    bool operator!=(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <class T>
    bool operator>(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class T, class U>
    bool operator>(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <class T>
    bool operator>=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <class T, class U>
    bool operator>=(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <class T>
    bool operator<=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    
    template <class T, class U>
    bool operator<=(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class T>
    random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> &it)
    {
        return (it + n);
    }

    template <class T>
    random_access_iterator<T> operator-(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> &it)
    {
        return (it - n);
    }
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

//    class iterator 
//     {
//         public :
//             /*
//                 ============================= Member types =============================
//             */
//                 typedef T                                       value_type;
//                 typedef std::ptrdiff_t                          difference_type;
//                 typedef T*                                       pointer;
//                 typedef T&                                      reference;
//                 typedef std::random_access_iterator_tag         iterator_category;
//         private :
//             pointer _ptr;
//         /*
//             ======================= Canonical Form =============================
//         */
//         public :
//             iterator():_ptr(NULL){}
//             iterator(pointer ptr):_ptr(ptr){}//done
//             iterator(const iterator& other):_ptr(other._ptr) {}
//             iterator& operator=(const iterator& other)
//             {
//                 this->_ptr = other._ptr;
//                 return (*this);
//             }
//             ~iterator() {}
//         /* 
//             ==============================getter and setter ===================================
//         */
//             pointer base() const
//             {
//                 return (this->_ptr);
//             }
//         /*
//             ============================== comparision ===================================
//         */
//             //TODO: template bcz we need to check if the other iterator is of the same type
//         /*
//             ============================= Arithmitics ====================================
//         */
//             iterator& operator++()
//             {
//                 this->_ptr++;
//                 return (*this);
//             }

//             iterator operator++(int)
//             {
//                 iterator tmp(*this);
//                 this->_ptr++;
//                 return (tmp);
//             }

//             iterator& operator--()
//             {
//                 this->_ptr--;
//                 return (*this);
//             }

//             iterator operator--(int)
//             {
//                 iterator tmp(*this);
//                 this->_ptr--;
//                 return (tmp);
//             }
           
//             iterator operator+(difference_type n) const
//             {
//                 return (iterator(this->_ptr + n));
//             }

//             iterator operator-(difference_type n) const
//             {
//                 std::cout << "iterator - operator" << std::endl;
//                 return (iterator(this->_ptr - n));
//             }

//             difference_type operator-(const iterator &other) const
//             {
//                 return (iterator(this->_ptr - other.base()));
//             }
//            // TODO:difference_type or int !
//             iterator& operator+=(difference_type n)//done += operator to increment an iterator
//             {
//                 this->_ptr += n;
//                 return (*this);
//             }
//             iterator& operator-=(difference_type n) //done -= operator to decrement an iterator
//             {
//                 this->_ptr -= n;
//                 return (*this);
//             }
//             /*
//                 =================================================================
//             */
//             reference operator*() const
//             {
//                 /*
//                     return the value of the current object
//                 */
//                 return (*this->_ptr);
//             }

//             reference operator[](difference_type n) const
//             {
//                 std::cout << "iterator [] operator" << std::endl;
//                 return (*(this->_ptr + n));
//             }

//             pointer operator->() const // is used to access a member variable "m" of an object "a"
//             {
//                 /*
//                     return the address of the object
//                 */
//                 std::cout << "iterator -> operator" << std::endl;
//                 return (this->_ptr);
//             }
    //};