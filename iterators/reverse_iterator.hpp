#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
#include <iterator>
namespace ft
{
    class reverse_iterator_tag : public std::bidirectional_iterator_tag
    {
    };
    template <typename Iterator>
    class reverse_iterator
    {
        public :
            typedef Iterator iterator_type;
            typedef typename std::iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename std::iterator_traits<Iterator>::value_type value_type;
            typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
            typedef typename std::iterator_traits<Iterator>::pointer pointer;
            typedef typename std::iterator_traits<Iterator>::reference reference;
        private :
            Iterator _base;
        public :
            reverse_iterator():_base(NULL){}
            reverse_iterator(Iterator it):_base(it){}
            template <class U>
            reverse_iterator(const reverse_iterator<U> &other):_base(other._base){}
            template <class U>
            reverse_iterator& operator=(const reverse_iterator<U>& other)
            {
                this->_base = other._base;
                return (*this);
            }
            ~reverse_iterator(){}
            /*
                ============================== getter and setter ===================================
            */
            Iterator base() const
            {
                return (this->_base);
            }
            /*
                ============================== arith ===================================
            */
            reference operator*() const//
            {
                Iterator tmp;

                tmp = this->_base;
                return (*--tmp);
            }

            pointer operator->() const
            {
                return (&(operator*()));
            }

            reverse_iterator& operator++()
            {
                --this->_base;
                return (*this);
            }

            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                --this->_base;
                return (tmp);
            }
            reverse_iterator& operator--()
            {
                ++this->_base;
                return (*this);
            }
            
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                ++this->_base;
                return (tmp);
            }

            reverse_iterator operator+(difference_type n) const
            {
                return (reverse_iterator(this->_base - n));
            }

            reverse_iterator& operator+=(difference_type n)
            {
                this->_base -= n;
                return (*this);
            }

            reverse_iterator operator-(difference_type n) const
            {
                return (reverse_iterator(this->_base + n));
            }

            reverse_iterator& operator-=(difference_type n)
            {
                this->_base += n;
                return (*this);
            }

            reference operator[](difference_type n) const
            {
                return (this->_base[-n - 1]);
            }
    };
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
    // template <class Iterator>
    // typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    // {
    //     return (rhs.base() - lhs.base());
    // }
}
#endif
/*
 const keyword at the end of the function signature means that
 the function will not modify the object on which it is called.
*/