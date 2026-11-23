// CRT_Ostream_Construct: ported from Pizza Connection 2 at 0x54d7e9.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d7e9
#include "pc2_port.h"

int * CRT_Ostream_Construct(void)

{
  int value1;
  int *extraout_ECX;
  int unaff_EBP;
  
  CRT_StackFrameStub();
  *(uint32_t *)(unaff_EBP + -0x10) = 0;
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    *extraout_ECX = (intptr_t)&DAT_0055cca8;
    CRT_Ios_Construct(extraout_ECX + 2);
    *(uint32_t *)(unaff_EBP + -0x10) = 1;
    *(uint32_t *)(unaff_EBP + -4) = 0;
  }
  value1 = *(int *)(unaff_EBP + 8);
  *(uint8_t ***)(*(int *)(*extraout_ECX + 4) + (intptr_t)extraout_ECX) = &PTR_LAB_0055cca4;
  Stream_SetBuffer((void *)(*(int *)(*extraout_ECX + 4) + (intptr_t)extraout_ECX),value1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[1] = 0;
  return extraout_ECX;
}
