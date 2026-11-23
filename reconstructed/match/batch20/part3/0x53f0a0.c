extern "C" char *strcpy(char *, const char *);
extern "C" char *strcat(char *, const char *);
extern "C" size_t strlen(const char *);
#pragma intrinsic(strcpy)
#pragma intrinsic(strcat)
#pragma intrinsic(strlen)

extern "C" char DAT_00574c10[];

extern "C" char *Sound_FormatErrorString(int code);
extern "C" int CRT_Vsprintf(char *buffer, const char *format, void *args);
void *operator new(unsigned int size);
void operator delete(void *ptr);

void Sound_SetLastError(int *lastError, char *label, int code, ...)
{
    char message[1024];
    char text[1024];

    strcpy(message, Sound_FormatErrorString(code));
    strcat(message, DAT_00574c10);
    strcat(message, label);
    CRT_Vsprintf(text, message, &code + 1);
    if (*lastError != 0)
        operator delete((void *)*lastError);
    *lastError = (int)operator new(strlen(text) + 1);
    if (*lastError != 0)
        strcpy((char *)*lastError, text);
}
