// rea decompile_all
// name: AI_IsDirectionOnRoute
// address: 0x477120
// body: available
// range: 0x477120-0x477183 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall AI_IsDirectionOnRoute(void *this,int *param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
                    /* Depth-1 proposal batch 2. */
  iVar3 = *(int *)((int)this + 0x1514);
  iVar4 = 0;
  if (iVar3 < 1) {
    piVar1 = param_1;
  }
  else {
    do {
      piVar1 = (int *)FUN_004017f0((void *)((int)this + 0x1500),iVar4,(int *)0x0);
      if ((int *)*piVar1 == param_1) break;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  if (iVar4 == iVar3) {
    return 0;
  }
  uVar2 = piVar1[1];
  iVar3 = 0;
  do {
    if (uVar2 == param_2) {
      return 1;
    }
    uVar2 = uVar2 + 1 & 7;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return 0;
}

