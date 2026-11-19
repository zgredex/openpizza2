// rea decompile_all
// name: FUN_0055752d
// address: 0x55752d
// body: available
// range: 0x55752d-0x5576e3 inclusive
// range: 0x5576fa-0x557752 inclusive
// range: 0x557765-0x5577a9 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __cdecl
FUN_0055752d(LCID param_1,DWORD param_2,byte *param_3,int param_4,byte *param_5,int param_6,
            UINT param_7)

{
  int iVar1;
  BOOL BVar2;
  BYTE *pBVar3;
  int iVar4;
  undefined1 unaff_DI;
  undefined1 uStack00000000;
  BYTE aBStack_42 [2];
  _cpinfo local_40;
  undefined1 *local_2c;
  PCNZWCH local_28;
  int local_24;
  int local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0055d330;
  puStack_10 = &LAB_00553be0;
  local_14 = ExceptionList;
  local_1c = (&local_40)[-1].DefaultChar;
  ExceptionList = &local_14;
  pBVar3 = (&local_40)[-1].DefaultChar;
  if (DAT_005859a0 == 0) {
    ExceptionList = &local_14;
    iVar1 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar1 == 0) {
      iVar1 = CompareStringA(0,0,&DAT_0057ca0c,1,&DAT_0057ca0c,1);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_005859a0 = 2;
      pBVar3 = local_1c;
    }
    else {
      DAT_005859a0 = 1;
      pBVar3 = local_1c;
    }
  }
  local_1c = pBVar3;
  if (0 < param_4) {
    param_4 = FUN_005577aa((char *)param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_005577aa((char *)param_5,param_6);
  }
  if (DAT_005859a0 == 2) {
    iVar1 = CompareStringA(param_1,param_2,(PCNZCH)param_3,param_4,(PCNZCH)param_5,param_6);
    ExceptionList = local_14;
    return iVar1;
  }
  if (DAT_005859a0 != 1) {
    ExceptionList = local_14;
    return 0;
  }
  if (param_7 == 0) {
    param_7 = DAT_005857dc;
  }
  if ((param_4 != 0) && (param_6 != 0)) {
LAB_005576ab:
    local_20 = MultiByteToWideChar(param_7,9,(LPCSTR)param_3,param_4,(LPWSTR)0x0,0);
    if (local_20 != 0) {
      local_8 = 0;
      FUN_0054f110(unaff_DI);
      local_8 = 0xffffffff;
      if ((&uStack00000000 != (undefined1 *)0x50) &&
         (local_28 = (PCNZWCH)(&local_40)[-1].DefaultChar, local_1c = (&local_40)[-1].DefaultChar,
         iVar1 = MultiByteToWideChar(param_7,1,(LPCSTR)param_3,param_4,
                                     (LPWSTR)(&local_40)[-1].DefaultChar,local_20), iVar1 != 0)) {
        iVar1 = MultiByteToWideChar(param_7,9,(LPCSTR)param_5,param_6,(LPWSTR)0x0,0);
        if (iVar1 != 0) {
          local_8 = 1;
          local_24 = iVar1;
          FUN_0054f110(unaff_DI);
          local_8 = 0xffffffff;
          if ((&uStack00000000 != (undefined1 *)0x50) &&
             (local_2c = (&local_40)[-1].DefaultChar, local_1c = (&local_40)[-1].DefaultChar,
             iVar4 = MultiByteToWideChar(param_7,1,(LPCSTR)param_5,param_6,
                                         (LPWSTR)(&local_40)[-1].DefaultChar,iVar1), iVar4 != 0)) {
            iVar1 = CompareStringW(param_1,param_2,local_28,local_20,
                                   (PCNZWCH)(&local_40)[-1].DefaultChar,iVar1);
            ExceptionList = local_14;
            return iVar1;
          }
        }
      }
    }
    ExceptionList = local_14;
    return 0;
  }
  if (param_4 == param_6) {
    ExceptionList = local_14;
    return 2;
  }
  if (1 < param_6) {
    ExceptionList = local_14;
    return 1;
  }
  if (param_4 < 2) {
    BVar2 = GetCPInfo(param_7,&local_40);
    if (BVar2 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    if (param_4 < 1) {
      if (0 < param_6) {
        if (local_40.MaxCharSize < 2) {
          ExceptionList = local_14;
          return 1;
        }
        pBVar3 = local_40.LeadByte;
        while( true ) {
          if (local_40.LeadByte[0] == 0) {
            ExceptionList = local_14;
            return 1;
          }
          if (pBVar3[1] == 0) break;
          if ((*pBVar3 <= *param_5) && (*param_5 <= pBVar3[1])) {
            ExceptionList = local_14;
            return 2;
          }
          pBVar3 = pBVar3 + 2;
          local_40.LeadByte[0] = *pBVar3;
        }
        ExceptionList = local_14;
        return 1;
      }
      goto LAB_005576ab;
    }
    if (1 < local_40.MaxCharSize) {
      pBVar3 = local_40.LeadByte;
      while ((local_40.LeadByte[0] != 0 && (pBVar3[1] != 0))) {
        if ((*pBVar3 <= *param_3) && (*param_3 <= pBVar3[1])) {
          ExceptionList = local_14;
          return 2;
        }
        pBVar3 = pBVar3 + 2;
        local_40.LeadByte[0] = *pBVar3;
      }
    }
  }
  ExceptionList = local_14;
  return 3;
}

