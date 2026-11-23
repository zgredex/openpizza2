// Map_BuildPixelCoordIndex: ported from Pizza Connection 2 at 0x4825c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4825c0
#include "pc2_port.h"


void __fastcall Map_BuildPixelCoordIndex(int arg1)

{
  uint8_t flag1;
  uint32_t *uptr2;
  int value3;
  int value4;
  int value5;
  int local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005581fb;
  local_c = ExceptionList;
  uptr2 = (uint32_t *)(arg1 + 0x388);
  ExceptionList = &local_c;
  for (value3 = 0x460; value3 != 0; value3 = value3 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  local_10 = operator_new(0x11c);
  local_4 = 0;
  if (local_10 == (void *)0x0) {
    uptr2 = (uint32_t *)0x0;
  }
  else {
    uptr2 = FullscreenImage_Load
                       (local_10,s_KI_PCX_005680b4,DAT_0057c5c8,DAT_0057c5d8,&local_14,
                        (uint8_t *)0x0);
  }
  local_4 = 0xffffffff;
  if (local_14 != 0) {
    NoOp_Stub();
  }
  value3 = uptr2[6];
  local_14 = 0;
  do {
    flag1 = *(uint8_t *)(value3 + local_14);
    if (flag1 != 0) {
      value4 = (uint32_t)flag1 * 0x140;
      value5 = *(int *)(value4 + 0x388 + arg1) + 1;
      *(int *)(value4 + 0x388 + arg1) = value5;
      value5 = value5 + (uint32_t)flag1 * 0x28;
      *(int *)(arg1 + 0x388 + value5 * 8) = local_14 % 800;
      *(int *)(arg1 + 0x38c + value5 * 8) = local_14 / 800;
      *(int *)(arg1 + 0x408 + value5 * 8) = 0x214 - *(int *)(arg1 + 0x388 + value5 * 8);
      *(int *)(arg1 + 0x40c + value5 * 8) = 0x224 - local_14 / 800;
    }
    local_14 = local_14 + 1;
  } while (local_14 < 480000);
  if (uptr2 != (uint32_t *)0x0) {
    (**(code **)*uptr2)(1);
  }
  ExceptionList = local_c;
  return;
}
