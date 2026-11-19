// rea decompile_all
// name: SubMenu_InitSelectedPage
// address: 0x484f60
// body: available
// range: 0x484f60-0x485083 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __fastcall SubMenu_InitSelectedPage(void *param_1)

{
  int iVar1;
  void *pvVar2;
  void *local_4;
  
                    /* Initializes the selected submenu page. */
  local_4 = param_1;
  if (*(int *)((int)param_1 + 0x268) != 0) {
    Game_CloseSelectionDialog((int)param_1);
  }
  switch(*(undefined4 *)((int)param_1 + *(int *)((int)param_1 + 0x290) * 4 + 0x298)) {
  case 1:
    break;
  case 2:
    pvVar2 = SubMenu_BuildSaveGame((int *)&local_4);
    LoadGameMenu_InitSlotList(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 3:
    pvVar2 = SoundOptionsPage_Create((int *)&local_4);
    SoundOptions_Init(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 4:
    pvVar2 = GraphicsOptionsPage_Create((int *)&local_4);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 5:
    pvVar2 = GameOptionsPage_Create((int *)&local_4);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  default:
    *(void **)((int)param_1 + 0x264) = local_4;
    return local_4;
  }
  iVar1 = SaveGame_AnyExist();
  if (iVar1 == 0) {
    Game_ShowConfirmationDialog
              (param_1,0xfffe7978,DAT_005825a4,DAT_00580bb4,*(undefined4 *)((int)param_1 + 0x25c));
    *(undefined4 *)((int)param_1 + 0x264) = *(undefined4 *)((int)param_1 + 0x268);
    return local_4;
  }
  pvVar2 = SubMenu_BuildLoadSavegame((int *)&local_4);
  SaveGameMenu_Init(pvVar2);
  *(void **)((int)param_1 + 0x264) = pvVar2;
  return local_4;
}

