// PORT_STATUS: STUB
// Temporary Win32/CRT shims so the readable source port can link as a PE.
// These are not recovered functions and must not be counted as such.
#include "pc2_port.h"

void __stdcall EnterCriticalSection(void *) {}
void __stdcall LeaveCriticalSection(void *) {}
void __stdcall DeleteCriticalSection(void *) {}
void __stdcall InitializeCriticalSection(void *) {}
DWORD __stdcall GetCurrentThreadId(void) { return 0; }
DWORD __stdcall GetTickCount(void) { return 0; }
void __stdcall Sleep(DWORD) {}
int CRT_Atexit(intptr_t) { return 0; }
void *CRT_GetThreadData(void *, int) { return 0; }
LONG RegCloseKey(HKEY) { return 0; }
void CRT_Ostream_Write() {}
void CRT_Istream_Read() {}
void CRT_DoExit() {}
int SetRect(LPRECT, int, int, int, int) { return 1; }
int ShowWindow(void *, int) { return 1; }
int MoveWindow(void *, int, int, int, int, int) { return 1; }
int GetWindowRect(void *, LPRECT) { return 1; }

/* Minimal freestanding CRT helpers; PORT_STATUS: STUB (link scaffolding). */
void __main(void) {}
void *memset(void *destination, int value, size_t count)
{
    unsigned char *bytes = (unsigned char *)destination;
    for (size_t i = 0; i < count; i++) {
        bytes[i] = (unsigned char)value;
    }
    return destination;
}
void *memcpy(void *destination, const void *source, size_t count)
{
    unsigned char *dst = (unsigned char *)destination;
    const unsigned char *src = (const unsigned char *)source;
    for (size_t i = 0; i < count; i++) {
        dst[i] = src[i];
    }
    return destination;
}
