// Game_HandleBriefingEntry: ported from Pizza Connection 2 at 0x48b9b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48b9b0
#include "pc2_port.h"

void __thiscall Game_HandleBriefingEntry(void *self,int arg1,int arg2)

{
  void *this_00;
  int value1;
  int value2;
  
                    /* Opens or closes a briefing entry as a mission offer or message. */
  value1 = arg2;
  if (arg1 == 1) {
    this_00 = (void *)((intptr_t)self + 0x304);
    value2 = MessageList_FindKeyByValue(this_00,arg2,&arg1);
    if (*(int *)(value2 + 4) == 1) {
      if (*(int *)((intptr_t)self + 0x268) != 0) {
        if (*(int *)((intptr_t)self + 0x278) == 0x11d7) {
          return;
        }
        Game_CloseSelectionDialog((intptr_t)self);
      }
      Game_ShowDatedMessageDialog(self,arg1);
      Sound_TriggerSoundById(DAT_0057ba0c,0x14);
      UI_AdvanceBriefing(this_00,arg1);
      return;
    }
    if ((DAT_00567da0 != value1) && (*(int *)((intptr_t)self + 0x268) != 0)) {
      Game_CloseSelectionDialog((intptr_t)self);
    }
    Game_ShowQuestionDialog(self,0xffffffff,DAT_00582408,value2 + 0x78,1,0,value1,'\0');
    Sound_TriggerSoundById(DAT_0057ba0c,0x14);
    UI_AdvanceBriefing(this_00,arg1);
  }
  else if (arg1 == 0x15) {
    if ((*(int *)((intptr_t)self + 0x278) == 1) && (*(int *)((intptr_t)self + 0x268) != 0)) {
      Game_CloseSelectionDialog((intptr_t)self);
    }
    MessageList_FindKeyByValue((void *)((intptr_t)self + 0x304),arg2,&arg1);
    Sound_GetChannelObject((void *)((intptr_t)self + 0x304),arg1,0);
    Sound_TriggerSoundById(DAT_0057ba0c,0x13);
    return;
  }
  return;
}
