// Sound_StopPlaybackMode: ported from Pizza Connection 2 at 0x547de0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547de0
#include "pc2_port.h"

void __fastcall Sound_StopPlaybackMode(int arg1)

{
  int value1;
  
  value1 = *(int *)(arg1 + 0x104);
  *(uint32_t *)(arg1 + 0x104) = 0;
  if (*(char *)(arg1 + 0xfc) == '\0') {
    return;
  }
  CS_Enter(arg1 + 0x178);
  if (value1 == 1) {
    (**(code **)(**(int **)(arg1 + 8) + 0x68))
              (*(int **)(arg1 + 8),*(uint32_t *)(arg1 + 0x80));
  }
  else if (value1 != 2) {
    if (value1 != 3) goto LAB_00547e5f;
    if (*(char *)(arg1 + 0xff) != '\0') {
      (**(code **)(**(int **)(arg1 + 8) + 0x54))
                (*(int **)(arg1 + 8),*(uint32_t *)(arg1 + 0x20));
      *(uint8_t *)(arg1 + 0xff) = 0;
    }
    *(uint32_t *)(arg1 + 0x20) = 0;
  }
  if (*(int *)(arg1 + 0x1d4) == 0) {
    SoundBuffer_Release(arg1);
  }
LAB_00547e5f:
  CS_Leave(arg1 + 0x178);
  return;
}
