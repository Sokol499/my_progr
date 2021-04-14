#include <iostream>
using namespace std;

void Merge(int* arr, int left, int right) //функция , которая сливает массив
{
    int middle , start , final , j;
    int* array = new int[100];
    middle = (left + right) / 2; //вычисление среднего элемента
    start = left; //начало левой части
    final = middle + 1; //начало правой части
    for (j = left; j <= right; j++) //выполнять от начала до конца
    {
        if ((start <= middle) && ((final > right) || (arr[start] < arr[final])))
        {
            array[j] = arr[start];
            start++;
        }
        else
        {
            array[j] = arr[final];
            final++;
        }
    }
    for (j = left; j <= right; j++) //возврат результата
    {
        arr[j] = array[j];
    }
    delete[] array;
};
void MergeSort(int* arr, int left, int right) //рекурсивная функция сортировки
{
    if (left < right)
    {
        MergeSort(arr, left, (left + right) / 2); //сортировка левой части
        MergeSort(arr, (left + right) / 2 + 1, right);  //сортировка правой части
        Merge(arr, left, right);  //слияние двух частей
    }
}
void main() //главная функция
{
    setlocale(LC_ALL, "Rus");
    int i, n;
    int* arr = new int[100];
    cout << "Размер массива :";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cout << i << " Элемент массива : ";
        cin >> arr[i];
    }
    MergeSort(arr, 1, n); //вызов сортировки
    cout << "Упорядоченный массив по возрастанию : "; //вывод упорядоченного массива
    for (i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
};