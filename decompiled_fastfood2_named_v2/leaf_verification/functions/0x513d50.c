// rea decompile_all
// name: FUN_00513d50
// address: 0x513d50
// body: available
// range: 0x513d50-0x513e4f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00513d50(void *this,void *param_1)

{
  void *this_00;
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  void *local_4;
  
  this_00 = param_1;
  local_4 = this;
  FUN_0054cbc1(param_1,(int)this + 4,0x1e);
  FUN_0054cbc1(this_00,(int)this + 0x24,4);
  FUN_0054cbc1(this_00,(int *)((int)this + 0x28),4);
  FUN_0054cbc1(this_00,(int)this + 0x2c,4);
  FUN_0054cbc1(this_00,(int)this + 0x38,4);
  FUN_0054cbc1(this_00,(int)this + 0x3c,1);
  FUN_0054cbc1(this_00,(int)this + 0x40,4);
  FUN_0054cbc1(this_00,(int)this + 0x30,4);
  FUN_0054cbc1(this_00,&local_4,4);
  iVar1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((int)this + 0x28),(int *)0x0);
  uVar2 = IDMap_Lookup((void *)(iVar1 + 0xfac),(int)local_4,(int *)0x0);
  *(undefined4 *)((int)this + 0x34) = uVar2;
  FUN_0054cbc1(this_00,&param_1,4);
  iVar1 = 0;
  if (0 < (int)param_1) {
    do {
      pvVar3 = operator_new(0x20);
      FUN_0054cbc1(this_00,pvVar3,0x20);
      FUN_004014b0((void *)((int)this + 0x44),pvVar3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)param_1);
  }
  FUN_0054cbc1(this_00,(int)this + 0x60,0xf0);
  return;
}

