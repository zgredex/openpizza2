// rea decompile_all
// name: FUN_004f2020
// address: 0x4f2020
// body: available
// range: 0x4f2020-0x4f21d2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004f2020(void *this,int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  Object_UpdateState(this,(int)param_1);
  if (*(int *)((int)this + 0xc) != 0x10) {
    if (param_2 == -1000000) {
      FUN_00534370((void *)param_1[0x16],*param_1,&param_2,&param_3);
    }
    iVar3 = param_1[0xc];
    if (param_1[1] == -1) {
      if (iVar3 != -1) {
        iVar3 = *(int *)(*(int *)((int)this + 0x4c) + iVar3 * 0xc + 8);
        iVar1 = *(int *)(iVar3 + 0x30);
        if (0 < iVar1) {
          *(int *)(iVar3 + 0x30) = iVar1 + -1;
        }
      }
      if (param_1[0xd] != -1) {
        iVar3 = *(int *)(*(int *)((int)this + 0x4c) + param_1[0xd] * 0xc + 8);
        iVar1 = *(int *)(iVar3 + 0x30);
        if (0 < iVar1) {
          *(int *)(iVar3 + 0x30) = iVar1 + -1;
        }
      }
      iVar3 = FUN_004ed5a0(this,param_2 + 0xa0,param_3 + 0xd0,(int *)0x1,0);
      Object_ClearSlotRefs(this,(int)param_1);
      Object_EnsureFirstChild(iVar3,param_1,param_1 + 0x11);
      piVar2 = *(int **)(iVar3 + 8);
      if ((piVar2[0xd] == 0) && (-1 < piVar2[0xc])) {
        param_1[0xc] = *piVar2;
        piVar2 = (int *)(*(int *)(iVar3 + 8) + 0x30);
        *piVar2 = *piVar2 + 1;
      }
      uVar4 = Enum_MapDirection((int)param_1);
      iVar3 = FUN_004f3e10(this,iVar3,uVar4);
      Object_EnsureFirstChild(iVar3,param_1,param_1 + 0x12);
      piVar2 = *(int **)(iVar3 + 8);
      if ((piVar2[0xd] == 0) && (-1 < piVar2[0xc])) {
        param_1[0xd] = *piVar2;
        *(int *)(*(int *)(iVar3 + 8) + 0x30) = *(int *)(*(int *)(iVar3 + 8) + 0x30) + 1;
        return;
      }
    }
    else {
      if (iVar3 != -1) {
        piVar2 = (int *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + iVar3 * 0xc) + 0x34);
        *piVar2 = *piVar2 + -1;
      }
      if (param_1[0xd] != -1) {
        piVar2 = (int *)(*(int *)(*(int *)((int)this + 0x4c) + 8 + param_1[0xd] * 0xc) + 0x34);
        *piVar2 = *piVar2 + -1;
      }
      iVar3 = FUN_004ed5a0(this,*(int *)((int)this + 0xf8) + param_2,
                           *(int *)((int)this + 0xfc) + param_3,(int *)0x1,0);
      if ((*(int **)(iVar3 + 8))[0xc] == 0) {
        param_1[0xc] = **(int **)(iVar3 + 8);
        piVar2 = (int *)(*(int *)(iVar3 + 8) + 0x34);
        *piVar2 = *piVar2 + 1;
      }
      uVar4 = Enum_MapDirection((int)param_1);
      iVar3 = FUN_004f3e10(this,iVar3,uVar4);
      if ((*(int **)(iVar3 + 8))[0xc] == 0) {
        param_1[0xd] = **(int **)(iVar3 + 8);
        piVar2 = (int *)(*(int *)(iVar3 + 8) + 0x34);
        *piVar2 = *piVar2 + 1;
      }
    }
  }
  return;
}

