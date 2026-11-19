// rea decompile_all
// name: FUN_0047ec70
// address: 0x47ec70
// body: available
// range: 0x47ec70-0x47ed17 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0047ec70(void *param_1)

{
  void *this;
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  this = *(void **)((int)param_1 + 0x16f0);
  iVar2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((int)this + 0x28),(int *)0x0);
  pvVar1 = *(void **)(iVar2 + 0xfa8);
  iVar2 = FUN_0047aac0(param_1,0);
  if (iVar2 == 0) {
    FUN_004d2d10(this,pvVar1,2);
  }
  else {
    FUN_004d2d80(this,pvVar1,2);
  }
  iVar3 = FUN_0047aac0(param_1,2);
  if (iVar3 == 0) {
    FUN_004d2d10(this,pvVar1,4);
  }
  else {
    FUN_004d2d80(this,pvVar1,4);
  }
  iVar4 = FUN_0047aac0(param_1,3);
  if (iVar4 == 0) {
    FUN_004d2d10(this,pvVar1,8);
  }
  else {
    FUN_004d2d80(this,pvVar1,8);
    if (iVar3 != 0 && iVar2 != 0) {
      *(uint *)((int)param_1 + 0x28) = *(uint *)((int)param_1 + 0x28) & 0xfd;
      return;
    }
  }
  *(uint *)((int)param_1 + 0x28) = *(uint *)((int)param_1 + 0x28) | 2;
  return;
}

