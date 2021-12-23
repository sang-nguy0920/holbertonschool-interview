#include "holberton.h"

/**
 * main - main function
 * @argc: args
 * @argv: args
 * Return: Success
 */
int main(int argc, char **argv)
{
int lenArg1, lenArg2, leftover, x, y, arg1Num, arg2Num;
int *answer;

numCheck(argc, argv);
lenArg1 = newStrlen(argv[1]);
lenArg2 = newStrlen(argv[2]);

answer = newCalloc((lenArg1 + lenArg2), sizeof(*answer));

if (answer == NULL)
return (EXIT_FAILURE);

for (x = lenArg1 - 1; x >= 0; x--)
{
leftover = 0;
arg1Num = argv[1][x] - '0';

for (y = lenArg2 - 1; y >= 0; y--)
{
arg2Num = argv[2][y] - '0';
leftover += answer[x + y + 1] + (arg1Num * arg2Num);
answer[x + y + 1] = leftover % 10;
leftover /= 10;
}

if (leftover > 0)
answer[x + y + 1] += leftover;
}

arg1Num = answer[0] == 0 ? 1 : 0;
for (; arg1Num < lenArg1 + lenArg2; arg1Num++)
{
if (answer[arg1Num] == 0 && arg1Num + 1 != lenArg1 + lenArg2)
continue;
_putchar(answer[arg1Num] + '0');
}
_putchar('\n');

free(answer);
return (EXIT_SUCCESS);
}


/**
 * numCheck - checks args
 *
 * @argc: args
 * @argv: args
 * Return: 0
 */
void numCheck(int argc, char **argv)
{
int x, y;

if (argc != 3)
{
newPrintF("Error");
exit(98);
}

for (x = 1; x < argc; x++)
{
for (y = 0; argv[x][y]; y++)
{
if (argv[x][y] < '0' || argv[x][y] > '9')
{
newPrintF("Error");
exit(98);
}
}
}
}


/**
 * newCalloc - new helper function
 * @length: Length
 * @charSize: size
 * Return: void
 */
void *newCalloc(size_t length, size_t charSize)
{
char *memChunk;
size_t x;

memChunk = malloc(length * charSize);

if (memChunk == NULL)
return (NULL);

while (x < (length * charSize))
{
memChunk[x] = 0;
x++;
}

return ((void *)memChunk);
}


/**
 * newStrlen - new strlen
 * @string: string
 * Return: length
 */
size_t newStrlen(char *string)
{
size_t stringLength = 0;

while (string[stringLength])
stringLength++;

return (stringLength);
}


/**
 * newPrintF - new printf
 * @string: String
 *
 *  Return: void
 */
void newPrintF(char *string)
{
size_t charCount, x;

charCount = newStrlen(string);

for (x = 0; x < charCount; x++)
_putchar(string[x]);

_putchar('\n');
}
