// Object_AttachToParent: ported from Pizza Connection 2 at 0x50e730.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e730
#include "pc2_port.h"

void __thiscall Object_AttachToParent(void *self,void *arg1,int arg2)

{
  void *this_00;
  int value1;
  
  if (*(void **)((intptr_t)self + 0xfc) != (void *)0x0) {
    Game_RemoveObjectFromList(*(void **)((intptr_t)self + 0xfc),self,0);
  }
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  this_00 = *(void **)(value1 + 0xfa8);
  Object_SetFieldFC(self,arg1);
  if (arg2 != 0) {
    Game_AddObjectToList(arg1,self);
  }
  value1 = Array_GetRecord28(this_00,1,*(int *)((intptr_t)arg1 + 0x54));
  UI_SetChildTracking(self,0,value1);
  return;
}
