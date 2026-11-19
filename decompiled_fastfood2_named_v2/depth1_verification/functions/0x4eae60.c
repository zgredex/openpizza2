// rea decompile_all
// name: Map_CompactVisibleDrawRecords
// address: 0x4eae60
// body: available
// range: 0x4eae60-0x4eb0e3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Map_CompactVisibleDrawRecords(int param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int local_24;
  int local_20;
  int local_1c;
  void *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Depth-1 proposal batch 1. */
  iVar8 = *(int *)(param_1 + 0x70);
  local_18 = (void *)0x0;
  local_24 = 0;
  if (iVar8 == 0) {
    FUN_0053d090(*(void **)(param_1 + 0x74),&local_20,&local_1c);
    FUN_0053d100(*(void **)(param_1 + 0x74),&local_8,&local_4);
    local_20 = local_20 + local_8;
    local_1c = local_1c + local_4;
  }
  else {
    local_20 = *(int *)(iVar8 + 4) + 0x200;
    local_1c = *(int *)(iVar8 + 8) + 0x100;
  }
  local_10 = 0;
  if (0 < *(int *)(param_1 + 0x20)) {
    do {
      local_14 = 0;
      if (0 < *(int *)(param_1 + 0x1c)) {
        local_c = local_24 * 0xc;
        do {
          if (*(int *)(param_1 + 0xc) == 0x10) {
            piVar1 = (int *)(*(int *)(param_1 + 0x4c) + local_c);
            if ((((*piVar1 + 100 < *(int *)(param_1 + 0x2c) + DAT_00571960 * -0x10) ||
                 (piVar1[1] + 100 <
                  *(int *)(param_1 + 0x30) - *(int *)(param_1 + 0x10) * DAT_00571964)) ||
                (*(int *)(param_1 + 0x2c) + local_20 < *piVar1 + -100)) ||
               (*(int *)(param_1 + 0x30) + local_1c < piVar1[1] + -100)) {
              piVar1[2] = 0;
              goto LAB_004eafcf;
            }
          }
          else {
            piVar1 = (int *)(*(int *)(param_1 + 0x4c) + local_c);
            if (((*piVar1 + 100 < *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0xc) * DAT_00571960)
                || (piVar1[1] + 100 <
                    (*(int *)(param_1 + 0x30) - *(int *)(param_1 + 0x10) * DAT_00571964) -
                    *(int *)(param_1 + 0x10174))) ||
               ((*(int *)(param_1 + 0x2c) + local_20 < *piVar1 + -100 ||
                (*(int *)(param_1 + 0x10170) + *(int *)(param_1 + 0x30) + local_1c <
                 piVar1[1] + -100)))) {
              piVar1[2] = 0;
LAB_004eafcf:
              local_18 = (void *)((int)local_18 + 1);
            }
          }
          local_24 = local_24 + 1;
          local_c = local_c + 0xc;
          local_14 = local_14 + 1;
        } while (local_14 < *(int *)(param_1 + 0x1c));
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)(param_1 + 0x20));
  }
  iVar6 = 0;
  iVar8 = *(int *)(param_1 + 0x20) * *(int *)(param_1 + 0x1c) - (int)local_18;
  local_c = iVar8;
  pvVar2 = operator_new(iVar8 * 0x3c);
  iVar3 = 0;
  local_24 = 0;
  local_10 = 0;
  if (0 < *(int *)(param_1 + 0x20)) {
    do {
      local_14 = 0;
      if (0 < *(int *)(param_1 + 0x1c)) {
        iVar4 = iVar3 * 0xc;
        puVar5 = (undefined4 *)((int)pvVar2 + iVar6 * 0x3c);
        do {
          puVar7 = *(undefined4 **)(*(int *)(param_1 + 0x4c) + 8 + iVar4);
          if (puVar7 != (undefined4 *)0x0) {
            puVar9 = puVar5;
            for (iVar8 = 0xf; iVar8 != 0; iVar8 = iVar8 + -1) {
              *puVar9 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar9 = puVar9 + 1;
            }
            iVar6 = iVar6 + 1;
            *(undefined4 **)(*(int *)(param_1 + 0x4c) + 8 + iVar4) = puVar5;
            puVar5 = puVar5 + 0xf;
            iVar8 = local_c;
          }
          iVar3 = local_24 + 1;
          iVar4 = iVar4 + 0xc;
          local_14 = local_14 + 1;
          local_24 = iVar3;
        } while (local_14 < *(int *)(param_1 + 0x1c));
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)(param_1 + 0x20));
  }
  local_18 = pvVar2;
  FUN_0054dd78(*(LPVOID *)(param_1 + 0x138));
  *(int *)(param_1 + 0x13c) = iVar8;
  *(void **)(param_1 + 0x138) = pvVar2;
  return;
}

