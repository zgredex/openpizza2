// StatisticsBackdrop_UpdateCompanyValues: ported from Pizza Connection 2 at 0x4b0020.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b0020
#include "pc2_port.h"

void __cdecl StatisticsBackdrop_UpdateCompanyValues(void *arg1)

{
  int value1;
  int value2;
  int *ptr3;
  int value4;
  uint8_t local_40 [64];
  
  value2 = 0;
  value4 = 0x403;
  ptr3 = &DAT_0057d66c;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value2);
    if (value1 != 0) {
      String_Format(local_40,&DAT_005686f4,*(uint32_t *)(*ptr3 + 0x11c));
      Window_GadgetNotify_Text_SetText(arg1,value4,local_40);
    }
    ptr3 = ptr3 + 1;
    value2 = value2 + 1;
    value4 = value4 + 3;
  } while ((intptr_t)ptr3 < 0x57d684);
  return;
}
