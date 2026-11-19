// rea decompile_all
// name: City_CreateBranchObject
// address: 0x4d50a0
// body: available
// range: 0x4d50a0-0x4d5158 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


char * __thiscall City_CreateBranchObject(void *this,undefined4 param_1,int param_2)

{
  char cVar1;
  void *this_00;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558f1b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0x16c);
  pcVar5 = (char *)0x0;
  local_4 = 0;
  if (this_00 != (void *)0x0) {
    pcVar5 = (char *)Object_Construct(this_00,param_1,*(int *)((int)this + 0xc1c),0,param_2,-1);
  }
  local_4 = 0xffffffff;
  pcVar2 = Game_GetDataByIndex(param_1);
  uVar3 = 0xffffffff;
  do {
    pcVar6 = pcVar2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar6 + -uVar3;
  pcVar2 = pcVar5;
  for (uVar4 = uVar3 >> 2; pcVar2 = pcVar2 + 4, uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar2 = pcVar2 + 1;
  }
  Game_AddObjectToRegistry(DAT_0057c670,pcVar5);
  Game_AddObjectToList(*(void **)(param_2 + 0x16f0),pcVar5);
  ExceptionList = local_c;
  return pcVar5;
}

