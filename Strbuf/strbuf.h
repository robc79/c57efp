#ifndef STRBUF_H_INCLUDED
#define STRBUF_H_INCLUDED

typedef struct
{
    char *text;
    size_t length;
    size_t capacity;
} StringBuffer;

// Make a string buffer of default capacity and length zero.
StringBuffer *strbuf_make();

// Make a string buffer with starting capacity and length zero.
StringBuffer *strbuf_make_cap(size_t capacity);

// Make a string buffer containing string str.
StringBuffer *strbuf_make_from(const char *str);

// Clear content of string buffer and reset the length to zero.
void strbuf_clear(StringBuffer *sb);

// Append a single character to the end of the string buffer.
void strbuf_append_char(StringBuffer *sb, char c);

// Append a string to the end of the string buffer.
void strbuf_append_str(StringBuffer *sb, const char *str);

#endif // STRBUF_H_INCLUDED
