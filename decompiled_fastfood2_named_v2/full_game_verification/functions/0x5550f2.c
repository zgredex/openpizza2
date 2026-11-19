// rea decompile_all
// name: CRT_HeapFreeBlock
// address: 0x5550f2
// body: available
// range: 0x5550f2-0x5553e7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl CRT_HeapFreeBlock(uint *param_1,int param_2,int param_3)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint local_c;
  
  uVar5 = param_1[4];
  uVar11 = param_3 + 0x17U & 0xfffffff0;
  uVar9 = param_2 - param_1[3] >> 0xf;
  iVar3 = uVar9 * 0x204 + 0x144 + uVar5;
  iVar6 = *(int *)(param_2 + -4);
  iVar8 = iVar6 + -1;
  uVar12 = *(uint *)(iVar6 + -5 + param_2);
  iVar6 = iVar6 + -5 + param_2;
  if (iVar8 < (int)uVar11) {
    if (((uVar12 & 1) != 0) || ((int)(uVar12 + iVar8) < (int)uVar11)) {
      return 0;
    }
    local_c = ((int)uVar12 >> 4) - 1;
    if (0x3f < local_c) {
      local_c = 0x3f;
    }
    if (*(int *)(iVar6 + 4) == *(int *)(iVar6 + 8)) {
      if (local_c < 0x20) {
        pcVar1 = (char *)(local_c + 4 + uVar5);
        uVar10 = ~(0x80000000U >> ((byte)local_c & 0x1f));
        puVar7 = (uint *)(uVar5 + 0x44 + uVar9 * 4);
        *puVar7 = *puVar7 & uVar10;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar10;
        }
      }
      else {
        pcVar1 = (char *)(local_c + 4 + uVar5);
        uVar10 = ~(0x80000000U >> ((byte)local_c - 0x20 & 0x1f));
        puVar7 = (uint *)(uVar5 + 0xc4 + uVar9 * 4);
        *puVar7 = *puVar7 & uVar10;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar10;
        }
      }
    }
    *(undefined4 *)(*(int *)(iVar6 + 8) + 4) = *(undefined4 *)(iVar6 + 4);
    *(undefined4 *)(*(int *)(iVar6 + 4) + 8) = *(undefined4 *)(iVar6 + 8);
    iVar6 = uVar12 + (iVar8 - uVar11);
    if (0 < iVar6) {
      uVar12 = (iVar6 >> 4) - 1;
      iVar8 = param_2 + -4 + uVar11;
      if (0x3f < uVar12) {
        uVar12 = 0x3f;
      }
      iVar3 = iVar3 + uVar12 * 8;
      *(undefined4 *)(iVar8 + 4) = *(undefined4 *)(iVar3 + 4);
      *(int *)(iVar8 + 8) = iVar3;
      *(int *)(iVar3 + 4) = iVar8;
      *(int *)(*(int *)(iVar8 + 4) + 8) = iVar8;
      if (*(int *)(iVar8 + 4) == *(int *)(iVar8 + 8)) {
        cVar4 = *(char *)(uVar12 + 4 + uVar5);
        *(char *)(uVar12 + 4 + uVar5) = cVar4 + '\x01';
        if (uVar12 < 0x20) {
          if (cVar4 == '\0') {
            *param_1 = *param_1 | 0x80000000U >> ((byte)uVar12 & 0x1f);
          }
          puVar7 = (uint *)(uVar5 + 0x44 + uVar9 * 4);
        }
        else {
          if (cVar4 == '\0') {
            param_1[1] = param_1[1] | 0x80000000U >> ((byte)uVar12 - 0x20 & 0x1f);
          }
          puVar7 = (uint *)(uVar5 + 0xc4 + uVar9 * 4);
          uVar12 = uVar12 - 0x20;
        }
        *puVar7 = *puVar7 | 0x80000000U >> ((byte)uVar12 & 0x1f);
      }
      piVar2 = (int *)(param_2 + -4 + uVar11);
      *piVar2 = iVar6;
      *(int *)(iVar6 + -4 + (int)piVar2) = iVar6;
    }
    *(uint *)(param_2 + -4) = uVar11 + 1;
    *(uint *)(param_2 + -8 + uVar11) = uVar11 + 1;
  }
  else if ((int)uVar11 < iVar8) {
    param_3 = iVar8 - uVar11;
    *(uint *)(param_2 + -4) = uVar11 + 1;
    piVar2 = (int *)(param_2 + -4 + uVar11);
    uVar10 = (param_3 >> 4) - 1;
    piVar2[-1] = uVar11 + 1;
    if (0x3f < uVar10) {
      uVar10 = 0x3f;
    }
    if ((uVar12 & 1) == 0) {
      uVar11 = ((int)uVar12 >> 4) - 1;
      if (0x3f < uVar11) {
        uVar11 = 0x3f;
      }
      if (*(int *)(iVar6 + 4) == *(int *)(iVar6 + 8)) {
        if (uVar11 < 0x20) {
          pcVar1 = (char *)(uVar11 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)uVar11 & 0x1f));
          puVar7 = (uint *)(uVar5 + 0x44 + uVar9 * 4);
          *puVar7 = *puVar7 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar11;
          }
        }
        else {
          pcVar1 = (char *)(uVar11 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)uVar11 - 0x20 & 0x1f));
          puVar7 = (uint *)(uVar5 + 0xc4 + uVar9 * 4);
          *puVar7 = *puVar7 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar11;
          }
        }
      }
      *(undefined4 *)(*(int *)(iVar6 + 8) + 4) = *(undefined4 *)(iVar6 + 4);
      *(undefined4 *)(*(int *)(iVar6 + 4) + 8) = *(undefined4 *)(iVar6 + 8);
      param_3 = param_3 + uVar12;
      uVar10 = (param_3 >> 4) - 1;
      if (0x3f < uVar10) {
        uVar10 = 0x3f;
      }
    }
    iVar6 = iVar3 + uVar10 * 8;
    piVar2[1] = *(int *)(iVar3 + 4 + uVar10 * 8);
    piVar2[2] = iVar6;
    *(int **)(iVar6 + 4) = piVar2;
    *(int **)(piVar2[1] + 8) = piVar2;
    if (piVar2[1] == piVar2[2]) {
      cVar4 = *(char *)(uVar10 + 4 + uVar5);
      *(char *)(uVar10 + 4 + uVar5) = cVar4 + '\x01';
      if (uVar10 < 0x20) {
        if (cVar4 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> ((byte)uVar10 & 0x1f);
        }
        puVar7 = (uint *)(uVar5 + 0x44 + uVar9 * 4);
      }
      else {
        if (cVar4 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> ((byte)uVar10 - 0x20 & 0x1f);
        }
        puVar7 = (uint *)(uVar5 + 0xc4 + uVar9 * 4);
        uVar10 = uVar10 - 0x20;
      }
      *puVar7 = *puVar7 | 0x80000000U >> ((byte)uVar10 & 0x1f);
    }
    *piVar2 = param_3;
    *(int *)(param_3 + -4 + (int)piVar2) = param_3;
  }
  return 1;
}

