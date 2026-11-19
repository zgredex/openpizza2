// rea decompile_all
// name: FUN_0053fda0
// address: 0x53fda0
// body: available
// range: 0x53fda0-0x53ff7b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __thiscall FUN_0053fda0(void *this,LPCSTR param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *puVar1;
  char cVar2;
  uint extraout_EAX;
  int *piVar3;
  uint extraout_EAX_00;
  int iVar4;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  char *pcVar5;
  undefined4 extraout_EAX_03;
  uint uVar6;
  int iVar7;
  char local_78 [96];
  uint local_18;
  int local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ae88;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)((int)this + 0x23c);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  if (*(int *)((int)this + 0x238) < 0x14) {
    puVar1 = (undefined4 *)((int)this + *(int *)((int)this + 0x238) * 0x1c + 8);
    piVar3 = (int *)FUN_0054dfe0(param_1,&DAT_00563184);
    *puVar1 = piVar3;
    if (piVar3 == (int *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      uVar6 = extraout_EAX_00 & 0xffffff00;
    }
    else {
      puVar1[6] = 1;
      FUN_0054e978(local_78,1,0x6c,piVar3);
      uVar6 = 0xffffffff;
      pcVar5 = s_ResourceFile_ID_7654_0056316c;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
      iVar4 = _strncmp(local_78,s_ResourceFile_ID_7654_0056316c,~uVar6 - 1);
      if (iVar4 == 0) {
        if (local_14 < 0x65) {
          pcVar5 = operator_new(local_18);
          puVar1[1] = pcVar5;
          FUN_0054e978(pcVar5,1,local_18,(int *)*puVar1);
          if (local_10 != 0) {
            FUN_00401f30(puVar1[1],local_18);
            piVar3 = (int *)puVar1[1];
            puVar1[2] = piVar3;
            puVar1[3] = piVar3 + 1;
            puVar1[4] = piVar3 + *piVar3 * 5 + 1;
          }
          iVar4 = 0;
          if (0 < *(int *)puVar1[2]) {
            iVar7 = 0;
            do {
              iVar4 = iVar4 + 1;
              *(int *)(puVar1[3] + 0x10 + iVar7) = *(int *)(puVar1[3] + 0x10 + iVar7) + puVar1[4];
              iVar7 = iVar7 + 0x14;
            } while (iVar4 < *(int *)puVar1[2]);
          }
          FUN_0053ff90((int *)puVar1[3],*(undefined4 **)puVar1[2]);
          *(int *)((int)this + 0x238) = *(int *)((int)this + 0x238) + 1;
          LeaveCriticalSection(lpCriticalSection);
          uVar6 = CONCAT31((int3)((uint)extraout_EAX_03 >> 8),1);
        }
        else {
          FUN_0054dee4((FILE *)*puVar1);
          FUN_0048e0a0();
          LeaveCriticalSection(lpCriticalSection);
          uVar6 = extraout_EAX_02 & 0xffffff00;
        }
      }
      else {
        FUN_0054dee4((FILE *)*puVar1);
        LeaveCriticalSection(lpCriticalSection);
        uVar6 = extraout_EAX_01 & 0xffffff00;
      }
    }
  }
  else {
    LeaveCriticalSection(lpCriticalSection);
    uVar6 = extraout_EAX & 0xffffff00;
  }
  ExceptionList = local_c;
  return uVar6;
}

