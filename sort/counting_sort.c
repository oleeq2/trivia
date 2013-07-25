#include <stdio.h>

void counting_sort(int *array,int *result_array,int n,int max)
{
    int temp_array[max+1];
    int i;
    for (i = 0;i <= max;i++)
        temp_array[i] = 0;

    for (i = 0;i < n; i++)
        temp_array[array[i]]++;

    for (i = 1; i <= max; i++)
        temp_array[i] += temp_array[i-1];

    for (i = 0; i < n; i++)
        result_array[temp_array[array[i]]--] = array[i];
}

