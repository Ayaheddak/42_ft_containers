# ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP
# include <type_traits>
namespace ft
{
    template <typename T>
        struct is_integral : std::is_integral<T> {};

    template <typename T>
        struct is_integral<const T> : is_integral<T> {};

    template <typename T>
        struct is_integral<volatile T> : is_integral<T> {};

    template <typename T>
        struct is_integral<const volatile T> : is_integral<T> {};
}

#endif
/*
The std::is_integral type trait is part of the <type_traits> header in the Standard Template Library (STL)
and it can be used to check if a type is an integral type at compile-time.
It returns a std::true_type or std::false_type based on the result of the check.
*/