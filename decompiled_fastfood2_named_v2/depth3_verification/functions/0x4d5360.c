// rea decompile_all
// name: FUN_004d5360
// address: 0x4d5360
// body: available
// range: 0x4d5360-0x4d5499 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004d5360(void *this,int param_1)

{
  char cVar1;
  void *this_00;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *this_01;
  char *pcVar5;
  char *pcVar6;
  char local_4c [64];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558f7b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00401320(*(int *)((int)DAT_0057c670 + 0x240));
  FUN_00401320(*(int *)((int)DAT_0057c670 + 0x244));
  this_00 = operator_new(0x16c);
  this_01 = (char *)0x0;
  local_4 = 0;
  if (this_00 != (void *)0x0) {
    this_01 = (char *)FUN_00504610(this_00,0xe,*(int *)((int)this + 0xc1c),0,param_1,-1);
  }
  local_4 = 0xffffffff;
  FUN_0054dd83(local_4c,(byte *)s__s__s_00563314,DAT_00580dfc);
  uVar3 = 0xffffffff;
  pcVar6 = local_4c;
  do {
    pcVar5 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar5 + -uVar3;
  pcVar6 = this_01;
  for (uVar4 = uVar3 >> 2; pcVar6 = pcVar6 + 4, uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  FUN_00482790(DAT_0057c670,this_01);
  FUN_004d28f0(*(void **)(param_1 + 0x16f0),this_01);
  iVar2 = FUN_004f3a90(*(int *)(param_1 + 0x14e0));
  FUN_00505e60(this_01,1,iVar2);
  FUN_0050e890(this_01,5);
  FUN_00509060(this_01,0xc);
  FUN_005090e0((int)this_01);
  FUN_00401340(*(int *)((int)DAT_0057c670 + 0x244));
  FUN_00401340(*(int *)((int)DAT_0057c670 + 0x240));
  ExceptionList = local_c;
  return;
}

