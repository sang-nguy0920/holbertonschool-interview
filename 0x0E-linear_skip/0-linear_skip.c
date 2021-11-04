#include "search.h"

/**
 * linear_skip -  function that searches for a value
 *
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: value
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *pass = NULL;
skiplist_t *stay = NULL;

if (!list)
return (NULL);

pass = list;

while (pass->express)
{
printf("Value checked at index [%lu] = [%i]\n",
(pass->express)->index, (pass->express)->n);
if ((pass->express)->n >= value)
{
printf("Value found between indexes [%lu] and [%lu]\n",
pass->index, (pass->express)->index);
break;
}
if ((pass->express)->express == NULL)
{
pass = pass->express;
stay = pass;
while (stay->next)
stay = stay->next;
printf("Value found between indexes [%lu] and [%lu]\n",
pass->index, stay->index);
break;
}
pass = pass->express;
}

while (pass->next)
{
printf("Value checked at index [%lu] = [%i]\n",
pass->index, pass->n);
if (pass->n == value)
return (pass);
if (pass->n > value)
return (NULL);
pass = pass->next;
}

printf("Value checked at index [%lu] = [%i]\n", pass->index, pass->n);
return (NULL);
}
