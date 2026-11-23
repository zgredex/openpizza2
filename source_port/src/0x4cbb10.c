// FreePlaySetup_FillHighScoreTable: ported from Pizza Connection 2 at 0x4cbb10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cbb10
#include "pc2_port.h"


void __cdecl FreePlaySetup_FillHighScoreTable(void *arg1)

{
  uint8_t *uptr1;
  int value2;
  uint32_t *uptr3;
  uint32_t uvalue4;
  uint32_t *self;
  int value5;
  BYTE *pBVar6;
  int *ptr7;
  char *cptr8;
  int local_1a0;
  void *local_19c;
  char local_198 [64];
  CHAR local_158 [64];
  char local_118 [64];
  BYTE local_d8 [64];
  int local_98 [35];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558bfe;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uptr1 = NameMap_GetRecordString(&DAT_0057de38,DAT_0057bb40);
  String_Format(local_158,(uint8_t *)s__s_hi_00568368,uptr1);
  value2 = HighScore_ReadRegistryBlob(local_158,local_d8);
  if (value2 == 0) {
    String_Format(local_118,(uint8_t *)s_names__s_txt_00568358,uptr1);
    local_19c = operator_new(0x18);
    local_4 = 0;
    if (local_19c == (void *)0x0) {
      uptr3 = (uint32_t *)0x0;
    }
    else {
      uptr3 = FileObject_Open(local_19c,DAT_0057c5d8,local_118,&local_1a0);
    }
    local_4 = 0xffffffff;
    if (local_1a0 != 0) {
      uptr3 = (uint32_t *)0x0;
    }
    value5 = 30000;
    pBVar6 = local_d8;
    for (value2 = 0x33; value2 != 0; value2 = value2 + -1) {
      pBVar6[0] = '\0';
      pBVar6[1] = '\0';
      pBVar6[2] = '\0';
      pBVar6[3] = '\0';
      pBVar6 = pBVar6 + 4;
    }
    ptr7 = local_98;
    do {
      if (uptr3 == (uint32_t *)0x0) {
        cptr8 = local_198;
        uvalue4 = Random_RangeFast(0,1);
        self = DAT_0057ba10;
      }
      else {
        cptr8 = local_198;
        uvalue4 = Random_RangeFast(0,1);
        self = uptr3;
      }
      IDMap_GetRandomName(self,uvalue4,cptr8);
      String_Format((uint8_t *)(ptr7 + -0x10),&DAT_005630d0,local_198);
      *ptr7 = value5;
      value5 = value5 + -10000;
      ptr7 = ptr7 + 0x11;
    } while (0 < value5);
    if (uptr3 != (uint32_t *)0x0) {
      (**(code **)*uptr3)(1);
    }
    Config_WriteRegistryBlock(local_158,local_d8);
  }
  ptr7 = local_98;
  value2 = 0x495;
  do {
    Window_GadgetNotify_Text_SetText(arg1,value2 + -3,ptr7 + -0x10);
    Gadget_SetTextf(arg1,value2,&DAT_005686f4,*ptr7);
    ptr7 = ptr7 + 0x11;
    value5 = value2 + -0x494;
    value2 = value2 + 1;
  } while (value5 < 3);
  ExceptionList = local_c;
  return;
}
