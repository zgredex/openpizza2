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
typedef code LPOFNHOOKPROC;
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
typedef uint32_t LCID;
typedef const void *LPCVOID;
typedef int *LPBOOL;
typedef unsigned short *LPWCH;
typedef char *LPCH;
typedef void *HRSRC;
typedef struct tagPOINT {
    LONG x;
    LONG y;
} tagPOINT;
typedef struct _MEMORYSTATUS {
    uint32_t dwLength;
    uint32_t dwMemoryLoad;
    uint32_t dwTotalPhys;
    uint32_t dwAvailPhys;
    uint32_t dwTotalPageFile;
    uint32_t dwAvailPageFile;
    uint32_t dwTotalVirtual;
    uint32_t dwAvailVirtual;
} MEMORYSTATUS, _MEMORYSTATUS;
typedef struct _SYSTEMTIME {
    uint16_t wYear;
    uint16_t wMonth;
    uint16_t wDayOfWeek;
    uint16_t wDay;
    uint16_t wHour;
    uint16_t wMinute;
    uint16_t wSecond;
    uint16_t wMilliseconds;
} SYSTEMTIME, _SYSTEMTIME;
typedef struct _WIN32_FIND_DATAA {
    uint32_t dwFileAttributes;
    uint32_t ftCreationTime[2];
    uint32_t ftLastAccessTime[2];
    uint32_t ftLastWriteTime[2];
    uint32_t nFileSizeHigh;
    uint32_t nFileSizeLow;
    uint32_t dwReserved0;
    uint32_t dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
} WIN32_FIND_DATAA, _WIN32_FIND_DATAA;
typedef struct _STARTUPINFOA {
    uint32_t cb;
    char *lpReserved;
    char *lpDesktop;
    char *lpTitle;
    uint32_t dwX;
    uint32_t dwY;
    uint32_t dwXSize;
    uint32_t dwYSize;
    uint32_t dwXCountChars;
    uint32_t dwYCountChars;
    uint32_t dwFillAttribute;
    uint32_t dwFlags;
    uint16_t wShowWindow;
    uint16_t cbReserved2;
    unsigned char *lpReserved2;
    void *hStdInput;
    void *hStdOutput;
    void *hStdError;
} STARTUPINFOA, _STARTUPINFOA;
typedef struct _OVERLAPPED {
    uintptr_t Internal;
    uintptr_t InternalHigh;
    uint32_t Offset;
    uint32_t OffsetHigh;
    void *hEvent;
} OVERLAPPED, _OVERLAPPED, *LPOVERLAPPED;
typedef struct _cpinfo {
    uint32_t MaxCharSize;
    unsigned char DefaultChar[2];
    unsigned char LeadByte[12];
} cpinfo, _cpinfo;
typedef struct tagWNDCLASSA {
    uint32_t style;
    intptr_t lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    void *hInstance;
    void *hIcon;
    void *hCursor;
    void *hbrBackground;
    const char *lpszMenuName;
    const char *lpszClassName;
} WNDCLASSA, *LPWNDCLASSA;
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
LONG RegCloseKey();
void CRT_DoExit();
int SetRect();
int ShowWindow();
int MoveWindow();
int GetWindowRect();
#ifdef __cplusplus
}
#endif


extern void *ExceptionList;
void NoOp_Stub();

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


