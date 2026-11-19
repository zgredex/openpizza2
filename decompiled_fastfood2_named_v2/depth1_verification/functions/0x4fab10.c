// rea decompile_all
// name: FUN_004fab10
// address: 0x4fab10
// body: available
// range: 0x4fab10-0x4faca5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_004fab10(int *param_1,uint param_2,char param_3,int param_4)

{
  uint uVar1;
  void *this;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint local_90;
  uint local_8c;
  int local_88;
  int local_84;
  uint local_80;
  uint local_7c;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64 [25];
  
  local_84 = 0;
  if (param_4 < 1) {
    return 0;
  }
  if (param_2 == 5) {
    local_88 = City_FindMatchingCity(param_1);
    local_80 = 1;
  }
  else {
    AI_SelectBestPlan(param_2,*(int *)(*param_1 + 0x24),(int)param_1,&local_88,&local_80,-1,-1);
  }
  piVar3 = &local_70;
  piVar4 = &local_74;
  uVar1 = Random_Mod(local_80);
  City_GetListEndpoints(DAT_0057c670,local_88,uVar1,piVar4,piVar3);
  local_6c = local_74;
  local_68 = local_70;
  this = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 0x74),local_88,(int *)0x0);
  FUN_004e4160(this,&local_8c,&local_90);
  if ((int)local_8c < 1) {
    local_8c = 1;
  }
  if ((int)local_90 < 1) {
    local_90 = 1;
  }
  piVar3 = local_64;
  for (uVar1 = local_8c * local_90 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *piVar3 = 0x20202020;
    piVar3 = piVar3 + 1;
  }
  for (uVar1 = local_8c * local_90 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)piVar3 = 0x20;
    piVar3 = (int *)((int)piVar3 + 1);
  }
  if (0 < (int)local_90) {
    piVar3 = local_64;
    local_7c = local_90;
    do {
      piVar4 = piVar3;
      for (uVar1 = local_8c >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
        *piVar4 = 0x61616161;
        piVar4 = piVar4 + 1;
      }
      piVar3 = (int *)((int)piVar3 + local_8c);
      for (uVar1 = local_8c & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
        *(undefined1 *)piVar4 = 0x61;
        piVar4 = (int *)((int)piVar4 + 1);
      }
      local_7c = local_7c - 1;
    } while (local_7c != 0);
    local_7c = 0;
  }
  if (0 < param_4) {
    do {
      iVar2 = FUN_004f9ee0(param_1,local_8c,local_90,local_64,(int)&local_74,1,0,param_3);
      if (iVar2 != 0) {
        local_84 = local_84 + 1;
      }
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return local_84;
}

