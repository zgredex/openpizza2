// rea decompile_all
// name: FUN_0047f100
// address: 0x47f100
// body: available
// range: 0x47f100-0x47f178 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall FUN_0047f100(void *param_1)

{
  void *this;
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  this = *(void **)((int)param_1 + 0x16f0);
  iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)((int)this + 0x28),(int *)0x0);
  pvVar1 = *(void **)(iVar2 + 0xfa8);
  iVar2 = FUN_0047d010(param_1);
  iVar3 = FUN_0047cc10(param_1,5);
  if ((iVar2 < 4) || (iVar3 < 1)) {
    Map_SetObjectFlags(this,pvVar1,0x10);
    *(uint *)((int)param_1 + 0x28) = *(uint *)((int)param_1 + 0x28) | 4;
    return 1;
  }
  Map_ClearObjectFlags(this,pvVar1,0x10);
  *(uint *)((int)param_1 + 0x28) = *(uint *)((int)param_1 + 0x28) & 0xfb;
  return 0;
}

