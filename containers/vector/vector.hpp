#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <vector>
namespace ft
{
    template <class T, class Allocator = allocator<T> >
    class vector
    {
        public:
            
        private :
            T* _array;
            size_t _size;
            size_t _capacity;
            Allocator _allocator;
    };
    
}
#endif