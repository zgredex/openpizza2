// HighScore_UpdatePlayerEntry: ported from Pizza Connection 2 at 0x48e270.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48e270
#include "pc2_port.h"


void __fastcall HighScore_UpdatePlayerEntry(void *arg1)

{
  int value1;
  uint32_t *self;
  uint32_t uvalue2;
  int value3;
  uint32_t *this_00;
  BYTE *pBVar4;
  char *cptr5;
  int local_240;
  void *local_23c;
  BYTE local_238 [64];
  int local_1f8;
  uint8_t local_1f4 [64];
  int local_1b4;
  uint8_t local_1b0 [64];
  int local_170;
  uint8_t local_16c [64];
  int local_12c;
  char local_128 [64];
  int local_e8 [6];
  uint8_t local_d0 [64];
  int local_90;
  CHAR local_8c [64];
  char local_4c [64];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055840e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  Game_BuildPlayerRankingData(arg1,local_e8);
  value3 = *(int *)(local_e8[*(int *)(*(int *)(DAT_0057c670 + 0x200 +
                                             *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x48)] + 0x11c);
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  String_Format(local_8c,(uint8_t *)s__s_hi_00568368,value1 + 0x44);
  value1 = HighScore_ReadRegistryBlob(local_8c,local_238);
  if (value1 == 0) {
    value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
    String_Format(local_4c,(uint8_t *)s_names__s_txt_00568358,value1 + 0x44);
    local_23c = operator_new(0x18);
    local_4 = 0;
    if (local_23c == (void *)0x0) {
      self = (uint32_t *)0x0;
    }
    else {
      self = FileObject_Open(local_23c,DAT_0057c5d8,local_4c,&local_240);
    }
    local_4 = 0xffffffff;
    if (local_240 != 0) {
      self = (uint32_t *)0x0;
    }
    pBVar4 = local_238;
    for (value1 = 0x33; value1 != 0; value1 = value1 + -1) {
      pBVar4[0] = '\0';
      pBVar4[1] = '\0';
      pBVar4[2] = '\0';
      pBVar4[3] = '\0';
      pBVar4 = pBVar4 + 4;
    }
    local_1f8 = value3;
    value1 = Game_GetPlayerCity(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4));
    String_Format(local_238,&DAT_005630d0,value1 + 0xc);
    local_1b4 = value3 / 5;
    local_170 = value3 / 10;
    if (self == (uint32_t *)0x0) {
      cptr5 = local_128;
      uvalue2 = Random_RangeFast(0,1);
      this_00 = DAT_0057ba10;
    }
    else {
      cptr5 = local_128;
      uvalue2 = Random_RangeFast(0,1);
      this_00 = self;
    }
    IDMap_GetRandomName(this_00,uvalue2,cptr5);
    String_Format(local_1f4,&DAT_005630d0,local_128);
    if (self == (uint32_t *)0x0) {
      cptr5 = local_128;
      uvalue2 = Random_RangeFast(0,1);
      self = DAT_0057ba10;
    }
    else {
      cptr5 = local_128;
      uvalue2 = Random_RangeFast(0,1);
    }
    IDMap_GetRandomName(self,uvalue2,cptr5);
    String_Format(local_1b0,&DAT_005630d0,local_128);
  }
  if (local_1f8 < value3) {
    local_12c = local_1f8;
    String_Format(local_16c,&DAT_005630d0,local_238);
    local_90 = local_1b4;
    String_Format(local_d0,&DAT_005630d0,local_1f4);
    local_1f8 = value3;
    value3 = Game_GetPlayerCity(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4));
    String_Format(local_238,&DAT_005630d0,value3 + 0xc);
    local_1b4 = local_12c;
    String_Format(local_1f4,&DAT_005630d0,local_16c);
    local_170 = local_90;
    String_Format(local_1b0,&DAT_005630d0,local_d0);
  }
  else if (local_1b4 < value3) {
    local_12c = local_1b4;
    String_Format(local_16c,&DAT_005630d0,local_1f4);
    local_1b4 = value3;
    value3 = Game_GetPlayerCity(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4));
    String_Format(local_1f4,&DAT_005630d0,value3 + 0xc);
    local_170 = local_12c;
    String_Format(local_1b0,&DAT_005630d0,local_12c);
  }
  else if (local_170 < value3) {
    local_170 = value3;
    value3 = Game_GetPlayerCity(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4));
    String_Format(local_1b0,&DAT_005630d0,value3 + 0xc);
  }
  Config_WriteRegistryBlock(local_8c,local_238);
  ExceptionList = local_c;
  return;
}
