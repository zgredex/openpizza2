// UI_Briefing_AddPinnedMessage: ported from Pizza Connection 2 at 0x54aa10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54aa10
#include "pc2_port.h"

void __cdecl
UI_Briefing_AddPinnedMessage
          (void *arg1,int arg2,int arg3,int arg4,int arg5,int arg6,char *arg7,
          uint8_t *arg8,uint32_t arg9)

{
  char local_400 [1024];
  
  CRT_Vsprintf(local_400,arg8,&arg9);
  Sound_SetState(DAT_0057ba0c,arg3);
  Sound_PlaySpeechStatement(DAT_0057ba0c,arg2);
  UI_AddBriefingEntry(arg1,arg2,arg3,arg4,arg5,arg6,1,arg7,local_400);
  return;
}
