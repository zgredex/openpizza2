// Person_SelectFacingTarget: ported from Pizza Connection 2 at 0x50cdc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50cdc0
#include "pc2_port.h"

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x01040404) */

int __thiscall Person_SelectFacingTarget(void *self,void *arg1)

{
  bool flag1;
  char cVar2;
  void *this_00;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  uint32_t extraout_var_01;
  uint32_t extraout_var_02;
  int value3;
  void *pvVar4;
  uint32_t extraout_var_03;
  int value5;
  uint32_t uvalue6;
  int value7;
  int local_10;
  uint32_t local_c;
  int local_8;
  void *local_4;
  
                    /* Selects and links a facing target. */
  value7 = -1;
  local_4 = *(void **)((intptr_t)arg1 + 0x16f0);
  if (local_4 != (void *)0x0) {
    local_8 = *(int *)((intptr_t)self + 0x84);
    local_10 = 0;
    pvVar4 = arg1;
    if (0 < *(int *)((intptr_t)local_4 + 0x8c)) {
      do {
        this_00 = (void *)Game_MapRecordToGlobal(local_4,local_10);
        value5 = *(int *)((intptr_t)this_00 + 0xa4);
        if ((((value5 != -1) && (*(int *)((intptr_t)this_00 + 0x38) != 0x2d)) &&
            (*(int *)((intptr_t)this_00 + 0x38) != 0x2e)) &&
           ((*(int *)((intptr_t)this_00 + 0x30) != 0x1d || ((value5 != 0x1a && (value5 != 0x19)))))) {
          switch(*(int *)((intptr_t)this_00 + 0x30)) {
          case 0x16:
            if ((*(int *)((intptr_t)self + 0xa4) != 0x16) &&
               (flag1 = MapObject_IsFacingTarget(this_00,arg1,self),
               CONCAT31(extraout_var,flag1) != 0)) {
              if (*(int *)((intptr_t)this_00 + 0xa4) == 1) {
                if (value7 < 1) {
                  pvVar4 = *(void **)((intptr_t)this_00 + 0x164);
                  value7 = 1;
                }
              }
              else if (value7 < 2) {
                pvVar4 = *(void **)((intptr_t)this_00 + 0x164);
                value7 = 2;
              }
            }
            break;
          case 0x1d:
            flag1 = MapObject_IsFacingTarget(this_00,arg1,self);
            if (CONCAT31(extraout_var_02,flag1) != 0) {
              if (*(int *)((intptr_t)this_00 + 0xa4) == 0xe) {
                if (value7 < 5) {
                  pvVar4 = *(void **)((intptr_t)this_00 + 0x164);
                  value7 = 5;
                }
              }
              else if (value7 < 6) {
                pvVar4 = *(void **)((intptr_t)this_00 + 0x164);
                value7 = 6;
              }
            }
            break;
          case 0x1e:
            flag1 = MapObject_IsFacingTarget(this_00,arg1,self);
            if ((CONCAT31(extraout_var_01,flag1) != 0) && (value7 < 4)) {
              pvVar4 = *(void **)((intptr_t)this_00 + 0x164);
              value7 = 4;
            }
            break;
          case 0x1f:
            if (((*(int *)((intptr_t)self + 0xa4) != 0x16) &&
                (flag1 = MapObject_IsFacingTarget(this_00,arg1,self),
                CONCAT31(extraout_var_00,flag1) != 0)) && (value7 < 3)) {
              pvVar4 = *(void **)((intptr_t)this_00 + 0x164);
              value7 = 3;
            }
          }
        }
        local_10 = local_10 + 1;
      } while (local_10 < *(int *)((intptr_t)local_4 + 0x8c));
    }
    if (local_8 < value7) {
      *(void **)((intptr_t)self + 0x8c) = pvVar4;
      *(int *)((intptr_t)self + 0x84) = value7;
      switch(value7) {
      case 1:
      case 2:
      case 3:
      case 4:
        value5 = Person_FindFreeNeighborCell(self,arg1,(intptr_t)pvVar4,&local_c);
        value3 = UI_RemoveLastChild((intptr_t)self);
        if (value3 != value5) {
          *(uint32_t *)((intptr_t)self + 0x88) = local_c;
          Object_SetState(self,0x28);
          Person_AdvanceRoute(self,value5);
          return value7;
        }
        break;
      case 5:
      case 6:
        pvVar4 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),(intptr_t)pvVar4,(int *)0x0);
        Object_SetState(self,0x2c);
        *(uint32_t *)((intptr_t)pvVar4 + 0x8c) = *(uint32_t *)((intptr_t)self + 0x164);
        Object_SetState(pvVar4,0x2c);
        Branch_InitCityObjects(arg1,0x1e);
        if (*(int *)((intptr_t)pvVar4 + 0x110) != -1) {
          value7 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)pvVar4 + 0x110));
          *(int *)(value7 + 0x78) = *(int *)(value7 + 0x78) + 1;
          return -1;
        }
      }
    }
    else if (local_8 != -1) {
      value7 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),*(int *)((intptr_t)self + 0x8c),(int *)0x0)
      ;
      if (((value7 == 0) || (*(int *)(value7 + 200) == 0)) ||
         (value7 = State_Is2DOr2E(value7), value7 != 0)) {
        *(uint32_t *)((intptr_t)self + 0x84) = 0xffffffff;
        return -1;
      }
      if (0 < local_8) {
        if (local_8 < 4) {
          value7 = Person_ApplyAttackOutcome(self,arg1,*(int *)((intptr_t)self + 0x8c));
          if (value7 != 0) {
LAB_0050d132:
            if (*(int *)((intptr_t)self + 200) == 0) {
              uvalue6 = 0xffffffff;
            }
            else {
              uvalue6 = *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0xc);
            }
            *(uint32_t *)((intptr_t)self + 0x88) = uvalue6;
            Person_TruncatePathToCurrentStep((intptr_t)self);
            *(uint32_t *)((intptr_t)self + 0x84) = 0xffffffff;
            Object_SetState(self,8);
            return -1;
          }
          value7 = Person_FindFreeNeighborCell(self,arg1,*(int *)((intptr_t)self + 0x8c),&local_c);
          value5 = UI_RemoveLastChild((intptr_t)self);
          if (value5 != value7) {
            Person_AdvanceRoute(self,value7);
            return local_8;
          }
        }
        else if (local_8 == 4) {
          cVar2 = Person_ResolveGroupFight(self,arg1,*(int *)((intptr_t)self + 0x8c));
          value7 = CONCAT31(extraout_var_03,cVar2);
          if (value7 == 0) {
            value7 = Person_FindFreeNeighborCell(self,arg1,*(int *)((intptr_t)self + 0x8c),&local_c);
            value5 = UI_RemoveLastChild((intptr_t)self);
            if (value5 != value7) {
              Person_AdvanceRoute(self,value7);
              return 4;
            }
          }
          else {
            if (value7 == 1) goto LAB_0050d132;
            if (value7 == 2) {
              Person_TruncatePathToCurrentStep((intptr_t)self);
              Object_SetState(self,0x2c);
            }
          }
        }
      }
    }
  }
  return -1;
}
