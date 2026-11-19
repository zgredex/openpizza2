// rea decompile_all
// name: FUN_00499f30
// address: 0x499f30
// body: available
// range: 0x499f30-0x49a03a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_00499f30(int param_1,byte *param_2,char *param_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  bool bVar12;
  byte local_100 [256];
  
  uVar6 = 0xffffffff;
  pcVar9 = param_3;
  do {
    pcVar10 = pcVar9;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = pcVar9 + 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar10;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pbVar8 = (byte *)(pcVar10 + -uVar6);
  pbVar5 = local_100;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pbVar5 = *(undefined4 *)pbVar8;
    pbVar8 = pbVar8 + 4;
    pbVar5 = pbVar5 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pbVar5 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    pbVar5 = pbVar5 + 1;
  }
  iVar3 = FUN_00488be0(DAT_0057c670,param_1);
LAB_00499f7f:
  iVar11 = 0;
  if (0 < *(int *)(iVar3 + 0x124)) {
    do {
      iVar4 = FUN_004017f0((void *)(iVar3 + 0x110),iVar11,(int *)0x0);
      pbVar8 = local_100;
      pbVar5 = (byte *)(iVar4 + 4);
      do {
        bVar2 = *pbVar5;
        bVar12 = bVar2 < *pbVar8;
        if (bVar2 != *pbVar8) {
LAB_00499fc6:
          iVar4 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          goto LAB_00499fcb;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar5[1];
        bVar12 = bVar2 < pbVar8[1];
        if (bVar2 != pbVar8[1]) goto LAB_00499fc6;
        pbVar5 = pbVar5 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar2 != 0);
      iVar4 = 0;
LAB_00499fcb:
      if (iVar4 == 0) goto LAB_00499fdc;
      iVar11 = iVar11 + 1;
      if (*(int *)(iVar3 + 0x124) <= iVar11) break;
    } while( true );
  }
  uVar6 = 0xffffffff;
  pbVar8 = local_100;
  do {
    pbVar5 = pbVar8;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pbVar5 = pbVar8 + 1;
    bVar2 = *pbVar8;
    pbVar8 = pbVar5;
  } while (bVar2 != 0);
  uVar6 = ~uVar6;
  pbVar8 = pbVar5 + -uVar6;
  for (uVar7 = uVar6 >> 2; param_2 = param_2 + 4, uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)param_2 = *(undefined4 *)pbVar8;
    pbVar8 = pbVar8 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *param_2 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    param_2 = param_2 + 1;
  }
  return;
LAB_00499fdc:
  FUN_0054dd83(local_100,(byte *)s__s__d_00568964,param_3);
  goto LAB_00499f7f;
}

