// Game_SelectFoundObject: ported from Pizza Connection 2 at 0x48bdd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48bdd0
#include "pc2_port.h"

void __thiscall Game_SelectFoundObject(void *self,void *arg1)

{
  void *this_00;
  int value1;
  
                    /* Applies a selection from the object-list/search dialog. */
  value1 = *(int *)((intptr_t)arg1 + 0x30);
  if ((((value1 == 0x1d) || (value1 == 0x1e)) || (value1 == 0x1f)) &&
     (*(int *)((intptr_t)arg1 + 0x110) == -1)) {
    this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
    value1 = Map_GetRandomBuildingOfType(this_00,0x17,0,'\0');
    Game_SelectBuilding(value1,0);
    return;
  }
  if (value1 == 0xc) {
    SubMenu_SetSelection(self,*(int *)((intptr_t)arg1 + 0xcc),0,0,0);
    Object_ScrollViewToObject(arg1);
    *(void **)((intptr_t)self + 0x21c) = arg1;
    *(uint32_t *)((intptr_t)self + 0x2da8) = 1;
    Sound_ProcessEvent(DAT_0057ba0c,*(int *)((intptr_t)arg1 + 0x30),0,
                       *(int *)((intptr_t)arg1 + 0x24) == 0);
    return;
  }
  if ((value1 == 0x10) &&
     (*(int *)(*(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x2ec) * 4 + 0x200) + 0x15c) == 0)) {
    Game_ShowConfirmationDialog(self,0xfffe79af,DAT_005825a4,DAT_0058191c,0);
    return;
  }
  if (*(int *)((intptr_t)arg1 + 0x108) == 1) {
    Game_ShowConfirmationDialog(self,0xfffe79af,DAT_005825a4,DAT_00580e84,0);
    return;
  }
  SubMenu_SetSelection(self,0,(intptr_t)arg1,0,0);
  return;
}
