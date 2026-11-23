// Branch_UpdateConstruction: ported from Pizza Connection 2 at 0x506d60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x506d60
#include "pc2_port.h"

void __thiscall Branch_UpdateConstruction(void *self,int arg1)

{
  uint8_t uvalue1;
  void *this_00;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  int *ptr2;
  int value3;
  char cVar4;
  int value5;
  int64_t lvalue6;
  
                    /* Advances branch construction and completion stages. */
  this_00 = (void *)Game_GetPlayerSubmapValue
                              (DAT_0057c670,*(int *)(*(int *)((intptr_t)self + 0xf4) + 8),
                               *(int *)(*(int *)((intptr_t)self + 0xf4) + 0x2c));
  if ((arg1 % 10 == 0) && (0 < *(int *)((intptr_t)self + 0x44))) {
    *(int *)((intptr_t)self + 0x44) = *(int *)((intptr_t)self + 0x44) + -1;
  }
  value5 = *(int *)((intptr_t)self + 0x30);
  if ((((-1 < value5) && (value5 < 8)) || (value5 == 0xb)) || ((value5 == 0xf || (value5 == 0x21)))) {
    switch(*(uint16_t *)((intptr_t)self + 0x40)) {
    case 2:
      if (*(int *)((intptr_t)self + 0x44) == 0) {
        UI_SetChildState(self,3);
        *(short *)((intptr_t)this_00 + 0x16d2) = *(short *)((intptr_t)this_00 + 0x16d2) + 1;
        Game_GetTimeByMode(self,7);
        Object_SetState(self,9);
        UI_DetachChildRecord((intptr_t)self);
        Object_SyncChildState(self,(intptr_t)this_00,0x14);
        *(uint32_t *)((intptr_t)self + *(int *)((intptr_t)this_00 + 0x30) * 4 + 0xac) = 0x14;
        value5 = *(int *)((intptr_t)this_00 + 0x30);
        value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
        if (value5 == value3) {
          UI_AppendCommandIfActive(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x23,1);
          BuildingProject_AdvanceStep
                    (*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x23,0x14);
          return;
        }
      }
      else {
        lvalue6 = Math_RoundFloat((float)*(int *)((intptr_t)self + 0x44) /
                                ((float)*(int *)((intptr_t)self + 0x48) * 0.0625));
        value5 = 0x4f - (intptr_t)lvalue6;
        if (0x4e < value5) {
          value5 = 0x4e;
        }
        Object_SetChildShort8(self,value5);
        uvalue1 = Game_GetHourlyValue(this_00,0x28);
        if (CONCAT31(extraout_var,uvalue1) == 0) {
          UI_DetachChildRecord((intptr_t)self);
          Object_SetState(self,9);
          UI_SetChildState(self,0xffff);
          return;
        }
      }
      break;
    case 3:
    case 8:
    case 0xb:
      if (*(int *)((intptr_t)self + 0x44) == 0) {
        UI_SetChildState(self,0xffff);
        return;
      }
      break;
    case 5:
      if (*(int *)((intptr_t)self + 0x44) == 0) {
        UI_SetChildState(self,6);
        *(short *)((intptr_t)this_00 + 0x16d2) = *(short *)((intptr_t)this_00 + 0x16d2) + 1;
        UI_DetachChildRecord((intptr_t)self);
        Game_GetTimeByMode(self,7);
        Object_SetState(self,9);
        Object_SyncChildState(self,(intptr_t)this_00,0x14);
        *(uint32_t *)((intptr_t)self + *(int *)((intptr_t)this_00 + 0x30) * 4 + 0xac) = 0x14;
        value5 = *(int *)((intptr_t)this_00 + 0x30);
        value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
        if (value5 == value3) {
          UI_AppendCommandIfActive(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x23,1);
          BuildingProject_AdvanceStep
                    (*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x23,0x14);
          return;
        }
      }
      else {
        lvalue6 = Math_RoundFloat((float)*(int *)((intptr_t)self + 0x44) /
                                ((float)*(int *)((intptr_t)self + 0x48) * 0.0625));
        value5 = 0x60 - (intptr_t)lvalue6;
        if (0x5f < value5) {
          value5 = 0x5f;
        }
        Object_SetChildShort8(self,value5);
        uvalue1 = Game_GetHourlyValue(this_00,0xf);
        if (CONCAT31(extraout_var_00,uvalue1) == 0) {
          UI_DetachChildRecord((intptr_t)self);
          UI_SetChildState(self,0xffff);
          Object_SetState(self,9);
          return;
        }
      }
      break;
    case 9:
      if (*(int *)((intptr_t)self + 0x44) == 0) {
        ptr2 = (int *)Game_ApplyObjectEvent((intptr_t)self);
        if ((*(int *)((intptr_t)self + 0x30) == 0xb) &&
           (value5 = *(int *)((intptr_t)self + 0x98), value3 = Game_GetDateField0C((intptr_t)DAT_0057c670),
           value3 - value5 < 0x18)) {
          Object_SetState(self,0xd);
          UI_DetachChildRecord((intptr_t)self);
          UI_SetChildState(self,2);
          Game_GetTimeByMode(self,3);
          UI_SetChildRecordVariant(self,*(int *)((intptr_t)self + 0x84) + 0x10);
          return;
        }
        Object_SetState(self,9);
        UI_DetachChildRecord((intptr_t)self);
        UI_SetChildState(self,8);
        Game_GetTimeByMode(self,5);
      }
      else {
        lvalue6 = Math_RoundFloat((float)*(int *)((intptr_t)self + 0x44) /
                                ((float)*(int *)((intptr_t)self + 0x48) * 0.11111111));
        value5 = 9 - (intptr_t)lvalue6;
        if (8 < value5) {
          value5 = 8;
        }
        ptr2 = (int *)Map_GetObjectNeighborCell
                                  (*(void **)((intptr_t)self + 0xc4),*(int *)((intptr_t)self + 200),
                                   *(int *)((intptr_t)self + 0x88));
        cVar4 = (char)value5;
        switch(*(uint32_t *)(*(int *)((intptr_t)self + 200) + 0xc)) {
        case 0x14:
          *(char *)(ptr2[2] + 0x2c) = cVar4 + '(';
          break;
        case 0x15:
          *(char *)(ptr2[2] + 0x2d) = cVar4 + '\x1e';
          break;
        case 0x16:
          *(char *)(ptr2[2] + 0x2e) = cVar4 + '\x14';
          break;
        case 0x17:
          *(char *)(ptr2[2] + 0x2f) = cVar4 + '\n';
        }
      }
      if (ptr2 != (int *)0x0) {
        UI_DrawCenteredSelectionRect(*(void **)((intptr_t)self + 0xc4),ptr2);
      }
    }
  }
  return;
}
