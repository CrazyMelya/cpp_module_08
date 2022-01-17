#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <fstream>

typedef std::vector<int>::iterator spanIter;

class Span
{
private:
	std::vector<int> _vec;
public:
	Span(unsigned int N = 0);
	Span(Span const &other);
	~Span();

	Span &operator=(Span const &other);

	std::vector<int> getVec() const;
	void addNumber(int num);
	void addNumber(spanIter begin, spanIter end);
	int shortestSpan();
	int longestSpan();
	class NotEnoughSpaceException: public std::exception
	{
		const char *what() const throw();
	};
	class NotEnoughElementsException: public std::exception
	{
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Span const &span);

#endif
