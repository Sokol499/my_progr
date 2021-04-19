#include <iostream>
using namespace std;
template <class T>
void Merge(T* arr, int left, int right) // функция , которая сливает массив
{
    int middle , start , finish , j;
    int* array = new T[right - left + 1];
    middle = (left + right) / 2; // вычисление среднего элемента
    start = left; // начало левой части
    finish = middle + 1; // начало правой части
    for (j = left; j <= right; j++) // выполнять от начала до конца
    {
        if ((start <= middle) && ((finish > right) || (arr[start] < arr[finish])))
        {
            array[j] = arr[start];
            ++start;
        }
        else
        {
            array[j] = arr[finish];
            ++finish;
        }
    }
    for (j = left; j <= right; j++) // возврат результата
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