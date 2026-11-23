// SoundSample_Destruct: ported from Pizza Connection 2 at 0x53f5d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53f5d0
#include "pc2_port.h"


void __fastcall SoundSample_Destruct(uint32_t *arg1)

{
  int *ptr1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055ae48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *arg1 = &PTR_LAB_0055c850;
  local_4 = 0;
  if ((LPVOID)arg1[0xf] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0xf]);
  }
  if (arg1[3] != 0) {
    SoundStream_Close((void *)arg1[2],arg1[3]);
  }
  if ((LPVOID)arg1[4] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[4]);
  }
  ptr1 = (int *)arg1[2];
  if (ptr1 != (int *)0x0) {
    (**(code **)(*ptr1 + 4))(ptr1);
  }
  *arg1 = &PTR_LAB_0055c840;
  ExceptionList = local_c;
  return;
}
