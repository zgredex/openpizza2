// SaveMenu_WritePreview: ported from Pizza Connection 2 at 0x498930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x498930
#include "pc2_port.h"


bool __cdecl SaveMenu_WritePreview(void *arg1)

{
  int *self;
  bool flag1;
  double fVar2;
  uint32_t local_94;
  void *local_90;
  uint8_t local_8c [64];
  uint8_t auStack_4c [64];
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005585ce;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(uint8_t *)((intptr_t)arg1 + 0x1dd) = 0;
  String_Format(local_8c,(uint8_t *)s_save_piz__s_piz_005688c0,(intptr_t)arg1 + 4);
  local_90 = operator_new(0x58);
  self = (int *)0x0;
  local_4 = 0;
  if (local_90 != (void *)0x0) {
    self = CRT_Ofstream_Construct();
  }
  local_4 = 0xffffffff;
  if ((*(uint8_t *)(*(int *)(*self + 4) + 8 + (intptr_t)self) & 6) == 0) {
    local_94 = 0x2e;
    CRT_Ostream_Write(self,&local_94,4);
    Recipe_SaveToStream(arg1,self,'\0');
    flag1 = (*(uint8_t *)(*(int *)(*self + 4) + 8 + (intptr_t)self) & 6) == 0;
    if (self != (int *)0x0) {
      (*(code *)**(uint32_t **)(*(int *)(*self + 4) + (intptr_t)self))();
    }
    fVar2 = Game_GetPlayerWeightedStat((intptr_t)arg1);
    String_Format(auStack_4c,(uint8_t *)s__0_2f__005688b8,SUB84((double)fVar2,0));
    if (*(void **)(DAT_0057c670 + 0x264) != (void *)0x0) {
      Window_GadgetNotify_Text_SetText(*(void **)(DAT_0057c670 + 0x264),0x4f9,auStack_4c);
    }
  }
  else {
    if (self != (int *)0x0) {
      (*(code *)**(uint32_t **)(*(int *)(*self + 4) + (intptr_t)self))();
    }
    flag1 = false;
  }
  ExceptionList = pvStack_c;
  return flag1;
}
