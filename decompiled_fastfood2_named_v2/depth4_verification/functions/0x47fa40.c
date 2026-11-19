// rea decompile_all
// name: FUN_0047fa40
// address: 0x47fa40
// body: available
// range: 0x47fa40-0x47fb32 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall FUN_0047fa40(void *param_1)

{
  int iVar1;
  void *pvVar2;
  void *this;
  int iVar3;
  int iVar4;
  
  if (*(int *)((int)param_1 + 0x2c) != 0) {
    iVar1 = *(int *)(*(int *)((int)param_1 + 0x16f0) + 0x8c);
    iVar4 = iVar1;
    while (iVar4 = iVar4 + -1, -1 < iVar4) {
      pvVar2 = (void *)FUN_004d2a60(*(void **)((int)param_1 + 0x16f0),iVar4);
      if (*(int *)((int)pvVar2 + 0x74) == 0) {
        FUN_0054a660(DAT_0057c1e0,0xff,(byte *)s_Falsche_Personenliste_____s__00567d14,
                     (int)pvVar2 + 4);
        Game_RemoveObjectFromList(*(void **)((int)param_1 + 0x16f0),pvVar2,0);
      }
      else {
        iVar3 = *(int *)((int)pvVar2 + 0x30);
        if (((iVar3 < 0x2b) || (0x2f < iVar3)) && ((iVar3 < 0x1a || (0x1c < iVar3)))) break;
      }
    }
    if (iVar4 == -1) {
      if (*(int *)((int)param_1 + 0x2c) != 6) {
        if (*(int *)((int)param_1 + 0x2c) != 7) {
          FUN_0047f470(param_1);
          return 0;
        }
        pvVar2 = *(void **)((int)param_1 + 0x16f0);
        this = (void *)FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                    (int *)0x0);
        FUN_004d5160(this,1,0x2e,pvVar2);
      }
      return 1;
    }
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        iVar3 = FUN_004d2a60(*(void **)((int)param_1 + 0x16f0),iVar4);
        iVar4 = iVar4 + 1;
        *(undefined1 *)(iVar3 + 0x81) = 1;
      } while (iVar4 < iVar1);
    }
  }
  return 0;
}

