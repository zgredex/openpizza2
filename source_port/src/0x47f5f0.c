// Branch_RemoveAllBuildings: ported from Pizza Connection 2 at 0x47f5f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47f5f0
#include "pc2_port.h"

void __fastcall Branch_RemoveAllBuildings(void *arg1)

{
  void *self;
  void *pvVar1;
  int value2;
  
  self = *(void **)((intptr_t)arg1 + 0x16f0);
  if (self == (void *)0x0) {
    return;
  }
LAB_0047f5ff:
  value2 = 0;
  if (*(int *)((intptr_t)self + 0x8c) < 1) {
    return;
  }
  do {
    pvVar1 = (void *)Game_MapRecordToGlobal(self,value2);
    switch(*(uint32_t *)((intptr_t)pvVar1 + 0x30)) {
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x2f:
      goto switchD_0047f626_caseD_1a;
    default:
      value2 = value2 + 1;
      if (*(int *)((intptr_t)self + 0x8c) <= value2) {
        return;
      }
    }
  } while( true );
switchD_0047f626_caseD_1a:
  Branch_RemoveBuildingObject(arg1,pvVar1);
  goto LAB_0047f5ff;
}
