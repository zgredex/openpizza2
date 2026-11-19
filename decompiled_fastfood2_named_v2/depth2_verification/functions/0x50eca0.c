// rea decompile_all
// name: FUN_0050eca0
// address: 0x50eca0
// body: available
// range: 0x50eca0-0x50efaa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0050eca0(void *this,int *param_1)

{
  int iVar1;
  int *this_00;
  undefined4 *puVar2;
  int local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  this_00 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a3bc;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0054cbc1(param_1,(int)this + 0x84,4);
  FUN_0054cbc1(this_00,(int)this + 0x88,4);
  FUN_0054cbc1(this_00,(int)this + 8,4);
  FUN_0054cbc1(this_00,(int)this + 0xc,0x20);
  FUN_0054cbc1(this_00,(int)this + 0x2c,4);
  FUN_0054cbc1(this_00,(int)this + 0x30,4);
  FUN_0054cbc1(this_00,(int)this + 0x3c,4);
  FUN_0054cbc1(this_00,(int)this + 0x40,4);
  FUN_0054cbc1(this_00,(int)this + 0x44,4);
  FUN_0054cbc1(this_00,(int)this + 0x48,4);
  FUN_0054cbc1(this_00,(int)this + 0x4c,4);
  FUN_0054cbc1(this_00,(int)this + 0x50,4);
  FUN_0054cbc1(this_00,(int)this + 0x54,4);
  FUN_0054cbc1(this_00,(int)this + 0x58,4);
  FUN_0054cbc1(this_00,(int)this + 0x5c,4);
  FUN_0054cbc1(this_00,(int)this + 0x60,4);
  FUN_0054cbc1(this_00,(int)this + 100,4);
  FUN_0054cbc1(this_00,(int)this + 0x68,4);
  FUN_0054cbc1(this_00,(int)this + 0x6c,0x18);
  FUN_0054cbc1(this_00,(int)this + 0x34,4);
  FUN_0054cbc1(this_00,(int)this + 0x38,4);
  local_10 = operator_new(0x828);
  local_4 = 0;
  if (local_10 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FUN_004d36f0(local_10,this_00);
  }
  *(undefined4 **)((int)this + 4) = puVar2;
  local_4 = 0xffffffff;
  FUN_0054cbc1(this_00,&local_14,4);
  if ((local_14 < 0) || (10000 < local_14)) {
    iVar1 = *(int *)(*this_00 + 4);
    if (*(int *)(iVar1 + 0x34 + (int)this_00) < 0) {
      FUN_0054d35c((LPCRITICAL_SECTION)((int)this_00 + iVar1 + 0x38));
    }
    *(undefined4 *)((int)this_00 + iVar1 + 8) = 4;
    if (*(int *)((int)this_00 + iVar1 + 0x34) < 0) {
      FUN_0054d367((LPCRITICAL_SECTION)((int)this_00 + iVar1 + 0x38));
    }
    ExceptionList = local_c;
    return;
  }
  param_1 = (int *)0x0;
  if (0 < local_14) {
    do {
      local_10 = operator_new(0xc);
      local_4 = 1;
      if (local_10 == (void *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_005019d0(local_10,this_00);
      }
      local_4 = 0xffffffff;
      FUN_004014b0((void *)((int)this + 0x8c),puVar2);
      param_1 = (int *)((int)param_1 + 1);
    } while ((int)param_1 < local_14);
  }
  FUN_0054cbc1(this_00,&param_1,4);
  if (param_1 == (int *)0x0) {
    *(undefined4 *)((int)this + 0xa8) = 0;
  }
  else {
    local_10 = operator_new(0x250);
    local_4 = 2;
    if (local_10 == (void *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_00501aa0(local_10,this_00);
    }
    local_4 = 0xffffffff;
    *(undefined4 **)((int)this + 0xa8) = puVar2;
  }
  FUN_0054cbc1(this_00,&param_1,4);
  if (param_1 == (int *)0x0) {
    *(undefined4 *)((int)this + 0xac) = 0;
    ExceptionList = local_c;
    return;
  }
  local_10 = operator_new(0xd8);
  local_4 = 3;
  if (local_10 == (void *)0x0) {
    *(undefined4 *)((int)this + 0xac) = 0;
    ExceptionList = local_c;
    return;
  }
  puVar2 = FUN_004f5df0(local_10,this_00);
  *(undefined4 **)((int)this + 0xac) = puVar2;
  ExceptionList = local_c;
  return;
}

