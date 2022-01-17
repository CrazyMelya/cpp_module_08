# include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	it = mstack.begin();

	it++;
	std::cout << *it << std::endl;


	std::cout << "-----------------------" << std::endl;
	MutantStack<double> myStack;

	myStack.push(3.14);
	myStack.push(2);
	myStack.push(-3.12);
	
	MutantStack<double>::const_reverse_iterator it2 = myStack.rbegin();
	while (it2 != myStack.rend())
		std::cout << *it2++ << std::endl;
	while (--it2 != myStack.rbegin() - 1)
		std::cout << *it2 << std::endl;	

	MutantStack<double>::iterator cit = myStack.begin();

	while (cit != myStack.end())
	{
		(*cit)++;
		std::cout << *cit++ << std::endl;
	}

	return 0;
}
