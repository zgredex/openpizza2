// CRT_Istream_SkipWhitespace: ported from Pizza Connection 2 at 0x54d599.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d599
#include "pc2_port.h"

void __fastcall CRT_Istream_SkipWhitespace(int *arg1)

{
  int value1;
  uint32_t uvalue2;
  void *extraout_ECX;
  void *self;
  void *extraout_ECX_00;
  
  value1 = *(int *)(*(int *)(*arg1 + 4) + 4 + (intptr_t)arg1);
  if (*(int *)(value1 + 0x30) < 0) {
    CS_EnterRaw((LPCRITICAL_SECTION)(value1 + 0x34));
  }
  uvalue2 = Stream_PeekChar(*(int **)(*(int *)(*arg1 + 4) + 4 + (intptr_t)arg1));
  self = extraout_ECX;
  while (uvalue2 != 0xffffffff) {
    uvalue2 = CRT_Isspace_L(self,uvalue2);
    if (uvalue2 == 0) goto LAB_0054d5f7;
    uvalue2 = Stream_GetChar(*(int **)(*(int *)(*arg1 + 4) + 4 + (intptr_t)arg1));
    self = extraout_ECX_00;
  }
  Thread_SetField8Locked
            ((void *)(*(int *)(*arg1 + 4) + (intptr_t)arg1),
             *(uint32_t *)(*(int *)(*arg1 + 4) + 8 + (intptr_t)arg1) | 1);
LAB_0054d5f7:
  value1 = *(int *)(*(int *)(*arg1 + 4) + 4 + (intptr_t)arg1);
  if (*(int *)(value1 + 0x30) < 0) {
    CS_LeaveRaw((LPCRITICAL_SECTION)(value1 + 0x34));
  }
  return;
}
