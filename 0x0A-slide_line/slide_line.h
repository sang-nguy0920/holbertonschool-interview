#ifndef SLIDE
#define SLIDE

#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT -1
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
int slide_left(int *line, size_t size);
int slide_right(int *line, size_t size);

#endif
