#include <iostream>
using namespace std;

int rowSum(int arr[], int size)
{
    if (size == 0)
        return 0;

    return arr[size - 1] + rowSum(arr, size - 1);
}

int recursiveArraySum(int* arr[], int sizes[], int dim)
{
    if (dim == 0)
        return 0;

    return rowSum(arr[dim - 1], sizes[dim - 1])
         + recursiveArraySum(arr, sizes, dim - 1);
}

int main()
{
    int rows = 3;

    int sizes[] = {3, 2, 4};

    int** arr = new int*[rows];

    arr[0] = new int[3]{1, 2, 3};
    arr[1] = new int[2]{4, 5};
    arr[2] = new int[4]{6, 7, 8, 9};

    cout << "Total Sum = "
         << recursiveArraySum(arr, sizes, rows);

    return 0;
}
