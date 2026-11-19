// rea decompile_all
// name: FUN_00556d7e
// address: 0x556d7e
// body: available
// range: 0x556d7e-0x557010 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl
FUN_00556d7e(uint param_1,uint param_2,uint param_3,int param_4,byte param_5,short *param_6)

{
  short *psVar1;
  uint uVar2;
  short *psVar3;
  char cVar4;
  uint uVar5;
  short *psVar6;
  short *psVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined2 local_14;
  undefined4 local_12;
  undefined4 local_e;
  undefined1 local_a;
  char cStack_9;
  undefined4 local_8;
  
  psVar3 = param_6;
  uVar5 = param_3 & 0x7fff;
  local_20 = 0xcc;
  local_1f = 0xcc;
  local_1e = 0xcc;
  local_1d = 0xcc;
  local_1c = 0xcc;
  local_1b = 0xcc;
  local_1a = 0xcc;
  local_19 = 0xcc;
  local_18 = 0xcc;
  local_17 = 0xcc;
  local_16 = 0xfb;
  local_15 = 0x3f;
  local_8 = 1;
  if ((param_3 & 0x8000) == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if ((((short)uVar5 == 0) && (param_2 == 0)) && (param_1 == 0)) {
LAB_00556df5:
    *psVar3 = 0;
    *(undefined1 *)(psVar3 + 1) = 0x20;
    *(undefined1 *)((int)psVar3 + 3) = 1;
    *(undefined1 *)(psVar3 + 2) = 0x30;
  }
  else {
    if ((short)uVar5 == 0x7fff) {
      *param_6 = 1;
      if (((param_2 == 0x80000000) && (param_1 == 0)) || ((param_2 & 0x40000000) != 0)) {
        if (((param_3 & 0x8000) == 0) || (param_2 != 0xc0000000)) {
          if ((param_2 != 0x80000000) || (param_1 != 0)) goto LAB_00556e73;
          pcVar11 = "1#INF";
        }
        else {
          if (param_1 != 0) {
LAB_00556e73:
            pcVar11 = "1#QNAN";
            goto LAB_00556e78;
          }
          pcVar11 = "1#IND";
        }
        FUN_00553620((uint *)(param_6 + 2),(uint *)pcVar11);
        *(undefined1 *)((int)psVar3 + 3) = 5;
      }
      else {
        pcVar11 = "1#SNAN";
LAB_00556e78:
        FUN_00553620((uint *)(param_6 + 2),(uint *)pcVar11);
        *(undefined1 *)((int)psVar3 + 3) = 6;
      }
      local_8 = 0;
      goto LAB_00556fe4;
    }
    local_14 = 0;
    local_a = (undefined1)uVar5;
    cStack_9 = (char)(uVar5 >> 8);
    sVar8 = (short)(((uVar5 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uVar5 * 0x4d10 >>
                   0x10);
    local_e = param_2;
    local_12 = param_1;
    FUN_005574b1((int *)&local_14,-(int)sVar8,1);
    if (0x3ffe < CONCAT11(cStack_9,local_a)) {
      sVar8 = sVar8 + 1;
      FUN_00557291((int *)&local_14,(int *)&local_20);
    }
    *psVar3 = sVar8;
    if ((param_5 & 1) == 0) {
      iVar10 = param_4;
    }
    else {
      iVar10 = param_4 + sVar8;
      if (param_4 + sVar8 < 1) goto LAB_00556df5;
    }
    if (0x15 < iVar10) {
      iVar10 = 0x15;
    }
    iVar9 = CONCAT11(cStack_9,local_a) - 0x3ffe;
    local_a = 0;
    cStack_9 = '\0';
    param_6 = (short *)0x8;
    do {
      FUN_00556c5c((uint *)&local_14);
      param_6 = (short *)((int)param_6 + -1);
    } while (param_6 != (short *)0x0);
    if (iVar9 < 0) {
      param_6 = (short *)0x0;
      for (uVar5 = -iVar9 & 0xff; uVar5 != 0; uVar5 = uVar5 - 1) {
        FUN_00556c8a((uint *)&local_14);
      }
    }
    param_4 = iVar10 + 1;
    psVar6 = psVar3 + 2;
    if (0 < param_4) {
      param_6 = psVar6;
      uVar5 = local_12;
      uVar2 = local_e;
      do {
        local_e._2_2_ = (undefined2)(uVar2 >> 0x10);
        local_e._0_2_ = (undefined2)uVar2;
        local_12._2_2_ = (undefined2)(uVar5 >> 0x10);
        local_12._0_2_ = (undefined2)uVar5;
        param_1 = CONCAT22((undefined2)local_12,local_14);
        param_2 = CONCAT22((undefined2)local_e,local_12._2_2_);
        param_3 = CONCAT13(cStack_9,CONCAT12(local_a,local_e._2_2_));
        local_12 = uVar5;
        local_e = uVar2;
        FUN_00556c5c((uint *)&local_14);
        FUN_00556c5c((uint *)&local_14);
        ___add_12((uint *)&local_14,&param_1);
        FUN_00556c5c((uint *)&local_14);
        cVar4 = cStack_9;
        cStack_9 = '\0';
        psVar6 = (short *)((int)param_6 + 1);
        param_4 = param_4 + -1;
        *(char *)param_6 = cVar4 + '0';
        param_6 = psVar6;
        uVar5 = local_12;
        uVar2 = local_e;
      } while (param_4 != 0);
    }
    psVar7 = psVar6 + -1;
    psVar1 = psVar3 + 2;
    if ('4' < *(char *)((int)psVar6 + -1)) {
      for (; psVar1 <= psVar7; psVar7 = (short *)((int)psVar7 + -1)) {
        if ((char)*psVar7 != '9') {
          if (psVar1 <= psVar7) goto LAB_00556fd0;
          break;
        }
        *(char *)psVar7 = '0';
      }
      psVar7 = (short *)((int)psVar7 + 1);
      *psVar3 = *psVar3 + 1;
LAB_00556fd0:
      *(char *)psVar7 = (char)*psVar7 + '\x01';
LAB_00556fd2:
      cVar4 = ((char)psVar7 - (char)psVar3) + -3;
      *(char *)((int)psVar3 + 3) = cVar4;
      *(undefined1 *)(cVar4 + 4 + (int)psVar3) = 0;
      goto LAB_00556fe4;
    }
    for (; psVar1 <= psVar7; psVar7 = (short *)((int)psVar7 + -1)) {
      if ((char)*psVar7 != '0') {
        if (psVar1 <= psVar7) goto LAB_00556fd2;
        break;
      }
    }
    *psVar3 = 0;
    *(undefined1 *)(psVar3 + 1) = 0x20;
    *(undefined1 *)((int)psVar3 + 3) = 1;
    *(char *)psVar1 = '0';
  }
  *(undefined1 *)((int)psVar3 + 5) = 0;
  local_8 = 1;
LAB_00556fe4:
  return local_8;
}

