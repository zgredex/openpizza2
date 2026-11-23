// SaveGame_LoadFromFile: ported from Pizza Connection 2 at 0x4a0b80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a0b80
#include "pc2_port.h"

uint32_t SaveGame_LoadFromFile(void)

{
  HCURSOR pHVar1;
  void *pvVar2;
  int value3;
  int *self;
  uint32_t local_100;
  uint8_t local_fc [240];
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Loads a save slot through the loading screen and state lock. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055882e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  UI_ShowLoadingOverlay(0);
  pHVar1 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
  SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar1);
  PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar1);
  pvVar2 = operator_new(0x5c);
  self = (int *)0x0;
  local_4 = 0;
  if (pvVar2 != (void *)0x0) {
    self = CRT_Ifstream_Construct();
  }
  local_4 = 0xffffffff;
  if ((*(uint8_t *)(*(int *)(*self + 4) + 8 + (intptr_t)self) & 6) == 0) {
    DAT_0057cdac = 0;
    Sound_StopCurrentBuffer(DAT_0057ba0c);
    CRT_Istream_Read(self,local_fc,0xf0);
    Game_AcquireStateLock(DAT_0057c670,1);
    UI_ResetScrollPosition(DAT_0057c5e0);
    CS_Enter(*(int *)((intptr_t)DAT_0057c670 + 0x240));
    value3 = Game_LoadSaveGame(DAT_0057c670,self,&DAT_0057cdac);
    if ((value3 == 0) || ((*(uint8_t *)(*(int *)(*self + 4) + 8 + (intptr_t)self) & 6) != 0)) {
      local_100 = 0;
      Game_ShutdownWorld((intptr_t)DAT_0057c670);
    }
    else {
      local_100 = 1;
    }
    CS_Leave(*(int *)((intptr_t)DAT_0057c670 + 0x240));
    *(uint32_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 0x14) = 0xc35;
    Window_UnlockState((intptr_t)DAT_0057c670);
    if (self != (int *)0x0) {
      (*(code *)**(uint32_t **)(*(int *)(*self + 4) + (intptr_t)self))(1);
    }
    pHVar1 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar1);
    PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar1);
    UI_CloseLoadingScreen();
  }
  else {
    pHVar1 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar1);
    PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar1);
    if (self != (int *)0x0) {
      (*(code *)**(uint32_t **)(*(int *)(*self + 4) + (intptr_t)self))(1);
    }
    UI_CloseLoadingScreen();
    local_100 = 0;
  }
  ExceptionList = pvStack_c;
  return local_100;
}
