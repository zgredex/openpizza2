// City_BuildObjectListEntries: ported from Pizza Connection 2 at 0x4d87f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d87f0
#include "pc2_port.h"


void __thiscall City_BuildObjectListEntries(void *self,void *arg1)

{
  uint32_t uvalue1;
  int value2;
  int value3;
  int value4;
  void *pvVar5;
  char *cptr6;
  int value7;
  uint32_t uvalue8;
  void *local_118;
  int local_114;
  char local_10c [256];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Builds sorted list entries for a city's notable objects. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00559174;
  local_c = ExceptionList;
  local_114 = 0;
  ExceptionList = &local_c;
  if (0 < *(int *)((intptr_t)self + 0xfc0)) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0xfac),local_114,(int *)0x0);
      value7 = 0;
      switch(*(uint32_t *)(value2 + 4)) {
      case 0x10:
        value4 = *(int *)(value2 + 8);
        value7 = value4 * 10000 + 18000;
        value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
        if (value4 != value3) break;
        pvVar5 = (void *)Game_GetPlayerBySlot(DAT_0057c670,value4);
        value4 = Game_FindRecordByField34(pvVar5,value2);
        if (value4 == 0) break;
        uvalue8 = 0;
        if (pvVar5 != (void *)0x0) {
          uvalue8 = *(uint32_t *)((intptr_t)pvVar5 + 0x1dc);
        }
        Get_Subobject4(value4);
        String_Format(local_10c,(uint8_t *)s__s___s_0056cd9c,DAT_00582158);
        local_118 = operator_new(0x58);
        local_4 = 3;
        if (local_118 == (void *)0x0) goto LAB_004d8a68;
LAB_004d89b5:
        cptr6 = UI_ListEntry_ConstructWithValue(local_118,local_10c,value2,uvalue8);
        goto LAB_004d8b66;
      default:
        break;
      case 0x17:
        value7 = 1;
      case 0x18:
        value7 = value7 + 1;
switchD_004d8852_caseD_19:
        if (*(int *)(value2 + 0x54) != -1) {
          pvVar5 = operator_new(0x58);
          local_4 = 0;
          if (pvVar5 == (void *)0x0) {
            cptr6 = (char *)0x0;
          }
          else {
            cptr6 = UI_ListEntry_Construct
                               (pvVar5,*(char **)(&DAT_005840d4 + *(int *)(value2 + 4) * 4),value2);
          }
          goto LAB_004d8b66;
        }
        break;
      case 0x19:
        goto switchD_004d8852_caseD_19;
      case 0x1a:
        value4 = *(int *)(value2 + 8);
        value7 = value4 * 10000 + 19000;
        if (*(int *)(value2 + 0x30) == 0x1c) {
          value7 = value4 * 10000 + 0x2774;
          value4 = Game_GetPlayerBySlot(DAT_0057c670,value4);
          uvalue8 = 0;
          if (value4 != 0) {
            uvalue8 = *(uint32_t *)(value4 + 0x1dc);
          }
          String_Format(local_10c,(uint8_t *)s__s___s__0056c954,DAT_00584144);
          pvVar5 = operator_new(0x58);
          local_4 = 1;
          if (pvVar5 == (void *)0x0) goto LAB_004d8b4d;
          cptr6 = UI_ListEntry_ConstructWithValue(pvVar5,local_10c,value2,uvalue8);
          goto LAB_004d8b4f;
        }
        value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
        if (value4 != value3) break;
        value4 = Game_GetPlayerBySlot(DAT_0057c670,value4);
        if (value4 == 0) {
          uvalue8 = 0;
        }
        else {
          uvalue8 = *(uint32_t *)(value4 + 0x1dc);
        }
        String_Format(local_10c,(uint8_t *)s__s___s__0056c954,DAT_005821b0);
        local_118 = operator_new(0x58);
        local_4 = 2;
        if (local_118 != (void *)0x0) goto LAB_004d89b5;
        goto LAB_004d8a68;
      case 0x1c:
        value7 = 1;
      case 0xf:
        uvalue1 = *(uint32_t *)(value2 + 0x2c);
        value4 = *(int *)(value2 + 8);
        value3 = Game_GetPlayerSubmapValue(DAT_0057c670,value4,uvalue1);
        if (value7 == 0) {
          value7 = value4 * 10000 + 0x2774 + (uvalue1 & 0x7f);
        }
        else {
          value7 = value4 * 10000 + 0x2774;
        }
        value4 = Game_GetPlayerBySlot(DAT_0057c670,value4);
        uvalue8 = 0;
        if (value4 != 0) {
          uvalue8 = *(uint32_t *)(value4 + 0x1dc);
        }
        if (value3 == 0) {
          pvVar5 = operator_new(0x58);
          local_4 = 5;
          if (pvVar5 == (void *)0x0) {
LAB_004d8b4d:
            cptr6 = (char *)0x0;
          }
          else {
            cptr6 = UI_ListEntry_ConstructWithValue
                               (pvVar5,*(char **)(&DAT_005840d4 + *(int *)(value2 + 4) * 4),value2,
                                uvalue8);
          }
LAB_004d8b4f:
          *(int *)(cptr6 + 0x50) = *(int *)(value2 + 4) + 10000;
        }
        else {
          pvVar5 = operator_new(0x58);
          local_4 = 4;
          if (pvVar5 == (void *)0x0) {
LAB_004d8a68:
            cptr6 = (char *)0x0;
          }
          else {
            cptr6 = UI_ListEntry_ConstructWithValue(pvVar5,(char *)(value3 + 4),value2,uvalue8);
          }
        }
LAB_004d8b66:
        local_4 = 0xffffffff;
        if (cptr6 != (char *)0x0) {
          *(int *)(cptr6 + 0x50) = value7;
          List_Add(arg1,cptr6);
        }
      }
      local_114 = local_114 + 1;
    } while (local_114 < *(int *)((intptr_t)self + 0xfc0));
  }
  ExceptionList = local_c;
  return;
}
