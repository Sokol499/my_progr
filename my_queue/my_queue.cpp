#include <iostream>
using namespace std;

class queue
{
private:
    int maxSize; // для хранения максимального количества элементов очереди
    int* queArray; // для хранения самих элементов очереди (одномерный массив)
    int front; // для хранения первого элемента очереди
    int rear; // для хранения последнего элемента очереди
    int nItems; // для хранения текущего элемента очереди
public:
    // конструктор
    queue(int s) // s - то кол-во элементов, с каким мы хотим создать нашу очередь
    {
        maxSize = s;
        queArray = new int[maxSize];
        front = 0;
        rear = -1; // т.к. front = 0
        nItems = 0;
    }

    // вставка элемента в конец очереди
    void insert(int j) // j - тот элемент, который мы хотим вставить в очередь
    {
        if (rear == maxSize - 1) // происходит циклический перенос
        {
            rear = -1;
            nItems = 0; // т.к. начинается новая очередь
        }
        queArray[++rear] = j; // увеличение rear и вставка
        ++nItems;
    }

    // извлечение элемента в начале очереди
    int remove()
    {
        int temp = queArray[++front]; // выборка и увеличение front
        if (front == maxSize) // циклический перенос
        {
            front = 0;
        }
        --nItems;
        return temp; // возвращаем тот элемент, который извлекли
    }

    // чтение элемента в начале очереди
    int peekFront()
    {
        return queArray[front];
    }

    // проверка очереди на пустоту 
    bool isEmpty()
    {
        return(nItems == 0); // true, если чоередь пуста
    }

    // проверка очереди на заполненность 
    bool isFull()
    {
        return(nItems == maxSize); // true, если чоередь пуста
    }

    // количество элементов в очереди
    int size()
    {
        return nItems;
    }

    // вывод очереди на экран
    void display()
    {
        if (nItems == 0)
        {
            return;
        }
        if (front > rear)
        {
            int j = front;
            while (j != maxSize)
            {
                cout << queArray[j] << endl;
                ++j;
            }
            j = 0;
            while (j <= rear)
            {
                cout << queArray[j] << endl;
                ++j;
            }
        }
        else if (front < rear)
        {
            for (int i = front; i <= rear; ++i)
                cout << i + 1 << queArray[i] << endl;
        }
        else if (nItems == 1)
        {
            cout << queArray[front];
        }
        cout << endl;
        return;
    }
};

int main()
{
   cout << "Hello Ivan!\n";
   return 0;
}

