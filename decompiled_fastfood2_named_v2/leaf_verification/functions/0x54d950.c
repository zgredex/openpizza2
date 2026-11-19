// rea decompile_all
// name: FUN_0054d950
// address: 0x54d950
// body: available
// range: 0x54d950-0x54dac5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int * __thiscall FUN_0054d950(void *this,LPCSTR param_1,uint param_2,uint param_3)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (*(int *)((int)this + 0x4c) != -1) {
    return (int *)0x0;
  }
  uVar4 = (-(uint)((param_2 & 0x80) != 0) & 0x4000) + 0x4000;
  if ((param_2 & 0x20) == 0) {
    uVar4 = uVar4 | 0x100;
  }
  uVar5 = 0x40;
  if ((param_2 & 0x40) != 0) {
    uVar4 = uVar4 | 0x400;
  }
  if ((param_2 & 8) != 0) {
    param_2 = param_2 | 2;
    uVar4 = uVar4 | 8;
  }
  if ((param_2 & 0x10) != 0) {
    param_2 = param_2 | 2;
    uVar4 = uVar4 | 0x200;
  }
  if ((param_2 & 2) == 0) {
    if ((param_2 & 1) == 0) {
      return (int *)0x0;
    }
  }
  else {
    if ((param_2 & 1) == 0) {
      uVar4 = uVar4 | 1;
    }
    else {
      uVar4 = uVar4 | 2;
    }
    if ((param_2 & 0x4d) == 0) {
      param_2 = param_2 | 0x10;
      uVar4 = uVar4 | 0x200;
    }
  }
  uVar3 = param_3 & 0xe00;
  if (uVar3 != 0) {
    if (uVar3 == 0x800) {
      uVar5 = 0x10;
    }
    else if (uVar3 == 0xa00) {
      uVar5 = 0x20;
    }
    else if (uVar3 == 0xc00) {
      uVar5 = 0x30;
    }
    else if (uVar3 == 0xe00) {
      uVar5 = 0x40;
    }
  }
  uVar4 = FUN_0055099b(param_1,uVar4,uVar5,0x180);
  *(uint *)((int)this + 0x4c) = uVar4;
  if (uVar4 != 0xffffffff) {
    if (*(int *)((int)this + 0x30) < 0) {
      CS_EnterRaw((LPCRITICAL_SECTION)((int)this + 0x34));
    }
    *(undefined4 *)((int)this + 0x50) = 1;
    if ((*(int *)((int)this + 8) == 0) && (*(int *)((int)this + 0x14) == 0)) {
      pvVar1 = operator_new(0x200);
      if (pvVar1 == (void *)0x0) {
        *(undefined4 *)((int)this + 8) = 1;
      }
      else {
        FUN_0054dcd4(this,pvVar1,(int)pvVar1 + 0x200,1);
      }
    }
    if (((param_2 & 4) == 0) ||
       (iVar2 = (**(code **)(*(int *)this + 0xc))(0,2,param_2), iVar2 != -1)) {
      if (*(int *)((int)this + 0x30) < 0) {
        CS_LeaveRaw((LPCRITICAL_SECTION)((int)this + 0x34));
      }
      return this;
    }
    FUN_0054ce1e(this);
    if (*(int *)((int)this + 0x30) < 0) {
      CS_LeaveRaw((LPCRITICAL_SECTION)((int)this + 0x34));
    }
  }
  return (int *)0x0;
}

