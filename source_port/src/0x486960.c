// Game_DispatchQuarterlyVisitors: ported from Pizza Connection 2 at 0x486960.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x486960
#include "pc2_port.h"

void __fastcall Game_DispatchQuarterlyVisitors(int arg1)

{
  int *ptr1;
  void *self;
  uint32_t uvalue2;
  int value3;
  void *pvVar4;
  int value5;
  uint8_t *bptr6;
  int local_108;
  uint8_t local_100 [256];
  
                    /* Dispatches quarterly customer, celebrity, and visitor objects. */
  IDMap_Lookup((void *)(arg1 + 4),*(int *)(arg1 + 0x2f4),(int *)0x0);
  local_108 = 0;
  if (0 < *(int *)(arg1 + 0x50)) {
    do {
      self = (void *)IDMap_Lookup((void *)(arg1 + 0x3c),local_108,(int *)0x0);
      value3 = *(int *)((intptr_t)self + 0x30);
      if (value3 == 0xb) {
        if (((*(int *)((intptr_t)self + 0x74) == 0) &&
            (pvVar4 = Game_FindBestCompositeRatedBranch(-1), pvVar4 != (void *)0x0)) &&
           (*(int *)((intptr_t)pvVar4 + 0x16f0) != 0)) {
          Object_SetDestinationAndTarget(self,1,*(int *)((intptr_t)pvVar4 + 0x16f0));
        }
      }
      else if (value3 == 0xf) {
        uvalue2 = Random_RangeFast(0,2);
        if (((uvalue2 == 0) && (*(int *)((intptr_t)self + 0x74) == 0)) &&
           ((pvVar4 = Game_FindBestCompositeRatedBranch(5), pvVar4 != (void *)0x0 &&
            (*(int *)((intptr_t)pvVar4 + 0x16f0) != 0)))) {
          DebugConsole_Printf(DAT_0057c1e0,0xa000,(uint8_t *)s_Prommi_geht_nach__s_00568150,
                              (intptr_t)pvVar4 + 4);
          Object_SetDestinationAndTarget(self,1,*(int *)((intptr_t)pvVar4 + 0x16f0));
          value3 = *(int *)((intptr_t)pvVar4 + 0x30);
          value5 = Game_GetCurrentPlayerCompanyName(arg1);
          if (value3 == value5) {
            bptr6 = local_100;
            String_Format(bptr6,DAT_005825d8,(intptr_t)pvVar4 + 4);
            UI_Briefing_AddMessage
                      ((void *)(arg1 + 0x304),-1,0,4,1,*(int *)((intptr_t)pvVar4 + 0x16f0),
                       DAT_00582a6c,local_100,bptr6);
            UI_AppendCommandIfActive(*(void **)(*(int *)(arg1 + 0x224) + 0xa8),7,-1);
            UI_AppendCommandIfActive(*(void **)(*(int *)(arg1 + 0x224) + 0xa8),0x12,-1);
          }
        }
      }
      else if ((value3 == 0x21) && (*(int *)(*(int *)(*(int *)(arg1 + 0x224) + 0xa8) + 0xb8) != 0)
              ) {
        if (*(int *)((intptr_t)self + 0x74) == 0) {
          value3 = *(int *)(arg1 + 0x200 + *(int *)(arg1 + 0x2ec) * 4);
          value5 = *(int *)(value3 + 0x15c);
          if (value5 == 0) goto LAB_00486b54;
          uvalue2 = Random_RangeFast(0,value5 - 1);
          value3 = IDMap_Lookup((void *)(value3 + 0x148),uvalue2,(int *)0x0);
          if (value3 != 0) {
            Object_SetDestinationAndTarget(self,1,*(int *)(value3 + 0x16f0));
          }
        }
        ptr1 = (int *)(*(int *)(*(int *)(arg1 + 0x224) + 0xa8) + 0xb8);
        *ptr1 = *ptr1 + -1;
      }
LAB_00486b54:
      local_108 = local_108 + 1;
    } while (local_108 < *(int *)(arg1 + 0x50));
  }
  return;
}
