/* UI_MessageBoxf: format and show a single-button message box. */
extern "C" int __cdecl CRT_Vsprintf(char *buffer, char *format, void *args);
extern "C" int __cdecl UI_ShowChoiceMessageBox(void *window, char *text, int count,
                                               int id);

int __cdecl UI_MessageBoxf(void *window, char *format, ...)
{
    char buffer[0x200];

    CRT_Vsprintf(buffer, format, &format + 1);
    return UI_ShowChoiceMessageBox(window, buffer, 1,
                                   *(int *)((char *)window + 0x2b0)) != -1;
}
