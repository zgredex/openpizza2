// rea decompile_all
// name: SoundPakStream_Read
// address: 0x5401b0
// body: available
// range: 0x5401b0-0x54025c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __thiscall SoundPakStream_Read(void *this,char *param_1,uint param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  uint uVar2;
  char *pcVar3;
  
                    /* Reads bytes from a sound-pak stream. */
  lpCriticalSection = (LPCRITICAL_SECTION)((int)this + 0x23c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = *(int *)(param_3 + 0x10);
  if (*(uint *)(param_3 + 8) <= iVar1 + param_2) {
    param_2 = *(uint *)(param_3 + 8) - iVar1;
  }
  if ((int)param_2 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  if (*(int *)(param_3 + 0x1c) == 2) {
    pcVar3 = (char *)(*(int *)(param_3 + 0x20) + *(int *)(param_3 + 0xc) + iVar1);
    for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined4 *)param_1 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      param_1 = param_1 + 4;
    }
    for (uVar2 = param_2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *param_1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      param_1 = param_1 + 1;
    }
  }
  else {
    CRT_Fseek(*(int **)(param_3 + 0x18),*(int *)(param_3 + 0xc) + iVar1,0);
    param_2 = FUN_0054e978(param_1,1,param_2,*(int **)(param_3 + 0x18));
  }
  *(uint *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + param_2;
  LeaveCriticalSection(lpCriticalSection);
  return param_2;
}

