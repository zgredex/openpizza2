// rea decompile_all
// name: FUN_0047d340
// address: 0x47d340
// body: available
// range: 0x47d340-0x47d49e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_0047d340(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *this_00;
  int iVar3;
  int iVar4;
  longlong lVar5;
  int local_c;
  
  iVar3 = 0;
  iVar4 = 0;
  local_c = 0;
  if (0 < *(int *)((int)this + 0x1514)) {
    do {
      piVar2 = (int *)FUN_004017f0((void *)((int)this + 0x1500),iVar4,(int *)0x0);
      iVar1 = *piVar2;
      if ((*(char *)(iVar1 + 0x824) == '\0') && (iVar1 != param_1)) {
        FUN_004d3910(iVar1);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)((int)this + 0x1514));
  }
  this_00 = Branch_CollectOrdersByCategory(this,5);
  if (0 < (int)this_00[5]) {
    do {
      iVar4 = FUN_004017f0(this_00,iVar3,(int *)0x0);
      if (iVar4 != 0) {
        iVar4 = FUN_004017f0((void *)(DAT_0057c670 + 0x74),*(int *)(iVar4 + 4),(int *)0x0);
        FUN_0047acf0(iVar4);
        local_c = local_c + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)this_00[5]);
  }
  if (this_00 != (undefined4 *)0x0) {
    (**(code **)*this_00)(1);
  }
  if (local_c < 1) {
    return 0xb4;
  }
  FUN_004d4000(param_1);
  lVar5 = __ftol();
  return (int)lVar5;
}

