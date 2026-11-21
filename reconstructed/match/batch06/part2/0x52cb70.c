/* Text_SkipFieldSeparators: advances past field separators (0x52cb70). */
void __stdcall Text_SkipFieldSeparators(char *text, int *index)
{
    while (1) {
        char value = text[*index];

        if (value == '}' || value == '\0' || (value > ' ' && value != ',')) {
            break;
        }
        (*index)++;
    }
}
