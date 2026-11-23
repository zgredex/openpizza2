// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x556995.c:28:31: error: called object type 'intptr_t' (aka 'int') is not a function or function pointer
// FUN_00556995: ported from Pizza Connection 2 at 0x556995.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x556995
#include "pc2_port.h"

int __cdecl FUN_00556995(uint32_t arg1,uint32_t arg2,uint32_t arg3)

{
  HMODULE hModule;
  int value1;
  
  value1 = 0;
  if (DAT_00585970 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_00585970 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_00585970 != (FARPROC)0x0) {
        DAT_00585974 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_00585978 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_005569e4;
      }
    }
    value1 = 0;
  }
  else {
LAB_005569e4:
    if (DAT_00585974 != (FARPROC)0x0) {
      value1 = (*DAT_00585974)();
      if ((value1 != 0) && (DAT_00585978 != (FARPROC)0x0)) {
        value1 = (*DAT_00585978)(value1);
      }
    }
    value1 = (*DAT_00585970)(value1,arg1,arg2,arg3);
  }
  return value1;
}
