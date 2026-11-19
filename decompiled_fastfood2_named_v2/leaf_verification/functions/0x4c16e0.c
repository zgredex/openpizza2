// rea decompile_all
// name: FUN_004c16e0
// address: 0x4c16e0
// body: available
// range: 0x4c16e0-0x4c1825 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c16e0(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  
  iVar3 = *(int *)((int)DAT_0057c670 + 0x218);
  this = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)(iVar3 + 0x28),(int *)0x0);
  iVar1 = IDMap_Lookup((void *)(*(int *)((int)DAT_0057c670 +
                                        *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0x180),
                       *(int *)(iVar3 + 0x2c),(int *)0x0);
  iVar2 = Array_GetStride60(this,*(int *)(iVar1 + 0x30));
  iVar3 = Get_Field2C(iVar1);
  lVar5 = FUN_004d6390(3,iVar3);
  iVar4 = (int)lVar5;
  iVar3 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(iVar3 + 0x11c) == 0) {
    if (*(int *)(iVar3 + 0x200) != 0) {
      iVar4 = (iVar4 * 0xf) / 10;
    }
  }
  else {
    iVar4 = (iVar4 * 5) / 10;
  }
  FUN_0052f080(param_1,0x4ee,&DAT_005683a4,iVar4);
  iVar3 = Get_Field2C(iVar1);
  if ((iVar3 == 0) || (iVar3 == 1)) {
    FUN_0052f080(param_1,0x4eb,(byte *)s__d__s_00568324,3);
  }
  iVar3 = FUN_005144a0(iVar1);
  iVar4 = 0;
  do {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_0048c7b0(DAT_0057c670,iVar4,iVar3);
    }
    FUN_004a80e0(param_1,0x4e2,iVar4,iVar1,DAT_00581048);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  return;
}

