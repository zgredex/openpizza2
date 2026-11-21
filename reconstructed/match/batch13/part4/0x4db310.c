/* Parse_ReadIntToken (0x4db310). */
extern "C" void String_SkipDelimiters(char *text, int *position);
extern "C" int CRT_AtoiThunk(char *text);

extern "C" int __cdecl Parse_ReadIntToken(char *text, int *position)
{
    char current;
    int negative;
    int index;
    int value;

    String_SkipDelimiters(text, position);
    current = text[*position];
    negative = (current == '-') ? 1 : 0;
    if (current == '-' || current == '+') {
        *position = *position + 1;
    }
    String_SkipDelimiters(text, position);
    index = *position;
    value = CRT_AtoiThunk(text + index);
    while (text[index] >= '0' && text[index] <= '9') {
        index = index + 1;
    }
    *position = index + 1;
    if (negative != 0) {
        value = -value;
    }
    return value;
}
