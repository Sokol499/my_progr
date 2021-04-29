#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Queue
{
private:
    stack<T> s1_;
    stack<T> s2_;
public:
    Queue(const Queue<T>& other)
    {
        s1_ = other.s1_;
        s2_ = other.s2_;
    }

    void push(T k)
    {
        s1_.push(k);
    }

    void pop()
    {
        if (s2_.empty())
        {
            while (!s1_.empty())
            {
                s2_.push(s1_.top());
                s1_.pop();
            }
            s2_.pop();
        }
    }
    void print()
    {
        while (!s1_.empty())
        {
            s2_.push(s1_.top());
            s1_.pop();
        }
        //вывод элементов
        while (!s2_.empty())
        {
            cout << s2_.top() << ' ';
            s1_.push(s2_.top());
            s2_.pop();
        }
    }
};

int main()
{
    return 0;
}