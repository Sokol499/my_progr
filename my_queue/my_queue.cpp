#include <iostream>
#include <stack>
using namespace std;

class Queue
{
private:
    stack <int> s1_;
    stack <int> s2_;
public:
    void push(int k)
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
    };

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
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    q.print();
    cout << endl;

    //удаляем элемент очереди
    q.pop();
    q.print();
    cout << endl;

    //удаляем элемент очереди
    q.pop();
    q.print();
    cout << endl;

    //удаляем элемент очереди
    q.pop();
    q.print();
    cout << endl;

    //удаляем элемент очереди
    q.pop();
    q.print();
    cout << endl;

    //удаляем элемент очереди
    q.pop();
    q.print();
    cout << endl;

    //удаляем элемент очереди
    q.pop();
    q.print();
    cout << endl;

    return 0;
}