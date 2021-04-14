#include <iostream>
using namespace std;

class VectorClass
{
    int* arr;
    int capacity; // Размер буффера
    int size_; // Текущее количество элементов, которое присутствует в векторе.

    void makeBigger()
    {
        int* temp = new int[2 * capacity];
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = arr[i];
        }

        delete[] arr;
        capacity *= 2;
        arr = temp;
    }
public:
    VectorClass()
    {
        arr = new int[1];
        capacity = 1;
        size_ = 0;
    }

    VectorClass(const VectorClass& other)
    {
        capacity = other.capacity;
        size_ = other.size_;
        arr = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    void push(int data)
    {
        if (size_ == capacity)
        {
            makeBigger();
        }
        arr[size_] = data;
        size_++;
    }

    int& operator[](int index) const
    {
        return arr[index];
    }

    int get(int index) const
    {
        if (index < size_)
        {
            return arr[index];
        }
        return arr[0];
    }

    void pop()
    {
        --size_;
    }

    int size() const
    {
        return size_;
    }

    int getCapacity() const
    {
        return capacity;
    }

    void print() const
    {
        for (int i = 0; i < size_; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~VectorClass()
    {
        delete[] arr;
    }

    bool operator==(const VectorClass& other) const
    {
        if (size_ != other.size_)
        {
            return false;
        }
        for (int i = 0; i < size_; ++i)
        {
            if (arr[i] != other.arr[i])
            {
                return false;
            }
        }
        return true;
    }
};


int main()
{
    VectorClass v;
    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    v.push(50);
    v.push(60);
    v.push(70);

    cout << "Vector size : " << v.size() << endl;
    cout << "Vector capacity : " << v.getCapacity() << endl;
    cout << "Vector elements : ";

    v.print();
    v[1] = 100;

    cout << "\nAfter updating 1st index" << endl;
    cout << "Vector elements : ";
    v.print();
    cout << "Element at 1st index : " << v.get(1) << endl;
    v.pop();
    cout << "\nAfter deleting last element" << endl;
    cout << "Vector size : " << v.size() << endl;
    cout << "Vector capacity : " << v.getCapacity() << endl;
    cout << "Vector elements : ";
    v.print();
    return 0;
}
