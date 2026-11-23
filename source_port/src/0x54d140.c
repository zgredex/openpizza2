// CRT_Ofstream_Construct: ported from Pizza Connection 2 at 0x54d140.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d140
#include "pc2_port.h"

int * CRT_Ofstream_Construct(void)

{
  uint32_t *uptr1;
  int value2;
  uint32_t uvalue3;
  uint32_t *uptr4;
  int *ptr5;
  int *extraout_ECX;
  int unaff_EBP;
  
  CRT_StackFrameStub();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(uint32_t *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0x14) != 0) {
    *extraout_ECX = (intptr_t)&DAT_0055cc88;
    CRT_Ios_Construct(extraout_ECX + 2);
    *(uint32_t *)(unaff_EBP + -0x10) = 1;
    *(uint32_t *)(unaff_EBP + -4) = 0;
  }
  uptr4 = operator_new(0x54);
  *(uint32_t **)(unaff_EBP + 0x14) = uptr4;
  *(uint32_t *)(unaff_EBP + -4) = 1;
  if (uptr4 != (uint32_t *)0x0) {
    CRT_FileBuf_Construct(uptr4);
  }
  *(uint8_t *)(unaff_EBP + -4) = 0;
  CRT_Ostream_Construct();
  value2 = *(int *)(*extraout_ECX + 4);
  uvalue3 = *(uint32_t *)(unaff_EBP + 0x10);
  *(uint32_t *)(unaff_EBP + -4) = 2;
  *(uint8_t ***)(value2 + (intptr_t)extraout_ECX) = &PTR_LAB_0055cc84;
  *(uint32_t *)(*(int *)(*extraout_ECX + 4) + 0x1c + (intptr_t)extraout_ECX) = 1;
  ptr5 = CRT_Filebuf_Open(*(void **)(*(int *)(*extraout_ECX + 4) + 4 + (intptr_t)extraout_ECX),
                            *(LPCSTR *)(unaff_EBP + 8),*(uint32_t *)(unaff_EBP + 0xc) | 2,uvalue3);
  if (ptr5 == (int *)0x0) {
    uptr1 = (uint32_t *)(*(int *)(*extraout_ECX + 4) + 8 + (intptr_t)extraout_ECX);
    *uptr1 = *uptr1 | 2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}
