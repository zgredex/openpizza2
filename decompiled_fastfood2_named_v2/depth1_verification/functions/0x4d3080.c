// rea decompile_all
// name: FUN_004d3080
// address: 0x4d3080
// body: available
// range: 0x4d3080-0x4d31af inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


bool __fastcall FUN_004d3080(int param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  void *this_00;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_4;
  
  iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  this = *(void **)(iVar2 + 0xfa8);
  if (this == (void *)0x0) {
    return false;
  }
  iVar2 = *(int *)(param_1 + 0x24);
  iVar1 = *(int *)((int)this + 0x4c);
  this_00 = (void *)FUN_004eab50(DAT_0057c5cc,*(int *)(param_1 + 0x20));
  if (this_00 == (void *)0x0) {
    return false;
  }
  UI_AlignSpriteToRect(this,(int *)(iVar1 + iVar2 * 0xc),this_00,&local_38,&local_34);
  FUN_0053d100(this_00,&local_30,&local_2c);
  FUN_0053d090(this_00,&local_28,&local_24);
  local_38 = local_38 + *(int *)((int)this + 0x24);
  local_34 = local_34 + *(int *)((int)this + 0x28);
  iVar2 = local_30 + local_38;
  iVar1 = local_2c + local_34;
  local_4 = iVar1 + local_24;
  FUN_004f5c20(this,&local_20);
  if (iVar2 < local_20 + -0x23) {
    return false;
  }
  if (local_18 + 0x23 < iVar2 + local_28) {
    return false;
  }
  if (iVar1 < local_1c + -0x23) {
    return false;
  }
  return local_4 <= local_14 + 0x23;
}

