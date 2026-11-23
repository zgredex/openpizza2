// CRT_Tolower_L: ported from Pizza Connection 2 at 0x54f918.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f918
#include "pc2_port.h"

uint32_t __thiscall CRT_Tolower_L(void *self,uint32_t arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  int value3;
  void *local_8;
  
  uvalue1 = arg1;
  if (DAT_005857cc == 0) {
    if ((intptr_t)arg1 < 0x41) {
      return arg1;
    }
    if ((intptr_t)arg1 < 0x5b) {
      return arg1 + 0x20;
    }
    return arg1;
  }
  value3 = 1;
  local_8 = self;
  if ((intptr_t)arg1 < 0x100) {
    if (DAT_00576cf0 < 2) {
      uvalue2 = (uint8_t)PTR_DAT_00576ae4[arg1 * 2] & 1;
    }
    else {
      uvalue2 = CRT_Mbtowc(self,arg1,1);
    }
    if (uvalue2 == 0) {
      return uvalue1;
    }
  }
  if ((PTR_DAT_00576ae4[((intptr_t)uvalue1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
    arg1 = CONCAT31((int3)(arg1 >> 8),(char)uvalue1) & 0xffff00ff;
  }
  else {
    uvalue2 = arg1 >> 0x10;
    arg1 = (arg1 & ~(0x0u << 16)) | (((CONCAT11((char)uvalue1,(char)(uvalue1 >> 8))) & 0x0u) << 16);
    arg1 = CONCAT22((short)uvalue2,(uint16_t)arg1) & 0xff00ffff;
    value3 = 2;
  }
  value3 = CRT_LCMapStringA(DAT_005857cc,0x100,(char *)&arg1,value3,(LPWSTR)&local_8,3,0,1);
  if (value3 == 0) {
    return uvalue1;
  }
  if (value3 == 1) {
    return (uint32_t)local_8 & 0xff;
  }
  return (uint32_t)local_8 & 0xffff;
}
