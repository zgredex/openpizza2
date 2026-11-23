// MapObjectList_Load: ported from Pizza Connection 2 at 0x4d6cb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d6cb0
#include "pc2_port.h"


void __thiscall MapObjectList_Load(void *self,int *arg1)

{
  uint32_t uvalue1;
  int *this_00;
  uint32_t uvalue2;
  uint32_t *uptr3;
  int value4;
  int local_20;
  int local_1c;
  int local_18;
  uint32_t local_14;
  uint32_t *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  this_00 = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005590a6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CRT_Istream_Read(arg1,&arg1,4);
  uvalue2 = Game_UpdateIDMapEntry(DAT_0057c5cc,(intptr_t)arg1);
  *(uint32_t *)((intptr_t)self + 0xfa8) = uvalue2;
  CRT_Istream_Read(this_00,(intptr_t)self + 0xc1c,4);
  uvalue1 = (intptr_t)self + 4;
  CRT_Istream_Read(this_00,uvalue1,0x20);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x44,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xc20,0x18);
  CRT_Istream_Read(this_00,&local_1c,4);
  if (local_1c != 0xc18) {
    uptr3 = (uint32_t *)(-(uint32_t)(self != (void *)0x0) & uvalue1);
    for (value4 = 0x306; value4 != 0; value4 = value4 + -1) {
      *uptr3 = 0;
      uptr3 = uptr3 + 1;
    }
  }
  CRT_Istream_Read(this_00,-(uint32_t)(self != (void *)0x0) & uvalue1,local_1c);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xdac,0x18);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xdc4,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xdc8,0x1e0);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xc38,0x60);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xc98,0x18);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xcc8,0x18);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xd40,0x18);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xd58,0x30);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xd88,0x24);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xce0,0x60);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xcb0,0x18);
  CRT_Istream_Read(this_00,(intptr_t)self + 0xfe4,0xc0);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x10ac,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x10b0,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x10b4,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x10b8,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x10c4,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x10d0,0x78);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x10c0,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x10bc,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x10cc,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x10c8,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1148,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x114c,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1150,4);
  CRT_Istream_Read(this_00,(intptr_t)self + 0x1154,4);
  CRT_Istream_Read(this_00,&arg1,4);
  value4 = 0;
  if (0 < (intptr_t)arg1) {
    do {
      local_10 = operator_new(0x9c);
      local_4 = 0;
      if (local_10 == (uint32_t *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = MapObject_Construct(local_10,this_00);
      }
      local_4 = 0xffffffff;
      List_Add((void *)((intptr_t)self + 0xfac),uptr3);
      value4 = value4 + 1;
    } while (value4 < (intptr_t)arg1);
  }
  CRT_Istream_Read(this_00,&local_20,4);
  if ((local_20 < 0) || (10000 < local_20)) {
    value4 = *(int *)(*this_00 + 4);
    if (*(int *)((intptr_t)this_00 + value4 + 0x34) < 0) {
      CS_EnterRaw((LPCRITICAL_SECTION)((intptr_t)this_00 + value4 + 0x38));
    }
    *(uint32_t *)((intptr_t)this_00 + value4 + 8) = 4;
    if (*(int *)((intptr_t)this_00 + value4 + 0x34) < 0) {
      CS_LeaveRaw((LPCRITICAL_SECTION)((intptr_t)this_00 + value4 + 0x38));
    }
  }
  else {
    arg1 = (int *)0x0;
    if (0 < local_20) {
      do {
        CRT_Istream_Read(this_00,&local_14,4);
        CRT_Istream_Read(this_00,&local_18,4);
        uptr3 = operator_new(8);
        local_4 = 1;
        local_10 = uptr3;
        if (uptr3 == (uint32_t *)0x0) {
          uptr3 = (uint32_t *)0x0;
        }
        else {
          uvalue2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),local_18,(int *)0x0);
          *uptr3 = uvalue2;
          uptr3[1] = local_14;
        }
        local_4 = 0xffffffff;
        List_Add((void *)((intptr_t)self + 0xfc8),uptr3);
        arg1 = (int *)((intptr_t)arg1 + 1);
      } while ((intptr_t)arg1 < local_20);
    }
    CRT_Istream_Read(this_00,(intptr_t)self + 0x10a4,4);
    Map_BuildOccupiedCellList(self);
    Map_LoadMapSprite((intptr_t)self);
  }
  ExceptionList = local_c;
  return;
}
