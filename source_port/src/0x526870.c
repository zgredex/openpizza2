// UI_MessageBoxf: ported from Pizza Connection 2 at 0x526870.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526870
#include "pc2_port.h"

bool __cdecl UI_MessageBoxf(void *arg1,uint8_t *arg2,uint32_t arg3)

{
  int value1;
  char local_200 [512];
  
                    /* Formats and shows a single-button modal message box. */
  CRT_Vsprintf(local_200,arg2,&arg3);
  value1 = UI_ShowChoiceMessageBox(arg1,local_200,1,*(uint32_t *)((intptr_t)arg1 + 0x2b0));
  return value1 != -1;
}
