// rea decompile_all
// name: FUN_0052fdd0
// address: 0x52fdd0
// body: available
// range: 0x52fdd0-0x52fee6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
FUN_0052fdd0(void *this,int param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  DWORD DVar1;
  DWORD DVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  bool bVar8;
  
  DVar1 = *(DWORD *)(*(int *)((int)this + 0x134) + 0x830c);
  DVar2 = GetCurrentThreadId();
  bVar8 = DVar2 != DVar1;
  if (bVar8) {
    FUN_00401320(*(int *)(*(int *)((int)this + 0x134) + 0x1c8));
  }
  piVar3 = (int *)Array_GetRecordByKey(this,param_1);
  if (piVar3 == (int *)0x0) {
    if (bVar8) {
      FUN_00401340(*(int *)(*(int *)((int)this + 0x134) + 0x1c8));
    }
    FUN_00526f20(*(undefined4 *)((int)this + 0x134),0,
                 (byte *)s_Window__GadgetNotify__Gadget___d_0057447c,param_1);
    return 0;
  }
  if ((param_2 == 0) || (param_2 == piVar3[0x10])) {
    uVar5 = (**(code **)(*piVar3 + 0xc))(param_3,param_4,param_5);
    if (bVar8) {
      FUN_00401340(*(int *)(*(int *)((int)this + 0x134) + 0x1c8));
    }
    return uVar5;
  }
  iVar7 = 0;
  if (bVar8) {
    FUN_00401340(*(int *)(*(int *)((int)this + 0x134) + 0x1c8));
  }
  if (DAT_005743a0 != param_2) {
    puVar6 = &DAT_005743a0;
    iVar4 = DAT_005743a0;
    do {
      if (iVar4 == 0) break;
      iVar4 = puVar6[2];
      puVar6 = puVar6 + 2;
      iVar7 = iVar7 + 1;
    } while (iVar4 != param_2);
  }
  FUN_00526f20(*(undefined4 *)((int)this + 0x134),2,
               (byte *)s_Window__GadgetNotify__Gadget_is_n_00574450,
               (&PTR_s_button_005743a4)[iVar7 * 2]);
  return 0;
}

