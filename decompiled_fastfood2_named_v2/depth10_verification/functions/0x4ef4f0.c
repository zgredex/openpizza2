// rea decompile_all
// name: FUN_004ef4f0
// address: 0x4ef4f0
// body: available
// range: 0x4ef4f0-0x4ef9d4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ef4f0(void *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint local_70;
  uint local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  tagRECT local_20;
  tagRECT local_10;
  
  if (*(int *)((int)param_1 + 0x60) != 0) {
    if (*(int *)(DAT_0057c670 + 0x358) == 0) {
      DAT_00580a4c = 0;
      FUN_004f58e0(param_1);
      *(undefined4 *)(DAT_0057c670 + 0x348) = 0xffffffff;
      *(undefined4 *)(DAT_0057c670 + 0x34c) = 0xffffffff;
    }
    else {
      puVar1 = (undefined4 *)
               FUN_004ef4b0(param_1,*(int *)(DAT_0057c670 + 0x348),*(int *)(DAT_0057c670 + 0x34c));
      if ((puVar1 == (undefined4 *)0x0) || (puVar1[2] == 0)) {
        DAT_00580a4c = 0;
      }
      else {
        FUN_004ed930(param_1,puVar1);
        DAT_00580a4c = 1;
      }
    }
  }
  if (*(int *)((int)param_1 + 0xf4) != 0) {
    SetRect(&local_20,0,0,DAT_00571950,DAT_00571954);
    FUN_00534e20(DAT_0058072c,(uint *)&local_20);
    *(undefined4 *)((int)param_1 + 0xf4) = 0;
    FUN_004ef1c0(param_1,0);
    return;
  }
  FUN_004ef1c0(param_1,1);
  iVar6 = *(int *)((int)param_1 + 0xe4) + *(int *)((int)param_1 + 0x28) + DAT_00571954;
  iVar5 = *(int *)((int)param_1 + 0x28) - *(int *)((int)param_1 + 0xe0);
  SetRect(&local_10,*(int *)((int)param_1 + 0x24) - *(int *)((int)param_1 + 0xd8),iVar5,
          *(int *)((int)param_1 + 0xdc) + *(int *)((int)param_1 + 0x24) + DAT_00571950,iVar6);
  FUN_004ed980(param_1,&local_10.left,&local_50,&local_54,&local_4c,&local_3c,&local_48);
  local_38 = 0;
  iVar4 = *(int *)((int)param_1 + 0x10) >> 1;
  iVar4 = (iVar6 - iVar5) / iVar4 + 3 + *(int *)((int)param_1 + 0xe4) / iVar4;
  local_34 = iVar4;
  if (0 < iVar4) {
    iVar5 = local_50;
    iVar6 = local_4c;
    do {
      local_58 = local_54;
      local_40 = iVar5;
      if (iVar5 <= iVar6) {
        do {
          iVar4 = local_40;
          piVar2 = (int *)FUN_004ef4b0(param_1,local_40,local_58);
          local_58 = local_58 + -1;
          if ((piVar2 != (int *)0x0) && (piVar2[2] != 0)) {
            iVar5 = *(int *)(piVar2[2] + 0x14);
            if (0 < iVar5) {
              iVar4 = 0;
              local_44 = iVar5;
              do {
                iVar5 = *(int *)(*(int *)(piVar2[2] + 0x18) + 8 + iVar4);
                FUN_004ed810(param_1,piVar2,*(void **)(iVar5 + 0x48),&local_68,&local_64);
                FUN_005336f0(*(void **)(iVar5 + 0x48),&local_60,&local_5c,&local_70,&local_6c);
                local_30 = local_70 + local_68;
                local_2c = local_64 + local_6c;
                local_28 = local_30 + local_60;
                local_24 = local_2c + local_5c;
                FUN_00534e20(DAT_0058072c,&local_30);
                iVar4 = iVar4 + 0xc;
                local_44 = local_44 + -1;
              } while (local_44 != 0);
              local_44 = 0;
              iVar4 = local_40;
            }
            FUN_004ee840(param_1,1,(int)piVar2,0,0);
            if ((((DAT_00580a4c != 0) && (*(char *)((int)param_1 + 0xb8) == '\0')) &&
                (*(int *)((int)param_1 + 0x60) != 0)) &&
               ((*(int *)((int)param_1 + 100) != 0 &&
                (*(int *)piVar2[2] == **(int **)(*(int *)((int)param_1 + 100) + 8))))) {
              if (*(char *)((int)*(void **)((int)param_1 + 4) +
                           *(int *)((int)param_1 + 0x68) * 0x48 + 0x24) == '\x01') {
                pvVar3 = (void *)FUN_004eab50(*(void **)((int)param_1 + 4),
                                              *(int *)((int)param_1 + 0x68));
                if (pvVar3 == (void *)0x0) {
                  return;
                }
                FUN_004ed780(param_1,*(int **)((int)param_1 + 100),pvVar3,&local_68,&local_64);
                FUN_0053d090(pvVar3,&local_60,&local_5c);
                FUN_0053d100(pvVar3,(int *)&local_70,(int *)&local_6c);
                local_30 = local_70 + local_68;
                local_2c = local_64 + local_6c;
                local_28 = local_30 + local_60;
                local_24 = local_2c + local_5c;
                FUN_00534e20(DAT_0058072c,&local_30);
                if (DAT_005719b0 != -1) {
                  FUN_00534e20(DAT_0058072c,(uint *)&DAT_005719a8);
                }
                _DAT_005719a8 = local_30;
                _DAT_005719ac = local_2c;
                DAT_005719b0 = local_28;
                _DAT_005719b4 = local_24;
              }
            }
          }
          local_40 = iVar4 + 1;
        } while (local_40 <= local_4c);
        iVar5 = local_50;
        iVar4 = local_34;
        iVar6 = local_4c;
      }
      if (local_48 == 0) {
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 1;
        local_50 = iVar5;
        local_4c = iVar6;
      }
      else {
        local_54 = local_54 + 1;
        local_3c = local_3c + 1;
      }
      local_48 = (uint)(local_48 == 0);
      local_38 = local_38 + 1;
    } while (local_38 < iVar4);
  }
  if (*(int *)((int)param_1 + 0xc) == 0x40) {
    local_38 = 0x2c41c;
    pvVar3 = *(void **)(*(int *)((int)param_1 + 4) + 0x2c3d4);
    do {
      iVar4 = *(int *)(local_38 + *(int *)((int)param_1 + 4));
      if (((-1 < iVar4) && (iVar4 < *(int *)((int)pvVar3 + 0x48))) &&
         (*(char *)(*(int *)((int)pvVar3 + 0x4c) + 0x3e + iVar4 * 0x48) != '\0')) {
        FUN_00534370(pvVar3,iVar4,&local_68,&local_64);
        FUN_00534060(pvVar3,iVar4,&local_60,&local_5c,&local_70,&local_6c);
        FUN_005340d0(pvVar3,iVar4,(int *)&local_70,(int *)&local_6c);
        iVar4 = (local_70 - 10) + local_68;
        iVar5 = (local_6c - 10) + local_64;
        local_30 = iVar4 - *(int *)((int)param_1 + 0x24);
        local_28 = (iVar4 + 10 + local_60) - *(int *)((int)param_1 + 0x24);
        local_2c = iVar5 - *(int *)((int)param_1 + 0x28);
        local_24 = (iVar5 + 10 + local_5c) - *(int *)((int)param_1 + 0x28);
        FUN_00534e20(DAT_0058072c,&local_30);
      }
      local_38 = local_38 + 4;
    } while (local_38 < 0x2c434);
  }
  return;
}

