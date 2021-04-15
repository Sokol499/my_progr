#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
	int size_;
	int count_element_;
	T* buffer_;
	void makebigger()
	{
		T* temp = new T[2 * size_];
		for (int i = 0; i < size_; ++i)
		{
			temp[i] = buffer_[i];
		}
		delete[] buffer_;
		size_ *= 2;
		buffer_ = temp;
	}
public:
	Stack()
	{
		buffer_ = new T[1];
		count_element_ = 0;
		size_ = 1;
	}

	Stack(const Stack<T>& other)
	{
		size_ = other.size_;
		count_element_ = other.count_element_;
		buffer_ = new T[size_];
		for (int i = 0; i < count_element_; ++i)
		{
			buffer_[i] = other.buffer_[i];
		}
	}
	void pop()
	{
		--count_element_;
	}
	void push(const T& data)
	{
		if (count_element_ == size_)
		{
			makebigger();
		}
		buffer_[count_element_] = data;
		++count_element_;
	}
	T top() const
	{
		if (count_element_ == 0)
		{
			return -1;
		}
		return buffer_[count_element_ - 1];
	}
	~Stack()
	{
		delete[] buffer_;
	}
	void Print() const
	{
		cout << endl;
		cout << "size_ = " << size_ << endl;
		cout << "count_element_ = " << count_element_ << endl;
		cout << "buffer_ = " << buffer_ << endl;
		for (int i = 0; i < count_element_; ++i)
		{
			cout << buffer_[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	return 0;
}