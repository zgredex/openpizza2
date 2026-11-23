// CRT_Onexit: ported from Pizza Connection 2 at 0x54de25.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54de25
#include "pc2_port.h"

int __cdecl CRT_Onexit(int arg1)

{
  SIZE_T SVar1;
  int *ptr2;
  
  CRT_LockExit();
  SVar1 = CRT_Msize(DAT_00586d34);
  if (SVar1 < (uint32_t)((intptr_t)DAT_00586d30 + (4 - (intptr_t)DAT_00586d34))) {
    SVar1 = CRT_Msize(DAT_00586d34);
    ptr2 = CRT_Realloc(DAT_00586d34,(uint32_t *)(SVar1 + 0x10));
    if (ptr2 == (int *)0x0) {
      arg1 = 0;
      goto LAB_0054de9a;
    }
    DAT_00586d30 = ptr2 + ((intptr_t)DAT_00586d30 - (intptr_t)DAT_00586d34 >> 2);
    DAT_00586d34 = ptr2;
  }
  *DAT_00586d30 = arg1;
  DAT_00586d30 = DAT_00586d30 + 1;
LAB_0054de9a:
  CRT_UnlockExit();
  return arg1;
}
