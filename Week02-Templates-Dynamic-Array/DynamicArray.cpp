#include <iostream>
#include <vector>
#include <utility>

template<typename T>
class DynArr
{
public:
	explicit DynArr(int capacity)
	{
		if (!capacity) throw std::invalid_argument("cant be 0");
		data = new T[capacity];
		cap = capacity;
		size = 0;
	}

	DynArr()
		:DynArr(4)
	{

	}

	DynArr(const DynArr& other)
	{
		cap = other.cap;
		size = other.size;
		data = new T[cap];
		try
		{
			for (int i = 0; i < other.size; i++)
			{

				data[i] = other.data[i];
			}
		}
		catch (...)
		{
			delete[] data;
			throw;
		}

	}

	DynArr& operator=(const DynArr& other)
	{
		if (this != &other)
		{
			DynArr copy(other);
			swap(copy);
		}
		return *this;
	}

	~DynArr()
	{
		delete[] data;
	}

	void push_back(const T& elem)
	{
		if (size == cap) resize();  //this is the dynamic part
		data[size] = elem;
		size++;
	}

private:
	T* data;
	int size;
	int cap;

	void swap(DynArr& other)
	{
		std::swap(data, other.data);
		std::swap(cap, other.cap);
		std::swap(size, other.size);
	}

	void resize()
	{
		int newcap = cap * 2;
		T* newdata = new T[newcap];
		try
		{
			for (int i = 0; i < size; i++)
			{
				newdata[i] = data[i];
			}
		}
		catch (...)
		{
			delete[] newdata;
			throw;
		}
		delete[] data;
		data = newdata;
		cap = newcap;
	}
};



int main()
{
	DynArr<int> myarr(2);
	myarr.push_back(1);
	myarr.push_back(2);
	myarr.push_back(3);

	std::vector<int> v;
    v.push_back(1);
}