#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 *
 * @list: pointer to list.
 *
 * Return: 1 is yes, 0 if no.
 */

int check_cycle(listint_t *list)
{
listint_t *s;
listint_t *f;

if (!list || !(list->next))
return (0);

s = list;
f = list->next;
while (f->next)
{
f = f->next;
if (f->next)
f = f->next;
else
return (0);
s = s->next;
if (s == f)
return (1);
}
return (0);
}
