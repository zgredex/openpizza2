// rea decompile_all
// name: FUN_005239d0
// address: 0x5239d0
// body: available
// range: 0x5239d0-0x523ac6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
FUN_005239d0(void *this,int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a6fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00401320(*(int *)((int)this + 0x1c8));
  iVar1 = FUN_00523930(this,&local_14);
  local_10 = operator_new(0x2c8);
  local_4 = 0;
  if (local_10 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = Dialog_ConstructFixed
                       (local_10,this,*(void **)((int)this + 0xc),param_1,param_2,param_3,param_4,
                        param_5,(undefined4 *)((int)this + 0x250),param_7,param_8,param_9,param_10);
  }
  *(undefined4 **)((int)this + iVar1 * 4 + 0x14) = puVar2;
  puVar2[1] = local_14;
  local_4 = 0xffffffff;
  FUN_0054a660(DAT_0057c1e0,0xff0000,(byte *)s_CreateWindow__ID__d_Type_Fixed_P_00574114,local_14);
  FUN_00401340(*(int *)((int)this + 0x1c8));
  ExceptionList = local_c;
  return local_14;
}

