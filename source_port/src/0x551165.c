// CRT_Output: ported from Pizza Connection 2 at 0x551165.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551165
#include "pc2_port.h"


int __cdecl CRT_Output(int *arg1,uint8_t *arg2,uint32_t *arg3)

{
  WCHAR WVar1;
  uint8_t *bptr2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  short *psVar5;
  uint8_t *uptr6;
  WCHAR *pWVar7;
  int *ptr8;
  int value9;
  uint8_t flag10;
  int value11;
  uint64_t uvalue12;
  uint64_t uvalue13;
  int64_t lvalue14;
  uint8_t local_24c [511];
  uint8_t local_4d;
  uint32_t local_4c;
  uint32_t local_48;
  uint32_t local_44;
  uint32_t local_40;
  CHAR local_3c [4];
  uint32_t local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  char local_1a;
  char local_19;
  int local_18;
  int local_14;
  uint8_t *local_10;
  WCHAR *local_c;
  uint32_t local_8;
  
  local_34 = 0;
  flag10 = *arg2;
  local_10 = (uint8_t *)0x0;
  local_18 = 0;
  if (flag10 != 0) {
    bptr2 = arg2;
    while (arg2 = bptr2 + 1, -1 < local_18) {
      if (((char)flag10 < ' ') || ('x' < (char)flag10)) {
        uvalue3 = 0;
      }
      else {
        uvalue3 = *(uint8_t *)((intptr_t)&PTR_LAB_0055ccfc + (intptr_t)(char)flag10) & 0xf;
      }
      local_34 = (intptr_t)(char)(&DAT_0055cd1c)[uvalue3 * 8 + local_34] >> 4;
      switch(local_34) {
      case 0:
switchD_005511d3_caseD_0:
        local_28 = 0;
        if ((PTR_DAT_00576ae4[(uint32_t)flag10 * 2 + 1] & 0x80) != 0) {
          CRT_StreamPutc((intptr_t)(char)flag10,arg1,&local_18);
          flag10 = *arg2;
          arg2 = bptr2 + 2;
        }
        CRT_StreamPutc((intptr_t)(char)flag10,arg1,&local_18);
        break;
      case 1:
        local_14 = -1;
        local_38 = 0;
        local_2c = 0;
        local_24 = 0;
        local_20 = 0;
        local_8 = 0;
        local_28 = 0;
        break;
      case 2:
        if (flag10 == 0x20) {
          local_8 = local_8 | 2;
        }
        else if (flag10 == 0x23) {
          local_8 = local_8 | 0x80;
        }
        else if (flag10 == 0x2b) {
          local_8 = local_8 | 1;
        }
        else if (flag10 == 0x2d) {
          local_8 = local_8 | 4;
        }
        else if (flag10 == 0x30) {
          local_8 = local_8 | 8;
        }
        break;
      case 3:
        if (flag10 == 0x2a) {
          local_24 = CRT_GetVaArg((int *)&arg3);
          if (local_24 < 0) {
            local_8 = local_8 | 4;
            local_24 = -local_24;
          }
        }
        else {
          local_24 = (char)flag10 + -0x30 + local_24 * 10;
        }
        break;
      case 4:
        local_14 = 0;
        break;
      case 5:
        if (flag10 == 0x2a) {
          local_14 = CRT_GetVaArg((int *)&arg3);
          if (local_14 < 0) {
            local_14 = -1;
          }
        }
        else {
          local_14 = (char)flag10 + -0x30 + local_14 * 10;
        }
        break;
      case 6:
        if (flag10 == 0x49) {
          if ((*arg2 != 0x36) || (bptr2[2] != 0x34)) {
            local_34 = 0;
            goto switchD_005511d3_caseD_0;
          }
          arg2 = bptr2 + 3;
          local_8 = local_8 | 0x8000;
        }
        else if (flag10 == 0x68) {
          local_8 = local_8 | 0x20;
        }
        else if (flag10 == 0x6c) {
          local_8 = local_8 | 0x10;
        }
        else if (flag10 == 0x77) {
          local_8 = local_8 | 0x800;
        }
        break;
      case 7:
        pWVar7 = local_c;
        if ((char)flag10 < 'h') {
          if ('d' < (char)flag10) {
LAB_005513f3:
            local_8 = local_8 | 0x40;
            pWVar7 = (WCHAR *)local_24c;
            if (local_14 < 0) {
              local_14 = 6;
            }
            else if ((local_14 == 0) && (flag10 == 0x67)) {
              local_14 = 1;
            }
            local_4c = *arg3;
            local_48 = arg3[1];
            arg3 = arg3 + 2;
            local_c = pWVar7;
            (*(code *)PTR_FUN_00576a18)(&local_4c,local_24c,(intptr_t)(char)flag10,local_14,local_38);
            uvalue3 = local_8 & 0x80;
            if ((uvalue3 != 0) && (local_14 == 0)) {
              (*(code *)PTR_FUN_00576a24)(local_24c);
            }
            if ((flag10 == 0x67) && (uvalue3 == 0)) {
              (*(code *)PTR_FUN_00576a1c)(local_24c);
            }
            if (local_24c[0] == '-') {
              local_8 = local_8 | 0x100;
              pWVar7 = (WCHAR *)(local_24c + 1);
              local_c = pWVar7;
            }
LAB_00551565:
            uptr6 = (uint8_t *)_strlen((char *)pWVar7);
            goto LAB_0055176c;
          }
          if ((char)flag10 < 'Y') {
            if (flag10 == 0x58) {
LAB_005515e4:
              local_30 = 7;
LAB_005515eb:
              local_10 = (uint8_t *)0x10;
              if ((local_8 & 0x80) != 0) {
                local_1a = '0';
                local_19 = (char)local_30 + 'Q';
                local_20 = 2;
              }
              goto LAB_00551655;
            }
            if (flag10 == 0x43) {
              if ((local_8 & 0x830) == 0) {
                local_8 = local_8 | 0x800;
              }
              goto LAB_00551420;
            }
            if ((flag10 != 0x45) && (flag10 != 0x47)) {
              if (flag10 == 0x53) {
                if ((local_8 & 0x830) == 0) {
                  local_8 = local_8 | 0x800;
                }
                goto LAB_00551392;
              }
              goto LAB_0055176f;
            }
            local_38 = 1;
            flag10 = flag10 + 0x20;
            goto LAB_005513f3;
          }
          if (flag10 == 0x5a) {
            psVar5 = (short *)CRT_GetVaArg((int *)&arg3);
            if ((psVar5 != (short *)0x0) &&
               (local_c = *(WCHAR **)(psVar5 + 2), local_c != (WCHAR *)0x0)) {
              if ((local_8 & 0x800) == 0) {
                local_28 = 0;
                uptr6 = (uint8_t *)(intptr_t)*psVar5;
                goto LAB_0055176c;
              }
              local_10 = (uint8_t *)((uint32_t)(intptr_t)*psVar5 >> 1);
              local_28 = 1;
              pWVar7 = local_c;
              goto LAB_0055176f;
            }
            local_c = (WCHAR *)PTR_DAT_00576a10;
            pWVar7 = (WCHAR *)PTR_DAT_00576a10;
            goto LAB_00551565;
          }
          if (flag10 == 99) {
LAB_00551420:
            if ((local_8 & 0x810) == 0) {
              uvalue4 = CRT_GetVaArg((int *)&arg3);
              local_24c[0] = (char)uvalue4;
              local_10 = (uint8_t *)0x1;
            }
            else {
              uvalue4 = CRT_ReadArg16((int *)&arg3);
              local_10 = (uint8_t *)CRT_Wctomb(local_24c,(WCHAR)uvalue4);
              if ((intptr_t)local_10 < 0) {
                local_2c = 1;
              }
            }
            pWVar7 = (WCHAR *)local_24c;
          }
          else if (flag10 == 100) goto LAB_0055164a;
        }
        else {
          if (flag10 == 0x69) {
LAB_0055164a:
            local_8 = local_8 | 0x40;
LAB_0055164e:
            local_10 = (uint8_t *)0xa;
LAB_00551655:
            if ((local_8 & 0x8000) == 0) {
              if ((local_8 & 0x20) == 0) {
                if ((local_8 & 0x40) == 0) {
                  uvalue3 = CRT_GetVaArg((int *)&arg3);
                  uvalue12 = (uint64_t)uvalue3;
                  goto LAB_005516a8;
                }
                uvalue3 = CRT_GetVaArg((int *)&arg3);
              }
              else if ((local_8 & 0x40) == 0) {
                uvalue3 = CRT_GetVaArg((int *)&arg3);
                uvalue3 = uvalue3 & 0xffff;
              }
              else {
                uvalue4 = CRT_GetVaArg((int *)&arg3);
                uvalue3 = (uint32_t)(short)uvalue4;
              }
              uvalue12 = (uint64_t)(intptr_t)uvalue3;
            }
            else {
              uvalue12 = CRT_ReadArg64((int *)&arg3);
            }
LAB_005516a8:
            value11 = (intptr_t)(uvalue12 >> 0x20);
            if ((((local_8 & 0x40) != 0) && (value11 == 0 || (int64_t)uvalue12 < 0)) &&
               ((int64_t)uvalue12 < 0)) {
              local_8 = local_8 | 0x100;
              uvalue12 = CONCAT44(-(value11 + (uint32_t)((intptr_t)uvalue12 != 0)),-(intptr_t)uvalue12);
            }
            value11 = (intptr_t)(uvalue12 >> 0x20);
            if ((local_8 & 0x8000) == 0) {
              value11 = 0;
            }
            lvalue14 = CONCAT44(value11,(intptr_t)uvalue12);
            if (local_14 < 0) {
              local_14 = 1;
            }
            else {
              local_8 = local_8 & 0xfffffff7;
            }
            if ((intptr_t)uvalue12 == 0 && value11 == 0) {
              local_20 = 0;
            }
            local_c = (WCHAR *)&local_4d;
            while ((value11 = local_14 + -1, 0 < local_14 || (lvalue14 != 0))) {
              local_40 = (intptr_t)local_10 >> 0x1f;
              local_44 = (uint32_t)local_10;
              uvalue3 = (uint32_t)((uint64_t)lvalue14 >> 0x20);
              local_14 = value11;
              uvalue13 = __aullrem((uint32_t)lvalue14,uvalue3,(uint32_t)local_10,local_40);
              value11 = (intptr_t)uvalue13 + 0x30;
              lvalue14 = __aulldiv((uint32_t)lvalue14,uvalue3,local_44,local_40);
              if (0x39 < value11) {
                value11 = value11 + local_30;
              }
              pWVar7 = (WCHAR *)((intptr_t)local_c + -1);
              *(char *)local_c = (char)value11;
              local_c = pWVar7;
            }
            local_10 = local_24c + -(intptr_t)local_c + 0x1ff;
            pWVar7 = (WCHAR *)((intptr_t)local_c + 1);
            local_14 = value11;
            if ((local_8 & 0x200) == 0) goto LAB_0055176f;
            if (*(char *)pWVar7 == '0') {
              if (local_10 != (uint8_t *)0x0) goto LAB_0055176f;
            }
            uptr6 = local_24c + -(intptr_t)local_c + 0x200;
            *(char *)local_c = '0';
          }
          else {
            if (flag10 == 0x6e) {
              ptr8 = (int *)CRT_GetVaArg((int *)&arg3);
              if ((local_8 & 0x20) == 0) {
                *ptr8 = local_18;
              }
              else {
                *(uint16_t *)ptr8 = (uint16_t)local_18;
              }
              local_2c = 1;
              break;
            }
            if (flag10 == 0x6f) {
              local_10 = (uint8_t *)0x8;
              if ((local_8 & 0x80) != 0) {
                local_8 = local_8 | 0x200;
              }
              goto LAB_00551655;
            }
            if (flag10 == 0x70) {
              local_14 = 8;
              goto LAB_005515e4;
            }
            if (flag10 != 0x73) {
              if (flag10 != 0x75) {
                if (flag10 != 0x78) goto LAB_0055176f;
                local_30 = 0x27;
                goto LAB_005515eb;
              }
              goto LAB_0055164e;
            }
LAB_00551392:
            value11 = local_14;
            if (local_14 == -1) {
              value11 = 0x7fffffff;
            }
            local_c = (WCHAR *)CRT_GetVaArg((int *)&arg3);
            if ((local_8 & 0x810) == 0) {
              if (local_c == (WCHAR *)0x0) {
                local_c = (WCHAR *)PTR_DAT_00576a10;
              }
              for (pWVar7 = local_c; (value11 != 0 && ((char)*pWVar7 != '\0'));
                  pWVar7 = (WCHAR *)((intptr_t)pWVar7 + 1)) {
                value11 = value11 + -1;
              }
              uptr6 = (uint8_t *)((intptr_t)pWVar7 - (intptr_t)local_c);
            }
            else {
              if (local_c == (WCHAR *)0x0) {
                local_c = (WCHAR *)PTR_DAT_00576a14;
              }
              local_28 = 1;
              for (pWVar7 = local_c; (value11 != 0 && (*pWVar7 != L'\0')); pWVar7 = pWVar7 + 1) {
                value11 = value11 + -1;
              }
              uptr6 = (uint8_t *)((intptr_t)pWVar7 - (intptr_t)local_c >> 1);
            }
          }
LAB_0055176c:
          local_10 = uptr6;
          pWVar7 = local_c;
        }
LAB_0055176f:
        local_c = pWVar7;
        uvalue3 = local_8;
        if (local_2c == 0) {
          if ((local_8 & 0x40) != 0) {
            if ((local_8 & 0x100) == 0) {
              if ((local_8 & 1) == 0) {
                if ((local_8 & 2) == 0) goto LAB_005517a7;
                local_1a = ' ';
              }
              else {
                local_1a = '+';
              }
            }
            else {
              local_1a = '-';
            }
            local_20 = 1;
          }
LAB_005517a7:
          value11 = (local_24 - local_20) - (intptr_t)local_10;
          if ((local_8 & 0xc) == 0) {
            CRT_WriteMultiChar(0x20,value11,arg1,&local_18);
          }
          CRT_WriteString(&local_1a,local_20,arg1,&local_18);
          if (((uvalue3 & 8) != 0) && ((uvalue3 & 4) == 0)) {
            CRT_WriteMultiChar(0x30,value11,arg1,&local_18);
          }
          if ((local_28 == 0) || ((intptr_t)local_10 < 1)) {
            CRT_WriteString((char *)local_c,(intptr_t)local_10,arg1,&local_18);
          }
          else {
            uptr6 = local_10;
            pWVar7 = local_c;
            do {
              uptr6 = uptr6 + -1;
              WVar1 = *pWVar7;
              pWVar7 = pWVar7 + 1;
              value9 = CRT_Wctomb(local_3c,WVar1);
              if (value9 < 1) break;
              CRT_WriteString(local_3c,value9,arg1,&local_18);
            } while (uptr6 != (uint8_t *)0x0);
          }
          if ((local_8 & 4) != 0) {
            CRT_WriteMultiChar(0x20,value11,arg1,&local_18);
          }
        }
      }
      flag10 = *arg2;
      if (flag10 == 0) {
        return local_18;
      }
      bptr2 = arg2;
    }
  }
  return local_18;
}
