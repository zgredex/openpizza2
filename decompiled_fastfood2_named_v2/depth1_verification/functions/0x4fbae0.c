// rea decompile_all
// name: Map_BuildObjectGrid
// address: 0x4fbae0
// body: available
// range: 0x4fbae0-0x4fbed8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Map_BuildObjectGrid(void *param_1,undefined4 *param_2)

{
  short sVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined3 extraout_var;
  void *this;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  short *local_4c;
  short *local_48;
  short *local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  short *local_2c;
  int local_28;
  short *local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 *local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Depth-1 proposal batch 3/4. */
  iVar7 = 0x50;
  puVar3 = param_2;
  do {
    iVar6 = 0x50;
    do {
      *(undefined2 *)(puVar3 + 1) = 0xffff;
      *puVar3 = 0;
      puVar3 = puVar3 + 2;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  FUN_004f3b30(param_1,&local_18,&local_1c,&local_c,&local_10);
  local_40 = local_c;
  iVar7 = local_18;
  iVar6 = local_1c;
  iVar4 = local_10;
  iVar9 = local_c;
  if (local_c < local_10) {
    iVar8 = 0;
    local_14 = param_2 + 0x9f;
    do {
      iVar10 = 0;
      if (iVar7 < iVar6) {
        do {
          iVar6 = FUN_004ef4b0(param_1,iVar7,local_40);
          if ((iVar6 != 0) && (*(int *)(iVar6 + 8) != 0)) {
            iVar6 = FUN_004f3b10(iVar6,0);
            iVar4 = FUN_004f2aa0(iVar6);
            if (iVar4 == 0) {
              bVar2 = FUN_004f2a60(iVar6);
              if (CONCAT31(extraout_var,bVar2) == 0) {
                iVar4 = FUN_004f2a80(iVar6);
                if (iVar4 == 0) {
                  iVar6 = FUN_004f29d0(iVar6);
                  if (iVar6 != 0) goto LAB_004fbbdd;
                }
                else {
                  *(undefined2 *)(param_2 + (iVar8 + iVar10) * 2 + 1) = 0xfffd;
                }
              }
              else {
                *(undefined2 *)(param_2 + (iVar8 + iVar10) * 2 + 1) = 0xfffe;
              }
            }
            else {
LAB_004fbbdd:
              *(undefined2 *)(param_2 + (iVar8 + iVar10) * 2 + 1) = 0;
            }
          }
          iVar10 = iVar10 + 1;
          iVar7 = iVar7 + 1;
        } while (iVar7 < local_1c);
        iVar7 = local_18;
        iVar6 = local_1c;
        iVar4 = local_10;
        iVar9 = local_c;
      }
      iVar8 = iVar8 + 0x50;
      *(undefined2 *)local_14 = 0xffff;
      local_14 = local_14 + 0xa0;
      local_40 = local_40 + 1;
    } while (local_40 < iVar4);
  }
  local_38 = 0;
  local_40 = iVar9;
  if (iVar4 <= iVar9) {
    return;
  }
  do {
    iVar9 = 0;
    if (iVar7 < iVar6) {
      local_20 = 1;
      local_44 = (short *)(param_2 + local_38 * 0xa0 + -0x9f);
      local_48 = (short *)(param_2 + local_38 * 0xa0 + 0xa1);
      local_2c = (short *)(param_2 + local_38 * 0xa0 + -1);
      local_24 = (short *)(param_2 + local_38 * 0xa0 + 3);
      local_4c = (short *)(param_2 + local_38 * 0xa0 + 1);
      local_14 = (undefined4 *)iVar7;
      do {
        sVar1 = *local_4c;
        if (((sVar1 == 0) || (sVar1 == -2)) || (sVar1 == -3)) {
          if (*local_24 == -1) {
            *local_24 = 9;
          }
          if (*local_2c == -1) {
            *local_2c = 9;
          }
          if (*local_48 == -1) {
            *local_48 = 9;
          }
          if (*local_44 == -1) {
            *local_44 = 9;
          }
        }
        iVar7 = FUN_004ef4b0(param_1,(int)local_14,local_40);
        if (((iVar7 != 0) && (*(int *)(iVar7 + 8) != 0)) &&
           ((iVar7 = FUN_004f3b10(iVar7,1), iVar7 != -1 &&
            (this = (void *)FUN_004e4140(iVar7), this != (void *)0x0)))) {
          FUN_004e4160(this,&local_8,&local_4);
          if (local_8 == 1) {
            local_3c = iVar9;
            local_28 = iVar9;
          }
          else {
            if (local_8 == 2) {
              local_3c = iVar9;
            }
            else if (local_8 == 3) {
              local_3c = iVar9 + -1;
            }
            else {
              if (local_8 != 4) goto LAB_004fbd7e;
              local_3c = iVar9 + -2;
            }
            local_28 = local_20;
          }
LAB_004fbd7e:
          if (local_4 == 1) {
            local_34 = local_38;
            local_30 = local_38;
          }
          else {
            if (local_4 == 2) {
              local_34 = local_38;
LAB_004fbdc6:
              local_30 = local_38 + 1;
            }
            else {
              if (local_4 == 3) {
                local_34 = local_38 + -1;
                goto LAB_004fbdc6;
              }
              if (local_4 == 4) {
                local_34 = local_38 + -2;
                goto LAB_004fbdc6;
              }
            }
            if (local_30 < local_34) goto LAB_004fbe98;
          }
          puVar3 = param_2 + (local_34 * 0x50 + local_3c) * 2;
          iVar7 = (local_30 - local_34) + 1;
          do {
            if (local_3c <= local_28) {
              iVar6 = (local_28 - local_3c) + 1;
              puVar5 = puVar3;
              do {
                *puVar5 = this;
                *(short *)(puVar5 + 1) = (short)*(undefined4 *)((int)this + 8);
                puVar5 = puVar5 + 2;
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
            puVar3 = puVar3 + 0xa0;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
LAB_004fbe98:
        local_20 = local_20 + 1;
        local_24 = local_24 + 4;
        local_2c = local_2c + 4;
        local_44 = local_44 + 4;
        local_48 = local_48 + 4;
        local_4c = local_4c + 4;
        iVar9 = iVar9 + 1;
        local_14 = (undefined4 *)((int)local_14 + 1);
      } while ((int)local_14 < local_1c);
      iVar7 = local_18;
      iVar6 = local_1c;
      iVar4 = local_10;
    }
    local_38 = local_38 + 1;
    local_40 = local_40 + 1;
    if (iVar4 <= local_40) {
      return;
    }
  } while( true );
}

