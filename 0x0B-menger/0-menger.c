#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 *
 * @level: level of the Menger Sponge to draw
 *
 *
 * Return: void
 */
void menger(int level)
{
int size, x, y, dx, dy, res;

size = (int)pow(3, level);
for (y = 0; y < size; y++)
{
for (x = 0; x < size; x++)
{
dx = x;
dy = y;
res = 0;

while (dx && dy)
{
if (dx % 3 == 1 && dy % 3 == 1)
{
printf(" ");
res = 1;
break;
}

dx = dx / 3;
dy = dy / 3;
}
if (!res)
printf("#");
}
printf("\n");
}
}
