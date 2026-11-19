// rea decompile_all
// name: FUN_004f89d0
// address: 0x4f89d0
// body: available
// range: 0x4f89d0-0x4f8a7b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_004f89d0(int param_1,void *param_2)

{
  undefined4 *this;
  int iVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar2 = 0;
  this = FUN_004d59c0(param_2,0x1d,0,'\0');
  iVar3 = 0;
  local_10 = 0;
  local_8 = this[5];
  if (0 < local_8) {
    do {
      iVar1 = FUN_004017f0(this,iVar2,(int *)0x0);
      if ((iVar1 != 0) &&
         (FUN_004d5dd0(param_2,iVar1,3,&local_14,&local_4,param_1,&local_c), local_14 != 0)) {
        if (local_c != 0) {
          local_14 = local_14 >> 1;
        }
        if ((iVar3 == 0) || (local_14 < iVar3)) {
          iVar3 = local_14;
          local_10 = iVar1;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < local_8);
  }
  if (this != (undefined4 *)0x0) {
    (**(code **)*this)(1);
  }
  if (iVar3 == 0) {
    return 0;
  }
  return local_10;
}

