// Person_BlocksFootprintCells: ported from Pizza Connection 2 at 0x509cf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509cf0
#include "pc2_port.h"

bool __thiscall Person_BlocksFootprintCells(void *self,void *arg1)

{
  uint8_t uvalue1;
  uint32_t extraout_var;
  int value2;
  int value3;
  int value4;
  
                    /* Tests whether a person blocks a footprint cell list. */
  value4 = 0;
  if (*(int *)((intptr_t)self + 200) == 0) {
    return false;
  }
  uvalue1 = Object_IsVisibleThisFrame((intptr_t)self);
  if (CONCAT31(extraout_var,uvalue1) == 0) {
    return (bool)uvalue1;
  }
  if (*(short *)(*(int *)((intptr_t)self + 200) + 0x28) == -1) {
    return false;
  }
  value2 = UI_RemoveLastChild((intptr_t)self);
  if (0 < *(int *)((intptr_t)arg1 + 0x14)) {
    do {
      value3 = IDMap_Lookup(arg1,value4,(int *)0x0);
      value3 = Array_GetRecord28(*(void **)((intptr_t)self + 0xc4),1,
                                (intptr_t)*(short *)(*(int *)(value3 + 8) + 0x24));
      if (value3 == value2) {
        return true;
      }
      value4 = value4 + 1;
    } while (value4 < *(int *)((intptr_t)arg1 + 0x14));
  }
  Object_ResetLinkVisitedFlags(*(void **)((intptr_t)self + 0xc4));
  Map_DrawObjectList(*(void **)((intptr_t)self + 0xc4),1,arg1);
  value4 = Map_FindShortestPath();
  Map_DrawObjectList(*(void **)((intptr_t)self + 0xc4),0,arg1);
  Object_ClearRecordFirstBytes(*(void **)((intptr_t)self + 0xc4),(int *)0x1);
  return value4 == 0;
}
