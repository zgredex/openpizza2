// rea decompile_all
// name: FUN_004cec60
// address: 0x4cec60
// body: available
// range: 0x4cec60-0x4cefdc inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004cec60(void *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x290) * 4 + 0x298);
  iVar1 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  iVar2 = FUN_00482820((int)DAT_0057c670);
  iVar1 = *(int *)(iVar1 + 0xc20 + iVar2 * 4);
  UI_Group_ClearAll((int)param_1);
  FUN_00532330(param_1,0,9,0x3f4);
  FUN_0052ff50(param_1,0x3f4,(uint)(iVar5 == 1));
  FUN_00531620(param_1,0x3f4,(uint)(iVar5 == 1));
  FUN_0052ff50(param_1,0x3fe,(uint)(iVar5 == 2));
  FUN_00531620(param_1,0x3fe,(uint)(iVar5 == 2));
  iVar2 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  puVar3 = FUN_004d5b90(iVar2);
  iVar2 = puVar3[5];
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  iVar4 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  puVar3 = FUN_004d5c40(iVar4);
  iVar4 = puVar3[5];
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  FUN_0052ff50(param_1,0x402,(uint)(iVar5 == 0xb));
  FUN_00531620(param_1,0x402,(uint)(iVar5 == 0xb));
  FUN_005316f0(param_1,0x402,(uint)(0 < iVar2 + iVar4));
  FUN_0052ff50(param_1,0x401,(uint)(iVar5 == 4));
  FUN_00531620(param_1,0x401,(uint)(iVar5 == 4));
  FUN_0052ff50(param_1,0x3f8,(uint)(iVar5 == 5));
  FUN_00531620(param_1,0x3f8,(uint)(iVar5 == 5));
  uVar6 = (uint)(0 < iVar1);
  FUN_005316f0(param_1,0x3f8,uVar6);
  iVar1 = FUN_004e2280(*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200)
                      );
  if (iVar1 < 3) {
    FUN_0052ff50(param_1,0x3f9,0);
    FUN_00531740(param_1,0x3f9);
  }
  else {
    FUN_0052ff50(param_1,0x3f9,(uint)(iVar5 == 6));
    FUN_00531620(param_1,0x3f9,(uint)(iVar5 == 6));
    FUN_005316f0(param_1,0x3f9,uVar6);
  }
  uVar6 = (uint)(iVar5 == 10);
  FUN_0052ff50(param_1,0x3fd,uVar6);
  FUN_00531620(param_1,0x3fd,uVar6);
  FUN_005316f0(param_1,0x3fd,uVar6);
  iVar1 = *(int *)((int)DAT_0057c670 + 0x218);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 4) == 0x10)) && (*(int *)(iVar1 + 0x38) == 0)) {
    iVar2 = *(int *)(iVar1 + 8);
    iVar4 = FUN_00482820((int)DAT_0057c670);
    if (iVar2 == iVar4) {
      FUN_0052ff50(param_1,0x404,(uint)(iVar5 == 7));
      FUN_00531620(param_1,0x404,(uint)(iVar5 == 7));
      FUN_005316f0(param_1,0x404,1);
      iVar2 = FUN_00488be0(DAT_0057c670,*(int *)(iVar1 + 8));
      iVar1 = FUN_004017f0((void *)(iVar2 + 0x180),*(int *)(iVar1 + 0x2c),(int *)0x0);
      FUN_0052ff50(param_1,0x403,(uint)(iVar5 == 8));
      FUN_00531620(param_1,0x403,(uint)(iVar5 == 8));
      iVar5 = FUN_00513fd0(iVar1);
      FUN_005316f0(param_1,0x403,(uint)(iVar5 < 2));
      FUN_005316f0(param_1,0x3fd,1);
      return;
    }
  }
  FUN_00531670(param_1,0x403);
  FUN_005316f0(param_1,0x403,0);
  FUN_00531670(param_1,0x404);
  FUN_005316f0(param_1,0x404,0);
  FUN_005316f0(param_1,0x3fd,uVar6);
  return;
}

