// rea decompile_all
// name: FUN_004e3c00
// address: 0x4e3c00
// body: available
// range: 0x4e3c00-0x4e3d26 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004e3c00(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  char *pcVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00559526;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  if (*(undefined4 **)(param_1 + 0x1d4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x1d4))(1);
  }
  iVar3 = FUN_00482820(DAT_0057c670);
  if (*(int *)(param_1 + 0x48) != iVar3) {
    uVar7 = *(uint *)(iVar2 + 0x1148);
    FUN_004034d0(0,2);
    pvVar4 = operator_new(0x330);
    uStack_4 = 1;
    if (pvVar4 == (void *)0x0) {
      pbVar6 = (byte *)0x0;
    }
    else {
      pbVar6 = FUN_00510c90(pvVar4,*(int *)(param_1 + 0x48),uVar7,2,*(float *)(iVar2 + 0xc1c),-1);
    }
    *(byte **)(param_1 + 0x1d4) = pbVar6;
    ExceptionList = pvStack_c;
    return;
  }
  pvVar4 = operator_new(0x330);
  uStack_4 = 0;
  if (pvVar4 == (void *)0x0) {
    pcVar5 = (char *)0x0;
  }
  else {
    pcVar5 = (char *)FUN_0050fc20(pvVar4,(int *)0x0,'\0');
  }
  uVar7 = 0xffffffff;
  pcVar10 = (char *)(&DAT_005834d4)[*(int *)(iVar2 + 0x1148)];
  do {
    pcVar9 = pcVar10;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pcVar9 = pcVar10 + 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar9;
  } while (cVar1 != '\0');
  uVar7 = ~uVar7;
  pcVar9 = pcVar9 + -uVar7;
  pcVar10 = pcVar5;
  for (uVar8 = uVar7 >> 2; pcVar10 = pcVar10 + 4, uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar10 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    pcVar10 = pcVar10 + 1;
  }
  *(char **)(param_1 + 0x1d4) = pcVar5;
  ExceptionList = pvStack_c;
  return;
}

