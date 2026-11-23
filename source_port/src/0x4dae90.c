// City_UpdateSecurityPatrolFrames: ported from Pizza Connection 2 at 0x4dae90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dae90
#include "pc2_port.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall City_UpdateSecurityPatrolFrames(void *self,int arg1)

{
  int *ptr1;
  uint32_t *this_00;
  int value2;
  void *this_01;
  int value3;
  uint32_t *uptr4;
  int value5;
  int value6;
  int local_14 [5];
  
                    /* Updates city security patrol visuals from player budgets. */
  value3 = 0;
  ptr1 = (int *)((intptr_t)self + 0xcb0);
  value5 = 6;
  do {
    value6 = *ptr1;
    ptr1 = ptr1 + 1;
    value3 = value3 + value6;
    value5 = value5 + -1;
  } while (value5 != 0);
  value5 = 0;
  DAT_0057df98 = 999;
  _DAT_0057df9c = 999;
  _DAT_0057dfa0 = 999;
  _DAT_0057dfa4 = 999;
  _DAT_0057dfa8 = 999;
  do {
    local_14[value5] = value5;
    value5 = value5 + 1;
  } while (value5 < 5);
  value5 = value3 >> 0x1f;
  value3 = value3 / 1000 + value5;
  if ((value3 == value5) && (arg1 != 0)) {
    value6 = *(int *)(arg1 + 0x48);
    if ((-1 < value6) && (value6 < 4)) {
      value6 = *(int *)(&DAT_00568188 + value6 * 4);
    }
    *(int *)(arg1 + 0x34) = value6 + 0x979;
  }
  this_00 = City_CollectBuildingsByType(self,0x11,0,'\0');
  value6 = 0;
  if (0 < (intptr_t)this_00[5]) {
    uptr4 = &DAT_0057df98;
    do {
      value2 = IDMap_Lookup(this_00,value6,(int *)0x0);
      value6 = value6 + 1;
      *uptr4 = *(uint32_t *)(value2 + 0xc);
      uptr4 = uptr4 + 1;
    } while (value6 < (intptr_t)this_00[5]);
  }
  CRT_QSort(local_14,(uint32_t *)0x5,4,&LAB_004dafe0);
  value6 = 0;
  if (0 < (intptr_t)this_00[5]) {
    ptr1 = local_14;
    do {
      this_01 = (void *)IDMap_Lookup(this_00,*ptr1,(int *)0x0);
      value2 = *(int *)((intptr_t)this_01 + 0x48);
      if (value6 < value3 - value5) {
        if ((-1 < value2) && (value2 < 4)) {
          value2 = *(int *)(&DAT_00568188 + value2 * 4);
        }
        value2 = value2 + 0x975;
      }
      else {
        if ((-1 < value2) && (value2 < 4)) {
          value2 = *(int *)(&DAT_00568188 + value2 * 4);
        }
        value2 = value2 + 0x979;
      }
      MapObject_SetTypeAndSprite(this_01,0x11,value2);
      value6 = value6 + 1;
      ptr1 = ptr1 + 1;
    } while (value6 < (intptr_t)this_00[5]);
  }
  if (this_00 != (uint32_t *)0x0) {
    (**(code **)*this_00)(1);
  }
  return;
}
