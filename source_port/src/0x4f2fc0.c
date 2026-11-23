// Map_DrawObjectList: ported from Pizza Connection 2 at 0x4f2fc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f2fc0
#include "pc2_port.h"

void __thiscall Map_DrawObjectList(void *self,int arg1,void *arg2)

{
  short svalue1;
  int value2;
  int value3;
  int value4;
  short *psVar5;
  char *cptr6;
  int value7;
  int *ptr8;
  short *psVar9;
  int local_28;
  int local_20 [4];
  uint32_t local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_20[0] = 1;
  local_10 = 0xffffffff;
  local_20[2] = *(int *)((intptr_t)self + 0x1c);
  local_20[1] = local_20[2] + 1;
  local_20[3] = local_20[2] + -1;
  local_c = -1 - local_20[2];
  local_4 = 1 - local_20[2];
  local_8 = -local_20[2];
  EnterCriticalSection((LPCRITICAL_SECTION)((intptr_t)self + 0xc0));
  if (arg1 == 0) {
    value3 = 0;
    if (0 < *(int *)((intptr_t)arg2 + 0x14)) {
      do {
        value4 = IDMap_Lookup(arg2,value3,(int *)0x0);
        svalue1 = *(short *)(*(int *)(value4 + 8) + 0x24);
        if ((svalue1 != -1) &&
           (cptr6 = (char *)Array_GetRecord28(self,1,(intptr_t)svalue1), *cptr6 != '\x01')) {
          *(uint32_t *)(*(int *)(value4 + 8) + 0x28) = 1;
        }
        value3 = value3 + 1;
      } while (value3 < *(int *)((intptr_t)arg2 + 0x14));
    }
    arg1 = 0;
    if (0 < *(int *)((intptr_t)arg2 + 0x14)) {
      do {
        value3 = IDMap_Lookup(arg2,arg1,(int *)0x0);
        svalue1 = *(short *)(*(int *)(value3 + 8) + 0x24);
        if ((svalue1 != -1) &&
           (cptr6 = (char *)Array_GetRecord28(self,1,(intptr_t)svalue1), *cptr6 != '\x01')) {
          ptr8 = local_20;
          local_28 = 8;
          do {
            value4 = *(int *)((intptr_t)self + 0x4c);
            value7 = **(int **)(value3 + 8) + *ptr8;
            value2 = *(int *)(value4 + 8 + value7 * 0xc);
            if ((*(int *)(value2 + 0x28) != 0) &&
               (cptr6 = (char *)Array_GetRecord28(self,1,(intptr_t)*(short *)(value2 + 0x24)),
               *cptr6 != '\x01')) {
              Map_LinkCells(self,1,(intptr_t)*(short *)(*(int *)(value3 + 8) + 0x24),
                            (intptr_t)*(short *)(*(int *)(value4 + value7 * 0xc + 8) + 0x24));
            }
            ptr8 = ptr8 + 1;
            local_28 = local_28 + -1;
          } while (local_28 != 0);
        }
        arg1 = arg1 + 1;
      } while (arg1 < *(int *)((intptr_t)arg2 + 0x14));
    }
  }
  else {
    arg1 = 0;
    if (0 < *(int *)((intptr_t)arg2 + 0x14)) {
      do {
        value3 = IDMap_Lookup(arg2,arg1,(int *)0x0);
        svalue1 = *(short *)(*(int *)(value3 + 8) + 0x24);
        if (svalue1 != -1) {
          value4 = Array_GetRecord28(self,1,(intptr_t)svalue1);
          psVar9 = (short *)(value4 + 0x14);
          local_28 = 8;
          *(uint32_t *)(*(int *)(value3 + 8) + 0x28) = 0;
          do {
            if (*psVar9 != -1) {
              value4 = Array_GetRecord28(self,1,(intptr_t)*psVar9);
              psVar5 = (short *)(value4 + 0x14);
              value4 = 8;
              do {
                if (*psVar5 == *(short *)(*(int *)(value3 + 8) + 0x24)) {
                  *psVar5 = -1;
                }
                psVar5 = psVar5 + 1;
                value4 = value4 + -1;
              } while (value4 != 0);
            }
            *psVar9 = -1;
            psVar9 = psVar9 + 1;
            local_28 = local_28 + -1;
          } while (local_28 != 0);
        }
        arg1 = arg1 + 1;
      } while (arg1 < *(int *)((intptr_t)arg2 + 0x14));
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((intptr_t)self + 0xc0));
  return;
}
