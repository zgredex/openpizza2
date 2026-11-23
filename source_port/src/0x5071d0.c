// Person_UpdateWaitAndHunger: ported from Pizza Connection 2 at 0x5071d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5071d0
#include "pc2_port.h"

void __fastcall Person_UpdateWaitAndHunger(void *arg1)

{
  void *self;
  uint32_t uvalue1;
  int value2;
  uint32_t unaff_EDI;
  int64_t lvalue3;
  char *cptr4;
  
                    /* Ticks a person's wait timer and idle/hunger behavior. */
  if (0 < *(int *)((intptr_t)arg1 + 0x44)) {
    *(int *)((intptr_t)arg1 + 0x44) = *(int *)((intptr_t)arg1 + 0x44) + -1;
  }
  if (*(void **)(DAT_0057c670 + 0x21c) == arg1) {
    if (*(int *)((intptr_t)arg1 + 0xfc) == 0) {
      DebugConsole_Printf(DAT_0057c1e0,0,(uint8_t *)s_C__d__In__d__St__d__NULL_00572f80,
                          *(uint32_t *)((intptr_t)arg1 + 0x44));
    }
    else {
      DebugConsole_Printf(DAT_0057c1e0,0,(uint8_t *)s_C__d__In__d__St__d___s_00572f68,
                          *(uint32_t *)((intptr_t)arg1 + 0x44));
    }
  }
  value2 = *(int *)((intptr_t)arg1 + 0x30);
  if (value2 == 0xf) {
    return;
  }
  if (value2 == 0x21) {
    return;
  }
  if (value2 == 0xb) {
    return;
  }
  switch(*(uint16_t *)((intptr_t)arg1 + 0x40)) {
  case 0:
    if (*(int *)((intptr_t)arg1 + 0x44) != 0) {
      lvalue3 = Math_RoundFloat((float)*(int *)((intptr_t)arg1 + 0x44) /
                              ((float)*(int *)((intptr_t)arg1 + 0x48) * 0.0625));
      value2 = 0x29 - (intptr_t)lvalue3;
      if (0x28 < value2) {
        value2 = 0x28;
      }
      Object_SetChildShort8(arg1,value2);
      return;
    }
    Game_GetTimeByMode(arg1,2);
    UI_SetChildState(arg1,1);
    *(uint32_t *)((intptr_t)arg1 + 0x4c) = 0;
    *(uint32_t *)((intptr_t)arg1 + 0x54) = 0;
    if (*(void **)(DAT_0057c670 + 0x21c) == arg1) {
      DebugConsole_Printf(DAT_0057c1e0,0,(uint8_t *)s_Bricht_Suche_ab__00572f54,unaff_EDI);
    }
    uvalue1 = Game_GetTimeSegment(DAT_0057c670);
    value2 = Person_SelectRouteStopForTimeSlot(arg1,uvalue1);
    if (value2 == 0) {
      Person_ReturnToHomeBase(arg1);
      return;
    }
    break;
  case 1:
    if (*(int *)((intptr_t)arg1 + 0x44) == 0) {
      UI_SetChildState(arg1,0xffff);
      Game_GetTimeByMode(arg1,0);
      return;
    }
    break;
  case 0x11:
    if (*(int *)((intptr_t)arg1 + 0x44) == 0) {
      Game_GetTimeByMode(arg1,9);
      UI_SetChildState(arg1,0x16);
      *(uint32_t *)((intptr_t)arg1 + 0x4c) = 0;
      *(uint32_t *)((intptr_t)arg1 + 0x54) = 0;
      if (*(void **)((intptr_t)arg1 + 0xfc) != (void *)0x0) {
        Map_SetObjectMode(*(void **)((intptr_t)arg1 + 0xfc),*(void **)((intptr_t)arg1 + 0xc4),0x10);
        return;
      }
    }
    else {
      lvalue3 = Math_RoundFloat((float)*(int *)((intptr_t)arg1 + 0x44) /
                              ((float)*(int *)((intptr_t)arg1 + 0x48) * 0.0625));
      value2 = 0x10 - (intptr_t)lvalue3;
      if (0xf < value2) {
        value2 = 0xf;
      }
      if (*(void **)((intptr_t)arg1 + 0xfc) != (void *)0x0) {
        Map_SetObjectMode(*(void **)((intptr_t)arg1 + 0xfc),*(void **)((intptr_t)arg1 + 0xc4),
                          (char)value2);
        return;
      }
    }
    break;
  case 0x16:
    if (*(int *)((intptr_t)arg1 + 0x44) == 0) {
      UI_SetChildState(arg1,0xffff);
      Object_SetState(arg1,4);
      Game_GetTimeByMode(arg1,0);
      if (*(void **)((intptr_t)arg1 + 0xfc) != (void *)0x0) {
        Map_ClearObjectFlags(*(void **)((intptr_t)arg1 + 0xfc),*(void **)((intptr_t)arg1 + 0xc4),1);
        return;
      }
    }
    break;
  case 0xffff:
    if (*(int *)((intptr_t)arg1 + 0x44) != 0) {
      return;
    }
    if (*(int *)((intptr_t)arg1 + 0x38) == 4) {
      self = *(void **)((intptr_t)arg1 + 0xfc);
      if ((self == (void *)0x0) ||
         ((*(int *)((intptr_t)self + 4) != 0 && (*(int *)((intptr_t)self + 4) != 7)))) {
LAB_005074b2:
        Object_Deactivate(arg1,*(void **)((intptr_t)arg1 + 0xfc));
        goto LAB_005074c0;
      }
      uvalue1 = Random_RangeFast(1,100);
      value2 = *(int *)((intptr_t)arg1 + 0x30);
      if ((value2 == 0xf) || (((value2 == 0xb || (value2 == 0x21)) || ((intptr_t)uvalue1 < 0x33))))
      goto LAB_005074b2;
      Map_SetObjectFlags(self,*(void **)((intptr_t)arg1 + 0xc4),1);
      Object_SetState(arg1,0x1a);
      UI_SetChildState(arg1,0x11);
      Game_GetTimeByMode(arg1,8);
      if (*(void **)(DAT_0057c670 + 0x21c) != arg1) {
        return;
      }
      cptr4 = s_Bestellt_telefonisch_Pizza__00572f38;
    }
    else {
LAB_005074c0:
      UI_SetChildState(arg1,0);
      Game_GetTimeByMode(arg1,1);
      *(uint32_t *)((intptr_t)arg1 + 0x4c) = 1;
      Object_SetState(arg1,1);
      List_Node_Reset((intptr_t)arg1 + 0x130);
      if (*(void **)(DAT_0057c670 + 0x21c) != arg1) {
        return;
      }
      cptr4 = s_Sucht_Pizzeria__00572f28;
    }
    DebugConsole_Printf(DAT_0057c1e0,0,(uint8_t *)cptr4,unaff_EDI);
  }
  return;
}
