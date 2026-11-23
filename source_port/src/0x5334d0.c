// List_ReleaseSharedBuffers: ported from Pizza Connection 2 at 0x5334d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5334d0
#include "pc2_port.h"

void __fastcall List_ReleaseSharedBuffers(int arg1)

{
  LPVOID pvVar1;
  bool flag2;
  int value3;
  
  flag2 = false;
  if (*(char *)(arg1 + 0x34) != '\0') {
    CS_Enter(0x584248);
    if (*(char *)(arg1 + 0x35) != '\0') {
      value3 = 0;
      if (0 < *(int *)(arg1 + 0x68)) {
        do {
          if ((!flag2) &&
             (pvVar1 = *(LPVOID *)(*(int *)(arg1 + 0x80) + value3 * 4), pvVar1 != (LPVOID)0x0)) {
            flag2 = true;
            Mem_Free(pvVar1);
          }
          value3 = value3 + 1;
          *(uint32_t *)(*(int *)(arg1 + 0x80) + -4 + value3 * 4) = 0;
        } while (value3 < *(int *)(arg1 + 0x68));
      }
      *(uint8_t *)(arg1 + 0x35) = 0;
    }
    CS_Leave(0x584248);
  }
  return;
}
