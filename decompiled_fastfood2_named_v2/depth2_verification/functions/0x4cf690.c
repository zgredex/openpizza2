// rea decompile_all
// name: FUN_004cf690
// address: 0x4cf690
// body: available
// range: 0x4cf690-0x4cfa11 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004cf690(void *param_1)

{
  undefined4 *puVar1;
  void *this;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  bVar3 = false;
  this = *(void **)(DAT_0057c670 + 0x9c);
  if ((*(int *)((int)this + 0x2c) != 0) || (*(char *)((int)this + 0x16f5) != '\0')) {
    puVar1 = (undefined4 *)(DAT_0057c670 + 0x2a8);
    *(undefined4 *)(DAT_0057c670 + 0x2c8) = *(undefined4 *)(DAT_0057c670 + 0x2a8);
    bVar3 = true;
    *puVar1 = 9;
  }
  iVar2 = *(int *)(DAT_0057c670 + 0x298 + *(int *)(DAT_0057c670 + 0x290) * 4);
  iVar4 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  iVar5 = FUN_00482820(DAT_0057c670);
  iVar4 = *(int *)(iVar4 + 0xc20 + iVar5 * 4);
  FUN_00532520((int)param_1);
  FUN_00532330(param_1,0,10,0x3f4);
  FUN_0052ff50(param_1,0x3f4,(uint)(iVar2 == 1));
  FUN_00531620(param_1,0x3f4,(uint)(iVar2 == 1));
  uVar6 = (uint)!bVar3;
  FUN_005316f0(param_1,0x3f4,uVar6);
  if ((iVar2 == 2) || (iVar2 == 0xb)) {
    iVar5 = 1;
  }
  else {
    iVar5 = 0;
  }
  FUN_0052ff50(param_1,0x3f5,iVar5);
  if ((iVar2 == 2) || (iVar2 == 0xb)) {
    iVar5 = 1;
  }
  else {
    iVar5 = 0;
  }
  FUN_00531620(param_1,0x3f5,iVar5);
  FUN_005316f0(param_1,0x3f5,uVar6);
  FUN_0052ff50(param_1,0x3f6,(uint)(iVar2 == 3));
  FUN_00531620(param_1,0x3f6,(uint)(iVar2 == 3));
  FUN_005316f0(param_1,0x3f6,uVar6);
  FUN_0052ff50(param_1,0x3f7,(uint)(iVar2 == 4));
  FUN_00531620(param_1,0x3f7,(uint)(iVar2 == 4));
  FUN_005316f0(param_1,0x3f7,uVar6);
  FUN_0052ff50(param_1,0x3f8,(uint)(iVar2 == 5));
  FUN_00531620(param_1,0x3f8,(uint)(iVar2 == 5));
  if ((iVar4 < 1) || (bVar3)) {
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
  }
  FUN_005316f0(param_1,0x3f8,iVar5);
  FUN_0052ff50(param_1,0x3f9,(uint)(iVar2 == 6));
  FUN_00531620(param_1,0x3f9,(uint)(iVar2 == 6));
  if ((iVar4 < 1) || (bVar3)) {
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
  }
  FUN_005316f0(param_1,0x3f9,iVar5);
  FUN_0052ff50(param_1,0x3fa,(uint)(iVar2 == 7));
  FUN_00531620(param_1,0x3fa,(uint)(iVar2 == 7));
  if ((iVar4 < 1) || (bVar3)) {
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
  }
  FUN_005316f0(param_1,0x3fa,iVar5);
  iVar5 = FUN_0047aac0(this,1);
  FUN_0052ff50(param_1,0x3fb,(uint)(iVar2 == 8));
  FUN_00531620(param_1,0x3fb,(uint)(iVar2 == 8));
  if (((iVar4 < 3) || (bVar3)) || (iVar5 < 1)) {
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
  }
  FUN_005316f0(param_1,0x3fb,iVar5);
  if (*(int *)((int)this + 0x38) < 2) {
    FUN_0052ff50(param_1,0x3fe,(uint)(iVar2 == 9));
    FUN_00531620(param_1,0x3fe,(uint)(iVar2 == 9));
    FUN_005316f0(param_1,0x3fe,(uint)(0 < iVar4));
  }
  else {
    FUN_0052ff50(param_1,0x3fe,0);
    UI_RemoveObjectByKey(param_1,0x3fe);
  }
  uVar6 = (uint)(iVar2 == 10);
  FUN_0052ff50(param_1,0x3fd,uVar6);
  FUN_00531620(param_1,0x3fd,uVar6);
  FUN_005316f0(param_1,0x3fd,uVar6);
  return;
}

