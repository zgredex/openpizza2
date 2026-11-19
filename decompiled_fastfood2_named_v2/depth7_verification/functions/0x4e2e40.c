// rea decompile_all
// name: FUN_004e2e40
// address: 0x4e2e40
// body: available
// range: 0x4e2e40-0x4e2f26 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __thiscall FUN_004e2e40(void *this,int param_1)

{
  int iVar1;
  uint in_EAX;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != 0) {
    iVar4 = 0;
    if (0 < *(int *)((int)this + 0x1cc)) {
      do {
        piVar2 = (int *)FUN_004017f0((void *)((int)this + 0x1b8),iVar4,(int *)0x0);
        iVar3 = FUN_004017f0((void *)(DAT_0057c670 + 0x3c),*piVar2,(int *)0x0);
        if (*(int *)(iVar3 + 0xa4) != -1) {
          if (*(int *)(iVar3 + 0x74) == 0) {
            iVar1 = *(int *)(iVar3 + 0xfc);
          }
          else {
            iVar1 = *(int *)(iVar3 + 0xf4);
          }
          if (iVar1 == param_1) goto LAB_004e2f1d;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)((int)this + 0x1cc));
    }
    iVar4 = 0;
    in_EAX = DAT_0057c670;
    if (0 < *(int *)(DAT_0057c670 + 0x50)) {
      do {
        iVar3 = FUN_004017f0((void *)(DAT_0057c670 + 0x3c),iVar4,(int *)0x0);
        if (((*(int *)(iVar3 + 0xa4) != -1) &&
            (*(int *)(iVar3 + 0x110) == *(int *)((int)this + 0x48))) &&
           (*(int *)(iVar3 + 0x30) == 0x16)) {
          if (*(int *)(iVar3 + 0x74) == 0) {
            iVar1 = *(int *)(iVar3 + 0xfc);
          }
          else {
            iVar1 = *(int *)(iVar3 + 0xf4);
          }
          if (iVar1 == param_1) {
LAB_004e2f1d:
            return CONCAT31((int3)((uint)iVar3 >> 8),1);
          }
        }
        iVar4 = iVar4 + 1;
        in_EAX = DAT_0057c670;
      } while (iVar4 < *(int *)(DAT_0057c670 + 0x50));
    }
  }
  return in_EAX & 0xffffff00;
}

