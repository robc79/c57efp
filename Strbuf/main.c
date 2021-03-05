#include <stdio.h>
#include <stdlib.h>
#include "strbuf.h"

int main(int argc, char* argv[])
{
    StringBuffer *buf = strbuf_make_from("Hello, world!");

    printf("Text: %s\n", buf->text);
    printf("Length: %lu\n", buf->length);
    printf("Capacity: %lu\n", buf->capacity);

    strbuf_clear(buf);

    printf("Text: %s\n", buf->text);
    printf("Length: %lu\n", buf->length);
    printf("Capacity: %lu\n", buf->capacity);

    free(buf);
    buf = NULL;

    return 0;
}
