// Window_UpdateCompanyProfilePage: ported from Pizza Connection 2 at 0x4a6990.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a6990
#include "pc2_port.h"

void __cdecl Window_UpdateCompanyProfilePage(void *arg1)

{
  int value1;
  int value2;
  int value3;
  int *ptr4;
  int value5;
  uint32_t unaff_EDI;
  int local_5c [3];
  uint8_t local_50 [32];
  int local_30 [4];
  uint32_t local_20;
  uint32_t local_1c;
  int local_18 [4];
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Fills the company-profile page from the selected company. */
  value5 = *(int *)(DAT_0057c670 + 0x224 + *(int *)(DAT_0057c670 + 0x2f0) * 4);
  value1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value3 = *(int *)(value5 + 4);
  UI_ComposeOverlayWindowFromRecord(arg1,0x2357,value3);
  Window_GadgetNotify_Text_SetText(arg1,0x515,value5 + 0xc);
  String_Format(local_50,(uint8_t *)s__d__s_00568324,*(uint32_t *)(value3 + 0x40));
  Window_GadgetNotify_Text_SetText(arg1,0x514,local_50);
  String_Format(local_50,&DAT_005686f4,*(uint32_t *)(value5 + 0x2c));
  Window_GadgetNotify_Text_SetText(arg1,0x513,local_50);
  String_Format(local_50,&DAT_005686f4,*(int *)(value5 + 0x30) + 1);
  Window_GadgetNotify_Text_SetText(arg1,0x2331,local_50);
  local_30[0] = *(int *)(value5 + 0x3c);
  local_30[1] = *(uint32_t *)(value5 + 0x40);
  local_30[2] = *(uint32_t *)(value5 + 0x44);
  local_30[3] = *(uint32_t *)(value5 + 0x48);
  local_20 = *(uint32_t *)(value5 + 0x4c);
  local_1c = *(uint32_t *)(value5 + 0x50);
  local_18[0] = *(uint32_t *)(value5 + 0x54);
  local_18[1] = *(uint32_t *)(value5 + 0x58);
  local_18[2] = *(uint32_t *)(value5 + 0x5c);
  local_18[3] = *(uint32_t *)(value5 + 0x60);
  local_8 = *(uint32_t *)(value5 + 100);
  local_4 = *(uint32_t *)(value5 + 0x68);
  ptr4 = local_30;
  value3 = 0x2342;
  do {
    UI_PrintSignedValue(arg1,value3 + -6,*ptr4);
    UI_PrintSignedValue(arg1,value3,ptr4[6]);
    UI_PrintSignedValue(arg1,value3 + 6,ptr4[6] + *ptr4);
    ptr4 = ptr4 + 1;
    value2 = value3 + -0x2341;
    value3 = value3 + 1;
  } while (value2 < 6);
  Window_GadgetNotify_Text_SetText(arg1,0x51b,value1 + 8);
  Personnel_SetEmployeePhotoByKey(arg1,0x2358,value1);
  value1 = *(int *)(value5 + 0xa0);
  value3 = 0;
  local_5c[0] = 0;
  local_5c[1] = 0;
  local_5c[2] = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)(value5 + 0x8c),value3,(int *)0x0);
      value2 = *(int *)(value2 + 4);
      if (value2 == 0) {
        local_5c[2] = local_5c[2] + 1;
      }
      else if (value2 == 1) {
        local_5c[0] = local_5c[0] + 1;
      }
      else if (value2 == 2) {
        local_5c[1] = local_5c[1] + 1;
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  ptr4 = local_5c;
  value5 = 0x2352;
  do {
    value1 = *ptr4;
    if (value1 == 0) {
      Gadget_SetTextf(arg1,value5,DAT_00582e4c,unaff_EDI);
    }
    else {
      Gadget_SetTextf(arg1,value5,&DAT_005686f4,value1);
      UI_DrawAwardMedals(arg1,value5 + -3,value1,value5 + -0x2352);
    }
    ptr4 = ptr4 + 1;
    value1 = value5 + -0x2351;
    value5 = value5 + 1;
  } while (value1 < 3);
  return;
}
