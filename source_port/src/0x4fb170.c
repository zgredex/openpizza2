// CityMap_GenerateLayout: ported from Pizza Connection 2 at 0x4fb170.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fb170
#include "pc2_port.h"


uint32_t
CityMap_GenerateLayout
          (uint32_t arg1,char *arg2,char *arg3,char *arg4,uint32_t arg5,
          uint32_t arg6,uint32_t arg7,uint32_t arg8,int arg9,int arg10,
          int arg11,int arg12,int arg13,int arg14)

{
  void *pvVar1;
  void *self;
  uint32_t *uptr2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int value5;
  int value6;
  int *ptr7;
  int *ptr8;
  int value9;
  int iStack000000f4;
  void *in_stack_000019f4;
  int *in_stack_00001a04;
  char cVar10;
  uint8_t uvalue11;
  uint8_t uStack_9;
  uint8_t *local_8;
  int local_4;
  
  pvVar1 = ExceptionList;
  local_4 = -1;
  local_8 = &LAB_0055a12e;
  uvalue11 = SUB41(ExceptionList,0);
  ExceptionList = (void *)((intptr_t)register0x00000010 + -0xc);
  __chkstk(uvalue11);
  in_stack_00001a04[4] = *(int *)(*in_stack_00001a04 + 0x14e0);
  in_stack_00001a04[1] = *(int *)(*in_stack_00001a04 + 0x38);
  self = operator_new(0x1c);
  if (self == (void *)0x0) {
    uptr2 = (uint32_t *)0x0;
  }
  else {
    uptr2 = List_Construct(self,0x28);
  }
  in_stack_00001a04[3] = (intptr_t)uptr2;
  Game_GetPlayerBySlot(DAT_0057c670,*(int *)(*in_stack_00001a04 + 0x30));
  Map_BuildTerrainGrid((intptr_t)in_stack_00001a04);
  value9 = 0;
  do {
    ptr7 = in_stack_00001a04 + 10;
    ptr8 = &iStack000000f4;
    for (value5 = 0x640; value5 != 0; value5 = value5 + -1) {
      *ptr8 = *ptr7;
      ptr7 = ptr7 + 1;
      ptr8 = ptr8 + 1;
    }
    value5 = Map_GenerateSceneryPatterns((intptr_t)in_stack_00001a04);
    if (value5 == 0) {
      ExceptionList = in_stack_000019f4;
      return 3;
    }
    if (in_stack_00001a04[2] == 0) break;
    local_4 = 0;
    ptr7 = in_stack_00001a04 + 10;
    value5 = 0x50;
    do {
      value6 = 0;
      do {
        switch(*(uint8_t *)((intptr_t)ptr7 + value6)) {
        case 0x53:
        case 0x73:
          break;
        case 0x54:
        case 0x74:
          local_4 = local_4 + 1;
        }
        value6 = value6 + 1;
      } while (value6 < 0x50);
      ptr7 = ptr7 + 0x14;
      value5 = value5 + -1;
    } while (value5 != 0);
    if (in_stack_00001a04[1] * 6 + 10 <= local_4) break;
    if (value9 < 0x13) {
      ptr7 = &iStack000000f4;
      ptr8 = in_stack_00001a04 + 10;
      for (value5 = 0x640; value5 != 0; value5 = value5 + -1) {
        *ptr8 = *ptr7;
        ptr7 = ptr7 + 1;
        ptr8 = ptr8 + 1;
      }
    }
    value9 = value9 + 1;
  } while (value9 < 0x14);
  Object_GetRect100((void *)in_stack_00001a04[4],&arg8,&arg7,&arg6,&arg5);
  if (in_stack_00001a04[2] != 0) {
    value9 = 1;
    if (in_stack_00001a04[1] == 2) {
      value9 = 2;
    }
    CityMap_PlaceBuildingBlocks(in_stack_00001a04,5,'-',value9);
    if (in_stack_00001a04[2] != 0) {
      CityMap_PlaceSceneryProps(in_stack_00001a04);
      uvalue3 = City_ComputeServiceLevel(*in_stack_00001a04);
      CityMap_PlaceHouseBlocks(in_stack_00001a04,uvalue3);
      CityMap_PlaceLargeComplexes(in_stack_00001a04,*(int *)(*in_stack_00001a04 + 0x24));
      value9 = *(int *)(*in_stack_00001a04 + 0x24);
      if (value9 == 0) {
        uvalue3 = Random_Mod(10);
        if (0 < (intptr_t)uvalue3) {
          do {
            value9 = AI_SelectBestPlan(3,4,(intptr_t)in_stack_00001a04,(int *)&local_8,
                                      (uint32_t *)((intptr_t)register0x00000010 + -0xc),2,2);
            if (value9 != -1) {
              ptr7 = &arg10;
              ptr8 = &arg9;
              uvalue4 = Random_Mod((uint32_t)pvVar1);
              City_GetListEndpoints(DAT_0057c670,(intptr_t)local_8,uvalue4,ptr8,ptr7);
              CityMap_StampObjectPattern
                        (in_stack_00001a04,6,4,(int *)s_aa_aa_00572154,(intptr_t)&arg9,1,1,' ');
            }
            uvalue3 = uvalue3 - 1;
          } while (uvalue3 != 0);
        }
      }
      else if (value9 == 2) {
        arg2 = s_bb_bb_aaa_aaacc_aaacc_bb_bb_005720f0;
        arg3 = s_cc_cc_aaa_aaacc_aaacc_bb_bb_0057208c;
        arg4 = s_bb_bb_ccaaa_ccaaa_aaa_cc_cc_00572028;
        uvalue3 = _rand();
        value9 = (uvalue3 & 1) + 1;
        if (value9 != 0) {
          do {
            AI_SelectBestPlan(4,4,(intptr_t)in_stack_00001a04,(int *)&local_8,
                              (uint32_t *)((intptr_t)register0x00000010 + -0xc),3,3);
            ptr7 = &arg10;
            ptr8 = &arg9;
            uvalue3 = Random_Mod((uint32_t)pvVar1);
            City_GetListEndpoints(DAT_0057c670,(intptr_t)local_8,uvalue3,ptr8,ptr7);
            AI_SelectBestPlan(3,4,(intptr_t)in_stack_00001a04,(int *)&local_8,
                              (uint32_t *)((intptr_t)register0x00000010 + -0xc),2,2);
            ptr7 = &arg12;
            ptr8 = &arg11;
            uvalue3 = Random_Mod((uint32_t)pvVar1);
            City_GetListEndpoints(DAT_0057c670,(intptr_t)local_8,uvalue3,ptr8,ptr7);
            AI_SelectBestPlan(3,4,(intptr_t)in_stack_00001a04,(int *)&local_8,
                              (uint32_t *)((intptr_t)register0x00000010 + -0xc),2,2);
            ptr7 = &arg14;
            ptr8 = &arg13;
            uvalue3 = Random_Mod((uint32_t)pvVar1);
            City_GetListEndpoints(DAT_0057c670,(intptr_t)local_8,uvalue3,ptr8,ptr7);
            cVar10 = ' ';
            value6 = 1;
            ptr7 = &arg9;
            value5 = 0;
            uvalue3 = Random_Mod(3);
            CityMap_StampObjectPattern
                      (in_stack_00001a04,9,0xb,(int *)(&arg2)[uvalue3],(intptr_t)ptr7,value5,value6,
                       cVar10);
            value9 = value9 + -1;
          } while (value9 != 0);
        }
      }
      else if (value9 == 3) {
        uvalue3 = _rand();
        value9 = (uvalue3 & 1) + 1;
        if (value9 != 0) {
          do {
            AI_SelectBestPlan(4,3,(intptr_t)in_stack_00001a04,(int *)&local_8,
                              (uint32_t *)((intptr_t)register0x00000010 + -0xc),3,3);
            ptr7 = &arg10;
            ptr8 = &arg9;
            uvalue3 = Random_Mod((uint32_t)pvVar1);
            City_GetListEndpoints(DAT_0057c670,(intptr_t)local_8,uvalue3,ptr8,ptr7);
            AI_SelectBestPlan(3,4,(intptr_t)in_stack_00001a04,(int *)&local_8,
                              (uint32_t *)((intptr_t)register0x00000010 + -0xc),2,2);
            ptr7 = &arg12;
            ptr8 = &arg11;
            uvalue3 = Random_Mod((uint32_t)pvVar1);
            City_GetListEndpoints(DAT_0057c670,(intptr_t)local_8,uvalue3,ptr8,ptr7);
            CityMap_StampObjectPattern
                      (in_stack_00001a04,0xb,7,(int *)s_bbaaa_bbaaabb_aaabb_00571fd8,(intptr_t)&arg9,0
                       ,1,' ');
            value9 = value9 + -1;
          } while (value9 != 0);
        }
      }
    }
  }
  ExceptionList = in_stack_000019f4;
  return 1;
}
