// rea decompile_all
// name: SoundVoice_ServiceStream
// address: 0x5420d0
// body: available
// range: 0x5420d0-0x5424a3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall SoundVoice_ServiceStream(void *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint local_c;
  uint local_8;
  uint local_4;
  
  iVar7 = 0;
  if (*(char *)((int)param_1 + 0x54) == '\0') {
    return 1;
  }
  if (*(char *)((int)param_1 + 0x56) == '\0') {
    return 0;
  }
  if (*(char *)((int)param_1 + 0x53) == '\0') {
    iVar7 = SoundVoice_Open(param_1);
    if (iVar7 < 0) {
      *(undefined1 *)((int)param_1 + 0x57) = 1;
      return iVar7;
    }
    EnterCriticalSection(*(LPCRITICAL_SECTION *)((int)param_1 + 0x38));
    if (*(char *)((int)param_1 + 0x54) == '\0') {
      LeaveCriticalSection(*(LPCRITICAL_SECTION *)((int)param_1 + 0x38));
      return 1;
    }
    SoundBuffer_Configure(*(int **)(*(int *)((int)param_1 + 0x28) + 0x48),'\x01');
    LeaveCriticalSection(*(LPCRITICAL_SECTION *)((int)param_1 + 0x38));
    return iVar7;
  }
  local_c = 0;
  uVar6 = *(uint *)(*(int *)((int)param_1 + 0x28) + 0x10) >> 1;
  if (*(char *)((int)param_1 + 0x55) != '\0') {
    local_c = uVar6;
  }
  if (*(char *)((int)param_1 + 0x57) == '\0') {
    do {
      local_8 = 0;
      local_4 = 0;
      iVar7 = *(int *)((int)param_1 + 0x2c);
      if (*(short *)(iVar7 + 0x14) == 1) {
        iVar7 = *(int *)(iVar7 + 0x30) - (uint)*(ushort *)(iVar7 + 0x20);
      }
      else {
        iVar7 = *(int *)(iVar7 + 0x30) + (uint)*(ushort *)(iVar7 + 0x16) * -2;
      }
      iVar7 = Stream_RequestBlock((void *)((int)param_1 + 8),iVar7,uVar6,(int *)&local_8,&local_4);
      if (iVar7 != 2) {
        if ((iVar7 == 1) &&
           (uVar8 = *(int *)(*(int *)((int)param_1 + 0x2c) + 0x28) -
                    *(int *)(*(int *)((int)param_1 + 0x2c) + 0x30), uVar8 < uVar6)) {
          if ((uVar8 != 0) &&
             (local_4 = SoundVoice_WriteSamples(param_1,local_c,uVar8), (int)local_4 < 0)) {
            EnterCriticalSection(*(LPCRITICAL_SECTION *)((int)param_1 + 0x38));
            iVar7 = *(int *)((int)param_1 + 0x28);
            piVar2 = *(int **)(iVar7 + 0x48);
            if ((piVar2 != (int *)0x0) &&
               (iVar3 = (**(code **)(*piVar2 + 0x48))(piVar2), -1 < iVar3)) {
              if (*(char *)(iVar7 + 0x34) != '\0') {
                List_DestroyObjects(iVar7);
              }
              (**(code **)(**(int **)(iVar7 + 0x48) + 0x34))(*(int **)(iVar7 + 0x48),0);
            }
            LeaveCriticalSection(*(LPCRITICAL_SECTION *)((int)param_1 + 0x38));
            return local_4;
          }
          local_c = local_c + uVar8;
          uVar6 = uVar6 - uVar8;
          iVar7 = SoundStream_LoadNextSample((int)param_1);
          if (iVar7 < 0) {
            return iVar7;
          }
          goto LAB_0054236d;
        }
        break;
      }
      iVar7 = SoundVoice_WriteSamples(param_1,local_c,local_8);
      if (iVar7 < 0) {
        EnterCriticalSection(*(LPCRITICAL_SECTION *)((int)param_1 + 0x38));
        iVar3 = *(int *)((int)param_1 + 0x28);
        piVar2 = *(int **)(iVar3 + 0x48);
        if ((piVar2 != (int *)0x0) && (iVar5 = (**(code **)(*piVar2 + 0x48))(piVar2), -1 < iVar5)) {
          if (*(char *)(iVar3 + 0x34) != '\0') {
            List_DestroyObjects(iVar3);
          }
          (**(code **)(**(int **)(iVar3 + 0x48) + 0x34))(*(int **)(iVar3 + 0x48),0);
        }
        LeaveCriticalSection(*(LPCRITICAL_SECTION *)((int)param_1 + 0x38));
        return iVar7;
      }
      local_c = local_c + local_8;
      uVar6 = uVar6 - local_8;
      *(uint *)((int)param_1 + 0x84) = local_4;
      *(undefined1 *)((int)param_1 + 0x88) = 1;
    } while (uVar6 != 0);
LAB_00542418:
    iVar7 = SoundVoice_WriteSamples(param_1,local_c,uVar6);
    if (iVar7 < 0) {
      EnterCriticalSection(*(LPCRITICAL_SECTION *)((int)param_1 + 0x38));
      iVar3 = *(int *)((int)param_1 + 0x28);
      piVar2 = *(int **)(iVar3 + 0x48);
      if ((piVar2 != (int *)0x0) && (iVar5 = (**(code **)(*piVar2 + 0x48))(piVar2), -1 < iVar5)) {
        if (*(char *)(iVar3 + 0x34) != '\0') {
          List_DestroyObjects(iVar3);
        }
        (**(code **)(**(int **)(iVar3 + 0x48) + 0x34))(*(int **)(iVar3 + 0x48),0);
      }
      LeaveCriticalSection(*(LPCRITICAL_SECTION *)((int)param_1 + 0x38));
      return iVar7;
    }
    goto LAB_0054248b;
  }
  cVar1 = *(char *)((int)param_1 + 0x70);
  if (cVar1 == '\0') {
    iVar7 = SoundVoice_WriteSilence(param_1,local_c,uVar6);
    if (-1 < iVar7) {
      *(undefined1 *)((int)param_1 + 0x70) = 1;
      goto LAB_005421ae;
    }
  }
  else {
    *(undefined1 *)((int)param_1 + 0x54) = 0;
LAB_005421ae:
    if (cVar1 == '\0') goto LAB_0054248b;
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)((int)param_1 + 0x38));
  iVar7 = *(int *)((int)param_1 + 0x28);
  piVar2 = *(int **)(iVar7 + 0x48);
  if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x48))(piVar2), -1 < iVar3)) {
    if (*(char *)(iVar7 + 0x34) != '\0') {
      List_DestroyObjects(iVar7);
    }
    (**(code **)(**(int **)(iVar7 + 0x48) + 0x34))(*(int **)(iVar7 + 0x48),0);
  }
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)((int)param_1 + 0x38));
  iVar7 = 1;
