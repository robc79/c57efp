#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t getInput(char *, int);

int main()
{
    const int bufSize = 100;
    // Initialise a buffer to hold user input string.
    char buf[bufSize];
    memset(buf, '\0', bufSize);
    size_t size = getInput(&buf[0], bufSize);

    while (size == 0)
    {
        size = getInput(&buf[0], bufSize);
    }

    printf("%s has %Iu characters.", buf, size);

    return 0;
}

size_t getInput(char *buf, int bufSize)
{
    // Prompt for input.
    printf("What is the input string? ");
    fgets(buf, bufSize-1, stdin);
    size_t rawSize = strlen(buf);
    size_t size = rawSize - 1;
    buf[size] = '\0';

    return size;
}
