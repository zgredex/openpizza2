// rea decompile_all
// name: Movie_Play
// address: 0x4ce9d0
// body: available
// range: 0x4ce9d0-0x4ceb74 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl Movie_Play(int param_1,char *param_2)

{
  void *this;
  undefined4 *puVar1;
  int iVar2;
  undefined4 *this_00;
  int iVar3;
  DWORD DVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Plays a fullscreen Bink movie until completion or exit. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558ceb;
  local_c = ExceptionList;
  DAT_0056b40c = 1;
  ExceptionList = &local_c;
  this = operator_new(0x11c);
  local_4 = 0;
  if (this == (void *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_00537230(this,800,600,0x10);
  }
  local_4 = 0xffffffff;
  FUN_005374b0((int)puVar1);
  iVar2 = FUN_00523bb0(DAT_0057c5e0,0,100,s_clipsprite_spr_0056b410,&LAB_004ce950);
  this_00 = (undefined4 *)FUN_00528040(DAT_0057c5e0,iVar2,(int *)0x0);
  DAT_0057df90 = this_00;
  FUN_00531bb0(this_00,100,0,0,param_2,(undefined4 *)0x1);
  UI_StartButtonMovie(DAT_0057df90,100,0);
  if (param_1 != 0) {
    iVar3 = FUN_005260e0(param_1);
    Window_HideWindowById(DAT_0057c5e0,iVar3);
  }
  FUN_00523900(DAT_0057c5e0,puVar1);
  Window_ProcessMessageQueue(DAT_0057c5e0,0);
  FUN_005238c0((int)DAT_0057c5e0);
  FUN_00547fd0((int)DAT_0057ba0c);
  Window_ShowWindowById(DAT_0057c5e0,iVar2);
  do {
    if (DAT_0056b40c == 0) break;
    Window_ProcessMessageQueue(DAT_0057c5e0,0);
    Sleep(1);
    DVar4 = WaitForSingleObject(DAT_0057c0d8,0);
  } while (DVar4 != 0);
  DAT_0057df90 = (undefined4 *)0x0;
  Window_DestroyChild(DAT_0057c5e0,this_00);
  if (param_1 != 0) {
    iVar2 = FUN_005260e0(param_1);
    Window_ShowWindowById(DAT_0057c5e0,iVar2);
  }
  FUN_00547e70(DAT_0057ba0c);
  ExceptionList = local_c;
  return;
}

