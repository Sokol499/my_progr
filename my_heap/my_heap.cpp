#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class Heap
{
private:
    int size_;
    std::vector<T> arr_;
    void ShiftUp(T* arr_, int k)
    {
        while (true)
        {
            int parent = k - 1 / 2;
            {
                if (k == 0)
                {
                    return;
                }
                if (arr_[parent] < arr_[k])
                {
                    swap(arr_[parent], arr_[k]);
                    k = parent;
                }
                else
                {
                    return;
                }
            }
        }
    }
    void ShiftDown(T*arr_, int k)
    {
        while (true)
        {
            int first_child = k * 2 + 1;
            int second_child = k * 2 + 1;
            if (first_child < arr_.size())
            {
                if (arr_[first_child] > arr_[k])
                {
                    swap(arr_[first_child], arr_[k]);
                    k = first_child;
                }
                else
                {
                    if (arr_[second_child] > arr_[k])
                    {
                        swap(arr_[second_child], arr_[k]);
                        k = second_child;
                    }
                    else
                    {
                        return;
                    }
                }
            }
            else
            {
                return;
            }
        }
    }
public:
    void Add(T*arr_, const T& elem)
    {
        arr_.push_back(elem);
        ShiftUp(arr_.size() - 1);
    }
    Heap() {}
    Heap(const T& elem)
    {
        Add(elem);
    }
    Heap(const vector<T>& vec)
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            Add(vec[i]);
        }
    }
    T PopMax(T* arr_)
    {
        T maximum = arr_[0];
        swap(arr_[0], arr_[arr_.size() - 1]);
        arr_.pop_back();
        ShiftDown(0);
        return maximum;
    }
};

int main()
{
    cout << "Hello Ivan!\n";
    return 0;
}






            
