// CRT_Mbtowc: ported from Pizza Connection 2 at 0x552b23.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552b23
#include "pc2_port.h"

uint32_t __thiscall CRT_Mbtowc(void *self,int arg1,uint32_t arg2)

{
  BOOL BVar1;
  int value2;
  uint32_t local_8;
  
  if (arg1 + 1U < 0x101) {
    arg1 = (arg1 & ~(0xffffu << 16)) | (((*(uint16_t *)(PTR_DAT_00576ae4 + arg1 * 2)) & 0xffffu) << 16);
  }
  else {
    if ((PTR_DAT_00576ae4[(arg1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      local_8 = CONCAT31((int3)((uint32_t)self >> 8),(char)arg1) & 0xffff00ff;
      value2 = 1;
    }
    else {
      local_8 = (local_8 & ~(0x0u << 16)) | (((CONCAT11((char)arg1,(char)((uint32_t)arg1 >> 8))) & 0x0u) << 16);
      local_8 = CONCAT22((short)((uint32_t)self >> 0x10),(uint16_t)local_8) & 0xff00ffff;
      value2 = 2;
    }
    BVar1 = FUN_00555dd9(1,(LPCSTR)&local_8,value2,(LPWORD)((intptr_t)&arg1 + 2),0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return ((uint16_t)((arg1) >> 16)) & arg2;
}
