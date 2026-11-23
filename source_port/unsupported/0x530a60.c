// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x530a60.c:63:54: error: invalid operands to binary expression ('double' and 'int')
// Gfx_FillGradientDither: ported from Pizza Connection 2 at 0x530a60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x530a60
#include "pc2_port.h"

void __fastcall Gfx_FillGradientDither(int arg1)

{
  double dVar1;
  int value2;
  uint32_t uvalue3;
  int value4;
  int value5;
  int value6;
  uint32_t uvalue7;
  uint32_t uvalue8;
  int64_t lvalue9;
  double local_c0;
  int local_b4;
  int local_b0;
  uint32_t local_ac;
  double local_a8;
  double local_a0;
  char local_94 [16];
  uint32_t local_84;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  local_94[1] = 0xfe;
  local_94[4] = 0xfe;
  local_94[6] = 0xfd;
  local_94[0xe] = 0xfd;
  local_94[5] = 2;
  local_94[8] = 2;
  local_94[2] = 1;
  local_94[10] = 1;
  local_94[0] = '\0';
  local_94[3] = 0xff;
  local_94[7] = 3;
  local_94[9] = 0;
  local_94[0xb] = 0xff;
  local_94[0xc] = 0xfc;
  local_94[0xd] = 4;
  local_94[0xf] = 3;
  Sprite_GetSize(*(void **)(arg1 + 0x50),&local_b0,&local_b4);
  if (*(int *)(arg1 + 0x100) == -0x1000000) {
    *(uint32_t *)(arg1 + 0x100) = *(uint32_t *)(arg1 + 0xfc);
  }
  uvalue8 = *(uint32_t *)(arg1 + 0x100);
  local_a8 = (double)CONCAT44(((uint32_t)((local_a8) >> 32)),uvalue8);
  if ((uvalue8 != 0xff000000) &&
     ((*(int *)(arg1 + 0x104) == -0x1000000 || (*(int *)(arg1 + 0x108) == -0x1000000)))) {
    uvalue7 = *(uint32_t *)(arg1 + 0xfc);
    *(uint32_t *)(arg1 + 0x10c) = 4;
    local_84 = uvalue7 & 0xff;
    value4 = (uvalue8 & 0xff) - local_84;
    local_a8 = (double)CONCAT44(((uint32_t)((local_a8) >> 32)),value4);
    uvalue3 = uvalue7 >> 8 & 0xff;
    uvalue7 = uvalue7 >> 0x10 & 0xff;
    local_ac = (uvalue8 >> 8 & 0xff) - uvalue3;
    value2 = (uvalue8 >> 0x10 & 0xff) - uvalue7;
    if (*(int *)(arg1 + 0x104) == -0x1000000) {
      value6 = local_b0 + local_b4;
      value5 = ((value2 * local_b0) / value6 + uvalue7) * 0x100;
      local_a0 = (double)CONCAT44(((uint32_t)((local_a0) >> 32)),value5);
      *(uint32_t *)(arg1 + 0x104) =
           (value4 * local_b0) / value6 +
           local_84 + ((intptr_t)(local_ac * local_b0) / value6 + uvalue3 + value5) * 0x100;
    }
    if (*(int *)(arg1 + 0x108) == -0x1000000) {
      value6 = local_b0 + local_b4;
      *(uint32_t *)(arg1 + 0x108) =
           (value4 * local_b4) / value6 +
           local_84 +
           ((intptr_t)(local_ac * local_b4) / value6 +
           uvalue3 + ((value2 * local_b4) / value6 + uvalue7) * 0x100) * 0x100;
    }
  }
  local_84 = Sprite_GetPixelBuffer(*(void **)(arg1 + 0x50));
  uvalue8 = *(uint32_t *)(arg1 + 0xfc);
  local_c0 = (double)(uint64_t)(uvalue8 >> 0x10 & 0xff);
  local_a0 = (double)(int64_t)local_c0;
  local_c0 = (double)(uint64_t)(uvalue8 >> 8 & 0xff);
  local_a8 = (double)(int64_t)local_c0;
  uvalue7 = *(uint32_t *)(arg1 + 0x108);
  local_c0 = (double)(uint64_t)(uvalue8 & 0xff);
  local_80 = (double)(int64_t)local_c0;
  dVar1 = (double)local_b4;
  local_50 = ((double)(uvalue7 >> 0x10 & 0xff) - local_a0) / dVar1;
  uvalue8 = *(uint32_t *)(arg1 + 0x104);
  uvalue3 = *(uint32_t *)(arg1 + 0x100);
  local_c0 = (double)(uint64_t)(uvalue8 >> 0x10 & 0xff);
  local_18 = ((double)(uvalue7 >> 8 & 0xff) - local_a8) / dVar1;
  local_48 = ((double)(uvalue7 & 0xff) - local_80) / dVar1;
  local_78 = (double)(int64_t)local_c0;
  local_c0 = (double)(uint64_t)(uvalue8 >> 8 & 0xff);
  local_70 = (double)(int64_t)local_c0;
  local_c0 = (double)(uint64_t)(uvalue8 & 0xff);
  local_c0 = (double)(int64_t)local_c0;
  local_40 = ((double)(uvalue3 >> 0x10 & 0xff) - local_78) / dVar1;
  local_ac = 0;
  local_30 = ((double)(uvalue3 >> 8 & 0xff) - local_70) / dVar1;
  local_20 = ((double)(uvalue3 & 0xff) - local_c0) / dVar1;
  if (0 < local_b4) {
    value2 = local_b0;
    do {
      uvalue8 = 0;
      dVar1 = (double)local_b0;
      local_58 = local_a0;
      local_68 = local_a8;
      local_60 = local_80;
      local_38 = (local_78 - local_a0) / dVar1;
      local_10 = (local_70 - local_a8) / dVar1;
      local_28 = (local_c0 - local_80) / dVar1;
      if (0 < value2) {
        uvalue7 = local_ac & 3;
        do {
          value2 = (intptr_t)local_94[(uvalue8 & 3) + uvalue7 * 4];
          lvalue9 = __ftol();
          uvalue3 = (intptr_t)lvalue9 + value2;
          if ((intptr_t)uvalue3 < 0) {
            uvalue3 = 0;
          }
          else if (0xff < (intptr_t)uvalue3) {
            uvalue3 = 0xff;
          }
          lvalue9 = __ftol();
          value4 = (intptr_t)lvalue9 + value2;
          if (value4 < 0) {
            value4 = 0;
          }
          else if (0xff < value4) {
            value4 = 0xff;
          }
          lvalue9 = __ftol();
          value2 = (intptr_t)lvalue9 + value2;
          if (value2 < 0) {
            value2 = 0;
          }
          else if (0xff < value2) {
            value2 = 0xff;
          }
          uvalue3 = Color_RGBTo16(DAT_0057c5c8,(uint8_t)value2,(uint8_t)value4,uvalue3);
          local_58 = local_38 + local_58;
          local_68 = local_10 + local_68;
          value2 = local_ac * local_b0 + uvalue8;
          uvalue8 = uvalue8 + 1;
          *(short *)(local_84 + value2 * 2) = (short)uvalue3;
          local_60 = local_28 + local_60;
        } while ((intptr_t)uvalue8 < local_b0);
        value2 = local_b0;
      }
      local_a0 = local_50 + local_a0;
      local_ac = local_ac + 1;
      local_a8 = local_18 + local_a8;
      local_80 = local_48 + local_80;
      local_78 = local_40 + local_78;
      local_70 = local_30 + local_70;
      local_c0 = local_20 + local_c0;
    } while ((intptr_t)local_ac < local_b4);
  }
  return;
}
