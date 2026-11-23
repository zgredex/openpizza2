// Renderer_CreateChild: ported from Pizza Connection 2 at 0x539ea0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539ea0
#include "pc2_port.h"


uint32_t * __fastcall Renderer_CreateChild(void *arg1)

{
  void *self;
  uint32_t *uptr1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ad3b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  self = operator_new(0x9c);
  local_4 = 0;
  if (self == (void *)0x0) {
    ExceptionList = local_c;
    return (uint32_t *)0x0;
  }
  uptr1 = Renderer_ConstructChild(self,arg1);
  ExceptionList = local_c;
  return uptr1;
}
