// RecipeMenu_ShowRecipeChooser: ported from Pizza Connection 2 at 0x49c450.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49c450
#include "pc2_port.h"

void RecipeMenu_ShowRecipeChooser(void)

{
  int value1;
  
                    /* Shows the available recipe chooser or its empty/completed message. */
  value1 = Menu_BuildUnassignedMenuList();
  if (value1 == -1) {
    Game_ShowConfirmationDialog(DAT_0057c670,0xfffe79af,DAT_0058282c,DAT_00581698,0);
    return;
  }
  if (value1 == 0) {
    Game_ShowConfirmationDialog(DAT_0057c670,0xfffe79af,DAT_0058282c,DAT_00581a00,0);
    return;
  }
  UI_ShowScrollingListDialog(DAT_0057c670,0xfffe7986,DAT_0058282c,DAT_00581208,DAT_0057ca8c,0,0);
  return;
}
