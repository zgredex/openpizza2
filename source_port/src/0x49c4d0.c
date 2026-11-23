// RecipeMenu_ShowMenuFileChooser: ported from Pizza Connection 2 at 0x49c4d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49c4d0
#include "pc2_port.h"

void RecipeMenu_ShowMenuFileChooser(void)

{
  int value1;
  
                    /* Shows the saved-menu file chooser or an empty message. */
  value1 = SaveMenu_ScanMenuFileList();
  if (value1 < 1) {
    Game_ShowConfirmationDialog(DAT_0057c670,0xfffe79af,DAT_0058282c,DAT_00582c8c,0);
    return;
  }
  UI_ShowScrollingListDialog(DAT_0057c670,0xfffe7987,DAT_0058282c,DAT_00581a1c,DAT_0057ca8c,0,0);
  return;
}
