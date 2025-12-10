#include <stdio.h>

// quicksort usando lomutus partition


// troca de posição
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// retorna posição do pivot
int partition(int *array, int first, int last)
{
    int pivot = array[last]; // pivot 
    int i = first-1; // ultimo elemento meno que pivot

    for (int j = first; j < last; j++)
    {
    
        if (array[j] < pivot)
        {
            i++;
            swap(&array[j], &array[i]);
            
        }
    }
    swap(&array[i+1], &array[last]); // coloca pivot ;

    return i+1;
}

void quicksort(int *array, int first, int last)
{   // caso recursivo
    if (first < last)
    {
        int pivot = partition(array, first, last);
        quicksort(array, first, pivot - 1);
        quicksort(array, pivot + 1, last);
    }
}

int main()
{
    int array[] = {10, 7, 8, 9, 1, 5, 3, 20, 15,10,10,10,10,1,1,1,1};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array original:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    quicksort(array, 0, n - 1);

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}
