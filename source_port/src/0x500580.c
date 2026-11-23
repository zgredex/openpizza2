// Font_DrawGlyphPattern: ported from Pizza Connection 2 at 0x500580.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x500580
#include "pc2_port.h"

uint32_t __cdecl
Font_DrawGlyphPattern(int arg1,int *arg2,int *arg3,int arg4,int arg5,int *arg6)

{
  uint8_t *uptr1;
  int *ptr2;
  uint32_t uvalue3;
  int value4;
  uint32_t uvalue5;
  int *ptr6;
  int value7;
  int *ptr8;
  int local_4;
  
  local_4 = 0;
  uvalue5 = 6;
  switch(arg5) {
  case 0:
  case 0x15:
    uvalue5 = Random_Mod(3);
    ptr2 = (int *)(&PTR_s_ss_ss_tttt_ssttttss_ssttttss_ttt_00572214)[uvalue5];
    uvalue5 = 0xc;
    local_4 = 0xc;
    break;
  case 1:
    NoOp_Stub();
  case 2:
    uvalue5 = 6;
    local_4 = 1;
    ptr2 = (int *)PTR_s__00572220;
    break;
  case 3:
    uvalue5 = Random_Mod(1);
    ptr2 = (int *)(&PTR_s__00572224)[uvalue5];
    uvalue5 = 6;
    local_4 = 3;
    break;
  default:
    NoOp_Stub();
    ptr2 = arg3;
    break;
  case 6:
    uvalue5 = Random_Mod(1);
    ptr2 = (int *)(&PTR_s__0057222c)[uvalue5];
    uvalue5 = 6;
    local_4 = 3;
    break;
  case 7:
    uvalue5 = Random_Mod(1);
    ptr2 = (int *)(&PTR_s__00572230)[uvalue5];
    uvalue5 = 6;
    local_4 = 4;
    break;
  case 0x14:
    uvalue5 = Random_Mod(1);
    ptr2 = (int *)(&PTR_s__00572228)[uvalue5];
    local_4 = 2;
    uvalue5 = 6;
  }
  if (arg4 == 2) {
    if (local_4 != 0) {
      arg5 = local_4;
      do {
        ptr6 = ptr2;
        ptr8 = (int *)(*arg2 * 0x50 + *arg3 + 0x28 + arg1);
        for (uvalue3 = uvalue5 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
          *ptr8 = *ptr6;
          ptr6 = ptr6 + 1;
          ptr8 = ptr8 + 1;
        }
        for (uvalue3 = uvalue5 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
          *(char *)ptr8 = (char)*ptr6;
          ptr6 = (int *)((intptr_t)ptr6 + 1);
          ptr8 = (int *)((intptr_t)ptr8 + 1);
        }
        arg5 = arg5 + -1;
        *arg2 = *arg2 + -1;
        ptr2 = (int *)((intptr_t)ptr2 + uvalue5);
      } while (arg5 != 0);
    }
  }
  else if (arg4 == 3) {
    if (local_4 != 0) {
      arg5 = local_4;
      do {
        value7 = 0;
        if (uvalue5 != 0) {
          do {
            value4 = *arg2 * 0x50 - value7;
            uptr1 = (uint8_t *)(value7 + (intptr_t)ptr2);
            value7 = value7 + 1;
            *(uint8_t *)(value4 + *arg3 + 0x28 + arg1) = *uptr1;
          } while (value7 < (intptr_t)uvalue5);
        }
        ptr2 = (int *)((intptr_t)ptr2 + uvalue5);
        arg5 = arg5 + -1;
        *arg2 = *arg2 + -1;
      } while (arg5 != 0);
    }
  }
  else if (arg4 == 0) {
    if (local_4 != 0) {
      arg5 = local_4;
      do {
        value7 = 0;
        if (uvalue5 != 0) {
          do {
            value4 = *arg2 + value7;
            uptr1 = (uint8_t *)(value7 + (intptr_t)ptr2);
            value7 = value7 + 1;
            *(uint8_t *)(value4 * 0x50 + *arg3 + 0x28 + arg1) = *uptr1;
          } while (value7 < (intptr_t)uvalue5);
        }
        ptr2 = (int *)((intptr_t)ptr2 + uvalue5);
        arg5 = arg5 + -1;
        *arg3 = *arg3 + 1;
      } while (arg5 != 0);
    }
  }
  else if ((arg4 == 1) && (local_4 != 0)) {
    arg5 = local_4;
    do {
      value7 = 0;
      if (uvalue5 != 0) {
        do {
          value4 = *arg2 - value7;
          uptr1 = (uint8_t *)(value7 + (intptr_t)ptr2);
          value7 = value7 + 1;
          *(uint8_t *)(value4 * 0x50 + *arg3 + 0x28 + arg1) = *uptr1;
        } while (value7 < (intptr_t)uvalue5);
      }
      ptr2 = (int *)((intptr_t)ptr2 + uvalue5);
      arg5 = arg5 + -1;
      *arg3 = *arg3 + -1;
    } while (arg5 != 0);
  }
  *arg6 = *arg6 - local_4;
  return uvalue5;
}
