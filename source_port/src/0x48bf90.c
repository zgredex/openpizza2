// UI_Briefing_Printf: ported from Pizza Connection 2 at 0x48bf90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48bf90
#include "pc2_port.h"

void __cdecl
UI_Briefing_Printf(int arg1,int arg2,int arg3,int arg4,int arg5,int arg6,
                  char *arg7,uint8_t *arg8,uint32_t arg9)

{
  uint8_t *bptr1;
  uint8_t local_400 [1024];
  
  bptr1 = local_400;
  CRT_Vsprintf(local_400,arg8,&arg9);
  UI_Briefing_AddMessage
            ((void *)(arg1 + 0x304),arg2,arg3,arg4,arg5,arg6,arg7,local_400,
             bptr1);
  return;
}
