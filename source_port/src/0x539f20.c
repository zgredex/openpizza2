// Surface_ResetFlags: ported from Pizza Connection 2 at 0x539f20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539f20
#include "pc2_port.h"

/* WARNING: Removing unreachable block (ram,0x00539f68) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __fastcall Surface_ResetFlags(int arg1)

{
  int value1;
  uint32_t uvalue2;
  uint8_t in_AF;
  uint8_t in_TF;
  uint8_t in_IF;
  uint8_t in_NT;
  uint8_t in_AC;
  uint8_t in_VIF;
  uint8_t in_VIP;
  uint8_t in_ID;
  uint32_t uvalue3;
  uint32_t local_8;
  
  *(uint32_t *)(arg1 + 0x74) = 0;
  uvalue3 = (uint32_t)(in_NT & 1) * 0x4000 | (uint32_t)(in_IF & 1) * 0x200 | (uint32_t)(in_TF & 1) * 0x100 | 0x40
          | (uint32_t)(in_AF & 1) * 0x10 | 4 | (uint32_t)(in_ID & 1) * 0x200000 |
          (uint32_t)(in_VIP & 1) * 0x100000 | (uint32_t)(in_VIF & 1) * 0x80000 | (uint32_t)(in_AC & 1) * 0x40000
  ;
  uvalue2 = uvalue3 ^ 0x200000;
  if (((uint32_t)((uvalue2 & 0x4000) != 0) * 0x4000 | (uint32_t)((uvalue2 & 0x200) != 0) * 0x200 |
       (uint32_t)((uvalue2 & 0x100) != 0) * 0x100 | (uint32_t)((uvalue2 & 0x40) != 0) * 0x40 |
       (uint32_t)((uvalue2 & 0x10) != 0) * 0x10 | (uint32_t)((uvalue2 & 4) != 0) * 4 |
       (uint32_t)((uvalue2 & 0x200000) != 0) * 0x200000 | (uint32_t)((uvalue2 & 0x40000) != 0) * 0x40000) !=
      uvalue3) {
    value1 = cpuid_Version_info(1);
    local_8 = (uint32_t)((*(uint32_t *)(value1 + 8) & 0x800000) != 0);
    *(uint32_t *)(arg1 + 0x74) = local_8;
  }
  return;
}
