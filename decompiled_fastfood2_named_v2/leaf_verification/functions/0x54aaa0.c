// rea decompile_all
// name: FUN_0054aaa0
// address: 0x54aaa0
// body: available
// range: 0x54aaa0-0x54ac35 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall
FUN_0054aaa0(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            char *param_7,char *param_8)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  void *this_00;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  char *pcVar9;
  int *piVar10;
  void *local_4;
  
  local_4 = this;
  Sound_SetState(DAT_0057ba0c,param_2);
  FUN_00548e00(DAT_0057ba0c,param_1);
  uVar5 = 0xffffffff;
  pcVar9 = param_8;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  uVar6 = 0xffffffff;
  pcVar9 = param_8;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  piVar2 = operator_new(~uVar6 + 0x7b);
  uVar6 = 0xffffffff;
  do {
    pcVar9 = param_8;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar9 = param_8 + 1;
    cVar1 = *param_8;
    param_8 = pcVar9;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  piVar8 = (int *)(pcVar9 + -uVar6);
  piVar10 = piVar2 + 0x1e;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *piVar10 = *piVar8;
    piVar8 = piVar8 + 1;
    piVar10 = piVar10 + 1;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(char *)piVar10 = (char)*piVar8;
    piVar8 = (int *)((int)piVar8 + 1);
    piVar10 = (int *)((int)piVar10 + 1);
  }
  _strncpy((char *)(piVar2 + 0xe),param_7,0x40);
  *piVar2 = ~uVar5 + 0x7b;
  piVar2[1] = param_2;
  piVar2[5] = param_6;
  iVar3 = -1;
  piVar2[4] = 0;
  piVar2[2] = -1;
  piVar2[7] = -0x40800000;
  piVar2[6] = (int)this;
  piVar2[9] = param_3;
  piVar2[10] = param_4;
  if (param_5 != 0) {
    this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                   (int *)0x0);
    iVar3 = FUN_004d7e90(this_00,param_5);
  }
  piVar2[0xc] = iVar3;
  piVar2[0xb] = param_1;
  piVar2[0xd] = 0;
  iVar3 = FUN_004014b0((void *)((int)this + 4),piVar2);
  if (*(int *)((int)this + 0x30) == 0) {
    do {
      if (*(int *)((int)this + 0x18) < 10) {
        return iVar3;
      }
      iVar4 = FUN_0054b160(this);
    } while (iVar4 != 0);
    return iVar3;
  }
  iVar4 = FUN_0054b070(this,(int *)&local_4);
  while( true ) {
    if (iVar4 != -1) {
      FUN_0054aec0(this,(int)piVar2,iVar4,600);
      piVar2[3] = (int)local_4;
      piVar2[8] = (int)-((float)piVar2[7] - (float)(int)local_4);
      FUN_005313d0(*(void **)((int)this + 0x34),iVar4);
      return iVar3;
    }
    iVar4 = FUN_0054b160(this);
    if (iVar4 == 0) break;
    iVar4 = FUN_0054b070(this,(int *)&local_4);
  }
  return -1;
}

