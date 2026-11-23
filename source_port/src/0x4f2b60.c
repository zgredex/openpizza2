// Grid_CollectFootprintCells: ported from Pizza Connection 2 at 0x4f2b60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f2b60
#include "pc2_port.h"


uint32_t * __thiscall Grid_CollectFootprintCells(void *self,int arg1)

{
  int value1;
  void *this_00;
  int value2;
  int value3;
  int value4;
  uint32_t *this_01;
  int local_18;
  void *local_14;
  uint32_t local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a02b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_14 = operator_new(0x1c);
  this_01 = (uint32_t *)0x0;
  local_4 = 0;
  if (local_14 != (void *)0x0) {
    this_01 = List_Construct(local_14,0);
  }
  local_4 = 0xffffffff;
  value4 = *(int *)(arg1 + 0x1c);
  value1 = *(int *)(arg1 + 0x18);
  Grid_GetCell(self,value1,value4);
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(arg1 + 4),(int *)0x0);
  Object_GetPair68(this_00,&local_18,&local_10);
  if (local_18 == 2) {
    value2 = Grid_GetCell(self,value1,value4);
    List_Add(this_01,value2);
    value2 = Grid_GetCell(self,value1 + 1,value4);
    List_Add(this_01,value2);
    value4 = value4 + 1;
  }
  else {
    if (local_18 == 3) {
      value2 = Grid_GetCell(self,value1,value4);
      List_Add(this_01,value2);
      value2 = Grid_GetCell(self,value1 + 1,value4);
      List_Add(this_01,value2);
      value2 = Grid_GetCell(self,value1 + 1,value4 + 1);
      List_Add(this_01,value2);
      value2 = Grid_GetCell(self,value1,value4 + 1);
      List_Add(this_01,value2);
      value2 = Grid_GetCell(self,value1 + -1,value4 + 1);
      List_Add(this_01,value2);
      value2 = Grid_GetCell(self,value1 + -1,value4);
      List_Add(this_01,value2);
      value4 = value4 + -1;
      value2 = Grid_GetCell(self,value1 + -1,value4);
      List_Add(this_01,value2);
      value2 = Grid_GetCell(self,value1,value4);
      List_Add(this_01,value2);
      goto LAB_004f2e23;
    }
    if (local_18 != 4) {
      ExceptionList = local_c;
      return this_01;
    }
    value2 = Grid_GetCell(self,value1,value4);
    List_Add(this_01,value2);
    value2 = value1 + 1;
    value3 = Grid_GetCell(self,value2,value4);
    List_Add(this_01,value3);
    value3 = Grid_GetCell(self,value2,value4 + 1);
    List_Add(this_01,value3);
    value3 = Grid_GetCell(self,value1,value4 + 1);
    List_Add(this_01,value3);
    value3 = Grid_GetCell(self,value1 + -1,value4 + 1);
    List_Add(this_01,value3);
    value3 = Grid_GetCell(self,value1 + -1,value4);
    List_Add(this_01,value3);
    value3 = Grid_GetCell(self,value1 + -1,value4 + -1);
    List_Add(this_01,value3);
    value3 = Grid_GetCell(self,value1,value4 + -1);
    List_Add(this_01,value3);
    value2 = Grid_GetCell(self,value2,value4 + -1);
    List_Add(this_01,value2);
    value2 = Grid_GetCell(self,value1 + -2,value4 + 1);
    List_Add(this_01,value2);
    value2 = Grid_GetCell(self,value1 + -2,value4);
    List_Add(this_01,value2);
    value2 = Grid_GetCell(self,value1 + -2,value4 + -1);
    List_Add(this_01,value2);
    value4 = value4 + -2;
    value2 = Grid_GetCell(self,value1 + -2,value4);
    List_Add(this_01,value2);
    value2 = Grid_GetCell(self,value1 + -1,value4);
    List_Add(this_01,value2);
  }
  value2 = Grid_GetCell(self,value1,value4);
  List_Add(this_01,value2);
LAB_004f2e23:
  arg1 = value1 + 1;
  value4 = Grid_GetCell(self,arg1,value4);
  List_Add(this_01,value4);
  ExceptionList = local_c;
  return this_01;
}
