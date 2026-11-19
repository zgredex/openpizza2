// rea decompile_all
// name: RecipeMenu_BuildOnMenuList
// address: 0x49b4e0
// body: available
// range: 0x49b4e0-0x49b5e4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int RecipeMenu_BuildOnMenuList(void)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Rebuilds the temporary list of the player's on-menu recipes. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005586b6;
  local_c = ExceptionList;
  iVar1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar6 = 0;
  local_18 = 0;
  iVar2 = *(int *)(iVar1 + 0x124);
  ExceptionList = &local_c;
  pvVar3 = operator_new(0x1c);
  local_4 = 0;
  if (pvVar3 == (void *)0x0) {
    DAT_0057ca8c = (undefined4 *)0x0;
  }
  else {
    DAT_0057ca8c = FUN_004013a0(pvVar3,0);
  }
  local_4 = 0xffffffff;
  if (iVar2 < 1) {
    ExceptionList = local_c;
    return 0;
  }
  do {
    iVar4 = FUN_004017f0((void *)(iVar1 + 0x110),iVar6,(int *)0x0);
    if (*(char *)(iVar4 + 0x1dc) == '\x01') {
      pvVar3 = operator_new(0x58);
      local_4 = 1;
      if (pvVar3 == (void *)0x0) {
        pcVar5 = (char *)0x0;
      }
      else {
        pcVar5 = UI_ListEntry_Construct(pvVar3,(char *)(iVar4 + 4),iVar6);
      }
      local_4 = 0xffffffff;
      FUN_004014b0(DAT_0057ca8c,pcVar5);
      local_18 = local_18 + 1;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < iVar2);
  ExceptionList = local_c;
  return local_18;
}

