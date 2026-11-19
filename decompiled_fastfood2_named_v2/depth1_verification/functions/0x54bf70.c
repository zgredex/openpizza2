// rea decompile_all
// name: FUN_0054bf70
// address: 0x54bf70
// body: available
// range: 0x54bf70-0x54c4ca inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0054bf70(void *this,uint param_1,int param_2,int param_3)

{
  char *pcVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  int iVar12;
  bool bVar13;
  int local_ac;
  int local_a4;
  int local_a0;
  int local_9c;
  float local_94 [4];
  int local_84;
  float local_80 [24];
  char local_20 [32];
  
  local_80[4] = -1.0;
  local_80[5] = 3.0;
  local_80[6] = -3.0;
  local_80[7] = 1.0;
  local_80[8] = 3.0;
  local_80[9] = -6.0;
  local_80[10] = 3.0;
  local_80[0xb] = 0.0;
  local_80[0xc] = -3.0;
  local_80[0xd] = 3.0;
  local_80[0xe] = 0.0;
  local_80[0xf] = 0.0;
  local_80[0x10] = 1.0;
  local_80[0x11] = 0.0;
  local_80[0x12] = 0.0;
  local_80[0x13] = 0.0;
  if (*(int *)((int)this + 4) == 0) {
    param_3 = 0;
  }
  *(uint *)((int)this + 0x1b0) = param_1;
  *(int *)((int)this + 0x1b4) = param_2;
  if ((param_2 < 1) && (param_2 < 0)) {
    bVar13 = param_1 != 0;
    param_1 = -param_1;
    *(undefined4 *)((int)this + 0x1b8) = 1;
    param_2 = -(param_2 + (uint)bVar13);
  }
  else {
    *(undefined4 *)((int)this + 0x1b8) = 0;
  }
  FUN_0054dd83(local_20,(byte *)s__0_ld_005765dc,9);
  iVar9 = 0;
  local_a0 = 0;
  if ((param_2 < *(int *)((int)this + 0x1a4)) ||
     ((param_2 <= *(int *)((int)this + 0x1a4) && (param_1 <= *(uint *)((int)this + 0x1a0))))) {
    local_84 = 0;
  }
  else {
    local_84 = 1;
  }
  *(uint *)((int)this + 0x1a0) = param_1;
  *(int *)((int)this + 0x1a4) = param_2;
  if (param_3 == 0) {
    iVar9 = 0;
    pfVar6 = (float *)((int)this + 0x1bc);
    do {
      pcVar1 = local_20 + iVar9;
      iVar9 = iVar9 + 1;
      *pfVar6 = (float)(*pcVar1 + -0x30) * 16.0;
      pfVar6[0x21] = *(float *)((int)this + 0x1b8);
      pfVar6[0x22] = 0.0;
      pfVar6[1] = *pfVar6;
      pfVar6[2] = 0.0;
      pfVar6 = pfVar6 + 0x23;
    } while (iVar9 < 9);
    if (*(void **)((int)this + 4) != (void *)0x0) {
      FUN_00521b40(*(void **)((int)this + 4),0x32,&LAB_0054bd00,this);
      return;
    }
  }
  else {
    local_9c = 0;
    local_a4 = 0;
    pfVar6 = (float *)((int)this + 0x1c0);
    do {
      bVar13 = true;
      fVar5 = (float)(local_20[local_9c] + -0x30) * 16.0;
      *pfVar6 = fVar5;
      if ((iVar9 == 0) && (fVar5 == pfVar6[-1])) {
        pfVar6[0x21] = 0.0;
        bVar13 = false;
        if (pfVar6[0x20] != *(float *)((int)this + 0x1b8)) goto LAB_0054c18b;
      }
      else {
LAB_0054c18b:
        if (local_84 == 0) {
          if (*pfVar6 == pfVar6[-1]) {
            fVar5 = 0.0;
          }
          else if (pfVar6[-1] <= *pfVar6) {
            fVar5 = -((pfVar6[-1] - *pfVar6) + 160.0);
          }
          else {
            fVar5 = *pfVar6 - pfVar6[-1];
          }
          fVar5 = fVar5 - (float)(iVar9 * 0xa0);
          if (pfVar6[0x20] != *(float *)((int)this + 0x1b8)) {
            if (iVar9 == 0) {
              fVar5 = fVar5 - 320.0;
            }
            else if (iVar9 == 1) {
              fVar5 = fVar5 - 160.0;
            }
          }
        }
        else {
          if (*pfVar6 == pfVar6[-1]) {
            fVar5 = 0.0;
          }
          else if (*pfVar6 <= pfVar6[-1]) {
            fVar5 = 160.0 - (pfVar6[-1] - *pfVar6);
          }
          else {
            fVar5 = *pfVar6 - pfVar6[-1];
          }
          fVar5 = fVar5 + (float)(iVar9 * 0xa0);
          if (pfVar6[0x20] != *(float *)((int)this + 0x1b8)) {
            if (iVar9 == 0) {
              fVar5 = fVar5 + 320.0;
            }
            else if (iVar9 == 1) {
              fVar5 = fVar5 + 160.0;
            }
          }
        }
        if ((pfVar6[0x21] == 0.0) || (0x1d < (int)pfVar6[1])) {
          local_94[0] = 0.0;
          local_94[1] = 0.0;
        }
        else {
          iVar9 = (int)pfVar6[1] + local_a4;
          local_94[0] = *(float *)((int)this + iVar9 * 4 + 0x1c8);
          local_94[1] = (float)*(undefined4 *)((int)this + iVar9 * 4 + 0x1cc);
        }
        if (fVar5 <= 0.0) {
          local_94[0] = -20.0;
          local_94[3] = -20.0;
          local_94[2] = -20.0;
        }
        else {
          local_94[0] = 20.0;
          local_94[3] = 20.0;
          local_94[2] = 20.0;
        }
        pfVar8 = local_80 + 4;
        pfVar7 = local_80 + 0x14;
        iVar9 = 4;
        do {
          *pfVar7 = 0.0;
          pfVar10 = local_94;
          fVar2 = *pfVar7;
          iVar12 = 4;
          do {
            fVar3 = *pfVar8;
            fVar4 = *pfVar10;
            pfVar8 = pfVar8 + 1;
            pfVar10 = pfVar10 + 1;
            iVar12 = iVar12 + -1;
            fVar2 = fVar3 * fVar4 + fVar2;
          } while (iVar12 != 0);
          *pfVar7 = fVar2;
          pfVar7 = pfVar7 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        pfVar8 = pfVar6 + 2;
        local_80[3] = 1.0;
        local_ac = 0;
        pfVar7 = pfVar8;
        do {
          *pfVar7 = 0.0;
          iVar9 = 0;
          local_80[2] = (float)local_ac * 0.06666667;
          local_80[1] = local_80[2] * local_80[2];
          local_80[0] = local_80[2] * local_80[2] * local_80[2];
          fVar2 = *pfVar7;
          do {
            pfVar10 = (float *)((int)local_80 + iVar9);
            iVar12 = iVar9 + 0x50;
            iVar9 = iVar9 + 4;
            fVar2 = *pfVar10 * *(float *)((int)local_80 + iVar12) + fVar2;
          } while (iVar9 < 0x10);
          *pfVar7 = fVar2;
          local_ac = local_ac + 1;
          pfVar7 = pfVar7 + 1;
        } while (local_ac < 0xf);
        local_94[2] = 0.0;
        local_94[1] = local_94[3];
        local_94[3] = 0.0;
        pfVar7 = local_80 + 4;
        pfVar10 = local_80 + 0x14;
        iVar9 = 4;
        do {
          *pfVar10 = 0.0;
          pfVar11 = local_94;
          fVar2 = *pfVar10;
          iVar12 = 4;
          do {
            fVar3 = *pfVar7;
            fVar4 = *pfVar11;
            pfVar7 = pfVar7 + 1;
            pfVar11 = pfVar11 + 1;
            iVar12 = iVar12 + -1;
            fVar2 = fVar3 * fVar4 + fVar2;
          } while (iVar12 != 0);
          *pfVar10 = fVar2;
          pfVar10 = pfVar10 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        local_80[3] = 1.0;
        local_ac = 0;
        pfVar7 = pfVar6 + 0x11;
        do {
          *pfVar7 = 0.0;
          iVar9 = 0;
          local_80[2] = (float)local_ac * 0.06666667;
          local_80[1] = local_80[2] * local_80[2];
          local_80[0] = local_80[2] * local_80[2] * local_80[2];
          fVar2 = *pfVar7;
          do {
            pfVar10 = (float *)((int)local_80 + iVar9);
            iVar12 = iVar9 + 0x50;
            iVar9 = iVar9 + 4;
            fVar2 = *pfVar10 * *(float *)((int)local_80 + iVar12) + fVar2;
          } while (iVar9 < 0x10);
          *pfVar7 = fVar2;
          local_ac = local_ac + 1;
          pfVar7 = pfVar7 + 1;
        } while (local_ac < 0xf);
        fVar2 = 0.0;
        iVar9 = 0x1e;
        pfVar7 = pfVar8;
        do {
          fVar2 = fVar2 + *pfVar7;
          pfVar7 = pfVar7 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        if (fVar2 == 0.0) {
          fVar5 = 1.0;
        }
        else {
          fVar5 = fVar5 / fVar2;
        }
        iVar9 = 0x1e;
        do {
          iVar9 = iVar9 + -1;
          *pfVar8 = fVar5 * *pfVar8;
          pfVar8 = pfVar8 + 1;
        } while (iVar9 != 0);
        pfVar6[1] = 0.0;
        pfVar6[0x21] = 1.4013e-45;
        *(undefined4 *)((int)this + 0x1ac) = 0;
        if (bVar13) {
          local_a0 = local_a0 + 1;
        }
        iVar9 = local_a0;
      }
      pfVar6 = pfVar6 + 0x23;
      local_9c = local_9c + 1;
      local_a4 = local_a4 + 0x23;
    } while (local_a4 < 0x13b);
    FUN_00521b40(*(void **)((int)this + 4),0x32,&LAB_0054bd00,this);
  }
  return;
}

