// rea decompile_all
// name: UI_FillFadeRect
// address: 0x5282c0
// body: available
// range: 0x5282c0-0x5283a8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall UI_FillFadeRect(void *this,int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  short *psVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  undefined4 local_4;
  
  uVar1 = *(ushort *)(param_1 + 0x1a);
  uVar2 = *(ushort *)(param_1 + 0x1c);
  psVar6 = *(short **)(param_1 + 0x28);
  uVar5 = 1;
  local_4 = 1;
  if (*(int *)((int)this + 0xc) == 0x42000000) {
    uVar5 = 0;
    local_4 = 0;
  }
  else {
    fVar3 = (float)param_2 * *(float *)((int)this + 8) + *(float *)((int)this + 0xc);
    *(float *)((int)this + 0xc) = fVar3;
    if (32.0 < fVar3) {
      *(undefined4 *)((int)this + 0xc) = 0x42000000;
    }
  }
  iVar4 = (uint)uVar2 * (uint)uVar1;
  if (iVar4 < 1) {
    return uVar5;
  }
  do {
    lVar7 = __ftol();
    lVar8 = __ftol();
    lVar9 = __ftol();
    iVar4 = iVar4 + -1;
    *psVar6 = (((ushort)lVar7 & 0x1f) * 0x20 + ((ushort)lVar8 & 0x1f)) * 0x40 +
              ((ushort)lVar9 & 0x1f);
    psVar6 = psVar6 + 1;
  } while (iVar4 != 0);
  return local_4;
}

