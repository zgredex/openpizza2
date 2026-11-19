// rea decompile_all
// name: DebugConsole_Printf
// address: 0x54a660
// body: available
// range: 0x54a660-0x54a766 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl DebugConsole_Printf(int param_1,undefined4 param_2,byte *param_3,undefined4 param_4)

{
  char cVar1;
  HWND pHVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 *puVar9;
  UINT UVar10;
  WPARAM WVar11;
  undefined4 local_844;
  undefined4 local_840;
  undefined4 local_83c [5];
  undefined4 local_828;
  char local_800 [2048];
  
                    /* Formats and appends a colored line to the debug console log. */
  if (*(int *)(param_1 + 4) != 0) {
    FUN_0054f084(local_800,param_3,&param_4);
    uVar3 = 0xffffffff;
    pcVar6 = &DAT_0056832c;
    do {
      pcVar8 = pcVar6;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar8 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar8;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar4 = -1;
    pcVar6 = local_800;
    do {
      pcVar7 = pcVar6;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar7;
    } while (cVar1 != '\0');
    pcVar6 = pcVar8 + -uVar3;
    pcVar8 = pcVar7 + -1;
    for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar8 = pcVar8 + 4;
    }
    pHVar2 = *(HWND *)(param_1 + 4);
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar8 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 1;
    }
    puVar9 = local_83c;
    for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    puVar9 = &local_844;
    local_828 = param_2;
    WVar11 = 0;
    UVar10 = 0x437;
    local_83c[0] = 0x3c;
    local_83c[1] = 0x40000000;
    local_83c[2] = 0;
    local_844 = 0x100000;
    local_840 = 0x100000;
    pHVar2 = GetDlgItem(pHVar2,0x3ef);
    SendMessageA(pHVar2,UVar10,WVar11,(LPARAM)puVar9);
    puVar9 = local_83c;
    WVar11 = 1;
    UVar10 = 0x444;
    pHVar2 = GetDlgItem(*(HWND *)(param_1 + 4),0x3ef);
    SendMessageA(pHVar2,UVar10,WVar11,(LPARAM)puVar9);
    pcVar6 = local_800;
    WVar11 = 0;
    UVar10 = 0xc2;
    pHVar2 = GetDlgItem(*(HWND *)(param_1 + 4),0x3ef);
    SendMessageA(pHVar2,UVar10,WVar11,(LPARAM)pcVar6);
  }
  return;
}

