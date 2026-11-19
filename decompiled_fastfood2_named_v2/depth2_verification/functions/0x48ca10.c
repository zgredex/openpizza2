// rea decompile_all
// name: Game_GetPlayerValueSharePercent
// address: 0x48ca10
// body: available
// range: 0x48ca10-0x48cad8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


longlong __thiscall Game_GetPlayerValueSharePercent(void *this,int param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  uint extraout_EDX;
  uint extraout_EDX_00;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  longlong lVar7;
  float local_18 [6];
  
                    /* Depth-2 proposal batch 2/4. */
  local_18[0] = 0.0;
  local_18[1] = 0.0;
  local_18[2] = 0.0;
  local_18[3] = 0.0;
  local_18[4] = 0.0;
  local_18[5] = 0.0;
  iVar5 = 0;
  pfVar3 = local_18;
  do {
    iVar2 = FUN_00488be0(this,iVar5);
    uVar4 = extraout_EDX;
    if (iVar2 != 0) {
      fVar6 = FUN_004e09e0(iVar2,-1,-1,-1);
      *pfVar3 = (float)fVar6;
      uVar4 = extraout_EDX_00;
    }
    iVar5 = iVar5 + 1;
    pfVar3 = pfVar3 + 1;
  } while (iVar5 < 6);
  iVar5 = 6;
  pfVar3 = local_18;
  fVar1 = 0.0;
  do {
    fVar1 = fVar1 + *pfVar3;
    pfVar3 = pfVar3 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if ((fVar1 == 0.0) || (local_18[param_1] == 0.0)) {
    return (ulonglong)uVar4 << 0x20;
  }
  lVar7 = __ftol();
  return lVar7;
}

