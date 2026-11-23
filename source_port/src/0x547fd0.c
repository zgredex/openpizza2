// SoundBuffer_Release: ported from Pizza Connection 2 at 0x547fd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547fd0
#include "pc2_port.h"

void __fastcall SoundBuffer_Release(int arg1)

{
  int value1;
  int value2;
  
  value1 = *(int *)(arg1 + 0xc);
  if (value1 != 0) {
    value2 = *(int *)(arg1 + 0x108);
    if ((value2 < 0) || (0xb < value2)) {
      if (value2 == 0x3ec) {
        (**(code **)(**(int **)(arg1 + 8) + 0xf0))(*(int **)(arg1 + 8),value1,arg1 + 0x13c);
      }
    }
    else {
      (**(code **)(**(int **)(arg1 + 8) + 0xf0))
                (*(int **)(arg1 + 8),value1,arg1 + 0x10c + value2 * 4);
    }
    (**(code **)(**(int **)(arg1 + 8) + 0x54))
              (*(int **)(arg1 + 8),*(uint32_t *)(arg1 + 0xc));
    *(uint32_t *)(arg1 + 0xc) = 0;
  }
  return;
}
