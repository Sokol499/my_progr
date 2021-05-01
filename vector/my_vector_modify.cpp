#include <iostream>
using namespace std;

template <class T>
class VectorClass
{
    T* arr_;
    int capacity_; // Размер буффера
    int size_; // Текущее количество элементов, которое присутствует в векторе.

    void makeBigger()
    {
        T* temp = new T[2 * capacity_];
        for (int i = 0; i < capacity_; ++i)
        {
            temp[i] = arr_[i];
        }

        delete[] arr_;
        capacity_ *= 2;
        arr_ = temp;
    }
public:
    VectorClass()
    {
        arr_ = new T[1];
        capacity_ = 1;
        size_ = 0;
    }

    VectorClass(const VectorClass& other)
    {
        capacity_ = other.capacity_;
        size_ = other.size_;
        arr_ = new T[capacity_];
        for (int i = 0; i < capacity_; ++i)
        {
            arr_[i] = other.arr_[i];
        }
    }

    void push(T data)
    {
        if (size_ == capacity_)
        {
            makeBigger();
        }
        arr_[size_] = data;
        ++size_;
    }

    T& operator[](T index) const
    {
        return arr_[index];
    }

    T get(T index) const
    {
        if (index < size_)
        {
            return arr_[index];
        }
        return arr_[0];
    }

    void pop()
    {
        --size_;
    }

    T size() const
    {
        return size_;
    }

    T getCapacity() const
    {
        return capacity_;
    }

    void print() const
    {
        for (int i = 0; i < size_; ++i)
        {
            cout << arr_[i] << " ";
        }
        cout << endl;
    }

    ~VectorClass()
    {
        delete[] arr_;
    }

    bool operator==(const VectorClass& other) const
    {
        if (size_ != other.size_)
        {
            return false;
        }
        for (int i = 0; i < size_; ++i)
        {
            if (arr_[i] != other.arr_[i])
            {
                return false;
            }
        }
        return true;
    }
};


int main()
{
    return 0;
}
