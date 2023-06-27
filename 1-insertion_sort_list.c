#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current, *sorted, *temp;

    current = (*list)->next;
    while (current != NULL)
    {
        sorted = current->prev;
        while (sorted != NULL && sorted->n > current->n)
        {
            temp = current->next;

            /* Update next node */
            if (temp != NULL)
                temp->prev = sorted;

            /* Update prev node */
            sorted->next = temp;

            /* Swap current and sorted */
            current->next = sorted;
            current->prev = sorted->prev;

            if (sorted->prev != NULL)
                sorted->prev->next = current;

            sorted->prev = current;

            if (current->prev == NULL)
                *list = current;

            /* Print list */
            print_list(*list);

            sorted = current->prev;
            current = temp;
        }
        current = current->next;
    }
}
