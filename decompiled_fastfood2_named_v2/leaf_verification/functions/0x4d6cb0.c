// rea decompile_all
// name: FUN_004d6cb0
// address: 0x4d6cb0
// body: available
// range: 0x4d6cb0-0x4d708f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004d6cb0(void *this,int *param_1)

{
  uint uVar1;
  int *this_00;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  this_00 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005590a6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0054cbc1(param_1,&param_1,4);
  uVar2 = FUN_004eacd0(DAT_0057c5cc,(int)param_1);
  *(undefined4 *)((int)this + 0xfa8) = uVar2;
  FUN_0054cbc1(this_00,(int)this + 0xc1c,4);
  uVar1 = (int)this + 4;
  FUN_0054cbc1(this_00,uVar1,0x20);
  FUN_0054cbc1(this_00,(int)this + 0x44,4);
  FUN_0054cbc1(this_00,(int)this + 0xc20,0x18);
  FUN_0054cbc1(this_00,&local_1c,4);
  if (local_1c != 0xc18) {
    puVar3 = (undefined4 *)(-(uint)(this != (void *)0x0) & uVar1);
    for (iVar4 = 0x306; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
  }
  FUN_0054cbc1(this_00,-(uint)(this != (void *)0x0) & uVar1,local_1c);
  FUN_0054cbc1(this_00,(int)this + 0xdac,0x18);
  FUN_0054cbc1(this_00,(int)this + 0xdc4,4);
  FUN_0054cbc1(this_00,(int)this + 0xdc8,0x1e0);
  FUN_0054cbc1(this_00,(int)this + 0xc38,0x60);
  FUN_0054cbc1(this_00,(int)this + 0xc98,0x18);
  FUN_0054cbc1(this_00,(int)this + 0xcc8,0x18);
  FUN_0054cbc1(this_00,(int)this + 0xd40,0x18);
  FUN_0054cbc1(this_00,(int)this + 0xd58,0x30);
  FUN_0054cbc1(this_00,(int)this + 0xd88,0x24);
  FUN_0054cbc1(this_00,(int)this + 0xce0,0x60);
  FUN_0054cbc1(this_00,(int)this + 0xcb0,0x18);
  FUN_0054cbc1(this_00,(int)this + 0xfe4,0xc0);
  FUN_0054cbc1(this_00,(int)this + 0x10ac,4);
  FUN_0054cbc1(this_00,(int)this + 0x10b0,4);
  FUN_0054cbc1(this_00,(int)this + 0x10b4,4);
  FUN_0054cbc1(this_00,(int)this + 0x10b8,4);
  FUN_0054cbc1(this_00,(int)this + 0x10c4,4);
  FUN_0054cbc1(this_00,(int)this + 0x10d0,0x78);
  FUN_0054cbc1(this_00,(int)this + 0x10c0,4);
  FUN_0054cbc1(this_00,(int)this + 0x10bc,4);
  FUN_0054cbc1(this_00,(int)this + 0x10cc,4);
  FUN_0054cbc1(this_00,(int)this + 0x10c8,4);
  FUN_0054cbc1(this_00,(int)this + 0x1148,4);
  FUN_0054cbc1(this_00,(int)this + 0x114c,4);
  FUN_0054cbc1(this_00,(int)this + 0x1150,4);
  FUN_0054cbc1(this_00,(int)this + 0x1154,4);
  FUN_0054cbc1(this_00,&param_1,4);
  iVar4 = 0;
  if (0 < (int)param_1) {
    do {
      local_10 = operator_new(0x9c);
      local_4 = 0;
      if (local_10 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = FUN_004d1cb0(local_10,this_00);
      }
      local_4 = 0xffffffff;
      FUN_004014b0((void *)((int)this + 0xfac),puVar3);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)param_1);
  }
  FUN_0054cbc1(this_00,&local_20,4);
  if ((local_20 < 0) || (10000 < local_20)) {
    iVar4 = *(int *)(*this_00 + 4);
    if (*(int *)((int)this_00 + iVar4 + 0x34) < 0) {
      CS_EnterRaw((LPCRITICAL_SECTION)((int)this_00 + iVar4 + 0x38));
    }
    *(undefined4 *)((int)this_00 + iVar4 + 8) = 4;
    if (*(int *)((int)this_00 + iVar4 + 0x34) < 0) {
      CS_LeaveRaw((LPCRITICAL_SECTION)((int)this_00 + iVar4 + 0x38));
    }
  }
  else {
    param_1 = (int *)0x0;
    if (0 < local_20) {
      do {
        FUN_0054cbc1(this_00,&local_14,4);
        FUN_0054cbc1(this_00,&local_18,4);
        puVar3 = operator_new(8);
        local_4 = 1;
        local_10 = puVar3;
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          uVar2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),local_18,(int *)0x0);
          *puVar3 = uVar2;
          puVar3[1] = local_14;
        }
        local_4 = 0xffffffff;
        FUN_004014b0((void *)((int)this + 0xfc8),puVar3);
        param_1 = (int *)((int)param_1 + 1);
      } while ((int)param_1 < local_20);
    }
    FUN_0054cbc1(this_00,(int)this + 0x10a4,4);
    FUN_004d5940(this);
    FUN_004d4880((int)this);
  }
  ExceptionList = local_c;
  return;
}

