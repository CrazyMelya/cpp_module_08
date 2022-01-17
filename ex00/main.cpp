#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> myVector;

	try
	{
		myVector.push_back(5);
		myVector.push_back(42);
		myVector.push_back(13);
		myVector.push_back(-10);
		myVector.push_back(-23);

		//for (unsigned int i = 0; i < myVector.size(); i++)
		//	std::cout << myVector[i] << std::endl;

		std::vector<int>::const_iterator it = easyfind(myVector, -10);
		std::cout << *it << std::endl;
		std::cout << std::distance((myVector.cbegin()), it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
