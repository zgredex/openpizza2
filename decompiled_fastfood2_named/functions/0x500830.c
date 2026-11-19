// rea decompile_all
// name: FUN_00500830
// address: 0x500830
// body: available
// range: 0x500830-0x500e66 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl FUN_00500830(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  bool bVar9;
  bool bVar10;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  uint local_68;
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
  uVar2 = FUN_00500470(param_1,&local_70,&local_74,&local_68,1);
  if ((char)uVar2 == '\0') {
    return 0;
  }
  if (*(int *)(param_1 + 8) != 0) {
    uVar2 = FUN_00500470(param_1,&local_70,&local_74,&local_68,0);
    cVar1 = (char)uVar2;
    while (cVar1 != '\0') {
      iVar7 = 0;
      local_78 = 0;
      if ((int)local_68 < 2) {
        local_58 = local_70 * 0x50;
        iVar5 = (-(uint)(local_68 != 0) & 0xfffffffe) + 1;
        if (*(char *)(param_1 + 0x28 + local_58 + local_74) == '.') {
          do {
            local_64 = (char *)0x1;
            pcVar8 = (char *)((iVar5 + local_70) * 0x50 + iVar7 + local_74 + 0x28 + param_1);
            iVar7 = 1;
            do {
              if (*pcVar8 != '.') {
                if (iVar7 < 0xc) goto LAB_005009ab;
                break;
              }
              iVar7 = iVar7 + 1;
              pcVar8 = pcVar8 + iVar5 * 0x50;
            } while (iVar7 < 0xc);
            local_78 = local_78 + 1;
            iVar7 = local_50[local_68] * local_78;
          } while (*(char *)(param_1 + 0x28 + local_58 + iVar7 + local_74) == '.');
LAB_005009ab:
          bVar10 = local_78 < 0;
          bVar9 = false;
          if (local_78 != 0) goto LAB_00500bed;
        }
        local_64 = (char *)0x0;
        local_5c = 0;
        do {
          iVar7 = (local_5c + local_70) * 0x50 + local_74 + local_50[local_68] * local_78;
          if (*(char *)(iVar7 + 0x28 + param_1) != '.') break;
          *(undefined1 *)(iVar7 + 0x28 + param_1) = 0x20;
          local_64 = local_64 + 1;
          local_5c = local_5c + iVar5;
        } while ((int)local_64 < 0xc);
LAB_00500ad4:
        bVar10 = local_78 < 0;
        bVar9 = local_78 == 0;
        if (!bVar9) goto LAB_00500bed;
        local_54 = local_70 * 0x50 + local_74;
        local_64 = (char *)(local_54 + 0x28 + param_1);
        pcVar8 = local_64;
        local_60 = local_70;
        cVar1 = *local_64;
        while (cVar1 == '.') {
          pcVar8 = pcVar8 + -0x50;
          local_60 = local_60 + -1;
          cVar1 = *pcVar8;
        }
        cVar1 = *local_64;
        pcVar8 = local_64;
        iVar7 = local_70;
        while (cVar1 == '.') {
          pcVar8 = pcVar8 + 0x50;
          iVar7 = iVar7 + 1;
          cVar1 = *pcVar8;
        }
        local_58 = local_74;
        if (*local_64 == '.') {
          pcVar8 = local_64;
          do {
            local_58 = local_58 + -1;
            pcVar8 = pcVar8 + -1;
          } while (*pcVar8 == '.');
        }
        local_5c = local_74;
        if (*(char *)(local_54 + 0x28 + param_1) == '.') {
          pcVar8 = local_64;
          do {
            local_5c = local_5c + 1;
            pcVar8 = pcVar8 + 1;
          } while (*pcVar8 == '.');
        }
        if ((iVar7 - local_60 < 0xe) && (local_5c - local_58 < 0xe)) {
          iVar6 = local_60 + 1;
          iVar5 = local_58;
          if (iVar6 < iVar7) {
            iVar3 = iVar6 * 0x50;
            iVar7 = iVar7 - iVar6;
            do {
              iVar6 = local_74 + iVar3;
              iVar3 = iVar3 + 0x50;
              iVar7 = iVar7 + -1;
              *(undefined1 *)(iVar6 + 0x28 + param_1) = 0x20;
            } while (iVar7 != 0);
          }
          while (iVar5 = iVar5 + 1, iVar5 < local_5c) {
            *(undefined1 *)(local_70 * 0x50 + iVar5 + 0x28 + param_1) = 0x20;
          }
          bVar10 = false;
          bVar9 = true;
          goto LAB_00500bed;
        }
      }
      else {
        iVar7 = local_70 * 0x50;
        iVar5 = (-(uint)(local_68 != 2) & 0xfffffffe) + 1;
        if (*(char *)(param_1 + 0x28 + iVar7 + local_74) != '.') {
LAB_00500a87:
          iVar7 = 0;
          local_64 = (char *)0x0;
          do {
            iVar6 = (local_50[local_68] * local_78 + local_70) * 0x50 + iVar7 + local_74;
            if (*(char *)(iVar6 + 0x28 + param_1) != '.') break;
            iVar7 = iVar7 + iVar5;
            local_64 = local_64 + 1;
            *(undefined1 *)(iVar6 + 0x28 + param_1) = 0x20;
          } while ((int)local_64 < 0xc);
          goto LAB_00500ad4;
        }
        do {
          iVar6 = 1;
          pcVar8 = (char *)(iVar7 + iVar5 + local_74 + 0x28 + param_1);
          do {
            if (*pcVar8 != '.') {
              if (iVar6 < 0xc) goto LAB_00500a7f;
              break;
            }
            iVar6 = iVar6 + 1;
            pcVar8 = pcVar8 + iVar5;
          } while (iVar6 < 0xc);
          local_78 = local_78 + 1;
          iVar7 = (local_50[local_68] * local_78 + local_70) * 0x50;
        } while (*(char *)(param_1 + 0x28 + iVar7 + local_74) == '.');
LAB_00500a7f:
        bVar10 = local_78 < 0;
        bVar9 = local_78 == 0;
        if (bVar9) goto LAB_00500a87;
LAB_00500bed:
        if (!bVar9 && !bVar10) {
          do {
            if (local_78 == 1) {
              iVar7 = 2;
LAB_00500c11:
              FUN_00500580(param_1,&local_70,&local_74,local_68,iVar7,&local_78);
              if (local_6c < 0xf) {
                local_6c = local_6c + 1;
              }
            }
            else {
              if (local_78 == 2) {
                iVar7 = 0x14;
                goto LAB_00500c11;
              }
              if (0xb < local_78) {
                uVar4 = _rand();
                iVar7 = local_6c;
                if ((int)(uVar4 & 100) < local_50[local_6c + 4]) {
                  FUN_00500580(param_1,&local_70,&local_74,local_68,2,&local_78);
                  if (iVar7 < 0xf) {
                    local_6c = iVar7 + 1;
                  }
                  goto LAB_00500e2c;
                }
                if (local_78 == 0xc) {
                  iVar7 = 0;
                }
                else {
                  iVar7 = 0;
                }
LAB_00500e1b:
                FUN_00500580(param_1,&local_70,&local_74,local_68,iVar7,&local_78);
                local_6c = 0;
                goto LAB_00500e2c;
              }
              bVar10 = true;
              switch(local_68) {
              case 0:
                iVar5 = local_70 * 0x50 + local_74;
                iVar7 = iVar5 + param_1;
                if ((*(char *)(iVar5 + -0x28 + param_1) == '@') && (*(char *)(iVar7 + -0x27) == '@')
                   ) {
                  cVar1 = *(char *)(iVar7 + -0x26);
joined_r0x00500ce1:
                  if (cVar1 == '@') goto switchD_00500c5e_default;
                }
                break;
              case 1:
                iVar7 = local_70 * 0x50 + local_74 + param_1;
                if ((*(char *)(iVar7 + 0x78) == '@') && (*(char *)(iVar7 + 0x77) == '@')) {
                  cVar1 = *(char *)(iVar7 + 0x76);
                  goto joined_r0x00500ce1;
                }
                break;
              case 2:
                iVar5 = local_70 * 0x50 + local_74;
                iVar7 = iVar5 + param_1;
                if ((*(char *)(iVar5 + 0x27 + param_1) == '@') && (*(char *)(iVar7 + -0x29) == '@'))
                {
                  cVar1 = *(char *)(iVar7 + -0x79);
                  goto joined_r0x00500ce1;
                }
                break;
              case 3:
                iVar7 = local_70 * 0x50 + local_74 + param_1;
                if ((*(char *)(iVar7 + 0x29) == '@') && (*(char *)(iVar7 + -0x27) == '@')) {
                  cVar1 = *(char *)(iVar7 + -0x77);
                  goto joined_r0x00500ce1;
                }
                break;
              default:
                goto switchD_00500c5e_default;
              }
              bVar10 = false;
switchD_00500c5e_default:
              uVar4 = FUN_004034b0(100);
              if (uVar4 < 10) {
                if ((local_78 < 4) || (uVar4 = FUN_004034b0(100), 0x31 < uVar4)) goto LAB_00500d48;
                FUN_00500580(param_1,&local_70,&local_74,local_68,7,&local_78);
                local_6c = local_6c + 4;
              }
              else {
                if (bVar10) {
                  iVar7 = 3;
                  goto LAB_00500e1b;
                }
LAB_00500d48:
                FUN_00500580(param_1,&local_70,&local_74,local_68,6,&local_78);
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
      uVar2 = FUN_00500470(param_1,&local_70,&local_74,&local_68,0);
      cVar1 = (char)uVar2;
    }
  }
  return 1;
}

