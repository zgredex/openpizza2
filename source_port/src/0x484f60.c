// SubMenu_InitSelectedPage: ported from Pizza Connection 2 at 0x484f60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x484f60
#include "pc2_port.h"

void * __fastcall SubMenu_InitSelectedPage(void *arg1)

{
  int value1;
  void *pvVar2;
  void *local_4;
  
                    /* Initializes the selected submenu page. */
  local_4 = arg1;
  if (*(int *)((intptr_t)arg1 + 0x268) != 0) {
    Game_CloseSelectionDialog((intptr_t)arg1);
  }
  switch(*(uint32_t *)((intptr_t)arg1 + *(int *)((intptr_t)arg1 + 0x290) * 4 + 0x298)) {
  case 1:
    break;
  case 2:
    pvVar2 = SubMenu_BuildSaveGame((int *)&local_4);
    LoadGameMenu_InitSlotList(pvVar2);
    *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
    return local_4;
  case 3:
    pvVar2 = SoundOptionsPage_Create((int *)&local_4);
    SoundOptions_Init(pvVar2);
    *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
    return local_4;
  case 4:
    pvVar2 = GraphicsOptionsPage_Create((int *)&local_4);
    *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
    return local_4;
  case 5:
    pvVar2 = GameOptionsPage_Create((int *)&local_4);
    *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
    return local_4;
  default:
    *(void **)((intptr_t)arg1 + 0x264) = local_4;
    return local_4;
  }
  value1 = SaveGame_AnyExist();
  if (value1 == 0) {
    Game_ShowConfirmationDialog
              (arg1,0xfffe7978,DAT_005825a4,DAT_00580bb4,*(uint32_t *)((intptr_t)arg1 + 0x25c));
    *(uint32_t *)((intptr_t)arg1 + 0x264) = *(uint32_t *)((intptr_t)arg1 + 0x268);
    return local_4;
  }
  pvVar2 = SubMenu_BuildLoadSavegame((int *)&local_4);
  SaveGameMenu_Init(pvVar2);
  *(void **)((intptr_t)arg1 + 0x264) = pvVar2;
  return local_4;
}
