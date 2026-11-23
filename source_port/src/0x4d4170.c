// Rating_DecayAndUpdateIndicators: ported from Pizza Connection 2 at 0x4d4170.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d4170
#include "pc2_port.h"

void __fastcall Rating_DecayAndUpdateIndicators(int arg1)

{
  void *self;
  uint32_t uvalue1;
  
  if (0 < *(int *)(arg1 + 0x14)) {
    *(int *)(arg1 + 4) = *(int *)(arg1 + 4) + 1;
    *(int *)(arg1 + 0x14) = *(int *)(arg1 + 0x14) + -1;
  }
  if (*(int *)(arg1 + 0x14) < 0) {
    *(int *)(arg1 + 4) = *(int *)(arg1 + 4) + -1;
    *(int *)(arg1 + 0x14) = *(int *)(arg1 + 0x14) + 1;
  }
  if (0 < *(int *)(arg1 + 0x18)) {
    *(int *)(arg1 + 8) = *(int *)(arg1 + 8) + 1;
    *(int *)(arg1 + 0x18) = *(int *)(arg1 + 0x18) + -1;
  }
  if (*(int *)(arg1 + 0x18) < 0) {
    *(int *)(arg1 + 8) = *(int *)(arg1 + 8) + -1;
    *(int *)(arg1 + 0x18) = *(int *)(arg1 + 0x18) + 1;
  }
  if (0 < *(int *)(arg1 + 0x1c)) {
    *(int *)(arg1 + 0xc) = *(int *)(arg1 + 0xc) + 1;
    *(int *)(arg1 + 0x1c) = *(int *)(arg1 + 0x1c) + -1;
  }
  if (*(int *)(arg1 + 0x1c) < 0) {
    *(int *)(arg1 + 0xc) = *(int *)(arg1 + 0xc) + -1;
    *(int *)(arg1 + 0x1c) = *(int *)(arg1 + 0x1c) + 1;
  }
  if (0 < *(int *)(arg1 + 0x20)) {
    *(int *)(arg1 + 0x10) = *(int *)(arg1 + 0x10) + 1;
    *(int *)(arg1 + 0x20) = *(int *)(arg1 + 0x20) + -1;
  }
  if (*(int *)(arg1 + 0x20) < 0) {
    *(int *)(arg1 + 0x10) = *(int *)(arg1 + 0x10) + -1;
    *(int *)(arg1 + 0x20) = *(int *)(arg1 + 0x20) + 1;
  }
  self = (void *)Game_GetRecordByField814(arg1);
  if (self != (void *)0x0) {
    uvalue1 = State_IsNegative(arg1);
    if ((char)uvalue1 == '\0') {
      if (*(short *)((intptr_t)self + 0x40) == 0x25) {
        UI_SetChildState(self,0xffff);
      }
      if (*(int *)(arg1 + 0x10) < 0x14) {
        UI_SetChildState(self,0x24);
        return;
      }
      if (*(short *)((intptr_t)self + 0x40) == 0x24) {
        UI_SetChildState(self,0xffff);
      }
      if (*(int *)(arg1 + 0xc) < 0x14) {
        UI_SetChildState(self,0x26);
        return;
      }
      if (*(short *)((intptr_t)self + 0x40) == 0x24) {
        UI_SetChildState(self,0xffff);
      }
      uvalue1 = State_HasFlags(arg1);
      if ((char)uvalue1 == '\0') {
        if (*(short *)((intptr_t)self + 0x40) == 0x21) {
          UI_SetChildState(self,0xffff);
        }
        uvalue1 = State_HasPositive(arg1);
        if (((char)uvalue1 == '\0') && (*(short *)((intptr_t)self + 0x40) == 0x27)) {
          UI_SetChildState(self,0xffff);
        }
      }
    }
  }
  return;
}
