// SaveGame_Scan: ported from Pizza Connection 2 at 0x4a1940.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a1940
#include "pc2_port.h"


void __cdecl SaveGame_Scan(void *arg1,int arg2)

{
  void *self;
  char *cptr1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055887b;
  local_c = ExceptionList;
  if (arg2 == 0) {
    cptr1 = s_save_games_auto___piz_00568d04;
    ExceptionList = &local_c;
  }
  else {
    ExceptionList = &local_c;
    self = operator_new(0x58);
    local_4 = 0;
    if (self == (void *)0x0) {
      cptr1 = (char *)0x0;
    }
    else {
      cptr1 = UI_ListEntry_Construct(self,DAT_00582894,0xffffffff);
    }
    local_4 = 0xffffffff;
    String_SetOwned(cptr1,DAT_00580ea0);
    List_Add(arg1,cptr1);
    cptr1 = (char *)0x0;
  }
  SaveGame_ReadHeaderEntry(arg1,cptr1,s_save_games_save___piz_00568d1c);
  ExceptionList = local_c;
  return;
}
