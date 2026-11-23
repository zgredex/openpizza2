// Sound_LoadSpeechSet: ported from Pizza Connection 2 at 0x5478c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5478c0
#include "pc2_port.h"


void __fastcall Sound_LoadSpeechSet(int *arg1)

{
  int value1;
  int value2;
  int *ptr3;
  uint8_t **pptr4;
  int *local_108;
  uint8_t auStack_104 [260];
  
  value2 = -1;
  local_108 = arg1 + 0x5d;
  ptr3 = local_108;
  do {
    if (value2 == 0) break;
    value2 = value2 + -1;
    value1 = *ptr3;
    ptr3 = (int *)((intptr_t)ptr3 + 1);
  } while ((char)value1 != '\0');
  if (value2 != -2) {
    if (*arg1 == 1) {
      if (((uint8_t)((DAT_00575090) >> 8)) != '\0') {
        return;
      }
    }
    else if ((*arg1 == 2) && (((uint8_t)((DAT_00575090) >> 8)) == '\0')) {
      return;
    }
    if ((char)arg1[0x3f] != '\0') {
      if (((uint8_t)((DAT_00575090) >> 8)) == '\0') {
        *arg1 = 2;
      }
      else {
        *arg1 = 1;
        local_108 = DAT_00582530;
      }
      pptr4 = &PTR_s_Wache_m_3_WAV_00575170;
      ptr3 = arg1 + 0x91;
      do {
        value2 = 2;
        do {
          if (*ptr3 != 0) {
            (**(code **)(*(int *)arg1[2] + 0x50))((int *)arg1[2],*ptr3);
            *ptr3 = 0;
          }
          String_Format(auStack_104,(uint8_t *)s_speech__s__s_005760d0,local_108);
          (**(code **)(*(int *)arg1[2] + 0x28))((int *)arg1[2],auStack_104,ptr3);
          (**(code **)(*(int *)arg1[2] + 0x9c))((int *)arg1[2],arg1[0x3d],*ptr3);
          pptr4 = pptr4 + 1;
          ptr3 = ptr3 + 1;
          value2 = value2 + -1;
        } while (value2 != 0);
      } while ((intptr_t)pptr4 < 0x575190);
    }
  }
  return;
}
