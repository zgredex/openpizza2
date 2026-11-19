// rea decompile_all
// name: FUN_0054bd10
// address: 0x54bd10
// body: available
// range: 0x54bd10-0x54bf4f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


bool __thiscall FUN_0054bd10(void *this,uint *param_1)

{
  float fVar1;
  bool bVar2;
  DWORD DVar3;
  uint uVar4;
  int iVar5;
  void *this_00;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  longlong lVar10;
  int local_c;
  
  DVar3 = timeGetTime();
  uVar4 = *(uint *)((int)this + 0x1ac);
  iVar7 = 0;
  if (uVar4 == 0) {
    *(DWORD *)((int)this + 0x1ac) = DVar3;
    local_c = 1;
  }
  else {
    local_c = 0;
    while (uVar4 < DVar3) {
      uVar4 = *(int *)((int)this + 0x1ac) + 0x32;
      local_c = local_c + 1;
      *(uint *)((int)this + 0x1ac) = uVar4;
    }
  }
  uVar4 = FUN_00521b10((int)param_1);
  FUN_00521380((int)param_1);
  param_1 = (uint *)0x0;
  bVar2 = true;
  piVar8 = (int *)((int)this + 0x1c4);
  do {
    iVar5 = 0;
    iVar6 = 0;
    if (piVar8[0x20] != 0) {
      bVar2 = false;
      if (0 < local_c) {
        do {
          if (0x1d < *piVar8) break;
          piVar8[-2] = (int)(*(float *)((int)this + (*piVar8 + iVar7) * 4 + 0x1c8) +
                            (float)piVar8[-2]);
          iVar5 = iVar5 + 1;
          *piVar8 = *piVar8 + 1;
        } while (iVar5 < local_c);
      }
      fVar1 = ABS(*(float *)((int)this + (*piVar8 + iVar7) * 4 + 0x1c4));
      if (fVar1 <= 8.0) {
        if (4.0 < fVar1) {
          iVar6 = 1;
        }
      }
      else {
        iVar6 = 2;
      }
      if (160.0 < (float)piVar8[-2]) {
        do {
          piVar8[-2] = (int)((float)piVar8[-2] - 160.0);
          if (piVar8[0x1f] != *(int *)((int)this + 0x1b8)) {
            piVar8[0x1f] = *(int *)((int)this + 0x1b8);
          }
        } while (160.0 < (float)piVar8[-2]);
      }
      if ((float)piVar8[-2] < 0.0) {
        do {
          piVar8[-2] = (int)((float)piVar8[-2] + 160.0);
          if (piVar8[0x1f] != *(int *)((int)this + 0x1b8)) {
            piVar8[0x1f] = *(int *)((int)this + 0x1b8);
          }
        } while ((float)piVar8[-2] < 0.0);
      }
      if (*piVar8 == 0x1e) {
        piVar8[-2] = piVar8[-1];
        piVar8[0x20] = 0;
      }
    }
    uVar9 = -(uint)(piVar8[0x1f] != 0) & 3;
    if (iVar6 == 0) {
      lVar10 = __ftol();
      iVar5 = (int)lVar10;
      this_00 = *(void **)((int)this + uVar9 * 0x44 + 0x48);
    }
    else if (iVar6 == 1) {
      lVar10 = __ftol();
      iVar5 = (int)lVar10;
      this_00 = *(void **)((int)this + uVar9 * 0x44 + 0x8c);
    }
    else {
      lVar10 = __ftol();
      iVar5 = (int)lVar10;
      this_00 = *(void **)((int)this + uVar9 * 0x44 + 0xd0);
    }
    FUN_0053d570(this_00,uVar4,param_1,iVar5);
    iVar7 = iVar7 + 0x23;
    param_1 = param_1 + 3;
    piVar8 = piVar8 + 0x23;
    if (0x13a < iVar7) {
      return !bVar2;
    }
  } while( true );
}

