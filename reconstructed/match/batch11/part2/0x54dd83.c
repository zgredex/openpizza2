struct FILE { char *ptr; int cnt; char *base; int flag; int file; int charbuf; int bufsiz; char *tmpfname; };
extern "C" int __cdecl CRT_Output(FILE *state, char *format, ...);
extern "C" void __cdecl CRT_FlushStreamBuffer(int handle, FILE *state);
extern "C" int __cdecl String_Format(char *buffer, char *format, int value)
{
    FILE strfile;
    int result;
    strfile.base = buffer;
    strfile.ptr = buffer;
    strfile.flag = 0x42;
    strfile.cnt = 0x7fffffff;
    result = CRT_Output(&strfile, format, &value);
    if (--strfile.cnt >= 0)
        *strfile.ptr = 0;
    else
        CRT_FlushStreamBuffer(0, &strfile);
    return result;
}
