#include <iostream>

int main()
{
    int size;  // размер массива
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    int* arr = new int[size];
    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    for (int i = 1; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
        {
            max = arr[i];
            std::cout << "Local maximum: " << max << "\n";
        }
    }

    for (int i = 1; i < size - 1; i++)
    {
        if (arr[i] < arr[i + 1] && arr[i] < arr[i - 1])
        {
            min = arr[i];
            std::cout << "Local minimum: " << min << "\n";
        }
    }

    delete[] arr;
    return 0;
}