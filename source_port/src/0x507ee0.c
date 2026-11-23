// Person_SelectRouteStopForTimeSlot: ported from Pizza Connection 2 at 0x507ee0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x507ee0
#include "pc2_port.h"

uint32_t __thiscall Person_SelectRouteStopForTimeSlot(void *self,int arg1)

{
  int value1;
  uint32_t unaff_EDI;
  
                    /* Switches a person to a daily-route stop for the time slot. */
  if (((*(int *)((intptr_t)self + 0x38) != 0x1a) && (*(int *)((intptr_t)self + 0x108) != 10)) &&
     (arg1 != *(int *)((intptr_t)self + 0x3c))) {
    if (*(void **)(DAT_0057c670 + 0x21c) == self) {
      DebugConsole_Printf(DAT_0057c1e0,0,(uint8_t *)s_Neue_Zeitzone__0057300c,unaff_EDI);
    }
    value1 = *(int *)((intptr_t)self + arg1 * 4 + 0xd4);
    if (value1 != *(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x3c) * 4 + 0xd4)) {
      *(int *)((intptr_t)self + 0xd0) = value1;
      Object_SetDestinationAndTarget(self,6,*(int *)((intptr_t)self + arg1 * 4 + 0xd4));
      Object_SetState(self,2);
      *(int *)((intptr_t)self + 0x3c) = arg1;
      if (*(void **)(DAT_0057c670 + 0x21c) == self) {
        DebugConsole_Printf(DAT_0057c1e0,0,(uint8_t *)s_Neues_Ziel___s_00572ffc,
                            *(uint32_t *)(&DAT_005840d4 + *(int *)(value1 + 4) * 4));
      }
      return 1;
    }
    if (*(void **)(DAT_0057c670 + 0x21c) == self) {
      DebugConsole_Printf(DAT_0057c1e0,0,(uint8_t *)s_Person_bleibt__00572fec,unaff_EDI);
    }
    *(int *)((intptr_t)self + 0x3c) = arg1;
  }
  return 0;
}
