// rea decompile_all
// name: FUN_0050f870
// address: 0x50f870
// body: available
// range: 0x50f870-0x50faaa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_0050f870(void *this,int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint local_14;
  int local_c;
  int local_8;
  int local_4;
  
  iVar1 = Game_GetPlayerBySlot(DAT_0057c670,param_1);
  if (*(int *)(iVar1 + 0x15c) == 0) {
    return 0;
  }
  param_1 = 0x28;
  if (*(int *)((int)this + 0x10) != 0) {
    param_1 = (*(int *)(&DAT_005730ac + (param_2 + *(int *)((int)this + 0x10) * 8) * 4) + 8) * 5;
  }
  if (*(int *)((int)this + 0x1c) < 1) {
    local_c = 0;
  }
  else {
    local_c = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((int)this + 0x1c));
  }
  if (*(int *)((int)this + 0x14) != 0) {
    local_14 = 1;
    do {
      if ((*(uint *)((int)this + 0x14) & local_14) != 0) {
        local_8 = 0x2d;
        local_4 = 0x37;
        if (local_c != 0) {
          iVar6 = *(int *)(local_c + 0x15c);
          iVar4 = 0;
          iVar5 = 0;
          if (0 < iVar6) {
            do {
              pvVar2 = (void *)IDMap_Lookup((void *)(local_c + 0x148),iVar5,(int *)0x0);
              iVar3 = FUN_0050fab0(this,local_14,pvVar2,param_2,local_14);
              iVar4 = iVar4 + iVar3;
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar6);
            if (0 < iVar6) {
              local_8 = iVar4 / iVar6 + -5;
              local_4 = iVar4 / iVar6 + 5;
            }
          }
        }
        if ((*(int *)((int)this + 8) == 2) || (*(int *)((int)this + 8) == 3)) {
          pvVar2 = (void *)IDMap_Lookup((void *)(iVar1 + 0x148),*(int *)((int)this + 0xc),(int *)0x0
                                       );
          iVar6 = FUN_0050fab0(this,param_2,pvVar2,param_2,local_14);
        }
        else {
          iVar6 = 0;
          iVar5 = 0;
          iVar4 = *(int *)(iVar1 + 0x15c);
          if (0 < iVar4) {
            do {
              pvVar2 = (void *)IDMap_Lookup((void *)(iVar1 + 0x148),iVar5,(int *)0x0);
              iVar3 = FUN_0050fab0(this,local_14,pvVar2,param_2,local_14);
              iVar6 = iVar6 + iVar3;
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar4);
            if (0 < iVar4) {
              iVar6 = iVar6 / iVar4;
            }
          }
        }
        if (iVar6 < local_8) {
          param_1 = param_1 - (local_8 - iVar6 >> 2);
        }
        if (local_4 < iVar6) {
          param_1 = param_1 + (iVar6 - local_4 >> 1);
        }
      }
      local_14 = local_14 * 2;
    } while ((int)local_14 < 0xf);
  }
  iVar6 = Company_GetPercentModifier(this,-1);
  iVar1 = Game_GetPlayerCity(iVar1);
  iVar1 = (((*(int *)(iVar1 + 100) + *(int *)(iVar1 + 0x4c)) * -3 + 100) *
          ((iVar6 * (param_1 + -0x28)) / 100 + 0x28)) / 100;
  if (iVar1 < 0) {
    return 0;
  }
  if (100 < iVar1) {
    iVar1 = 100;
  }
  return iVar1;
}

