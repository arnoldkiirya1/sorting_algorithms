#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using Selection sort algorithm
 * @array: Pointer to the array
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    size_t i, j, min_idx;
    int temp;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
        {
            temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;

            /* Print array */
            print_array(array, size);
        }
    }
}
