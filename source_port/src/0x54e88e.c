// __local_unwind2: ported from Pizza Connection 2 at 0x54e88e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e88e
#include "pc2_port.h"


/* Library Function - Single Match
    __local_unwind2
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void __cdecl __local_unwind2(int arg1,int arg2)

{
  int value1;
  int value2;
  void *pvStack_1c;
  uint8_t *puStack_18;
  uint32_t local_14;
  int iStack_10;
  
  iStack_10 = arg1;
  puStack_18 = &LAB_0054e86c;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  while( true ) {
    value1 = *(int *)(arg1 + 8);
    value2 = *(int *)(arg1 + 0xc);
    if ((value2 == -1) || (value2 == arg2)) break;
    local_14 = *(uint32_t *)(value1 + value2 * 0xc);
    *(uint32_t *)(arg1 + 0xc) = local_14;
    if (*(int *)(value1 + 4 + value2 * 0xc) == 0) {
      CRT_NotifyDebugger();
      (**(code **)(value1 + 8 + value2 * 0xc))();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}
