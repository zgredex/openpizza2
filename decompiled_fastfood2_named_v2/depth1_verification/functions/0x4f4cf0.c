// rea decompile_all
// name: FUN_004f4cf0
// address: 0x4f4cf0
// body: available
// range: 0x4f4cf0-0x4f4e80 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004f4cf0(void *param_1)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  tagRECT local_10;
  
  if (*(int *)((int)param_1 + 0x40) != 0) {
    iVar4 = *(int *)((int)param_1 + 0x70);
    if (iVar4 == 0) {
      FUN_0053d090(*(void **)((int)param_1 + 0x74),&local_28,&local_2c);
    }
    else {
      local_28 = *(int *)(iVar4 + 4);
      local_2c = *(int *)(iVar4 + 8);
    }
    iVar4 = *(int *)((int)param_1 + 0x30) + local_2c;
    iVar1 = *(int *)((int)param_1 + 0x30) - *(int *)((int)param_1 + 0x10) * DAT_00571964;
    SetRect(&local_10,*(int *)((int)param_1 + 0x2c) - *(int *)((int)param_1 + 0xc) * DAT_00571960,
            iVar1,*(int *)((int)param_1 + 0x2c) + local_28,iVar4);
    FUN_004ed980(param_1,&local_10.left,&local_38,&local_3c,&local_34,&local_24,&local_30);
    iVar5 = *(int *)((int)param_1 + 0x10) >> 1;
    local_20 = (iVar4 - iVar1) / iVar5 + 3 + *(int *)((int)param_1 + 0xe4) / iVar5;
    if (0 < local_20) {
      iVar4 = local_34;
      iVar1 = local_38;
      do {
        iVar5 = local_3c;
        if (iVar1 <= iVar4) {
          while( true ) {
            piVar2 = (int *)FUN_004ef4b0(param_1,iVar1,iVar5);
            local_1c = iVar5 + -1;
            if ((piVar2 != (int *)0x0) && (iVar4 = *(int *)(piVar2[2] + 0x10), -1 < iVar4)) {
              piVar7 = &local_18;
              piVar6 = &local_14;
              pvVar3 = (void *)FUN_004eab50(*(void **)((int)param_1 + 4),iVar4);
              UI_AlignSpriteToRect(param_1,piVar2,pvVar3,piVar6,piVar7);
              pvVar3 = *(void **)(*(int *)((int)param_1 + 4) + 0x60 + iVar4 * 0x48);
              if (pvVar3 != (void *)0x0) {
                Sprite_BlitRLEMasked(param_1,pvVar3,local_14,local_18);
              }
            }
            iVar1 = iVar1 + 1;
            if (local_34 < iVar1) break;
            iVar5 = local_1c;
          }
          iVar4 = local_34;
          iVar1 = local_38;
        }
        if (local_30 == 0) {
          iVar1 = iVar1 + 1;
          iVar4 = iVar4 + 1;
          local_38 = iVar1;
          local_34 = iVar4;
        }
        else {
          local_3c = local_3c + 1;
          local_24 = local_24 + 1;
        }
        local_30 = (uint)(local_30 == 0);
        local_20 = local_20 + -1;
      } while (local_20 != 0);
    }
  }
  return;
}

