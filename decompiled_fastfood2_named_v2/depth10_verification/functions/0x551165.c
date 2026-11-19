// rea decompile_all
// name: FUN_00551165
// address: 0x551165
// body: available
// range: 0x551165-0x551885 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __cdecl FUN_00551165(int *param_1,byte *param_2,undefined4 *param_3)

{
  WCHAR WVar1;
  byte *pbVar2;
  uint uVar3;
  undefined4 uVar4;
  short *psVar5;
  undefined1 *puVar6;
  WCHAR *pWVar7;
  int *piVar8;
  int iVar9;
  byte bVar10;
  int iVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  longlong lVar14;
  undefined1 local_24c [511];
  undefined1 local_4d;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  uint local_40;
  CHAR local_3c [4];
  undefined4 local_38;
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
  undefined1 *local_10;
  WCHAR *local_c;
  uint local_8;
  
  local_34 = 0;
  bVar10 = *param_2;
  local_10 = (undefined1 *)0x0;
  local_18 = 0;
  if (bVar10 != 0) {
    pbVar2 = param_2;
    while (param_2 = pbVar2 + 1, -1 < local_18) {
      if (((char)bVar10 < ' ') || ('x' < (char)bVar10)) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(byte *)((int)&PTR_LAB_0055ccfc + (int)(char)bVar10) & 0xf;
      }
      local_34 = (int)(char)(&DAT_0055cd1c)[uVar3 * 8 + local_34] >> 4;
      switch(local_34) {
      case 0:
switchD_005511d3_caseD_0:
        local_28 = 0;
        if ((PTR_DAT_00576ae4[(uint)bVar10 * 2 + 1] & 0x80) != 0) {
          FUN_005518a6((int)(char)bVar10,param_1,&local_18);
          bVar10 = *param_2;
          param_2 = pbVar2 + 2;
        }
        FUN_005518a6((int)(char)bVar10,param_1,&local_18);
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
        if (bVar10 == 0x20) {
          local_8 = local_8 | 2;
        }
        else if (bVar10 == 0x23) {
          local_8 = local_8 | 0x80;
        }
        else if (bVar10 == 0x2b) {
          local_8 = local_8 | 1;
        }
        else if (bVar10 == 0x2d) {
          local_8 = local_8 | 4;
        }
        else if (bVar10 == 0x30) {
          local_8 = local_8 | 8;
        }
        break;
      case 3:
        if (bVar10 == 0x2a) {
          local_24 = FUN_00551944((int *)&param_3);
          if (local_24 < 0) {
            local_8 = local_8 | 4;
            local_24 = -local_24;
          }
        }
        else {
          local_24 = (char)bVar10 + -0x30 + local_24 * 10;
        }
        break;
      case 4:
        local_14 = 0;
        break;
      case 5:
        if (bVar10 == 0x2a) {
          local_14 = FUN_00551944((int *)&param_3);
          if (local_14 < 0) {
            local_14 = -1;
          }
        }
        else {
          local_14 = (char)bVar10 + -0x30 + local_14 * 10;
        }
        break;
      case 6:
        if (bVar10 == 0x49) {
          if ((*param_2 != 0x36) || (pbVar2[2] != 0x34)) {
            local_34 = 0;
            goto switchD_005511d3_caseD_0;
          }
          param_2 = pbVar2 + 3;
          local_8 = local_8 | 0x8000;
        }
        else if (bVar10 == 0x68) {
          local_8 = local_8 | 0x20;
        }
        else if (bVar10 == 0x6c) {
          local_8 = local_8 | 0x10;
        }
        else if (bVar10 == 0x77) {
          local_8 = local_8 | 0x800;
        }
        break;
      case 7:
        pWVar7 = local_c;
        if ((char)bVar10 < 'h') {
          if ('d' < (char)bVar10) {
LAB_005513f3:
            local_8 = local_8 | 0x40;
            pWVar7 = (WCHAR *)local_24c;
            if (local_14 < 0) {
              local_14 = 6;
            }
            else if ((local_14 == 0) && (bVar10 == 0x67)) {
              local_14 = 1;
            }
            local_4c = *param_3;
            local_48 = param_3[1];
            param_3 = param_3 + 2;
            local_c = pWVar7;
            (*(code *)PTR_FUN_00576a18)(&local_4c,local_24c,(int)(char)bVar10,local_14,local_38);
            uVar3 = local_8 & 0x80;
            if ((uVar3 != 0) && (local_14 == 0)) {
              (*(code *)PTR_FUN_00576a24)(local_24c);
            }
            if ((bVar10 == 0x67) && (uVar3 == 0)) {
              (*(code *)PTR_FUN_00576a1c)(local_24c);
            }
            if (local_24c[0] == '-') {
              local_8 = local_8 | 0x100;
              pWVar7 = (WCHAR *)(local_24c + 1);
              local_c = pWVar7;
            }
LAB_00551565:
            puVar6 = (undefined1 *)_strlen((char *)pWVar7);
            goto LAB_0055176c;
          }
          if ((char)bVar10 < 'Y') {
            if (bVar10 == 0x58) {
LAB_005515e4:
              local_30 = 7;
LAB_005515eb:
              local_10 = (undefined1 *)0x10;
              if ((local_8 & 0x80) != 0) {
                local_1a = '0';
                local_19 = (char)local_30 + 'Q';
                local_20 = 2;
              }
              goto LAB_00551655;
            }
            if (bVar10 == 0x43) {
              if ((local_8 & 0x830) == 0) {
                local_8 = local_8 | 0x800;
              }
              goto LAB_00551420;
            }
            if ((bVar10 != 0x45) && (bVar10 != 0x47)) {
              if (bVar10 == 0x53) {
                if ((local_8 & 0x830) == 0) {
                  local_8 = local_8 | 0x800;
                }
                goto LAB_00551392;
              }
              goto LAB_0055176f;
            }
            local_38 = 1;
            bVar10 = bVar10 + 0x20;
            goto LAB_005513f3;
          }
          if (bVar10 == 0x5a) {
            psVar5 = (short *)FUN_00551944((int *)&param_3);
            if ((psVar5 != (short *)0x0) &&
               (local_c = *(WCHAR **)(psVar5 + 2), local_c != (WCHAR *)0x0)) {
              if ((local_8 & 0x800) == 0) {
                local_28 = 0;
                puVar6 = (undefined1 *)(int)*psVar5;
                goto LAB_0055176c;
              }
              local_10 = (undefined1 *)((uint)(int)*psVar5 >> 1);
              local_28 = 1;
              pWVar7 = local_c;
              goto LAB_0055176f;
            }
            local_c = (WCHAR *)PTR_DAT_00576a10;
            pWVar7 = (WCHAR *)PTR_DAT_00576a10;
            goto LAB_00551565;
          }
          if (bVar10 == 99) {
LAB_00551420:
            if ((local_8 & 0x810) == 0) {
              uVar4 = FUN_00551944((int *)&param_3);
              local_24c[0] = (char)uVar4;
              local_10 = (undefined1 *)0x1;
            }
            else {
              uVar4 = FUN_00551961((int *)&param_3);
              local_10 = (undefined1 *)CRT_Wctomb(local_24c,(WCHAR)uVar4);
              if ((int)local_10 < 0) {
                local_2c = 1;
              }
            }
            pWVar7 = (WCHAR *)local_24c;
          }
          else if (bVar10 == 100) goto LAB_0055164a;
        }
        else {
          if (bVar10 == 0x69) {
LAB_0055164a:
            local_8 = local_8 | 0x40;
LAB_0055164e:
            local_10 = (undefined1 *)0xa;
LAB_00551655:
            if ((local_8 & 0x8000) == 0) {
              if ((local_8 & 0x20) == 0) {
                if ((local_8 & 0x40) == 0) {
                  uVar3 = FUN_00551944((int *)&param_3);
                  uVar12 = (ulonglong)uVar3;
                  goto LAB_005516a8;
                }
                uVar3 = FUN_00551944((int *)&param_3);
              }
              else if ((local_8 & 0x40) == 0) {
                uVar3 = FUN_00551944((int *)&param_3);
                uVar3 = uVar3 & 0xffff;
              }
              else {
                uVar4 = FUN_00551944((int *)&param_3);
                uVar3 = (uint)(short)uVar4;
              }
              uVar12 = (ulonglong)(int)uVar3;
            }
            else {
              uVar12 = FUN_00551951((int *)&param_3);
            }
LAB_005516a8:
            iVar11 = (int)(uVar12 >> 0x20);
            if ((((local_8 & 0x40) != 0) && (iVar11 == 0 || (longlong)uVar12 < 0)) &&
               ((longlong)uVar12 < 0)) {
              local_8 = local_8 | 0x100;
              uVar12 = CONCAT44(-(iVar11 + (uint)((int)uVar12 != 0)),-(int)uVar12);
            }
            iVar11 = (int)(uVar12 >> 0x20);
            if ((local_8 & 0x8000) == 0) {
              iVar11 = 0;
            }
            lVar14 = CONCAT44(iVar11,(int)uVar12);
            if (local_14 < 0) {
              local_14 = 1;
            }
            else {
              local_8 = local_8 & 0xfffffff7;
            }
            if ((int)uVar12 == 0 && iVar11 == 0) {
              local_20 = 0;
            }
            local_c = (WCHAR *)&local_4d;
            while ((iVar11 = local_14 + -1, 0 < local_14 || (lVar14 != 0))) {
              local_40 = (int)local_10 >> 0x1f;
              local_44 = (uint)local_10;
              uVar3 = (uint)((ulonglong)lVar14 >> 0x20);
              local_14 = iVar11;
              uVar13 = __aullrem((uint)lVar14,uVar3,(uint)local_10,local_40);
              iVar11 = (int)uVar13 + 0x30;
              lVar14 = __aulldiv((uint)lVar14,uVar3,local_44,local_40);
              if (0x39 < iVar11) {
                iVar11 = iVar11 + local_30;
              }
              pWVar7 = (WCHAR *)((int)local_c + -1);
              *(char *)local_c = (char)iVar11;
              local_c = pWVar7;
            }
            local_10 = local_24c + -(int)local_c + 0x1ff;
            pWVar7 = (WCHAR *)((int)local_c + 1);
            local_14 = iVar11;
            if ((local_8 & 0x200) == 0) goto LAB_0055176f;
            if (*(char *)pWVar7 == '0') {
              if (local_10 != (undefined1 *)0x0) goto LAB_0055176f;
            }
            puVar6 = local_24c + -(int)local_c + 0x200;
            *(char *)local_c = '0';
          }
          else {
            if (bVar10 == 0x6e) {
              piVar8 = (int *)FUN_00551944((int *)&param_3);
              if ((local_8 & 0x20) == 0) {
                *piVar8 = local_18;
              }
              else {
                *(undefined2 *)piVar8 = (undefined2)local_18;
              }
              local_2c = 1;
              break;
            }
            if (bVar10 == 0x6f) {
              local_10 = (undefined1 *)0x8;
              if ((local_8 & 0x80) != 0) {
                local_8 = local_8 | 0x200;
              }
              goto LAB_00551655;
            }
            if (bVar10 == 0x70) {
              local_14 = 8;
              goto LAB_005515e4;
            }
            if (bVar10 != 0x73) {
              if (bVar10 != 0x75) {
                if (bVar10 != 0x78) goto LAB_0055176f;
                local_30 = 0x27;
                goto LAB_005515eb;
              }
              goto LAB_0055164e;
            }
LAB_00551392:
            iVar11 = local_14;
            if (local_14 == -1) {
              iVar11 = 0x7fffffff;
            }
            local_c = (WCHAR *)FUN_00551944((int *)&param_3);
            if ((local_8 & 0x810) == 0) {
              if (local_c == (WCHAR *)0x0) {
                local_c = (WCHAR *)PTR_DAT_00576a10;
              }
              for (pWVar7 = local_c; (iVar11 != 0 && ((char)*pWVar7 != '\0'));
                  pWVar7 = (WCHAR *)((int)pWVar7 + 1)) {
                iVar11 = iVar11 + -1;
              }
              puVar6 = (undefined1 *)((int)pWVar7 - (int)local_c);
            }
            else {
              if (local_c == (WCHAR *)0x0) {
                local_c = (WCHAR *)PTR_DAT_00576a14;
              }
              local_28 = 1;
              for (pWVar7 = local_c; (iVar11 != 0 && (*pWVar7 != L'\0')); pWVar7 = pWVar7 + 1) {
                iVar11 = iVar11 + -1;
              }
              puVar6 = (undefined1 *)((int)pWVar7 - (int)local_c >> 1);
            }
          }
LAB_0055176c:
          local_10 = puVar6;
          pWVar7 = local_c;
        }
LAB_0055176f:
        local_c = pWVar7;
        uVar3 = local_8;
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
          iVar11 = (local_24 - local_20) - (int)local_10;
          if ((local_8 & 0xc) == 0) {
            FUN_005518db(0x20,iVar11,param_1,&local_18);
          }
          FUN_0055190c(&local_1a,local_20,param_1,&local_18);
          if (((uVar3 & 8) != 0) && ((uVar3 & 4) == 0)) {
            FUN_005518db(0x30,iVar11,param_1,&local_18);
          }
          if ((local_28 == 0) || ((int)local_10 < 1)) {
            FUN_0055190c((char *)local_c,(int)local_10,param_1,&local_18);
          }
          else {
            puVar6 = local_10;
            pWVar7 = local_c;
            do {
              puVar6 = puVar6 + -1;
              WVar1 = *pWVar7;
              pWVar7 = pWVar7 + 1;
              iVar9 = CRT_Wctomb(local_3c,WVar1);
              if (iVar9 < 1) break;
              FUN_0055190c(local_3c,iVar9,param_1,&local_18);
            } while (puVar6 != (undefined1 *)0x0);
          }
          if ((local_8 & 4) != 0) {
            FUN_005518db(0x20,iVar11,param_1,&local_18);
          }
        }
      }
      bVar10 = *param_2;
      if (bVar10 == 0) {
        return local_18;
      }
      pbVar2 = param_2;
    }
  }
  return local_18;
}

