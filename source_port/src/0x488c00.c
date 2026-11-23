// Game_RunSimulationFrame: ported from Pizza Connection 2 at 0x488c00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x488c00
#include "pc2_port.h"

void __fastcall Game_RunSimulationFrame(void *arg1)

{
                    /* Runs one simulation frame and advances world phases. */
  if (*(int *)((intptr_t)arg1 + 0x1508) == 0) {
    CS_Enter(*(int *)((intptr_t)arg1 + 0x23c));
    *(uint32_t *)((intptr_t)arg1 + 0x254) = 1;
    CS_Leave(*(int *)((intptr_t)arg1 + 0x23c));
    CS_Enter(*(int *)((intptr_t)arg1 + 0x240));
    Game_UpdateWorldObjects(arg1,DAT_0057c68c);
    *(int *)((intptr_t)arg1 + 0x340) = *(int *)((intptr_t)arg1 + 0x340) + 1;
    if (DAT_0057c68c == 0) {
      Game_UpdateIdleCars((intptr_t)arg1);
    }
    Sound_UpdateCityAmbience
              (DAT_0057ba0c,(uint32_t)*(uint8_t *)(*(int *)((intptr_t)arg1 + 0x94) + 7),
               (uint32_t)*(uint8_t *)(*(int *)((intptr_t)arg1 + 0x94) + 6) * 5);
    CS_Leave(*(int *)((intptr_t)arg1 + 0x240));
    *(uint32_t *)((intptr_t)arg1 + 0x254) = 0;
    DAT_0057c68c = DAT_0057c68c + 1;
    if (4 < DAT_0057c68c) {
      DAT_0057c68c = 0;
    }
  }
  return;
}
