# ifndef VECTOR_HPP
#define VECTOR_HPP
#include "../../iterators/iterator_traits.hpp"
#include "../../iterators/random_acess_iterator.hpp"
#include "../../iterators/reverse_iterator.hpp"
#include <vector>
/*

alloc	-	allocator to use for all memory allocations of this container
count	-	the size of the container
value	-	the value to initialize elements of the container with
first, last	-	the range to copy the elements from
other	-	another container to be used as source to initialize the elements of the container with
init	-	initializer list to initialize the elements of the container with
*/
namespace ft
{
	/*
		<class T, class Allocator = std::allocator<T> >
			- T is the type of elements that the vector will store
			- Allocator is the type of the allocator (like int or float or double ....) object used to define the storage allocation model.
	*/
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {   
    /* ============================== MEMBER TYPE ============================== */
        public :
        typedef T											            value_type;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef typename ft::random_access_iterator<value_type>			iterator;
		typedef typename ft::random_access_iterator<const value_type>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef typename allocator_type::difference_type				difference_type;
		typedef typename allocator_type::size_type						size_type;
    
	/* ============================== MEMBER ATTRIBUTES ============================== */

        private :
            pointer			_array; //An array of elements that store the actual data.
            size_type		_size; //that represents the number of elements currently stored in the vector
            size_type		_capacity;//A variable that stores the capacity of the vector, or the maximum number of elements it can hold.
            allocator_type	_allocator; // that manages the memory used by the vector. It is responsible for allocating and deallocating memory as needed,

    /* ============================== CONSTRUCTORS/DESTRUCTOR ============================== */
        public :
            /*
                default constructor : This creates an empty vector
                Constructs an empty container, with no elements.
				The memory for the elements of the vector will be managed by the specified allocator. 
            */
            explicit vector (const allocator_type& alloc = allocator_type()):_array(nullptr), _size(0), _capacity(0), _allocator(alloc){}

            /*
				Fill constructor : Fill constructor: This creates a vector with a specified number of elements, all initialized to a given value.
                Fill cons : Constructs a container with n elements. Each element is a copy of val.
				- n : is the number of elements to be in the vector
				- val :  is the value that each element will be initialized to
				- alloc : is the allocator object to be used by the vector. By default, it is an instance of the allocator_type class,
				which is the default allocator type for the vector.
				-this->_array = this->_allocator.allocate(n) = allocating memory to store the elements of the vector,
				and saving the resulting pointer in the _array member so that it can be used to access the elements later on.
            */
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            {
				this->_array = this->_allocator.allocate(n);// allocating memory to store the elements of the vector,
				this->_size = n;
				this->_capacity = n;
				for (size_type i = 0; i < n; i++)
					this->_array[i] = val;
            }
            /*
				- range constructor : Constructs a container with as many elements as the range [first,last),
				with each element constructed from its corresponding element in that range, in the same order.
				-  two iterators (first and last) which specify the range of elements to copy into the vector The elements are copied from first up to (but not including) last
				- The optional alloc argument specifies an allocator object to be used for memory allocation.

            */
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
            {
				this->_size = 0;
				this->_capacity = 0;
				this->_array = nullptr;
				this->assign(first, last);
            }
            /*
				Copy constructor: This creates a vector by copying the contents of another vector. 
				Constructs a container with a copy of each of the elements in x, in the same order.
            */
            vector (const vector& x)
			{

			}
            /*
			*/
			~vector()
			{
				this->_allocator.deallocate(this->_array, this->_capacity);
			}
    /* ============================== MEMBER FUNCTIONS =================================== */
            /*
                ============================== iterator ===================================
            */
            // iterator begin()
            // {
            //     return (iterator(this->_array));
            // }
            // const_iterator begin() const
            // {
            //     return (const_iterator(this->_array));
            // }
            // iterator end()
            // {
            //     return (iterator(this->_array + this->_size));
            // }
            // const_iterator end() const
            // {
            //     return (const_iterator(this->_array + this->_size));
            // }
            // reverse_iterator rbegin()
            // {
            //     return (reverse_iterator(this->end()));
            // }

            // const_reverse_iterator rbegin() const
            // {
            //     return (const_reverse_iterator(this->end()));
            // }
            // reverse_iterator rend()
            // {
            //     return (reverse_iterator(this->begin()));
            // }
            // const_reverse_iterator rend() const
            // {
            //     return (const_reverse_iterator(this->begin()));
            // }
            /*
                ============================== capacity ===================================
            */
            // size_type size() const
            // {
            //     return (this->_size);
            // }
            // size_type max_size() const
            // {
            //     return (this->_allocator.max_size());
            // }
            // void resize(size_type n, value_type val = value_type())
            // {
            //     if (n > this->_size)
            //     {
            //         if (n > this->_capacity)
            //             this->reserve(n);
            //         for (size_t i = this->_size; i < n; i++)
            //             this->_array[i] = val;
            //     }
            //     this->_size = n;
            // }
            // size_type capacity() const
            // {
            //     return (this->_capacity);
            // }
            // bool empty() const
            // {
            //     return (this->_size == 0);
            // }
            // void reserve(size_type n)
            // {
            //     if (n > this->_capacity)
            //     {
            //         T* tmp = this->_allocator.allocate(n);
            //         for (size_t i = 0; i < this->_size; i++)
            //             tmp[i] = this->_array[i];
            //         this->_allocator.deallocate(this->_array, this->_capacity);
            //         this->_array = tmp;
            //         this->_capacity = n;
            //     }
            // }
            /*
                ============================== element access ===================================
            */
            // reference operator[](size_type n)
            // {
            //     return (this->_array[n]);
            // }
            // const_reference operator[](size_type n) const
            // {
            //     return (this->_array[n]);
            // }
            // reference at(size_type n)
            // {
            //     if (n >= this->_size)
            //         throw std::out_of_range("vector");
            //     return (this->_array[n]);
            // }
            // const_reference at(size_type n) const
            // {
            //     if (n >= this->_size)
            //         throw std::out_of_range("vector");
            //     return (this->_array[n]);
            // }
            // reference front()
            // {
            //     return (this->_array[0]);
            // }
            // const_reference front() const
            // {
            //     return (this->_array[0]);
            // } 
            // reference back()
            // {
            //     return (this->_array[this->_size - 1]);
            // }
            // const_reference back() const
            // {
            //     return (this->_array[this->_size - 1]);
            // }
            /*
                ============================== modifiers ===================================
            */
            // template <class InputIterator>
            // void assign(InputIterator first, InputIterator last)
            // {
            //     this->clear();
            //     while (first != last)
            //     {
            //         this->push_back(*first);
            //         first++;
            //     }
            // }
            // void assign(size_type n, const value_type& val)
            // {
            //     this->clear();
            //     for (size_t i = 0; i < n; i++)
            //         this->push_back(val);
            // }
            // void push_back(const value_type& val)
            // {
            //     if (this->_size == this->_capacity)
            //         this->reserve(this->_capacity + 1);
            //     this->_array[this->_size] = val;
            //     this->_size++;
            // }
            // void pop_back()
            // {
            //     this->_size--;
            // }
    };
    
}
#endif
//   pointer                                         __begin_;
// pointer                                         __end_;
// __compressed_pair<pointer, allocator_type> __end_cap_;