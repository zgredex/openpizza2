// Screen_AnimateTileWipe: ported from Pizza Connection 2 at 0x51fda0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x51fda0
#include "pc2_port.h"

void __thiscall Screen_AnimateTileWipe(char *self,uint32_t arg1)

{
  double dVar1;
  DWORD DVar2;
  int value3;
  uint32_t uvalue4;
  uint32_t uvalue6;
  uint32_t uvalue5;
  uint32_t uvalue7;
  uint32_t *uptr8;
  uint16_t *uptr9;
  int value10;
  int64_t lvalue11;
  int value12;
  int value13;
  int local_2c;
  int local_28;
  int local_24;
  uint16_t *local_20;
  int local_1c;
  int local_10;
  int local_c;
  double local_8;
  
  if (*(int *)((intptr_t)self + 8) == 0) {
    return;
  }
  DVar2 = timeGetTime();
  local_8 = (double)(uint64_t)(DVar2 - *(int *)((intptr_t)self + 0xc));
  dVar1 = (double)(int64_t)local_8;
  local_8 = (double)(uint64_t)*(uint32_t *)((intptr_t)self + 0x10);
  local_8 = dVar1 / (double)(int64_t)local_8;
  if (1.0 < local_8) {
    local_8 = 1.0;
  }
  value13 = *(int *)(*(int *)((intptr_t)self + 8) + 0x18);
  value12 = *(int *)(arg1 + 0x28);
  *(int *)((intptr_t)self + 0x1c) = *(int *)(arg1 + 0x20) << 1;
  if (*(int *)((intptr_t)self + 0x14) != 0) {
    DAT_00584164 = (uint32_t *)(*(int *)((intptr_t)self + 0x20) / *(int *)((intptr_t)self + 0x28));
    DAT_0058416c = *(int *)((intptr_t)self + 0x24) / *(int *)((intptr_t)self + 0x28);
    DAT_00584170 = operator_new(DAT_0058416c * (intptr_t)DAT_00584164);
    DAT_00584174 = operator_new(DAT_0058416c * (intptr_t)DAT_00584164 * 4);
    value10 = 0;
    if (0 < (intptr_t)(DAT_0058416c * (intptr_t)DAT_00584164)) {
      do {
        value3 = value10 + 1;
        *(uint8_t *)((intptr_t)DAT_00584170 + value10) = 0;
        value10 = value3;
      } while (value3 < (intptr_t)(DAT_0058416c * (intptr_t)DAT_00584164));
    }
    Map_GenerateRandomTiles((intptr_t)self,DAT_00584174,DAT_00584164,DAT_0058416c);
    switch(*(uint32_t *)((intptr_t)self + 0x18)) {
    case 0:
    case 1:
      DAT_00584168 = *(int *)((intptr_t)self + 0x24) / *(int *)((intptr_t)self + 0x28) +
                     *(int *)((intptr_t)self + 0x28);
      break;
    case 2:
    case 3:
      DAT_00584168 = *(int *)((intptr_t)self + 0x20) / *(int *)((intptr_t)self + 0x28) +
                     *(int *)((intptr_t)self + 0x28);
      break;
    case 4:
    case 5:
    case 6:
    case 7:
      DAT_00584168 = (*(int *)((intptr_t)self + 0x24) + *(int *)((intptr_t)self + 0x20)) /
                     *(int *)((intptr_t)self + 0x28) + *(int *)((intptr_t)self + 0x28);
      break;
    case 8:
    case 9:
      DAT_00584168 = (intptr_t)DAT_0058416c / 2 + (intptr_t)DAT_00584164 / 2 + *(int *)((intptr_t)self + 0x28);
      break;
    default:
      DAT_00584168 = DAT_00584168 + *(int *)((intptr_t)self + 0x28);
    }
  }
  uvalue4 = DAT_0058416c;
  uptr8 = DAT_00584164;
  local_20 = *(uint16_t **)((intptr_t)self + 0x18);
  switch((intptr_t)local_20) {
  case 0x0:
  case 0x1:
    lvalue11 = __ftol();
    local_2c = (intptr_t)lvalue11;
    if (local_20 == (uint16_t *)0x1) {
      local_2c = uvalue4 - local_2c;
    }
    arg1 = 1;
    do {
      value10 = (intptr_t)uptr8 * local_2c;
      if (((local_20 == (uint16_t *)0x0) && (local_2c < 0)) ||
         ((local_20 == (uint16_t *)0x1 && ((intptr_t)DAT_0058416c < local_2c)))) goto LAB_0052041b;
      if ((local_2c < (intptr_t)DAT_0058416c) && (-1 < local_2c)) {
        uvalue4 = *(uint32_t *)((intptr_t)self + 0x28);
        if (*(uint8_t *)((intptr_t)DAT_00584170 + value10) == uvalue4) goto LAB_0052041b;
        local_20 = (uint16_t *)(uvalue4 * *(int *)((intptr_t)self + 0x1c) * local_2c + value12);
        local_24 = value13 + *(int *)((intptr_t)self + 0x20) * uvalue4 * local_2c * 2;
        value3 = 0;
        if (0 < (intptr_t)uptr8) {
          local_1c = value10 * 4;
          do {
            Surface_BlitOriented
                      (self,local_24,local_20,(uint32_t)*(uint8_t *)((intptr_t)DAT_00584170 + value3 + value10),
                       arg1,(int *)(local_1c + (intptr_t)DAT_00584174));
            *(uint8_t *)((intptr_t)DAT_00584170 + value3 + value10) = (uint8_t)arg1;
            local_24 = local_24 + *(int *)((intptr_t)self + 0x28) * 2;
            local_20 = local_20 + *(int *)((intptr_t)self + 0x28);
            value3 = value3 + 1;
            local_1c = local_1c + 4;
            uptr8 = DAT_00584164;
          } while (value3 < (intptr_t)DAT_00584164);
        }
      }
      local_20 = *(uint16_t **)((intptr_t)self + 0x18);
      arg1 = arg1 + 1;
      if (local_20 == (uint16_t *)0x0) {
        local_2c = local_2c + -1;
      }
      else {
        local_2c = local_2c + 1;
      }
      if ((intptr_t)*(uint32_t *)((intptr_t)self + 0x28) < (intptr_t)arg1) {
        arg1 = *(uint32_t *)((intptr_t)self + 0x28);
      }
    } while( true );
  case 0x2:
  case 0x3:
    lvalue11 = __ftol();
    local_28 = (intptr_t)lvalue11;
    if (local_20 == (uint16_t *)0x3) {
      local_28 = (intptr_t)uptr8 - local_28;
    }
    arg1 = 1;
    do {
      if (((local_20 == (uint16_t *)0x2) && (local_28 < 0)) ||
         ((local_20 == (uint16_t *)0x3 && ((intptr_t)uptr8 < local_28)))) goto LAB_0052022f;
      if ((local_28 < (intptr_t)uptr8) && (-1 < local_28)) {
        if ((uint32_t)*(uint8_t *)((intptr_t)DAT_00584170 + local_28) == *(uint32_t *)((intptr_t)self + 0x28))
        goto LAB_0052022f;
        value3 = *(uint32_t *)((intptr_t)self + 0x28) * local_28 * 2;
        local_2c = 0;
        value10 = value3 + value13;
        local_20 = (uint16_t *)(value3 + value12);
        value3 = local_28;
        if (0 < (intptr_t)DAT_0058416c) {
          do {
            Surface_BlitOriented
                      (self,value10,local_20,(uint32_t)*(uint8_t *)((intptr_t)DAT_00584170 + value3),arg1,
                       (int *)(DAT_00584174 + value3));
            *(uint8_t *)((intptr_t)DAT_00584170 + value3) = (uint8_t)arg1;
            local_20 = (uint16_t *)
                       ((intptr_t)local_20 + *(int *)((intptr_t)self + 0x28) * *(int *)((intptr_t)self + 0x1c));
            value10 = value10 + *(int *)((intptr_t)self + 0x28) * *(int *)((intptr_t)self + 0x20) * 2;
            value3 = value3 + (intptr_t)DAT_00584164;
            local_2c = local_2c + 1;
            uptr8 = DAT_00584164;
          } while (local_2c < (intptr_t)DAT_0058416c);
        }
      }
      local_20 = *(uint16_t **)((intptr_t)self + 0x18);
      arg1 = arg1 + 1;
      if (local_20 == (uint16_t *)0x2) {
        local_28 = local_28 + -1;
      }
      else {
        local_28 = local_28 + 1;
      }
      if ((intptr_t)*(uint32_t *)((intptr_t)self + 0x28) < (intptr_t)arg1) {
        arg1 = *(uint32_t *)((intptr_t)self + 0x28);
      }
    } while( true );
  case 0x4:
  case 0x5:
  case 0x6:
  case 0x7:
    lvalue11 = __ftol();
    local_28 = (intptr_t)lvalue11;
    arg1 = 1;
    if ((local_20 == (uint16_t *)0x4) || (local_20 == (uint16_t *)0x6)) {
      local_1c = -1;
    }
    else if ((local_20 == (uint16_t *)0x5) || (local_20 == (uint16_t *)0x7)) {
      local_1c = 1;
      local_28 = (intptr_t)uptr8 - local_28;
    }
    while (((-1 < local_28 || ((local_20 != (uint16_t *)0x4 && (local_20 != (uint16_t *)0x6))))
           && ((local_28 <= (intptr_t)uptr8 ||
               ((local_20 != (uint16_t *)0x5 && (local_20 != (uint16_t *)0x7))))))) {
      if ((intptr_t)local_20 < 6) {
        uvalue4 = *(uint32_t *)((intptr_t)self + 0x28);
        value10 = uvalue4 * local_28 * 2;
        local_24 = value10;
      }
      else {
        uvalue4 = *(uint32_t *)((intptr_t)self + 0x28);
        value10 = ((DAT_0058416c - 1) * *(int *)((intptr_t)self + 0x1c) + local_28 * 2) * uvalue4;
        local_24 = (*(int *)((intptr_t)self + 0x20) * (DAT_0058416c - 1) + local_28) * uvalue4 * 2;
      }
      local_24 = value13 + local_24;
      uptr9 = (uint16_t *)(value10 + value12);
      local_2c = 0;
      local_10 = local_28;
      local_c = local_28;
      if (0 < (intptr_t)DAT_0058416c) {
        do {
          if ((-1 < local_c) && (local_c < (intptr_t)uptr8)) {
            if (*(uint8_t *)((intptr_t)DAT_00584170 + local_10) == uvalue4) break;
            Surface_BlitOriented
                      (self,local_24,uptr9,(uint32_t)*(uint8_t *)((intptr_t)DAT_00584170 + local_10),arg1,
                       (int *)(DAT_00584174 + local_10));
            *(uint8_t *)((intptr_t)DAT_00584170 + local_10) = (uint8_t)arg1;
            uptr8 = DAT_00584164;
          }
          uvalue4 = *(uint32_t *)((intptr_t)self + 0x28);
          value10 = *(int *)((intptr_t)self + 0x20) * uvalue4;
          local_20 = *(uint16_t **)((intptr_t)self + 0x18);
          value3 = value10 * 2;
          if (5 < (intptr_t)local_20) {
            value3 = value10 * -2;
          }
          value10 = uvalue4 * local_1c * 2;
          local_24 = local_24 + value3 + value10;
          value3 = uvalue4 * *(int *)((intptr_t)self + 0x1c);
          if (5 < (intptr_t)local_20) {
            value3 = -value3;
          }
          uptr9 = (uint16_t *)((intptr_t)uptr9 + value10 + value3);
          local_10 = (intptr_t)uptr8 + local_10 + local_1c;
          local_c = local_c + local_1c;
          local_2c = local_2c + 1;
        } while (local_2c < (intptr_t)DAT_0058416c);
      }
      local_28 = local_28 + local_1c;
      arg1 = arg1 + 1;
      if ((intptr_t)*(uint32_t *)((intptr_t)self + 0x28) < (intptr_t)arg1) {
        arg1 = *(uint32_t *)((intptr_t)self + 0x28);
      }
    }
LAB_0052041b:
    value13 = *(int *)((intptr_t)self + 0x24);
    value12 = *(int *)((intptr_t)self + 0x20);
    break;
  case 0x8:
  case 0x9:
    lvalue11 = __ftol();
    local_2c = 0;
    if (0 < (intptr_t)uvalue4) {
      do {
        local_28 = 0;
        local_24 = value13 + *(int *)((intptr_t)self + 0x28) * local_2c * *(int *)((intptr_t)self + 0x20) * 2;
        value10 = (intptr_t)uptr8 * local_2c;
        local_20 = (uint16_t *)
                   (*(int *)((intptr_t)self + 0x28) * *(int *)((intptr_t)self + 0x1c) * local_2c + value12);
        if (0 < (intptr_t)uptr8) {
          do {
            if ((intptr_t)DAT_00584174[value10] < *(int *)((intptr_t)self + 0x2c)) {
              uvalue7 = local_28 - ((intptr_t)uptr8 >> 1);
              uvalue4 = local_2c - ((intptr_t)DAT_0058416c >> 1);
              uvalue5 = (intptr_t)uvalue4 >> 0x1f;
              uvalue6 = (intptr_t)uvalue7 >> 0x1f;
              if (*(int *)((intptr_t)self + 0x18) == 8) {
                uvalue4 = ((intptr_t)lvalue11 - ((uvalue7 ^ uvalue6) - uvalue6)) - ((uvalue4 ^ uvalue5) - uvalue5);
              }
              else {
                uvalue4 = (-((intptr_t)DAT_0058416c / 2) - (intptr_t)uptr8 / 2) +
                        ((uvalue7 ^ uvalue6) - uvalue6) + (intptr_t)lvalue11 + ((uvalue4 ^ uvalue5) - uvalue5);
                uptr8 = DAT_00584164;
              }
              if ((intptr_t)*(uint32_t *)((intptr_t)self + 0x2c) < (intptr_t)uvalue4) {
                uvalue4 = *(uint32_t *)((intptr_t)self + 0x2c);
              }
              if (0 < (intptr_t)uvalue4) {
                Surface_BlitOriented
                          (self,local_24,local_20,(uint32_t)*(uint8_t *)((intptr_t)DAT_00584170 + value10),uvalue4,
                           (int *)(DAT_00584174 + value10));
                *(char *)((intptr_t)DAT_00584170 + value10) = (char)uvalue4;
                uptr8 = DAT_00584164;
              }
            }
            local_24 = local_24 + *(int *)((intptr_t)self + 0x28) * 2;
            local_20 = local_20 + *(int *)((intptr_t)self + 0x28);
            value10 = value10 + 1;
            local_28 = local_28 + 1;
          } while (local_28 < (intptr_t)uptr8);
        }
        local_2c = local_2c + 1;
      } while (local_2c < (intptr_t)DAT_0058416c);
    }
    value13 = *(int *)((intptr_t)self + 0x24);
    value12 = *(int *)((intptr_t)self + 0x20);
    break;
  default:
    goto switchD_0051ff8e_default;
  }
LAB_005205a9:
  Rect_Union(*(void **)((intptr_t)self + 0x30),0,0,value12,value13);
switchD_0051ff8e_default:
  *(uint32_t *)((intptr_t)self + 0x14) = 0;
  if (local_8 == 1.0) {
    Mem_Free(DAT_00584170);
    DAT_00584170 = (LPVOID)0x0;
    Mem_Free(DAT_00584174);
    DAT_00584174 = (uint32_t *)0x0;
    *(uint32_t *)((intptr_t)self + 8) = 0;
  }
  return;
LAB_0052022f:
  value13 = *(int *)((intptr_t)self + 0x24);
  value12 = *(int *)((intptr_t)self + 0x20);
  goto LAB_005205a9;
}
