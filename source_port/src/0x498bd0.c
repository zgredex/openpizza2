// SaveMenu_Load: ported from Pizza Connection 2 at 0x498bd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x498bd0
#include "pc2_port.h"


uint32_t __cdecl SaveMenu_Load(int arg1)

{
  uint8_t flag1;
  int value2;
  HANDLE pvVar3;
  int value4;
  void *pvVar5;
  int *self;
  int value6;
  uint8_t *bptr7;
  uint32_t *uptr8;
  uint8_t *bptr9;
  int value10;
  bool flag11;
  uint32_t *local_36c;
  uint8_t local_364 [64];
  uint32_t local_324 [5];
  uint8_t local_310 [260];
  uint8_t local_20c [512];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055862c;
  local_c = ExceptionList;
  value10 = 0;
  ExceptionList = &local_c;
  pvVar3 = CRT_FindFirst(s_save_piz___piz_005688d0,local_324);
  if (pvVar3 != (HANDLE)0xffffffff) {
    do {
      if (value10 == arg1) {
        String_Format(local_20c,(uint8_t *)s_save_piz__s_005688e0,local_310);
        break;
      }
      value10 = value10 + 1;
      value4 = CRT_FindNext(pvVar3,local_324);
    } while (value4 != -1);
    CRT_FindClose(pvVar3);
    pvVar5 = operator_new(0x5c);
    value10 = 0;
    local_4 = 0;
    if (pvVar5 == (void *)0x0) {
      self = (int *)0x0;
    }
    else {
      self = CRT_Ifstream_Construct();
    }
    local_4 = 0xffffffff;
    if ((*(uint8_t *)(*(int *)(*self + 4) + 8 + (intptr_t)self) & 6) == 0) {
      CRT_Istream_Read(self,&DAT_0057c668,4);
      if ((DAT_0057c668 < 0x2a) || (0x2e < DAT_0057c668)) {
        if (self != (int *)0x0) {
          (*(code *)**(uint32_t **)(*(int *)(*self + 4) + (intptr_t)self))(1);
        }
      }
      else {
        pvVar5 = operator_new(0x330);
        local_4 = 1;
        if (pvVar5 == (void *)0x0) {
          local_36c = (uint32_t *)0x0;
        }
        else {
          local_36c = Recipe_Construct(pvVar5,self,'\x01');
        }
        local_4 = 0xffffffff;
        uptr8 = (uint32_t *)(*(int *)(*self + 4) + (intptr_t)self);
        if ((*(uint8_t *)(*(int *)(*self + 4) + 8 + (intptr_t)self) & 6) == 0) {
          if (self != (int *)0x0) {
            (**(code **)*uptr8)(1);
          }
          String_Format(local_364,&DAT_005630d0,local_36c + 1);
          value4 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
          value2 = *(int *)(value4 + 0x124);
          if (0 < value2) {
            do {
              value6 = IDMap_Lookup((void *)(value4 + 0x110),value10,(int *)0x0);
              bptr9 = local_364;
              bptr7 = (uint8_t *)(value6 + 4);
              do {
                flag1 = *bptr7;
                flag11 = flag1 < *bptr9;
                if (flag1 != *bptr9) {
LAB_00498dba:
                  value6 = (1 - (uint32_t)flag11) - (uint32_t)(flag11 != 0);
                  goto LAB_00498dbf;
                }
                if (flag1 == 0) break;
                flag1 = bptr7[1];
                flag11 = flag1 < bptr9[1];
                if (flag1 != bptr9[1]) goto LAB_00498dba;
                bptr7 = bptr7 + 2;
                bptr9 = bptr9 + 2;
              } while (flag1 != 0);
              value6 = 0;
LAB_00498dbf:
              if (value6 == 0) {
                ExceptionList = local_c;
                return 2;
              }
              value10 = value10 + 1;
            } while (value10 < value2);
          }
          List_Add((void *)(value4 + 0x110),local_36c);
          ExceptionList = local_c;
          return 1;
        }
        if (self != (int *)0x0) {
          (**(code **)*uptr8)(1);
        }
      }
    }
    else if (self != (int *)0x0) {
      (*(code *)**(uint32_t **)(*(int *)(*self + 4) + (intptr_t)self))(1);
    }
  }
  ExceptionList = local_c;
  return 0;
}
