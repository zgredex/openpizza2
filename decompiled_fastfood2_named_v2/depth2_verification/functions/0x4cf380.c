// rea decompile_all
// name: FUN_004cf380
// address: 0x4cf380
// body: available
// range: 0x4cf380-0x4cf68c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004cf380(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  
  iVar1 = *(int *)(DAT_0057c670 + 0x298 + *(int *)(DAT_0057c670 + 0x290) * 4);
  iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  iVar3 = FUN_00482820(DAT_0057c670);
  iVar2 = *(int *)(iVar2 + 0xc20 + iVar3 * 4);
  FUN_00532520((int)param_1);
  FUN_00532330(param_1,0,9,0x3f4);
  FUN_0052ff50(param_1,0x3f4,(uint)(iVar1 == 1));
  FUN_00531620(param_1,0x3f4,(uint)(iVar1 == 1));
  FUN_0052ff50(param_1,0x3fe,(uint)(iVar1 == 2));
  FUN_00531620(param_1,0x3fe,(uint)(iVar1 == 2));
  iVar3 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  puVar4 = FUN_004d5b90(iVar3);
  iVar3 = puVar4[5];
  if (puVar4 != (undefined4 *)0x0) {
    (**(code **)*puVar4)(1);
  }
  iVar5 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  puVar4 = FUN_004d5c40(iVar5);
  iVar5 = puVar4[5];
  if (puVar4 != (undefined4 *)0x0) {
    (**(code **)*puVar4)(1);
  }
  FUN_0052ff50(param_1,0x404,(uint)(iVar1 == 0xb));
  FUN_00531620(param_1,0x404,(uint)(iVar1 == 0xb));
  FUN_005316f0(param_1,0x404,(uint)(0 < iVar3 + iVar5));
  FUN_0052ff50(param_1,0x401,(uint)(iVar1 == 4));
  FUN_00531620(param_1,0x401,(uint)(iVar1 == 4));
  FUN_0052ff50(param_1,0x3f8,(uint)(iVar1 == 5));
  FUN_00531620(param_1,0x3f8,(uint)(iVar1 == 5));
  uVar6 = (uint)(0 < iVar2);
  FUN_005316f0(param_1,0x3f8,uVar6);
  iVar3 = FUN_004e2280(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4));
  if (iVar3 < 3) {
    FUN_0052ff50(param_1,0x3f9,0);
    UI_RemoveObjectByKey(param_1,0x3f9);
  }
  else {
    FUN_0052ff50(param_1,0x3f9,(uint)(iVar1 == 6));
    FUN_00531620(param_1,0x3f9,(uint)(iVar1 == 6));
    FUN_005316f0(param_1,0x3f9,uVar6);
  }
  if ((*(int *)(DAT_0057c670 + 0x218) == 0) ||
     (*(int *)(*(int *)(DAT_0057c670 + 0x218) + 4) != 0x19)) {
    FUN_005316f0(param_1,0x402,0);
    FUN_005316f0(param_1,0x403,0);
    FUN_005316f0(param_1,0x3fd,0);
    return;
  }
  FUN_0052ff50(param_1,0x402,(uint)(iVar1 == 8));
  FUN_00531620(param_1,0x402,(uint)(iVar1 == 8));
  iVar3 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  if (*(int *)(iVar3 + 0x10c4) < 1) {
    uVar6 = 0;
  }
  else {
    uVar6 = (uint)(1 < iVar2);
  }
  FUN_005316f0(param_1,0x402,uVar6);
  FUN_0052ff50(param_1,0x403,(uint)(iVar1 == 9));
  FUN_00531620(param_1,0x403,(uint)(iVar1 == 9));
  FUN_0052ff50(param_1,0x3fd,(uint)(iVar1 == 0xc));
  FUN_005316f0(param_1,0x3fd,1);
  return;
}

