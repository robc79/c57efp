#include <stdlib.h>
#include <string.h>
#include "strbuf.h"

const size_t INIT_CAPACITY = 64;

StringBuffer *strbuf_make()
{
    StringBuffer * sb = (StringBuffer *)malloc(sizeof(StringBuffer));
    sb->length = (size_t)0;
    sb->capacity = INIT_CAPACITY;
    sb->text = (char *)calloc(INIT_CAPACITY, sizeof(char));
    sb->text[0] = '\0';

    return sb;
}

StringBuffer *strbuf_make_cap(size_t capacity)
{
    StringBuffer * sb = (StringBuffer *)malloc(sizeof(StringBuffer));
    sb->length = (size_t)0;
    sb->capacity = capacity;
    sb->text = (char *)calloc(capacity, sizeof(char));
    sb->text[0] = '\0';

    return sb;
}

StringBuffer *strbuf_make_from(const char *str)
{
    int len = 0;
    char c;
    const char *cptr = str;

    while ((c = *cptr++) != '\0')
    {
        len++;
    }

    StringBuffer * sb = (StringBuffer *)malloc(sizeof(StringBuffer));
    sb->length = len;
    sb->capacity = len + 1;
    sb->text = (char *)calloc(sb->capacity, sizeof(char));
    strcpy(sb->text, str);

    return sb;
}

void strbuf_clear(StringBuffer *sb)
{
    free(sb->text);
    sb->length = (size_t)0;
    sb->capacity = INIT_CAPACITY;
    sb->text = (char *)calloc(INIT_CAPACITY, sizeof(char));
    sb->text[0] = '\0';
}
