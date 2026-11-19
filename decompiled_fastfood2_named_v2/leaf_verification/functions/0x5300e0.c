// rea decompile_all
// name: FUN_005300e0
// address: 0x5300e0
// body: available
// range: 0x5300e0-0x5301be inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __thiscall FUN_005300e0(void *this,int *param_1,undefined4 *param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  
  *param_2 = 1;
  iVar1 = *(int *)((int)this + 0xf0);
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    pvVar2 = *(void **)(*(int *)((int)this + 0xec) + iVar1 * 8);
    if ((pvVar2 != (void *)0x0) &&
       (iVar6 = UI_IsValidSize(pvVar2,*param_1 - *(int *)((int)this + 0x18),
                               param_1[1] - *(int *)((int)this + 0x1c)), iVar6 != 0)) {
      return pvVar2;
    }
  }
  pvVar2 = *(void **)((int)this + 0x50);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = *(void **)((int)this + 0x94);
    if (pvVar2 != (void *)0x0) {
      iVar1 = param_1[1];
      iVar6 = *(int *)((int)this + 0x1c);
      iVar3 = *param_1;
      iVar4 = *(int *)((int)this + 0x18);
      if (*(char *)((int)pvVar2 + 0x39) == '\0') {
        FUN_0053cea0(pvVar2);
      }
      bVar5 = Sprite_BlitClipped(pvVar2,*(ushort **)((int)pvVar2 + 0x2c),iVar3 - iVar4,iVar1 - iVar6
                                 ,(uint *)0x0);
      if (CONCAT31(extraout_var_00,bVar5) == 0) {
        *param_2 = 0;
      }
    }
  }
  else {
    iVar1 = param_1[1];
    iVar6 = *(int *)((int)this + 0x1c);
    iVar3 = *param_1;
    iVar4 = *(int *)((int)this + 0x18);
    if (*(char *)((int)pvVar2 + 0x39) == '\0') {
      FUN_0053cea0(pvVar2);
    }
    bVar5 = Sprite_BlitClipped(pvVar2,*(ushort **)((int)pvVar2 + 0x2c),iVar3 - iVar4,iVar1 - iVar6,
                               (uint *)0x0);
    if (CONCAT31(extraout_var,bVar5) == 0) {
      *param_2 = 0;
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}

