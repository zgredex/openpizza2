// City_OpenBuildingDirectory: ported from Pizza Connection 2 at 0x48a4c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48a4c0
#include "pc2_port.h"


void __fastcall City_OpenBuildingDirectory(void *arg1)

{
  void *pvVar1;
  uint32_t *uptr2;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Opens a sorted directory of the player's city buildings. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005583ab;
  local_c = ExceptionList;
  if (*(int *)((intptr_t)arg1 + 0x290) != 4) {
    ExceptionList = &local_c;
    *(uint32_t *)((intptr_t)arg1 + 0x21c) = 0;
    *(uint32_t *)((intptr_t)arg1 + 0x2da8) = 1;
    pvVar1 = operator_new(0x1c);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      uptr2 = (uint32_t *)0x0;
    }
    else {
      uptr2 = List_Construct(pvVar1,0);
    }
    local_4 = 0xffffffff;
    pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)arg1 + 4),*(int *)((intptr_t)arg1 + 0x2f4),
                                  (int *)0x0);
    if (pvVar1 != (void *)0x0) {
      City_BuildObjectListEntries(pvVar1,uptr2);
      CRT_QSort((int *)uptr2[1],(uint32_t *)uptr2[5],4,&LAB_0048a490);
      UI_ShowScrollingListDialog(arg1,0xfffe79d4,DAT_00581b70,DAT_00580f08,(intptr_t)uptr2,-1,0);
      *(uint32_t *)((intptr_t)arg1 + 0x278) = 0;
    }
  }
  ExceptionList = local_c;
  return;
}
