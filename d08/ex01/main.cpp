#include "span.hpp"
#include <iostream>

int main()
{
    try {
        std::cout << "Default test:" << std::endl;
        Span sp = Span(5);
        
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "'Full span exception' test:" << std::endl;
        Span sp = Span(2);
        
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "'Empty span' test:" << std::endl;
        Span sp = Span(5);
        
        sp.addNumber(5);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}
