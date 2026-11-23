// CRT_Filebuf_Sync: ported from Pizza Connection 2 at 0x54cfd6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cfd6
#include "pc2_port.h"

uint32_t __fastcall CRT_Filebuf_Sync(int arg1)

{
  uint8_t flag1;
  uint32_t uvalue2;
  DWORD DVar3;
  int value4;
  char *cptr5;
  DWORD DVar6;
  
  if (*(uint32_t *)(arg1 + 0x4c) == 0xffffffff) {
    return 0xffffffff;
  }
  if (*(int *)(arg1 + 8) == 0) {
    cptr5 = *(char **)(arg1 + 0x18);
    if (*(char **)(arg1 + 0x1c) < cptr5) {
      DVar6 = 0;
    }
    else {
      DVar6 = (intptr_t)*(char **)(arg1 + 0x1c) - (intptr_t)cptr5;
    }
    if ((DVar6 != 0) && (DVar3 = CRT_Write(*(uint32_t *)(arg1 + 0x4c),cptr5,DVar6), DVar3 != DVar6))
    {
      if (0 < (intptr_t)DVar3) {
        if (*(int *)(arg1 + 0x20) != 0) {
          *(int *)(arg1 + 0x1c) = *(int *)(arg1 + 0x1c) - DVar3;
        }
        _memmove(*(uint32_t **)(arg1 + 0x18),
                 (uint32_t *)(DVar3 + (intptr_t)*(uint32_t **)(arg1 + 0x18)),DVar6 - DVar3);
      }
      return 0xffffffff;
    }
    *(uint32_t *)(arg1 + 0x18) = 0;
    *(uint32_t *)(arg1 + 0x1c) = 0;
    *(uint32_t *)(arg1 + 0x20) = 0;
    value4 = Stream_GetAvailable(arg1);
    if (0 < value4) {
      uvalue2 = *(uint32_t *)(arg1 + 0x4c);
      flag1 = *(uint8_t *)((&DAT_00586c20)[(intptr_t)uvalue2 >> 5] + 4 + (uvalue2 & 0x1f) * 0x24);
      if ((flag1 & 0x80) != 0) {
        for (cptr5 = *(char **)(arg1 + 0x28); cptr5 < *(char **)(arg1 + 0x2c);
            cptr5 = cptr5 + 1) {
          if (*cptr5 == '\n') {
            value4 = value4 + 1;
          }
        }
        if ((flag1 & 2) != 0) {
          value4 = value4 + 1;
        }
      }
      DVar6 = CRT_Lseek(uvalue2,-value4,1);
      if (DVar6 == 0xffffffff) {
        return 0xffffffff;
      }
    }
    *(uint32_t *)(arg1 + 0xc) = 0xffffffff;
    *(uint32_t *)(arg1 + 0x24) = 0;
    *(uint32_t *)(arg1 + 0x28) = 0;
    *(uint32_t *)(arg1 + 0x2c) = 0;
  }
  return 0;
}
