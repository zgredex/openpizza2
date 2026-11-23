// Person_SetAtWork: ported from Pizza Connection 2 at 0x50e2a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e2a0
#include "pc2_port.h"

void __fastcall Person_SetAtWork(int arg1,uint32_t arg2,int arg3,char arg4)

{
  void *self;
  int value1;
  int64_t lvalue2;
  
  if (*(char *)(arg1 + 0x80) != arg4) {
    *(char *)(arg1 + 0x80) = arg4;
    if ((arg3 != 0) &&
       (((value1 = *(int *)(arg1 + 0x30), value1 == 0x11 || (value1 == 0x13)) || (value1 == 0x14))))
    {
      lvalue2 = Game_GetContextCompanyRating(arg3,arg2,value1);
      self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x20),*(int *)(arg1 + 0x50),(int *)0x0)
      ;
      if (self != (void *)0x0) {
        value1 = *(int *)((intptr_t)self + 0xc) - (intptr_t)lvalue2;
        if (value1 < 0) {
          value1 = 0;
        }
        Person_SetMotivation(self,value1);
      }
    }
  }
  return;
}
