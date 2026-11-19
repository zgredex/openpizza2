// rea decompile_all
// name: FUN_004dd8f0
// address: 0x4dd8f0
// body: available
// range: 0x4dd8f0-0x4ddaaf inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004dd8f0(void *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  byte *pbVar6;
  void *pvVar7;
  int iVar8;
  float fVar9;
  int iVar10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00559331;
  local_c = ExceptionList;
  uVar1 = *(undefined4 *)((int)param_1 + 0x108);
  uVar2 = *(undefined4 *)((int)param_1 + 0x10c);
  ExceptionList = &local_c;
  *(undefined4 *)((int)param_1 + 0x108) = 0;
  *(undefined4 *)((int)param_1 + 0x10c) = 0x412e8480;
  pvVar4 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0
                               );
  FUN_004dc0f0(pvVar4,(int)param_1);
  *(undefined4 *)((int)param_1 + 0x108) = uVar1;
  *(undefined4 *)((int)param_1 + 0x10c) = uVar2;
  pvVar4 = operator_new(0x330);
  local_4 = 0;
  if (pvVar4 == (void *)0x0) {
    pbVar6 = (byte *)0x0;
  }
  else {
    iVar3 = *(int *)((int)param_1 + 0x48);
    iVar10 = 1;
    fVar9 = *(float *)(DAT_0057c670 + 0x2f4);
    iVar8 = 2;
    uVar5 = FUN_004034d0(0,7);
    pbVar6 = Recipe_CreateGenerated(pvVar4,iVar3,uVar5,iVar8,fVar9,iVar10);
  }
  pvVar4 = (void *)((int)param_1 + 0x110);
  local_4 = 0xffffffff;
  FUN_004014b0(pvVar4,pbVar6);
  FUN_004e3460(param_1,(int)pbVar6,1);
  pvVar7 = operator_new(0x330);
  local_4 = 1;
  if (pvVar7 == (void *)0x0) {
    pbVar6 = (byte *)0x0;
  }
  else {
    iVar3 = *(int *)((int)param_1 + 0x48);
    iVar10 = 2;
    fVar9 = *(float *)(DAT_0057c670 + 0x2f4);
    iVar8 = 2;
    uVar5 = FUN_004034d0(0,7);
    pbVar6 = Recipe_CreateGenerated(pvVar7,iVar3,uVar5,iVar8,fVar9,iVar10);
  }
  local_4 = 0xffffffff;
  FUN_004014b0(pvVar4,pbVar6);
  FUN_004e3460(param_1,(int)pbVar6,1);
  pvVar7 = operator_new(0x330);
  local_4 = 2;
  if (pvVar7 == (void *)0x0) {
    pbVar6 = (byte *)0x0;
  }
  else {
    iVar3 = *(int *)((int)param_1 + 0x48);
    iVar10 = 3;
    fVar9 = *(float *)(DAT_0057c670 + 0x2f4);
    iVar8 = 2;
    uVar5 = FUN_004034d0(0,7);
    pbVar6 = Recipe_CreateGenerated(pvVar7,iVar3,uVar5,iVar8,fVar9,iVar10);
  }
  local_4 = 0xffffffff;
  FUN_004014b0(pvVar4,pbVar6);
  FUN_004e3460(param_1,(int)pbVar6,1);
  ExceptionList = local_c;
  return;
}

