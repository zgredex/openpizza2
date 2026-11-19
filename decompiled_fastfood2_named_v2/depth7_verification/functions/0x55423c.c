// rea decompile_all
// name: CRT_NMsgWrite
// address: 0x55423c
// body: available
// range: 0x55423c-0x55438e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl CRT_NMsgWrite(DWORD param_1)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  size_t sVar4;
  HANDLE hFile;
  int iVar5;
  uint *_Dest;
  undefined1 auStackY_1e3 [7];
  LPCVOID lpBuffer;
  LPOVERLAPPED lpOverlapped;
  uint local_1a8 [65];
  uint local_a4 [40];
  
                    /* Reports MSVC runtime errors to stderr or a message box. */
  iVar5 = 0;
  pDVar2 = &DAT_005770d8;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while ((int)pDVar2 < 0x577168);
  if (param_1 == (&DAT_005770d8)[iVar5 * 2]) {
    if ((DAT_0058565c == 1) || ((DAT_0058565c == 0 && (DAT_00576744 == 1)))) {
      pDVar2 = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x5770dc);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,sVar4,pDVar2,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_00553620(local_1a8,(uint *)"<program name unknown>");
      }
      _Dest = local_1a8;
      sVar4 = _strlen((char *)local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen((char *)local_1a8);
        _Dest = (uint *)(auStackY_1e3 + sVar4);
        _strncpy((char *)_Dest,"...",3);
      }
      FUN_00553620(local_a4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_00553630(local_a4,_Dest);
      FUN_00553630(local_a4,(uint *)&DAT_0055d160);
      FUN_00553630(local_a4,*(uint **)(iVar5 * 8 + 0x5770dc));
      auStackY_1e3._3_4_ = 0x554360;
      FUN_00556995(local_a4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}

