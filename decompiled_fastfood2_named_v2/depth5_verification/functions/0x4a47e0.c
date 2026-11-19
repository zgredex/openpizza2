// rea decompile_all
// name: FUN_004a47e0
// address: 0x4a47e0
// body: available
// range: 0x4a47e0-0x4a48a9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a47e0(void *param_1,int param_2)

{
  void *this;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_4;
  
  this = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_4 = *(int *)((int)this + 0x15c);
  if (local_4 < 9) {
    param_2 = 0;
  }
  else {
    local_4 = 8;
  }
  iVar2 = 0;
  if (0 < local_4) {
    do {
      iVar1 = FUN_004017f0((void *)((int)this + 0x148),iVar2 + param_2,(int *)0x0);
      FUN_0052f9b0(param_1,(&DAT_00568f90)[iVar2],iVar1 + 4);
      iVar1 = FUN_004e2750(this,iVar1,0x17);
      if (iVar1 == 0) {
        iVar3 = (&DAT_00568fb0)[iVar2];
        uVar4 = 0xff;
      }
      else {
        iVar3 = (&DAT_00568fb0)[iVar2];
        uVar4 = 0;
      }
      FUN_0052f910(param_1,iVar3,uVar4);
      FUN_0052f080(param_1,(&DAT_00568fb0)[iVar2],&DAT_005686f4,iVar1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < local_4);
  }
  return;
}

