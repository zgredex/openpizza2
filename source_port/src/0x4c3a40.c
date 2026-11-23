// PosterAdvertisingPage_Update: ported from Pizza Connection 2 at 0x4c3a40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c3a40
#include "pc2_port.h"


void __cdecl PosterAdvertisingPage_Update(void *arg1)

{
  void *self;
  uint32_t *uptr1;
  int value2;
  uint32_t uvalue3;
  uint8_t local_2c [32];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Refreshes the poster-advertising page. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558afb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  StringTable_SortIndexArray(&DAT_0057d740,&DAT_0057d8a8);
  value2 = *(int *)((intptr_t)DAT_0057c670 + 0x218);
  self = *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  DAT_0057da10 = Game_FindNearestObjectByPosition(self,value2);
  DAT_0057da18 = *(uint32_t *)(DAT_0057da10 + 0x3c);
  Gadget_SetText(arg1,0x1f44,DAT_0057da10 + 4);
  DAT_0057da14 = (void *)Game_FindPlanByTarget(self,value2);
  if (DAT_0057da14 == (void *)0x0) {
    uptr1 = operator_new(0x30);
    local_4 = 0;
    if (uptr1 == (uint32_t *)0x0) {
      DAT_0057da14 = (void *)0x0;
    }
    else {
      DAT_0057da14 = (void *)GamePlan_Construct(uptr1);
    }
    local_4 = 0xffffffff;
    Game_SetDifficulty(DAT_0057da14,3);
    *(uint32_t *)((intptr_t)DAT_0057da14 + 0x2c) = *(uint32_t *)(value2 + 0x24);
    *(uint32_t *)((intptr_t)DAT_0057da14 + 0xc) = *(uint32_t *)(DAT_0057da10 + 0x3c);
    Gadget_SetText(arg1,0x519,DAT_00582978);
  }
  Gadget_SetText(arg1,0x512,
                 *(uint32_t *)
                  (&DAT_00583504 + (&DAT_0057d8a8)[*(int *)((intptr_t)DAT_0057da14 + 0x10)] * 4));
  Window_GadgetNotify_Button_SetState(arg1,0x43a,*(uint32_t *)((intptr_t)DAT_0057da14 + 0x14) & 8);
  Window_GadgetNotify_Button_SetState(arg1,0x43b,*(uint32_t *)((intptr_t)DAT_0057da14 + 0x14) & 4);
  Window_GadgetNotify_Button_SetState(arg1,0x43c,*(uint32_t *)((intptr_t)DAT_0057da14 + 0x14) & 2);
  Window_GadgetNotify_Button_SetState(arg1,0x43d,*(uint32_t *)((intptr_t)DAT_0057da14 + 0x14) & 1);
  if (*(int *)((intptr_t)DAT_0057da14 + 0x18) == 0) {
    uvalue3 = DAT_00580f68;
  }
  else {
    DAT_0057da1c = Lookup_BytePlusOne(*(int *)((intptr_t)DAT_0057da14 + 0x18));
    uvalue3 = *(uint32_t *)(&DAT_00583540 + *(int *)((intptr_t)DAT_0057da14 + 0x18) * 4);
  }
  Gadget_SetText(arg1,0x514,uvalue3);
  if (*(int *)((intptr_t)DAT_0057da14 + 0x1c) == -1) {
    value2 = DAT_00582634;
  }
  else {
    value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)DAT_0057da14 + 0x1c));
    value2 = value2 + 8;
  }
  Gadget_SetText(arg1,0x517,value2);
  String_Format(local_2c,&DAT_005683a4,0xdac);
  Window_GadgetNotify_Text_SetText(arg1,0x51b,local_2c);
  GamePlan_UpdateEffectBars(arg1,(intptr_t)self);
  ExceptionList = local_c;
  return;
}
