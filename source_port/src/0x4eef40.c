// Map_BuildElementAnimationList: ported from Pizza Connection 2 at 0x4eef40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eef40
#include "pc2_port.h"

void __thiscall Map_BuildElementAnimationList(void *self,int arg1,int arg2)

{
  int *ptr1;
  char *cptr2;
  int value3;
  int value4;
  void *pvVar5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  int value8;
  
                    /* Builds animation records for one named map element group. */
  value3 = arg1;
  value4 = Game_GetRecordChild14(*(void **)((intptr_t)self + 4),arg1);
  value8 = 0;
  *(int *)(arg2 + 4) = value4;
  if (value4 < 1) {
    *(uint32_t *)(arg2 + 8) = 0;
  }
  else {
    pvVar5 = operator_new(value4 * 0xc);
    *(void **)(arg2 + 8) = pvVar5;
    arg1 = 0;
    if (0 < *(int *)(arg2 + 4)) {
      do {
        uvalue6 = Game_GetNestedArrayEntry(*(void **)((intptr_t)self + 4),value3,arg1);
        *(uint32_t *)(value8 + 8 + *(int *)(arg2 + 8)) = uvalue6;
        *(uint32_t *)(value8 + 4 + *(int *)(arg2 + 8)) = 0;
        cptr2 = *(char **)(value8 + 8 + *(int *)(arg2 + 8));
        if ((((uint8_t)cptr2[3] <= *(uint8_t *)(*(int *)((intptr_t)self + 4) + 0x2bf48)) &&
            (*cptr2 == '\x01')) && (cptr2[1] == '\x01')) {
          *(uint32_t *)(value8 + *(int *)(arg2 + 8) + 4) = 1;
        }
        uvalue6 = Game_GetNestedArrayEntry(*(void **)((intptr_t)self + 4),value3,arg1);
        *(uint32_t *)(value8 + 8 + *(int *)(arg2 + 8)) = uvalue6;
        value4 = RecordList_FindFreeSlot
                          (*(void **)(*(int *)(value8 + 8 + *(int *)(arg2 + 8)) + 0x48),-1);
        *(int *)(value8 + *(int *)(arg2 + 8)) = value4;
        ptr1 = (int *)(value8 + *(int *)(arg2 + 8));
        if (*(int *)(value8 + 4 + *(int *)(arg2 + 8)) != 0) {
          Record_SelectVariant(*(void **)(ptr1[2] + 0x48),*ptr1,-1);
          if ((0x64b < value3) && (value3 < 0x66e)) {
            ptr1 = (int *)(value8 + *(int *)(arg2 + 8));
            value4 = _rand();
            Record_SetIndex48(*(void **)(ptr1[2] + 0x48),*ptr1,value4 % 0xc);
          }
          if (value3 == 0x6a2) {
            ptr1 = (int *)(value8 + *(int *)(arg2 + 8));
            uvalue7 = _rand();
            Record_SetIndex48(*(void **)(ptr1[2] + 0x48),*ptr1,uvalue7 & 0x1f);
          }
        }
        arg1 = arg1 + 1;
        value8 = value8 + 0xc;
      } while (arg1 < *(int *)(arg2 + 4));
      return;
    }
  }
  return;
}
