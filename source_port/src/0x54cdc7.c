// CRT_Filebuf_Destroy: ported from Pizza Connection 2 at 0x54cdc7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cdc7
#include "pc2_port.h"

void CRT_Filebuf_Destroy(void)

{
  int *extraout_ECX;
  int unaff_EBP;
  
  CRT_StackFrameStub();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = (intptr_t)&PTR_CRT_Filebuf_Delete_0055cc54;
  *(uint32_t *)(unaff_EBP + -4) = 0;
  if (extraout_ECX[0xc] < 0) {
    CS_EnterRaw((LPCRITICAL_SECTION)(extraout_ECX + 0xd));
  }
  if (extraout_ECX[0x14] == 0) {
    CRT_Filebuf_Sync((intptr_t)extraout_ECX);
  }
  else {
    CRT_Filebuf_Close(extraout_ECX);
  }
  *(uint32_t *)(unaff_EBP + -4) = 0xffffffff;
  CRT_Streambuf_Destroy(extraout_ECX);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}
