// BranchScreen_SelectBranchRecord: ported from Pizza Connection 2 at 0x4b5a40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b5a40
#include "pc2_port.h"

void __cdecl BranchScreen_SelectBranchRecord(void *arg1,char arg2)

{
  int value1;
  
  value1 = IDMap_Lookup((void *)(DAT_0057d6ac + 0x148),DAT_0057d6a8,(int *)0x0);
  *(int *)(DAT_0057c670 + 0x9c) = value1;
  Sound_SelectCurrentTrack(DAT_0057ba0c);
  DAT_0057d6a8 = *(uint32_t *)(value1 + 0x3c);
  Window_GadgetNotify_Text_SetText(arg1,0x40f,value1 + 4);
  if (arg2 != '\0') {
    UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x264),-0x1864e,0x23,*(int *)(value1 + 0x3c));
  }
  return;
}
