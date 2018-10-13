#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
    typedef std::stack<T>   stack;

public:
    typedef typename stack::container_type::iterator iterator;
    using stack::operator=;

    iterator begin() {
        return (stack::c.begin());
    }

    iterator end() {
        return (stack::c.end());
    }
};

#endif // MUTANTSTACK_HPP