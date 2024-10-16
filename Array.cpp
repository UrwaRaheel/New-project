#include <iostream>
using namespace std;
class Array
{
	int* data;
	int capacity;
	bool isValidIndex(int index)
	{
		return (index >= 0 && index < capacity);
	}
public:
	Array(int cap = 0)
	{
		if (cap <= 0)
		{
			capacity = 0;
			data = nullptr;
		}
		else if (cap > 0)
		{
			capacity = cap;
			data = new int[capacity];
		}
		cout << "ctor\n";
	}
	int& getSet(int index)
	{
		if (isValidIndex(index))
		{
			return data[index];
		}
		exit(0);
	}
	int getCapacity()
	{
		return capacity;
	}
	~Array()
	{
		delete[] data;
		data = nullptr;
		capacity = 0;
		cout << "dtor\n";
	}
	void resize(int newCapacity)
	{
		if (newCapacity <= 0)
		{
			this->~Array();
			return;
		}
		int* temp = new int[newCapacity];
		int smallerCap = (newCapacity < capacity ? newCapacity : capacity);
		for (int i = 0; i < smallerCap; i++)
		{
			temp[i] = data[i];
		}
		this->~Array();
		data = temp;
		capacity = newCapacity;
	}

	Array(Array&& ref)
	{
		cout << "Move ctor\n";
		data = ref.data;
		capacity = ref.capacity;
		ref.data = nullptr;
		ref.capacity = 0;

	}
	Array &operator =(const Array& ref)
	{
		cout << "cpy assignment operator\n";
		if (this == &ref)
		{
			return *this;
		}
		this->~Array();
		if (!ref.data)
		{
			return *this;
		}
		capacity = ref.capacity;
		data = new int[capacity];
		for (int i = 0; i < ref.capacity; i++)
		{
			data[i] = ref.data[i];
		}
		return *this;
	}
	Array(const Array& ref)

	{
		cout << "cpy ctor\n";

		if (!ref.data)
		{
			return;
		}
		capacity = ref.capacity;
		data = new int[capacity];
		for (int i = 0; i < ref.capacity; i++)
		{
			data[i] = ref.data[i];
		}

	}
	Array& operator=(Array&& ref)
	{
		cout << "move assignment operator\n";
		this->~Array();
		data = ref.data;
		capacity = ref.capacity;
		ref.data = nullptr;
		capacity = 0;
		return *this;
	}
	int& operator[](int index)
	{
		if (isValidIndex(index))
		{
			return data[index];
		}
		exit(0);
	}
	/*Array f()
	{
		int x;
		Array arr;
		Array arr1;
		if (x = 1)
		{
			return arr;
		}
		else
		{
			return arr1;
		}
	}*/
	void input()
	{
		for (int i = 0; i < capacity; i++)
		{
			cin >> data[i];
		}
	}
	friend ostream& operator <<(ostream& out, Array& ref)
	{
		for (int i = 0; i < ref.capacity; i++)
		{
			out << ref.data[i] << " ";
		}
		return out;
	}
	friend istream& operator>>(istream& in, Array& ref)
	{
		cout << ">> operator\n";
		for (int i = 0; i < ref.capacity; i++)
		{
			in >>ref. data[i];
		}
		return in;
	}
};
Array f(Array a)
{
	return a;
}
int main()
{
	Array arr{ 3 };
	//arr[0] = 9;
	cin >> arr[0];
	cout << arr[0];
}
