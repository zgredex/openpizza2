/* DebugConsole_Errorf: formats and prints a debug console message
   (0x526f20). */
extern void *DAT_0057c1e0;

extern "C" int __cdecl CRT_Vsprintf(char *buffer, const char *format,
                                    void *args);
extern "C" void __cdecl DebugConsole_Printf(void *console, int level,
                                            char *text);

void __cdecl DebugConsole_Errorf(int level, int code, const char *format, ...)
{
    char text[2048];

    CRT_Vsprintf(text, format, (void *)(&format + 1));
    DebugConsole_Printf(DAT_0057c1e0, 0xff, text);
}
