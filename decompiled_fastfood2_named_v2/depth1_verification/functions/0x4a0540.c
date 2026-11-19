// rea decompile_all
// name: FUN_004a0540
// address: 0x4a0540
// body: available
// range: 0x4a0540-0x4a0671 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a0540(void *param_1)

{
  int iVar1;
  void *this;
  uint *this_00;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  tagRECT local_1c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005587cb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00531cf0(param_1,0x1f52);
  this = operator_new(0x18);
  local_4 = 0;
  if (this == (void *)0x0) {
    this_00 = (uint *)0x0;
  }
  else {
    this_00 = FUN_00534d60(this,0xaa,0xaa,0xf);
  }
  local_4 = 0xffffffff;
  SetRect(&local_1c,0,0,800,600);
  Gfx_BlitRectList(this_00,(uint *)&local_1c);
  puVar2 = (undefined4 *)FUN_0053d480(DAT_0057cda8);
  puVar3 = (undefined4 *)FUN_0053d480(DAT_0057cda4);
  for (iVar7 = 0x54ab; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar7 = FUN_0053d480(DAT_0057cda4);
  pbVar4 = (byte *)(iVar7 + 2);
  iVar8 = 0x70e4;
  iVar7 = DAT_00568c78;
  do {
    if ((int)(uint)*pbVar4 < iVar7) {
      *pbVar4 = (byte)iVar7;
      iVar7 = DAT_00568c78;
    }
    pbVar4 = pbVar4 + 3;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar10 = 0;
  iVar8 = 0;
  iVar7 = 0;
  puVar5 = (uint *)FUN_0053d480(DAT_0057cda4);
  puVar9 = this_00;
  uVar6 = FUN_00521b10(iVar1);
  Gfx_BlitRLEScaled(DAT_0057cda4,uVar6,puVar9,puVar5,iVar7,iVar8,iVar10);
  *(undefined4 *)((int)param_1 + 0xe0) = 1;
  if (this_00 != (uint *)0x0) {
    (**(code **)*this_00)(1);
  }
  ExceptionList = local_c;
  return;
}

