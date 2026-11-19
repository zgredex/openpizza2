// rea decompile_all
// name: UI_CreateAnimationWindow
// address: 0x531a50
// body: available
// range: 0x531a50-0x531b4f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
UI_CreateAnimationWindow(void *this,int param_1,int param_2,int param_3,LPCSTR param_4)

{
  undefined4 *puVar1;
  void *pvVar2;
  int local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Loads an .ani file and creates a movie window. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055abd6;
  local_c = ExceptionList;
  pvVar2 = *(void **)(*(int *)((int)this + 0x134) + 0x10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x98);
  local_4 = 0;
  if (local_10 == (void *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = Anim_Load(local_10,*(int *)((int)this + 0xdc),pvVar2,param_4,&local_14,0);
  }
  local_4 = 0xffffffff;
  if (local_14 != 0) {
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    ExceptionList = local_c;
    return 0;
  }
  pvVar2 = operator_new(0xbc);
  local_4 = 1;
  if (pvVar2 == (void *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = MovieWindow_Construct(pvVar2,param_1,param_2,param_3,1,puVar1,param_4,1,(int)this);
  }
  local_4 = 0xffffffff;
  UI_EnsureObjectArray(this,(int)puVar1,param_1);
  ExceptionList = local_c;
  return 1;
}

