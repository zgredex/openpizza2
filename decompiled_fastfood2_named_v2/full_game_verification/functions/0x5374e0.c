// rea decompile_all
// name: Sprite_Blit24Bit
// address: 0x5374e0
// body: available
// range: 0x5374e0-0x5376ae inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
Sprite_Blit24Bit(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                int param_7)

{
  byte *pbVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  if (param_6 < 0) {
    param_2 = param_2 - param_6;
    param_6 = 0;
  }
  if (param_7 < 0) {
    param_3 = param_3 - param_7;
    param_7 = 0;
  }
  iVar4 = *(int *)((int)this + 4);
  if (param_4 < 0) {
    param_4 = iVar4 - param_6;
    param_5 = *(int *)((int)this + 8) - param_7;
  }
  else {
    if (iVar4 - param_6 < param_4) {
      param_4 = iVar4 - param_6;
    }
    iVar5 = *(int *)((int)this + 8) - param_7;
    if (iVar5 < param_5) {
      param_5 = iVar5;
    }
  }
  iVar5 = *(int *)(param_1 + 4);
  if (param_2 < iVar5) {
    param_6 = iVar5 - param_2;
    param_4 = param_4 - param_6;
    param_2 = iVar5;
  }
  if (*(int *)(param_1 + 8) < param_2 + param_4) {
    param_4 = *(int *)(param_1 + 8) - param_2;
  }
  iVar5 = *(int *)(param_1 + 0xc);
  if (param_3 < iVar5) {
    param_7 = iVar5 - param_3;
    param_5 = param_5 - param_7;
    param_3 = iVar5;
  }
  if (*(int *)(param_1 + 0x10) < param_3 + param_5) {
    param_5 = *(int *)(param_1 + 0x10) - param_3;
  }
  if ((0 < param_4) && (0 < param_5)) {
    puVar6 = (undefined4 *)
             (*(int *)(param_1 + 0x28) + (*(int *)(param_1 + 0x20) * param_3 + param_2) * 2);
    if (*(byte *)((int)this + 0x10) == 8) {
      iVar5 = *(int *)((int)this + 0x14);
      iVar4 = *(int *)((int)this + 0x18) + iVar4 * param_7 + param_6;
      if (0 < param_5) {
        param_2 = param_5;
        do {
          iVar2 = 0;
          if (0 < param_4) {
            puVar3 = puVar6;
            do {
              pbVar1 = (byte *)(iVar2 + iVar4);
              iVar2 = iVar2 + 1;
              *(undefined2 *)puVar3 = *(undefined2 *)(iVar5 + 4 + (uint)*pbVar1 * 2);
              puVar3 = (undefined4 *)((int)puVar3 + 2);
            } while (iVar2 < param_4);
          }
          iVar4 = iVar4 + *(int *)((int)this + 4);
          puVar6 = (undefined4 *)((int)puVar6 + *(int *)(param_1 + 0x20) * 2);
          param_2 = param_2 + -1;
        } while (param_2 != 0);
        return;
      }
    }
    else if ((*(byte *)((int)this + 0x10) < 0x11) &&
            (puVar3 = (undefined4 *)(*(int *)((int)this + 0x18) + (iVar4 * param_7 + param_6) * 2),
            0 < param_5)) {
      do {
        Memory_Fill16(puVar6,puVar3,param_4 * 2,0);
        param_5 = param_5 + -1;
        puVar6 = (undefined4 *)((int)puVar6 + *(int *)(param_1 + 0x20) * 2);
        puVar3 = (undefined4 *)((int)puVar3 + *(int *)((int)this + 4) * 2);
      } while (param_5 != 0);
    }
  }
  return;
}

