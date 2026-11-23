// CompanyOverview_SortCompanyIndices: ported from Pizza Connection 2 at 0x4b43f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b43f0
#include "pc2_port.h"


void __cdecl CompanyOverview_SortCompanyIndices(uint32_t *arg1)

{
  int value1;
  
  if (0 < (intptr_t)arg1) {
    value1 = 0;
    if (0 < (intptr_t)arg1) {
      do {
        DAT_0057d6a0[value1] = value1;
        value1 = value1 + 1;
      } while (value1 < (intptr_t)arg1);
    }
    if (*(short *)(*(int *)(DAT_0057c670 + 0x94) + 10) != 0) {
      if (DAT_0057d69c == 0) {
        CRT_QSort(DAT_0057d6a0,arg1,4,&LAB_004b4480);
      }
      else {
        if (DAT_0057d69c == 1) {
          CRT_QSort(DAT_0057d6a0,arg1,4,&LAB_004b4510);
          return;
        }
        if (DAT_0057d69c == 2) {
          CRT_QSort(DAT_0057d6a0,arg1,4,&LAB_004b45b0);
          return;
        }
      }
    }
  }
  return;
}
