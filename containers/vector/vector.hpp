# ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../../iterators/reverse_iterator.hpp"
#include "../../iterators/random_access_iterator.hpp"
#include "../../tools/enable_if.hpp"
#include "../../tools/is_integral.hpp"
#include <iostream>
#include <vector>
#include <cstddef>
#include <iterator>
#include <typeinfo>
#include <memory>

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
            typedef typename allocator_type::difference_type				difference_type;
            typedef typename allocator_type::size_type						size_type;
            typedef          ft::random_access_iterator<pointer>			iterator;
            typedef          ft::random_access_iterator<const_pointer>	    const_iterator;
            typedef          ft::reverse_iterator<iterator>					reverse_iterator;
            typedef          ft::reverse_iterator<const_iterator>			const_reverse_iterator;
            // typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
            
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
                alloc : The container keeps and uses an internal copy of this allocator.
            */
            explicit vector (const allocator_type& alloc = allocator_type()):_array(NULL), _size(0), _capacity(0), _allocator(alloc){}

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
                this->_allocator = alloc;
            }
            /*
				- range constructor : Constructs a container with as many elements as the range [first,last),
				with each element constructed from its corresponding element in that range, in the same order.
				-  two iterators (first and last) which specify the range of elements to copy into the vector The elements are copied from first up to (but not including) last
				- The optional alloc argument specifies an allocator object to be used for memory allocation.
                - std::enable_if helps to avoid ambiguity and to ensure that the correct constructor is selected based on the type of the arguments.
            */
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
            {
                this->_size = 0;
                this->_array = NULL;
                this->_capacity = 0;
                this->_allocator = alloc;
                while (first != last)
                {
                    this->push_back(*first);
                    first++;
                }
            }
            /*
				Copy constructor: This creates a vector by copying the contents of another vector. 
				Constructs a container with a copy of each of the elements in x, in the same order.
                - x = Another vector object of the same type (with the same class template arguments T and Alloc),
                whose contents are either copied or acquired.
            */
            vector (const vector& x)
			{
                this->_size = x._size;
                this->_capacity = x._capacity;
                this->_array = this->_allocator.allocate(this->_capacity);
                for (size_type i = 0; i < this->_size; i++)
                    this->_array[i] = x._array[i];
            }
            /*
                - The vector is assigned a copy of the contents of x.
                - The allocator object is not copied.
                - The assignment operator returns a reference to the vector.
            */
            vector& operator= (const vector& x)
            {
                if (*this != x)
                {
                    this->_size = x._size;
                    this->_capacity = x._capacity;
                    this->_array = this->_allocator.allocate(this->_capacity);
                    for (size_type i = 0; i < this->_size; i++)
                        this->_array[i] = x._array[i];
                }
                return (*this);
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
                /*
                    - Returns an iterator pointing to the first element in the vector.
                    - If the container is empty, the returned iterator value shall not be dereferenced.
                */
                iterator begin()
                {
                    return (iterator(_array));
                }
                const_iterator begin() const
                {
                    return (const_iterator(_array));
                }

                /*
                    - Returns an iterator referring to the past-the-end element in the vector container.
                    - The past-the-end element is the theoretical element that would follow the last element in the vector.
                    - It does not point to any element, and thus shall not be dereferenced.
                */
                iterator end()
                {
                    return (iterator(this->_array + _size));
                }
                const_iterator end() const
                {
                    return (const_iterator(this->_array + _size));
                }
                /*
                    - Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning).
                    - If the container is empty, the returned iterator value shall not be dereferenced.
                */
                reverse_iterator rbegin()
                {
                    return (reverse_iterator(this->_array + _size - 1));
                }
                const_reverse_iterator rbegin() const
                {
                    return (const_reverse_iterator(this->_array + _size - 1));
                }
                /*
                    - Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (which is considered its reverse end).
                    - The range between vector::rend and vector::rbegin includes all the elements of the vector (in reverse order).
                */
                reverse_iterator rend()
                {
                    return (reverse_iterator(this->_array - 1));
                }
                const_reverse_iterator rend() const
                {
                    return (const_reverse_iterator(this->_array - 1));
                }
                /*
                    -Returns a const_iterator pointing to the first element in the container.
                    - A const_iterator is an iterator that points to const content. This iterator can be increased and decreased (unless it is itself also const)
                        just like the iterator returned by vector::begin
                        but it cannot be used to modify the contents it points to, even if the vector object is not itself const.
                */
               const_iterator cbegin() const
               {
                    return (const_iterator(this->_array));
               }

                /*
                      - Returns a const_iterator pointing to the past-the-end element in the container.
                      - The past-the-end element is the theoretical element that would follow the last element in the vector.
                      - It does not point to any element, and thus shall not be dereferenced.
                      - A const_iterator is an iterator that points to const content. This iterator can be increased and decreased (unless it is itself also const)
                            just like the iterator returned by vector::end
                            but it cannot be used to modify the contents it points to, even if the vector object is not itself const.
                */
                const_iterator cend() const
                {
                    return (const_iterator(this->_array + _size));
                }
                /*
                    - Returns a const_reverse_iterator pointing to the last element in the vector (i.e., its reverse beginning).
                    - If the container is empty, the returned iterator value shall not be dereferenced.
                    - A const_reverse_iterator is a reverse iterator that points to const content. This iterator can be increased and decreased (unless it is itself also const)
                        just like the reverse iterator returned by vector::rbegin
                        but it cannot be used to modify the contents it points to, even if the vector object is not itself const.
                */
                const_reverse_iterator crbegin() const
                {
                    return (const_reverse_iterator(this->_array + _size - 1));
                }
                /*
                    - Returns a const_reverse_iterator pointing to the theoretical element preceding the first element in the vector (which is considered its reverse end).
                    - The range between vector::rend and vector::rbegin includes all the elements of the vector (in reverse order).
                    - A const_reverse_iterator is a reverse iterator that points to const content. This iterator can be increased and decreased (unless it is itself also const)
                        just like the reverse iterator returned by vector::rend
                        but it cannot be used to modify the contents it points to, even if the vector object is not itself const.
                */
                const_reverse_iterator crend() const
                {
                    return (const_reverse_iterator(this->_array - 1));
                }
           /*
                ============================== capacity ===================================
           */

                /*
                     - Returns the number of elements in the vector.
                    - This is the number of actual objects held in the vector, which is not necessarily equal to its storage capacity.
                */
                size_type size() const
                {
                    return (this->_size);
                }
                /*
                    - Returns the maximum number of elements that the vector can hold
                */
                size_type max_size() const
                {
                    return (this->_allocator.max_size());
                }
                /*
                    - Resizes the container so that it contains n elements.
                    - If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
                    - If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n.
                    - If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
                    - If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
                    param :
                        - n : new size of the container.
                        - val : Object whose content is copied to the new elements in case that n is greater than the current container size.

                */
                void resize (size_type n, value_type val = value_type())
                {
                    if (n > this->_capacity)
                    {
                        pointer tmp;

                        this->_capacity = n;
                        tmp = this->_allocator.allocate(this->_capacity);
                        for (size_type i = 0; i < this->_size; i++)
                            tmp[i] = this->_array[i];
                        this->_allocator.deallocate(this->_array, this->_size);
                        this->_array = tmp;
                    }
                    if (n > this->_size)
                    {
                        for (size_type i = this->_size; i < n; i++)
                            this->_array[i] = val;
                    }
                        this->_size = n;
                }
                /*
                    - Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
                    - This capacity is not necessarily equal to the vector size. It can be equal or greater, with the extra space allowing to accommodate for growth without the need to reallocate on each insertion.
                */
                size_type capacity() const
                {
                    return (this->_capacity);
                }
                /*
                    - Requests that the vector capacity be at least enough to contain n elements.
                    - If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).
                    - In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.
                    - This function has no effect on the vector size and cannot alter its elements.
                    - param :
                        - n : new capacity of the vector.
                */
                void reserve (size_type n)
                {
                    if (n > this->_capacity)
                    {
                        pointer tmp;

                        this->_capacity = n;
                        tmp = this->_allocator.allocate(this->_capacity);
                        for (size_type i = 0; i < this->_size; i++)
                            tmp[i] = this->_array[i];
                        this->_allocator.deallocate(this->_array, this->_size);
                        this->_array = tmp;
                    }
                }
                /*
                    - Returns whether the vector is empty (i.e. whether its size is 0).
                    - This function does not modify the container in any way. To clear the content of a vector, see vector::clear.
                */
                bool empty() const
                {
                    if (_size == 0)
                        return (true);
                    return (false);
                }

                /*
                    - Requests the container to reduce its capacity to fit its size.
                    - This is a non-binding request to reduce capacity() to size().
                    - It depends on the implementation whether the request is fulfilled.
                    - If reallocation occurs, all iterators, including the past-the-end iterator, and all references to the elements are invalidated.
                    - Otherwise, no iterators or references are invalidated.
                */
                void shrink_to_fit()
                {
                    pointer tmp;

                    this->_capacity = this->_size;
                    tmp = this->_allocator.allocate(this->_capacity);
                    for (size_type i = 0; i < this->_size; i++)
                        tmp[i] = this->_array[i];
                    this->_allocator.deallocate(this->_array, this->_size);
                    this->_array = tmp;
                }
            /*
                ============================== element access ===================================
            */

                reference operator[] (size_type n)
                {
                        return this->_array[n];
                }
                const_reference operator[] (size_type n) const
                {
                        return this->_array[n];
                }
                /*
                    - Returns a reference to the element at position n in the vector container.
                    - param :
                        - n : position of the element to return.
                    - return :
                        - A reference to the requested element.
                    - If n is not within the range of the container, an exception of type out_of_range is thrown.
                */
                reference at (size_type n)
                {
                    if (n >= this->_size)
                        throw std::out_of_range("out of range");
                    return (this->_array[n]);
                }
                const_reference at (size_type n) const
                {
                    if (n >= this->_size)
                        throw std::out_of_range("out of range");
                    return (this->_array[n]);
                }
                /*
                    - Returns a reference to the first element in the vector.
                    - return :
                        - A reference to the first element in the vector container.
                    - Calling front on an empty container causes undefined behavior.
                */
                reference front()
                {
                    return (this->_array[0]);
                }
                const_reference front() const
                {
                    return (this->_array[0]);
                }
                /*
                    - Returns a reference to the last element in the vector.
                    - return :
                        - A reference to the last element in the vector container.
                    - Calling back on an empty container causes undefined behavior.
                */
                reference back()
                {
                    return (this->_array[this->_size - 1]);
                }
                const_reference back() const
                {
                    return (this->_array[this->_size - 1]);
                }
                /*
                    return a direct pointer to the memory array 
                    used internally by the vector to store its owned elements.
                */
                value_type *data()
                {
                    return (this->_array);
                }
                const value_type *data() const
                {
                      return (this->_array);
                }

            /*
                ============================== modifiers ===================================
            */

                /*
                    - Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
                    - param :
                        - n : new size of the container.
                        - val : value to be assigned to the container elements.
                    - The new contents are initialized as copies of val.
                    - If val is not specified, the new elements are value-initialized.
                    - If n is 0, the container is cleared.
                    - If n is greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
                    - Notice that this function changes the actual content of the container by inserting or erasing elements from it.
                */
                template <class InputIterator>
                void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
                {
                    size_type i;
                    size_type size;
                    
                    i = 0;
                    size = 0;
                    while (first != last)// cuz last no include
                    {
                        first++;
                        size++;
                    }
                    if (size > this->_capacity)
                    {
                        pointer tmp;

                        this->_capacity = size;
                        tmp = this->_allocator.allocate(this->_capacity);
                        for (size_type i = 0; i < this->_size; i++)
                            tmp[i] = this->_array[i];
                        this->_allocator.deallocate(this->_array, this->_size);
                        this->_array = tmp;
                    }
                    while (i < size)
                    {
                        this->_array[i] = *first;
                        first++;
                        i++;
                    }
                    this->_size = size;
                }

                void assign (size_type n, const value_type& val)
                {
                    if (n > this->_capacity)
                    {
                        pointer tmp;

                        this->_capacity = n;
                        tmp = this->_allocator.allocate(this->_capacity);
                        for (size_type i = 0; i < this->_size; i++)
                            tmp[i] = this->_array[i];
                        this->_allocator.deallocate(this->_array, this->_size);
                        this->_array = tmp;
                    }
                    for (size_type i = 0; i < n; i++)
                        this->_array[i] = val;
                    this->_size = n;
                }
                /*
                    - Adds a new element at the end of the vector, after its current last element.
                    - The content of val is copied (or moved) to the new element.
                    - This effectively increases the container size by one, which causes an automatic reallocation of the allocated storage space if - and only if - the new vector size surpasses the current vector capacity.
                    - param :
                        - val : Value to be copied (or moved) to the new element.
                */
                void push_back (const value_type& val)
                {
                    if (this->_size == this->_capacity)
                    {
                        pointer tmp;
    
                        if (this->_capacity == 0) 
                            this->_capacity = 1;
                        else
                            this->_capacity *= 2;
                        tmp = this->_allocator.allocate(this->_capacity);
                        for (size_type i = 0; i < this->_size; i++)
                            tmp[i] = this->_array[i];
                        this->_allocator.deallocate(this->_array, this->_capacity);
                        this->_array = tmp;
                    }
                    this->_array[this->_size] = val;
                    this->_size++;
                }
                /*
                    - Removes the last element in the vector, effectively reducing the container size by one.
                    - This destroys the removed element.
                    - Calling pop_back on an empty container causes undefined behavior.
                */
                void pop_back()
                {
                    this->_size--;
                }
                /*
                    - The vector is extended by inserting new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted.
                    - This causes an automatic reallocation of the allocated storage space if - and only if - the new vector size surpasses the current vector capacity.
                    - param :
                        - position : Position in the vector where the new elements are inserted.
                        - val : Value to be copied (or moved) to the inserted elements.
                    - return :
                        - An iterator that points to the first of the newly inserted elements.
                    - If the new size() is greater than capacity(), all iterators, including the past-the-end iterator, and all references to the elements are invalidated.
                    - Otherwise, only the iterators and references before the insertion point remain valid.
                    - The past-the-end iterator is also invalidated.
                */
                // 3 9 4 7 0 insert(begin(), 200)
                iterator insert (iterator position, const value_type& val)
                {
                    size_type           i;
                    difference_type     pos;
                    pointer             tmp;

                    i = 0;
                    pos = position - this->begin();// need to know position of 
                    if (this->_size == this->_capacity)
                    {
                        if (this->_capacity == 0) 
                            this->_capacity = 1;
                        else
                            this->_capacity *= 2;
                        tmp = this->_allocator.allocate(this->_capacity);
                        for (size_type i = 0; i < this->_size; i++)
                            tmp[i] = this->_array[i];
                        this->_allocator.deallocate(this->_array, this->_size);
                        this->_array = tmp;
                    }
                    while (i < this->_size - pos)
                    {
                        this->_array[this->_size - i] = this->_array[this->_size - i - 1];
                        i++;
                    }
                    this->_array[pos] = val;
                    this->_size++;
                    return (this->begin() + pos);
                }
    
                void insert (iterator position, size_type n, const value_type& val)
                {
                    size_type       i;
                    difference_type pos;
                    pointer         tmp;

                    i = 0;
                    pos = position - this->begin();
                    if (this->_size + n > this->_capacity)
                    {
                        if (this->_capacity == 0) 
                            this->_capacity = 1;
                        else
                            this->_capacity *= 2;
                        while (this->_size + n > this->_capacity)
                            this->_capacity *= 2;
                        tmp = this->_allocator.allocate(this->_capacity);
                        for (size_type i = 0; i < this->_size; i++)
                            tmp[i] = this->_array[i];
                        this->_allocator.deallocate(this->_array, this->_size);
                        this->_array = tmp;
                    }
                    while (i < this->_size - pos)
                    {
                        this->_array[this->_size + n - i - 1] = this->_array[this->_size - i - 1];
                        i++;
                    }
                    while (n > 0)
                    {
                        this->_array[pos] = val;
                        pos++;
                        n--;
                    }
                    this->_size += n;
                }

                template <class InputIterator>
                void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
                {
                    size_type       i;
                    difference_type pos;
                    difference_type n;
                    pointer         tmp;

                    i = 0;
                    pos = position - this->begin();
                    n = last - first;
                    if (this->_size + n > this->_capacity)
                    {
                        if (this->_capacity == 0) 
                            this->_capacity = 1;
                        else
                            this->_capacity *= 2;
                        while (this->_size + n > this->_capacity)
                            this->_capacity *= 2;
                        tmp = this->_allocator.allocate(this->_capacity);
                        for (size_type i = 0; i < this->_size; i++)
                            tmp[i] = this->_array[i];
                        this->_allocator.deallocate(this->_array, this->_size);
                        this->_array = tmp;
                    }
                    while (i < this->_size - pos)
                    {
                        this->_array[this->_size + n - i - 1] = this->_array[this->_size - i - 1];
                        i++;
                    }
                    while (n > 0)
                    {
                        this->_array[pos] = *first;
                        pos++;
                        first++;
                        n--;
                    }
                    this->_size += n;
                }
                /*
                    - Removes from the vector either a single element (position) or a range of elements ([first,last)).
                    - position : iterator pointing to a single element to be removed from the vector.
                    - first and last : Iterators specifying a range within the vector] to be removed: [first,last).
                */
                // 4 3 2 0
                iterator erase (iterator position)
                {
                    size_type       i;
                    difference_type pos;

                    i = 0;
                    pos = position - this->begin();
                    while (i < this->_size - pos - 1)
                    {
                        this->_array[pos + i] = this->_array[pos + i + 1];
                        i++;
                    }
                    this->_size--;
                    return (this->begin() + pos);
                }
                iterator erase (iterator first, iterator last)
                {
                    size_type       i;
                    difference_type pos;
                    size_type       n;

                    i = 0;
                    pos = first - this->begin();
                    n = last - first;
                    while (i < this->_size - pos - n)
                    {
                        this->_array[pos + i] = this->_array[pos + i + n];
                        i++;
                    }
                    this->_size -= n;
                    return (this->begin() + pos);
                }
                /*
                    - Exchanges the content of the container by the content of x, which is another vector object of the same type.
                    - Sizes may differ.
                    - After the call to this member function, the elements in this container are those which were in x before the call, and the elements of x are those which were in this.
                    - All iterators, references and pointers remain valid for the swapped objects.
                */
                void swap (vector& x)
                {
                    pointer tmp_array;
                    size_type tmp_size;
                    size_type tmp_capacity;
                    allocator_type tmp_allocator;

                    tmp_array = this->_array;
                    tmp_size = this->_size;
                    tmp_capacity = this->_capacity;
                    tmp_allocator = this->_allocator;
                    this->_array = x._array;
                    this->_size = x._size;
                    this->_capacity = x._capacity;
                    this->_allocator = x._allocator;
                    x._array = tmp_array;
                    x._size = tmp_size;
                    x._capacity = tmp_capacity;
                    x._allocator = tmp_allocator;
                }
                void clear()
                {
                    this->_size = 0;
                }

            /*
                ============================== Allocator ===================================
            */
                allocator_type get_allocator() const
                {
                    return (this->_allocator);
                }
    };
    template <class T, class Alloc>  
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        for (size_t i = 0; i < lhs.size(); i++)
            if (lhs[i] != rhs[i])
                return (false);
        return (true);
    }

    template <class T, class Alloc>  
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T, class Alloc> 
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        size_t i;

        i = 0;
        while (i < lhs.size() && i < rhs.size())
        {
            if (lhs[i] < rhs[i])
                return (true);
            else if (lhs[i] > rhs[i])
                return (false);
            i++;
        }
        if (i == lhs.size() && i != rhs.size())
            return (true);
        return (false);
    }

    template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(rhs < lhs));
    }

    template <class T, class Alloc>  bool operator>
    (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }
    template <class T, class Alloc> 
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
}
#endif
/* #TODO : add this in readme:
- how the compiler chooses the right function overload to call !
    function overloading allows multiple functions with the same name to exist in the same scope, but with different parameter lists.
    The compiler uses the number, types, and order of arguments in the function call to determine which function to call.
    This process is called "argument-dependent lookup" or "Koenig lookup", 
    and it helps the compiler determine the best match for the arguments in a function call, among the available overloads.
    If there is no unique match, a compile-time error is generated.

-  input iterator is a type of iterator that can be used to read elements from a container one at a time,
but it cannot be used to modify the elements. Input iterators are often used to define the range of elements that can be copied into a container.
*/