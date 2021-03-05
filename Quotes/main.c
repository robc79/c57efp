#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char quote[1000];
    char attribution[100];

    printf("What is the quote? ");
    fgets(quote, 999, stdin);
    size_t quoteSize = strlen(quote);
    quote[quoteSize-1] = '\0';

    printf("Who said it? ");
    fgets(attribution, 99, stdin);
    size_t attributionSize = strlen(attribution);
    attribution[attributionSize-1] = '\0';

    printf("%s said \"%s\"", attribution, quote);

    return 0;
}
