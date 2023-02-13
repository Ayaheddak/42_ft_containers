# ifndef STACK_HPP
#define STACK_HPP
#include <deque>
#include <vector>
#include <cstddef>
#include "../vector/vector.hpp"

/*
    - Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out),
    where elements are inserted and extracted only from one end of the container.
    - Stacks are implemented as containers adaptors, which are classes that use an encapsulated object of a specific container class as its
    underlying container, providing a specific set of member functions to access its elements. Elements are pushed/popped from the "back"
    of the specific container, which is known as the top of the stack.
    - The underlying container may be any of the standard container class templates or some other specifically designed container class.
    The container shall support the following operations:
        - empty
        - size
        - back
        - push_back
        - pop_back
*/
namespace ft
{
   template <class T, class Container = std::deque<T> >
    class stack
    {
        public :
            typedef Container                               container_type;
            typedef typename Container::value_type          value_type   
            typedef typename Container::size_type           size_type;
            typedef typename Container::reference           reference;
            typedef typename Container::const_reference     const_reference;
        protected :
            container_type _c;
        
        public :
        /* ================================ constructor =============================== */
            explicit stack (const container_type& ctnr = container_type()):_c(ctnr)
            stack &operator=(const stack &x)
            {
                c = x.c;
                return (*this);
            }
            ~stack() {}
        /* ================================ Element access =============================== */
            bool empty() const { return (c.empty()); }
            size_type size() const
            {
                return (c.size());
            }
            value_type& top()
            {
                return (c.back());
            }
            const value_type& top() const
            {
                return (c.back());
            }
            void push (const value_type& val)
            {
                c.push_back(val);
            }
            void pop()
            {
                c.pop_back();
            }
    };
    template <class T, class Container>
    bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c == rhs.c; }
    template <class T, class Container>
    bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c != rhs.c; }
    template <class T, class Container>
    bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c < rhs.c; }
    template <class T, class Container>
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c <= rhs.c; }
    template <class T, class Container>
    bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c > rhs.c; }
    template <class T, class Container>
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c >= rhs.c; }
}
#endif