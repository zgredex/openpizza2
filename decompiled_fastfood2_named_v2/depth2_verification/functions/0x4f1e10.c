// rea decompile_all
// name: Object_TryNeighborPlacement
// address: 0x4f1e10
// body: available
// range: 0x4f1e10-0x4f1f6c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


bool __thiscall Object_TryNeighborPlacement(void *this,int *param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Depth-2 proposal batch 3. */
  if (*(int *)((int)this + 0xc) == 0x10) {
    return false;
  }
  if (param_2 == -1000000) {
    FUN_00534370((void *)param_1[0x16],*param_1,&param_2,&param_3);
  }
  iVar3 = FUN_004f1d90((int)param_1);
  if (param_1[1] == -1) {
    iVar4 = FUN_004ed5a0(this,param_2 + 0xa0,param_3 + 0xd0,(int *)0x1,0);
    bVar1 = 0 < (*(int **)(iVar4 + 8))[0xd];
    if (bVar1) {
      param_1[0xe] = **(int **)(iVar4 + 8);
    }
    iVar5 = FUN_004f5b40(iVar4,(int)param_1,param_1 + 0x13,(undefined4 *)0x0);
    iVar3 = FUN_004f3e10(this,iVar4,iVar3);
    bVar2 = 0 < (*(int **)(iVar3 + 8))[0xd];
    if (bVar2) {
      param_1[0xf] = **(int **)(iVar3 + 8);
    }
    bVar2 = bVar2 || (iVar5 != 0 || bVar1);
    iVar3 = FUN_004f5b40(iVar3,(int)param_1,param_1 + 0x13,(undefined4 *)0x0);
    if (iVar3 != 0) {
      return true;
    }
  }
  else {
    iVar4 = FUN_004ed5a0(this,*(int *)((int)this + 0xf8) + param_2,
                         *(int *)((int)this + 0xfc) + param_3,(int *)0x1,0);
    bVar2 = 0 < (*(int **)(iVar4 + 8))[0xc];
    if (bVar2) {
      param_1[0xe] = **(int **)(iVar4 + 8);
    }
    if (iVar3 != -1) {
      iVar3 = FUN_004f3e10(this,iVar4,iVar3);
      if (0 < (*(int **)(iVar3 + 8))[0xc]) {
        bVar2 = true;
        param_1[0xf] = **(int **)(iVar3 + 8);
      }
    }
  }
  return bVar2;
}

