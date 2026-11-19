// rea decompile_all
// name: Renderer_FlipPrimarySurface
// address: 0x539860
// body: available
// range: 0x539860-0x539923 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Renderer_FlipPrimarySurface(int param_1)

{
  int *piVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 1;
  if (DAT_005844fc != 0) {
    DVar2 = timeGetTime();
    uVar4 = DVar2 + 30000;
    while ((DAT_00584500 != 0 && (DVar2 = timeGetTime(), DVar2 < uVar4))) {
      Win32_PumpMessages();
      Sleep(0x14);
    }
    CRT_Exit(0x32);
  }
  while( true ) {
    while( true ) {
      while( true ) {
        piVar1 = *(int **)(*(int *)(param_1 + 0x40) + 4);
        iVar3 = (**(code **)(*piVar1 + 0x2c))(piVar1,0,1);
        if (-0x7789fe3e < iVar3) {
          if (iVar3 == 0) {
            *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) ^ 1;
            return;
          }
          return;
        }
        if (iVar3 != -0x7789fe3e) break;
        if (uVar4 == 0) {
          Thread_WaitForExit(param_1);
        }
        else {
          Thread_WaitForExit(param_1);
          uVar4 = 0;
        }
      }
      if (iVar3 != -0x7789ff1f) break;
      iVar3 = (**(code **)(*(int *)**(undefined4 **)(param_1 + 0x40) + 0x50))
                        ((int *)**(undefined4 **)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44),
                         0x13);
      if (iVar3 != 0) {
        return;
      }
    }
    if (iVar3 != -0x7789fe52) break;
    Sleep(1);
  }
  return;
}

