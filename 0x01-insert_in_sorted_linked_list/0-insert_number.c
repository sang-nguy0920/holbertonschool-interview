#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 *
 * @head: head
 * @number: number to insert
 *
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
listint_t *new, *p;
if (!head)
return (NULL);
new = malloc(sizeof(listint_t));
if (new == NULL)
return (NULL);
new->n = number;
if (!*head)
{
*head = new;
return (new);
}
p = *head;
if (number < p->n)
{
new->next = p;
*head = new;
return (new);
}
while (p->next && number > p->next->n)
{
p = p->next;
}
new->next = p->next;
p->next = new;
return (new);
}
