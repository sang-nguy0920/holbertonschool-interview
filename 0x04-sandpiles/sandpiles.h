#ifndef _SANGPILES_H_
#define _SANGPILES_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void add_grids(int grid1[3][3], int grid2[3][3]);
int checker(int grid1[3][3]);
static void print_grid(int grid[3][3]);
void switcher(int grid1[3][3]);

#endif /* _SANGPILES_H_ */
