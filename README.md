# ft_containers

# What's a iterator and why we use them ?
An iterator is an object (like a pointer) that points to an element inside the container.
We can use iterators to move through the contents of the container. They can be
visualised as something similar to a pointer pointing to some location and we can
access content at that particular location using them.
Iterators play a critical role in connecting algorithm with containers along with the manipulation of data stored inside the containers. The most obvious form of iterator is a pointer.
A pointer can point to elements in an array, and can iterate through them using
the increment operator (++).
But, all iterators do not have similar functionality as that of
pointers
and we have five types of iterators :
- Input Iterators: used for reading data from a container. They support basic operations like read, increment and compare.
- Output Iterators: used for writing data to a container.
 They support basic operations like write and increment.
- Forward Iterators: an extension of Input Iterators, they also support multiple passes over the same elements.
- Bidirectional Iterators: an extension of Forward Iterators, they also support decrement operations.
- Random Access Iterators: the most versatile type of iterators, they support all operations of Bidirectional Iterators and also provide random access to elements using arithmetic operations.

# why we use iterator and we don't use pointer ?
While we are using pointers to hold a memory address, whatever memory address, an iterator is always used with containers. An iterator is used to go through the elements of a container and the items of the container don’t need to be stored on a contagious memory area

# iterator Traits 
is a class trait that provides specific information about the iterator that stl::algorithms needs .
or is a template class defined in the Standard Library that provides information about an iterator, such as its value type, difference type, and pointer type. The iterator_traits class is defined in the <iterator> header.
We use iterator_traits to obtain information about an iterator in a type-safe and generic way, without having to know the actual type of the iterator. This is useful when writing generic algorithms that work with iterators, as it allows us to write algorithms that are independent of the specific type of iterator used.

>
* difference_type : Type to express the result of subtracting one iterator from another it gets stored in type able to represent the result of any valid pointer subtraction operation(ptrdiff_t)
And "ptrdiff_t is an integer data type in C++ that is used to represent the difference between two pointer values. It is defined in the <cstddef> header and is guaranteed to be able to store the difference between any two pointers to elements of the same array."

* value_type : The type of element the iterator can point to.

* pointer : the type of a pointer to an element the iterator can point to.

* refernce : The type of reference to an element the iterator can point to.

* The iterator category: it can be one of these:
                        • input_iterator_tag
                        • output_iterator_tag
                        • forward_iterator_tag
                        • bidirectional_iterator_tag
                        • random_access_iterator_tag
>

>
# Vector 
Vectors are sequence containers representing arrays that can change in size.

# Stack
Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), where elements are inserted and extracted only from one end of the container.
# Map
Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.

>
# Vector :
a vector is a data structure that represents a sequence of elements, often of the same type. Vectors are a type of container, meaning they store and manage a collection of elements.
(Why we use vector and not array !)One of the main reasons we use vectors is because they provide dynamic sizing, meaning their size can change as you add or remove elements, unlike arrays which have a fixed size. Vectors also provide a convenient and efficient way to store and manage data. They have a wide range of member functions that allow you to easily manipulate their elements, such as adding or removing elements, accessing elements, and sorting elements.

A vector is implemented as an array that can grow or shrink dynamically. It is implemented as a template class, which means that you can create a vector of elements of any data type, such as int, float, or user-defined types.
Under the hood, a vector is composed of three main components:
  - An array of elements that store the actual data.
  - A variable that stores the size of the vector, or the number of elements it contains.
  - A variable that stores the capacity of the vector, or the maximum   number of elements it can hold.
When you create a vector, you can specify its initial size and capacity. If you do not specify these values, the vector will be created with a default size and capacity.
# When you add elements to the vector, it checks if there is enough capacity to store the new elements. If there is enough capacity, the elements are simply added to the end of the vector. If not, the vector needs to resize itself to accommodate the new elements. This process is called reallocation, and it involves creating a new array with a larger capacity and copying the existing elements to the new array.
When you remove elements from the vector, it adjusts its size accordingly, but its capacity remains the same unless you explicitly reduce it.
