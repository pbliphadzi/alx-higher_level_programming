#include <stdio.h>
#include <stdlib.h>

typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

listint_t *insert_node(listint_t **head, int number) {
    listint_t *new = malloc(sizeof(listint_t));
    if (!new) {
        return NULL;
    }
    
    new->n = number;
    new->next = NULL; 
    
    if (*head == NULL || (*head)->n >= number) {
        new->next = *head;
        *head = new;
        return new;
    }
    
    listint_t *current
    current = *head;
    while (current->next != NULL && current->next->n < number) {
        current = current->next;
    }
    
    new->next = current->next;
    current->next = new;
    return new;
}

void free_listint(listint_t *head) {
    listint_t *current = head;
    while (current != NULL) {
        printf("%d -> ", current->n);
        current = current->next;
    }
    printf("NULL\n");
}


