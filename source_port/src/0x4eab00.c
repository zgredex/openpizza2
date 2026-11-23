// World_LoadNameIndexTable: ported from Pizza Connection 2 at 0x4eab00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eab00
#include "pc2_port.h"

void __thiscall World_LoadNameIndexTable(void *self,void *arg1)

{
  int value1;
  int value2;
  uint16_t *uptr3;
  uint8_t local_64 [100];
  
  value2 = 0x9c4;
  uptr3 = (uint16_t *)((intptr_t)self + 0x2e4f4);
  do {
    CRT_Istream_Read(arg1,local_64,0x32);
    value1 = Map_FindNameIndex(self,local_64);
    if (value1 != -1) {
      *uptr3 = (short)value1;
    }
    uptr3 = uptr3 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  return;
}
