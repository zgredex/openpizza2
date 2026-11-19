// rea decompile_all
// name: FUN_00555dd9
// address: 0x555dd9
// body: available
// range: 0x555dd9-0x555ed1 inclusive
// range: 0x555edd-0x555f21 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


BOOL __cdecl
FUN_00555dd9(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6,
            int param_7)

{
  WCHAR *pWVar1;
  BOOL BVar2;
  int iVar3;
  undefined1 unaff_DI;
  undefined1 uStack00000000;
  WCHAR aWStack_2a [5];
  WORD local_20 [2];
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0055d1a0;
  puStack_10 = &LAB_00553be0;
  local_14 = ExceptionList;
  local_1c = (undefined1 *)(aWStack_2a + -7);
  ExceptionList = &local_14;
  pWVar1 = aWStack_2a + -7;
  if (DAT_00585900 == 0) {
    iVar3 = 1;
    ExceptionList = &local_14;
    BVar2 = GetStringTypeW(1,L"",1,local_20);
    if (BVar2 == 0) {
      BVar2 = GetStringTypeA(0,1,&DAT_0057ca0c,1,local_20);
      if (BVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      iVar3 = 2;
    }
    DAT_00585900 = iVar3;
    pWVar1 = (WCHAR *)local_1c;
  }
  local_1c = (undefined1 *)pWVar1;
  if (DAT_00585900 == 2) {
    if (param_6 == 0) {
      param_6 = DAT_005857cc;
    }
    BVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
    ExceptionList = local_14;
    return BVar2;
  }
  if (DAT_00585900 == 1) {
    if (param_5 == 0) {
      param_5 = DAT_005857dc;
    }
    iVar3 = MultiByteToWideChar(param_5,(-(uint)(param_7 != 0) & 8) + 1,param_2,param_3,(LPWSTR)0x0,
                                0);
    if (iVar3 != 0) {
      local_8 = 0;
      __chkstk(unaff_DI);
      local_1c = (undefined1 *)(aWStack_2a + -7);
      _memset(aWStack_2a + -7,0,iVar3 * 2);
      local_8 = 0xffffffff;
      if ((&uStack00000000 != (undefined1 *)0x38) &&
         (iVar3 = MultiByteToWideChar(param_5,1,param_2,param_3,aWStack_2a + -7,iVar3), iVar3 != 0))
      {
        BVar2 = GetStringTypeW(param_1,aWStack_2a + -7,iVar3,param_4);
        ExceptionList = local_14;
        return BVar2;
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}

