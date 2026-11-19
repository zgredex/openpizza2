// rea decompile_all
// name: Map_BuildElementAnimationList
// address: 0x4eef40
// body: available
// range: 0x4eef40-0x4ef0b4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Map_BuildElementAnimationList(void *this,int param_1,int param_2)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  
                    /* Builds animation records for one named map element group. */
  iVar3 = param_1;
  iVar4 = FUN_004eac00(*(void **)((int)this + 4),param_1);
  iVar8 = 0;
  *(int *)(param_2 + 4) = iVar4;
  if (iVar4 < 1) {
    *(undefined4 *)(param_2 + 8) = 0;
  }
  else {
    pvVar5 = operator_new(iVar4 * 0xc);
    *(void **)(param_2 + 8) = pvVar5;
    param_1 = 0;
    if (0 < *(int *)(param_2 + 4)) {
      do {
        uVar6 = FUN_004eac30(*(void **)((int)this + 4),iVar3,param_1);
        *(undefined4 *)(iVar8 + 8 + *(int *)(param_2 + 8)) = uVar6;
        *(undefined4 *)(iVar8 + 4 + *(int *)(param_2 + 8)) = 0;
        pcVar2 = *(char **)(iVar8 + 8 + *(int *)(param_2 + 8));
        if ((((byte)pcVar2[3] <= *(byte *)(*(int *)((int)this + 4) + 0x2bf48)) &&
            (*pcVar2 == '\x01')) && (pcVar2[1] == '\x01')) {
          *(undefined4 *)(iVar8 + *(int *)(param_2 + 8) + 4) = 1;
        }
        uVar6 = FUN_004eac30(*(void **)((int)this + 4),iVar3,param_1);
        *(undefined4 *)(iVar8 + 8 + *(int *)(param_2 + 8)) = uVar6;
        iVar4 = FUN_005338c0(*(void **)(*(int *)(iVar8 + 8 + *(int *)(param_2 + 8)) + 0x48),-1);
        *(int *)(iVar8 + *(int *)(param_2 + 8)) = iVar4;
        piVar1 = (int *)(iVar8 + *(int *)(param_2 + 8));
        if (*(int *)(iVar8 + 4 + *(int *)(param_2 + 8)) != 0) {
          Record_SelectVariant(*(void **)(piVar1[2] + 0x48),*piVar1,-1);
          if ((0x64b < iVar3) && (iVar3 < 0x66e)) {
            piVar1 = (int *)(iVar8 + *(int *)(param_2 + 8));
            iVar4 = _rand();
            FUN_00534990(*(void **)(piVar1[2] + 0x48),*piVar1,iVar4 % 0xc);
          }
          if (iVar3 == 0x6a2) {
            piVar1 = (int *)(iVar8 + *(int *)(param_2 + 8));
            uVar7 = _rand();
            FUN_00534990(*(void **)(piVar1[2] + 0x48),*piVar1,uVar7 & 0x1f);
          }
        }
        param_1 = param_1 + 1;
        iVar8 = iVar8 + 0xc;
      } while (param_1 < *(int *)(param_2 + 4));
      return;
    }
  }
  return;
}

