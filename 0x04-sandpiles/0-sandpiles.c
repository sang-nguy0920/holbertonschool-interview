#include "sandpiles.h"

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 *
 * @grid1: sangpile1
 * @grid2: sangpile2
 *
 * Return: stable grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

add_grids(grid1, grid2);

while (!checker(grid1))
{
print_grid(grid1);
switcher(grid1);
}
}


/**
 * add_grids - adds two grids together
 *
 * @grid1: sangpile1
 * @grid2: sangpile2
 *
 * Return: void
 */
void add_grids(int grid1[3][3], int grid2[3][3])
{
int i;
int j;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
grid1[i][j] += grid2[i][j];
}
}
}


/**
 * checker - checks grid1
 *
 * @grid1: sangpile1
 *
 * Return: 0 if > 3
 */
int checker(int grid1[3][3])
{

int i = 0;
int j = 0;

for (i = 0; i < 3; i++)
for (j = 0; j < 3; j++)
if (grid1[i][j] > 3)
{
return (0);
}
return (1);
}


/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
int i, j;
printf("=\n");

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (j)
printf(" ");
printf("%d", grid[i][j]);
}
printf("\n");
}
}

/**
 * switcher - switches grids
 *
 * @grid1: sangpile1
 *
 * Return: void
 */
void switcher(int grid1[3][3])
{
int i, j;
int grid3[3][3];

for (i = 0; i < 3; i++)
for (j = 0; j < 3; j++)
grid3[i][j] = 0;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (grid1[i][j] > 3)
{
grid1[i][j] = grid1[i][j] - 4;
if ((i - 1 >= 0) && (i - 1 < 3))
grid3[i - 1][j] += 1;
if ((j - 1 >= 0) && (j - 1 < 3))
grid3[i][j - 1] += 1;
if ((i + 1 >= 0) && (i + 1 < 3))
grid3[i + 1][j] += 1;
if ((j + 1 >= 0) && (j + 1 < 3))
grid3[i][j + 1] += 1;
}
}
}
add_grids(grid1, grid3);
}
