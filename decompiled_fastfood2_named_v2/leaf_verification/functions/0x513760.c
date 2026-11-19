// rea decompile_all
// name: FUN_00513760
// address: 0x513760
// body: available
// range: 0x513760-0x51395f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00513760(void *this,int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  undefined4 *puVar6;
  float10 fVar7;
  longlong lVar8;
  float local_20 [8];
  
  iVar3 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(param_1 + 0x34),(int *)0x0);
  puVar6 = (undefined4 *)((int)this + 0x2e4);
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  fVar7 = Rating_GetFloat(iVar3,0);
  local_20[0] = (float)fVar7;
  fVar7 = Rating_GetFloat(iVar3,1);
  local_20[1] = (float)fVar7;
  fVar7 = Rating_GetFloat(iVar3,2);
  local_20[2] = (float)fVar7;
  fVar7 = Rating_GetFloat(iVar3,3);
  local_20[3] = (float)fVar7;
  fVar7 = Rating_GetFloat(iVar3,4);
  local_20[4] = (float)fVar7;
  fVar7 = Rating_GetFloat(iVar3,5);
  local_20[5] = (float)fVar7;
  fVar7 = Rating_GetFloat(iVar3,6);
  local_20[6] = (float)fVar7;
  fVar7 = Rating_GetFloat(iVar3,7);
  local_20[7] = (float)fVar7;
  fVar1 = *(float *)(iVar3 + 0x98);
  iVar3 = *(int *)(param_1 + 0x38);
  pfVar4 = local_20;
  iVar5 = 8;
  do {
    if (iVar3 == 1) {
      fVar2 = fVar1 + fVar1;
LAB_00513849:
      *pfVar4 = fVar2 + *pfVar4;
    }
    else if (iVar3 == 2) {
      fVar2 = fVar1 * 4.0;
      goto LAB_00513849;
    }
    pfVar4 = pfVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar3 = 0;
  do {
    if (local_20[iVar3] < param_2) {
      lVar8 = __ftol();
      *(int *)((int)this + iVar3 * 4 + 0x2e4) = (int)lVar8;
    }
    if (local_20[iVar3] <= param_2) goto switchD_005138e6_default;
    if (param_2 == 0.0) {
      *(undefined4 *)((int)this + iVar3 * 4 + 0x2e4) = 100;
    }
    else {
      lVar8 = __ftol();
      *(int *)((int)this + iVar3 * 4 + 0x2e4) = (int)lVar8;
    }
    switch(iVar3) {
    case 0:
    case 6:
      if (0x28 < *(int *)((int)this + iVar3 * 4 + 0x2e4)) {
        *(undefined4 *)((int)this + iVar3 * 4 + 0x2e4) = 0x28;
      }
      break;
    case 1:
      iVar5 = 10;
      goto LAB_0051391d;
    case 2:
      iVar5 = *(int *)((int)this + iVar3 * 4 + 0x2e4);
      goto joined_r0x00513943;
    case 3:
      iVar5 = 0x1e;
      goto LAB_0051391d;
    case 4:
      iVar5 = 5;
LAB_0051391d:
      if (iVar5 < *(int *)((int)this + iVar3 * 4 + 0x2e4)) {
        *(int *)((int)this + iVar3 * 4 + 0x2e4) = iVar5;
      }
      break;
    case 5:
      *(undefined4 *)((int)this + iVar3 * 4 + 0x2e4) = 0;
      break;
    case 7:
      iVar5 = *(int *)((int)this + iVar3 * 4 + 0x2e4);
joined_r0x00513943:
      if (0x14 < iVar5) {
        *(undefined4 *)((int)this + iVar3 * 4 + 0x2e4) = 0x14;
      }
    }
switchD_005138e6_default:
    iVar3 = iVar3 + 1;
    if (7 < iVar3) {
      return;
    }
  } while( true );
}

