// CRT_CxxCatchAllSearch: ported from Pizza Connection 2 at 0x552ec2.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552ec2
#include "pc2_port.h"

void __cdecl
CRT_CxxCatchAllSearch
          (PEXCEPTION_RECORD arg1,PVOID arg2,DWORD arg3,uint32_t arg4,uint32_t arg5,
          int arg6,int arg7,PVOID arg8)

{
  DWORD *pDVar1;
  int value2;
  int *ptr3;
  int value4;
  uint32_t local_c;
  uint32_t local_8;
  
                    /* Offers the exception to the SEH translator and catch-all clauses. */
  pDVar1 = CRT_GetThreadData();
  if ((pDVar1[0x1a] != 0) &&
     (value2 = CRT_InvokeSeTranslator
                        (&arg1->ExceptionCode,arg2,arg3,arg4,arg5,arg7,arg8),
     value2 != 0)) {
    return;
  }
  ptr3 = (int *)CRT_FindTryBlockRange(arg5,arg7,arg6,&local_8,&local_c);
  for (; local_8 < local_c; local_8 = local_8 + 1) {
    if ((*ptr3 <= arg6) && (arg6 <= ptr3[1])) {
      value4 = ptr3[3] * 0x10 + ptr3[4];
      value2 = *(int *)(value4 + -0xc);
      if ((value2 == 0) || (*(char *)(value2 + 8) == '\0')) {
        CRT_CatchIt(arg1,arg2,arg3,arg4,arg5,(uint8_t *)(value4 + -0x10),(uint8_t *)0x0,
                    ptr3,arg7,arg8);
      }
    }
    ptr3 = ptr3 + 5;
  }
  return;
}
