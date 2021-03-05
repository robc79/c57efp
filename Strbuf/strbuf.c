#include <stdlib.h>
#include <string.h>
#include "strbuf.h"

const size_t INIT_CAPACITY = 32;

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

void strbuf_append_char(StringBuffer *sb, char c)
{
    if (sb->length + 2 > sb->capacity)
    {
        int nCapacity = sb->capacity * 2;
        char *ntext = (char *)realloc(sb->text, nCapacity);

        if (ntext == NULL)
        {
            exit(EXIT_FAILURE);
        }

        sb->text = ntext;
        sb->capacity = nCapacity;
    }

    sb->text[sb->length] = c;
    sb->text[sb->length + 1] = '\0';
    sb->length++;
}

void strbuf_append_str(StringBuffer *sb, const char *str)
{
    int len = 0;
    char c;
    const char *cptr = str;

    while ((c = *cptr++) != '\0')
    {
        len++;
    }

    int requiredLength = sb->length + len + 1;

    if (requiredLength > sb->capacity)
    {
        int nCapacity = sb->capacity * 2;

        while (requiredLength > nCapacity)
        {
            nCapacity *= 2;
        }

        char *ntext = (char *)realloc(sb->text, nCapacity);

        if (ntext == NULL)
        {
            exit(EXIT_FAILURE);
        }

        sb->text = ntext;
        sb->capacity = nCapacity;
    }

    sb->text = strcat(sb->text, str);
    sb->length = requiredLength - 1;
}
