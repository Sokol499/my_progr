#include<iostream>
#include<cstdlib>

int main()
{
    int N;  // размер массива 
    int i = 0;  // счетчик
    int j = 0;  // счетчик
    int y = 0;  // счетчик

    std::cout << "Set the size of the array: ";
    std::cin >> N;

    int* arr = new int[N];
    int max = arr[0];

    while (i < N)
    {
        std::cout << "arr[" << j++ << "]" << " == ";
        std::cin >> arr[i++];
    }

    for (int k = 0; k < N; k++) 
    {
        if (arr[k] > max)
        {
            max = arr[k];
        }
    }

    std::cout << "\n" << "The largest number: " << max << "\n";

    delete[] arr;
    return 0;
}