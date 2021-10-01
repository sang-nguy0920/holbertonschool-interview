#include "slide_line.h"

/**
 * slide_left - slide left
 *
 * @line: slide left
 * @size: size
 *
 * Return: 1 on success
 */

int slide_left(int *line, size_t size)
{
size_t right = 0;
size_t left = 0;
int stay = 0;

for (; right < size; right++)
{
if (line[right] == 0)
continue;
if (stay == 0)
stay = line[right];
else if (stay == line[right])
{
line[left] = stay + line[right];
stay = 0;
left++;
}
else
{
line[left] = stay;
stay = line[right];
left++;
}
}
if (stay)
{
line[left] = stay;
left++;
}
for (; left < right; left++)
line[left] = 0;
return (1);
}

/**
 * slide_right - slide right
 *
 * @line: slide right
 * @size: size
 *
 * Return: 1 on success
 */

int slide_right(int *line, size_t size)
{
size_t right = size;
size_t left = size;
int stay = 0;

for (; left > 0; left--)
{
if (line[left - 1] == 0)
continue;
if (stay == 0)
stay = line[left - 1];
else if (stay == line[left - 1])
{
line[right - 1] = stay + line[left - 1];
stay = 0;
right--;
}
else
{
line[right - 1] = stay;
stay = line[left - 1];
right--;
}
}
if (stay)
{
line[right - 1] = stay;
right--;
}
for (; left < right; right--)
line[right - 1] = 0;
return (1);
}

/**
 * slide_line - slides line
 *
 * @line: int to slide
 * @size: size
 * @direction: direction to slide
 *
 * Return: 1 upon success
 */

int slide_line(int *line, size_t size, int direction)
{
int output = 0;

if (direction == -1)
output = slide_left(line, size);
else if (direction == 1)
output = slide_right(line, size);
return (output);
}
