#include "span.hpp"

Span::Span() :
arr(NULL), it(0), size(0) {}

Span::Span(unsigned n) :
arr(NULL), it(0), size(n)
{
    this->arr = new unsigned[n];
}

Span::Span(const Span &src) {
    *this = src;
}

Span::~Span() {
    if (this->arr)
        delete[] this->arr;
}

Span &Span::operator=(const Span &rhs)
{
    if (arr)
        delete[] arr;
    this->it = rhs.it;
    this->size = rhs.size;
    this->arr = new unsigned[rhs.size];
    for (unsigned i = 0; i < rhs.it; i++)
        this->arr[i] = rhs.arr[i];

    return (*this);
}

void    Span::addNumber(unsigned numb) {
    if (this->it == this->size)
        throw Span::SpanIsFullException();
    this->arr[this->it] = numb;
    this->it++;
}

unsigned    Span::shortestSpan() {
    unsigned    small, smallest;

    if (this->it <= 1)
        throw Span::NoSpanToFindException();
    
    small = this->arr[0];
    smallest = this->arr[0];
    for (unsigned i = 0; i < this->it; i++)
        if (this->arr[i] < smallest) {
            std::swap(small, smallest);
            smallest = this->arr[i];
        }
    return (small - smallest);
}

unsigned    Span::longestSpan() {
    unsigned    max, min;

    if (this->it <= 1)
        throw Span::NoSpanToFindException();
    
    min = this->arr[0];
    max = this->arr[0];
    for (unsigned i = 0; i < this->it; i++)
        if (this->arr[i] < min)
            min = this->arr[i];
        else if (this->arr[i] > max)
            max = this->arr[i];
    return (max - min);
}

Span::SpanIsFullException::SpanIsFullException() {}

Span::SpanIsFullException::SpanIsFullException(const SpanIsFullException &src) {
	*this = src;
}

Span::SpanIsFullException::~SpanIsFullException() throw() {}

Span::SpanIsFullException	&Span::SpanIsFullException::operator=(const SpanIsFullException &rhs) {
	UNUSED(rhs);
	return (*this);
}

const char		*Span::SpanIsFullException::what() const throw() {
	return (SPAN_IS_FULL_EXCEPTION);
}

Span::NoSpanToFindException::NoSpanToFindException() {}

Span::NoSpanToFindException::NoSpanToFindException(const NoSpanToFindException &src) {
	*this = src;
}

Span::NoSpanToFindException::~NoSpanToFindException() throw() {}

Span::NoSpanToFindException	&Span::NoSpanToFindException::operator=(const NoSpanToFindException &rhs) {
	UNUSED(rhs);
	return (*this);
}

const char		*Span::NoSpanToFindException::what() const throw() {
	return (NO_SPAN_TO_FIND_EXCEPTION);
}