// Game_AutoSaveTick: ported from Pizza Connection 2 at 0x48b570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48b570
#include "pc2_port.h"

void __fastcall Game_AutoSaveTick(void *arg1)

{
  int value1;
  bool flag2;
  
  if ((((*(int *)((intptr_t)arg1 + 0x1508) == 0) && (*(int *)((intptr_t)arg1 + 0x290) != 7)) &&
      (DAT_0057b9f0 != -1)) && (DAT_0057b9f4 = DAT_0057b9f4 + 1, DAT_0057b9f0 <= DAT_0057b9f4)) {
    DAT_0057b9f4 = 0;
    flag2 = *(int *)((intptr_t)arg1 + 0x1508) == 0;
    if (flag2) {
      Game_SuspendSimulation(arg1);
    }
    value1 = DAT_0057b9fc;
    if (DAT_0057b9f8 <= DAT_0057b9fc) {
      value1 = 0;
    }
    DAT_0057b9fc = value1 + 1;
    if (DAT_0057b9f8 <= DAT_0057b9fc) {
      DAT_0057b9fc = 0;
    }
    SaveGame_Write(arg1,(char *)0x0,value1);
    if (flag2) {
      Game_ResumeSimulation(arg1);
    }
  }
  return;
}
