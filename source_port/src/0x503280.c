// BuildingProject_ResetState: ported from Pizza Connection 2 at 0x503280.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x503280
#include "pc2_port.h"

void __fastcall BuildingProject_ResetState(int arg1)

{
  *(uint8_t *)(arg1 + 4) = 0;
  *(uint32_t *)(arg1 + 0x44) = 0xffffffff;
  *(uint32_t *)(arg1 + 0x40) = 0xffffffff;
  *(uint32_t *)(arg1 + 0x48) = 0xffffffff;
  *(uint32_t *)(arg1 + 0x4c) = 0xffffffff;
  *(uint32_t *)(arg1 + 0x50) = 0xffffffff;
  *(uint32_t *)(arg1 + 0x54) = 0xffffffff;
  *(uint32_t *)(arg1 + 0x58) = 0xffffffff;
  *(uint8_t *)(arg1 + 0x60) = 0;
  *(uint32_t *)(arg1 + 100) = 0xffffffff;
  *(uint32_t *)(arg1 + 8) = 0xffffffff;
  *(uint32_t *)(arg1 + 0x84) = 0xffffffff;
  List_Node_Reset(arg1 + 0x68);
  return;
}
