// rea decompile_all
// name: Sprite_Load
// address: 0x53c7f0
// body: available
// range: 0x53c7f0-0x53ce99 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
Sprite_Load(void *this,void *param_1,void *param_2,LPCSTR param_3,undefined4 *param_4,int param_5,
           void *param_6,int param_7)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  void *pvVar4;
  char *pcVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint uVar13;
  char *pcVar14;
  undefined4 *puVar15;
  LPCSTR pCVar16;
  int iVar17;
  FILE *local_348;
  int local_344;
  int local_338;
  void *local_334;
  uint local_330;
  byte local_32c;
  undefined4 local_32b [7];
  char local_30c [768];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
                    /* Loads a .spr header/payload, handles palette and lazy/raw/RLE modes. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055adb3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_334 = this;
  FUN_0053a1e0(this);
  local_4 = 0;
  *(undefined ***)this = &PTR_FUN_0055c82c;
  bVar2 = false;
  *(undefined1 *)((int)this + 0x38) = 0;
  *(undefined1 *)((int)this + 0x39) = 1;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined1 *)((int)this + 0x36) = 0xff;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined1 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (*param_3 == '\0') {
LAB_0053c869:
    *param_4 = 0x12d;
    ExceptionList = local_c;
    return this;
  }
  if (param_2 == (void *)0x0) {
    local_348 = (FILE *)FUN_0054dfe0(param_3,&DAT_00563184);
    if (local_348 == (FILE *)0x0) {
      if (param_4 != (undefined4 *)0x0) goto LAB_0053c869;
      FUN_0048e0a0();
    }
    FUN_0054e978((char *)&local_330,1,0x21,(int *)local_348);
  }
  else {
    local_348 = (FILE *)FUN_00402290(param_2,param_3,0);
    if (local_348 == (FILE *)0x0) {
      if (param_4 != (undefined4 *)0x0) goto LAB_0053c869;
      FUN_0048e0a0();
    }
    FUN_00402750(param_2,(char *)&local_330,0x21,(int)local_348);
  }
  puVar12 = local_32b;
  puVar15 = this;
  for (iVar9 = 7; puVar15 = puVar15 + 1, iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar15 = *puVar12;
    puVar12 = puVar12 + 1;
  }
  if ((*(byte *)((int)this + 5) & 0x40) != 0) {
    bVar2 = true;
    if (param_6 == (void *)0x0) {
      FUN_0048e0a0();
    }
    local_32c = *(byte *)((int)this + 5);
    *(byte *)((int)this + 5) = local_32c & 0xbf;
    local_32c = local_32c & 0xbf;
  }
  if (*(byte *)((int)this + 5) < 0x80) {
    *(undefined1 *)((int)this + 0x34) = 1;
    if (local_32c != 8) {
      uVar13 = local_330;
      bVar3 = local_32c;
      goto LAB_0053c9a5;
    }
  }
  else {
    bVar3 = *(byte *)((int)this + 5) + 0x80;
    *(byte *)((int)this + 0x34) = bVar3;
    pvVar4 = operator_new((uint)bVar3 << 2);
    *(void **)((int)this + 0x24) = pvVar4;
    *(undefined1 *)((int)this + 5) = 8;
    local_32c = 8;
  }
  bVar3 = local_32c;
  if (bVar2) {
    uVar13 = local_330 + (uint)*(byte *)((int)this + 0x34) * 4;
  }
  else {
    uVar13 = (uint)*(byte *)((int)this + 0x34) * 0x300 + local_330;
  }
LAB_0053c9a5:
  if (((int)uVar13 < 0) || (0x40000000 < (int)uVar13)) {
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0x12e;
      ExceptionList = local_c;
      return this;
    }
    FUN_0048e0a0();
  }
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  if ((param_5 == 0) || (param_2 == (void *)0x0)) {
    pvVar4 = operator_new(uVar13);
    *(void **)((int)this + 0x2c) = pvVar4;
    if (pvVar4 == (void *)0x0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 0x12f;
        ExceptionList = local_c;
        return this;
      }
      FUN_0048e0a0();
    }
    if (param_2 == (void *)0x0) {
      FUN_0054e978(*(char **)((int)this + 0x2c),1,uVar13,(int *)local_348);
      FUN_0054dee4(local_348);
    }
    else {
      FUN_00402750(param_2,*(char **)((int)this + 0x2c),uVar13,(int)local_348);
      FUN_00402990(param_2,(int)local_348);
    }
    if (bVar3 == 8) {
      if ((*(char *)((int)param_1 + 0x18) == '\0') || ((*(byte *)((int)this + 4) & 0x10) != 0)) {
        iVar9 = 0;
      }
      else {
        iVar9 = 1;
      }
      if (*(byte *)((int)this + 0x34) < 2) {
        if (bVar2) {
          local_338 = *(int *)(*(int *)((int)this + 0x2c) + local_330);
          uVar8 = FUN_00535d50(param_6,local_338);
          *(undefined4 *)((int)this + 0x20) = uVar8;
        }
        else {
          pvVar4 = operator_new(0x20c);
          local_4._0_1_ = 3;
          if (pvVar4 == (void *)0x0) {
            local_4 = (uint)local_4._1_3_ << 8;
            *(undefined4 *)((int)this + 0x20) = 0;
          }
          else {
            piVar7 = FUN_00535d70(pvVar4,iVar9,
                                  (undefined4 *)(*(int *)((int)this + 0x2c) + local_330),param_7);
            local_4 = (uint)local_4._1_3_ << 8;
            *(int **)((int)this + 0x20) = piVar7;
          }
        }
      }
      else {
        iVar6 = 0;
        if (*(byte *)((int)this + 0x34) != 0) {
          iVar17 = 0;
          do {
            if (bVar2) {
              local_338 = *(int *)(*(int *)((int)this + 0x2c) + iVar6 * 4 + local_330);
              uVar8 = FUN_00535d50(param_6,local_338);
              *(undefined4 *)((int)this + 0x20) = uVar8;
            }
            else {
              pvVar4 = operator_new(0x20c);
              local_4._0_1_ = 4;
              if (pvVar4 == (void *)0x0) {
                piVar7 = (int *)0x0;
              }
              else {
                piVar7 = FUN_00535d70(pvVar4,iVar9,
                                      (undefined4 *)
                                      (iVar17 + *(int *)((int)this + 0x2c) + local_330),param_7);
              }
              local_4 = (uint)local_4._1_3_ << 8;
              *(int **)(*(int *)((int)this + 0x24) + iVar6 * 4) = piVar7;
            }
            iVar6 = iVar6 + 1;
            iVar17 = iVar17 + 0x300;
          } while (iVar6 < (int)(uint)*(byte *)((int)this + 0x34));
        }
        *(undefined4 *)((int)this + 0x20) = **(undefined4 **)((int)this + 0x24);
      }
      *(undefined1 *)((int)this + 0x35) = 0;
      *(int *)((int)this + 0x28) = *(int *)((int)this + 0x20) + 4;
    }
    if ((*(byte *)((int)this + 4) & 0x10) == 0) {
      Sprite_ConvertRGB555to565(this,param_1);
    }
  }
  else {
    if (bVar3 == 8) {
      if (bVar2) {
        iVar9 = (uint)*(byte *)((int)this + 0x34) << 2;
      }
      else {
        iVar9 = (uint)*(byte *)((int)this + 0x34) * 0x300;
      }
    }
    else {
      iVar9 = 0;
    }
    uVar10 = 0xffffffff;
    *(undefined4 *)((int)this + 0x2c) = 0;
    *(undefined1 *)((int)this + 0x38) = 1;
    *(undefined1 *)((int)this + 0x39) = 0;
    pCVar16 = param_3;
    do {
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      cVar1 = *pCVar16;
      pCVar16 = pCVar16 + 1;
    } while (cVar1 != '\0');
    pcVar5 = operator_new(~uVar10);
    uVar10 = 0xffffffff;
    *(char **)((int)this + 0x3c) = pcVar5;
    do {
      pcVar14 = param_3;
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      pcVar14 = param_3 + 1;
      cVar1 = *param_3;
      param_3 = pcVar14;
    } while (cVar1 != '\0');
    uVar10 = ~uVar10;
    pcVar14 = pcVar14 + -uVar10;
    for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar14;
      pcVar14 = pcVar14 + 4;
      pcVar5 = pcVar5 + 4;
    }
    iVar6 = uVar13 - iVar9;
    for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *pcVar5 = *pcVar14;
      pcVar14 = pcVar14 + 1;
      pcVar5 = pcVar5 + 1;
    }
    *(undefined4 *)((int)this + 0x40) = 0x21;
    *(int *)((int)this + 0x44) = iVar6;
    *(void **)((int)this + 0x48) = param_2;
    if (iVar9 == 0) {
      FUN_00402990(param_2,(int)local_348);
    }
    else if (*(char *)((int)this + 0x34) == '\x01') {
      if ((*(char *)((int)param_1 + 0x18) == '\0') || ((*(byte *)((int)this + 4) & 0x10) != 0)) {
        iVar9 = 0;
      }
      else {
        iVar9 = 1;
      }
      FUN_00540000(iVar6 + 0x21,(int)local_348,0);
      if (bVar2) {
        FUN_00402750(param_2,(char *)&local_338,4,(int)local_348);
        piVar7 = (int *)FUN_00535d50(param_6,local_338);
      }
      else {
        FUN_00402750(param_2,local_30c,0x300,(int)local_348);
        pvVar4 = operator_new(0x20c);
        local_4._0_1_ = 1;
        if (pvVar4 == (void *)0x0) {
          piVar7 = (int *)0x0;
        }
        else {
          piVar7 = FUN_00535d70(pvVar4,iVar9,(undefined4 *)local_30c,param_7);
        }
        local_4 = (uint)local_4._1_3_ << 8;
      }
      *(int **)((int)this + 0x20) = piVar7;
      *(undefined1 *)((int)this + 0x35) = 0;
      *(int **)((int)this + 0x28) = piVar7 + 1;
      FUN_00402990(param_2,(int)local_348);
    }
    else {
      if ((*(char *)((int)param_1 + 0x18) == '\0') ||
         (local_344 = 1, (*(byte *)((int)this + 4) & 0x10) != 0)) {
        local_344 = 0;
      }
      FUN_00540000(iVar6 + 0x21,(int)local_348,0);
      iVar9 = 0;
      if (*(char *)((int)this + 0x34) != '\0') {
        do {
          if (bVar2) {
            FUN_00402750(param_2,(char *)&local_338,4,(int)local_348);
            uVar8 = FUN_00535d50(param_6,local_338);
            *(undefined4 *)(*(int *)((int)this + 0x24) + iVar9 * 4) = uVar8;
          }
          else {
            FUN_00402750(param_2,local_30c,0x300,(int)local_348);
            pvVar4 = operator_new(0x20c);
            local_4._0_1_ = 2;
            if (pvVar4 == (void *)0x0) {
              piVar7 = (int *)0x0;
            }
            else {
              piVar7 = FUN_00535d70(pvVar4,local_344,(undefined4 *)local_30c,param_7);
            }
            local_4 = (uint)local_4._1_3_ << 8;
            *(int **)(*(int *)((int)this + 0x24) + iVar9 * 4) = piVar7;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)(uint)*(byte *)((int)this + 0x34));
      }
      iVar9 = **(int **)((int)this + 0x24);
      *(int *)((int)this + 0x20) = iVar9;
      *(undefined1 *)((int)this + 0x35) = 0;
      *(int *)((int)this + 0x28) = iVar9 + 4;
      FUN_00402990(param_2,(int)local_348);
    }
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  ExceptionList = local_c;
  return this;
}

