// Menu_BuildUnassignedMenuList: ported from Pizza Connection 2 at 0x49b5f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49b5f0
#include "pc2_port.h"


int Menu_BuildUnassignedMenuList(void)

{
  int value1;
  int value2;
  void *pvVar3;
  int value4;
  char *cptr5;
  int value6;
  int local_14;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Builds the list of unassigned, non-empty player recipes. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005586d6;
  local_c = ExceptionList;
  value6 = 0;
  local_14 = 0;
  value1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value2 = *(int *)(value1 + 0x124);
  if (value2 == 0) {
    return -1;
  }
  ExceptionList = &local_c;
  pvVar3 = operator_new(0x1c);
  local_4 = 0;
  if (pvVar3 == (void *)0x0) {
    DAT_0057ca8c = (uint32_t *)0x0;
  }
  else {
    DAT_0057ca8c = List_Construct(pvVar3,0);
  }
  local_4 = 0xffffffff;
  if (0 < value2) {
    do {
      value4 = IDMap_Lookup((void *)(value1 + 0x110),value6,(int *)0x0);
      if ((*(char *)(value4 + 0x1dc) == '\0') && (0 < *(int *)(value4 + 0x1d8))) {
        pvVar3 = operator_new(0x58);
        local_4 = 1;
        if (pvVar3 == (void *)0x0) {
          cptr5 = (char *)0x0;
        }
        else {
          cptr5 = UI_ListEntry_Construct(pvVar3,(char *)(value4 + 4),value6);
        }
        local_4 = 0xffffffff;
        List_Add(DAT_0057ca8c,cptr5);
        local_14 = local_14 + 1;
      }
      value6 = value6 + 1;
    } while (value6 < value2);
    if (local_14 != 0) {
      ExceptionList = local_c;
      return local_14;
    }
  }
  if (DAT_0057ca8c != (uint32_t *)0x0) {
    (**(code **)*DAT_0057ca8c)(1);
  }
  ExceptionList = local_c;
  return local_14;
}
