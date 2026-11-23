// CRT_Ios_Destroy: ported from Pizza Connection 2 at 0x54d8d7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d8d7
#include "pc2_port.h"

void __fastcall CRT_Ios_Destroy(uint32_t *arg1)

{
  arg1[0xd] = 0xffffffff;
  *arg1 = &PTR_CRT_Ios_Delete_0055ccc0;
  DAT_005855d0 = DAT_005855d0 + -1;
  if (DAT_005855d0 == 0) {
    CS_DeleteRaw((LPCRITICAL_SECTION)&DAT_00585598);
  }
  CS_DeleteRaw((LPCRITICAL_SECTION)(arg1 + 0xe));
  if ((arg1[7] != 0) && ((uint32_t *)arg1[1] != (uint32_t *)0x0)) {
    (*(code *)**(uint32_t **)arg1[1])(1);
  }
  arg1[1] = 0;
  arg1[2] = 4;
  return;
}
