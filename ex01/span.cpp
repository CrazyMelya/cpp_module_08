#include "span.hpp"

Span::Span(unsigned int N)
{
	this->_vec.reserve(N);
}

Span::Span(Span const &other)
{
	*this = other;
}

Span::~Span()
{
}

Span &Span::operator=(Span const &other)
{
	this->_vec = other._vec;
	return *this;
}

std::vector<int> Span::getVec() const
{
	return this->_vec;
}

void Span::addNumber(int num)
{
	if (this->_vec.size() < this->_vec.capacity())
		this->_vec.push_back(num);
	else
		throw NotEnoughSpaceException();
}

void Span::addNumber(spanIter begin, spanIter end)
{
	if (static_cast<unsigned int>(end - begin) > this->_vec.capacity() - this->_vec.size())
		throw NotEnoughSpaceException();
	
	while (begin != end)
		this->_vec.push_back(*begin++);
}

int Span::longestSpan()
{
	if (this->_vec.size() < 2)
		throw NotEnoughElementsException();

	std::vector<int> copy = this->_vec;
	std::sort(copy.begin(), copy.end());
	return  *(copy.end() - 1) - *copy.begin();
}

int Span::shortestSpan()
{
	int shortest_span;
	if (this->_vec.size() < 2)
		throw NotEnoughElementsException();

	std::vector<int> copy = this->_vec;
	std::sort(copy.begin(), copy.end());
	shortest_span = this->longestSpan();
	for (spanIter it = copy.begin(); it + 1 < copy.end(); it++)
	{
		if (shortest_span > *(it + 1) - *it)
			shortest_span = *(it + 1) - *it;
	}
	return shortest_span;
}

const char *Span::NotEnoughSpaceException::what() const throw()
{
	return "Not enough space"; 
}

const char *Span::NotEnoughElementsException::what() const throw()
{
	return "Not enough elements";
}

std::ostream &operator<<(std::ostream &os, Span const &span)
{
	spanIter it = span.getVec().begin();

	if (span.getVec().size() > 0)
	{
		while (it < span.getVec().end() - 1)
			os << *it++ << " ";
		os << *it;
	}
	return os;
}
