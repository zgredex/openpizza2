// Company_CreateNew: ported from Pizza Connection 2 at 0x49a0e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49a0e0
#include "pc2_port.h"


void Company_CreateNew(void)

{
  void *self;
  int value1;
  uint8_t *bptr2;
  char *cptr3;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Creates a new company for the selected player. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055866b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  NewRecipe_CloseIngredientPalette();
  UI_RemoveAllObjects(*(void **)(DAT_0057c670 + 0x25c));
  self = operator_new(0x330);
  local_4 = 0;
  if (self == (void *)0x0) {
    DAT_0057cda0 = (uint8_t *)0x0;
  }
  else {
    DAT_0057cda0 = (uint8_t *)Recipe_Construct(self,(int *)0x0,'\0');
  }
  local_4 = 0xffffffff;
  bptr2 = DAT_0057cda0;
  cptr3 = DAT_00582c6c;
  value1 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  Company_GenerateUniqueName(value1,bptr2,cptr3);
  List_Add((void *)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x110),
           DAT_0057cda0);
  *(uint8_t **)(DAT_0057c670 + 0x98) = DAT_0057cda0;
  UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x25c),-0x1866a,0x23,1);
  ExceptionList = local_c;
  return;
}
