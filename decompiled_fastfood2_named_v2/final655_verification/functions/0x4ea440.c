// rea decompile_all
// name: FUN_004ea440
// address: 0x4ea440
// body: available
// range: 0x4ea440-0x4eaa05 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall FUN_004ea440(int param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  undefined4 *puVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *local_128;
  int local_124;
  void *local_120;
  int local_11c;
  uint local_118;
  uint local_114;
  void *local_110;
  char local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00559ee4;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(param_1 + 0x2bf44) == 0) {
    ExceptionList = &local_c;
    FUN_0048e0a0();
  }
  piVar3 = FUN_00402290(*(void **)(param_1 + 0x2bf44),s_Isodaten_idx_00571908,0);
  piVar1 = (int *)(param_1 + 0x20);
  FUN_00402750(*(void **)(param_1 + 0x2bf44),(char *)piVar1,4,(int)piVar3);
  FUN_0052fd00(DAT_0057c5f4,0x3f7,0,*piVar1,0);
  local_114 = 0;
  if (0 < *piVar1) {
    local_128 = (char *)(param_1 + 0x25);
    do {
      if ((local_114 & 0xf) == 0) {
        FUN_0052fd70(DAT_0057c5f4,0x3f7,local_114,0);
        FUN_00525a10(DAT_0057c5e0,0);
      }
      FUN_00402750(*(void **)(param_1 + 0x2bf44),local_128 + -1,1,(int)piVar3);
      FUN_00402750(*(void **)(param_1 + 0x2bf44),local_128,0x32,(int)piVar3);
      local_120 = operator_new(0x50);
      local_4 = 0;
      if (local_120 == (void *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = FUN_0053c7f0(local_120,DAT_0057c5c8,*(void **)(param_1 + 0x2bf44),local_128,
                              &local_124,1,*(void **)(param_1 + 0x1c),0);
      }
      *(undefined4 **)(local_128 + 0x33) = puVar4;
      local_4 = 0xffffffff;
      if (local_124 != 0) {
        FUN_0048e0a0();
      }
      FUN_00402750(*(void **)(param_1 + 0x2bf44),(char *)&local_11c,4,(int)piVar3);
      if (local_11c == 1) {
        uVar6 = 0xffffffff;
        pcVar5 = local_128;
        do {
          pcVar10 = pcVar5;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar10 = pcVar5 + 1;
          cVar2 = *pcVar5;
          pcVar5 = pcVar10;
        } while (cVar2 != '\0');
        uVar6 = ~uVar6;
        pcVar5 = pcVar10 + -uVar6;
        pcVar10 = local_10c;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar10 = pcVar10 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar10 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar10 = pcVar10 + 1;
        }
        FUN_004e6420(local_10c);
        uVar6 = 0xffffffff;
        pcVar5 = &DAT_005718d8;
        do {
          pcVar10 = pcVar5;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar10 = pcVar5 + 1;
          cVar2 = *pcVar5;
          pcVar5 = pcVar10;
        } while (cVar2 != '\0');
        uVar6 = ~uVar6;
        iVar8 = -1;
        pcVar5 = local_10c;
        do {
          pcVar9 = pcVar5;
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          pcVar9 = pcVar5 + 1;
          cVar2 = *pcVar5;
          pcVar5 = pcVar9;
        } while (cVar2 != '\0');
        pcVar5 = pcVar10 + -uVar6;
        pcVar10 = pcVar9 + -1;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar10 = pcVar10 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar10 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar10 = pcVar10 + 1;
        }
        local_120 = operator_new(0x50);
        local_4 = 1;
        if (local_120 == (void *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          puVar4 = FUN_0053c7f0(local_120,DAT_0057c5c8,*(void **)(param_1 + 0x2bf44),local_10c,
                                &local_124,1,*(void **)(param_1 + 0x1c),0);
        }
        local_4 = 0xffffffff;
        *(undefined4 **)(local_128 + 0x37) = puVar4;
        if (local_124 != 0) {
          FUN_0048e0a0();
        }
      }
      else {
        local_128[0x37] = '\0';
        local_128[0x38] = '\0';
        local_128[0x39] = '\0';
        local_128[0x3a] = '\0';
      }
      FUN_00402750(*(void **)(param_1 + 0x2bf44),(char *)&local_11c,4,(int)piVar3);
      if (local_11c == 1) {
        uVar6 = 0xffffffff;
        pcVar5 = local_128;
        do {
          pcVar10 = pcVar5;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar10 = pcVar5 + 1;
          cVar2 = *pcVar5;
          pcVar5 = pcVar10;
        } while (cVar2 != '\0');
        uVar6 = ~uVar6;
        pcVar5 = pcVar10 + -uVar6;
        pcVar10 = local_10c;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar10 = pcVar10 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar10 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar10 = pcVar10 + 1;
        }
        FUN_004e6420(local_10c);
        uVar6 = 0xffffffff;
        pcVar5 = &DAT_005718d0;
        do {
          pcVar10 = pcVar5;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar10 = pcVar5 + 1;
          cVar2 = *pcVar5;
          pcVar5 = pcVar10;
        } while (cVar2 != '\0');
        uVar6 = ~uVar6;
        iVar8 = -1;
        pcVar5 = local_10c;
        do {
          pcVar9 = pcVar5;
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          pcVar9 = pcVar5 + 1;
          cVar2 = *pcVar5;
          pcVar5 = pcVar9;
        } while (cVar2 != '\0');
        pcVar5 = pcVar10 + -uVar6;
        pcVar10 = pcVar9 + -1;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar10 = pcVar10 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar10 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar10 = pcVar10 + 1;
        }
        local_120 = operator_new(0x50);
        local_4 = 2;
        if (local_120 == (void *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          puVar4 = FUN_0053c7f0(local_120,DAT_0057c5c8,*(void **)(param_1 + 0x2bf44),local_10c,
                                &local_124,1,*(void **)(param_1 + 0x1c),0);
        }
        local_4 = 0xffffffff;
        *(undefined4 **)(local_128 + 0x3b) = puVar4;
        if (local_124 != 0) {
          FUN_0048e0a0();
        }
      }
      else {
        local_128[0x3b] = '\0';
        local_128[0x3c] = '\0';
        local_128[0x3d] = '\0';
        local_128[0x3e] = '\0';
      }
      FUN_00402750(*(void **)(param_1 + 0x2bf44),(char *)&local_11c,4,(int)piVar3);
      if (local_11c == 1) {
        uVar6 = 0xffffffff;
        pcVar5 = local_128;
        do {
          pcVar10 = pcVar5;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar10 = pcVar5 + 1;
          cVar2 = *pcVar5;
          pcVar5 = pcVar10;
        } while (cVar2 != '\0');
        uVar6 = ~uVar6;
        pcVar5 = pcVar10 + -uVar6;
        pcVar10 = local_10c;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar10 = pcVar10 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar10 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar10 = pcVar10 + 1;
        }
        FUN_004e6420(local_10c);
        uVar6 = 0xffffffff;
        pcVar5 = &DAT_005718c8;
        do {
          pcVar10 = pcVar5;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar10 = pcVar5 + 1;
          cVar2 = *pcVar5;
          pcVar5 = pcVar10;
        } while (cVar2 != '\0');
        uVar6 = ~uVar6;
        iVar8 = -1;
        pcVar5 = local_10c;
        do {
          pcVar9 = pcVar5;
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          pcVar9 = pcVar5 + 1;
          cVar2 = *pcVar5;
          pcVar5 = pcVar9;
        } while (cVar2 != '\0');
        pcVar5 = pcVar10 + -uVar6;
        pcVar10 = pcVar9 + -1;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar10 = pcVar10 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar10 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar10 = pcVar10 + 1;
        }
        local_120 = operator_new(0x50);
        local_4 = 3;
        if (local_120 == (void *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          puVar4 = FUN_0053c7f0(local_120,DAT_0057c5c8,*(void **)(param_1 + 0x2bf44),local_10c,
                                &local_124,1,*(void **)(param_1 + 0x1c),0);
        }
        local_4 = 0xffffffff;
        *(undefined4 **)(local_128 + 0x3f) = puVar4;
        if (local_124 != 0) {
          FUN_0048e0a0();
        }
      }
      else {
        local_128[0x3f] = '\0';
        local_128[0x40] = '\0';
        local_128[0x41] = '\0';
        local_128[0x42] = '\0';
      }
      FUN_00402750(*(void **)(param_1 + 0x2bf44),(char *)&local_118,4,(int)piVar3);
      if ((int)local_118 < 1) {
        local_128[0x43] = '\0';
        local_128[0x44] = '\0';
        local_128[0x45] = '\0';
        local_128[0x46] = '\0';
      }
      else {
        local_120 = operator_new(0x1c);
        local_4 = 4;
        if (local_120 == (void *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          puVar4 = FUN_004013a0(local_120,local_118);
        }
        *(undefined4 **)(local_128 + 0x43) = puVar4;
        local_4 = 0xffffffff;
        local_120 = (void *)0x0;
        if (0 < (int)local_118) {
          do {
            pcVar5 = operator_new(0x4c);
            FUN_00402750(*(void **)(param_1 + 0x2bf44),pcVar5,1,(int)piVar3);
            FUN_00402750(*(void **)(param_1 + 0x2bf44),pcVar5 + 1,1,(int)piVar3);
            FUN_00402750(*(void **)(param_1 + 0x2bf44),pcVar5 + 2,1,(int)piVar3);
            FUN_00402750(*(void **)(param_1 + 0x2bf44),pcVar5 + 3,1,(int)piVar3);
            FUN_00402750(*(void **)(param_1 + 0x2bf44),pcVar5 + 4,0xf,(int)piVar3);
            FUN_00402750(*(void **)(param_1 + 0x2bf44),pcVar5 + 0x13,0x32,(int)piVar3);
            local_110 = operator_new(0x98);
            local_4 = 5;
            if (local_110 == (void *)0x0) {
              puVar4 = (undefined4 *)0x0;
            }
            else {
              puVar4 = Anim_Load(local_110,(int)DAT_0057c5c8,*(void **)(param_1 + 0x2bf44),
                                 pcVar5 + 0x13,&local_124,1);
            }
            *(undefined4 **)(pcVar5 + 0x48) = puVar4;
            local_4 = 0xffffffff;
            FUN_004014b0(*(void **)(local_128 + 0x43),pcVar5);
            local_120 = (void *)((int)local_120 + 1);
          } while ((int)local_120 < (int)local_118);
        }
      }
      local_114 = local_114 + 1;
      local_128 = local_128 + 0x48;
    } while ((int)local_114 < *(int *)(param_1 + 0x20));
  }
  FUN_00402990(*(void **)(param_1 + 0x2bf44),(int)piVar3);
  ExceptionList = local_c;
  return 1;
}

