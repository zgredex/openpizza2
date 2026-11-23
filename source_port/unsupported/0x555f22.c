// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x555f22.c:23:27: error: called object type 'intptr_t' (aka 'int') is not a function or function pointer
// FUN_00555f22: ported from Pizza Connection 2 at 0x555f22.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555f22
#include "pc2_port.h"

int FUN_00555f22(int *arg1)

{
  int *ptr1;
  bool flag2;
  int value3;
  uint32_t extraout_var;
  
  ptr1 = (int *)*arg1;
  if (((*ptr1 == -0x1f928c9d) && (ptr1[4] == 3)) && (ptr1[5] == 0x19930520)) {
    value3 = CRT_Terminate();
    return value3;
  }
  if ((DAT_00585904 == (FARPROC)0x0) ||
     (flag2 = FUN_00555fbe(DAT_00585904), CONCAT31(extraout_var,flag2) == 0)) {
    return 0;
  }
  value3 = (*DAT_00585904)(arg1);
  return value3;
}
