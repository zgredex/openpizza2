// Company_CreateAIStrategy: ported from Pizza Connection 2 at 0x4e3c00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3c00
#include "pc2_port.h"


void __fastcall Company_CreateAIStrategy(int arg1)

{
  char cVar1;
  int value2;
  int value3;
  void *pvVar4;
  char *cptr5;
  uint8_t *bptr6;
  uint32_t uvalue7;
  uint32_t uvalue8;
  char *cptr9;
  char *cptr10;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00559526;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  if (*(uint32_t **)(arg1 + 0x1d4) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)(arg1 + 0x1d4))(1);
  }
  value3 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  if (*(int *)(arg1 + 0x48) != value3) {
    uvalue7 = *(uint32_t *)(value2 + 0x1148);
    Random_RangeFast(0,2);
    pvVar4 = operator_new(0x330);
    uStack_4 = 1;
    if (pvVar4 == (void *)0x0) {
      bptr6 = (uint8_t *)0x0;
    }
    else {
      bptr6 = Recipe_CreateGenerated
                         (pvVar4,*(int *)(arg1 + 0x48),uvalue7,2,*(float *)(value2 + 0xc1c),-1);
    }
    *(uint8_t **)(arg1 + 0x1d4) = bptr6;
    ExceptionList = pvStack_c;
    return;
  }
  pvVar4 = operator_new(0x330);
  uStack_4 = 0;
  if (pvVar4 == (void *)0x0) {
    cptr5 = (char *)0x0;
  }
  else {
    cptr5 = (char *)Recipe_Construct(pvVar4,(int *)0x0,'\0');
  }
  uvalue7 = 0xffffffff;
  cptr10 = (char *)(&DAT_005834d4)[*(int *)(value2 + 0x1148)];
  do {
    cptr9 = cptr10;
    if (uvalue7 == 0) break;
    uvalue7 = uvalue7 - 1;
    cptr9 = cptr10 + 1;
    cVar1 = *cptr10;
    cptr10 = cptr9;
  } while (cVar1 != '\0');
  uvalue7 = ~uvalue7;
  cptr9 = cptr9 + -uvalue7;
  cptr10 = cptr5;
  for (uvalue8 = uvalue7 >> 2; cptr10 = cptr10 + 4, uvalue8 != 0; uvalue8 = uvalue8 - 1) {
    *(uint32_t *)cptr10 = *(uint32_t *)cptr9;
    cptr9 = cptr9 + 4;
  }
  for (uvalue7 = uvalue7 & 3; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
    *cptr10 = *cptr9;
    cptr9 = cptr9 + 1;
    cptr10 = cptr10 + 1;
  }
  *(char **)(arg1 + 0x1d4) = cptr5;
  ExceptionList = pvStack_c;
  return;
}
