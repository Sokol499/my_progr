#include <iostream>
using namespace std;

template <class T>
bool compare(const T& a, const T& b)
{
    return a < b;
}

template <class T>
void Merge(T* arr, int left, int right) // функция , которая сливает массив
{
    int middle , iterator_left_part, iterator_right_part , j;
    int* array = new T[right - left + 1];
    middle = (left + right) / 2; // вычисление среднего элемента
    iterator_left_part = left; // начало левой части
    iterator_right_part = middle + 1; // начало правой части
    for (j = left; j < right; j++) // выполнять от начала до конца
    {
        if ((iterator_left_part <= middle) && ((iterator_right_part > right) || (compare(arr[iterator_left_part], arr[iterator_right_part]))))
        {
            array[j] = arr[iterator_left_part];
            ++iterator_left_part;
        }
        else
        {
            array[j] = arr[iterator_right_part];
            ++iterator_right_part;
        }
    }
    for (j = left; j < right; j++) // возврат результата
    {
        arr[j] = array[j];
    }
    delete[] array;
};

template <class T>
void MergeSort(T* arr, T left, T right) // рекурсивная функция сортировки
{
    if (left < right)
    {
        MergeSort(arr, left, (left + right) / 2); // сортировка левой части
        MergeSort(arr, (left + right) / 2 + 1, right);  // сортировка правой части
        Merge(arr, left, right);  // слияние двух частей
    }
}

int main() // главная функция
{
    return 0;
};