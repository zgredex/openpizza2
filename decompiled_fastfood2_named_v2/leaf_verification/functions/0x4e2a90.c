// rea decompile_all
// name: FUN_004e2a90
// address: 0x4e2a90
// body: available
// range: 0x4e2a90-0x4e2b31 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004e2a90(void *this,int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int local_2b0 [172];
  
  iVar1 = 0;
  piVar4 = local_2b0 + 1;
  do {
    piVar4[-1] = iVar1;
    *piVar4 = 0;
    iVar1 = iVar1 + 1;
    piVar4 = piVar4 + 2;
  } while (iVar1 < 0x56);
  iVar1 = 0;
  if (0 < *(int *)((int)this + 0x124)) {
    do {
      iVar2 = IDMap_Lookup((void *)((int)this + 0x110),iVar1,(int *)0x0);
      piVar4 = local_2b0 + 3;
      piVar3 = (int *)(iVar2 + 0x68);
      iVar2 = 0x55;
      do {
        if (0 < *piVar3) {
          *piVar4 = *piVar4 + 1;
        }
        piVar3 = piVar3 + 1;
        piVar4 = piVar4 + 2;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)((int)this + 0x124));
  }
  FUN_0054ea8f(local_2b0,(undefined4 *)0x56,8,&LAB_004e2b40);
  *param_1 = local_2b0[0];
  *param_2 = local_2b0[2];
  return;
}

