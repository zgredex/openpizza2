// rea decompile_all
// name: City_OpenBuildingDirectory
// address: 0x48a4c0
// body: available
// range: 0x48a4c0-0x48a59c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall City_OpenBuildingDirectory(void *param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Opens a sorted directory of the player's city buildings. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005583ab;
  local_c = ExceptionList;
  if (*(int *)((int)param_1 + 0x290) != 4) {
    ExceptionList = &local_c;
    *(undefined4 *)((int)param_1 + 0x21c) = 0;
    *(undefined4 *)((int)param_1 + 0x2da8) = 1;
    pvVar1 = operator_new(0x1c);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = List_Construct(pvVar1,0);
    }
    local_4 = 0xffffffff;
    pvVar1 = (void *)IDMap_Lookup((void *)((int)param_1 + 4),*(int *)((int)param_1 + 0x2f4),
                                  (int *)0x0);
    if (pvVar1 != (void *)0x0) {
      City_BuildObjectListEntries(pvVar1,puVar2);
      CRT_QSort((int *)puVar2[1],(undefined4 *)puVar2[5],4,&LAB_0048a490);
      UI_ShowScrollingListDialog(param_1,0xfffe79d4,DAT_00581b70,DAT_00580f08,(int)puVar2,-1,0);
      *(undefined4 *)((int)param_1 + 0x278) = 0;
    }
  }
  ExceptionList = local_c;
  return;
}

