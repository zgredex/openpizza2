// rea decompile_all
// name: FUN_00504e90
// address: 0x504e90
// body: available
// range: 0x504e90-0x505200 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00504e90(void *this,int param_1,int param_2,int param_3)

{
  void *pvVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a29b;
  local_c = ExceptionList;
  if (param_2 == -1) {
    param_2 = *(int *)((int)this + 0x30);
  }
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x7c);
  local_4 = 0;
  pvVar2 = (void *)0x0;
  if (pvVar1 != (void *)0x0) {
    FUN_0054b390((undefined4 *)((int)pvVar1 + 0x14));
    pvVar2 = pvVar1;
  }
  local_4 = 0xffffffff;
  *(void **)((int)this + 200) = pvVar2;
  if (param_2 == 0x14) {
    *(undefined4 *)((int)this + 0x24) = 0;
  }
  if (*(int *)((int)this + 0xc4) != 0) {
    switch(param_2) {
    case 0xd:
    case 0x17:
      iVar4 = FUN_0050dbd0((int)this);
      if (iVar4 != 0) {
        if (*(int *)((int)this + 0x74) == 0) {
          ExceptionList = local_c;
          return;
        }
        param_2 = 0x29;
      }
      break;
    case 0x1d:
    case 0x1e:
      iVar4 = FUN_0050dbd0((int)this);
      if (iVar4 != 0) {
        if (*(int *)((int)this + 0x74) == 0) {
          ExceptionList = local_c;
          return;
        }
        param_2 = 0x2a;
      }
    }
    switch(param_2) {
    case 0x23:
      uVar3 = FUN_004ead90(DAT_0057c5cc,param_1,0,0);
      *(undefined4 *)(*(int *)((int)this + 200) + 0x58) = uVar3;
      break;
    default:
      if (*(int *)((int)this + 0x30) == 0x10) {
        if (param_3 == -1) {
          FUN_0048e0a0();
        }
        iVar4 = *(int *)((int)this + 0x24);
        param_2 = param_3 + 0x25;
      }
      else {
        iVar4 = *(int *)((int)this + 0x24);
      }
      uVar3 = FUN_004ead90(DAT_0057c5cc,param_1,iVar4,param_2);
      *(undefined4 *)(*(int *)((int)this + 200) + 0x58) = uVar3;
      break;
    case 0x29:
      *(undefined4 *)(*(int *)((int)this + 200) + 0x58) =
           *(undefined4 *)((int)DAT_0057c5cc + 0x2c3bc);
      break;
    case 0x2a:
      *(undefined4 *)(*(int *)((int)this + 200) + 0x58) =
           *(undefined4 *)((int)DAT_0057c5cc + 0x2c3c0);
      break;
    case 0x2b:
    case 0x2c:
      *(undefined4 *)(*(int *)((int)this + 200) + 0x58) =
           *(undefined4 *)((int)DAT_0057c5cc + 0x2c3c8);
      break;
    case 0x2d:
      *(undefined4 *)(*(int *)((int)this + 200) + 0x58) =
           *(undefined4 *)((int)DAT_0057c5cc + 0x2c3c4);
      break;
    case 0x2e:
      *(undefined4 *)(*(int *)((int)this + 200) + 0x58) =
           *(undefined4 *)((int)DAT_0057c5cc + 0x2c3cc);
      break;
    case 0x2f:
      *(undefined4 *)(*(int *)((int)this + 200) + 0x58) =
           *(undefined4 *)((int)DAT_0057c5cc + 0x2c3d0);
    }
    CS_Enter(*(int *)(DAT_0057c670 + 0x240));
    pvVar2 = *(void **)(*(int *)((int)this + 200) + 0x58);
    if (pvVar2 == (void *)0x0) {
      *(undefined4 *)((int)this + 200) = 0;
      CS_Leave(*(int *)(DAT_0057c670 + 0x240));
    }
    else {
      iVar4 = FUN_005338c0(pvVar2,-1);
      **(int **)((int)this + 200) = iVar4;
      iVar4 = FUN_005338c0(*(void **)((int)DAT_0057c5cc + 0x2c3b4),-1);
      *(int *)(*(int *)((int)this + 200) + 4) = iVar4;
      CS_Leave(*(int *)(DAT_0057c670 + 0x240));
      *(undefined2 *)(*(int *)((int)this + 200) + 8) = 0xffff;
      *(undefined2 *)(*(int *)((int)this + 200) + 10) = 0xffff;
      *(undefined4 *)(*(int *)((int)this + 200) + 0x6c) = 0;
      *(undefined4 *)(*(int *)((int)this + 200) + 0x70) = 0;
      *(undefined2 *)(*(int *)((int)this + 200) + 0x28) = 0xffff;
      *(undefined4 *)(*(int *)((int)this + 200) + 0xc) = 0xffffffff;
      *(undefined1 *)(*(int *)((int)this + 200) + 0x10) = 0;
      *(undefined4 *)(*(int *)((int)this + 200) + 0x20) = 0;
      *(undefined4 *)(*(int *)((int)this + 200) + 0x24) = 0;
      *(undefined4 *)(*(int *)((int)this + 200) + 0x30) = 0xffffffff;
      *(undefined4 *)(*(int *)((int)this + 200) + 0x34) = 0xffffffff;
      *(undefined4 *)(*(int *)((int)this + 200) + 0x38) = 0xffffffff;
      *(undefined4 *)(*(int *)((int)this + 200) + 0x3c) = 0xffffffff;
      *(undefined4 *)(*(int *)((int)this + 200) + 0x40) = 0xffffffff;
      *(undefined4 *)(*(int *)((int)this + 200) + 0x44) = 0xffffffff;
      *(undefined4 *)(*(int *)((int)this + 200) + 0x48) = 0xffffffff;
      *(undefined4 *)(*(int *)((int)this + 200) + 0x4c) = 0xffffffff;
      *(undefined4 *)(*(int *)((int)this + 200) + 0x50) = 0xffffffff;
      *(undefined4 *)(*(int *)((int)this + 200) + 0x54) = 0xffffffff;
      if (((*(int *)((int)this + 0x30) == 0x11) || (*(int *)((int)this + 0x30) != 0x13)) ||
         (param_1 != 1)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0x10;
      }
      FUN_0050e4c0(this,uVar3);
      FUN_004f1370(*(void **)((int)this + 0xc4),*(int *)((int)this + 200));
      if (param_1 == 1) {
        FUN_005342e0((void *)(*(int **)((int)this + 200))[0x16],**(int **)((int)this + 200),-1,-1);
      }
      SetRect((LPRECT)(*(int *)((int)this + 200) + 0x5c),0xffff,0xffff,-1,-1);
      *(void **)(*(int *)((int)this + 200) + 0x74) = this;
      *(undefined4 *)(*(int *)((int)this + 200) + 0x78) = 0;
    }
  }
  ExceptionList = local_c;
  return;
}

