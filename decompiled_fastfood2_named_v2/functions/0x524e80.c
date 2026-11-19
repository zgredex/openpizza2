// rea decompile_all
// name: FUN_00524e80
// address: 0x524e80
// body: available
// range: 0x524e80-0x524fc2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00524e80(void *this,void *param_1,void **param_2,int *param_3)

{
  HWND hWnd;
  int iVar1;
  BOOL BVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 uStack00000000;
  tagOFNA local_150 [3];
  
  if ((param_1 == (void *)0x0) && (param_1 = *(void **)((int)this + 0x228), param_1 == (void *)0x0))
  {
    iVar4 = *(int *)((int)this + 0x23c) + -1;
    if (iVar4 < 0) {
      return;
    }
    puVar3 = (undefined4 *)((int)this + iVar4 * 4 + 0x14);
    while (((param_1 = (void *)*puVar3, param_1 == (void *)0x0 ||
            (*(int *)((int)param_1 + 0x4c) == 0)) ||
           (iVar1 = FUN_0052ffa0(param_1,param_3), iVar1 == 0))) {
      iVar4 = iVar4 + -1;
      puVar3 = puVar3 + -1;
      if (iVar4 < 0) {
        return;
      }
    }
    if (iVar4 < 0) {
      return;
    }
    if (param_1 == (void *)0x0) {
      return;
    }
  }
  if (param_2 == (void **)0x0) {
    hWnd = *(HWND *)((int)this + 0x8320);
    local_150[0].pvReserved._0_1_ = 0;
    local_150[0].hInstance = (HINSTANCE)GetWindowLongA(hWnd,-6);
    local_150[0].lpstrFile = (LPSTR)&local_150[0].pvReserved;
    local_150[0].lStructSize = 0x4c;
    local_150[0].lpstrFilter = s_subedit_dialog_file____dlg__00574258;
    local_150[0].lpstrCustomFilter = (LPSTR)0x0;
    local_150[0].nMaxCustFilter = 0;
    local_150[0].nFilterIndex = 1;
    local_150[0].nMaxFile = 0x104;
    local_150[0].lpstrFileTitle = (LPSTR)0x0;
    local_150[0].nMaxFileTitle = 0;
    local_150[0].lpstrInitialDir = (LPCSTR)0x0;
    local_150[0].lpstrTitle = s_Specify_file_to_export_window_di_00574230;
    local_150[0].Flags = 0xc;
    local_150[0].nFileOffset = 0;
    local_150[0].nFileExtension = 0;
    local_150[0].lpstrDefExt = &DAT_0057422c;
    local_150[0].lCustData = 0;
    local_150[0].lpfnHook = (LPOFNHOOKPROC)0x0;
    local_150[0].lpTemplateName = (LPCSTR)0x0;
    local_150[0].hwndOwner = hWnd;
    BVar2 = GetSaveFileNameA(local_150);
    if (BVar2 == 0) {
      return;
    }
    param_2 = &local_150[0].pvReserved;
    if (&uStack00000000 == (undefined1 *)0x104) {
      return;
    }
  }
  FUN_00531fe0(param_1,(LPCSTR)param_2);
  return;
}

