// CRT_SmallBlockNewRegion: ported from Pizza Connection 2 at 0x554f46.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x554f46
#include "pc2_port.h"

uint32_t * CRT_SmallBlockNewRegion(void)

{
  uint32_t *uptr1;
  LPVOID pvVar2;
  
  if (DAT_00585bd8 == DAT_00585bc8) {
    pvVar2 = HeapReAlloc(DAT_00585be0,0,DAT_00585bdc,(DAT_00585bc8 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (uint32_t *)0x0;
    }
    DAT_00585bc8 = DAT_00585bc8 + 0x10;
    DAT_00585bdc = pvVar2;
  }
  uptr1 = (uint32_t *)((intptr_t)DAT_00585bdc + DAT_00585bd8 * 0x14);
  pvVar2 = HeapAlloc(DAT_00585be0,8,0x41c4);
  uptr1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    uptr1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      uptr1[2] = 0xffffffff;
      *uptr1 = 0;
      uptr1[1] = 0;
      DAT_00585bd8 = DAT_00585bd8 + 1;
      *(uint32_t *)uptr1[4] = 0xffffffff;
      return uptr1;
    }
    HeapFree(DAT_00585be0,0,(LPVOID)uptr1[4]);
  }
  return (uint32_t *)0x0;
}
