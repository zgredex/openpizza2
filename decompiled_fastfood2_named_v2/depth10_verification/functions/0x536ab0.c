// rea decompile_all
// name: FUN_00536ab0
// address: 0x536ab0
// body: available
// range: 0x536ab0-0x536e93 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00536ab0(void *this,int param_1,char *param_2,void *param_3)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  char *pcVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  char *pcVar12;
  byte *pbVar13;
  FILE *local_39c;
  uint local_398;
  int local_394;
  void *local_390;
  char local_38c [3];
  char cStack_389;
  undefined2 local_388;
  undefined1 uStack_386;
  undefined1 uStack_385;
  ushort local_384;
  ushort uStack_382;
  uint local_34b;
  char local_30c [768];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055acfe;
  local_c = ExceptionList;
  uVar6 = 0xffffffff;
  pcVar4 = (char *)((int)this + 0x1c);
  do {
    pcVar10 = param_2;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar10;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar10 = pcVar10 + -uVar6;
  pcVar12 = pcVar4;
  ExceptionList = &local_c;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
    pcVar10 = pcVar10 + 4;
    pcVar12 = pcVar12 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar12 = *pcVar10;
    pcVar10 = pcVar10 + 1;
    pcVar12 = pcVar12 + 1;
  }
  if (param_3 == (void *)0x0) {
    local_39c = (FILE *)FUN_0054dfe0(pcVar4,&DAT_00563184);
    if (local_39c == (FILE *)0x0) {
      FUN_00403510();
      ExceptionList = local_c;
      return 0;
    }
    FUN_0054e978(local_38c,1,0x80,(int *)local_39c);
  }
  else {
    local_39c = (FILE *)FUN_00402290(param_3,pcVar4,0);
    if (local_39c == (FILE *)0x0) {
      FUN_00403510();
      ExceptionList = local_c;
      return 0;
    }
    FUN_00402750(param_3,local_38c,0x80,(int)local_39c);
  }
  iVar8 = ((uint)local_384 - (CONCAT12(uStack_386,local_388) & 0xffff)) + 1;
  *(int *)((int)this + 4) = iVar8;
  iVar9 = ((uint)uStack_382 - (uint)CONCAT11(uStack_385,uStack_386)) + 1;
  cVar1 = (char)local_34b;
  *(int *)((int)this + 8) = iVar9;
  if (((cVar1 == '\x01') || (cVar1 == '\x03')) && (cStack_389 == '\b')) {
    if (cVar1 == '\x01') {
      *(undefined1 *)((int)this + 0x10) = 8;
      *(undefined1 *)((int)this + 0x11) = 1;
    }
    else {
      *(undefined1 *)((int)this + 0x10) = 0x18;
      *(undefined1 *)((int)this + 0x11) = 3;
    }
    iVar8 = (uint)*(byte *)((int)this + 0x11) * iVar9 * iVar8;
    *(int *)((int)this + 0xc) = iVar8;
    pvVar3 = operator_new((iVar8 >> 1) * 2 + 2);
    *(void **)((int)this + 0x18) = pvVar3;
    local_394 = 0;
    if (0 < *(int *)((int)this + 8)) {
      do {
        iVar9 = 0;
        uVar6 = (uint)*(byte *)((int)this + 0x11);
        if (uVar6 != 0) {
          uVar7 = local_34b >> 8;
          do {
            uVar11 = 0;
            pbVar13 = (byte *)(((local_394 * *(int *)((int)this + 4) + 1) * uVar6 - iVar9) + -1 +
                              *(int *)((int)this + 0x18));
            if ((short)uVar7 != 0) {
              do {
                if ((int)(uint)*(byte *)((int)this + 0x11) <= iVar9) break;
                if (param_3 == (void *)0x0) {
                  local_398 = CRT_Fgetc(&local_39c->_ptr);
                }
                else {
                  local_398 = 0;
                  FUN_00402750(param_3,(char *)&local_398,1,(int)local_39c);
                }
                if (((byte)local_398 & 0xc0) == 0xc0) {
                  local_390 = (void *)(local_398 & 0x3f);
                  if (param_3 == (void *)0x0) {
                    local_398 = CRT_Fgetc(&local_39c->_ptr);
                  }
                  else {
                    local_398 = 0;
                    FUN_00402750(param_3,(char *)&local_398,1,(int)local_39c);
                  }
                  if (0 < (int)local_390) {
                    pvVar3 = local_390;
                    do {
                      if ((int)uVar11 < *(int *)((int)this + 4)) {
                        *pbVar13 = (byte)local_398;
                      }
                      pbVar13 = pbVar13 + *(byte *)((int)this + 0x11);
                      uVar11 = uVar11 + 1;
                      if (uVar11 == (local_34b >> 8 & 0xffff)) {
                        iVar9 = iVar9 + 1;
                        uVar11 = 0;
                        pbVar13 = (byte *)(((local_394 * *(int *)((int)this + 4) + 1) *
                                            (uint)*(byte *)((int)this + 0x11) - iVar9) + -1 +
                                          *(int *)((int)this + 0x18));
                      }
                      pvVar3 = (void *)((int)pvVar3 - 1);
                    } while (pvVar3 != (void *)0x0);
                  }
                }
                else {
                  if ((int)uVar11 < *(int *)((int)this + 4)) {
                    *pbVar13 = (byte)local_398;
                  }
                  pbVar13 = pbVar13 + *(byte *)((int)this + 0x11);
                  uVar11 = uVar11 + 1;
                }
                uVar7 = local_34b >> 8;
              } while ((int)uVar11 < (int)(uVar7 & 0xffff));
            }
            iVar9 = iVar9 + 1;
            uVar6 = (uint)*(byte *)((int)this + 0x11);
          } while (iVar9 < (int)uVar6);
        }
        local_394 = local_394 + 1;
      } while (local_394 < *(int *)((int)this + 8));
    }
    if (*(char *)((int)this + 0x10) == '\b') {
      if (param_3 == (void *)0x0) {
        FUN_0054ede0((int *)local_39c,1,1);
        FUN_0054e978(local_30c,1,0x300,(int *)local_39c);
      }
      else {
        FUN_00540000(1,(int)local_39c,1);
        FUN_00402750(param_3,local_30c,0x300,(int)local_39c);
      }
      pcVar4 = local_30c;
      iVar9 = 0x100;
      do {
        cVar1 = pcVar4[2];
        pcVar4[2] = *pcVar4;
        *pcVar4 = cVar1;
        pcVar4 = pcVar4 + 3;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      local_390 = operator_new(0x20c);
      local_4 = 0;
      if (local_390 == (void *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = FUN_00535d70(local_390,(uint)*(byte *)(param_1 + 0x18),(undefined4 *)local_30c,0);
      }
      local_4 = 0xffffffff;
      *(int **)((int)this + 0x14) = piVar5;
    }
    if (param_3 == (void *)0x0) {
      FUN_0054dee4(local_39c);
    }
    else {
      FUN_00402990(param_3,(int)local_39c);
    }
    uVar2 = 1;
  }
  else {
    FUN_00403510();
    uVar2 = 0;
  }
  ExceptionList = local_c;
  return uVar2;
}

