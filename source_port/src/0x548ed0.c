// Sound_PlayStatusAdvisory: ported from Pizza Connection 2 at 0x548ed0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548ed0
#include "pc2_port.h"

/* WARNING: Removing unreachable block (ram,0x00548f15) */

void __fastcall Sound_PlayStatusAdvisory(void *arg1)

{
  void *self;
  int value1;
  int value2;
  uint32_t uvalue3;
  int value4;
  int value5;
  
  if ((((*(char *)((intptr_t)arg1 + 0xfc) != '\0') && (*(char *)((intptr_t)arg1 + 0x100) == '\0')) &&
      (DAT_0057c670 != 0)) && ((*(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 7) & 3) == 0)) {
    value5 = 0;
    value1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
    value2 = *(int *)(value1 + 0x15c);
    if (0 < value2) {
      self = (void *)(value1 + 0x148);
      do {
        value4 = IDMap_Lookup(self,value5,(int *)0x0);
        uvalue3 = *(uint32_t *)(value4 + 0x28);
        if ((uvalue3 & 2) != 0) {
          Sound_PlaySpeechStatement(arg1,0x1c);
          return;
        }
        if ((uvalue3 & 4) != 0) {
          Sound_PlaySpeechStatement(arg1,0x1b);
          return;
        }
        if ((uvalue3 & 0x20) != 0) {
          Sound_PlaySpeechStatement(arg1,0x1e);
          return;
        }
        if ((uvalue3 & 0x10) != 0) {
          Sound_PlaySpeechStatement(arg1,0x1f);
          return;
        }
        value4 = IDMap_Lookup(self,value5,(int *)0x0);
        if (*(int *)(value4 + 0x1a24) != 0) {
          Sound_PlaySpeechStatement(arg1,0x1d);
          return;
        }
        value4 = IDMap_Lookup(self,value5,(int *)0x0);
        value4 = Rating_GetInverse100(value4);
        if (value4 < 10) {
          Sound_PlaySpeechStatement(arg1,8);
          return;
        }
        value5 = value5 + 1;
      } while (value5 < value2);
    }
    value2 = *(int *)(value1 + 0x194);
    value5 = 0;
    if (0 < value2) {
      while (value4 = IDMap_Lookup((void *)(value1 + 0x180),value5,(int *)0x0),
            *(int *)(value4 + 0x30) != -1) {
        value5 = value5 + 1;
        if (value2 <= value5) {
          return;
        }
      }
      Sound_PlaySpeechStatement(arg1,0x20);
    }
  }
  return;
}
