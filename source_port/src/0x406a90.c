// Settings_InitDefaults: ported from Pizza Connection 2 at 0x406a90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x406a90
#include "pc2_port.h"

void Settings_InitDefaults(void)

{
  bool flag1;
  uint32_t extraout_var;
  uint32_t *uptr2;
  int value3;
  uint32_t *uptr4;
  
  uptr4 = &DAT_0057b8a8;
  for (value3 = 0x59; value3 != 0; value3 = value3 + -1) {
    *uptr4 = 0;
    uptr4 = uptr4 + 1;
  }
  flag1 = Settings_LoadFromRegistry();
  if (CONCAT31(extraout_var,flag1) == 0) {
    DAT_0057b9f0 = 5;
    DAT_0057b9f8 = 4;
    DAT_0057b9fc = 0;
    DAT_0057b9f4 = 0;
    DAT_0057b938 = Random_RangeFast(0,1);
    DAT_0057b93c = Random_RangeFast(0,DAT_0058557c - 1);
    DAT_0057b940 = Random_RangeFast(0,DAT_00585580 - 1);
    DAT_0057b944 = Random_RangeFast(0,DAT_00585584 - 1);
    DAT_0057b948 = Random_RangeFast(0,DAT_00585588 - 1);
    DAT_0057b9c8 = 0xfa;
    DAT_0057b9d0 = 0xffffffff;
    DAT_0057b9d4 = 0xffffffff;
    DAT_0057b9d8 = 0xffffffff;
    DAT_0057b9cc = 0xb;
    DAT_0057b964 = 1;
    DAT_0057b968 = 0;
    DAT_0057b96c = 1;
    DAT_0057b970 = 1;
    DAT_0057b9dc = 3;
    DAT_0057b978 = 6;
    uptr2 = &DAT_0057b9ac;
    do {
      uptr2[-0xc] = 100;
      uptr2[-6] = 0;
      *uptr2 = (uint32_t)((intptr_t)uptr2 < 0x57b9b4);
      uptr2 = uptr2 + 1;
    } while ((intptr_t)uptr2 < 0x57b9c4);
  }
  return;
}
