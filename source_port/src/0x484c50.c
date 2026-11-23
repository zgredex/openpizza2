// SubMenu_BuildRecipePanelPage: ported from Pizza Connection 2 at 0x484c50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x484c50
#include "pc2_port.h"

int __fastcall SubMenu_BuildRecipePanelPage(int arg1)

{
  int *ptr1;
  void *pvVar2;
  int local_4;
  
                    /* Builds a recipe-panel submenu page. */
  local_4 = arg1;
  if (*(int *)(arg1 + 0x268) != 0) {
    Game_CloseSelectionDialog(arg1);
  }
  switch(*(uint32_t *)(arg1 + 0x298 + *(int *)(arg1 + 0x290) * 4)) {
  case 1:
    ptr1 = SubMenu_BuildRecipeList(&local_4);
    RecipeListPanel_Update(ptr1);
    *(int **)(arg1 + 0x264) = ptr1;
    return local_4;
  case 2:
    pvVar2 = SubMenu_BuildNewRecipe(&local_4);
    RecipeEditorPage_Update(pvVar2,'\x01');
    *(void **)(arg1 + 0x264) = pvVar2;
    return local_4;
  case 3:
  case 10:
    pvVar2 = SubMenu_BuildRecipeIngredients(&local_4);
    RecipeEditorIngredients_Update(pvVar2);
    *(void **)(arg1 + 0x264) = pvVar2;
    return local_4;
  case 4:
    pvVar2 = SubMenu_BuildMenuPlan(&local_4);
    RecipeRankingPanel_Update(pvVar2,'\x01');
    *(void **)(arg1 + 0x264) = pvVar2;
    return local_4;
  case 5:
    pvVar2 = SubMenu_BuildRecipeCheck(&local_4);
    AdvertisingMenu_UpdatePage(pvVar2);
    *(void **)(arg1 + 0x264) = pvVar2;
    return local_4;
  case 6:
    pvVar2 = SubMenu_BuildPizzaContest(&local_4);
    CompanyRating_InitCompanyList(pvVar2);
    *(void **)(arg1 + 0x264) = pvVar2;
    return local_4;
  case 7:
    pvVar2 = SubMenu_BuildContestRecipe(&local_4);
    PizzaContestRecipePage_Update(pvVar2);
    *(void **)(arg1 + 0x264) = pvVar2;
    return local_4;
  case 8:
    pvVar2 = Window_BuildRecipeEditorPage(&local_4);
    CompanyRecipeIngredients_Update(pvVar2);
    *(void **)(arg1 + 0x264) = pvVar2;
    return local_4;
  default:
    *(int *)(arg1 + 0x264) = local_4;
    return local_4;
  }
}
