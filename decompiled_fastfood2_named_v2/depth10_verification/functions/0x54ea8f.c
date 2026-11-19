// rea decompile_all
// name: FUN_0054ea8f
// address: 0x54ea8f
// body: available
// range: 0x54ea8f-0x54ebe2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_0054ea8f(int *param_1,undefined4 *param_2,uint param_3,undefined *param_4)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 local_fc [30];
  int local_84 [30];
  int *local_c;
  int local_8;
  
  if ((param_2 < (undefined4 *)0x2) || (param_3 == 0)) {
    return;
  }
  local_8 = 0;
  iVar4 = (int)param_2 + -1;
  param_2 = local_fc;
  piVar5 = (int *)(iVar4 * param_3 + (int)param_1);
  piVar3 = param_1;
  param_1 = local_84;
LAB_0054eace:
  uVar2 = (uint)((int)piVar5 - (int)piVar3) / param_3 + 1;
  if (8 < uVar2) {
    FUN_0054ec31((undefined1 *)((uVar2 >> 1) * param_3 + (int)piVar3),(undefined1 *)piVar3,param_3);
    piVar6 = (int *)(param_3 + (int)piVar5);
    local_c = piVar3;
LAB_0054eb25:
    local_c = (int *)((int)local_c + param_3);
    if (local_c <= piVar5) goto code_r0x0054eb32;
    goto LAB_0054eb3d;
  }
  FUN_0054ebe3((undefined1 *)piVar3,(undefined1 *)piVar5,param_3,param_4);
  goto LAB_0054eaed;
code_r0x0054eb32:
  iVar4 = (*(code *)param_4)(local_c,piVar3);
  if (iVar4 < 1) goto LAB_0054eb25;
LAB_0054eb3d:
  do {
    piVar6 = (int *)((int)piVar6 - param_3);
    if (piVar6 <= piVar3) break;
    iVar4 = (*(code *)param_4)(piVar6,piVar3);
  } while (-1 < iVar4);
  if (local_c <= piVar6) {
    FUN_0054ec31((undefined1 *)local_c,(undefined1 *)piVar6,param_3);
    goto LAB_0054eb25;
  }
  FUN_0054ec31((undefined1 *)piVar3,(undefined1 *)piVar6,param_3);
  piVar1 = local_c;
  if ((int)((int)piVar6 + (-1 - (int)piVar3)) < (int)piVar5 - (int)local_c) {
    if (local_c < piVar5) {
      local_8 = local_8 + 1;
      *param_2 = local_c;
      *param_1 = (int)piVar5;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    if ((int *)(param_3 + (int)piVar3) < piVar6) {
      piVar5 = (int *)((int)piVar6 - param_3);
      goto LAB_0054eace;
    }
  }
  else {
    if ((int *)((int)piVar3 + param_3) < piVar6) {
      local_8 = local_8 + 1;
      *param_2 = piVar3;
      *param_1 = (int)piVar6 - param_3;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    if (piVar1 < piVar5) {
      piVar3 = piVar1;
      goto LAB_0054eace;
    }
  }
LAB_0054eaed:
  local_8 = local_8 + -1;
  param_2 = param_2 + -1;
  param_1 = param_1 + -1;
  if (local_8 < 0) {
    return;
  }
  piVar5 = (int *)*param_1;
  piVar3 = (int *)*param_2;
  goto LAB_0054eace;
}

