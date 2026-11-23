// Sound_AllocDecompressedBuffer: ported from Pizza Connection 2 at 0x53f880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53f880
#include "pc2_port.h"

int __fastcall Sound_AllocDecompressedBuffer(int arg1)

{
  void *pvVar1;
  
  if ((*(short *)(arg1 + 0x14) == 0x11) && (*(short *)(arg1 + 0x22) == 4)) {
    if (*(uint16_t *)(arg1 + 0x20) < 0x801) {
      pvVar1 = operator_new((uint32_t)*(uint16_t *)(arg1 + 0x20) << 3);
      *(void **)(arg1 + 0x3c) = pvVar1;
      return (-(uint32_t)(pvVar1 != (void *)0x0) & 0x7ff8fff2) + 0x8007000e;
    }
    NoOp_Stub();
  }
  return -0x7fffbfff;
}
