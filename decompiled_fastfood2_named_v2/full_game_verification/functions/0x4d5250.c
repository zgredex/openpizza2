// rea decompile_all
// name: Branch_HireExterminator
// address: 0x4d5250
// body: available
// range: 0x4d5250-0x4d5353 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


bool __thiscall Branch_HireExterminator(void *this,int param_1,void *param_2)

{
  char cVar1;
  void *this_00;
  char *this_01;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Creates and charges an exterminator service object. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558f5b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0x16c);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    this_01 = (char *)0x0;
  }
  else {
    this_01 = (char *)Object_Construct(this_00,0x20,*(int *)((int)this + 0xc1c),0,0,-1);
  }
  uVar3 = 0xffffffff;
  pcVar6 = DAT_00580af8;
  do {
    pcVar5 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  local_4 = 0xffffffff;
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
  Game_AddObjectToRegistry(DAT_0057c670,this_01);
  Object_SetDestinationAndTarget(this_01,1,*(int *)((int)param_2 + 0x16f0));
  Object_SetFieldA4Locked(this_01,param_1);
  if (param_1 == 1) {
    Game_CanAfford(param_2,5,1000.0,'\0',-1);
    ExceptionList = local_c;
    return true;
  }
  uVar2 = Game_CanAfford(param_2,5,10000.0,'\x01',-1);
  ExceptionList = local_c;
  return (char)uVar2 != '\0';
}

