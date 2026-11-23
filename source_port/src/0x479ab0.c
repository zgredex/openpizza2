// Game_UpdateActivePlayerCount: ported from Pizza Connection 2 at 0x479ab0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x479ab0
#include "pc2_port.h"

void __fastcall Game_UpdateActivePlayerCount(void *arg1)

{
  int value1;
  
  value1 = Game_CountPlayersByByte(arg1,3);
  *(int *)((intptr_t)arg1 + 0x186c) = value1;
  value1 = Game_CountRecordsByByteC(arg1,6);
  *(int *)((intptr_t)arg1 + 0x186c) = *(int *)((intptr_t)arg1 + 0x186c) - value1;
  return;
}
