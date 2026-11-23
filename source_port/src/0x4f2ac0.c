// Grid_CollectFootprintCellsAtCell: ported from Pizza Connection 2 at 0x4f2ac0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f2ac0
#include "pc2_port.h"


uint32_t * __thiscall
Grid_CollectFootprintCellsAtCell(void *self,int arg1,uint32_t arg2,uint32_t arg3)

{
  void *this_00;
  int value1;
  uint32_t *uptr2;
  uint32_t *uptr3;
  uint32_t uvalue4;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Collects footprint cells for a catalog object at a cell. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a00b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0x24);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    uptr2 = (uint32_t *)0x0;
  }
  else {
    uvalue4 = 0;
    value1 = Map_FindIndex((void *)(DAT_0057c670 + 0x74),arg1);
    uptr2 = (uint32_t *)ConstructionOrder_Construct(this_00,value1,uvalue4);
  }
  local_4 = 0xffffffff;
  uptr2[6] = arg2;
  uptr2[7] = arg3;
  uptr3 = Grid_CollectFootprintCells(self,(intptr_t)uptr2);
  if (uptr2 != (uint32_t *)0x0) {
    (**(code **)*uptr2)(1);
  }
  ExceptionList = local_c;
  return uptr3;
}
