#include "palindrome.h"


/**
 * is_palindrome - checks a given unsigned integer is a palindrome.
 *
 * @n: number to be checked
 *
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
unsigned long d = 10;
unsigned long x = 0;
unsigned long y = 0;

while (n / d >= 10)
d = d * 10;
while (n > 9)
{
x = (n / d);
y = (n % 10);
if (x != y)
{
return (0);
}
n = (n % d) / 10;
d = d / 100;
}
return (1);
}
