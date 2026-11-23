// Game_CompanyManager_Construct: ported from Pizza Connection 2 at 0x4f6d30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f6d30
#include "pc2_port.h"

uint32_t * __fastcall Game_CompanyManager_Construct(uint32_t *arg1)

{
  uint32_t *uptr1;
  int value2;
  
  *arg1 = &PTR_Game_CompanyManager_Delete_0055c618;
  arg1[2] = 1;
  arg1[6] = 0;
  arg1[4] = 0xffffffff;
  arg1[0xe] = 0;
  arg1[3] = 0;
  uptr1 = Renderer_CreateChild(DAT_0057c5c8);
  arg1[7] = uptr1;
  InitializeCriticalSection((LPCRITICAL_SECTION)(arg1 + 8));
  uptr1 = arg1 + 0x45;
  value2 = 6;
  do {
    uptr1[1] = 0;
    *uptr1 = 0;
    uptr1 = uptr1 + 0x5a;
    value2 = value2 + -1;
  } while (value2 != 0);
  CRT_BeginThread(0x4f6da0,0,(intptr_t)arg1);
  return arg1;
}
