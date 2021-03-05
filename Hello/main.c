#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buf[100];
    printf("What is your name? ");
    scanf("%99s", buf);
    printf("Hello, %s, nice to meet you!", buf);

    return 0;
}
