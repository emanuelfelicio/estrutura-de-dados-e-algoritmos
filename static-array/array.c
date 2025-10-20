#include <stdio.h>
#define ARRAY_LENGHT 3
int main()
{
    // array definition
    int array[ARRAY_LENGHT];

    for (int i = 0; i < ARRAY_LENGHT; i++)
    {
        // assigning value
        array[i] = i * 10;
        // acessing value
        printf("%d\n", array[i]);
    }
    //multi-dimesion array
    int multi_array[ARRAY_LENGHT][ARRAY_LENGHT];

    for (int i = 0; i < ARRAY_LENGHT; i++)
    {
        for (int j = 0; j < ARRAY_LENGHT; j++)
        {
            multi_array[i][j] = (i + j) * 10;
            printf("%d\n", multi_array[i][j]);
        }
        }
}