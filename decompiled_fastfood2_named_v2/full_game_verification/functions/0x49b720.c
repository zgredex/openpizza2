// rea decompile_all
// name: SaveMenu_ScanMenuFileList
// address: 0x49b720
// body: available
// range: 0x49b720-0x49b87f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 SaveMenu_ScanMenuFileList(void)

{
  char cVar1;
  void *pvVar2;
  HANDLE pvVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  uint local_324 [5];
  undefined1 local_310 [260];
  char local_20c [512];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Scans and builds the saved-menu file list. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005586fc;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = operator_new(0x1c);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    DAT_0057ca8c = (undefined4 *)0x0;
  }
  else {
    DAT_0057ca8c = List_Construct(pvVar2,0);
  }
  local_4 = 0xffffffff;
  pvVar3 = CRT_FindFirst(s_save_menu___men_00568a34,local_324);
  if (pvVar3 == (HANDLE)0xffffffff) {
    ExceptionList = local_c;
    return 0;
  }
  do {
    String_Format(local_20c,&DAT_005630d0,local_310);
    pcVar4 = _strchr(local_20c,0x2e);
    uVar6 = 0xffffffff;
    pcVar8 = &DAT_0057ca0c;
    do {
      pcVar9 = pcVar8;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar9 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar9;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar8 = pcVar9 + -uVar6;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar4 = pcVar4 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar4 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar4 = pcVar4 + 1;
    }
    pvVar2 = operator_new(0x58);
    local_4 = 1;
    if (pvVar2 == (void *)0x0) {
      pcVar4 = (char *)0x0;
    }
    else {
      pcVar4 = UI_ListEntry_Construct(pvVar2,local_20c,0);
    }
    local_4 = 0xffffffff;
    List_Add(DAT_0057ca8c,pcVar4);
    iVar5 = CRT_FindNext(pvVar3,local_324);
    if (iVar5 == -1) {
      CRT_FindClose(pvVar3);
      ExceptionList = local_c;
      return 1;
    }
  } while( true );
}

