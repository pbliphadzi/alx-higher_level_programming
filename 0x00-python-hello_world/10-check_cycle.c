#include "lists.h"

/**
 * check_cycle - function checks if a singly linked list has a cycle in it.
 * @list: pointer to the beginning of the node
 * Return: 0 if no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *slow_ptr, *fast_ptr;

    if (list == NULL || list->next == NULL)
        return 0;

    slow_ptr = list;
    fast_ptr = list->next;

    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        if (slow_ptr == fast_ptr)
            return 1;

        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    return 0;
}
