#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
#include "iterator_traits.hpp"
namespace ft
{
    template <typename Iterator>
    class reverse_iterator
    {
        public :
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;
        private :
            iterator_type _it;
        public :
            reverse_iterator():_it(){}
            explicit reverse_iterator (iterator_type it):_it(it){}
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it)
            {
                this->_it = rev_it.base();
            }
            //template <class U>
            // reverse_iterator& operator=(const reverse_iterator<U>& other)
            // {
            //     this->_base = other._base;
            //     return (*this);
            // }
            // ~reverse_iterator(){}

            /*
                ============================== getter and setter ===================================
            */
            iterator_type base() const
            {
                return (this->_it);
            }
            /*
             ============================== Assignment Operator ====================================
            */

            template< class U >
            reverse_iterator& operator=( const reverse_iterator<U>& other)
            {
                this->__it = other.base();
                return *this;
            }
            /*
                ============================== arith ===================================
            */

            // reverse_iterator& operator=(const reverse_iterator &rhs)
            // {
            //     this->_it = rhs._it;
            //     return (*this);
            // }
            reference operator*() const
            {
                iterator_type tmp;

                tmp = this->_it;
                return (*--tmp);
            // return *(_it - 1);
            // it returns it -  1 because reverse iterator points to the element before the current one
            }

            pointer operator->() const
            {
                return (&(operator*()));
            }

            reverse_iterator& operator++()
            {
                --_it;
                return (*this);
            }

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

            reverse_iterator operator+(difference_type n) const//prb
            {
                return (reverse_iterator(this->_it - n));
            }

            reverse_iterator& operator+=(difference_type n)
            {
                this->_it -= n;
                return (*this);
            }

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
 const keyword at the end of the function signature means that
 the function will not modify the object on which it is called.
*/