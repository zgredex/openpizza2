// Map_LinkNeighbors: ported from Pizza Connection 2 at 0x4f3ce0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f3ce0
#include "pc2_port.h"

int * __thiscall Map_LinkNeighbors(void *self,void *arg1)

{
  int *ptr1;
  int value2;
  uint32_t uvalue3;
  int *ptr4;
  int value5;
  void *this_00;
  int value6;
  int value7;
  int local_c;
  int local_8;
  int local_4;
  
LAB_004f3ce9:
  do {
    do {
      uvalue3 = Random_RangeFast(1,**(uint32_t **)((intptr_t)self + 0x118));
      ptr1 = (int *)(*(int *)((intptr_t)self + 0x118) + uvalue3 * 4);
    } while (ptr1 == (int *)0x0);
    value2 = *(int *)((intptr_t)self + 0x4c) + *ptr1 * 0xc;
  } while (((value2 == 0) || (*(short *)(*(int *)(value2 + 8) + 0x24) == -1)) ||
          (*(int *)(*(int *)(value2 + 8) + 0x28) == 0));
  local_4 = Game_CountObjectsByType(arg1,0xffffffff);
  value7 = 0;
  if (local_4 < 1) {
    return ptr1;
  }
  do {
    ptr4 = (int *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x1500),value7,(int *)0x0);
    value5 = Game_GetRecordByField814(*ptr4);
    if (*(void **)(value5 + 0xc4) == self) {
      ptr4 = *(int **)(value5 + 200);
      if (ptr4 == (int *)0x0) {
        value6 = -1;
        this_00 = (void *)0x0;
      }
      else {
        value6 = *ptr4;
        this_00 = (void *)ptr4[0x16];
      }
      Record_GetTwoFloats48(this_00,value6,&local_8,&local_c);
      if (*(short *)(*(int *)(value5 + 200) + 0x28) == -1) {
        value5 = Map_ComputeBlitRect(self,*(int *)((intptr_t)self + 0xf8) + local_8,
                                    *(int *)((intptr_t)self + 0xfc) + local_c,(int *)0x1,0);
      }
      else {
        value5 = UI_RemoveLastChild(value5);
        value5 = *(int *)((intptr_t)self + 0x4c) + *(int *)(value5 + 8) * 0xc;
      }
      if (value5 == value2) goto LAB_004f3ce9;
    }
    value7 = value7 + 1;
    if (local_4 <= value7) {
      return ptr1;
    }
  } while( true );
}
