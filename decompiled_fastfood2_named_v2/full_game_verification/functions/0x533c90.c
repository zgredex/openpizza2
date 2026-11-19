// rea decompile_all
// name: Record_AdvanceFrameSequence
// address: 0x533c90
// body: available
// range: 0x533c90-0x53405c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
Record_AdvanceFrameSequence
          (void *this,int param_1,uint param_2,double *param_3,double *param_4,undefined4 *param_5)

{
  double *pdVar1;
  double dVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  double dVar11;
  bool bVar12;
  int iVar13;
  short sVar14;
  short *psVar15;
  int iVar16;
  int *piVar17;
  int iVar18;
  int local_30;
  
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  iVar18 = param_1 * 0x48;
  iVar13 = *(int *)((int)this + 0x4c) + iVar18;
  if (*(char *)(iVar13 + 0x3e) == '\0') {
    return 0;
  }
  local_30 = (int)*(short *)(iVar13 + 0x30);
  uVar3 = *(ushort *)(iVar13 + 0x3a);
  *(undefined2 *)(iVar13 + 0x30) = 0;
  iVar13 = *(int *)((int)this + 0x4c) + iVar18;
  if (*(char *)(iVar13 + 0x3c) == '\0') {
    *(uint *)(iVar13 + 4) = uVar3 + param_2;
    *(undefined1 *)(*(int *)((int)this + 0x4c) + 0x3c + iVar18) = 1;
  }
  else {
    if (*(char *)(iVar13 + 0x40) != '\0') {
      return 0;
    }
    piVar17 = (int *)(iVar13 + 4);
    uVar4 = *(uint *)(iVar13 + 4);
    while (uVar4 <= param_2) {
      *piVar17 = uVar4 + uVar3;
      local_30 = local_30 + 1;
      piVar17 = (int *)(*(int *)((int)this + 0x4c) + 4 + iVar18);
      uVar4 = *(uint *)(*(int *)((int)this + 0x4c) + 4 + iVar18);
    }
  }
  do {
    if (local_30 < 1) {
      return 1;
    }
    iVar13 = (int)*(short *)(*(int *)((int)this + 0x4c) + 0x34 + iVar18);
    piVar17 = (int *)(*(int *)((int)this + 0x4c) + iVar18);
    psVar15 = (short *)(*piVar17 * 0x98 + iVar13 * 6 + *(int *)((int)this + 0x50));
    if (((*(ushort *)((int)piVar17 + 0x36) & 1) == 0) || (*(char *)((int)psVar15 + 5) == '\0')) {
      bVar12 = true;
    }
    else {
      bVar12 = false;
    }
    if (bVar12) {
      if (psVar15[1] != *(short *)((int)piVar17 + 0x32)) goto LAB_00533d98;
LAB_00533dd5:
      *(ushort *)((int)piVar17 + 0x36) = *(ushort *)((int)piVar17 + 0x36) + 1;
      piVar17 = (int *)(*(int *)((int)this + 0x4c) + iVar18);
      if (*(short *)((int)piVar17 + 0x36) < (short)(char)psVar15[2]) {
        if (*(char *)((int)psVar15 + 5) != '\0') {
          *(char *)(piVar17 + 0xe) = -(char)piVar17[0xe];
          goto LAB_00533d98;
        }
        *(short *)((int)piVar17 + 0x32) = *psVar15;
      }
      else {
        iVar16 = 0;
        if (*(char *)((int)piVar17 + 0x3d) != '\0') {
LAB_00534048:
          Record_ClearFlags48(this,param_1);
          return 1;
        }
        if (*(char *)((int)piVar17 + 0x3f) == '\0') {
          while( true ) {
            iVar13 = iVar13 + 1;
            if (0xf < iVar13) {
              iVar13 = 0;
            }
            if (*(short *)(*(int *)((int)this + 0x50) + iVar13 * 6 + *piVar17 * 0x98) != -1) break;
            iVar16 = iVar16 + 1;
            if (0x11 < iVar16) goto LAB_00534048;
          }
          if (0x11 < iVar16) goto LAB_00534048;
        }
        else if (((psVar15[1] == *psVar15) &&
                 (*(double *)(*(int *)((int)this + 0x50) + 0x60 + *piVar17 * 0x98) == 0.0)) &&
                (*(double *)(*(int *)((int)this + 0x50) + *piVar17 * 0x98 + 0x68) == 0.0)) {
          *(undefined1 *)(piVar17 + 0x10) = 1;
          local_30 = 1;
        }
        if (iVar13 == *(short *)(*(int *)((int)this + 0x4c) + 0x34 + iVar18)) {
          *(undefined1 *)(*(int *)((int)this + 0x4c) + iVar18 + 0x3f) = 1;
        }
        Record_SetVariant(this,param_1,iVar13);
      }
    }
    else {
      if ((!bVar12) && (*psVar15 == *(short *)((int)piVar17 + 0x32))) goto LAB_00533dd5;
LAB_00533d98:
      iVar13 = *(int *)((int)this + 0x4c) + iVar18;
      sVar14 = *(short *)(iVar13 + 0x32);
      if (*(char *)(*(int *)((int)this + 0x4c) + 0x38 + iVar18) < '\x01') {
        if (sVar14 < 1) {
          sVar14 = *(short *)((int)this + 0x68) + -1;
        }
        else {
          sVar14 = sVar14 + -1;
        }
      }
      else {
        if (*(int *)((int)this + 0x68) <= sVar14 + 1) {
          *(undefined2 *)(iVar13 + 0x32) = 0;
          goto LAB_00533ee8;
        }
        sVar14 = sVar14 + 1;
      }
      *(short *)(iVar13 + 0x32) = sVar14;
    }
LAB_00533ee8:
    iVar16 = local_30;
    iVar13 = *(int *)(*(int *)((int)this + 0x4c) + iVar18);
    uVar5 = *(undefined4 *)(*(int *)((int)this + 0x50) + 0x68 + iVar13 * 0x98);
    iVar13 = *(int *)((int)this + 0x50) + iVar13 * 0x98;
    dVar2 = *(double *)(iVar13 + 0x60);
    uVar6 = *(undefined4 *)(iVar13 + 0x6c);
    *param_3 = dVar2 + *param_3;
    dVar11 = (double)CONCAT44(uVar6,uVar5) + *param_4;
    *param_4 = dVar11;
    if (param_5 != (undefined4 *)0x0) {
      iVar13 = *(int *)((int)this + 0x4c) + iVar18;
      uVar7 = *(undefined4 *)(*(int *)((int)this + 0x4c) + 0x18 + iVar18);
      uVar8 = *(undefined4 *)(iVar13 + 0x1c);
      pdVar1 = (double *)(iVar13 + 0x20);
      uVar9 = *(undefined4 *)pdVar1;
      uVar10 = *(undefined4 *)(iVar13 + 0x24);
      if ((((dVar2 == 0.0) || ((0.0 < dVar2 && ((double)CONCAT44(uVar8,uVar7) <= *param_3)))) ||
          ((dVar2 < 0.0 && (*param_3 <= (double)CONCAT44(uVar8,uVar7))))) &&
         ((((double)CONCAT44(uVar6,uVar5) == 0.0 ||
           ((0.0 < (double)CONCAT44(uVar6,uVar5) && (*pdVar1 <= dVar11)))) ||
          (((double)CONCAT44(uVar6,uVar5) < 0.0 && (dVar11 <= *pdVar1)))))) {
        local_30 = 1;
        *(short *)(iVar13 + 0x30) = (short)iVar16 + -1;
        *param_5 = 1;
        *(undefined4 *)param_3 = uVar7;
        *(undefined4 *)((int)param_3 + 4) = uVar8;
        *(undefined4 *)param_4 = uVar9;
        *(undefined4 *)((int)param_4 + 4) = uVar10;
      }
    }
    local_30 = local_30 + -1;
  } while( true );
}

