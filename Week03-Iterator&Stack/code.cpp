#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>


bool task1(const std::string& str)
{
	std::stack<char> stack;

	for (char s : str)
	{
		//HOMEWORK
	}

}

int main()
{
	//iterators
	{
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);


		//instead of this
		for (int i = 0; i < v.size(); i++)
		{
			std::cout << v[i];
		}

		//we can do this
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			std::cout << *it;
		}

		//or even this	(this is syntax sugar for the upper)
		for (int num : v)
		{
			std::cout << num;
		}

		std::list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		
		//the same result, the same syntax, different data structure!
		for (int num : l)
		{
			std::cout << num;
		}
	}

	//invalidation
	{
		std::vector<int> v(2);
		auto it = v.begin();
		std::cout << *it;	//ok
		v.push_back(1);
		std::cout << *it;	//crashes! the iterator is invalidated
	}


	//example usage of stack
	std::stack<int> s;
	s.push(1);
	int a = s.top();
	s.pop();
}