// Recipe_ImportFile: ported from Pizza Connection 2 at 0x49ba50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49ba50
#include "pc2_port.h"


bool __cdecl Recipe_ImportFile(int arg1)

{
  uint8_t *bptr1;
  uint8_t flag2;
  uint32_t uvalue3;
  HANDLE pvVar4;
  int value5;
  uint32_t *uptr6;
  uint8_t *bptr7;
  void *self;
  int *this_00;
  int value8;
  uint8_t *bptr9;
  bool flag10;
  int local_23c;
  void *local_238;
  int *local_234;
  uint32_t *local_230;
  int local_22c;
  void *local_228;
  uint32_t local_224 [5];
  uint8_t local_210 [260];
  uint8_t local_10c [256];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055874c;
  local_c = ExceptionList;
  local_23c = 0;
  ExceptionList = &local_c;
  pvVar4 = CRT_FindFirst(s_save_menu___men_00568a34,local_224);
  if (pvVar4 != (HANDLE)0xffffffff) {
    do {
      if (local_23c == arg1) {
        String_Format(local_10c,(uint8_t *)s_save_menu__s_00568a58,local_210);
        break;
      }
      local_23c = local_23c + 1;
      value5 = CRT_FindNext(pvVar4,local_224);
    } while (value5 != -1);
    CRT_FindClose(pvVar4);
    local_228 = operator_new(0x5c);
    local_4 = 0;
    if (local_228 == (void *)0x0) {
      local_234 = (int *)0x0;
    }
    else {
      local_234 = CRT_Ifstream_Construct();
    }
    this_00 = local_234;
    local_4 = 0xffffffff;
    if ((*(uint8_t *)(*(int *)(*local_234 + 4) + 8 + (intptr_t)local_234) & 6) == 0) {
      self = *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
      value5 = *(int *)((intptr_t)self + 0x124);
      local_238 = self;
      local_22c = value5;
      Game_AcquireStateLock(DAT_0057c670,0);
      CRT_Istream_Read(this_00,&DAT_0057c668,4);
      if ((0x29 < DAT_0057c668) && (DAT_0057c668 < 0x2f)) {
        UI_RemoveAllObjects(*(void **)((intptr_t)DAT_0057c670 + 0x25c));
        value8 = 0;
        if (0 < value5) {
          do {
            value5 = IDMap_Lookup((void *)((intptr_t)self + 0x110),value8,(int *)0x0);
            Recipe_SetOnMenu(self,value5,0);
            value8 = value8 + 1;
          } while (value8 < local_22c);
        }
        CRT_Istream_Read(this_00,&local_23c,4);
        local_228 = (void *)0x0;
        if (0 < local_23c) {
          do {
            local_230 = operator_new(0x330);
            local_4 = 1;
            if (local_230 == (void *)0x0) {
              local_230 = (uint32_t *)0x0;
            }
            else {
              local_230 = Recipe_Construct(local_230,this_00,'\x01');
            }
            value5 = 0;
            local_4 = 0xffffffff;
            if (0 < local_22c) {
              bptr1 = (uint8_t *)(local_230 + 1);
              do {
                uptr6 = (uint32_t *)
                         IDMap_Lookup((void *)((intptr_t)local_238 + 0x110),value5,(int *)0x0);
                bptr7 = (uint8_t *)(uptr6 + 1);
                bptr9 = bptr1;
                do {
                  flag2 = *bptr7;
                  flag10 = flag2 < *bptr9;
                  if (flag2 != *bptr9) {
LAB_0049bc8d:
                    value8 = (1 - (uint32_t)flag10) - (uint32_t)(flag10 != 0);
                    goto LAB_0049bc92;
                  }
                  if (flag2 == 0) break;
                  flag2 = bptr7[1];
                  flag10 = flag2 < bptr9[1];
                  if (flag2 != bptr9[1]) goto LAB_0049bc8d;
                  bptr7 = bptr7 + 2;
                  bptr9 = bptr9 + 2;
                } while (flag2 != 0);
                value8 = 0;
LAB_0049bc92:
                if (value8 == 0) {
                  Company_RemoveRecipe(local_238,uptr6);
                  break;
                }
                value5 = value5 + 1;
              } while (value5 < local_22c);
              self = local_238;
            }
            uptr6 = local_230;
            List_Add((void *)((intptr_t)self + 0x110),local_230);
            Recipe_SetOnMenu(self,(intptr_t)uptr6,1);
            local_228 = (void *)((intptr_t)local_228 + 1);
            this_00 = local_234;
          } while ((intptr_t)local_228 < local_23c);
        }
        uvalue3 = *(uint32_t *)(*(int *)(*this_00 + 4) + 8 + (intptr_t)this_00);
        if (this_00 != (int *)0x0) {
          (*(code *)**(uint32_t **)(*(int *)(*this_00 + 4) + (intptr_t)this_00))(1);
        }
        Company_InvalidateAllBranchRatings((intptr_t)self);
        Window_UnlockState((intptr_t)DAT_0057c670);
        ExceptionList = local_c;
        return (uvalue3 & 6) == 0;
      }
      if (this_00 != (int *)0x0) {
        (*(code *)**(uint32_t **)(*(int *)(*this_00 + 4) + (intptr_t)this_00))(1);
      }
      Window_UnlockState((intptr_t)DAT_0057c670);
    }
    else if (local_234 != (int *)0x0) {
      (*(code *)**(uint32_t **)(*(int *)(*local_234 + 4) + (intptr_t)local_234))(1);
    }
  }
  ExceptionList = local_c;
  return false;
}
