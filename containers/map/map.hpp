# ifndef MAP_HPP
#define MAP_HPP
#include <map>
#include "../../tools/enable_if.hpp"
#include "../../tools/is_integral.hpp
#include "../../tools/lexicographical_compare.hpp"
#include "../../tools/pair.hpp"

// #include <utility>
// #include <memory>
namespace ft
{
    template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>> > 
    class map
    {

    };
}

#endif