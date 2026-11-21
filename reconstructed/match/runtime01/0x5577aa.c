unsigned int CRT_Strnlen(const char *text, unsigned int limit)
{
    const char *cursor = text;
    unsigned int remaining = limit;
    while (remaining-- != 0 && *cursor != '\0')
        ++cursor;
    if (*cursor == '\0')
        return (unsigned int)(cursor - text);
    return limit;
}
