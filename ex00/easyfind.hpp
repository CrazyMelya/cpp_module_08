#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

class ElemNotFoundException: public std::exception
{
	const char *what() const throw()
	{
		return "Element not found!";
	}
};

template <typename T>
typename T::const_iterator easyfind(T const &container, int find)
{
	typename T::const_iterator itr = std::find(container.cbegin(), container.cend(), find);

	container.crbegin();
	if (itr == container.end())
		throw ElemNotFoundException();
	
	return itr;
}

#endif
