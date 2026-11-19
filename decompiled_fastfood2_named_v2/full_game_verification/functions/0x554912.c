// rea decompile_all
// name: CRT_Free
// address: 0x554912
// body: available
// range: 0x554912-0x554c3c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl CRT_Free(uint *param_1,uint param_2)

{
  char *pcVar1;
  uint *puVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int local_10;
  
  uVar5 = param_1[4];
  iVar6 = *(int *)(param_2 - 4);
  piVar9 = (int *)(param_2 - 4);
  uVar10 = param_2 - param_1[3] >> 0xf;
  uVar7 = *(uint *)(param_2 - 8);
  local_10 = iVar6 + -1;
  piVar3 = (int *)(uVar10 * 0x204 + 0x144 + uVar5);
  uVar12 = *(uint *)(local_10 + (int)piVar9);
  if ((uVar12 & 1) == 0) {
    param_2 = ((int)uVar12 >> 4) - 1;
    if (0x3f < param_2) {
      param_2 = 0x3f;
    }
    if (*(int *)(iVar6 + 3 + (int)piVar9) == *(int *)(iVar6 + 7 + (int)piVar9)) {
      if (param_2 < 0x20) {
        pcVar1 = (char *)(param_2 + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)param_2 & 0x1f));
        puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar11;
        }
      }
      else {
        pcVar1 = (char *)(param_2 + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)param_2 - 0x20 & 0x1f));
        puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar11;
        }
      }
    }
    *(undefined4 *)(*(int *)(iVar6 + 7 + (int)piVar9) + 4) =
         *(undefined4 *)(iVar6 + 3 + (int)piVar9);
    local_10 = local_10 + uVar12;
    *(undefined4 *)(*(int *)(iVar6 + 3 + (int)piVar9) + 8) =
         *(undefined4 *)(iVar6 + 7 + (int)piVar9);
  }
  uVar12 = (local_10 >> 4) - 1;
  if (0x3f < uVar12) {
    uVar12 = 0x3f;
  }
  if ((uVar7 & 1) == 0) {
    piVar9 = (int *)((int)piVar9 - uVar7);
    param_2 = ((int)uVar7 >> 4) - 1;
    if (0x3f < param_2) {
      param_2 = 0x3f;
    }
    local_10 = local_10 + uVar7;
    uVar12 = (local_10 >> 4) - 1;
    if (0x3f < uVar12) {
      uVar12 = 0x3f;
    }
    if (param_2 != uVar12) {
      if (piVar9[1] == piVar9[2]) {
        if (param_2 < 0x20) {
          pcVar1 = (char *)(param_2 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)param_2 & 0x1f));
          puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar11;
          }
        }
        else {
          pcVar1 = (char *)(param_2 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)param_2 - 0x20 & 0x1f));
          puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar11;
          }
        }
      }
      *(int *)(piVar9[2] + 4) = piVar9[1];
      *(int *)(piVar9[1] + 8) = piVar9[2];
    }
  }
  if (((uVar7 & 1) != 0) || (param_2 != uVar12)) {
    piVar9[1] = piVar3[uVar12 * 2 + 1];
    piVar9[2] = (int)(piVar3 + uVar12 * 2);
    (piVar3 + uVar12 * 2)[1] = (int)piVar9;
    *(int **)(piVar9[1] + 8) = piVar9;
    if (piVar9[1] == piVar9[2]) {
      cVar4 = *(char *)(uVar12 + 4 + uVar5);
      *(char *)(uVar12 + 4 + uVar5) = cVar4 + '\x01';
      bVar8 = (byte)uVar12;
      if (uVar12 < 0x20) {
        if (cVar4 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
        }
        puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar2 = *puVar2 | 0x80000000U >> (bVar8 & 0x1f);
      }
      else {
        if (cVar4 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
        puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar2 = *puVar2 | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
      }
    }
  }
  *piVar9 = local_10;
  *(int *)(local_10 + -4 + (int)piVar9) = local_10;
  *piVar3 = *piVar3 + -1;
  if (*piVar3 != 0) {
    return;
  }
  if (DAT_00585bd4 != (uint *)0x0) {
    VirtualFree((LPVOID)(DAT_00585bcc * 0x8000 + DAT_00585bd4[3]),0x8000,0x4000);
    DAT_00585bd4[2] = DAT_00585bd4[2] | 0x80000000U >> ((byte)DAT_00585bcc & 0x1f);
    *(undefined4 *)(DAT_00585bd4[4] + 0xc4 + DAT_00585bcc * 4) = 0;
    *(char *)(DAT_00585bd4[4] + 0x43) = *(char *)(DAT_00585bd4[4] + 0x43) + -1;
    if (*(char *)(DAT_00585bd4[4] + 0x43) == '\0') {
      DAT_00585bd4[1] = DAT_00585bd4[1] & 0xfffffffe;
    }
    if (DAT_00585bd4[2] == 0xffffffff) {
      VirtualFree((LPVOID)DAT_00585bd4[3],0,0x8000);
      HeapFree(DAT_00585be0,0,(LPVOID)DAT_00585bd4[4]);
      _memmove(DAT_00585bd4,DAT_00585bd4 + 5,
               (DAT_00585bd8 * 0x14 - (int)DAT_00585bd4) + -0x14 + DAT_00585bdc);
      DAT_00585bd8 = DAT_00585bd8 + -1;
      if (DAT_00585bd4 < param_1) {
        param_1 = param_1 + -5;
      }
      DAT_00585bcc = uVar10;
      DAT_00585bd0 = DAT_00585bdc;
      DAT_00585bd4 = param_1;
      return;
    }
  }
  DAT_00585bd4 = param_1;
  DAT_00585bcc = uVar10;
  return;
}

