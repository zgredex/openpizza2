// Object_LinkNeighborRecord: ported from Pizza Connection 2 at 0x4f0d00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f0d00
#include "pc2_port.h"

uint32_t __thiscall
Object_LinkNeighborRecord(void *self,int *arg1,int arg2,int arg3,uint32_t *arg4)

{
  int value1;
  int value2;
  int *ptr3;
  short *psVar4;
  int *ptr5;
  
  value2 = *(int *)((intptr_t)self + 0xb4);
  value1 = Object_FindRecordAtOffset(self,arg1,arg2,arg3);
  if (arg4 != (uint32_t *)0x0) {
    *arg4 = (uint32_t)(value1 != 0);
  }
  if (value1 == 0) {
    ptr3 = arg1;
  }
  else {
    ptr3 = (int *)(uint32_t)*(uint16_t *)(value1 + 2);
  }
  if (*(int *)((intptr_t)self + 0xb4) == 0) {
    ptr5 = arg1;
  }
  else {
    ptr5 = (int *)(uint32_t)*(uint16_t *)(*(int *)((intptr_t)self + 0xb4) + 2);
  }
  if (value1 == 0) {
    value1 = Object_AppendBufferRecord(self,arg1,arg2,arg3);
    *(int *)((intptr_t)self + 0xb4) = value1;
  }
  else {
    value1 = Object_FindRecordByKey28(self,arg1,(uint32_t)ptr3);
    *(int *)((intptr_t)self + 0xb4) = value1;
  }
  if ((value2 != 0) && (value2 = Object_FindRecordByKey28(self,arg1,(uint32_t)ptr5), value2 != 0)) {
    value1 = 0;
    psVar4 = (short *)(value2 + 0x14);
    do {
      if (*psVar4 == -1) {
        *(uint16_t *)(value2 + 0x14 + value1 * 2) = *(uint16_t *)(*(int *)((intptr_t)self + 0xb4) + 4);
        break;
      }
      value1 = value1 + 1;
      psVar4 = psVar4 + 1;
    } while (value1 < 8);
    if (arg1 == (int *)0x1) {
      value1 = 0;
      psVar4 = (short *)(*(int *)((intptr_t)self + 0xb4) + 0x14);
      do {
        if (*psVar4 == -1) {
          *(uint16_t *)(*(int *)((intptr_t)self + 0xb4) + 0x14 + value1 * 2) =
               *(uint16_t *)(value2 + 4);
          break;
        }
        value1 = value1 + 1;
        psVar4 = psVar4 + 1;
      } while (value1 < 8);
    }
  }
  NoOp_2();
  return *(uint32_t *)((intptr_t)self + 0xb4);
}
