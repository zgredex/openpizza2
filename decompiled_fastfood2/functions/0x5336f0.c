// rea decompile_all
// name: FUN_005336f0
// address: 0x5336f0
// body: available
// range: 0x5336f0-0x5338bb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_005336f0(void *this,int *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  uint uVar6;
  ushort *local_10;
  short *local_c;
  short *local_8;
  int local_4;
  
  if (*(int *)((int)this + 0x54) == -999) {
    local_4 = *(int *)((int)this + 0x68);
    for (iVar5 = 0;
        ((iVar5 < local_4 && (*(short *)(*(int *)((int)this + 0x20) + iVar5 * 2) == 0)) ||
        (*(short *)(*(int *)((int)this + 0x24) + iVar5 * 2) == 0)); iVar5 = iVar5 + 1) {
    }
    if (local_4 <= iVar5) {
      *param_4 = 0;
      *param_3 = 0;
      *param_2 = 0;
      *param_1 = 0;
      return;
    }
    puVar4 = (ushort *)(*(int *)((int)this + 0x28) + iVar5 * 2);
    local_10 = (ushort *)(*(int *)((int)this + 0x2c) + iVar5 * 2);
    *(uint *)((int)this + 0x54) = (uint)*puVar4;
    *(uint *)((int)this + 0x58) = (uint)*local_10;
    local_c = (short *)(*(int *)((int)this + 0x20) + iVar5 * 2);
    if (*(char *)((int)this + 5) == '\b') {
      *(uint *)((int)this + 0x5c) = (uint)*puVar4 + (int)*local_c;
    }
    else {
      *(uint *)((int)this + 0x5c) = (int)*local_c / 2 + (uint)*puVar4;
    }
    local_8 = (short *)(*(int *)((int)this + 0x24) + iVar5 * 2);
    local_4 = local_4 - iVar5;
    *(uint *)((int)this + 0x60) =
         (uint)*local_10 + (int)*(short *)(*(int *)((int)this + 0x24) + iVar5 * 2);
    do {
      sVar1 = *local_c;
      if ((sVar1 != 0) && (*local_8 != 0)) {
        if (*(char *)((int)this + 5) == '\b') {
          uVar2 = *puVar4;
          iVar5 = (int)sVar1;
        }
        else {
          uVar2 = *puVar4;
          iVar5 = (int)sVar1 / 2;
        }
        uVar6 = (uint)uVar2;
        iVar3 = (uint)*local_10 + (int)*local_8;
        if ((int)uVar6 < *(int *)((int)this + 0x54)) {
          *(uint *)((int)this + 0x54) = uVar6;
        }
        if ((int)(uint)*local_10 < *(int *)((int)this + 0x58)) {
          *(uint *)((int)this + 0x58) = (uint)*local_10;
        }
        if (*(int *)((int)this + 0x5c) < (int)(iVar5 + uVar6)) {
          *(uint *)((int)this + 0x5c) = iVar5 + uVar6;
        }
        if (*(int *)((int)this + 0x60) < iVar3) {
          *(int *)((int)this + 0x60) = iVar3;
        }
      }
      local_c = local_c + 1;
      local_8 = local_8 + 1;
      puVar4 = puVar4 + 1;
      local_10 = local_10 + 1;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  *param_3 = *(undefined4 *)((int)this + 0x54);
  *param_4 = *(undefined4 *)((int)this + 0x58);
  *param_1 = *(int *)((int)this + 0x5c) - *(int *)((int)this + 0x54);
  *param_2 = *(int *)((int)this + 0x60) - *(int *)((int)this + 0x58);
  return;
}

