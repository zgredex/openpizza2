// rea decompile_all
// name: Branch_ProcessCustomerOrder
// address: 0x47d4a0
// body: available
// range: 0x47d4a0-0x47d90b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Branch_ProcessCustomerOrder(void *this,int *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  void *this_00;
  int iVar3;
  double dVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  float10 fVar14;
  longlong lVar15;
  int local_1a8;
  int local_1a4;
  undefined4 local_190;
  int local_17c;
  undefined4 local_178;
  uint local_16c;
  int local_164;
  int local_160 [87];
  
                    /* Processes a customer order, consumes ingredients, and books sales. */
  iVar13 = 0;
  iVar9 = 0;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar6 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),param_1[4],(int *)0x0);
  iVar12 = 100;
  local_1a8 = 100;
  if (*(int *)(iVar6 + 0x30) == 0xb) {
    local_1a8 = 200;
    iVar12 = 200;
  }
  iVar2 = *(int *)(iVar6 + 0x2c);
  iVar7 = Branch_GetCustomerGroupRating(this,*(int *)(iVar6 + 0x34),1);
  local_17c = iVar7 - iVar2 >> 1;
  if (local_17c < 0) {
    local_17c = 0;
  }
  this_00 = (void *)*param_1;
  iVar2 = param_1[2];
  piVar8 = (int *)((int)this_00 + 100);
  iVar7 = 0x56;
  do {
    iVar3 = *piVar8;
    piVar8 = piVar8 + 1;
    iVar13 = iVar13 + iVar3;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  local_1a4 = iVar12 * iVar13;
  iVar7 = 0;
  if (0 < *(int *)((int)this + 0x19ac)) {
    do {
      piVar8 = (int *)IDMap_Lookup((void *)((int)this + 0x1998),iVar7,(int *)0x0);
      if (piVar8[7] != 0) {
        iVar9 = iVar9 + *piVar8;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)((int)this + 0x19ac));
    iVar12 = local_1a8;
  }
  if (iVar9 < local_1a4) {
    local_1a4 = iVar13 * (iVar9 / iVar13);
    local_1a8 = iVar9 / iVar13;
  }
  else {
    local_1a8 = iVar12;
  }
  uVar1 = *(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  local_16c = (uint)uVar1;
  if (99 < uVar1) {
    local_16c = 99;
  }
  if ((param_2 != 0) && (iVar12 != 0)) {
    local_164 = iVar12;
  }
  dVar4 = 0.0;
  if (local_1a8 == 0) {
    return 0;
  }
  piVar11 = (int *)(DAT_0057c670 + 0xa8);
  piVar8 = local_160;
  piVar10 = (int *)((int)this_00 + 100);
  iVar9 = 0x56;
  do {
    iVar12 = *piVar10;
    piVar10 = piVar10 + 1;
    *piVar8 = iVar12;
    iVar7 = *piVar11;
    piVar8 = piVar8 + 1;
    piVar11 = piVar11 + 1;
    iVar9 = iVar9 + -1;
    dVar4 = *(double *)(iVar7 + 0xc0) * (double)iVar12 * 0.001 + dVar4;
  } while (iVar9 != 0);
  iVar9 = *(int *)((int)this + 0x19ac);
  fVar5 = 0.0;
  for (; 0 < local_1a4; local_1a4 = local_1a4 - iVar12) {
    piVar8 = (int *)0x0;
    iVar12 = 0;
    if (iVar9 < 1) break;
    do {
      piVar10 = (int *)IDMap_Lookup((void *)((int)this + 0x1998),iVar12,(int *)0x0);
      if (((piVar10[7] != 0) && (*piVar10 != 0)) &&
         ((piVar8 == (int *)0x0 || (piVar10[1] < piVar8[1])))) {
        piVar8 = piVar10;
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < iVar9);
    if (piVar8 == (int *)0x0) break;
    iVar12 = *piVar8;
    if (local_1a4 <= *piVar8) {
      iVar12 = local_1a4;
    }
    *piVar8 = *piVar8 - iVar12;
    fVar5 = (float)piVar8[4] * (float)iVar12 * (float)(dVar4 / (double)iVar13) + fVar5;
  }
  fVar14 = Game_GetMarketBonusFactor((int)this);
  fVar14 = fVar14 * (float10)fVar5;
  lVar15 = __ftol();
  iVar9 = (int)lVar15;
  if (iVar9 < 1) {
    Stats_AddRecordValue(this,0x17,(float)-iVar9,-1);
  }
  else {
    Game_CanAfford(this,0x13,(float)iVar9,'\0',-1);
  }
  if (*(int *)(iVar6 + 0x38) == 0x1a) {
    iVar9 = 0x12;
  }
  else {
    iVar9 = 0xc;
  }
  Game_CanAfford(this,iVar9,
                 (float)((float10)(double)fVar14 - (float10)(double)(fVar14 - (float10)fVar5)),'\0',
                 -1);
  fVar5 = ((float)local_17c + 100.0) * (float)local_1a8 * (float)param_1[1] * 0.01;
  if (*(void **)(DAT_0057c670 + 0x9c) == this) {
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(byte *)s_Order_in__s_00567c50,(int)this + 4);
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(byte *)s_Gast__s_00567c48,
                        (&DAT_005834d4)[*(int *)(iVar6 + 0x34)]);
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(byte *)s_Trinkgeld__d_00567c38,local_17c);
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(byte *)s_Pizza____s_00567c28,*param_1 + 4);
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(byte *)s_Anzahl____d_00567c18,local_1a8);
    local_190 = SUB84((double)fVar14,0);
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(byte *)s_Ausgaben_____2f_00567c08,local_190);
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(byte *)s_MenuPreis____2f_00567bf8,
                        SUB84((double)(float)param_1[1],0));
    local_178 = SUB84((double)fVar5,0);
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(byte *)s_Einnahmen____2f_00567be8,local_178);
  }
  param_1[7] = (int)(fVar5 + 0.5);
  param_1[5] = local_1a8;
  param_1[8] = local_164;
  param_1[6] = (int)((fVar5 - (float)fVar14) + 0.5);
  param_1[9] = local_16c;
  param_1[0xb] = iVar2;
  param_1[10] = *(int *)((int)this + 0x3c);
  Branch_UpdateConstructionQueue(this);
  Recipe_AppendSalesRecord(this_00,(int)param_1);
  return local_1a8;
}

