// rea decompile_all
// name: ResourceManager_FindExtensionAlias
// address: 0x402ad0
// body: available
// range: 0x402ad0-0x402b75 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall ResourceManager_FindExtensionAlias(void *this,char *param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  byte *pbVar9;
  char *pcVar10;
  bool bVar11;
  undefined4 local_104;
  
                    /* Finds the registered directory alias for a file extension. */
  iVar3 = *(int *)((int)this + 0x1ab4);
  uVar6 = 0xffffffff;
  do {
    pcVar8 = param_1;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar8 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar8;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar8 = pcVar8 + -uVar6;
  pcVar10 = (char *)&local_104;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar10 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar10 = pcVar10 + 1;
  }
  FUN_0054ee99(&local_104);
  do {
    if (iVar3 == 0) {
      return 0;
    }
    pbVar9 = (byte *)&local_104;
    pbVar4 = (byte *)(iVar3 + 0x40);
    do {
      bVar2 = *pbVar4;
      bVar11 = bVar2 < *pbVar9;
      if (bVar2 != *pbVar9) {
LAB_00402b48:
        iVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_00402b4d;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar4[1];
      bVar11 = bVar2 < pbVar9[1];
      if (bVar2 != pbVar9[1]) goto LAB_00402b48;
      pbVar4 = pbVar4 + 2;
      pbVar9 = pbVar9 + 2;
    } while (bVar2 != 0);
    iVar5 = 0;
LAB_00402b4d:
    if (iVar5 == 0) {
      return iVar3;
    }
    iVar3 = *(int *)(iVar3 + 0x50);
  } while( true );
}

