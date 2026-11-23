// Map_GenerateSceneryPatterns: ported from Pizza Connection 2 at 0x500830.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x500830
#include "pc2_port.h"

uint32_t __cdecl Map_GenerateSceneryPatterns(int arg1)

{
  char cVar1;
  uint32_t uvalue2;
  int value3;
  uint32_t uvalue4;
  int value5;
  int value6;
  int value7;
  char *cptr8;
  bool flag9;
  bool flag10;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  uint32_t local_68;
  char *local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50 [20];
  
  local_50[1] = 0xffffffff;
  local_50[2] = 0xffffffff;
  local_50[3] = 0xffffffff;
  local_78 = 0;
  local_50[0] = 1;
  local_50[4] = 0x50;
  local_50[5] = 0x28;
  local_50[6] = 0x14;
  local_50[7] = 10;
  local_50[8] = 0;
  local_50[9] = 0;
  local_50[10] = 0;
  local_50[0xb] = 0;
  local_50[0xc] = 0;
  local_50[0xd] = 0;
  local_50[0xe] = 0;
  local_50[0xf] = 0;
  local_50[0x10] = 0;
  local_50[0x11] = 0;
  local_50[0x12] = 0;
  local_50[0x13] = 0;
  local_6c = 0;
  uvalue2 = Map_FindEdgeDot(arg1,&local_70,&local_74,&local_68,1);
  if ((char)uvalue2 == '\0') {
    return 0;
  }
  if (*(int *)(arg1 + 8) != 0) {
    uvalue2 = Map_FindEdgeDot(arg1,&local_70,&local_74,&local_68,0);
    cVar1 = (char)uvalue2;
    while (cVar1 != '\0') {
      value7 = 0;
      local_78 = 0;
      if ((intptr_t)local_68 < 2) {
        local_58 = local_70 * 0x50;
        value5 = (-(uint32_t)(local_68 != 0) & 0xfffffffe) + 1;
        if (*(char *)(arg1 + 0x28 + local_58 + local_74) == '.') {
          do {
            local_64 = (char *)0x1;
            cptr8 = (char *)((value5 + local_70) * 0x50 + value7 + local_74 + 0x28 + arg1);
            value7 = 1;
            do {
              if (*cptr8 != '.') {
                if (value7 < 0xc) goto LAB_005009ab;
                break;
              }
              value7 = value7 + 1;
              cptr8 = cptr8 + value5 * 0x50;
            } while (value7 < 0xc);
            local_78 = local_78 + 1;
            value7 = local_50[local_68] * local_78;
          } while (*(char *)(arg1 + 0x28 + local_58 + value7 + local_74) == '.');
LAB_005009ab:
          flag10 = local_78 < 0;
          flag9 = false;
          if (local_78 != 0) goto LAB_00500bed;
        }
        local_64 = (char *)0x0;
        local_5c = 0;
        do {
          value7 = (local_5c + local_70) * 0x50 + local_74 + local_50[local_68] * local_78;
          if (*(char *)(value7 + 0x28 + arg1) != '.') break;
          *(uint8_t *)(value7 + 0x28 + arg1) = 0x20;
          local_64 = local_64 + 1;
          local_5c = local_5c + value5;
        } while ((intptr_t)local_64 < 0xc);
LAB_00500ad4:
        flag10 = local_78 < 0;
        flag9 = local_78 == 0;
        if (!flag9) goto LAB_00500bed;
        local_54 = local_70 * 0x50 + local_74;
        local_64 = (char *)(local_54 + 0x28 + arg1);
        cptr8 = local_64;
        local_60 = local_70;
        cVar1 = *local_64;
        while (cVar1 == '.') {
          cptr8 = cptr8 + -0x50;
          local_60 = local_60 + -1;
          cVar1 = *cptr8;
        }
        cVar1 = *local_64;
        cptr8 = local_64;
        value7 = local_70;
        while (cVar1 == '.') {
          cptr8 = cptr8 + 0x50;
          value7 = value7 + 1;
          cVar1 = *cptr8;
        }
        local_58 = local_74;
        if (*local_64 == '.') {
          cptr8 = local_64;
          do {
            local_58 = local_58 + -1;
            cptr8 = cptr8 + -1;
          } while (*cptr8 == '.');
        }
        local_5c = local_74;
        if (*(char *)(local_54 + 0x28 + arg1) == '.') {
          cptr8 = local_64;
          do {
            local_5c = local_5c + 1;
            cptr8 = cptr8 + 1;
          } while (*cptr8 == '.');
        }
        if ((value7 - local_60 < 0xe) && (local_5c - local_58 < 0xe)) {
          value6 = local_60 + 1;
          value5 = local_58;
          if (value6 < value7) {
            value3 = value6 * 0x50;
            value7 = value7 - value6;
            do {
              value6 = local_74 + value3;
              value3 = value3 + 0x50;
              value7 = value7 + -1;
              *(uint8_t *)(value6 + 0x28 + arg1) = 0x20;
            } while (value7 != 0);
          }
          while (value5 = value5 + 1, value5 < local_5c) {
            *(uint8_t *)(local_70 * 0x50 + value5 + 0x28 + arg1) = 0x20;
          }
          flag10 = false;
          flag9 = true;
          goto LAB_00500bed;
        }
      }
      else {
        value7 = local_70 * 0x50;
        value5 = (-(uint32_t)(local_68 != 2) & 0xfffffffe) + 1;
        if (*(char *)(arg1 + 0x28 + value7 + local_74) != '.') {
LAB_00500a87:
          value7 = 0;
          local_64 = (char *)0x0;
          do {
            value6 = (local_50[local_68] * local_78 + local_70) * 0x50 + value7 + local_74;
            if (*(char *)(value6 + 0x28 + arg1) != '.') break;
            value7 = value7 + value5;
            local_64 = local_64 + 1;
            *(uint8_t *)(value6 + 0x28 + arg1) = 0x20;
          } while ((intptr_t)local_64 < 0xc);
          goto LAB_00500ad4;
        }
        do {
          value6 = 1;
          cptr8 = (char *)(value7 + value5 + local_74 + 0x28 + arg1);
          do {
            if (*cptr8 != '.') {
              if (value6 < 0xc) goto LAB_00500a7f;
              break;
            }
            value6 = value6 + 1;
            cptr8 = cptr8 + value5;
          } while (value6 < 0xc);
          local_78 = local_78 + 1;
          value7 = (local_50[local_68] * local_78 + local_70) * 0x50;
        } while (*(char *)(arg1 + 0x28 + value7 + local_74) == '.');
LAB_00500a7f:
        flag10 = local_78 < 0;
        flag9 = local_78 == 0;
        if (flag9) goto LAB_00500a87;
LAB_00500bed:
        if (!flag9 && !flag10) {
          do {
            if (local_78 == 1) {
              value7 = 2;
LAB_00500c11:
              Font_DrawGlyphPattern(arg1,&local_70,&local_74,local_68,value7,&local_78);
              if (local_6c < 0xf) {
                local_6c = local_6c + 1;
              }
            }
            else {
              if (local_78 == 2) {
                value7 = 0x14;
                goto LAB_00500c11;
              }
              if (0xb < local_78) {
                uvalue4 = _rand();
                value7 = local_6c;
                if ((intptr_t)(uvalue4 & 100) < local_50[local_6c + 4]) {
                  Font_DrawGlyphPattern(arg1,&local_70,&local_74,local_68,2,&local_78);
                  if (value7 < 0xf) {
                    local_6c = value7 + 1;
                  }
                  goto LAB_00500e2c;
                }
                if (local_78 == 0xc) {
                  value7 = 0;
                }
                else {
                  value7 = 0;
                }
LAB_00500e1b:
                Font_DrawGlyphPattern(arg1,&local_70,&local_74,local_68,value7,&local_78);
                local_6c = 0;
                goto LAB_00500e2c;
              }
              flag10 = true;
              switch(local_68) {
              case 0:
                value5 = local_70 * 0x50 + local_74;
                value7 = value5 + arg1;
                if ((*(char *)(value5 + -0x28 + arg1) == '@') && (*(char *)(value7 + -0x27) == '@')
                   ) {
                  cVar1 = *(char *)(value7 + -0x26);
joined_r0x00500ce1:
                  if (cVar1 == '@') goto switchD_00500c5e_default;
                }
                break;
              case 1:
                value7 = local_70 * 0x50 + local_74 + arg1;
                if ((*(char *)(value7 + 0x78) == '@') && (*(char *)(value7 + 0x77) == '@')) {
                  cVar1 = *(char *)(value7 + 0x76);
                  goto joined_r0x00500ce1;
                }
                break;
              case 2:
                value5 = local_70 * 0x50 + local_74;
                value7 = value5 + arg1;
                if ((*(char *)(value5 + 0x27 + arg1) == '@') && (*(char *)(value7 + -0x29) == '@'))
                {
                  cVar1 = *(char *)(value7 + -0x79);
                  goto joined_r0x00500ce1;
                }
                break;
              case 3:
                value7 = local_70 * 0x50 + local_74 + arg1;
                if ((*(char *)(value7 + 0x29) == '@') && (*(char *)(value7 + -0x27) == '@')) {
                  cVar1 = *(char *)(value7 + -0x77);
                  goto joined_r0x00500ce1;
                }
                break;
              default:
                goto switchD_00500c5e_default;
              }
              flag10 = false;
switchD_00500c5e_default:
              uvalue4 = Random_Mod(100);
              if (uvalue4 < 10) {
                if ((local_78 < 4) || (uvalue4 = Random_Mod(100), 0x31 < uvalue4)) goto LAB_00500d48;
                Font_DrawGlyphPattern(arg1,&local_70,&local_74,local_68,7,&local_78);
                local_6c = local_6c + 4;
              }
              else {
                if (flag10) {
                  value7 = 3;
                  goto LAB_00500e1b;
                }
LAB_00500d48:
                Font_DrawGlyphPattern(arg1,&local_70,&local_74,local_68,6,&local_78);
                local_6c = local_6c + 3;
              }
              if (0xf < local_6c) {
                local_6c = 0xf;
              }
            }
LAB_00500e2c:
          } while (0 < local_78);
        }
      }
      uvalue2 = Map_FindEdgeDot(arg1,&local_70,&local_74,&local_68,0);
      cVar1 = (char)uvalue2;
    }
  }
  return 1;
}
