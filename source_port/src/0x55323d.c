// CRT_BuildCatchObject: ported from Pizza Connection 2 at 0x55323d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55323d
#include "pc2_port.h"

void __cdecl CRT_BuildCatchObject(int arg1,int arg2,uint8_t *arg3,uint8_t *arg4)

{
  int *ptr1;
  bool flag2;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  int value3;
  uint32_t extraout_var_01;
  uint32_t extraout_var_02;
  uint32_t extraout_var_03;
  uint32_t extraout_var_04;
  uint32_t *uptr4;
  uint32_t extraout_var_05;
  uint32_t extraout_var_06;
  uint32_t extraout_var_07;
  uint32_t uvalue5;
  void *local_14;
  uint8_t *puStack_10;
  uint8_t *puStack_c;
  uint32_t local_8;
  
  puStack_c = &DAT_0055ce40;
  puStack_10 = &LAB_00553be0;
  local_14 = ExceptionList;
  if (*(int *)(arg3 + 4) == 0) {
    return;
  }
  if (*(char *)(*(int *)(arg3 + 4) + 8) == '\0') {
    return;
  }
  if (*(int *)(arg3 + 8) == 0) {
    return;
  }
  ptr1 = (int *)(*(int *)(arg3 + 8) + 0xc + arg2);
  local_8 = 0;
  if ((*arg3 & 8) == 0) {
    if ((*arg4 & 1) == 0) {
      if (*(int *)(arg4 + 0x18) == 0) {
        ExceptionList = &local_14;
        flag2 = FUN_00555f86(*(void **)(arg1 + 0x18),1);
        if ((CONCAT31(extraout_var_03,flag2) != 0) &&
           (flag2 = FUN_00555fa2(ptr1,1), CONCAT31(extraout_var_04,flag2) != 0)) {
          uvalue5 = *(uint32_t *)(arg4 + 0x14);
          uptr4 = (uint32_t *)
                   CRT_ResolveCatchObject(*(int *)(arg1 + 0x18),(int *)(arg4 + 8));
          _memmove(ptr1,uptr4,uvalue5);
          ExceptionList = local_14;
          return;
        }
      }
      else {
        ExceptionList = &local_14;
        flag2 = FUN_00555f86(*(void **)(arg1 + 0x18),1);
        if (((CONCAT31(extraout_var_05,flag2) != 0) &&
            (flag2 = FUN_00555fa2(ptr1,1), CONCAT31(extraout_var_06,flag2) != 0)) &&
           (flag2 = FUN_00555fbe(*(FARPROC *)(arg4 + 0x18)), CONCAT31(extraout_var_07,flag2) != 0
           )) {
          if ((*arg4 & 4) == 0) {
            CRT_ResolveCatchObject(*(int *)(arg1 + 0x18),(int *)(arg4 + 8));
            CRT_LockStub(ptr1,*(uint8_t **)(arg4 + 0x18));
            ExceptionList = local_14;
            return;
          }
          CRT_ResolveCatchObject(*(int *)(arg1 + 0x18),(int *)(arg4 + 8));
          CRT_UnlockHelper(ptr1,*(uint8_t **)(arg4 + 0x18));
          ExceptionList = local_14;
          return;
        }
      }
    }
    else {
      ExceptionList = &local_14;
      flag2 = FUN_00555f86(*(void **)(arg1 + 0x18),1);
      if ((CONCAT31(extraout_var_01,flag2) != 0) &&
         (flag2 = FUN_00555fa2(ptr1,1), CONCAT31(extraout_var_02,flag2) != 0)) {
        _memmove(ptr1,*(uint32_t **)(arg1 + 0x18),*(uint32_t *)(arg4 + 0x14));
        if (*(int *)(arg4 + 0x14) != 4) {
          ExceptionList = local_14;
          return;
        }
        value3 = *ptr1;
        if (value3 == 0) {
          ExceptionList = local_14;
          return;
        }
        goto LAB_005532cb;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    flag2 = FUN_00555f86(*(void **)(arg1 + 0x18),1);
    if ((CONCAT31(extraout_var,flag2) != 0) &&
       (flag2 = FUN_00555fa2(ptr1,1), CONCAT31(extraout_var_00,flag2) != 0)) {
      value3 = *(int *)(arg1 + 0x18);
      *ptr1 = value3;
LAB_005532cb:
      value3 = CRT_ResolveCatchObject(value3,(int *)(arg4 + 8));
      *ptr1 = value3;
      ExceptionList = local_14;
      return;
    }
  }
  CRT_Inconsistency();
  ExceptionList = local_14;
  return;
}
