#include <stdio.h>
// usado quando elementos estão ordenados e o acesso para cada elemento é O(1)

// complexidade de tempo O(log n)
int binary_search(int n, int *array, int target)
{
    int left = 0;  // primeiro indice
    int right = n; // ultimo indice

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // obtém o indice do meio

        if (array[mid] > target)
        {
            right = mid - 1;
        }
        else if (array[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            return mid; // posição do target
        }
    }

    return -1; // target não está no array
}

int recursive_binary_search(int *array, int target, int left, int right)
{

    if (left > right)
        return -1; // caso base

    int mid = left + (right - left) / 2;

    if (array[mid] == target)
        return mid; // caso base

    // casos rescursivos
    if (array[mid] < target)
    {
        return recursive_binary_search(array, target, mid + 1, right);
    }

    return recursive_binary_search(array, target, left, mid - 1);
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 40;
    int result = recursive_binary_search(arr, x, 0, n - 1);
    if (result == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present at index %d\n", result);
    return 0;
}