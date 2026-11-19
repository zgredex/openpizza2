// rea decompile_all
// name: Stats_ComputeWeightedAverages
// address: 0x513100
// body: available
// range: 0x513100-0x513265 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Stats_ComputeWeightedAverages(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  int unaff_retaddr;
  float fVar8;
  float local_8;
  float local_4;
  
  iVar6 = 0;
  iVar5 = 0;
  *(undefined4 *)((int)this + 0x24c) = 0;
  *(undefined4 *)((int)this + 0x254) = 0;
  *(undefined4 *)((int)this + 0x250) = 0;
  iVar1 = *(int *)((int)this + 0x5c);
  if (0 < iVar1) {
    do {
      iVar4 = IDMap_Lookup((void *)((int)this + 0x48),iVar6,(int *)0x0);
      iVar2 = *(int *)(DAT_0057c670 + 0xa8 + (uint)*(byte *)(iVar4 + 4) * 4);
      iVar3 = *(int *)(iVar2 + 0xac + (uint)*(byte *)(iVar4 + 6) * 4);
      iVar5 = iVar5 + iVar3;
      *(int *)((int)this + 0x24c) =
           *(int *)((int)this + 0x24c) + *(char *)(*(byte *)(iVar4 + 6) + 200 + iVar2) * iVar3;
      *(int *)((int)this + 0x254) =
           *(int *)((int)this + 0x254) +
           *(int *)(iVar2 + 0xac + (uint)*(byte *)(iVar4 + 6) * 4) * (int)*(char *)(iVar2 + 0xcc);
      iVar6 = iVar6 + 1;
      *(int *)((int)this + 0x250) =
           *(int *)((int)this + 0x250) +
           *(int *)(iVar2 + 0xac + (uint)*(byte *)(iVar4 + 6) * 4) * (int)*(char *)(iVar2 + 0xcd);
    } while (iVar6 < iVar1);
    if (0 < iVar5) {
      local_8 = (float)*(int *)((int)this + 0x24c) / (float)iVar5;
      goto LAB_005131ee;
    }
  }
  local_8 = 0.0;
LAB_005131ee:
  lVar7 = Math_RoundFloat(local_8);
  *(int *)((int)this + 0x24c) = (int)lVar7;
  if (iVar5 < 1) {
    local_4 = 0.0;
  }
  else {
    local_4 = (float)*(int *)((int)this + 0x254) / (float)unaff_retaddr;
  }
  lVar7 = Math_RoundFloat(local_4);
  *(int *)((int)this + 0x254) = (int)lVar7;
  if (iVar5 < 1) {
    fVar8 = 0.0;
  }
  else {
    fVar8 = (float)*(int *)((int)this + 0x250) / (float)param_1;
  }
  lVar7 = Math_RoundFloat(fVar8);
  *(int *)((int)this + 0x250) = (int)lVar7;
  return;
}

