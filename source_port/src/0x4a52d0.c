// TradeOffer_Page_Init: ported from Pizza Connection 2 at 0x4a52d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a52d0
#include "pc2_port.h"

void __cdecl TradeOffer_Page_Init(void *arg1)

{
                    /* Initializes the trade-offer page and refreshes its panel. */
  UI_ShowChildByID(arg1,0x1f67);
  UI_ShowChildByID(arg1,0x1f66);
  UI_ShowChildByID(arg1,0x433);
  UI_ShowChildByID(arg1,0x43a);
  UI_ShowChildByID(arg1,0x1f61);
  UI_ShowChildByID(arg1,0x1f63);
  UI_ShowChildByID(arg1,0x1f62);
  UI_ShowChildByID(arg1,0x1f65);
  UI_ShowChildByID(arg1,0x1f64);
  UI_ShowChildByID(arg1,0x439);
  TradeOffer_UpdatePanel(arg1,DAT_0057d270);
  return;
}
