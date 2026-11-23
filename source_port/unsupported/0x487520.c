// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x487520.c:32:3: error: use of undeclared identifier '_SYSTEMTIME'
// SaveGame_Write: ported from Pizza Connection 2 at 0x487520.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x487520
#include "pc2_port.h"

bool __thiscall SaveGame_Write(void *arg1,char *arg2,uint32_t arg3)

{
  char cVar1;
  HCURSOR pHVar2;
  DWORD DVar3;
  int value4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  int value7;
  char *cptr8;
  int *self;
  char *cptr9;
  bool flag10;
  uint32_t local_1c4;
  char *local_1c0;
  CHAR local_1bc [64];
  char local_17c [64];
  char local_13c [64];
  char local_fc [64];
  char local_bc;
  uint8_t auStack_bb [7];
  uint32_t local_b4;
  int local_b0;
  uint32_t local_ac;
  uint32_t local_a8;
  _SYSTEMTIME local_a4;
  uint32_t local_94;
  uint32_t local_90;
  CHAR local_8c [64];
  CHAR local_4c [64];
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055824c;
  pvStack_c = ExceptionList;
  value7 = 0;
  flag10 = *(int *)((intptr_t)arg1 + 0x1508) == 0;
  ExceptionList = &pvStack_c;
  if (flag10) {
    ExceptionList = &pvStack_c;
    Game_SuspendSimulation(arg1);
  }
  local_1c4 = (uint32_t)flag10;
  Game_AcquireStateLock(arg1,0);
  cptr8 = local_17c;
  for (value4 = 0x3c; value4 != 0; value4 = value4 + -1) {
    cptr8[0] = '\0';
    cptr8[1] = '\0';
    cptr8[2] = '\0';
    cptr8[3] = '\0';
    cptr8 = cptr8 + 4;
  }
  pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
  SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar2);
  PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar2);
  Game_GetDateFields(arg1,&local_b4,&local_b0);
  Game_GetYearAndWeekday(arg1,&local_ac,&local_a8);
  if (arg2 == (char *)0x0) {
    String_Format(local_1bc,(uint8_t *)s_save_games_auto__03d_piz_005681c0,arg3);
    GetDateFormatA(0x800,1,(SYSTEMTIME *)0x0,(LPCSTR)0x0,local_8c,0x40);
    GetTimeFormatA(0x800,2,(SYSTEMTIME *)0x0,(LPCSTR)0x0,local_4c,0x40);
    String_Format(local_17c,(uint8_t *)s_auto__s__s_005681b4,local_8c);
  }
  else {
    String_Format(local_1bc,(uint8_t *)s_save_games_save__03d_piz_00568198,arg3);
    uvalue5 = 0xffffffff;
    do {
      cptr8 = arg2;
      if (uvalue5 == 0) break;
      uvalue5 = uvalue5 - 1;
      cptr8 = arg2 + 1;
      cVar1 = *arg2;
      arg2 = cptr8;
    } while (cVar1 != '\0');
    uvalue5 = ~uvalue5;
    cptr8 = cptr8 + -uvalue5;
    cptr9 = local_17c;
    for (uvalue6 = uvalue5 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
      *(uint32_t *)cptr9 = *(uint32_t *)cptr8;
      cptr8 = cptr8 + 4;
      cptr9 = cptr9 + 4;
    }
    for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *cptr9 = *cptr8;
      cptr8 = cptr8 + 1;
      cptr9 = cptr9 + 1;
    }
  }
  local_bc = '\0';
  local_90 = 0x13738317;
  local_94 = 0x11;
  GetLocalTime(&local_a4);
  do {
    value4 = Game_GetPlayerBySlot(arg1,value7);
    if (value4 == 0) {
      auStack_bb[value7] = 0;
    }
    else {
      if (value4 == *(int *)((intptr_t)arg1 + *(int *)((intptr_t)arg1 + 0x2ec) * 4 + 0x200)) {
        uvalue5 = 0xffffffff;
        auStack_bb[value7] = 1;
        cptr8 = (char *)(value4 + 8);
        do {
          cptr9 = cptr8;
          if (uvalue5 == 0) break;
          uvalue5 = uvalue5 - 1;
          cptr9 = cptr8 + 1;
          cVar1 = *cptr8;
          cptr8 = cptr9;
        } while (cVar1 != '\0');
        uvalue5 = ~uvalue5;
        local_1c0 = local_13c;
        cptr8 = cptr9 + -uvalue5;
        cptr9 = local_1c0;
        for (uvalue6 = uvalue5 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
          *(uint32_t *)cptr9 = *(uint32_t *)cptr8;
          cptr8 = cptr8 + 4;
          cptr9 = cptr9 + 4;
        }
        for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
          *cptr9 = *cptr8;
          cptr8 = cptr8 + 1;
          cptr9 = cptr9 + 1;
        }
        value4 = Game_GetPlayerCity(value4);
        uvalue5 = 0xffffffff;
        cptr8 = (char *)(value4 + 0xc);
        do {
          cptr9 = cptr8;
          if (uvalue5 == 0) break;
          uvalue5 = uvalue5 - 1;
          cptr9 = cptr8 + 1;
          cVar1 = *cptr8;
          cptr8 = cptr9;
        } while (cVar1 != '\0');
        uvalue5 = ~uvalue5;
        cptr8 = cptr9 + -uvalue5;
        cptr9 = local_fc;
        for (uvalue6 = uvalue5 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
          *(uint32_t *)cptr9 = *(uint32_t *)cptr8;
          cptr8 = cptr8 + 4;
          cptr9 = cptr9 + 4;
        }
        for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
          *cptr9 = *cptr8;
          cptr8 = cptr8 + 1;
          cptr9 = cptr9 + 1;
        }
      }
      else {
        auStack_bb[value7] = 2;
      }
      local_bc = local_bc + '\x01';
    }
    value7 = value7 + 1;
  } while (value7 < 6);
  local_1c0 = operator_new(0x58);
  self = (int *)0x0;
  local_4 = 0;
  if (local_1c0 != (void *)0x0) {
    self = CRT_Ofstream_Construct();
  }
  local_4 = 0xffffffff;
  if ((*(uint8_t *)(*(int *)(*self + 4) + 8 + (intptr_t)self) & 6) != 0) {
    DVar3 = GetFileAttributesA(local_1bc);
    if ((DVar3 & 1) != 0) {
      if (self != (int *)0x0) {
        (*(code *)**(uint32_t **)(*(int *)(*self + 4) + (intptr_t)self))(1);
      }
      SetFileAttributesA(local_1bc,DVar3 & 0xfffffffe);
      local_1c0 = operator_new(0x58);
      local_4 = 1;
      if (local_1c0 == (void *)0x0) {
        self = (int *)0x0;
      }
      else {
        self = CRT_Ofstream_Construct();
      }
      local_4 = 0xffffffff;
    }
    if ((*(uint8_t *)(*(int *)(*self + 4) + 8 + (intptr_t)self) & 6) != 0) {
      pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
      SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar2);
      PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar2);
      Window_UnlockState((intptr_t)arg1);
      if (local_1c4 != 0) {
        Game_ResumeSimulation(arg1);
      }
      if (self != (int *)0x0) {
        (*(code *)**(uint32_t **)(*(int *)(*self + 4) + (intptr_t)self))(1);
      }
      goto LAB_0048791a;
    }
  }
  CRT_Ostream_Write(self,local_17c,0xf0);
  SaveGame_Serialize(arg1,self);
  if (self != (int *)0x0) {
    (*(code *)**(uint32_t **)(*(int *)(*self + 4) + (intptr_t)self))(1);
  }
  pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar2);
  PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar2);
  Window_UnlockState((intptr_t)arg1);
  if (local_1c4 != 0) {
    Game_ResumeSimulation(arg1);
  }
LAB_0048791a:
  ExceptionList = pvStack_c;
  return (uint8_t *)0xfffffe3b < &local_1c4;
}
