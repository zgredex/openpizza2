// rea decompile_all
// name: FUN_0050d810
// address: 0x50d810
// body: available
// range: 0x50d810-0x50d8ea inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0050d810(void *this,void *param_1,int param_2)

{
  void *pvVar1;
  undefined *puVar2;
  int iVar3;
  longlong lVar4;
  
  if (*(int *)((int)this + 0x30) == 0xd) {
    puVar2 = (undefined *)FUN_0050d7f0(this,2);
  }
  else {
    pvVar1 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((int)this + 0x110));
    if (pvVar1 == (void *)0x0) {
      return;
    }
    puVar2 = Economy_GetModifier(pvVar1,*(int *)((int)this + 0x30),2);
  }
  if (*(int *)((int)param_1 + 0x30) == 0xd) {
    FUN_0050d7f0(param_1,1);
  }
  else {
    pvVar1 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((int)param_1 + 0x110));
    if (pvVar1 == (void *)0x0) {
      return;
    }
    Economy_GetModifier(pvVar1,*(int *)((int)param_1 + 0x30),1);
  }
  if (puVar2 == (undefined *)0x0) {
    iVar3 = 100;
  }
  else {
    lVar4 = __ftol();
    iVar3 = (int)lVar4;
  }
  if (*(int *)((int)this + 0xa8) <= iVar3) {
    *(undefined4 *)((int)this + 0xa8) = 0;
    return;
  }
  iVar3 = *(int *)((int)this + 0xa8) - iVar3;
  *(int *)((int)this + 0xa8) = iVar3;
  if (iVar3 < 0) {
    *(undefined4 *)((int)this + 0xa8) = 0;
  }
  if (param_2 == 0) {
    FUN_00509240((int)this);
  }
  return;
}

