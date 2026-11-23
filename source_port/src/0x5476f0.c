// Sound_InitSpeechVoice: ported from Pizza Connection 2 at 0x5476f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5476f0
#include "pc2_port.h"

void __fastcall Sound_InitSpeechVoice(int *arg1)

{
  char cVar1;
  int value2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int *ptr5;
  char *cptr6;
  char *cptr7;
  int *ptr8;
  
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  uvalue3 = 0xffffffff;
  cptr6 = (char *)(value2 + 0x44);
  do {
    cptr7 = cptr6;
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cptr7 = cptr6 + 1;
    cVar1 = *cptr6;
    cptr6 = cptr7;
  } while (cVar1 != '\0');
  uvalue3 = ~uvalue3;
  ptr5 = (int *)(cptr7 + -uvalue3);
  ptr8 = arg1 + 0x5d;
  for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *ptr8 = *ptr5;
    ptr5 = ptr5 + 1;
    ptr8 = ptr8 + 1;
  }
  for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *(char *)ptr8 = (char)*ptr5;
    ptr5 = (int *)((intptr_t)ptr5 + 1);
    ptr8 = (int *)((intptr_t)ptr8 + 1);
  }
  Sound_LoadSpeechSet(arg1);
  arg1[0x51] = 0;
  arg1[0x53] = 0;
  arg1[0x5c] = 0x3f800000;
  arg1[6] = 1000;
  return;
}
