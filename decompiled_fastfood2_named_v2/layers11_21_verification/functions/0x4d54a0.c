// rea decompile_all
// name: FUN_004d54a0
// address: 0x4d54a0
// body: available
// range: 0x4d54a0-0x4d5571 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004d54a0(void *this,int param_1)

{
  char cVar1;
  void *this_00;
  char *this_01;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558f9b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0x16c);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    this_01 = (char *)0x0;
  }
  else {
    this_01 = (char *)Object_Construct(this_00,0x22,*(int *)((int)this + 0xc1c),0,0,-1);
  }
  uVar2 = 0xffffffff;
  pcVar5 = DAT_00580b40;
  do {
    pcVar4 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  local_4 = 0xffffffff;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = this_01;
  for (uVar3 = uVar2 >> 2; pcVar5 = pcVar5 + 4, uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  FUN_00482790(DAT_0057c670,this_01);
  FUN_0050e730(this_01,*(void **)(param_1 + 0x16f0),0);
  *(undefined4 *)(this_01 + 0xcc) = *(undefined4 *)(param_1 + 0x16f0);
  FUN_0050e890(this_01,8);
  FUN_00507c90(this_01);
  ExceptionList = local_c;
  return;
}

