#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
* is_palindrome - checks if a singly linked list is a palindrome
* @head: pointer to head of linked list
* empty list is considered a palindrome
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int is_palindrome(listint_t **head)
{
if (!*head)
	return (1);
	return (suckerfree(head, *head));
}


/**
* suckerfree - helper function to check if list is palindrome
* @left: start of list
* @right: end of list
* empty list is considered a palindrome
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int suckerfree(listint_t **left, listint_t *right)
{
if (!right)
	return (1);
if (suckerfree(left, right->next) && (*left)->n == right->n)
{
	*left = (*left)->next;
	return (1);
}
else
	return (0);
}
