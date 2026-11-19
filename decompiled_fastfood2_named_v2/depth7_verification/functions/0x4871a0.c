// rea decompile_all
// name: FUN_004871a0
// address: 0x4871a0
// body: available
// range: 0x4871a0-0x4872a4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004871a0(void *this,undefined4 *param_1)

{
  void *this_00;
  void *this_01;
  void *this_02;
  int iVar1;
  int iVar2;
  
  this_01 = (void *)FUN_00488be0(this,param_1[9]);
  this_02 = (void *)FUN_004017f0((void *)((int)this + 4),param_1[10],(int *)0x0);
  iVar1 = FUN_00513fd0((int)param_1);
  this_00 = (void *)param_1[0xd];
  iVar2 = *(int *)((int)this_00 + 0x48);
  if ((-1 < iVar2) && (iVar2 < 4)) {
    iVar2 = *(int *)(&DAT_00568188 + iVar2 * 4);
  }
  FUN_00486be0(this,1);
  Storage_SettlePendingOrders((int)param_1);
  FUN_004ddca0(this_01,(int)param_1);
  FUN_00401320(*(int *)((int)this + 0x240));
  FUN_004d2420(this_00,iVar1 + 0x1d,iVar2 + 0x840 + iVar1 * 4);
  FUN_004dc720(this_02,this_00,-1);
  *(undefined4 *)((int)this_00 + 0x2c) = 0xffffffff;
  *(undefined4 *)((int)this_00 + 0x4c) = 1;
  *(undefined4 *)(*(int *)((int)this_02 + 0xfa8) + 0xf4) = 1;
  FUN_00401340(*(int *)((int)this + 0x240));
  if (((*(void **)((int)this + 0x218) == this_00) && (*(int *)((int)this + 0x290) == 1)) &&
     (*(void **)((int)this + 0x25c) != (void *)0x0)) {
    FUN_005301c0(*(void **)((int)this + 0x25c),-0x18629,0x23,0);
  }
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(1);
  }
  FUN_00486e00((int)this);
  return;
}

