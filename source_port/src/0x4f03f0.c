// Map_DrawTileCursorDiamond: ported from Pizza Connection 2 at 0x4f03f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f03f0
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
Map_DrawTileCursorDiamond
          (void *self,int arg1,int arg2,int arg3,int arg4,uint32_t arg5,
          uint32_t arg6)

{
  uint16_t uvalue1;
  uint32_t uvalue2;
  int value3;
  uint32_t *uptr4;
  tagRECT local_10;
  
  uvalue1 = Color_RGBTo16FromDword(*(void **)((intptr_t)self + 8),arg6);
  SetRect(&local_10,0,0,DAT_00571950,DAT_00571954);
  if ((DAT_005719b8 != 0xffffffff) && (arg4 == 0)) {
    Surface_SetPixel(*(int *)((intptr_t)self + 8),DAT_00580a40,DAT_00580a44 + -2,(short)DAT_005719b8);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),DAT_00580a40,DAT_00580a44 + -1,DAT_005719bc);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),DAT_00580a40 + 1,DAT_00580a44,DAT_005719c0);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),DAT_00580a40 + 2,DAT_00580a44,DAT_005719c4);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),DAT_00580a40,DAT_00580a44 + 1,DAT_005719c8);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),DAT_00580a40,DAT_00580a44 + 2,DAT_005719cc);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),DAT_00580a40 + -1,DAT_00580a44,DAT_005719d0);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),DAT_00580a40 + -2,DAT_00580a44,DAT_005719d4);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),DAT_00580a40 + 1,DAT_00580a44 + -1,DAT_005719d8);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),DAT_00580a40 + 1,DAT_00580a44 + 1,DAT_005719dc);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),DAT_00580a40 + -1,DAT_00580a44 + -1,DAT_005719e0);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),DAT_00580a40 + -1,DAT_00580a44 + 1,DAT_005719e4);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),DAT_00580a40,DAT_00580a44,DAT_005719e8);
  }
  if (arg3 == 0) {
    uvalue2 = Tilemap_GetCell(*(uint32_t *)((intptr_t)self + 8),arg1,arg2 + -2);
    DAT_005719b8 = uvalue2 & 0xffff;
    _DAT_005719bc = Tilemap_GetCell(*(uint32_t *)((intptr_t)self + 8),arg1,arg2 + -1);
    _DAT_005719bc = _DAT_005719bc & 0xffff;
    _DAT_005719c0 = Tilemap_GetCell(*(uint32_t *)((intptr_t)self + 8),arg1 + 1,arg2);
    _DAT_005719c0 = _DAT_005719c0 & 0xffff;
    _DAT_005719c4 = Tilemap_GetCell(*(uint32_t *)((intptr_t)self + 8),arg1 + 2,arg2);
    _DAT_005719c4 = _DAT_005719c4 & 0xffff;
    _DAT_005719c8 = Tilemap_GetCell(*(uint32_t *)((intptr_t)self + 8),arg1,arg2 + 1);
    _DAT_005719c8 = _DAT_005719c8 & 0xffff;
    _DAT_005719cc = Tilemap_GetCell(*(uint32_t *)((intptr_t)self + 8),arg1,arg2 + 2);
    _DAT_005719cc = _DAT_005719cc & 0xffff;
    _DAT_005719d0 = Tilemap_GetCell(*(uint32_t *)((intptr_t)self + 8),arg1 + -1,arg2);
    _DAT_005719d0 = _DAT_005719d0 & 0xffff;
    _DAT_005719d4 = Tilemap_GetCell(*(uint32_t *)((intptr_t)self + 8),arg1 + -2,arg2);
    _DAT_005719d4 = _DAT_005719d4 & 0xffff;
    _DAT_005719d8 = Tilemap_GetCell(*(uint32_t *)((intptr_t)self + 8),arg1 + 1,arg2 + -1);
    _DAT_005719d8 = _DAT_005719d8 & 0xffff;
    _DAT_005719dc = Tilemap_GetCell(*(uint32_t *)((intptr_t)self + 8),arg1 + 1,arg2 + 1);
    _DAT_005719dc = _DAT_005719dc & 0xffff;
    _DAT_005719e0 = Tilemap_GetCell(*(uint32_t *)((intptr_t)self + 8),arg1 + -1,arg2 + -1);
    _DAT_005719e0 = _DAT_005719e0 & 0xffff;
    _DAT_005719e4 = Tilemap_GetCell(*(uint32_t *)((intptr_t)self + 8),arg1 + -1,arg2 + 1);
    _DAT_005719e4 = _DAT_005719e4 & 0xffff;
    _DAT_005719e8 = Tilemap_GetCell(*(uint32_t *)((intptr_t)self + 8),arg1,arg2);
    _DAT_005719e8 = _DAT_005719e8 & 0xffff;
    Surface_SetPixel(*(int *)((intptr_t)self + 8),arg1,arg2 + -2,uvalue1);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),arg1,arg2 + -1,uvalue1);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),arg1 + 1,arg2,uvalue1);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),arg1 + 2,arg2,uvalue1);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),arg1,arg2 + 1,uvalue1);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),arg1,arg2 + 2,uvalue1);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),arg1 + -1,arg2,uvalue1);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),arg1 + -2,arg2,uvalue1);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),arg1 + 1,arg2 + -1,uvalue1);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),arg1 + 1,arg2 + 1,uvalue1);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),arg1 + -1,arg2 + -1,uvalue1);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),arg1 + -1,arg2 + 1,uvalue1);
    Surface_SetPixel(*(int *)((intptr_t)self + 8),arg1,arg2,uvalue1);
    if (arg4 == 0) {
      DAT_00580a40 = arg1;
      DAT_00580a44 = arg2;
      return;
    }
  }
  uptr4 = &DAT_005719b8;
  for (value3 = 0xd; value3 != 0; value3 = value3 + -1) {
    *uptr4 = 0xffffffff;
    uptr4 = uptr4 + 1;
  }
  DAT_00580a40 = arg1;
  DAT_00580a44 = arg2;
  return;
}
