// UI_SliderUpdateFromPosition: ported from Pizza Connection 2 at 0x52a260.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52a260
#include "pc2_port.h"

int __fastcall UI_SliderUpdateFromPosition(void *arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int64_t lvalue5;
  int local_8;
  int local_4;
  
  local_4 = *(int *)((intptr_t)arg1 + 100);
  local_8 = *(int *)((intptr_t)arg1 + 0x68);
  UI_OffsetPoint(*(void **)((intptr_t)arg1 + 8),&local_4,&local_8);
  value1 = *(int *)((intptr_t)arg1 + 0x60);
  value4 = value1 + -1;
  if (value4 < 0) {
    value4 = 0;
  }
  value2 = *(int *)((intptr_t)arg1 + 0x94);
  lvalue5 = __ftol();
  value2 = (intptr_t)lvalue5 + value2;
  if (*(int *)((intptr_t)arg1 + 0x454) == 0) goto LAB_0052a33a;
  if (value4 == 0) {
    value3 = *(int *)((intptr_t)arg1 + 0x90);
    if (*(int *)((intptr_t)arg1 + 0x58) == 0) goto LAB_0052a32e;
joined_r0x0052a336:
    if (value2 <= value3) goto LAB_0052a33a;
  }
  else {
    value3 = *(int *)((intptr_t)arg1 + 0x8c);
    if (*(int *)((intptr_t)arg1 + 0x58) == 0) goto joined_r0x0052a336;
LAB_0052a32e:
    if (value3 <= value2) goto LAB_0052a33a;
  }
  value2 = value3;
LAB_0052a33a:
  if (value2 == *(int *)((intptr_t)arg1 + value4 * 4 + 0x8c)) {
    return value1;
  }
  UI_SetClampedValue(arg1,value2,value4);
  value4 = *(int *)((intptr_t)arg1 + value4 * 4 + 0x8c);
  UI_ClipRect(*(void **)((intptr_t)arg1 + 8),(int *)((intptr_t)arg1 + 0x28),1);
  if (*(int *)((intptr_t)arg1 + 0xc4) != 0) {
    UI_QueueControlCommand(*(void **)((intptr_t)arg1 + 8),*(int *)((intptr_t)arg1 + 4),0x19,value4);
  }
  return *(int *)((intptr_t)arg1 + 0x60);
}
