// rea decompile_all
// name: Map_BuildTerrainGrid
// address: 0x4f96e0
// body: available
// range: 0x4f96e0-0x4f9a14 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Map_BuildTerrainGrid(int param_1)

{
  char cVar1;
  bool bVar2;
  undefined1 uVar3;
  int iVar4;
  undefined3 extraout_var;
  void *this;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Depth-1 proposal batch 3/4. */
  puVar8 = (undefined4 *)(param_1 + 0x28);
  puVar11 = puVar8;
  for (iVar5 = 0x640; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar11 = 0x40404040;
    puVar11 = puVar11 + 1;
  }
  FUN_004f3b30(*(void **)(param_1 + 0x10),&local_18,&local_1c,&local_10,&local_14);
  local_30 = local_10;
  local_38 = local_18;
  iVar5 = local_1c;
  iVar4 = local_14;
  iVar9 = local_10;
  if (local_10 < local_14) {
    do {
      iVar10 = 0;
      if (local_38 < iVar5) {
        do {
          iVar5 = FUN_004ef4b0(*(void **)(param_1 + 0x10),local_38,local_30);
          if ((iVar5 != 0) && (*(int *)(iVar5 + 8) != 0)) {
            iVar5 = FUN_004f3b10(iVar5,0);
            iVar4 = FUN_004f2aa0(iVar5);
            if (iVar4 == 0) {
              bVar2 = FUN_004f2a60(iVar5);
              if (CONCAT31(extraout_var,bVar2) == 0) {
                iVar4 = FUN_004f2a80(iVar5);
                if (iVar4 == 0) {
                  iVar5 = FUN_004f29d0(iVar5);
                  if (iVar5 != 0) {
                    *(undefined1 *)(iVar10 + (int)puVar8) = 0x20;
                  }
                }
                else {
                  *(undefined1 *)(iVar10 + (int)puVar8) = 0x2b;
                }
              }
              else {
                *(undefined1 *)(iVar10 + (int)puVar8) = 0x2d;
              }
            }
            else {
              *(undefined1 *)(iVar10 + (int)puVar8) = 0x2e;
            }
          }
          iVar10 = iVar10 + 1;
          local_38 = local_38 + 1;
        } while (local_38 < local_1c);
        local_38 = local_18;
        iVar5 = local_1c;
        iVar4 = local_14;
        iVar9 = local_10;
      }
      puVar8 = puVar8 + 0x14;
      local_30 = local_30 + 1;
    } while (local_30 < iVar4);
  }
  local_34 = 0;
  if (iVar9 < iVar4) {
    iVar10 = local_20;
    iVar12 = local_24;
    local_30 = iVar9;
    do {
      iVar9 = 0;
      if (local_38 < iVar5) {
        local_3c = 1;
        iVar5 = local_34 * 0x50 + param_1;
        local_4 = iVar5;
        do {
          cVar1 = *(char *)(iVar5 + 0x28 + iVar9);
          if ((cVar1 == '+') || (cVar1 == '-')) {
            uVar3 = 0x31;
LAB_004f985f:
            if (*(char *)(iVar5 + 0x29 + iVar9) == '@') {
              *(undefined1 *)(iVar5 + 0x29 + iVar9) = uVar3;
            }
            if (*(char *)(iVar5 + 0x27 + iVar9) == '@') {
              *(undefined1 *)(iVar5 + 0x27 + iVar9) = uVar3;
            }
            if (*(char *)(iVar5 + 0x78 + iVar9) == '@') {
              *(undefined1 *)(iVar5 + 0x78 + iVar9) = uVar3;
            }
            if (*(char *)(iVar5 + -0x28 + iVar9) == '@') {
              *(undefined1 *)(iVar5 + -0x28 + iVar9) = uVar3;
            }
          }
          else if (cVar1 == '.') {
            uVar3 = 0x57;
            goto LAB_004f985f;
          }
          iVar4 = FUN_004ef4b0(*(void **)(param_1 + 0x10),local_38,local_30);
          if ((iVar4 != 0) && (*(int *)(iVar4 + 8) != 0)) {
            iVar4 = FUN_004f3b10(iVar4,1);
            if (iVar4 != -1) {
              this = (void *)FUN_004e4140(iVar4);
              if (this != (void *)0x0) {
                FUN_004e4160(this,&local_c,&local_8);
                if (local_c == 1) {
                  iVar10 = iVar9;
                  local_24 = iVar9;
LAB_004f9924:
                  iVar12 = local_24;
                  local_20 = iVar10;
                }
                else {
                  if (local_c == 2) {
                    local_24 = iVar9;
LAB_004f991c:
                    iVar10 = local_3c;
                    goto LAB_004f9924;
                  }
                  if (local_c == 3) {
                    local_24 = iVar9 + -1;
                    goto LAB_004f991c;
                  }
                  if (local_c == 4) {
                    local_24 = iVar9 + -2;
                    goto LAB_004f991c;
                  }
                }
                if (local_8 == 1) {
                  local_2c = local_34;
                  local_28 = local_34;
                }
                else {
                  if (local_8 == 2) {
                    local_2c = local_34;
LAB_004f9970:
                    local_28 = local_34 + 1;
                  }
                  else {
                    if (local_8 == 3) {
                      local_2c = local_34 + -1;
                      goto LAB_004f9970;
                    }
                    if (local_8 == 4) {
                      local_2c = local_34 + -2;
                      goto LAB_004f9970;
                    }
                  }
                  if (local_28 < local_2c) goto LAB_004f99ca;
                }
                puVar8 = (undefined4 *)(local_2c * 0x50 + iVar12 + 0x28 + param_1);
                iVar5 = (local_28 - local_2c) + 1;
                do {
                  if (iVar12 <= iVar10) {
                    uVar6 = (iVar10 - iVar12) + 1;
                    puVar11 = puVar8;
                    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                      *puVar11 = 0x78787878;
                      puVar11 = puVar11 + 1;
                    }
                    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
                      *(undefined1 *)puVar11 = 0x78;
                      puVar11 = (undefined4 *)((int)puVar11 + 1);
                    }
                    iVar10 = local_20;
                    iVar12 = local_24;
                  }
                  puVar8 = puVar8 + 0x14;
                  iVar5 = iVar5 + -1;
                } while (iVar5 != 0);
                iVar5 = local_4;
              }
            }
          }
LAB_004f99ca:
          iVar9 = iVar9 + 1;
          local_3c = local_3c + 1;
          local_38 = local_38 + 1;
        } while (local_38 < local_1c);
        local_38 = local_18;
        iVar5 = local_1c;
        iVar4 = local_14;
      }
      local_34 = local_34 + 1;
      local_30 = local_30 + 1;
    } while (local_30 < iVar4);
  }
  return;
}

