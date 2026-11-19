// rea decompile_all
// name: SoundPakManager_OpenStream
// address: 0x540040
// body: available
// range: 0x540040-0x5401a1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int * __thiscall SoundPakManager_OpenStream(void *this,char *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_11c;
  int local_118;
  LPCRITICAL_SECTION local_114;
  uint local_110 [65];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Opens a file inside the registered sound paks as a stream. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055aeab;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)((int)this + 0x23c);
  ExceptionList = &local_c;
  local_114 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  SoundPakManager_BuildArchivePath(this,param_1,local_110);
  piVar2 = (int *)FUN_005405b0((int)this);
  if (piVar2 == (int *)0x0) {
    FUN_0048e0a0();
    LeaveCriticalSection(lpCriticalSection);
    piVar2 = (int *)0x0;
  }
  else {
    local_118 = 0;
    local_11c = 0;
    uVar3 = FUN_00540390(this,(byte *)local_110,&local_118,&local_11c);
    if ((char)uVar3 == '\0') {
      piVar2[5] = 0;
      LeaveCriticalSection(lpCriticalSection);
      piVar2 = (int *)0x0;
    }
    else {
      piVar2[2] = *(int *)(*(int *)((int)this + local_118 * 0x1c + 0x14) + 8 + local_11c * 0x14);
      piVar2[3] = *(int *)(*(int *)((int)this + local_118 * 0x1c + 0x14) + 0xc + local_11c * 0x14) +
                  0x6c;
      *piVar2 = local_118;
      piVar2[1] = local_11c;
      piVar2[4] = 0;
      if (*(int *)((int)this + local_118 * 0x1c + 0x20) == 0) {
        piVar2[6] = 0;
        piVar2[7] = 2;
        piVar2[8] = *(int *)((int)this + (local_118 + 1) * 0x1c);
      }
      else {
        iVar1 = *(int *)((int)this + local_118 * 0x1c + 8);
        piVar2[7] = 0;
        piVar2[6] = iVar1;
        piVar2[8] = 0;
      }
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  ExceptionList = local_c;
  return piVar2;
}

