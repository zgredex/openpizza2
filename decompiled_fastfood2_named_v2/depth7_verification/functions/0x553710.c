// rea decompile_all
// name: CRT_LCMapStringA
// address: 0x553710
// body: available
// range: 0x553710-0x55381f inclusive
// range: 0x553833-0x5538d3 inclusive
// range: 0x5538e6-0x553933 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __cdecl
CRT_LCMapStringA(LCID param_1,DWORD param_2,char *param_3,int param_4,LPWSTR param_5,int param_6,
                UINT param_7,int param_8)

{
  int iVar1;
  int iVar2;
  undefined1 unaff_DI;
  undefined1 uStack00000000;
  WCHAR aWStack_2e [13];
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
                    /* Locale-aware ANSI LCMapString wrapper with Wide/ANSI probing. */
  local_8 = 0xffffffff;
  puStack_c = &DAT_0055ce98;
  puStack_10 = &LAB_00553be0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_00585754 == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,&DAT_0057ca0c,1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_00585754 = 2;
    }
    else {
      DAT_00585754 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_005577aa(param_3,param_4);
  }
  if (DAT_00585754 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,(LPSTR)param_5,param_6);
    ExceptionList = local_14;
    return iVar1;
  }
  if (DAT_00585754 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_005857dc;
    }
    iVar1 = MultiByteToWideChar(param_7,(-(uint)(param_8 != 0) & 8) + 1,param_3,param_4,(LPWSTR)0x0,
                                0);
    if (iVar1 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    local_8 = 0;
    FUN_0054f110(unaff_DI);
    local_8 = 0xffffffff;
    if (&uStack00000000 == (undefined1 *)0x3c) {
      ExceptionList = local_14;
      return 0;
    }
    iVar2 = MultiByteToWideChar(param_7,1,param_3,param_4,aWStack_2e + -7,iVar1);
    if (iVar2 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    iVar2 = LCMapStringW(param_1,param_2,aWStack_2e + -7,iVar1,(LPWSTR)0x0,0);
    if (iVar2 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    if ((param_2 & 0x400) == 0) {
      local_8 = 1;
      FUN_0054f110(unaff_DI);
      local_8 = 0xffffffff;
      if (&uStack00000000 == (undefined1 *)0x3c) {
        ExceptionList = local_14;
        return 0;
      }
      iVar1 = LCMapStringW(param_1,param_2,aWStack_2e + -7,iVar1,aWStack_2e + -7,iVar2);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      if (param_6 == 0) {
        param_6 = 0;
        param_5 = (LPWSTR)0x0;
      }
      iVar2 = WideCharToMultiByte(param_7,0x220,aWStack_2e + -7,iVar2,(LPSTR)param_5,param_6,
                                  (LPCSTR)0x0,(LPBOOL)0x0);
      iVar1 = iVar2;
    }
    else {
      if (param_6 == 0) {
        ExceptionList = local_14;
        return iVar2;
      }
      if (param_6 < iVar2) {
        ExceptionList = local_14;
        return 0;
      }
      iVar1 = LCMapStringW(param_1,param_2,aWStack_2e + -7,iVar1,param_5,param_6);
    }
    if (iVar1 != 0) {
      ExceptionList = local_14;
      return iVar2;
    }
  }
  ExceptionList = local_14;
  return 0;
}

