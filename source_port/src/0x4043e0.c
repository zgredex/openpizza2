// GameMain: ported from Pizza Connection 2 at 0x4043e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4043e0
#include "pc2_port.h"

void __cdecl
GameMain(int arg1,uint32_t arg2,char *arg3,uint32_t arg4,int arg5,
        uint32_t arg6,char *arg7,uint32_t arg8,int arg9,uint32_t arg10,
        char *arg11,uint32_t arg12,int arg13,uint32_t arg14,char *arg15,
        uint32_t arg16,int arg17,uint32_t arg18,char *arg19,uint32_t arg20,
        int arg21,uint32_t arg22,char *arg23,uint32_t arg24,int arg25)

{
  uint32_t *uptr1;
  char *unaff_ESI;
  uint32_t unaff_retaddr;
  
  ResetScreenRegistry();
  GameLoop_DispatchScreens
            (unaff_ESI,unaff_retaddr,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8
             ,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,
             arg18,arg19,arg20,arg21,arg22,arg23,arg24,arg25);
  ShutdownScreens();
  uptr1 = DAT_0057c5b0;
  DAT_0057c480 = 1;
  if (DAT_0057c5b0 != (uint32_t *)0x0) {
    Sound_StopThread(DAT_0057c5b0);
    Mem_Free(uptr1);
  }
  return;
}
