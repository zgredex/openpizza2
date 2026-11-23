// Sound_UpdateListener: ported from Pizza Connection 2 at 0x54bf70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54bf70
#include "pc2_port.h"


void __thiscall Sound_UpdateListener(void *self,uint32_t arg1,int arg2,int arg3)

{
  char *cptr1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *fptr6;
  float *fptr7;
  float *fptr8;
  int value9;
  float *fptr10;
  float *fptr11;
  int value12;
  bool flag13;
  int local_ac;
  int local_a4;
  int local_a0;
  int local_9c;
  float local_94 [4];
  int local_84;
  float local_80 [24];
  char local_20 [32];
  
  local_80[4] = -1.0;
  local_80[5] = 3.0;
  local_80[6] = -3.0;
  local_80[7] = 1.0;
  local_80[8] = 3.0;
  local_80[9] = -6.0;
  local_80[10] = 3.0;
  local_80[0xb] = 0.0;
  local_80[0xc] = -3.0;
  local_80[0xd] = 3.0;
  local_80[0xe] = 0.0;
  local_80[0xf] = 0.0;
  local_80[0x10] = 1.0;
  local_80[0x11] = 0.0;
  local_80[0x12] = 0.0;
  local_80[0x13] = 0.0;
  if (*(int *)((intptr_t)self + 4) == 0) {
    arg3 = 0;
  }
  *(uint32_t *)((intptr_t)self + 0x1b0) = arg1;
  *(int *)((intptr_t)self + 0x1b4) = arg2;
  if ((arg2 < 1) && (arg2 < 0)) {
    flag13 = arg1 != 0;
    arg1 = -arg1;
    *(uint32_t *)((intptr_t)self + 0x1b8) = 1;
    arg2 = -(arg2 + (uint32_t)flag13);
  }
  else {
    *(uint32_t *)((intptr_t)self + 0x1b8) = 0;
  }
  String_Format(local_20,(uint8_t *)s__0_ld_005765dc,9);
  value9 = 0;
  local_a0 = 0;
  if ((arg2 < *(int *)((intptr_t)self + 0x1a4)) ||
     ((arg2 <= *(int *)((intptr_t)self + 0x1a4) && (arg1 <= *(uint32_t *)((intptr_t)self + 0x1a0))))) {
    local_84 = 0;
  }
  else {
    local_84 = 1;
  }
  *(uint32_t *)((intptr_t)self + 0x1a0) = arg1;
  *(int *)((intptr_t)self + 0x1a4) = arg2;
  if (arg3 == 0) {
    value9 = 0;
    fptr6 = (float *)((intptr_t)self + 0x1bc);
    do {
      cptr1 = local_20 + value9;
      value9 = value9 + 1;
      *fptr6 = (float)(*cptr1 + -0x30) * 16.0;
      fptr6[0x21] = *(float *)((intptr_t)self + 0x1b8);
      fptr6[0x22] = 0.0;
      fptr6[1] = *fptr6;
      fptr6[2] = 0.0;
      fptr6 = fptr6 + 0x23;
    } while (value9 < 9);
    if (*(void **)((intptr_t)self + 4) != (void *)0x0) {
      UI_Sprite_BeginAnimation(*(void **)((intptr_t)self + 4),0x32,&LAB_0054bd00,self);
      return;
    }
  }
  else {
    local_9c = 0;
    local_a4 = 0;
    fptr6 = (float *)((intptr_t)self + 0x1c0);
    do {
      flag13 = true;
      fVar5 = (float)(local_20[local_9c] + -0x30) * 16.0;
      *fptr6 = fVar5;
      if ((value9 == 0) && (fVar5 == fptr6[-1])) {
        fptr6[0x21] = 0.0;
        flag13 = false;
        if (fptr6[0x20] != *(float *)((intptr_t)self + 0x1b8)) goto LAB_0054c18b;
      }
      else {
LAB_0054c18b:
        if (local_84 == 0) {
          if (*fptr6 == fptr6[-1]) {
            fVar5 = 0.0;
          }
          else if (fptr6[-1] <= *fptr6) {
            fVar5 = -((fptr6[-1] - *fptr6) + 160.0);
          }
          else {
            fVar5 = *fptr6 - fptr6[-1];
          }
          fVar5 = fVar5 - (float)(value9 * 0xa0);
          if (fptr6[0x20] != *(float *)((intptr_t)self + 0x1b8)) {
            if (value9 == 0) {
              fVar5 = fVar5 - 320.0;
            }
            else if (value9 == 1) {
              fVar5 = fVar5 - 160.0;
            }
          }
        }
        else {
          if (*fptr6 == fptr6[-1]) {
            fVar5 = 0.0;
          }
          else if (*fptr6 <= fptr6[-1]) {
            fVar5 = 160.0 - (fptr6[-1] - *fptr6);
          }
          else {
            fVar5 = *fptr6 - fptr6[-1];
          }
          fVar5 = fVar5 + (float)(value9 * 0xa0);
          if (fptr6[0x20] != *(float *)((intptr_t)self + 0x1b8)) {
            if (value9 == 0) {
              fVar5 = fVar5 + 320.0;
            }
            else if (value9 == 1) {
              fVar5 = fVar5 + 160.0;
            }
          }
        }
        if ((fptr6[0x21] == 0.0) || (0x1d < (intptr_t)fptr6[1])) {
          local_94[0] = 0.0;
          local_94[1] = 0.0;
        }
        else {
          value9 = (intptr_t)fptr6[1] + local_a4;
          local_94[0] = *(float *)((intptr_t)self + value9 * 4 + 0x1c8);
          local_94[1] = (float)*(uint32_t *)((intptr_t)self + value9 * 4 + 0x1cc);
        }
        if (fVar5 <= 0.0) {
          local_94[0] = -20.0;
          local_94[3] = -20.0;
          local_94[2] = -20.0;
        }
        else {
          local_94[0] = 20.0;
          local_94[3] = 20.0;
          local_94[2] = 20.0;
        }
        fptr8 = local_80 + 4;
        fptr7 = local_80 + 0x14;
        value9 = 4;
        do {
          *fptr7 = 0.0;
          fptr10 = local_94;
          fVar2 = *fptr7;
          value12 = 4;
          do {
            fVar3 = *fptr8;
            fVar4 = *fptr10;
            fptr8 = fptr8 + 1;
            fptr10 = fptr10 + 1;
            value12 = value12 + -1;
            fVar2 = fVar3 * fVar4 + fVar2;
          } while (value12 != 0);
          *fptr7 = fVar2;
          fptr7 = fptr7 + 1;
          value9 = value9 + -1;
        } while (value9 != 0);
        fptr8 = fptr6 + 2;
        local_80[3] = 1.0;
        local_ac = 0;
        fptr7 = fptr8;
        do {
          *fptr7 = 0.0;
          value9 = 0;
          local_80[2] = (float)local_ac * 0.06666667;
          local_80[1] = local_80[2] * local_80[2];
          local_80[0] = local_80[2] * local_80[2] * local_80[2];
          fVar2 = *fptr7;
          do {
            fptr10 = (float *)((intptr_t)local_80 + value9);
            value12 = value9 + 0x50;
            value9 = value9 + 4;
            fVar2 = *fptr10 * *(float *)((intptr_t)local_80 + value12) + fVar2;
          } while (value9 < 0x10);
          *fptr7 = fVar2;
          local_ac = local_ac + 1;
          fptr7 = fptr7 + 1;
        } while (local_ac < 0xf);
        local_94[2] = 0.0;
        local_94[1] = local_94[3];
        local_94[3] = 0.0;
        fptr7 = local_80 + 4;
        fptr10 = local_80 + 0x14;
        value9 = 4;
        do {
          *fptr10 = 0.0;
          fptr11 = local_94;
          fVar2 = *fptr10;
          value12 = 4;
          do {
            fVar3 = *fptr7;
            fVar4 = *fptr11;
            fptr7 = fptr7 + 1;
            fptr11 = fptr11 + 1;
            value12 = value12 + -1;
            fVar2 = fVar3 * fVar4 + fVar2;
          } while (value12 != 0);
          *fptr10 = fVar2;
          fptr10 = fptr10 + 1;
          value9 = value9 + -1;
        } while (value9 != 0);
        local_80[3] = 1.0;
        local_ac = 0;
        fptr7 = fptr6 + 0x11;
        do {
          *fptr7 = 0.0;
          value9 = 0;
          local_80[2] = (float)local_ac * 0.06666667;
          local_80[1] = local_80[2] * local_80[2];
          local_80[0] = local_80[2] * local_80[2] * local_80[2];
          fVar2 = *fptr7;
          do {
            fptr10 = (float *)((intptr_t)local_80 + value9);
            value12 = value9 + 0x50;
            value9 = value9 + 4;
            fVar2 = *fptr10 * *(float *)((intptr_t)local_80 + value12) + fVar2;
          } while (value9 < 0x10);
          *fptr7 = fVar2;
          local_ac = local_ac + 1;
          fptr7 = fptr7 + 1;
        } while (local_ac < 0xf);
        fVar2 = 0.0;
        value9 = 0x1e;
        fptr7 = fptr8;
        do {
          fVar2 = fVar2 + *fptr7;
          fptr7 = fptr7 + 1;
          value9 = value9 + -1;
        } while (value9 != 0);
        if (fVar2 == 0.0) {
          fVar5 = 1.0;
        }
        else {
          fVar5 = fVar5 / fVar2;
        }
        value9 = 0x1e;
        do {
          value9 = value9 + -1;
          *fptr8 = fVar5 * *fptr8;
          fptr8 = fptr8 + 1;
        } while (value9 != 0);
        fptr6[1] = 0.0;
        fptr6[0x21] = 1.4013e-45;
        *(uint32_t *)((intptr_t)self + 0x1ac) = 0;
        if (flag13) {
          local_a0 = local_a0 + 1;
        }
        value9 = local_a0;
      }
      fptr6 = fptr6 + 0x23;
      local_9c = local_9c + 1;
      local_a4 = local_a4 + 0x23;
    } while (local_a4 < 0x13b);
    UI_Sprite_BeginAnimation(*(void **)((intptr_t)self + 4),0x32,&LAB_0054bd00,self);
  }
  return;
}
