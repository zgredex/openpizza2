// FurniturePriceMenu_Init: ported from Pizza Connection 2 at 0x4bb650.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bb650
#include "pc2_port.h"

void __cdecl FurniturePriceMenu_Init(void *arg1)

{
                    /* Initializes the furnishing-price page. */
  Window_UpdateBranchInfoPage(arg1,'\x01');
  return;
}
