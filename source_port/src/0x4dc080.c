// Mission_ApplySettings: ported from Pizza Connection 2 at 0x4dc080.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dc080
#include "pc2_port.h"

void __fastcall Mission_ApplySettings(int arg1)

{
  DAT_0057bb24 = *(uint32_t *)(arg1 + 0x344);
  DAT_0057bb28 = *(uint32_t *)(arg1 + 0x48);
  DAT_0057bb2c = *(uint32_t *)(arg1 + 0x34c);
  DAT_0057bb30 = *(uint32_t *)(arg1 + 0x35c);
  DAT_0057bb34 = (DAT_0057bb34 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  DAT_0057bb38 = *(uint32_t *)(arg1 + 0x360);
  DAT_0057bb3c = (DAT_0057bb3c & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  DAT_0057bb48 = *(uint32_t *)(arg1 + 0x350);
  DAT_0057bb4c = *(uint32_t *)(arg1 + 0x354);
  DAT_0057bb50 = *(uint32_t *)(arg1 + 0x358);
  return;
}
