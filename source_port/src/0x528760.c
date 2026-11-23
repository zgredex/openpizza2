// Window_ReleaseResources: ported from Pizza Connection 2 at 0x528760.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x528760
#include "pc2_port.h"

void __fastcall Window_ReleaseResources(int arg1)

{
  *(uint32_t *)(arg1 + 0x44) = 0;
  UI_ReleaseRefCount(*(void **)(*(int *)(arg1 + 0x58) + 0x134),*(int *)(arg1 + 0x4c));
  if (*(LPVOID *)(arg1 + 0x68) != (LPVOID)0x0) {
    Mem_Free(*(LPVOID *)(arg1 + 0x68));
    *(uint32_t *)(arg1 + 0x68) = 0;
  }
  return;
}
