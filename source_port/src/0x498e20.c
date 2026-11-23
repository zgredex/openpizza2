// RecipeList_SelectRecipe: ported from Pizza Connection 2 at 0x498e20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x498e20
#include "pc2_port.h"

void __cdecl RecipeList_SelectRecipe(void *arg1,int arg2)

{
  void *self;
  int value1;
  int value2;
  
                    /* Selects a recipe and refreshes its summary and rating bars. */
  value2 = 0;
  do {
    Window_GadgetNotify_Button_SetState(arg1,value2 + 0x461,0);
    value2 = value2 + 1;
  } while (value2 < 8);
  Window_GadgetNotify_Button_SetState(arg1,arg2,1);
  DAT_0057c9fc = *(int *)(DAT_0057ca08 + -0x1184 + (DAT_0057ca00 + arg2) * 4);
  self = (void *)IDMap_Lookup((void *)(*(int *)(DAT_0057c670 + 0x200 +
                                               *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x110),
                              DAT_0057c9fc,(int *)0x0);
  *(void **)(DAT_0057c670 + 0x98) = self;
  UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x25c),-0x18671,0x23,DAT_0057c9fc);
  BranchList_UpdateSummary(arg1);
  value2 = 0;
  do {
    value1 = Game_MapInputIndex(self,value2);
    Rating_UpdateBarByKey(arg1,0x4f0,value2,value1,DAT_0058155c);
    value2 = value2 + 1;
  } while (value2 < 8);
  return;
}
