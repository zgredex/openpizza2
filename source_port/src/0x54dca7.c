// Stream_AllocateAttachedBuffer: ported from Pizza Connection 2 at 0x54dca7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54dca7
#include "pc2_port.h"

uint32_t __fastcall Stream_AllocateAttachedBuffer(void *arg1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x200);
  if (pvVar1 == (void *)0x0) {
    return 0xffffffff;
  }
  Stream_AttachBuffer(arg1,pvVar1,(intptr_t)pvVar1 + 0x200,1);
  return 1;
}
