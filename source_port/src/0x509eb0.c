// Person_BlocksFootprintPath: ported from Pizza Connection 2 at 0x509eb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509eb0
#include "pc2_port.h"

bool __thiscall Person_BlocksFootprintPath(void *self,void *arg1)

{
  uint8_t uvalue1;
  uint32_t extraout_var;
  int value2;
  int value3;
  int value4;
  bool flag5;
  
                    /* Tests whether a person blocks a footprint path. */
  if (*(int *)((intptr_t)self + 200) == 0) {
    return false;
  }
  uvalue1 = Object_IsVisibleThisFrame((intptr_t)self);
  if (CONCAT31(extraout_var,uvalue1) == 0) {
    return (bool)uvalue1;
  }
  value2 = Array_GetRandomRecord28(*(int *)((intptr_t)self + 0xc4));
  Map_DrawObjectList(*(void **)((intptr_t)self + 0xc4),1,arg1);
  value3 = Map_FindShortestPath();
  flag5 = value3 == 0;
  if (*(short *)(*(int *)((intptr_t)self + 200) + 0x28) != -1) {
    value4 = UI_RemoveLastChild((intptr_t)self);
    if (value4 != value2) {
      value3 = Map_FindShortestPath();
    }
    if (value3 == 0) {
      flag5 = true;
    }
  }
  Map_DrawObjectList(*(void **)((intptr_t)self + 0xc4),0,arg1);
  return flag5;
}
