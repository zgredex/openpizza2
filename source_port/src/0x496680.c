// CompareScreen_UpdateRows: ported from Pizza Connection 2 at 0x496680.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x496680
#include "pc2_port.h"

void __cdecl CompareScreen_UpdateRows(void *arg1,int arg2,int arg3)

{
  int value1;
  int value2;
  void *self;
  int value3;
  double fVar4;
  uint32_t uvalue5;
  char *cptr6;
  int local_254;
  int local_250;
  int local_24c;
  int local_248;
  int local_244;
  int local_240;
  uint32_t local_23c;
  float local_238;
  uint32_t local_234;
  void *local_230;
  uint32_t local_22c;
  uint8_t local_228 [32];
  char local_208 [516];
  
  local_24c = DAT_0057c704;
  local_234 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  local_230 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_240 = *(int *)(DAT_0057c670 + 0x9c);
  value1 = *(int *)(local_240 + 0x3c);
  if (arg3 == 1000) {
    local_250 = *(int *)(local_240 + 0x14a8);
  }
  else {
    local_250 = arg3;
  }
  if (DAT_0057c704 < 7) {
    arg2 = 0;
  }
  else {
    local_24c = 6;
  }
  local_254 = 0;
  value2 = DAT_0057c670;
  if (-1 < local_24c) {
    do {
      if (local_254 == 0) {
        self = *(void **)(*(int *)(value2 + 0x9c) + 0x14dc);
        if (self != (void *)0x0) {
          value2 = 0x4f7;
          local_248 = 0x51d;
          value3 = 0x4f7;
LAB_0049677b:
          Gadget_SetTextf(arg1,value2,&DAT_005630d0,(intptr_t)self + 4);
          switch(DAT_0057c708) {
          case 0:
            fVar4 = Branch_ComputeRecipePrice((intptr_t)self,local_240,local_250);
            String_Format(local_228,(uint8_t *)s__0_2f_005685f4,SUB84((double)fVar4,0));
            local_244 = local_250;
            Branch_GetRecipePriceParts(self,local_240,&local_22c,&local_238,&local_244,&local_23c);
            String_Format(local_208,(uint8_t *)s___2f___s_x__03d____s_x__03d____s_005687fc,
                          SUB84((double)local_238,0));
            cptr6 = local_208;
            goto LAB_004968b2;
          case 1:
            fVar4 = Stats_SumValuesByCategory((intptr_t)self,local_234,value1);
            uvalue5 = SUB84((double)fVar4,0);
            break;
          case 2:
            fVar4 = Game_ComputeCompanySharePercent(DAT_0057c700,(intptr_t)self,value1);
            uvalue5 = SUB84((double)fVar4,0);
            break;
          case 3:
            fVar4 = Stats_GetMaxCategoryValue((intptr_t)self,value1);
            uvalue5 = SUB84((double)fVar4,0);
            break;
          default:
            goto switchD_0049679c_default;
          }
          String_Format(local_228,(uint8_t *)s__0_2f_005685f4,uvalue5);
          cptr6 = &DAT_00579aec;
LAB_004968b2:
          UI_SetObjectTextByKey(arg1,value3,cptr6);
switchD_0049679c_default:
          Window_GadgetNotify_Text_SetText(arg1,local_248,local_228);
          goto LAB_004968cb;
        }
      }
      else {
        value2 = local_254 + -1;
        self = (void *)Game_GetActiveCompanyById
                                 (local_230,*(int *)(DAT_0057c714 + (value2 + arg2) * 4));
        if (self != (void *)0x0) {
          local_248 = (&DAT_005687dc)[value2];
          value2 = 0x512 - value2;
          value3 = local_254 + 0x501;
          goto LAB_0049677b;
        }
LAB_004968cb:
        value2 = DAT_0057c670;
      }
      local_254 = local_254 + 1;
    } while (local_254 <= local_24c);
  }
  return;
}
