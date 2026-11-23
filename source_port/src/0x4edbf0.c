// Map_DrawRecordLinkSprites: ported from Pizza Connection 2 at 0x4edbf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4edbf0
#include "pc2_port.h"

void __thiscall Map_DrawRecordLinkSprites(void *self,int arg1,int arg2)

{
  short svalue1;
  short *psVar2;
  int *local_10;
  uint32_t local_c;
  uint32_t local_8;
  int local_4;
  
  Object_GetBufferPair(self,arg1,(int *)&local_10,&local_4,&local_8,&local_c);
  arg1 = 8;
  psVar2 = (short *)(arg2 + 0x14);
  do {
    svalue1 = *psVar2;
    if (svalue1 != -1) {
      Surface_BlitFormat(*(int *)((intptr_t)self + 8),
                         *(int *)(arg2 + 0xc) - *(int *)((intptr_t)self + 0x24),
                         *(int *)(arg2 + 0x10) - *(int *)((intptr_t)self + 0x28),
                         *(int *)(*local_10 + svalue1 * 0x28 + 0xc) - *(int *)((intptr_t)self + 0x24),
                         *(int *)(*local_10 + 0x10 + svalue1 * 0x28) - *(int *)((intptr_t)self + 0x28),
                         local_8,local_c,'\x01');
    }
    psVar2 = psVar2 + 1;
    arg1 = arg1 + -1;
  } while (arg1 != 0);
  return;
}
