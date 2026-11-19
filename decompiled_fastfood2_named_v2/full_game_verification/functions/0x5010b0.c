// rea decompile_all
// name: UI_ProcessMenuInput
// address: 0x5010b0
// body: available
// range: 0x5010b0-0x5012a7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall UI_ProcessMenuInput(void *this,int *param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int local_e0 [2];
  undefined2 local_d8 [2];
  int aiStack_d4 [5];
  int local_c0 [4];
  undefined4 local_b0 [4];
  int local_a0 [4];
  int local_90 [36];
  
  iVar6 = *param_1;
  piVar5 = local_e0;
  for (iVar3 = 0x38; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  iVar3 = param_1[2];
  puVar1 = local_d8;
  iVar4 = 10;
  do {
    *(int *)(puVar1 + -4) = iVar6;
    *puVar1 = (short)iVar3;
    puVar1 = puVar1 + 8;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  switch(param_1[3]) {
  case 3:
    Game_AssignPlanStepWeight(this,4,local_e0);
    Game_AssignPlanStepWeight(this,0xf,aiStack_d4 + 1);
    piVar5 = local_c0;
    iVar6 = 3;
    uVar7 = 0x12;
    break;
  case 4:
    Game_AssignPlanStepWeight(this,5,local_e0);
    Game_AssignPlanStepWeight(this,6,aiStack_d4 + 1);
    piVar5 = local_c0;
    iVar6 = 3;
    uVar7 = 0xe;
    break;
  default:
    goto switchD_00501101_caseD_5;
  case 6:
    Game_AssignPlanStepWeight(this,8,local_e0);
    Game_AssignPlanStepWeight(this,0xb,aiStack_d4 + 1);
    Game_AssignPlanStepWeight(this,9,local_c0);
    Game_AssignPlanStepWeight(this,10,local_b0);
    Game_AssignPlanStepWeight(this,0xc,local_a0);
    piVar5 = local_90;
    iVar6 = 6;
    uVar7 = 0xd;
    break;
  case 0xf:
    Game_AssignPlanStepWeight(this,0x11,local_e0);
    piVar5 = aiStack_d4 + 1;
    iVar6 = 2;
    uVar7 = 0x10;
    break;
  case 0x12:
    Game_AssignPlanStepWeight(this,0x13,local_e0);
    Game_AssignPlanStepWeight(this,0x14,aiStack_d4 + 1);
    Game_AssignPlanStepWeight(this,0x15,local_c0);
    Game_AssignPlanStepWeight(this,0x16,local_b0);
    piVar5 = local_a0;
    iVar6 = 5;
    uVar7 = 0x17;
  }
  Game_AssignPlanStepWeight(this,uVar7,piVar5);
  uVar2 = 0;
  if (iVar6 != 0) {
    piVar5 = local_e0 + 1;
    iVar3 = iVar6;
    do {
      iVar4 = *piVar5;
      piVar5 = piVar5 + 4;
      uVar2 = uVar2 + iVar4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (uVar2 != 0) {
      uVar2 = Random_Mod(uVar2);
      iVar3 = 0;
      piVar5 = local_e0 + 1;
      do {
        if ((int)uVar2 < *piVar5) break;
        uVar2 = uVar2 - *piVar5;
        iVar3 = iVar3 + 1;
        piVar5 = piVar5 + 4;
      } while (iVar3 < iVar6);
      if (iVar3 != iVar6) {
        iVar6 = local_e0[iVar3 * 4];
        param_1[3] = aiStack_d4[iVar3 * 4];
        *param_1 = iVar6;
        return 0;
      }
      param_1[3] = 0;
switchD_00501101_caseD_5:
      return 1;
    }
  }
  param_1[3] = 0;
  return 1;
}

