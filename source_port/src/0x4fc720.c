// Game_CompanyManager_Destructor: ported from Pizza Connection 2 at 0x4fc720.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fc720
#include "pc2_port.h"

void __fastcall Game_CompanyManager_Destructor(uint32_t *arg1)

{
  int value1;
  
  value1 = 400;
  *arg1 = &PTR_Game_CompanyManager_Delete_0055c618;
  arg1[2] = 0;
  arg1[6] = 1;
  if (arg1[1] == 0) {
    do {
      if (value1 < 1) break;
      Sleep(10);
      value1 = value1 + -1;
      arg1[2] = 0;
    } while (arg1[1] == 0);
    if (arg1[1] == 0) {
      Debug_WarningMessageBox();
    }
  }
  if ((uint32_t *)arg1[7] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[7])(1);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(arg1 + 8));
  return;
}
