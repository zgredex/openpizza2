// rea decompile_all
// name: FUN_00402840
// address: 0x402840
// body: available
// range: 0x402840-0x402983 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_00402840(void *this,undefined1 *param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = (int)this + 0x1688;
  FUN_00401320(iVar1);
  iVar5 = param_2 + -1;
  if (iVar5 < 1) {
    FUN_00401340(iVar1);
    *param_1 = 0;
    return 0;
  }
  uVar3 = *(uint *)(param_3 + 0x10);
  if (*(uint *)(param_3 + 8) <= uVar3) {
    FUN_00401340(iVar1);
    return -1;
  }
  if (*(int *)(param_3 + 0x1c) == 2) {
    iVar6 = 0;
    pcVar4 = (char *)(*(int *)(param_3 + 0x20) + *(int *)(param_3 + 0xc) + uVar3);
    if (0 < iVar5) {
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 1;
        if (cVar2 != '\n') {
          if (cVar2 == '\r') break;
          param_1[iVar6] = cVar2;
          iVar6 = iVar6 + 1;
        }
      } while (iVar6 < iVar5);
    }
    param_1[iVar6] = 0;
    FUN_00401340(iVar1);
    return iVar6;
  }
  if ((*(int **)((int)this + 0x1ac0) != *(int **)(param_3 + 0x18)) ||
     (*(int *)((int)this + 0x1abc) != *(int *)(param_3 + 0xc) + uVar3)) {
    FUN_0054ede0(*(int **)(param_3 + 0x18),*(int *)(param_3 + 0xc) + uVar3,0);
  }
  iVar6 = 0;
  if (0 < iVar5) {
    do {
      if (*(uint *)(param_3 + 8) <= *(uint *)(param_3 + 0x10)) break;
      uVar3 = CRT_Fgetc(*(undefined4 **)(param_3 + 0x18));
      *(int *)((int)this + 0x1abc) = *(int *)((int)this + 0x1abc) + 1;
      *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 1;
      if (uVar3 == 0xd) break;
      if (uVar3 != 10) {
        param_1[iVar6] = (char)uVar3;
        iVar6 = iVar6 + 1;
      }
    } while (iVar6 < iVar5);
  }
  param_1[iVar6] = 0;
  *(undefined4 *)((int)this + 0x1ac0) = *(undefined4 *)(param_3 + 0x18);
  FUN_00401340(iVar1);
  return iVar6;
}

