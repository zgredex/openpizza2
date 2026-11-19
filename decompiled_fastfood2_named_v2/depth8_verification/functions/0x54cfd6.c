// rea decompile_all
// name: FUN_0054cfd6
// address: 0x54cfd6
// body: available
// range: 0x54cfd6-0x54d0b0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall FUN_0054cfd6(int param_1)

{
  byte bVar1;
  uint uVar2;
  DWORD DVar3;
  int iVar4;
  char *pcVar5;
  DWORD DVar6;
  
  if (*(uint *)(param_1 + 0x4c) == 0xffffffff) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 8) == 0) {
    pcVar5 = *(char **)(param_1 + 0x18);
    if (*(char **)(param_1 + 0x1c) < pcVar5) {
      DVar6 = 0;
    }
    else {
      DVar6 = (int)*(char **)(param_1 + 0x1c) - (int)pcVar5;
    }
    if ((DVar6 != 0) && (DVar3 = CRT_Write(*(uint *)(param_1 + 0x4c),pcVar5,DVar6), DVar3 != DVar6))
    {
      if (0 < (int)DVar3) {
        if (*(int *)(param_1 + 0x20) != 0) {
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) - DVar3;
        }
        FUN_0054e230(*(undefined4 **)(param_1 + 0x18),
                     (undefined4 *)(DVar3 + (int)*(undefined4 **)(param_1 + 0x18)),DVar6 - DVar3);
      }
      return 0xffffffff;
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    iVar4 = FUN_0054cf82(param_1);
    if (0 < iVar4) {
      uVar2 = *(uint *)(param_1 + 0x4c);
      bVar1 = *(byte *)((&DAT_00586c20)[(int)uVar2 >> 5] + 4 + (uVar2 & 0x1f) * 0x24);
      if ((bVar1 & 0x80) != 0) {
        for (pcVar5 = *(char **)(param_1 + 0x28); pcVar5 < *(char **)(param_1 + 0x2c);
            pcVar5 = pcVar5 + 1) {
          if (*pcVar5 == '\n') {
            iVar4 = iVar4 + 1;
          }
        }
        if ((bVar1 & 2) != 0) {
          iVar4 = iVar4 + 1;
        }
      }
      DVar6 = CRT_Lseek(uVar2,-iVar4,1);
      if (DVar6 == 0xffffffff) {
        return 0xffffffff;
      }
    }
    *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  return 0;
}

