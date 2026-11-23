// Filename_ToUpperStripExt @ 0x4e6420 (150 bytes)
// Uppercases a filename and replaces its extension with the fixed one.

extern "C" char *strcpy(char *dest, const char *source);
extern "C" char *strchr(const char *text, int ch);
extern "C" char *strupr(char *text);
#pragma intrinsic(strcpy)
#pragma intrinsic(strchr)

extern char DAT_0057ca0c[];

namespace CRT {
    char *Strupr(char *text);
}

void __cdecl Filename_ToUpperStripExt(char *name)
{
    char buffer[100];
    char *dot;

    strcpy(buffer, name);
    CRT::Strupr(buffer);
    dot = strchr(buffer, '.');
    if (dot != 0)
        strcpy(dot, DAT_0057ca0c);
    strcpy(name, buffer);
}
