// rea decompile_all
// name: FUN_004da200
// address: 0x4da200
// body: available
// range: 0x4da200-0x4da29a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004da200(void *this,int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  
  *(uint *)((int)this + param_1 * 4 + 0xdac) = param_2;
  if (*(int *)(*(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8) + 0xf8) != 0) {
    iVar3 = 0;
    puVar4 = (uint *)((int)this + 0xdac);
    do {
      iVar2 = FUN_00488be0(DAT_0057c670,iVar3);
      if ((iVar2 != 0) && (*puVar4 < param_2)) {
        piVar1 = (int *)(*(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8) + 0xf8);
        *piVar1 = *piVar1 + -1;
        break;
      }
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar3 < 6);
  }
  Game_AdjustPlayerRankingScores((int)this);
  if (*(void **)((int)DAT_0057c670 + 0x264) != (void *)0x0) {
    UI_QueueControlCommand(*(void **)((int)DAT_0057c670 + 0x264),-0x18612,0x23,0);
  }
  return;
}

