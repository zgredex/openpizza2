// SoundTrack_Destruct: ported from Pizza Connection 2 at 0x541f30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541f30
#include "pc2_port.h"


void __fastcall SoundTrack_Destruct(uint32_t *arg1)

{
  int *ptr1;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055b013;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_LAB_0055c8e0;
  ptr1 = (int *)arg1[10];
  local_4 = 1;
  if (ptr1 != (int *)0x0) {
    (**(code **)(*ptr1 + 4))(ptr1);
  }
  ptr1 = (int *)arg1[0xb];
  if (ptr1 != (int *)0x0) {
    (**(code **)(*ptr1 + 4))(ptr1);
  }
  ptr1 = (int *)arg1[0xd];
  if (ptr1 != (int *)0x0) {
    (**(code **)(*ptr1 + 8))(ptr1);
  }
  ptr1 = (int *)arg1[0xc];
  if (ptr1 != (int *)0x0) {
    (**(code **)(*ptr1 + 4))(ptr1);
  }
  local_4 = local_4 & 0xffffff00;
  if ((LPVOID)arg1[0x11] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x11]);
  }
  *arg1 = &PTR_LAB_0055c840;
  ExceptionList = pvStack_c;
  return;
}
