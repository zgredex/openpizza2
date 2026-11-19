// rea decompile_all
// name: Character_Construct
// address: 0x4d3730
// body: available
// range: 0x4d3730-0x4d3905 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall Character_Construct(void *this,int param_1,int param_2)

{
  uint uVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  longlong lVar7;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Constructs a character with random attributes, AI plan, and name. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558db6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = &PTR_FUN_0055c4fc;
  *(undefined4 *)((int)this + 0x814) = 0xffffffff;
  *(undefined4 *)((int)this + 0x818) = 0xffffffff;
  *(undefined4 *)((int)this + 0x81c) = 0xffffffff;
  *(undefined4 *)((int)this + 0x820) = 0xffffffff;
  uVar1 = FUN_004034d0(0x1e,0x46);
  *(uint *)((int)this + 4) = uVar1;
  uVar1 = FUN_004034d0(0x1e,0x46);
  *(uint *)((int)this + 8) = uVar1;
  uVar1 = FUN_004034d0(0x1e,0x46);
  *(uint *)((int)this + 0x10) = uVar1;
  uVar1 = FUN_004034d0(0x1e,0x46);
  *(uint *)((int)this + 0xc) = uVar1;
  uVar1 = FUN_004034d0(0x12,0x3c);
  *(uint *)((int)this + 0x38) = uVar1;
  *(undefined1 *)((int)this + 0x824) = (undefined1)param_2;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined1 *)((int)this + 0x825) = 2;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  piVar6 = (int *)((int)this + 0x44);
  for (iVar5 = 500; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar6 = 0;
    piVar6 = piVar6 + 1;
  }
  iVar5 = FUN_004d4000((int)this);
  *(int *)((int)this + 0x44) = iVar5;
  iVar5 = FUN_004d3f90((int)this);
  *(int *)((int)this + 0x1d4) = iVar5;
  iVar5 = FUN_004d3fc0((int)this);
  *(int *)((int)this + 0x364) = iVar5;
  *(undefined4 *)((int)this + 0x4f4) = *(undefined4 *)((int)this + 0xc);
  iVar5 = FUN_004d3fe0((int)this);
  *(int *)((int)this + 0x684) = iVar5;
  if (param_1 == -1) goto LAB_004d38e4;
  if (param_2 == 3) {
    pvVar2 = operator_new(0x16c);
    local_4 = 0;
    if (pvVar2 == (void *)0x0) {
LAB_004d3889:
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = Object_Construct(pvVar2,0x10,param_1,0,0,3);
    }
  }
  else {
    pvVar2 = operator_new(0x16c);
    local_4 = 1;
    if (pvVar2 == (void *)0x0) goto LAB_004d3889;
    iVar5 = 0;
    uVar1 = _rand();
    puVar3 = Object_Construct(pvVar2,0x10,param_1,uVar1 & 1,iVar5,param_2);
  }
  local_4 = 0xffffffff;
  FUN_00403020(DAT_0057ba10,puVar3[9],(char *)(puVar3 + 1));
  iVar5 = FUN_00482790(DAT_0057c670,puVar3);
  FUN_004d3ef0(this,puVar3[9]);
  iVar4 = FUN_004014b0((void *)((int)DAT_0057c670 + 0x20),this);
  *(int *)((int)this + 0x818) = param_1;
  *(int *)((int)this + 0x814) = iVar5;
  puVar3[0x14] = iVar4;
LAB_004d38e4:
  lVar7 = FUN_004d3990((int)this);
  *(int *)((int)this + 0x3c) = (int)lVar7;
  ExceptionList = local_c;
  return this;
}

