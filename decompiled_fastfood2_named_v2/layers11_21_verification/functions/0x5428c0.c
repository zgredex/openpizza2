// rea decompile_all
// name: SoundVoiceThread_Run
// address: 0x5428c0
// body: available
// range: 0x5428c0-0x542ac5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl SoundVoiceThread_Run(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *puVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  LPVOID pvVar5;
  DWORD DVar6;
  int iVar7;
  undefined4 *this;
  int local_c;
  uint local_8;
  uint local_4;
  
  do {
    local_8 = 0xffffffff;
    local_c = 0;
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x14);
    EnterCriticalSection(lpCriticalSection);
    this = (undefined4 *)(param_1 + 4);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 4);
    LeaveCriticalSection(lpCriticalSection);
    while( true ) {
      EnterCriticalSection(lpCriticalSection);
      puVar1 = *(undefined4 **)(param_1 + 0xc);
      if (puVar1 != (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 0xc) = puVar1[1];
      }
      LeaveCriticalSection(lpCriticalSection);
      if (puVar1 == (undefined4 *)0x0) break;
      piVar2 = (int *)*puVar1;
      if ((((*(char *)((int)piVar2 + 0x57) == '\0') || ((char)piVar2[0x16] == '\0')) ||
          (*(char *)((int)piVar2 + 0x53) == '\0')) ||
         (uVar4 = FUN_00542ad0(piVar2[10]), (char)uVar4 != '\0')) {
        local_4 = 0;
        cVar3 = FUN_00541fc0(piVar2,&local_4);
        if (cVar3 == '\0') {
          local_c = local_c + 1;
          *(undefined1 *)((int)piVar2 + 0x56) = 1;
          FUN_00542630((int)piVar2);
        }
        else {
          if (local_4 < local_8) {
            local_8 = local_4;
          }
          FUN_00542630((int)piVar2);
        }
      }
      else {
        EnterCriticalSection(lpCriticalSection);
        pvVar5 = (LPVOID)FUN_00542b00(this,(int)puVar1);
        FUN_0054dd78(pvVar5);
        LeaveCriticalSection(lpCriticalSection);
        *(undefined1 *)(piVar2 + 0x14) = 0;
        if ((piVar2[8] != 0) && ((undefined4 *)piVar2[9] != (undefined4 *)0x0)) {
          FUN_00544ae0((void *)piVar2[8],(undefined4 *)piVar2[9]);
          piVar2[8] = 0;
          piVar2[9] = 0;
        }
        (**(code **)(*piVar2 + 4))(piVar2);
      }
    }
    if (local_c == 0) {
      DVar6 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x2c),local_8);
      if (DVar6 == 0xffffffff) {
        return;
      }
    }
    else {
      EnterCriticalSection(lpCriticalSection);
      *(undefined4 *)(param_1 + 0xc) = *this;
      LeaveCriticalSection(lpCriticalSection);
      while( true ) {
        EnterCriticalSection(lpCriticalSection);
        puVar1 = *(undefined4 **)(param_1 + 0xc);
        if (puVar1 != (undefined4 *)0x0) {
          *(undefined4 *)(param_1 + 0xc) = puVar1[1];
        }
        LeaveCriticalSection(lpCriticalSection);
        if (puVar1 == (undefined4 *)0x0) break;
        piVar2 = (int *)*puVar1;
        iVar7 = SoundVoice_ServiceStream(piVar2);
        if ((iVar7 < 0) || ((iVar7 == 1 && ((char)piVar2[0x16] == '\0')))) {
          EnterCriticalSection(lpCriticalSection);
          if (*(undefined4 **)(param_1 + 0xc) == puVar1) {
            *(undefined4 *)(param_1 + 0xc) = (*(undefined4 **)(param_1 + 0xc))[1];
          }
          if (puVar1[2] == 0) {
            *this = puVar1[1];
          }
          else {
            *(undefined4 *)(puVar1[2] + 4) = puVar1[1];
          }
          if (puVar1 == *(undefined4 **)(param_1 + 8)) {
            *(undefined4 *)(param_1 + 8) = puVar1[2];
          }
          if (puVar1[1] != 0) {
            *(undefined4 *)(puVar1[1] + 8) = puVar1[2];
          }
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
          FUN_0054dd78(puVar1);
          LeaveCriticalSection(lpCriticalSection);
          *(undefined1 *)(piVar2 + 0x14) = 0;
          (**(code **)(*piVar2 + 4))(piVar2);
        }
      }
    }
  } while (*(char *)(param_1 + 0x34) == '\0');
  return;
}

