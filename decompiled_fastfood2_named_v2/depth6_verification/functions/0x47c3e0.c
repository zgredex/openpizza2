// rea decompile_all
// name: FUN_0047c3e0
// address: 0x47c3e0
// body: available
// range: 0x47c3e0-0x47c578 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_0047c3e0(void *this,int *param_1,undefined4 param_2,int param_3)

{
  void *this_00;
  undefined4 uVar1;
  int iVar2;
  void *this_01;
  void *this_02;
  undefined4 *this_03;
  uint uVar3;
  uint extraout_EDX;
  uint extraout_EDX_00;
  uint extraout_EDX_01;
  undefined4 uVar4;
  longlong lVar5;
  int *piVar6;
  int local_c;
  undefined4 local_4;
  
  local_c = 200;
  iVar2 = FUN_00488be0(DAT_0057c670,*(int *)((int)this + 0x30));
  *(undefined4 *)(*param_1 + 0x820) = *(undefined4 *)((int)this + 0x3c);
  *(undefined4 *)(*param_1 + 0x81c) = *(undefined4 *)((int)this + 0x30);
  FUN_004ddcc0(iVar2);
  lVar5 = FUN_004d3990(*param_1);
  FUN_004d4160((void *)*param_1,(int)lVar5);
  param_1[1] = param_3;
  this_01 = (void *)FUN_004d3910(*param_1);
  this_02 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)this + 0x34),
                                 (int *)0x0);
  this_00 = *(void **)((int)this_02 + 0xfa8);
  do {
    iVar2 = FUN_004f0cc0(this_00,1,*(int *)(*(int *)((int)this + 0x16f0) + 0x54));
    this_03 = FUN_004d8470(this_02,this_00,0,iVar2,local_c,0);
    iVar2 = this_03[5];
    uVar3 = extraout_EDX;
    if (iVar2 != 0) {
      piVar6 = (int *)0x0;
      uVar3 = FUN_004034d0(0,iVar2 - 1);
      local_4 = FUN_004017f0(this_03,uVar3,piVar6);
      uVar3 = extraout_EDX_00;
    }
    local_c = local_c + 100;
    if (this_03 != (undefined4 *)0x0) {
      (**(code **)*this_03)(1);
      uVar3 = extraout_EDX_01;
    }
  } while (iVar2 == 0);
  *(undefined4 *)((int)this_01 + 0xcc) = local_4;
  *(undefined4 *)((int)this_01 + 0x7c) = 0xff;
  FUN_0050e2a0((int)this_01,uVar3,(int)this,'\x01');
  uVar4 = 0xffffffff;
  FUN_0050e850(this_01,0xffffffff);
  *(undefined4 *)((int)this_01 + 0x88) = 0xffffffff;
  switch(param_2) {
  case 0:
    uVar4 = 0x11;
    break;
  case 1:
    uVar4 = 0x12;
    break;
  case 2:
    uVar4 = 0x13;
    break;
  case 3:
    uVar4 = 0x14;
    break;
  default:
    goto switchD_0047c509_default;
  }
  *(undefined4 *)((int)this_01 + 0x78) = uVar4;
switchD_0047c509_default:
  FUN_00507a80((int)this_01);
  iVar2 = FUN_004014b0((void *)((int)this + 0x1500),param_1);
  Game_ToggleObjectFlag2(this);
  FUN_004805d0(this);
  uVar1 = *(undefined4 *)((int)this_01 + 0x30);
  *(undefined4 *)((int)this_01 + 0x30) = uVar4;
  FUN_0050a0b0(this_01,0,*(int *)((int)this_01 + 0xcc));
  *(undefined4 *)((int)this_01 + 0x30) = uVar1;
  return iVar2;
}

