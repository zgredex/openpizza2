// CRT_CInit: ported from Pizza Connection 2 at 0x54f2b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f2b0
#include "pc2_port.h"

void CRT_CInit(void)

{
  if (PTR_CRT_InitFpEnvironment_00576718 != (uint8_t *)0x0) {
    (*(code *)PTR_CRT_InitFpEnvironment_00576718)();
  }
  CRT_RunAtexitRange((uint32_t *)&DAT_00563030,(uint32_t *)&DAT_00563044);
  CRT_RunAtexitRange((uint32_t *)&DAT_00563000,(uint32_t *)&DAT_0056302c);
  return;
}
