// Map_DrawRecordLinkOverlay: ported from Pizza Connection 2 at 0x4edc90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4edc90
#include "pc2_port.h"

void __thiscall Map_DrawRecordLinkOverlay(void *self,int arg1)

{
  int value1;
  short *psVar2;
  int value3;
  uint32_t uvalue4;
  LPCRITICAL_SECTION lpCriticalSection;
  uint32_t local_18;
  int *local_14;
  int *local_10;
  LPCRITICAL_SECTION local_c;
  uint32_t local_8;
  uint32_t local_4;
  
  lpCriticalSection = (LPCRITICAL_SECTION)((intptr_t)self + 0xc0);
  local_c = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  Object_GetBufferPair(self,arg1,(int *)&local_14,(int *)&local_10,&local_4,&local_8);
  value3 = *(int *)((intptr_t)self + 0xb4);
  if (value3 != 0) {
    value1 = *(int *)((intptr_t)self + 0xb0);
    if (*(int *)((intptr_t)self + 0xac) == 0xffff) {
      Surface_DrawLine(*(int *)((intptr_t)self + 8),*(int *)(value3 + 0xc) - *(int *)((intptr_t)self + 0x24),
                       *(int *)(value3 + 0x10) - *(int *)((intptr_t)self + 0x28),*(int *)(value1 + 0xc),
                       *(int *)(value1 + 0x10),0xffff,'\x01');
    }
    else {
      Surface_BlitFormat(*(int *)((intptr_t)self + 8),*(int *)(value3 + 0xc) - *(int *)((intptr_t)self + 0x24),
                         *(int *)(value3 + 0x10) - *(int *)((intptr_t)self + 0x28),*(int *)(value1 + 0xc),
                         *(int *)(value1 + 0x10),0xa000,0xff,'\x01');
    }
  }
  local_18 = 0;
  if (0 < *local_10) {
    value3 = 0;
    do {
      Map_DrawRecordLinkSprites(self,arg1,*local_14 + value3);
      uvalue4 = 0xffffff;
      if ((*(int *)((intptr_t)self + 0xc) == 0x40) &&
         ((((*(int *)(DAT_0057c670 + 0x21c) != 0 &&
            (value1 = *(int *)(*(int *)(DAT_0057c670 + 0x21c) + 200), value1 != 0)) &&
           (value1 = *(int *)(value1 + 0x20), value1 != 0)) ||
          ((*(int *)(DAT_0057c670 + 0x218) != 0 &&
           (value1 = Array_GetRecord28(self,1,*(int *)(*(int *)(DAT_0057c670 + 0x218) + 0x54)),
           value1 != 0)))))) {
        if (local_18 == *(uint16_t *)(value1 + 4)) {
          uvalue4 = 0xff00;
        }
        else {
          psVar2 = (short *)(value1 + 0x14);
          value1 = 8;
          do {
            if ((intptr_t)*psVar2 == local_18) {
              uvalue4 = 0xff;
            }
            psVar2 = psVar2 + 1;
            value1 = value1 + -1;
          } while (value1 != 0);
        }
      }
      if (*(int *)((intptr_t)self + 0xc) == 0x10) {
        value1 = *(int *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 +
                                 *(int *)(*local_14 + 8 + value3) * 0xc) + 0x10);
        if (value1 == -2) {
          uvalue4 = 0xff;
        }
        else {
          uvalue4 = (-(uint32_t)(value1 != -1) & 0xffffa001) + 0xffff;
        }
        if (*(char *)(*local_14 + value3) != '\0') {
          uvalue4 = 0xff0000;
        }
      }
      Map_DrawTileCursorDiamond
                (self,*(int *)(*local_14 + value3 + 0xc) - *(int *)((intptr_t)self + 0x24),
                 *(int *)(*local_14 + 0x10 + value3) - *(int *)((intptr_t)self + 0x28),0,1,0,uvalue4);
      local_18 = local_18 + 1;
      value3 = value3 + 0x28;
    } while ((intptr_t)local_18 < *local_10);
    lpCriticalSection = local_c;
  }
  LeaveCriticalSection(lpCriticalSection);
  return;
}
