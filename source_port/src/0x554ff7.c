// CRT_HeapCreateRegion: ported from Pizza Connection 2 at 0x554ff7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x554ff7
#include "pc2_port.h"

int __cdecl CRT_HeapCreateRegion(int arg1)

{
  int *ptr1;
  char cVar2;
  int value3;
  int value4;
  int value5;
  LPVOID pvVar6;
  int *ptr7;
  int value8;
  int value9;
  int *lpAddress;
  
  value3 = *(int *)(arg1 + 0x10);
  value9 = 0;
  for (value4 = *(int *)(arg1 + 8); -1 < value4; value4 = value4 << 1) {
    value9 = value9 + 1;
  }
  value8 = 0x3f;
  value4 = value9 * 0x204 + 0x144 + value3;
  value5 = value4;
  do {
    *(int *)(value5 + 8) = value5;
    *(int *)(value5 + 4) = value5;
    value5 = value5 + 8;
    value8 = value8 + -1;
  } while (value8 != 0);
  lpAddress = (int *)(value9 * 0x8000 + *(int *)(arg1 + 0xc));
  pvVar6 = VirtualAlloc(lpAddress,0x8000,0x1000,4);
  if (pvVar6 == (LPVOID)0x0) {
    value9 = -1;
  }
  else {
    if (lpAddress <= lpAddress + 0x1c00) {
      ptr7 = lpAddress + 4;
      do {
        ptr7[-2] = -1;
        ptr7[0x3fb] = -1;
        ptr7[-1] = 0xff0;
        *ptr7 = (intptr_t)(ptr7 + 0x3ff);
        ptr7[1] = (intptr_t)(ptr7 + -0x401);
        ptr7[0x3fa] = 0xff0;
        ptr1 = ptr7 + 0x3fc;
        ptr7 = ptr7 + 0x400;
      } while (ptr1 <= lpAddress + 0x1c00);
    }
    *(int **)(value4 + 0x1fc) = lpAddress + 3;
    lpAddress[5] = value4 + 0x1f8;
    *(int **)(value4 + 0x200) = lpAddress + 0x1c03;
    lpAddress[0x1c04] = value4 + 0x1f8;
    *(uint32_t *)(value3 + 0x44 + value9 * 4) = 0;
    *(uint32_t *)(value3 + 0xc4 + value9 * 4) = 1;
    cVar2 = *(char *)(value3 + 0x43);
    *(char *)(value3 + 0x43) = cVar2 + '\x01';
    if (cVar2 == '\0') {
      *(uint32_t *)(arg1 + 4) = *(uint32_t *)(arg1 + 4) | 1;
    }
    *(uint32_t *)(arg1 + 8) = *(uint32_t *)(arg1 + 8) & ~(0x80000000U >> ((uint8_t)value9 & 0x1f));
  }
  return value9;
}
