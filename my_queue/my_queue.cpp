#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Queue
{
private:
	stack<T> s1_; // первый стек
	stack<T> s2_; // второй стек
	int size_;
	int elem_;
	T* buffer_;
public:
	Queue()
	{
		buffer_ = new T[1];
		elem_ = 0;
		size_ = 1;
	}

	Queue(const Queue<T>& other)
	{
		size_ = other.size_;
		elem_ = other.elem_;
		buffer_ = new T[size_];
		for (int i = 0; i < elem_; ++i)
		{
			buffer_[i] = other.buffer_[i];
		}
	}

	void push(T k) // кладем элементы в стек s1
	{
		s1_.push(k);
	}

	void pop() // для каждого элемента делаем не более одного перекладывания из стека в стек
	{
		if (s2_.empty)
		{
			while (!s1_.empty())
			{
				T elem_ = s1_.top();
				s1_.pop();
				s2_.push(elem_);
			}
		}
		s2_.top();
		s2_.pop();
		return elem_;
	}
	
	~Queue()
	{
		delete[] buffer_;
	}
};

int main()
{
	return 0;
}