typedef struct _FILETIME { uint32_t dwLowDateTime; uint32_t dwHighDateTime; } FILETIME, _FILETIME;
typedef struct _IID { uint32_t Data1; uint16_t Data2; uint16_t Data3; unsigned char Data4[8]; } IID;
typedef struct _EXCEPTION_POINTERS { PEXCEPTION_RECORD ExceptionRecord; void *ContextRecord; } EXCEPTION_POINTERS, _EXCEPTION_POINTERS;
typedef struct _TIME_ZONE_INFORMATION { int32_t Bias; uint16_t StandardName[32]; SYSTEMTIME StandardDate; int32_t StandardBias; uint16_t DaylightName[32]; SYSTEMTIME DaylightDate; int32_t DaylightBias; } TIME_ZONE_INFORMATION, *LPTIME_ZONE_INFORMATION;
typedef const uint16_t *PCNZWCH;
typedef const uint16_t *PCNZCH;
typedef int errno_t;
typedef void *HGLOBAL;
typedef WIN32_FIND_DATAA *LPWIN32_FIND_DATAA;
typedef struct tagOFNA { uint32_t lStructSize; void *hwndOwner; void *hInstance; const char *lpstrFilter; char *lpstrCustomFilter; uint32_t nMaxCustFilter; uint32_t nFilterIndex; char *lpstrFile; uint32_t nMaxFile; char *lpstrFileTitle; uint32_t nMaxFileTitle; const char *lpstrInitialDir; const char *lpstrTitle; uint32_t Flags; uint16_t nFileOffset; uint16_t nFileExtension; const char *lpstrDefExt; uintptr_t lCustData; intptr_t lpfnHook; const char *lpTemplateName; void *pvReserved; uint32_t dwReserved; uint32_t FlagsEx; } OPENFILENAMEA, tagOFNA;
typedef struct tagPAINTSTRUCT { void *hdc; int fErase; RECT rcPaint; int fRestore; int fIncUpdate; unsigned char rgbReserved[32]; } PAINTSTRUCT, tagPAINTSTRUCT;
typedef struct _LIST_ENTRY { struct _LIST_ENTRY *Flink; struct _LIST_ENTRY *Blink; } LIST_ENTRY, _LIST_ENTRY;
typedef struct tagMSG { void *hwnd; uint32_t message; uint32_t wParam; intptr_t lParam; uint32_t time; POINT pt; } MSG, tagMSG;
extern void *type_info_vftable;
int _strcmp();


typedef void *LPUNKNOWN;
typedef struct _CRITICAL_SECTION {
    intptr_t DebugInfo;
    intptr_t LockCount;
    intptr_t RecursionCount;
    intptr_t OwningThread;
    intptr_t LockSemaphore;
    intptr_t SpinCount;
} CRITICAL_SECTION, *LPCRITICAL_SECTION;
typedef struct _RTL_CRITICAL_SECTION_DEBUG {
    uint16_t Type;
    uint16_t CreatorBackTraceIndex;
    CRITICAL_SECTION *CriticalSection;
    LIST_ENTRY ProcessLocksList;
    uint32_t EntryCount;
    uint32_t ContentionCount;
    uint32_t Flags;
    uint16_t CreatorBackTraceIndexHigh;
    uint16_t SpareWORD;
} RTL_CRITICAL_SECTION_DEBUG, *PRTL_CRITICAL_SECTION_DEBUG;
struct pc2_hdc { intptr_t unused; };
void Window_DefaultProc(HWND, UINT, WPARAM, HCURSOR);
void __cdecl Game_WindowProc(int, uint32_t, int, uint32_t *);
void __cdecl PersonnelPlan_WindowProc(void *, int, uint32_t, int);
void __cdecl FurnitureMenu_WindowProc(void *, int, int);
void __cdecl SubMenu_Police_HandleControl(void *, int, int);
void __cdecl IngredientMenu_HandleInput(void *, int, int, uint32_t *);
void SaveGameMenu_DestroyList(void);
void SaveGameList_Destroy(void);
void SaveGame_DestroyList(void);
int __cfltcvt(double *, char *, size_t, int, int, int);
void __cdecl CRT_CatchBlockFrameHandler(PEXCEPTION_RECORD, PVOID, DWORD);
uint32_t CRT_ThreadStart(LPVOID);
void __cdecl __fassign(int, char *, char *);

void __cdecl CRT_ForceDecimalPoint(char *);

#endif /* PC2_PORT_H */
