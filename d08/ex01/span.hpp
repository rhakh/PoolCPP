#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>

#define UNUSED(var)			{(void)(var);}
#define SPAN_IS_FULL_EXCEPTION  "Span is full"
#define NO_SPAN_TO_FIND_EXCEPTION   "No span to find"

class Span {
    unsigned    *arr;
    unsigned    it;
    unsigned    size;

public:
    Span();
    Span(unsigned n);
	Span(const Span &src);
	~Span();
    Span &operator=(const Span &rhs);
    
    void addNumber(unsigned numb);
    unsigned shortestSpan();
    unsigned longestSpan();

    class SpanIsFullException : public std::exception {
	public:
		SpanIsFullException();
		SpanIsFullException(const SpanIsFullException &src);
		~SpanIsFullException() throw();
		SpanIsFullException	&operator=(const SpanIsFullException &rhs);
		virtual const char		*what() const throw();
    };

    class NoSpanToFindException : public std::exception {
	public:
		NoSpanToFindException();
		NoSpanToFindException(const NoSpanToFindException &src);
		~NoSpanToFindException() throw();
		NoSpanToFindException	&operator=(const NoSpanToFindException &rhs);
		virtual const char		*what() const throw();
    };
};

#endif // SPAN_HPP