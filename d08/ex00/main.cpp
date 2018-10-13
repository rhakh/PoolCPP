#include <list>
#include <string>
#include <iostream>
#include "easyfind.hpp"

int    main(void) {
    std::list<int>  list;
    std::list<int>  empty;
    std::list<int>::iterator  it;
    std::list<int>::iterator  res;
    int n;

    list.push_back(1);
    list.push_back(2);
    list.push_back(4);
    list.push_back(64);
    list.push_back(1);
    list.push_back(24);

    std::cout << "List:" << std::endl;
    it = list.begin();
    while (it != list.end()) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;

    {
        n = 64;
        res = easyfind(list, n);
        if (res != list.end())
            std::cout << "Search for " << n << ": " << *res << std::endl;
        else
            std::cout << "Search for " << n << ": Not found" << std::endl;
    }

    {
        n = 24;
        res = easyfind(list, n);
        if (res != list.end())
            std::cout << "Search for " << n << ": " << *res << std::endl;
        else
            std::cout << "Search for " << n << ": Not found" << std::endl;
    }

    {
        n = 1;
        res = easyfind(list, n);
        if (res != list.end())
            std::cout << "Search for " << n << ": " << *res << std::endl;
        else
            std::cout << "Search for " << n << ": Not found" << std::endl;
    }

    {
        n = 80;
        res = easyfind(list, n);
        if (res != list.end())
            std::cout << "Search for " << n << ": " << *res << std::endl;
        else
            std::cout << "Search for " << n << ": Not found" << std::endl;
    }

    {
        std::cout << "Test for empty list:" << std::endl;
        n = 5;
        res = easyfind(empty, n);
        if (res != empty.end())
            std::cout << "Search for " << n << ": " << *res << std::endl;
        else
            std::cout << "Search for " << n << ": Not found" << std::endl;
    }

    return (0);
}