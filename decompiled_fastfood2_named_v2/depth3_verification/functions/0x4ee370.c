// rea decompile_all
// name: FUN_004ee370
// address: 0x4ee370
// body: available
// range: 0x4ee370-0x4ee634 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004ee370(void *this,uint *param_1,int param_2)

{
  void *pvVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  void *local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar5 = 0;
  if (*(int *)((int)this + 0xc) == 0x10) {
    pvVar1 = (void *)FUN_004eab50(*(void **)((int)this + 4),*(int *)(param_1[2] + 0x1c));
    if (pvVar1 != (void *)0x0) {
      if (param_2 == 0) {
        UI_DrawObjectSprite(this,param_1,pvVar1);
        return;
      }
      FUN_004ed780(this,(int *)param_1,pvVar1,&local_48,&local_44);
      FUN_0053d100(pvVar1,&local_38,&local_40);
      FUN_0053d090(pvVar1,&local_3c,&local_34);
      local_18 = local_38 + local_48;
      local_14 = local_44 + local_40;
      local_10 = local_18 + local_3c;
      local_c = local_14 + local_34;
      FUN_00534e20(DAT_0058072c,&local_18);
      return;
    }
  }
  else {
    pvVar1 = (void *)FUN_004eab50(*(void **)((int)this + 4),*(int *)(param_1[2] + 0x10));
    if (pvVar1 != (void *)0x0) {
      FUN_004ed780(this,(int *)param_1,pvVar1,&local_48,&local_44);
      FUN_0053d100(pvVar1,&local_38,&local_40);
      FUN_0053d090(pvVar1,&local_3c,&local_34);
      local_28 = *(void **)(*(int *)((int)this + 4) + 0x2c3b4);
      local_30 = *(int *)(*(int *)((int)this + 4) + 0x2c418);
      FUN_005336f0(local_28,&local_2c,&local_1c,&local_20,&local_24);
      if (param_2 == 0) {
        if (DAT_00571968 != 0xffffffff) {
          puVar4 = &DAT_00571968;
          uVar2 = DAT_00571968;
          do {
            if ((*(uint *)(param_1[2] + 0x1c) & uVar2) != 0) {
              iVar5 = iVar5 + local_2c;
            }
            uVar2 = puVar4[1];
            puVar4 = puVar4 + 1;
          } while (uVar2 != 0xffffffff);
        }
        local_44 = local_44 + local_40;
        iVar6 = 0;
        local_48 = local_48 + ((local_3c >> 1) - (iVar5 >> 1)) + local_38;
        if (DAT_00571968 != 0xffffffff) {
          iVar5 = 0;
          puVar3 = &DAT_00571968;
          do {
            pvVar1 = local_28;
            if ((*puVar3 & *(uint *)(param_1[2] + 0x1c)) != 0) {
              if (iVar6 == 0) {
                iVar5 = (uint)*(byte *)(param_1[2] + 0x2c) + DAT_00571988;
              }
              else {
                iVar5 = *(int *)((int)&DAT_00571988 + iVar5);
              }
              FUN_00534990(local_28,local_30,iVar5);
              Record_DrawSprite48(pvVar1,*(uint **)((int)this + 8),DAT_0058072c,local_30);
              local_48 = local_48 + local_2c;
            }
            iVar6 = iVar6 + 1;
            iVar5 = iVar6 * 4;
            puVar3 = &DAT_00571968 + iVar6;
          } while ((&DAT_00571968)[iVar6] != -1);
        }
      }
      else {
        local_14 = local_44 + local_40;
        local_18 = ((local_3c >> 1) - (local_2c * 8 >> 1)) + local_38 + local_48;
        local_10 = local_18 + local_2c * 8;
        local_c = local_14 + local_34;
        if (DAT_0058072c != (void *)0x0) {
          FUN_00534e20(DAT_0058072c,&local_18);
          return;
        }
      }
    }
  }
  return;
}

