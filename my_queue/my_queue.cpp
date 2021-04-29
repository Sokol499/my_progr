#include <iostream>
#include <stack>
using namespace std;

template <class T>
class queue
{
	stack <T> s1_; // первый стек
	stack <T> s2_; // второй стек
public:
	void push(T n) // кладем элементы в стек s1
	{
		s1_.push(n);
	}

	void pop() // для каждого элемента делаем не более одного перекладывания из стека в стек
	{
		while (!s1_.empty())
		{
			s2_.push(s1_.top());
			s1_.pop();
		}
		s2_.pop();
		//добавляем элементы обратно
		while (!s2_.empty())
		{
			s1_.push(s2_.top());
			s2_.pop();
		}
	}
};

int main()
{
	return 0;
}

