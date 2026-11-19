// rea decompile_all
// name: FUN_005108e0
// address: 0x5108e0
// body: available
// range: 0x5108e0-0x510c06 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_005108e0(void *this,int *param_1)

{
  int iVar1;
  int *this_00;
  undefined4 *puVar2;
  void *pvVar3;
  int local_18;
  int local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  this_00 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a446;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0054cbc1(param_1,(int)this + 4,0x40);
  FUN_0054cbc1(this_00,(int)this + 0x44,4);
  FUN_0054cbc1(this_00,&local_14,4);
  if ((local_14 < 0) || (10000 < local_14)) {
    iVar1 = *(int *)(*this_00 + 4);
    if (*(int *)((int)this_00 + iVar1 + 0x34) < 0) {
      FUN_0054d35c((LPCRITICAL_SECTION)((int)this_00 + iVar1 + 0x38));
    }
    *(undefined4 *)((int)this_00 + iVar1 + 8) = 4;
    if (*(int *)((int)this_00 + iVar1 + 0x34) < 0) {
      FUN_0054d367((LPCRITICAL_SECTION)((int)this_00 + iVar1 + 0x38));
    }
  }
  else {
    local_18 = 0;
    if (0 < local_14) {
      do {
        param_1 = operator_new(0x1c);
        local_4 = 0;
        if (param_1 == (int *)0x0) {
          puVar2 = (undefined4 *)0x0;
        }
        else {
          puVar2 = FUN_004d1b30(param_1,this_00);
        }
        local_4 = 0xffffffff;
        FUN_004014b0((void *)((int)this + 0x48),puVar2);
        local_18 = local_18 + 1;
      } while (local_18 < local_14);
    }
    FUN_0054cbc1(this_00,(int)this + 100,0x158);
    FUN_0054cbc1(this_00,(int)this + 0x1bc,0x1c);
    FUN_0054cbc1(this_00,(int)this + 0x1d8,4);
    FUN_0054cbc1(this_00,(int)this + 0x1dc,1);
    if (DAT_0057c668 < 0x2b) {
      FUN_0054cbc1(this_00,&param_1,1);
    }
    FUN_0054cbc1(this_00,(int)this + 0x1e0,0x60);
    FUN_0054cbc1(this_00,(int)this + 0x240,4);
    FUN_0054cbc1(this_00,(int)this + 0x244,4);
    FUN_0054cbc1(this_00,(int)this + 0x248,4);
    FUN_0054cbc1(this_00,(int)this + 0x24c,4);
    FUN_0054cbc1(this_00,(int)this + 0x250,4);
    FUN_0054cbc1(this_00,(int)this + 0x254,4);
    FUN_0054cbc1(this_00,(int)this + 600,4);
    FUN_0054cbc1(this_00,(int)this + 0x264,0x20);
    FUN_0054cbc1(this_00,(int)this + 0x284,0x20);
    FUN_0054cbc1(this_00,(int)this + 0x2a4,0x20);
    FUN_0054cbc1(this_00,(int)this + 0x2c4,0x20);
    FUN_0054cbc1(this_00,&local_18,4);
    if (local_18 == 0) {
      *(undefined4 *)((int)this + 0x304) = 0;
    }
    else {
      local_10 = operator_new(0x1c);
      local_4 = 1;
      if (local_10 == (void *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = List_Construct(local_10,0);
      }
      *(undefined4 **)((int)this + 0x304) = puVar2;
      local_4 = 0xffffffff;
      FUN_0054cbc1(this_00,&local_14,4);
      local_18 = 0;
      if (0 < local_14) {
        do {
          pvVar3 = operator_new(0x1c);
          FUN_0054cbc1(this_00,pvVar3,4);
          FUN_0054cbc1(this_00,(int)pvVar3 + 4,4);
          FUN_0054cbc1(this_00,(int)pvVar3 + 8,4);
          FUN_0054cbc1(this_00,(int)pvVar3 + 0xc,4);
          FUN_0054cbc1(this_00,(int)pvVar3 + 0x10,4);
          FUN_0054cbc1(this_00,(int)pvVar3 + 0x14,4);
          FUN_0054cbc1(this_00,(int)pvVar3 + 0x18,4);
          FUN_004014b0(*(void **)((int)this + 0x304),pvVar3);
          local_18 = local_18 + 1;
        } while (local_18 < local_14);
      }
    }
    FUN_0054cbc1(this_00,(int)this + 0x308,4);
    FUN_0054cbc1(this_00,(int)this + 0x30c,4);
  }
  ExceptionList = local_c;
  return;
}

