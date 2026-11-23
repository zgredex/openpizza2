// Object_SetSignAndLogoVariant: ported from Pizza Connection 2 at 0x4dc420.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dc420
#include "pc2_port.h"

void __thiscall Object_SetSignAndLogoVariant(void *self,int arg1,int arg2,int arg3)

{
  int value1;
  int value2;
  char *cptr3;
  int value4;
  int value5;
  int *ptr6;
  char *cptr7;
  int value8;
  
                    /* Selects SCHILD and ZLOGO variants on an object's children. */
  CS_Enter(*(int *)(DAT_0057c670 + 0x248));
  value1 = *(int *)(*(int *)((intptr_t)self + 0xfa8) + 0x4c) + *(int *)(arg2 + 0x24) * 0xc;
  value4 = Game_FindCityIndex(arg3);
  value2 = *(int *)(arg3 + 0x1e0);
  value5 = *(int *)(value1 + 8);
  value8 = 0;
  arg2 = 0;
  if (0 < *(int *)(value5 + 0x14)) {
    do {
      ptr6 = (int *)(*(int *)(value5 + 0x18) + value8);
      cptr3 = (char *)ptr6[2];
      value5 = *ptr6;
      if (*cptr3 == '\x02') {
        cptr7 = _strstr(cptr3 + 4,s_SCHILD_0056d04c);
        if (cptr7 != (char *)0x0) {
          *(int *)(*(int *)(*(int *)(value1 + 8) + 0x18) + 4 + value8) = arg1;
          if (arg1 == 0) {
            Record_ClearFlags48(*(void **)(cptr3 + 0x48),value5);
          }
          else {
            Record_SelectVariant(*(void **)(cptr3 + 0x48),value5,value4 + 1);
          }
        }
        cptr7 = _strstr(cptr3 + 4,s_ZLOGO_0056d044);
        if (cptr7 != (char *)0x0) {
          *(int *)(*(int *)(*(int *)(value1 + 8) + 0x18) + 4 + value8) = arg1;
          if (arg1 == 0) {
            Record_ClearFlags48(*(void **)(cptr3 + 0x48),value5);
          }
          else {
            Record_SelectVariant(*(void **)(cptr3 + 0x48),value5,value2 + 1);
          }
        }
      }
      value5 = *(int *)(value1 + 8);
      arg2 = arg2 + 1;
      value8 = value8 + 0xc;
    } while (arg2 < *(int *)(value5 + 0x14));
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x248));
  return;
}
