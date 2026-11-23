// Gfx_BlitRectList: ported from Pizza Connection 2 at 0x534e20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534e20
#include "pc2_port.h"

void __thiscall Gfx_BlitRectList(void *self,uint32_t *arg1)

{
  uint32_t *uptr1;
  short *psVar2;
  uint32_t *uptr3;
  uint32_t uvalue4;
  int value5;
  uint32_t *uptr6;
  short svalue7;
  uint32_t uvalue8;
  int value9;
  short svalue10;
  int value11;
  short *psVar12;
  short svalue13;
  int value14;
  short *psVar15;
  uint32_t *local_20;
  int local_1c;
  int local_14;
  uint32_t local_8;
  
  uptr6 = arg1;
  local_20 = (uint32_t *)(((intptr_t)*arg1 < 0) - 1 & *arg1);
  uptr3 = *(uint32_t **)((intptr_t)self + 4);
  if ((intptr_t)uptr3 < (intptr_t)local_20) {
    local_20 = uptr3;
  }
  uptr1 = arg1 + 2;
  arg1 = uptr3;
  if ((intptr_t)*uptr1 <= (intptr_t)uptr3) {
    arg1 = (uint32_t *)*uptr1;
  }
  uvalue8 = uptr6[1];
  uvalue8 = ((intptr_t)uvalue8 < 0) - 1 & uvalue8;
  uvalue4 = *(uint32_t *)((intptr_t)self + 8);
  if ((intptr_t)uvalue4 < (intptr_t)uvalue8) {
    uvalue8 = uvalue4;
  }
  local_8 = uptr6[3];
  if ((intptr_t)uvalue4 < (intptr_t)local_8) {
    local_8 = uvalue4;
  }
  if ((0 < (intptr_t)arg1 - (intptr_t)local_20) && (0 < (intptr_t)(local_8 - uvalue8))) {
    for (; (intptr_t)uvalue8 < (intptr_t)local_8; uvalue8 = uvalue8 + 1) {
      value5 = *(int *)((intptr_t)self + 0x10);
      local_1c = 0;
      psVar2 = (short *)(*(int *)((intptr_t)self + 0x14) + value5 * uvalue8 * 2);
      value9 = *(int *)((intptr_t)self + 0xc);
      svalue13 = (short)local_20;
      svalue10 = (short)arg1;
      psVar12 = psVar2;
      if (0 < value9) {
        do {
          if (*psVar12 == -1) {
            *psVar12 = svalue13;
            psVar12[1] = svalue10;
            break;
          }
          if ((intptr_t)local_20 <= (intptr_t)*psVar12) {
            if ((intptr_t)arg1 < (intptr_t)*psVar12) {
              if (psVar2[value5 + -4] != -1) {
                value11 = *(int *)((intptr_t)self + 4) << 1;
                value14 = 0;
                if (0 < value9 + -1) {
                  psVar15 = psVar2 + 1;
                  do {
                    if ((intptr_t)psVar15[1] - (intptr_t)*psVar15 < value11) {
                      value11 = (intptr_t)psVar15[1] - (intptr_t)*psVar15;
                      local_14 = value14;
                    }
                    value14 = value14 + 1;
                    psVar15 = psVar15 + 2;
                  } while (value14 < value9 + -1);
                }
                _memmove((uint32_t *)(psVar2 + local_14 * 2 + 1),
                         (uint32_t *)(psVar2 + local_14 * 2 + 3),(local_14 * -4 + value5 * 2) - 6);
                psVar2[*(int *)((intptr_t)self + 0xc) * 2 + -2] = -1;
                psVar2[*(int *)((intptr_t)self + 0xc) * 2 + -1] = -1;
                if (local_14 < local_1c) {
                  psVar12 = psVar12 + -2;
                }
              }
              _memmove((uint32_t *)(psVar12 + 2),(uint32_t *)psVar12,
                       ((intptr_t)psVar2 + (value5 * 2 - (intptr_t)psVar12) + -4 >> 1) << 1);
              psVar12[1] = svalue10;
              *psVar12 = svalue13;
            }
            else {
              *psVar12 = svalue13;
              if ((intptr_t)psVar12[1] < (intptr_t)arg1) {
                psVar12[1] = svalue10;
                while ((svalue7 = psVar12[2], svalue7 != -1 && ((intptr_t)svalue7 <= (intptr_t)arg1))) {
                  svalue7 = psVar12[1];
                  if (psVar12[1] <= psVar12[3]) {
                    svalue7 = psVar12[3];
                  }
                  psVar12[1] = svalue7;
                  _memmove((uint32_t *)(psVar12 + 2),(uint32_t *)(psVar12 + 4),
                           ((intptr_t)psVar2 + (value5 * 2 - (intptr_t)psVar12) + -8 >> 1) << 1);
                }
              }
            }
            break;
          }
          if ((intptr_t)local_20 <= (intptr_t)psVar12[1]) {
            if ((intptr_t)psVar12[1] < (intptr_t)arg1) {
              psVar12[1] = svalue10;
              while ((svalue7 = psVar12[2], svalue7 != -1 && ((intptr_t)svalue7 <= (intptr_t)arg1))) {
                svalue7 = psVar12[1];
                if (psVar12[1] <= psVar12[3]) {
                  svalue7 = psVar12[3];
                }
                psVar12[1] = svalue7;
                _memmove((uint32_t *)(psVar12 + 2),(uint32_t *)(psVar12 + 4),
                         ((intptr_t)psVar2 + (value5 * 2 - (intptr_t)psVar12) + -8 >> 1) << 1);
              }
            }
            break;
          }
          psVar12 = psVar12 + 2;
          local_1c = local_1c + 1;
        } while (local_1c < value9);
      }
      if (local_1c == *(int *)((intptr_t)self + 0xc)) {
        if (psVar2[value5 + -4] != -1) {
          value11 = 0;
          value9 = *(int *)((intptr_t)self + 4) << 1;
          value14 = *(int *)((intptr_t)self + 0xc) + -1;
          if (0 < value14) {
            psVar12 = psVar2 + 1;
            do {
              if ((intptr_t)psVar12[1] - (intptr_t)*psVar12 < value9) {
                value9 = (intptr_t)psVar12[1] - (intptr_t)*psVar12;
                local_14 = value11;
              }
              value11 = value11 + 1;
              psVar12 = psVar12 + 2;
            } while (value11 < value14);
          }
          _memmove((uint32_t *)(psVar2 + local_14 * 2 + 1),
                   (uint32_t *)(psVar2 + local_14 * 2 + 3),(local_14 * -4 + value5 * 2) - 6);
        }
        psVar2[value5 + -3] = svalue10;
        psVar2[value5 + -4] = svalue13;
      }
    }
  }
  return;
}
