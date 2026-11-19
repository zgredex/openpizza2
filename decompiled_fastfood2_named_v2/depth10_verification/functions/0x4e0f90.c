// rea decompile_all
// name: FUN_004e0f90
// address: 0x4e0f90
// body: available
// range: 0x4e0f90-0x4e1538 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004e0f90(void *this,int *param_1)

{
  int *this_00;
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int local_18;
  int local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  this_00 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00559452;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0054cbc1(param_1,(int)this + 8,0x40);
  FUN_0054cbc1(this_00,(int)this + 0x48,4);
  FUN_0054cbc1(this_00,(int)this + 0x4c,4);
  FUN_0054cbc1(this_00,&param_1,1);
  FUN_0054cbc1(this_00,(int)this + 0x5c,2);
  FUN_0054cbc1(this_00,(int)this + 0x50,4);
  FUN_0054cbc1(this_00,(int)this + 0x54,4);
  FUN_0054cbc1(this_00,(int)this + 0x1dc,4);
  FUN_0054cbc1(this_00,(int)this + 0x108,8);
  FUN_0054cbc1(this_00,(int)this + 0x1e4,4);
  FUN_0054cbc1(this_00,(int)this + 0x1e0,4);
  FUN_0054cbc1(this_00,(int)this + 100,4);
  FUN_0054cbc1(this_00,(int)this + 0x68,4);
  FUN_0054cbc1(this_00,(int)this + 0x6c,4);
  FUN_0054cbc1(this_00,(int)this + 0x70,0x24);
  FUN_0054cbc1(this_00,(int)this + 0x94,0x18);
  FUN_0054cbc1(this_00,(int)this + 0xac,6);
  FUN_0054cbc1(this_00,(int)this + 0xcc,0x18);
  FUN_0054cbc1(this_00,(int)this + 0xb4,0x18);
  FUN_0054cbc1(this_00,(int)this + 0xf0,4);
  FUN_0054cbc1(this_00,(int)this + 0xf4,4);
  FUN_0054cbc1(this_00,(int)this + 0xf8,4);
  FUN_0054cbc1(this_00,(int)this + 0xe4,10);
  FUN_0054cbc1(this_00,(int)this + 0x60,4);
  FUN_0054cbc1(this_00,(int)this + 0x58,4);
  FUN_0054cbc1(this_00,(int)this + 0x1e8,4);
  if (DAT_0057c668 < 0x2d) {
    *(undefined4 *)((int)this + 0xfc) = 0;
    *(undefined4 *)((int)this + 0x100) = 0;
  }
  else {
    FUN_0054cbc1(this_00,(int)this + 0xfc,4);
    FUN_0054cbc1(this_00,(int)this + 0x100,4);
  }
  FUN_0054cbc1(this_00,&local_14,4);
  if (local_14 == -1) {
    *(undefined4 *)((int)this + 0x1d8) = 0;
  }
  else {
    iVar1 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
    uVar2 = FUN_004017f0((void *)(iVar1 + 0xfac),local_14,(int *)0x0);
    *(undefined4 *)((int)this + 0x1d8) = uVar2;
  }
  FUN_0054cbc1(this_00,&local_18,4);
  iVar1 = 0;
  if (0 < local_18) {
    do {
      local_10 = operator_new(0x30);
      local_4 = 0;
      if (local_10 == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = GamePlan_StreamConstruct(local_10,this_00);
      }
      local_4 = 0xffffffff;
      FUN_004014b0((void *)((int)this + 300),puVar3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < local_18);
  }
  FUN_0054cbc1(this_00,&local_18,4);
  if ((local_18 < 0) || (10000 < local_18)) {
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
    iVar1 = 0;
    if (0 < local_18) {
      do {
        FUN_0054cbc1(this_00,&local_14,4);
        local_10 = operator_new(0x330);
        local_4 = 1;
        if (local_10 == (void *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3 = FUN_0050fc20(local_10,this_00,'\x01');
        }
        local_4 = 0xffffffff;
        FUN_004015b0((void *)((int)this + 0x110),puVar3,local_14);
        iVar1 = iVar1 + 1;
      } while (iVar1 < local_18);
    }
    FUN_0054cbc1(this_00,&local_14,4);
    if (local_14 == 1) {
      local_10 = operator_new(0x330);
      local_4 = 2;
      if (local_10 == (void *)0x0) {
        local_4 = 0xffffffff;
        *(undefined4 *)((int)this + 0x1d4) = 0;
      }
      else {
        puVar3 = FUN_0050fc20(local_10,this_00,'\x01');
        local_4 = 0xffffffff;
        *(undefined4 **)((int)this + 0x1d4) = puVar3;
      }
    }
    else {
      *(undefined4 *)((int)this + 0x1d4) = 0;
    }
    FUN_0054cbc1(this_00,&local_18,4);
    iVar1 = 0;
    if (0 < local_18) {
      do {
        FUN_0054cbc1(this_00,&local_14,4);
        local_10 = operator_new(0x1a3c);
        local_4 = 3;
        if (local_10 == (void *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3 = FUN_00477000(local_10,this_00,this);
        }
        local_4 = 0xffffffff;
        FUN_004015b0((void *)((int)this + 0x148),puVar3,local_14);
        iVar1 = iVar1 + 1;
      } while (iVar1 < local_18);
    }
    FUN_0054cbc1(this_00,&local_18,4);
    iVar1 = 0;
    if (0 < local_18) {
      do {
        local_10 = operator_new(0x35c);
        local_4 = 4;
        if (local_10 == (void *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3 = StatsPeriodReport_StreamConstruct(local_10,this_00);
        }
        local_4 = 0xffffffff;
        FUN_004014b0((void *)((int)this + 0x164),puVar3);
        iVar1 = iVar1 + 1;
      } while (iVar1 < local_18);
    }
    FUN_0054cbc1(this_00,&local_18,4);
    iVar1 = 0;
    if (0 < local_18) {
      do {
        FUN_0054cbc1(this_00,&local_14,4);
        local_10 = operator_new(0x150);
        local_4 = 5;
        if (local_10 == (void *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3 = Storage_Construct(local_10,this_00);
        }
        local_4 = 0xffffffff;
        FUN_004015b0((void *)((int)this + 0x180),puVar3,local_14);
        iVar1 = iVar1 + 1;
      } while (iVar1 < local_18);
    }
    FUN_0054cbc1(this_00,&local_18,4);
    iVar1 = 0;
    if (0 < local_18) {
      do {
        pvVar4 = operator_new(8);
        FUN_0054cbc1(this_00,&local_14,4);
        FUN_0054cbc1(this_00,pvVar4,8);
        FUN_004015b0((void *)((int)this + 0x1b8),pvVar4,local_14);
        iVar1 = iVar1 + 1;
      } while (iVar1 < local_18);
    }
    FUN_0054cbc1(this_00,&local_18,4);
    iVar1 = 0;
    if (0 < local_18) {
      do {
        pvVar4 = operator_new(0x1a0);
        FUN_0054cbc1(this_00,pvVar4,0x1a0);
        FUN_004014b0((void *)((int)this + 0x19c),pvVar4);
        iVar1 = iVar1 + 1;
      } while (iVar1 < local_18);
    }
    FUN_004ddd20((int)this);
  }
  ExceptionList = local_c;
  return;
}

