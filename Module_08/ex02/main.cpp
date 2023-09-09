#include "MutantStack.hpp"

int main()
{
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
	}
	{
		std::cout << "\nMy tests:" << std::endl;
        MutantStack<int> mystack;

        mystack.push(10);
        mystack.push(20);
        mystack.push(30);
		std::cout << "Size before pop: " <<mystack.size() << std::endl;
		mystack.pop();
		std::cout << "Size after pop: " <<mystack.size() << std::endl;
        MutantStack<int> stk(mystack);
        std::cout << stk.top() << std::endl;
		stk.push(30);
        std::cout << "Forward traversal:" << std::endl;
        for (MutantStack<int>::const_iterator it = stk.begin(); it != stk.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Reverse traversal:" << std::endl;
        for (MutantStack<int>::reverse_iterator rit = stk.rbegin(); rit != stk.rend(); ++rit) {
            std::cout << *rit << " ";
        }
        std::cout << std::endl;

		std::cout << "Const reverse traversal:" << std::endl;
		for (MutantStack<int>::const_reverse_iterator rit = stk.rbegin(); rit != stk.rend(); ++rit) {
			std::cout << *rit << " ";
		}
		std::cout << std::endl;

		std::cout << "Const forward traversal:" << std::endl;
		for (MutantStack<int>::const_iterator it = stk.begin(); it != stk.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
    }
	return 0;
}