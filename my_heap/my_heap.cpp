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
    void ShiftUp(int k)
    {
        while (true)
        {
            int parent = (k - 1) / 2;
            if (k == 0)
            {
                return;
            }
            if (arr_[parent] < arr_[k])
            {
                std::swap(arr_[parent], arr_[k]);
                k = parent;
            }
            else
            {
                return;
            }
        }
    }
    void ShiftDown(int k)
    {
        while (true)
        {
            int first_child = k * 2 + 1;
            int second_child = k * 2 + 2;
            if (first_child < arr_.size() && arr_.size() < second_child)
            {
                if (arr_[first_child] > arr_[k])
                {
                    std::swap(arr_[first_child], arr_[k]);
                    k = first_child;
                }
            }
            else
            {
                return;
            }
            if (second_child >= arr_.size() && arr_.size() > first_child)
            {
                if (arr_[second_child] > arr_[k])
                {
                    std::swap(arr_[second_child], arr_[k]);
                    k = second_child;
                }
            }
            else
            {
                return;
            }
            if (arr_.size() > first_child && arr_.size() > second_child)
            {
                exit(0);
            }
            if (first_child > second_child)
            {
                std::swap(arr_[first_child], arr_[k]);
                k = first_child;
            }
            else if (first_child < second_child)
            {
                std::swap(arr_[second_child], arr_[k]);
                k = second_child;
            }
        }
    }
public:
    void Add(const T& elem)
    {
        arr_.push_back(elem);
        ShiftUp(arr_.size() - 1);
    }
    Heap() {}
    Heap(const T& elem)
    {
        Add(elem);
    }
    Heap(const std::vector<T>& vec)
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            Add(vec[i]);
        }
    }
    T PopMax()
    {
        T maximum = arr_[0];
        std::swap(arr_[0], arr_[arr_.size() - 1]);
        arr_.pop_back();
        ShiftDown(0);
        return maximum;
    }
};

int main()
{
    return 0;
}