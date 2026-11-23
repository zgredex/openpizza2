// CRT_Istream_Construct: ported from Pizza Connection 2 at 0x54d40e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d40e
#include "pc2_port.h"

int * CRT_Istream_Construct(void)

{
  uint32_t *uptr1;
  int value2;
  int *extraout_ECX;
  int unaff_EBP;
  
  CRT_StackFrameStub();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(uint32_t *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    *extraout_ECX = (intptr_t)&DAT_0055cc98;
    CRT_Ios_Construct(extraout_ECX + 3);
    *(uint32_t *)(unaff_EBP + -0x10) = 1;
    *(uint32_t *)(unaff_EBP + -4) = 0;
  }
  value2 = *(int *)(unaff_EBP + 8);
  *(uint8_t ***)(*(int *)(*extraout_ECX + 4) + (intptr_t)extraout_ECX) = &PTR_LAB_0055cc94;
  Stream_SetBuffer((void *)(*(int *)(*extraout_ECX + 4) + (intptr_t)extraout_ECX),value2);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  uptr1 = (uint32_t *)(*(int *)(*extraout_ECX + 4) + 0x24 + (intptr_t)extraout_ECX);
  *uptr1 = *uptr1 | 1;
  extraout_ECX[2] = 0;
  extraout_ECX[1] = 0;
  return extraout_ECX;
}
