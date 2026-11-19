// rea decompile_all
// name: FUN_00540510
// address: 0x540510
// body: available
// range: 0x540510-0x5405a8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_00540510(void *this,char *param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  char *pcVar8;
  byte *pbVar9;
  char *pcVar10;
  bool bVar11;
  undefined4 local_10;
  
  uVar4 = 0xffffffff;
  do {
    pcVar8 = param_1;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar8 = pcVar8 + -uVar4;
  pcVar10 = (char *)&local_10;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar10 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar10 = pcVar10 + 1;
  }
  FUN_0054ee99(&local_10);
  iVar3 = *(int *)((int)this + 0x628);
  do {
    if (iVar3 == 0) {
      return 0;
    }
    pbVar9 = (byte *)&local_10;
    pbVar6 = (byte *)(iVar3 + 0x40);
    do {
      bVar2 = *pbVar6;
      bVar11 = bVar2 < *pbVar9;
      if (bVar2 != *pbVar9) {
LAB_00540583:
        iVar7 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_00540588;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar6[1];
      bVar11 = bVar2 < pbVar9[1];
      if (bVar2 != pbVar9[1]) goto LAB_00540583;
      pbVar6 = pbVar6 + 2;
      pbVar9 = pbVar9 + 2;
    } while (bVar2 != 0);
    iVar7 = 0;
LAB_00540588:
    if (iVar7 == 0) {
      return iVar3;
    }
    iVar3 = *(int *)(iVar3 + 0x50);
  } while( true );
}

