// UI_RecordList_SetVisibleRange: ported from Pizza Connection 2 at 0x49f640.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49f640
#include "pc2_port.h"

void __cdecl UI_RecordList_SetVisibleRange(void *arg1,int arg2,int arg3)

{
  void *self;
  int value1;
  uint32_t uvalue2;
  uint16_t local_8;
  short local_6;
  
  value1 = arg2;
  UI_ClearButtonRecordAnimation(arg1,arg2);
  self = (void *)UI_GetButtonContext(arg1,value1,&arg2);
  if (self != (void *)0x0) {
    RecordList_ReadSlot98(self,1,0,(uint32_t *)&local_8);
    value1 = Record_GetValue48(self,arg2);
    uvalue2 = RecordList_GetCount((intptr_t)self);
    local_8 = (uint16_t)value1;
    if (arg3 == 0) {
      local_6 = 0;
    }
    else {
      local_6 = (short)uvalue2 + -1;
      Sound_TriggerSoundById(DAT_0057ba0c,0xd);
    }
    Record_SetSlot6_98(self,1,0,(uint32_t *)&local_8);
    UI_SetButtonRecordVariant(arg1,0x438,1);
  }
  return;
}
