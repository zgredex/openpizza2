#ifndef PC2_PORT_H
#define PC2_PORT_H

/*
 * Shared types for the readable source port.
 *
 * These are ABI-width aliases, not a claim that every recovered function has
 * been behaviorally verified. The original titles are MSVC 6 / PE32, so the
 * port is compiled as 32-bit Windows code with the original calling
 * conventions where clang supports them.
 */

typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
typedef unsigned int uint32_t;
typedef signed int int32_t;
typedef unsigned long long uint64_t;
typedef signed long long int64_t;
typedef unsigned int uintptr_t;
typedef signed int intptr_t;
typedef unsigned int size_t;

/* Ghidra spelling used by the exported pseudocode. */
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned long long undefined8;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef unsigned char byte;
typedef signed char sbyte;
typedef double float10;
typedef intptr_t (*code)();
typedef uint32_t int3;
typedef uint32_t uint3;

/*
 * Recovered shared engine shapes. The bulk-port batch uses raw offsets from
 * the pseudocode; these declarations are the common vocabulary for the
 * hand-written, well-understood subsystems that follow.
 */
#ifdef __cplusplus
struct IDMap {
    void *Lookup(int index, int *out);
};

struct Game {
    void *GetPlayerBySlot(int slot);
};
#else
typedef int bool;
#define true 1
#define false 0
#endif

#ifdef __cplusplus
#define PC2_EXTERN_C extern "C"
#else
#define PC2_EXTERN_C extern
#endif


/* Win32 vocabulary used by the exported pseudocode. */
typedef unsigned int DWORD;
typedef int LONG;
typedef unsigned int UINT;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef int BOOL;
typedef void *LPVOID;
typedef void *PVOID;
typedef struct _EXCEPTION_RECORD {
    uint32_t ExceptionCode;
    uint32_t ExceptionFlags;
    struct _EXCEPTION_RECORD *ExceptionRecord;
    void *ExceptionAddress;
    uint32_t NumberParameters;
    uintptr_t ExceptionInformation[15];
} EXCEPTION_RECORD, *PEXCEPTION_RECORD;
typedef void *LPOPENFILENAMEA;
typedef void *LPSECURITY_ATTRIBUTES;
typedef char CHAR;
typedef unsigned short WCHAR;
typedef unsigned char *LPBYTE;
typedef void *HCURSOR;
typedef void *HBRUSH;
typedef void *HPEN;
typedef void *HFONT;
typedef void *HMONITOR;
typedef void *HGDIOBJ;
typedef unsigned int *LPDWORD;
typedef unsigned short *LPWORD;
typedef uintptr_t SIZE_T;
typedef uintptr_t ULONG_PTR;
typedef uintptr_t DWORD_PTR;
typedef intptr_t INT_PTR;
typedef short SHORT;
typedef unsigned short USHORT;
typedef unsigned short ATOM;
typedef unsigned short LANGID;
typedef intptr_t (*FARPROC)();
typedef intptr_t LPARAM;
typedef uint32_t WPARAM;
typedef intptr_t LRESULT;
typedef struct _FILE {
    unsigned char *_ptr;
    int _cnt;
    unsigned char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    unsigned char *_tmpfname;
} FILE;
typedef struct tagRECT tagRECT;
typedef union _LARGE_INTEGER {
    struct { uint32_t LowPart; int32_t HighPart; };
    struct { uint32_t LowPart; int32_t HighPart; } s;
    int64_t QuadPart;
} LARGE_INTEGER;
typedef const char *LPCSTR;
typedef char *LPSTR;
typedef const unsigned short *LPCWSTR;
typedef unsigned short *LPWSTR;
typedef void *HWND;
typedef void *HINSTANCE;
typedef void *HMODULE;
typedef void *HANDLE;
typedef void *HDC;
typedef void *HBITMAP;
typedef void *HICON;
typedef void *HMENU;
typedef void *HKEY;
typedef void *LPCRITICAL_SECTION;
typedef int HRESULT;
typedef unsigned int UINT_PTR;
typedef unsigned int COLORREF;
typedef unsigned int *PDWORD;
typedef int *PLONG;
typedef struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT, *LPRECT;
typedef LONG LSTATUS;
typedef struct POINT {
    LONG x;
    LONG y;
} POINT, *LPPOINT;

static inline intptr_t pc2_bits(double value)
{
    union { double d; intptr_t i[2]; } u;
    u.d = value;
    return u.i[0];
}

#ifdef __cplusplus
extern "C" {
#endif
void __stdcall EnterCriticalSection();
void __stdcall LeaveCriticalSection();
void __stdcall DeleteCriticalSection();
void __stdcall InitializeCriticalSection();
DWORD __stdcall GetCurrentThreadId();
DWORD __stdcall GetTickCount();
void __stdcall Sleep();
int CRT_Atexit();
void *CRT_GetThreadData();
LONG RegCloseKey();
void CRT_Ostream_Write();
void CRT_Istream_Read();
void CRT_DoExit();
int SetRect();
int ShowWindow();
int MoveWindow();
int GetWindowRect();
#ifdef __cplusplus
}
#endif


extern void *ExceptionList;

/* Ghidra helper macros, compile-only approximations. */
#define CONCAT11(a,b) ((uint16_t)(((uint16_t)(uint8_t)(a) << 8) | (uint8_t)(b)))
#define CONCAT12(a,b) ((uint32_t)(((uint32_t)(uint8_t)(a) << 16) | (uint16_t)(b)))
#define CONCAT13(a,b) ((uint32_t)(((uint32_t)(uint8_t)(a) << 24) | ((uint32_t)(b) & 0xffffff)))
#define CONCAT14(a,b) ((uint64_t)(((uint64_t)(uint8_t)(a) << 32) | (uint32_t)(b)))
#define CONCAT21(a,b) ((uint32_t)(((uint32_t)(uint16_t)(a) << 8) | (uint8_t)(b)))
#define CONCAT22(a,b) ((uint32_t)(((uint32_t)(uint16_t)(a) << 16) | (uint16_t)(b)))
#define CONCAT24(a,b) ((uint64_t)(((uint64_t)(uint16_t)(a) << 32) | (uint32_t)(b)))
#define CONCAT31(a,b) ((uint32_t)(((uint32_t)(a) << 8) | (uint8_t)(b)))
#define CONCAT44(a,b) ((uint64_t)(((uint64_t)(a) << 32) | (uint32_t)(b)))
#define SUB41(a,b) ((uint8_t)((uint32_t)(a) - (uint32_t)(b)))
#define SUB42(a,b) ((uint16_t)((uint32_t)(a) - (uint32_t)(b)))
#define SUB44(a,b) ((uint32_t)((uint32_t)(a) - (uint32_t)(b)))
#define SUB84(a,b) ((uint64_t)((uint64_t)(a) - (uint32_t)(b)))

#include "pc2_generated_symbols.h"

#endif /* PC2_PORT_H */
