// rea decompile_all
// name: FUN_00554784
// address: 0x554784
// body: available
// range: 0x554784-0x5548a8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __cdecl FUN_00554784(uint param_1,int param_2)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  DWORD DVar4;
  int iVar5;
  DWORD *pDVar6;
  HANDLE hFile;
  BOOL BVar7;
  undefined1 unaff_BP;
  int iVar8;
  char local_1008 [4064];
  undefined4 uStackY_28;
  
  FUN_0054f110(unaff_BP);
  iVar8 = 0;
  DVar1 = CRT_LseekLocked(param_1,0,1);
  if ((DVar1 == 0xffffffff) || (DVar2 = CRT_LseekLocked(param_1,0,2), DVar2 == 0xffffffff)) {
    iVar8 = -1;
  }
  else {
    DVar2 = param_2 - DVar2;
    if ((int)DVar2 < 1) {
      if ((int)DVar2 < 0) {
        CRT_LseekLocked(param_1,param_2,0);
        hFile = (HANDLE)CRT_GetOsHandle(param_1);
        BVar7 = SetEndOfFile(hFile);
        iVar8 = (BVar7 != 0) - 1;
        if (iVar8 == -1) {
          pDVar6 = CRT_GetErrnoPtr();
          *pDVar6 = 0xd;
          DVar2 = GetLastError();
          pDVar6 = CRT_GetDosErrnoPtr();
          *pDVar6 = DVar2;
        }
      }
    }
    else {
      _memset(local_1008,0,0x1000);
      uStackY_28 = 0x5547f1;
      iVar3 = FUN_00550c6a(param_1,0x8000);
      do {
        DVar4 = 0x1000;
        if ((int)DVar2 < 0x1000) {
          DVar4 = DVar2;
        }
        iVar5 = FUN_0054ffd0(param_1,local_1008,DVar4);
        if (iVar5 == -1) {
          pDVar6 = CRT_GetDosErrnoPtr();
          if (*pDVar6 == 5) {
            pDVar6 = CRT_GetErrnoPtr();
            *pDVar6 = 0xd;
          }
          iVar8 = -1;
          break;
        }
        DVar2 = DVar2 - iVar5;
      } while (0 < (int)DVar2);
      FUN_00550c6a(param_1,iVar3);
    }
    CRT_LseekLocked(param_1,DVar1,0);
  }
  return iVar8;
}

