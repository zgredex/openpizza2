// Game_ShutdownSubsystems: ported from Pizza Connection 2 at 0x4055d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4055d0
#include "pc2_port.h"

void Game_ShutdownSubsystems(void)

{
  LPVOID pvVar1;
  
                    /* Releases the global UI, renderer, and sound subsystems. */
  if (DAT_0057c5e0 != (uint32_t *)0x0) {
    (**(code **)*DAT_0057c5e0)(1);
    DAT_0057c5e0 = (uint32_t *)0x0;
  }
  if (DAT_0057c5ec != (uint32_t *)0x0) {
    (**(code **)*DAT_0057c5ec)(1);
    DAT_0057c5ec = (uint32_t *)0x0;
  }
  if (DAT_0057c5c8 != (uint32_t *)0x0) {
    (**(code **)*DAT_0057c5c8)(1);
    DAT_0057c5c8 = (uint32_t *)0x0;
  }
  pvVar1 = DAT_0057ba0c;
  if (DAT_0057ba0c != (LPVOID)0x0) {
    SoundSystem_Destruct((intptr_t)DAT_0057ba0c);
    Mem_Free(pvVar1);
    DAT_0057ba0c = (LPVOID)0x0;
  }
  return;
}
