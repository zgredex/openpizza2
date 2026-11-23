// StorageMenu_Init: ported from Pizza Connection 2 at 0x4c0ff0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c0ff0
#include "pc2_port.h"

void __cdecl StorageMenu_Init(void *arg1)

{
  void *self;
  uint32_t uvalue1;
  
                    /* Initializes the warehouse/storage submenu page. */
  self = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  DAT_0057d718 = Game_FindRecordByField34(self,*(int *)(DAT_0057c670 + 0x218));
  DAT_0057d710 = Game_FindSubrecordIndex(self,DAT_0057d718);
  if (*(char *)(DAT_0057d718 + 0x3c) == '\0') {
    uvalue1 = DAT_00581278;
  }
  else {
    uvalue1 = DAT_00582624;
  }
  Gadget_SetText(arg1,0x541,uvalue1);
  BranchStoragePanel_Update(arg1);
  return;
}
