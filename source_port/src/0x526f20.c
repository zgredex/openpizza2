// DebugConsole_Errorf: ported from Pizza Connection 2 at 0x526f20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526f20
#include "pc2_port.h"

void __cdecl
DebugConsole_Errorf(uint32_t arg1,uint32_t arg2,uint8_t *arg3,uint32_t arg4)

{
  uint8_t *bptr1;
  uint8_t local_800 [2048];
  
  bptr1 = local_800;
  CRT_Vsprintf(local_800,arg3,&arg4);
  DebugConsole_Printf(DAT_0057c1e0,0xff,local_800,bptr1);
  return;
}
