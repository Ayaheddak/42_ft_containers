# ifndef VECTOR_HPP
#define VECTOR_HPP
#include "../../iterators/iterator_traits.hpp"
#include "../../iterators/random_acess_iterator.hpp"
#include "../../iterators/reverse_iterator.hpp"
#include <vector>
namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {   
        public :
            typedef T value_type;
            typedef Allocator allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef std::random_access_iterator<T> iterator;
            typedef std::random_access_iterator<const T> const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef typename ft:iterator_traits<iterator>::difference_type difference_type;
            typedef size_t size_type;
        public :
            vector():_array(NULL), _size(0), _capacity(0), _allocator(Allocator()){}
            explicit vector(const allocator_type& alloc):_array(NULL), _size(0), _capacity(0), _allocator(alloc){}//
            explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):_array(NULL), _size(0), _capacity(0), _allocator(alloc)
            {
                this->assign(n, val);
            }
            template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()):_array(NULL), _size(0), _capacity(0), _allocator(alloc)
            {
                this->assign(first, last);
            }
            vector(const vector& x):_array(NULL), _size(0), _capacity(0), _allocator(x._allocator)
            {
                this->assign(x.begin(), x.end());
            }
            ~vector()
            {
                this->clear();
                this->_allocator.deallocate(this->_array, this->_capacity);
            }
            vector& operator=(const vector& x)
            {
                this->assign(x.begin(), x.end());
                return (*this);
            }
            /*
                ============================== iterator ===================================
            */
            iterator begin()
            {
                return (iterator(this->_array));
            }
            const_iterator begin() const
            {
                return (const_iterator(this->_array));
            }
            iterator end()
            {
                return (iterator(this->_array + this->_size));
            }
            const_iterator end() const
            {
                return (const_iterator(this->_array + this->_size));
            }
            reverse_iterator rbegin()
            {
                return (reverse_iterator(this->end()));
            }

            const_reverse_iterator rbegin() const
            {
                return (const_reverse_iterator(this->end()));
            }
            reverse_iterator rend()
            {
                return (reverse_iterator(this->begin()));
            }
            const_reverse_iterator rend() const
            {
                return (const_reverse_iterator(this->begin()));
            }
            /*
                ============================== capacity ===================================
            */
            size_type size() const
            {
                return (this->_size);
            }
            size_type max_size() const
            {
                return (this->_allocator.max_size());
            }
            void resize(size_type n, value_type val = value_type())
            {
                if (n > this->_size)
                {
                    if (n > this->_capacity)
                        this->reserve(n);
                    for (size_t i = this->_size; i < n; i++)
                        this->_array[i] = val;
                }
                this->_size = n;
            }
            size_type capacity() const
            {
                return (this->_capacity);
            }
            bool empty() const
            {
                return (this->_size == 0);
            }
            void reserve(size_type n)
            {
                if (n > this->_capacity)
                {
                    T* tmp = this->_allocator.allocate(n);
                    for (size_t i = 0; i < this->_size; i++)
                        tmp[i] = this->_array[i];
                    this->_allocator.deallocate(this->_array, this->_capacity);
                    this->_array = tmp;
                    this->_capacity = n;
                }
            }
            /*
                ============================== element access ===================================
            */
            reference operator[](size_type n)
            {
                return (this->_array[n]);
            }
            const_reference operator[](size_type n) const
            {
                return (this->_array[n]);
            }
            reference at(size_type n)
            {
                if (n >= this->_size)
                    throw std::out_of_range("vector");
                return (this->_array[n]);
            }
            const_reference at(size_type n) const
            {
                if (n >= this->_size)
                    throw std::out_of_range("vector");
                return (this->_array[n]);
            }
            reference front()
            {
                return (this->_array[0]);
            }
            const_reference front() const
            {
                return (this->_array[0]);
            } 
            reference back()
            {
                return (this->_array[this->_size - 1]);
            }
            const_reference back() const
            {
                return (this->_array[this->_size - 1]);
            }
            /*
                ============================== modifiers ===================================
            */
            template <class InputIterator>
            void assign(InputIterator first, InputIterator last)
            {
                this->clear();
                while (first != last)
                {
                    this->push_back(*first);
                    first++;
                }
            }
            void assign(size_type n, const value_type& val)
            {
                this->clear();
                for (size_t i = 0; i < n; i++)
                    this->push_back(val);
            }
            void push_back(const value_type& val)
            {
                if (this->_size == this->_capacity)
                    this->reserve(this->_capacity + 1);
                this->_array[this->_size] = val;
                this->_size++;
            }
            void pop_back()
            {
                this->_size--;
            }
        private :
            T* _array;
            size_t _size;
            size_t _capacity;
            Allocator _allocator;
    };
    
}
#endif
//   pointer                                         __begin_;
// pointer                                         __end_;
// __compressed_pair<pointer, allocator_type> __end_cap_;