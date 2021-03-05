#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void fizzBuzz(int, char*);

int main()
{
    const size_t BUF_MAX = 128;
    char *buf = (char *)malloc(sizeof(char) * BUF_MAX);

    for (int i=1; i<100; i++)
    {
        memset(buf, '\0', BUF_MAX);
        fizzBuzz(i, buf);
        printf("%s ", buf);
    }

    free(buf);
    buf = NULL;

    return 0;
}

void fizzBuzz(int num, char *buf)
{
    bool isFizz = num % 3 == 0;
    bool isBuzz = num % 5 == 0;

    if (isFizz && isBuzz)
    {
        sprintf(buf, "%s", "FizzBuzz");
    }
    else if(isFizz)
    {
        sprintf(buf, "%s", "Fizz");
    }
    else if(isBuzz)
    {
        sprintf(buf, "%s", "Buzz");
    }
    else
    {
        sprintf(buf, "%d", num);
    }
}
