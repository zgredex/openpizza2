// CRT_CxxCatchSearch: ported from Pizza Connection 2 at 0x552d0f.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552d0f
#include "pc2_port.h"

struct pc2_obj_0x552d0f_arg1 { intptr_t ExceptionCode; intptr_t NumberParameters; intptr_t ExceptionInformation[1]; };
void __cdecl
CRT_CxxCatchSearch(struct pc2_obj_0x552d0f_arg1 *arg1,PVOID arg2,DWORD arg3,uint32_t arg4,
                  uint32_t arg5,char arg6,int arg7,PVOID arg8)

{
  uint8_t *bptr1;
  bool flag2;
  DWORD *pDVar3;
  uint32_t extraout_var;
  int *ptr4;
  int value5;
  int *ptr6;
  uint32_t local_1c;
  uint32_t local_18;
  int local_14;
  int local_10;
  int local_c;
  uint32_t local_8;
  
                    /* Searches try blocks for a matching typed catch clause. */
  local_18 = local_18 & 0xffffff00;
  local_14 = *(int *)((intptr_t)arg2 + 8);
  if ((local_14 < -1) || (*(int *)(arg5 + 4) <= local_14)) {
    CRT_Inconsistency();
  }
  if (arg1->ExceptionCode == 0xe06d7363) {
    if (((arg1->NumberParameters == 3) && (arg1->ExceptionInformation[0] == 0x19930520)) &&
       (arg1->ExceptionInformation[2] == 0)) {
      pDVar3 = CRT_GetThreadData();
      if (pDVar3[0x1b] == 0) {
        return;
      }
      pDVar3 = CRT_GetThreadData();
      arg1 = (PEXCEPTION_RECORD)pDVar3[0x1b];
      pDVar3 = CRT_GetThreadData();
      arg3 = pDVar3[0x1c];
      local_18 = CONCAT31(((uint8_t)((local_18) >> 24)),1);
      flag2 = FUN_00555f86(arg1,1);
      if (CONCAT31(extraout_var,flag2) == 0) {
        CRT_Inconsistency();
      }
      if (arg1->ExceptionCode != 0xe06d7363) goto LAB_00552e97;
      if (((arg1->NumberParameters == 3) && (arg1->ExceptionInformation[0] == 0x19930520)) &&
         (arg1->ExceptionInformation[2] == 0)) {
        CRT_Inconsistency();
      }
    }
    value5 = local_14;
    if (((arg1->ExceptionCode == 0xe06d7363) && (arg1->NumberParameters == 3)) &&
       (arg1->ExceptionInformation[0] == 0x19930520)) {
      ptr4 = (int *)CRT_FindTryBlockRange(arg5,arg7,local_14,&local_8,&local_1c);
      do {
        if (local_1c <= local_8) {
          if (arg6 == '\0') {
            return;
          }
          CRT_InvokeExceptionHandler((intptr_t)arg1);
          return;
        }
        if ((*ptr4 <= value5) && (value5 <= ptr4[1])) {
          bptr1 = (uint8_t *)ptr4[4];
          for (local_10 = ptr4[3]; 0 < local_10; local_10 = local_10 + -1) {
            ptr6 = *(int **)(arg1->ExceptionInformation[2] + 0xc);
            for (local_c = *ptr6; 0 < local_c; local_c = local_c + -1) {
              ptr6 = ptr6 + 1;
              value5 = CRT_ExceptionTypeMatch
                                (bptr1,(uint8_t *)*ptr6,(uint32_t *)arg1->ExceptionInformation[2]);
              if (value5 != 0) {
                CRT_CatchIt(arg1,arg2,arg3,arg4,arg5,bptr1,(uint8_t *)*ptr6,ptr4,
                            arg7,arg8);
                goto LAB_00552e74;
              }
            }
            bptr1 = bptr1 + 0x10;
          }
LAB_00552e74:
          value5 = local_14;
        }
        local_8 = local_8 + 1;
        ptr4 = ptr4 + 5;
      } while( true );
    }
  }
LAB_00552e97:
  if (arg6 == '\0') {
    CRT_CxxCatchAllSearch(arg1,arg2,arg3,arg4,arg5,local_14,arg7,arg8);
    return;
  }
  CRT_Terminate();
  return;
}
