// WarehouseScreen_Refresh: ported from Pizza Connection 2 at 0x4c2000.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c2000
#include "pc2_port.h"


void __cdecl WarehouseScreen_Refresh(void *arg1)

{
                    /* Refreshes the warehouse product rows and title. */
  UI_SetPosition(arg1,&LAB_004c1a40,0);
  DAT_0057d724 = Game_FindRecordByField34
                           (*(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4),
                            *(int *)(DAT_0057c670 + 0x218));
  DAT_0057d71c = Game_FindSubrecordIndex
                           (*(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4),
                            DAT_0057d724);
  UI_Group_Create(arg1,0,2,0x2004);
  Window_GadgetNotify_Button_SetState(arg1,DAT_0057d728 + 0x2004,1);
  BranchStorageDistribution_Update(arg1);
  if (*(char *)(DAT_0057d724 + 0x3c) == '\0') {
    Gadget_SetText(arg1,0x1ff1,DAT_00581278);
    return;
  }
  Gadget_SetText(arg1,0x1ff1,DAT_00582624);
  return;
}
