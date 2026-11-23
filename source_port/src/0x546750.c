// SoundBuffer_Destructor: ported from Pizza Connection 2 at 0x546750.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x546750
#include "pc2_port.h"


void __fastcall SoundBuffer_Destructor(uint32_t *arg1)

{
  int value1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055b798;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *arg1 = &PTR_LAB_0055cb14;
  value1 = arg1[3];
  local_4 = 0;
  if (value1 != 0) {
    if (value1 == 1) {
      (**(code **)(*(int *)arg1[2] + 4))((int *)arg1[2]);
      goto LAB_00546792;
    }
    if (value1 != 2) goto LAB_00546792;
  }
  (**(code **)(*(int *)arg1[2] + 4))((int *)arg1[2]);
LAB_00546792:
  *arg1 = &PTR_LAB_0055c840;
  ExceptionList = local_c;
  return;
}
