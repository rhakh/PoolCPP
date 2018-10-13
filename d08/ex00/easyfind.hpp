#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template<typename T>
typename T::iterator    easyfind(T &arr, int n)
{
    typename T::iterator start = arr.begin();
    typename T::iterator end = arr.end();

    while (start != end && *start != n)
        start++;
    return (start);
};



#endif // EASYFIND_HPP