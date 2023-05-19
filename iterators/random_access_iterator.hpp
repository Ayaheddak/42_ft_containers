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
