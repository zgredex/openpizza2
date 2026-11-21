/* UI_Briefing_Printf (0x48bf90). */
struct UI {
    char pad00[0x304];
};
extern "C" int CRT_Vsprintf(char *buffer, const char *format, void *args);
extern "C" void UI_Briefing_AddMessage(void *ui, int a2, int a3, int a4,
                                       int a5, int a6, int a7, char *text);

extern "C" void __cdecl UI_Briefing_Printf(struct UI *ui, int a2, int a3,
                                           int a4, int a5, int a6, int a7,
                                           char *format, ...)
{
    char buffer[1024];

    CRT_Vsprintf(buffer, format, &format + 1);
    UI_Briefing_AddMessage((char *)ui + 0x304, a2, a3, a4, a5, a6, a7,
                           buffer);
}
