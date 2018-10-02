#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template<class T>
class Array {
	unsigned int	length;
	T				*arr;

public:
	Array<T>() {
		arr = 0;
		length = 0;
	}

	Array<T>(unsigned int n) {
		arr = new T[n];
		length = n;
	}

	~Array<T>() {
		delete[] arr;
	}

	Array<T>(const Array<T> &src) {
		*this = src;
	}

	T	&operator=(const Array<T> &src) {
		this->arr = new T[src.size()];
		this->length = src.size();

		for (unsigned int i = 0; i < this->length; i++)
			this->arr[i] = src[i];

		return (*this);
	}

	T	&operator[](unsigned int i) {
		if (i >= length)
			throw std::exception();
		return (arr[i]);
	}

	unsigned int	size() const {
		return (length);
	}

	const T			*getArr() const {
		return (arr);
	}
};

#endif //ARRAY_HPP
