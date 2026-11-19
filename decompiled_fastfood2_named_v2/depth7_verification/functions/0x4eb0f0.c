// rea decompile_all
// name: FUN_004eb0f0
// address: 0x4eb0f0
// body: available
// range: 0x4eb0f0-0x4eb271 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall FUN_004eb0f0(void *this,int param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined1 local_110 [260];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00559f20;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  List_Construct((void *)((int)this + 0x11c),0);
  local_4 = 0;
  List_Construct((void *)((int)this + 0x140),0);
  local_4._0_1_ = 1;
  *(undefined ***)this = &PTR_FUN_0055c5d4;
  if (param_1 == 0) {
    FUN_0048e0a0();
  }
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x70) = 0;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x78) = 0;
  *(undefined4 *)((int)this + 0x1015c) = 1;
  *(int *)((int)this + 4) = param_1;
  FUN_0054dd83(local_110,(byte *)s__sIsokarten__s_00571a60,&DAT_0057c278);
  pvVar1 = operator_new(0x5c);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_0054cc99();
  }
  local_4 = CONCAT31(local_4._1_3_,1);
  if ((*(byte *)(*(int *)(*piVar2 + 4) + 8 + (int)piVar2) & 6) != 0) {
    FUN_0048e0a0();
  }
  FUN_004eb900(this,piVar2);
  if (piVar2 != (int *)0x0) {
    (*(code *)**(undefined4 **)(*(int *)(*piVar2 + 4) + (int)piVar2))(1);
  }
  FUN_004eae00((int)this);
  FUN_004ed0a0(this);
  FUN_004ed440(this,*(int *)((int)this + 0x24),*(int *)((int)this + 0x28));
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)((int)this + 0xe8);
  *(undefined4 *)((int)this + 0x28) = *(undefined4 *)((int)this + 0xec);
  FUN_004eae60((int)this);
  if (*(int *)((int)this + 0xc) != 0x10) {
    FUN_004f4400(this,DAT_0057c5c8,(int *)0x0);
  }
  ExceptionList = pvStack_c;
  return this;
}

