#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list.
 * @head: head
 * Return: addy
 */

listint_t *find_listint_loop(listint_t *head)
{
listint_t *slow = head, *fast = head;

while (slow && fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;

if (fast == head || slow == head)
return (head);

if (slow == fast)
{
head = head->next;
fast = head;
slow = head;
}
}
return (NULL);
}
