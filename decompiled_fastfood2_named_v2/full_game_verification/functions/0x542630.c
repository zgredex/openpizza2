// rea decompile_all
// name: Sound_UpdateBufferFade
// address: 0x542630
// body: available
// range: 0x542630-0x54271a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __fastcall Sound_UpdateBufferFade(int param_1)

{
  DWORD DVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x8c) == 0) {
    return 1;
  }
  uVar2 = *(uint *)(param_1 + 0x90);
  DVar1 = timeGetTime();
  *(DWORD *)(param_1 + 0x94) = DVar1;
  if (DVar1 < uVar2) {
    uVar2 = (DVar1 - uVar2) - 1;
  }
  else {
    uVar2 = DVar1 - uVar2;
  }
  if (uVar2 < *(uint *)(param_1 + 0x98)) {
    return 1;
  }
  uVar2 = (uVar2 * 100) / *(uint *)(param_1 + 0x98);
  if (*(int *)(param_1 + 0x8c) == 1) {
    uVar2 = *(int *)(param_1 + 0x9c) + uVar2;
    if (*(uint *)(param_1 + 0x78) <= uVar2) {
      *(undefined4 *)(param_1 + 0x8c) = 0;
      *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x78);
      goto LAB_005426b1;
    }
  }
  else {
    if (*(int *)(param_1 + 0x8c) != 2) goto LAB_005426b1;
    if (*(uint *)(param_1 + 0x9c) < uVar2) {
      *(undefined4 *)(param_1 + 0x8c) = 0;
      *(undefined4 *)(param_1 + 0x9c) = 0;
      goto LAB_005426b1;
    }
    uVar2 = *(uint *)(param_1 + 0x9c) - uVar2;
  }
  *(uint *)(param_1 + 0x9c) = uVar2;
LAB_005426b1:
  DVar1 = timeGetTime();
  *(DWORD *)(param_1 + 0x90) = DVar1;
  *(DWORD *)(param_1 + 0x94) = DVar1;
  if (*(char *)(param_1 + 0x53) == '\0') {
    return 1;
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(param_1 + 0x38));
  uVar2 = Sound_SetBufferVolume(*(void **)(param_1 + 0x28),*(uint *)(param_1 + 0x9c));
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(param_1 + 0x38));
  return uVar2;
}

