// Game_EndOfHour: ported from Pizza Connection 2 at 0x486590.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x486590
#include "pc2_port.h"

void __fastcall Game_EndOfHour(void *arg1)

{
  char cVar1;
  int value2;
  void *pvVar3;
  uint32_t *uptr4;
  uint32_t *uptr5;
  uint32_t uvalue6;
  int value7;
  int value8;
  
                    /* Runs the end-of-hour simulation update. */
  uvalue6 = (uint32_t)*(uint8_t *)(*(int *)((intptr_t)arg1 + 0x94) + 7);
  cVar1 = *(char *)(*(int *)((intptr_t)arg1 + 0x94) + 8);
  Game_AcquireStateLock(arg1,0);
  value8 = 0;
  *(int *)(*(int *)((intptr_t)arg1 + 0x94) + 0xc) = *(int *)(*(int *)((intptr_t)arg1 + 0x94) + 0xc) + 1;
  value7 = *(int *)((intptr_t)arg1 + 0x34);
  if (0 < value7) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)arg1 + 0x20),value8,(int *)0x0);
      if (value2 != 0) {
        Rating_DecayAndUpdateIndicators(value2);
      }
      value8 = value8 + 1;
    } while (value8 < value7);
  }
  value7 = *(int *)((intptr_t)arg1 + 0x18);
  value8 = 0;
  if (0 < value7) {
    do {
      pvVar3 = (void *)IDMap_Lookup((void *)((intptr_t)arg1 + 4),value8,(int *)0x0);
      if (pvVar3 != (void *)0x0) {
        City_TickSimulation(pvVar3,uvalue6);
      }
      value8 = value8 + 1;
    } while (value8 < value7);
  }
  uptr4 = (uint32_t *)((intptr_t)arg1 + 0x224);
  value7 = 6;
  do {
    if ((void *)*uptr4 != (void *)0x0) {
      Player_MissionState_Tick((void *)*uptr4,uvalue6);
    }
    uptr4 = uptr4 + 1;
    value7 = value7 + -1;
  } while (value7 != 0);
  uptr4 = (uint32_t *)((intptr_t)arg1 + 0x200);
  value7 = 6;
  do {
    if ((void *)*uptr4 != (void *)0x0) {
      Company_ProcessHourlyTick((void *)*uptr4,uvalue6);
    }
    uptr4 = uptr4 + 1;
    value7 = value7 + -1;
  } while (value7 != 0);
  value7 = *(int *)((intptr_t)arg1 + 0x50);
  while (value7 = value7 + -1, -1 < value7) {
    uptr4 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x3c),value7,(int *)0x0);
    if ((uptr4 != (uint32_t *)0x0) && (value8 = Object_CanDetach(uptr4), value8 != 0)) {
      uptr5 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x20),uptr4[0x14],(int *)0x0);
      if (uptr5 != (uint32_t *)0x0) {
        IDMap_RemoveByKey((void *)((intptr_t)arg1 + 0x20),(intptr_t)uptr5);
        (**(code **)*uptr5)(1);
      }
      pvVar3 = (void *)IDMap_Lookup((void *)((intptr_t)arg1 + 4),*(int *)((intptr_t)arg1 + 0x2f4),
                                    (int *)0x0);
      Game_RemoveRecordFromAllLocalMaps(pvVar3,uptr4);
      IDMap_RemoveByKey((void *)((intptr_t)arg1 + 0x3c),(intptr_t)uptr4);
      uptr4[0x59] = 0xffffffff;
      if (*(uint32_t **)((intptr_t)arg1 + 0x21c) == uptr4) {
        *(uint32_t *)((intptr_t)arg1 + 0x21c) = 0;
        *(uint32_t *)((intptr_t)arg1 + 0x2da8) = 1;
        UI_QueueControlCommand(*(void **)((intptr_t)arg1 + 0x25c),-0x18624,0x23,0);
      }
      (**(code **)*uptr4)(1);
    }
  }
  Game_PurgeUnusedCompanyRecipes(*(int *)((intptr_t)arg1 + 0x90));
  if (uvalue6 == 0) {
    Game_EndOfQuarter(arg1,(char *)(uint32_t)(cVar1 == '\0'));
  }
  DebugConsole_Printf(DAT_0057c1e0,0xff,(uint8_t *)s_EndofHour__d___0056812c,uvalue6);
  if (*(void **)((intptr_t)arg1 + 0x264) != (void *)0x0) {
    UI_QueueControlCommand(*(void **)((intptr_t)arg1 + 0x264),-0x1863b,0x23,0);
  }
  if (*(void **)((intptr_t)arg1 + 0x25c) != (void *)0x0) {
    UI_QueueControlCommand(*(void **)((intptr_t)arg1 + 0x25c),-0x1863b,0x23,0);
  }
  if (uvalue6 % 3 == 0) {
    *(uint32_t *)((intptr_t)arg1 + 0x340) = 0;
  }
  Window_UnlockState((intptr_t)arg1);
  ThreadSync_Signal(*(int *)((intptr_t)arg1 + 0x94));
  return;
}
