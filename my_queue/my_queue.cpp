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
        }
        s2_.pop();
    }
    void print() const
    {
        stack s1_copy = s1_;
        stack s2_copy = s2_;
        while (!s2_copy.empty())
        {
            cout << s2_copy.top() << ' ';
            s2_copy.pop();
        }
        while (!s1_copy.empty())
        {
            s2_copy.push(s1_copy.top());
            s1_copy.pop();
        }
        while (!s2_copy.empty())
        {
            cout << s2_copy.top() << ' ';
            s2_copy.pop();
        }
    }
};

int main()
{
    return 0;
}