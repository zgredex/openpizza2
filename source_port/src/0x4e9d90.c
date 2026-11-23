// Game_ReleaseConstructionSpriteLists: ported from Pizza Connection 2 at 0x4e9d90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e9d90
#include "pc2_port.h"

void __fastcall Game_ReleaseConstructionSpriteLists(int arg1)

{
  int value1;
  int *ptr2;
  
  value1 = 0x29;
  ptr2 = (int *)(arg1 + 0x2c314);
  do {
    if (ptr2[-0x30] != 0) {
      List_ReleaseSharedBuffers(ptr2[-0x30]);
    }
    if (*ptr2 != 0) {
      List_ReleaseSharedBuffers(*ptr2);
    }
    ptr2 = ptr2 + 1;
    value1 = value1 + -1;
  } while (value1 != 0);
  if (*(int *)(arg1 + 0x2c3c0) != 0) {
    List_ReleaseSharedBuffers(*(int *)(arg1 + 0x2c3c0));
  }
  if (*(int *)(arg1 + 0x2c3bc) != 0) {
    List_ReleaseSharedBuffers(*(int *)(arg1 + 0x2c3bc));
  }
  if (*(int *)(arg1 + 0x2c3c4) != 0) {
    List_ReleaseSharedBuffers(*(int *)(arg1 + 0x2c3c4));
  }
  if (*(int *)(arg1 + 0x2c3c8) != 0) {
    List_ReleaseSharedBuffers(*(int *)(arg1 + 0x2c3c8));
  }
  if (*(int *)(arg1 + 0x2c3cc) != 0) {
    List_ReleaseSharedBuffers(*(int *)(arg1 + 0x2c3cc));
  }
  if (*(int *)(arg1 + 0x2c3d0) != 0) {
    List_ReleaseSharedBuffers(*(int *)(arg1 + 0x2c3d0));
  }
  if (*(int *)(arg1 + 0x2c3d4) == 0) {
    return;
  }
  List_ReleaseSharedBuffers(*(int *)(arg1 + 0x2c3d4));
  return;
}
