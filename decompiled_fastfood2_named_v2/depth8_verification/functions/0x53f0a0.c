// rea decompile_all
// name: FUN_0053f0a0
// address: 0x53f0a0
// body: available
// range: 0x53f0a0-0x53f1b3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_0053f0a0(undefined4 *param_1,char *param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  char *pcVar8;
  byte *pbVar9;
  char *pcVar10;
  byte local_800 [1024];
  char local_400 [1024];
  
  pcVar3 = FUN_0053f1c0(param_3);
  uVar4 = 0xffffffff;
  do {
    pcVar8 = pcVar3;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pbVar7 = (byte *)(pcVar8 + -uVar4);
  pbVar9 = local_800;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pbVar9 = *(undefined4 *)pbVar7;
    pbVar7 = pbVar7 + 4;
    pbVar9 = pbVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pbVar9 = *pbVar7;
    pbVar7 = pbVar7 + 1;
    pbVar9 = pbVar9 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar3 = &DAT_00574c10;
  do {
    pcVar8 = pcVar3;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pbVar7 = local_800;
  do {
    pbVar9 = pbVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pbVar9 = pbVar7 + 1;
    bVar2 = *pbVar7;
    pbVar7 = pbVar9;
  } while (bVar2 != 0);
  pbVar7 = (byte *)(pcVar8 + -uVar4);
  pbVar9 = pbVar9 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pbVar9 = *(undefined4 *)pbVar7;
    pbVar7 = pbVar7 + 4;
    pbVar9 = pbVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pbVar9 = *pbVar7;
    pbVar7 = pbVar7 + 1;
    pbVar9 = pbVar9 + 1;
  }
  uVar4 = 0xffffffff;
  do {
    pcVar3 = param_2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar3 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar3;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pbVar7 = local_800;
  do {
    pbVar9 = pbVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pbVar9 = pbVar7 + 1;
    bVar2 = *pbVar7;
    pbVar7 = pbVar9;
  } while (bVar2 != 0);
  pbVar7 = (byte *)(pcVar3 + -uVar4);
  pbVar9 = pbVar9 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pbVar9 = *(undefined4 *)pbVar7;
    pbVar7 = pbVar7 + 4;
    pbVar9 = pbVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pbVar9 = *pbVar7;
    pbVar7 = pbVar7 + 1;
    pbVar9 = pbVar9 + 1;
  }
  CRT_Vsprintf(local_400,local_800,&param_4);
  if ((LPVOID)*param_1 != (LPVOID)0x0) {
    FUN_0054dd78((LPVOID)*param_1);
  }
  uVar4 = 0xffffffff;
  pcVar3 = local_400;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = operator_new(~uVar4);
  *param_1 = pcVar3;
  if (pcVar3 != (char *)0x0) {
    uVar4 = 0xffffffff;
    pcVar8 = local_400;
    do {
      pcVar10 = pcVar8;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar10 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar10;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar8 = pcVar10 + -uVar4;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar3 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar3 = pcVar3 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar3 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar3 = pcVar3 + 1;
    }
  }
  return;
}

