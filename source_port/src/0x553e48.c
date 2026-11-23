// CRT_SetArgv: ported from Pizza Connection 2 at 0x553e48.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553e48
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_SetArgv(void)

{
  uint32_t *uptr1;
  uint8_t *bptr2;
  int local_c;
  int local_8;
  
  if (DAT_00586d2c == 0) {
    FUN_00556979();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_005857e4,0x104);
  _DAT_00585640 = &DAT_005857e4;
  bptr2 = &DAT_005857e4;
  if (*DAT_00586d24 != 0) {
    bptr2 = DAT_00586d24;
  }
  ParseCommandLine(bptr2,(uint32_t *)0x0,(uint8_t *)0x0,&local_8,&local_c);
  uptr1 = _malloc(local_c + local_8 * 4);
  if (uptr1 == (uint32_t *)0x0) {
    __amsg_exit(8);
  }
  ParseCommandLine(bptr2,uptr1,(uint8_t *)(uptr1 + local_8),&local_8,&local_c);
  _DAT_00585628 = uptr1;
  _DAT_00585624 = local_8 + -1;
  return;
}
