// SaveMenu_WriteMenuFile: ported from Pizza Connection 2 at 0x49b8d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49b8d0
#include "pc2_port.h"


bool __cdecl SaveMenu_WriteMenuFile(int arg1)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  int *self;
  int value4;
  void *this_00;
  int local_54;
  void *local_50;
  uint8_t local_4c [64];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055871b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  String_Format(local_4c,(uint8_t *)s_save_menu__s_men_00568a44,arg1);
  local_50 = operator_new(0x58);
  local_4 = 0;
  if (local_50 == (void *)0x0) {
    self = (int *)0x0;
  }
  else {
    self = CRT_Ofstream_Construct();
  }
  local_4 = 0xffffffff;
  if ((*(uint8_t *)(*(int *)(*self + 4) + 8 + (intptr_t)self) & 6) != 0) {
    if (self != (int *)0x0) {
      (*(code *)**(uint32_t **)(*(int *)(*self + 4) + (intptr_t)self))(1);
    }
    ExceptionList = local_c;
    return false;
  }
  value1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value2 = *(int *)(value1 + 0x124);
  local_54 = 0;
  arg1 = 0x2e;
  CRT_Ostream_Write(self,&arg1,4);
  arg1 = 0;
  if (0 < value2) {
    do {
      value4 = IDMap_Lookup((void *)(value1 + 0x110),arg1,(int *)0x0);
      if (*(char *)(value4 + 0x1dc) == '\x01') {
        local_54 = local_54 + 1;
      }
      arg1 = arg1 + 1;
    } while (arg1 < value2);
  }
  CRT_Ostream_Write(self,&local_54,4);
  arg1 = 0;
  if (0 < value2) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)(value1 + 0x110),arg1,(int *)0x0);
      if (*(char *)((intptr_t)this_00 + 0x1dc) == '\x01') {
        Recipe_SaveToStream(this_00,self,'\0');
      }
      arg1 = arg1 + 1;
    } while (arg1 < value2);
  }
  uvalue3 = *(uint32_t *)(*(int *)(*self + 4) + 8 + (intptr_t)self);
  if (self != (int *)0x0) {
    (*(code *)**(uint32_t **)(*(int *)(*self + 4) + (intptr_t)self))(1);
  }
  ExceptionList = local_c;
  return (bool)('\x01' - ((uvalue3 & 6) != 0));
}
