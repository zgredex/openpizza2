// Surface_SaveTga: ported from Pizza Connection 2 at 0x5377f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5377f0
#include "pc2_port.h"

uint32_t
Surface_SaveTga(uint32_t *arg1,uint32_t arg2,uint32_t arg3,uint32_t *arg4,char arg5,
               uint32_t arg6,uint16_t arg7,uint16_t arg8,char arg9,int arg10,
               int arg11,uint32_t arg12,uint8_t arg13,uint8_t arg14)

{
  uint16_t uvalue1;
  uint32_t uvalue2;
  FILE *pFVar3;
  int extraout_ECX;
  int value4;
  uint32_t *uptr5;
  uint32_t *uptr6;
  int value7;
  int value8;
  uint8_t local_res0;
  uint8_t uStack00000015;
  char cStack00000016;
  uint8_t uStack00000017;
  uint16_t uStack0000001e;
  uint16_t uStack00000022;
  uint8_t uStack00000025;
  int in_stack_00010034;
  int in_stack_00010038;
  LPCSTR in_stack_0001003c;
  
  __chkstk(local_res0);
  arg11 = 0;
  pFVar3 = (FILE *)CRT_Fopen(in_stack_0001003c,&DAT_00563114);
  if (pFVar3 == (FILE *)0x0) {
    return 0;
  }
  arg4 = *(uint32_t **)(extraout_ECX + 0x18);
  if (((*(char *)(extraout_ECX + 0x10) == '\x10') && (in_stack_00010034 != 0)) &&
     (*(char *)(in_stack_00010034 + 0x18) != '\0')) {
    value7 = *(int *)(extraout_ECX + 8) * *(int *)(extraout_ECX + 4);
    arg4 = operator_new(value7 * 2);
    value4 = 0;
    if (0 < value7) {
      do {
        uvalue1 = *(uint16_t *)(*(int *)(extraout_ECX + 0x18) + value4 * 2);
        *(uint16_t *)((intptr_t)arg4 + value4 * 2) = uvalue1 >> 1 & 0x7fe0 | uvalue1 & 0x1f;
        value4 = value4 + 1;
      } while (value4 < value7);
    }
    arg11 = 1;
  }
  arg9 = *(char *)(extraout_ECX + 0x10);
  arg5 = '\0';
  if (arg9 != '\b') {
    arg6 = (arg6 & ~(0xffu << 16)) | (((0) & 0xffu) << 16);
    arg6 = (arg6 & ~(0xffffffu << 8)) | (((0) & 0xffffffu) << 8);
    cStack00000016 = (-(in_stack_00010038 != 0) & 8U) + 2;
  }
  else {
    arg6 = (arg6 & ~(0xffu << 16)) | (((0x100) & 0xffu) << 16);
    arg6 = (arg6 & ~(0xffffffu << 8)) | (((0x18) & 0xffffffu) << 8);
    cStack00000016 = (-(in_stack_00010038 != 0) & 8U) + 1;
  }
  uStack00000015 = arg9 == '\b';
  arg8 = *(uint16_t *)(extraout_ECX + 4);
  uStack00000022 = *(uint16_t *)(extraout_ECX + 8);
  uStack00000017 = 0;
  arg6 = (arg6 & ~(0x0u << 8)) | (((0) & 0x0u) << 8);
  arg7 = 0;
  uStack0000001e = 0;
  uStack00000025 = 0x20;
  CRT_FwriteLocked(&arg5,1,0x12,(int *)pFVar3);
  if (*(char *)(extraout_ECX + 0x10) == '\b') {
    Palette_WriteToStream(*(void **)(extraout_ECX + 0x14),(int *)pFVar3);
  }
  arg1 = arg4;
  if (-1 < *(int *)(extraout_ECX + 8) + -1) {
    uptr6 = arg4;
    arg10 = *(int *)(extraout_ECX + 8);
    do {
      value4 = 0;
      if (0 < *(int *)(extraout_ECX + 4)) {
        arg1 = &arg12;
        uptr5 = uptr6;
        do {
          uptr6 = uptr5;
          switch(*(uint8_t *)(extraout_ECX + 0x10)) {
          case 8:
            arg3 = (uint32_t)(uint8_t)*uptr5;
            uptr6 = (uint32_t *)((intptr_t)uptr5 + 1);
            break;
          case 0xf:
          case 0x10:
            arg3 = (uint32_t)(uint16_t)*uptr5;
            uptr6 = (uint32_t *)((intptr_t)uptr5 + 2);
            break;
          case 0x18:
            uptr6 = (uint32_t *)((intptr_t)uptr5 + 3);
            arg3 = (uint32_t)(uint3)*uptr5;
            break;
          case 0x20:
            arg3 = *uptr5;
            uptr6 = uptr5 + 1;
          }
          if (in_stack_00010038 == 0) {
            CRT_FwriteLocked(&local_res0,1,(intptr_t)(*(uint8_t *)(extraout_ECX + 0x10) + 1) >> 3,
                             (int *)pFVar3);
          }
          else {
            *arg1 = arg3;
          }
          value4 = value4 + 1;
          arg1 = arg1 + 1;
          uptr5 = uptr6;
        } while (value4 < *(int *)(extraout_ECX + 4));
        arg1 = uptr6;
      }
      if (in_stack_00010038 != 0) {
        value4 = *(int *)(extraout_ECX + 4);
        value7 = 0;
        if (0 < value4) {
          do {
            value8 = value7 + 1;
            if (value8 < value4) {
              if (value7 + 2 < value4) {
                uvalue2 = (&arg12)[value7];
                if ((uvalue2 == *(uint32_t *)(&arg13 + value7 * 4)) &&
                   (uvalue2 == *(uint32_t *)(&arg14 + value7 * 4))) {
                  if (value8 < value4) {
                    uptr6 = &arg12 + value8;
                    do {
                      if ((value7 + 0x80 <= value8) || (*uptr6 != uvalue2)) break;
                      value8 = value8 + 1;
                      uptr6 = uptr6 + 1;
                    } while (value8 < value4);
                  }
                  CRT_Fputc((value8 - value7) - 1U | 0x80,(int *)pFVar3);
                  CRT_FwriteLocked(&local_res0,1,(intptr_t)(*(uint8_t *)(extraout_ECX + 0x10) + 1) >> 3,
                                   (int *)pFVar3);
                  value7 = value8;
                }
                else {
                  if (value8 < value4) {
                    uptr6 = &arg12 + value8;
                    do {
                      if ((value7 + 0x80 <= value8) ||
                         ((*uptr6 == uptr6[1] && (*uptr6 == uptr6[2])))) break;
                      value8 = value8 + 1;
                      uptr6 = uptr6 + 1;
                    } while (value8 < value4);
                  }
                  value4 = value8 - value7;
                  CRT_Fputc(value4 - 1,(int *)pFVar3);
                  if (value7 < value8) {
                    value7 = value7 + value4;
                    do {
                      CRT_FwriteLocked(&local_res0,1,(intptr_t)(*(uint8_t *)(extraout_ECX + 0x10) + 1) >> 3,
                                       (int *)pFVar3);
                      value4 = value4 + -1;
                    } while (value4 != 0);
                  }
                }
                uptr6 = arg1;
              }
              else {
                CRT_Fputc(1,(int *)pFVar3);
                CRT_FwriteLocked(&local_res0,1,(intptr_t)(*(uint8_t *)(extraout_ECX + 0x10) + 1) >> 3,
                                 (int *)pFVar3);
                CRT_FwriteLocked(&local_res0,1,(intptr_t)(*(uint8_t *)(extraout_ECX + 0x10) + 1) >> 3,
                                 (int *)pFVar3);
                value7 = *(int *)(extraout_ECX + 4);
              }
            }
            else {
              CRT_Fputc(0,(int *)pFVar3);
              CRT_FwriteLocked(&local_res0,1,(intptr_t)(*(uint8_t *)(extraout_ECX + 0x10) + 1) >> 3,
                               (int *)pFVar3);
              value7 = *(int *)(extraout_ECX + 4);
            }
            value4 = *(int *)(extraout_ECX + 4);
          } while (value7 < value4);
        }
      }
      arg10 = arg10 + -1;
    } while (arg10 != 0);
    arg10 = 0;
  }
  CRT_Fclose(pFVar3);
  if (arg11 != 0) {
    Mem_Free(arg4);
  }
  return 1;
}
