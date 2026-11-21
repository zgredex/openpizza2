/* Dialog_ParseInteger: parses a decimal integer from a dialog template at
   the current cursor (0x52cba0). */
extern "C" int __cdecl CRT_AtoiThunk(char *text);

extern "C" int __stdcall Dialog_ParseInteger(char *text, int *position)
{
    int start = *position;
    int end;
    int value;

    if (text[start] == '}' || text[start] == 0)
        return -1;
    end = start;
    while (text[end] >= '0' && text[end] <= '9')
        end++;
    if (end == start)
        return -1;
    value = CRT_AtoiThunk(text + start);
    *position = end;
    return value;
}