LAB_0054248b:
  *(bool *)((int)param_1 + 0x55) = *(char *)((int)param_1 + 0x55) == '\0';
  *(undefined1 *)((int)param_1 + 0x56) = 0;
  return iVar7;
LAB_0054236d:
  if (iVar7 != 1) goto LAB_00542418;
  if (*(char *)((int)param_1 + 0x52) == '\0') {
    iVar7 = 1;
    if ((uVar6 != 0) && (iVar7 = SoundVoice_WriteSilence(param_1,local_c,uVar6), iVar7 < 0)) {
      EnterCriticalSection(*(LPCRITICAL_SECTION *)((int)param_1 + 0x38));
      iVar3 = *(int *)((int)param_1 + 0x28);
      piVar2 = *(int **)(iVar3 + 0x48);
      if ((piVar2 != (int *)0x0) && (iVar5 = (**(code **)(*piVar2 + 0x48))(piVar2), -1 < iVar5)) {
        if (*(char *)(iVar3 + 0x34) != '\0') {
          List_DestroyObjects(iVar3);
        }
        (**(code **)(**(int **)(iVar3 + 0x48) + 0x34))(*(int **)(iVar3 + 0x48),0);
      }
      LeaveCriticalSection(*(LPCRITICAL_SECTION *)((int)param_1 + 0x38));
      return iVar7;
    }
    *(undefined1 *)((int)param_1 + 0x70) = 0;
    *(undefined1 *)((int)param_1 + 0x57) = 1;
    (**(code **)(**(int **)((int)param_1 + 0x2c) + 4))(*(int **)((int)param_1 + 0x2c));
    *(undefined4 *)((int)param_1 + 0x2c) = 0;
    goto LAB_0054248b;
  }
  *(char **)((int)param_1 + 0x48) = *(char **)((int)param_1 + 0x44);
  pcVar4 = _strchr(*(char **)((int)param_1 + 0x44),0x2c);
  *(char **)((int)param_1 + 0x4c) = pcVar4;
  if (pcVar4 != (char *)0x0) {
    *pcVar4 = '\0';
  }
  *(undefined1 *)((int)param_1 + 0x3c) = 1;
  iVar7 = SoundStream_LoadNextSample((int)param_1);
  if (iVar7 < 0) {
    return iVar7;
  }
  goto LAB_0054236d;
}

