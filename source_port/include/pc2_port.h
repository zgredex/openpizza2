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
typedef void code;

/*
 * Recovered shared engine shapes. The bulk-port batch uses raw offsets from
 * the pseudocode; these declarations are the common vocabulary for the
 * hand-written, well-understood subsystems that follow.
 */
struct IDMap {
    void *Lookup(int index, int *out);
};

struct Game {
    void *GetPlayerBySlot(int slot);
};

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

#ifdef __cplusplus
extern "C" {
#endif
void __stdcall EnterCriticalSection(void *section);
void __stdcall LeaveCriticalSection(void *section);
void __stdcall DeleteCriticalSection(void *section);
void __stdcall InitializeCriticalSection(void *section);
DWORD __stdcall GetCurrentThreadId(void);
DWORD __stdcall GetTickCount(void);
void __stdcall Sleep(DWORD milliseconds);
int CRT_Atexit(intptr_t function);
void *CRT_GetThreadData(void *module, int slot);
long __ftol(void);
void Mem_Free(void *block);
void *IDMap_Lookup(void *map, int index, int *out);
LONG RegCloseKey(HKEY key);
void Window_GadgetNotify_Text_SetText(void *window, int id, const char *text);
void Window_GadgetNotify(...);
void Game_CountFreeBuildingsByType(void *game, int type);
void CRT_Ostream_Write(...);
void CRT_Istream_Read(...);
void CRT_DoExit(...);
int SetRect(LPRECT rect, int left, int top, int right, int bottom);
int ShowWindow(void *window, int command);
int MoveWindow(void *window, int x, int y, int width, int height, int repaint);
int GetWindowRect(void *window, LPRECT rect);
void *Map_LookupLinear(...);
extern void *PTR_GamePlan_Delete_0055c688;
extern void *PTR_SpriteBase_Delete_0055c828;
#ifdef __cplusplus
}
#endif

#endif /* PC2_PORT_H */
