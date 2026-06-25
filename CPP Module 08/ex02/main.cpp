#include "MutantStack.hpp"

int main()
{
	std::cout << "===== MutantStack Test =====" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.push(0);

	std::cout << "\nContents:" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	std::cout << "\nCopy constructor test:" << std::endl;

	std::stack<int> s(mstack);

	std::cout << "Stack size: " << s.size() << std::endl;
	std::cout << "Stack top : " << s.top() << std::endl;

	return 0;
}
