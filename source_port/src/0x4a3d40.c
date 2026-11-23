// CompanyProfile_UpdateStatistics: ported from Pizza Connection 2 at 0x4a3d40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a3d40
#include "pc2_port.h"

void __cdecl CompanyProfile_UpdateStatistics(void *arg1)

{
  void *self;
  void *pvVar1;
  int value2;
  int value3;
  int value4;
  int value5;
  int *ptr6;
  double fVar7;
  
                    /* Fills the company-profile statistics block and city chart. */
  pvVar1 = arg1;
  value3 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  Gadget_SetTextf(arg1,0x23e2,&DAT_005686f4,*(uint32_t *)(value3 + 0x70));
  Gadget_SetTextf(arg1,0x23e3,&DAT_005686f4,*(int *)(value3 + 0x88) + *(int *)(value3 + 0x74));
  Gadget_SetTextf(arg1,0x23ea,&DAT_005686f4,*(uint32_t *)(value3 + 0x78));
  Gadget_SetTextf(arg1,0x23eb,&DAT_005686f4,*(uint32_t *)(value3 + 0x7c));
  Gadget_SetTextf(arg1,0x23ee,&DAT_005686f4,*(uint32_t *)(value3 + 0x80));
  Gadget_SetTextf(arg1,0x23ef,&DAT_005686f4,*(uint32_t *)(value3 + 0x84));
  Gadget_SetTextf(arg1,0x2379,&DAT_005686f4,*(uint32_t *)(value3 + 0x15c));
  Gadget_SetTextf(arg1,0x23f6,&DAT_005686f4,*(uint32_t *)(value3 + 0x194));
  fVar7 = Stats_SumFilteredFloats3(value3,-1,-1,-1);
  Gadget_SetTextf(arg1,0x237a,(uint8_t *)s__0_2f___005688b0,SUB84((double)fVar7,0));
  value4 = *(int *)(value3 + 0x48);
  value5 = 0;
  value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  Gadget_SetTextf(arg1,0x2374,&DAT_005686f4,*(uint32_t *)(value2 + 0xc20 + value4 * 4));
  self = *(void **)(value3 + 0x1d8);
  if (self == (void *)0x0) {
    Gadget_SetTextf(arg1,0x2380,&DAT_005686f4,0);
    Gadget_SetTextf(arg1,0x2382,&DAT_005686f4,0);
    Gadget_SetTextf(arg1,0x2383,&DAT_005686f4,0);
  }
  else {
    value3 = Game_CountFreeBuildingsByType(self,0x17);
    Gadget_SetTextf(arg1,0x2380,&DAT_005686f4,value3);
    value3 = Game_CountFreeBuildingsByType(self,0x1e);
    Gadget_SetTextf(arg1,0x2382,&DAT_005686f4,value3);
    value3 = Game_CountFreeBuildingsByType(self,0x1d);
    Gadget_SetTextf(arg1,0x2383,&DAT_005686f4,value3);
  }
  arg1 = (void *)0x0;
  ptr6 = &DAT_0057d24c;
  do {
    value3 = Game_GetPlayerBySlot(DAT_0057c670,value5);
    if (value3 == 0) {
      *ptr6 = 0;
    }
    else {
      value4 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      value3 = *(int *)(value3 + 0x94 + value4 * 4);
      *ptr6 = value3;
      if (0 < value3) {
        arg1 = (void *)((intptr_t)arg1 + 1);
      }
    }
    ptr6 = ptr6 + 1;
    value5 = value5 + 1;
  } while ((intptr_t)ptr6 < 0x57d264);
  HeadquartersPage_FillCompetitorRows(pvVar1,DAT_0057d248,(intptr_t)arg1);
  return;
}
