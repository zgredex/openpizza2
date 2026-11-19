// rea decompile_all
// name: Resource_Read
// address: 0x402750
// body: available
// range: 0x402750-0x402832 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __thiscall Resource_Read(void *this,char *param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  
                    /* Reads bytes from an opened resource/file object. */
  iVar1 = (int)this + 0x1688;
  CS_Enter(iVar1);
  iVar2 = *(int *)(param_3 + 0x10);
  if (*(uint *)(param_3 + 8) <= iVar2 + param_2) {
    param_2 = *(uint *)(param_3 + 8) - iVar2;
  }
  if ((int)param_2 < 0) {
    CS_Leave(iVar1);
    return 0;
  }
  if (*(int *)(param_3 + 0x1c) == 2) {
    pcVar4 = (char *)(*(int *)(param_3 + 0x20) + *(int *)(param_3 + 0xc) + iVar2);
    for (uVar3 = param_2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)param_1 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      param_1 = param_1 + 4;
    }
    for (uVar3 = param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *param_1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      param_1 = param_1 + 1;
    }
  }
  else {
    if ((*(int **)((int)this + 0x1ac0) != *(int **)(param_3 + 0x18)) ||
       (*(int *)((int)this + 0x1abc) != *(int *)(param_3 + 0xc) + iVar2)) {
      FUN_0054ede0(*(int **)(param_3 + 0x18),*(int *)(param_3 + 0xc) + iVar2,0);
    }
    param_2 = FUN_0054e978(param_1,1,param_2,*(int **)(param_3 + 0x18));
    *(uint *)((int)this + 0x1abc) = *(int *)(param_3 + 0xc) + *(int *)(param_3 + 0x10) + param_2;
    *(undefined4 *)((int)this + 0x1ac0) = *(undefined4 *)(param_3 + 0x18);
  }
  *(uint *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + param_2;
  CS_Leave(iVar1);
  return param_2;
}

