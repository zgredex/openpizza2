// Object_ResetLinkVisitedFlags: ported from Pizza Connection 2 at 0x4f4ed0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f4ed0
#include "pc2_port.h"

void __fastcall Object_ResetLinkVisitedFlags(void *arg1)

{
  int value1;
  uint8_t *uptr2;
  int value3;
  
  Object_ClearRecordFirstBytes(arg1,(int *)0x0);
  value3 = 0;
  value1 = Object_GetBufferCount(arg1,(uint32_t *)0x1);
  if (0 < value1) {
    do {
      uptr2 = (uint8_t *)Array_GetRecord28(arg1,1,value3);
      value1 = Array_CountValid8((intptr_t)uptr2);
      if (value1 == 0) {
        *uptr2 = 1;
      }
      value3 = value3 + 1;
      value1 = Object_GetBufferCount(arg1,(uint32_t *)0x1);
    } while (value3 < value1);
  }
  return;
}
