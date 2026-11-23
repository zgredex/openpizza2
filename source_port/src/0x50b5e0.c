// Person_AssignBranchStaffRole: ported from Pizza Connection 2 at 0x50b5e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50b5e0
#include "pc2_port.h"

void __thiscall
Person_AssignBranchStaffRole(void *self,int arg1,int arg2,uint32_t arg3,char arg4)

{
                    /* Assigns a person to a branch staff-role slot. */
  if (arg4 != '\0') {
    *(uint32_t *)((intptr_t)self + 0x108) = 2;
  }
  *(uint8_t *)(arg1 + 0x1880 + arg2) = 1;
  Object_SetDestinationAndTarget(self,1,*(int *)(arg1 + 0x16f0));
  Object_SetFieldA4Locked(self,0xc);
  *(uint32_t *)((intptr_t)self + 0x98) = 1;
  *(uint32_t *)((intptr_t)self + 0x8c) = arg3;
  if (arg2 == 0) {
    UI_SetChildState(self,0x17);
  }
  else {
    if (arg2 == 1) {
      UI_SetChildState(self,0x18);
      *(uint32_t *)((intptr_t)self + 0x10c) = 1;
      return;
    }
    if (arg2 == 2) {
      UI_SetChildState(self,0x19);
      *(uint32_t *)((intptr_t)self + 0x10c) = 2;
      return;
    }
  }
  *(int *)((intptr_t)self + 0x10c) = arg2;
  return;
}
