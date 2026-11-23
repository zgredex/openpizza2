// RecipeMenu_ShowRecipeFileChooser: ported from Pizza Connection 2 at 0x498ef0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x498ef0
#include "pc2_port.h"

void RecipeMenu_ShowRecipeFileChooser(void)

{
  int value1;
  
                    /* Shows the saved-recipe file chooser or an empty message. */
  value1 = SaveGame_ScanSaveFileList();
  if (value1 == 0) {
    Game_ShowConfirmationDialog(DAT_0057c670,0xfffe79af,DAT_00581e34,DAT_00580e80,0);
    return;
  }
  UI_ShowScrollingListDialog(DAT_0057c670,0xfffe7981,DAT_00581e34,DAT_00581594,DAT_0057ca04,0,0);
  return;
}
