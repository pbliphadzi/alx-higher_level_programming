#ifndef _LIST_FUNCTIONS_H_
#define _LIST_FUNCTIONS_H_
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 *
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
listint_t *insert_node(listint_t **head, int number);
void free_listint(listint_t *head);


#endif /* _LIST_FUNCTIONS_H_ */