// Company_GenerateUniqueName: ported from Pizza Connection 2 at 0x499f30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x499f30
#include "pc2_port.h"

void __cdecl Company_GenerateUniqueName(int arg1,uint8_t *arg2,char *arg3)

{
  char cVar1;
  uint8_t flag2;
  int value3;
  int value4;
  uint8_t *bptr5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  uint8_t *bptr8;
  char *cptr9;
  char *cptr10;
  int value11;
  bool flag12;
  uint8_t local_100 [256];
  
  uvalue6 = 0xffffffff;
  cptr9 = arg3;
  do {
    cptr10 = cptr9;
    if (uvalue6 == 0) break;
    uvalue6 = uvalue6 - 1;
    cptr10 = cptr9 + 1;
    cVar1 = *cptr9;
    cptr9 = cptr10;
  } while (cVar1 != '\0');
  uvalue6 = ~uvalue6;
  bptr8 = (uint8_t *)(cptr10 + -uvalue6);
  bptr5 = local_100;
  for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
    *(uint32_t *)bptr5 = *(uint32_t *)bptr8;
    bptr8 = bptr8 + 4;
    bptr5 = bptr5 + 4;
  }
  for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *bptr5 = *bptr8;
    bptr8 = bptr8 + 1;
    bptr5 = bptr5 + 1;
  }
  value3 = Game_GetPlayerBySlot(DAT_0057c670,arg1);
LAB_00499f7f:
  value11 = 0;
  if (0 < *(int *)(value3 + 0x124)) {
    do {
      value4 = IDMap_Lookup((void *)(value3 + 0x110),value11,(int *)0x0);
      bptr8 = local_100;
      bptr5 = (uint8_t *)(value4 + 4);
      do {
        flag2 = *bptr5;
        flag12 = flag2 < *bptr8;
        if (flag2 != *bptr8) {
LAB_00499fc6:
          value4 = (1 - (uint32_t)flag12) - (uint32_t)(flag12 != 0);
          goto LAB_00499fcb;
        }
        if (flag2 == 0) break;
        flag2 = bptr5[1];
        flag12 = flag2 < bptr8[1];
        if (flag2 != bptr8[1]) goto LAB_00499fc6;
        bptr5 = bptr5 + 2;
        bptr8 = bptr8 + 2;
      } while (flag2 != 0);
      value4 = 0;
LAB_00499fcb:
      if (value4 == 0) goto LAB_00499fdc;
      value11 = value11 + 1;
      if (*(int *)(value3 + 0x124) <= value11) break;
    } while( true );
  }
  uvalue6 = 0xffffffff;
  bptr8 = local_100;
  do {
    bptr5 = bptr8;
    if (uvalue6 == 0) break;
    uvalue6 = uvalue6 - 1;
    bptr5 = bptr8 + 1;
    flag2 = *bptr8;
    bptr8 = bptr5;
  } while (flag2 != 0);
  uvalue6 = ~uvalue6;
  bptr8 = bptr5 + -uvalue6;
  for (uvalue7 = uvalue6 >> 2; arg2 = arg2 + 4, uvalue7 != 0; uvalue7 = uvalue7 - 1) {
    *(uint32_t *)arg2 = *(uint32_t *)bptr8;
    bptr8 = bptr8 + 4;
  }
  for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *arg2 = *bptr8;
    bptr8 = bptr8 + 1;
    arg2 = arg2 + 1;
  }
  return;
LAB_00499fdc:
  String_Format(local_100,(uint8_t *)s__s__d_00568964,arg3);
  goto LAB_00499f7f;
}
