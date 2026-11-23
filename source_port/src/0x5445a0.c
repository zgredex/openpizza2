// SoundBuffer_StopPlayback: ported from Pizza Connection 2 at 0x5445a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5445a0
#include "pc2_port.h"

uint32_t __fastcall SoundBuffer_StopPlayback(int arg1)

{
  int *ptr1;
  int value2;
  
  ptr1 = *(int **)(arg1 + 0x48);
  if (ptr1 == (int *)0x0) {
    return 0x80070006;
  }
  value2 = (**(code **)(*ptr1 + 0x48))(ptr1);
  if (value2 < 0) {
    return 0x80004005;
  }
  if (*(char *)(arg1 + 0x34) != '\0') {
    List_DestroyObjects(arg1);
  }
  value2 = (**(code **)(**(int **)(arg1 + 0x48) + 0x34))(*(int **)(arg1 + 0x48),0);
  return (-1 < value2) - 1 & 0x80004005;
}
