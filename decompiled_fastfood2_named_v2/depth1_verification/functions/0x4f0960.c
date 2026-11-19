// rea decompile_all
// name: Map_LinkObjects
// address: 0x4f0960
// body: available
// range: 0x4f0960-0x4f0aa1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Map_LinkObjects(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  double dVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  
                    /* Depth-1 proposal batch 3/4. */
  iVar4 = *(int *)(param_3 + 0xc);
  iVar2 = *(int *)(param_2 + 0xc);
  uVar1 = *(ushort *)(param_2 + 4);
  if (iVar2 == iVar4) {
    dVar3 = 0.0;
  }
  else {
    dVar3 = (double)(*(int *)(param_2 + 0x10) - *(int *)(param_3 + 0x10)) / (double)(iVar2 - iVar4);
    if ((dVar3 == 0.5) || (dVar3 == -0.5)) goto LAB_004f09f7;
  }
  if ((iVar2 != iVar4) && (dVar3 != 0.0)) {
    FUN_0048e0a0();
    return;
  }
LAB_004f09f7:
  psVar6 = (short *)(param_2 + 0x14);
  iVar4 = 0;
  psVar5 = psVar6;
  do {
    if ((int)*psVar5 == (uint)*(ushort *)(param_3 + 4)) {
      return;
    }
    iVar4 = iVar4 + 1;
    psVar5 = psVar5 + 1;
  } while (iVar4 < 8);
  iVar4 = 0;
  do {
    if (*psVar6 == -1) {
      *(ushort *)(param_2 + 0x14 + iVar4 * 2) = *(ushort *)(param_3 + 4);
      break;
    }
    iVar4 = iVar4 + 1;
    psVar6 = psVar6 + 1;
  } while (iVar4 < 8);
  if (iVar4 == 8) {
    FUN_0048e0a0();
  }
  if (param_1 == 1) {
    psVar6 = (short *)(param_3 + 0x14);
    iVar4 = 0;
    psVar5 = psVar6;
    do {
      if ((int)*psVar5 == (uint)uVar1) {
        return;
      }
      iVar4 = iVar4 + 1;
      psVar5 = psVar5 + 1;
    } while (iVar4 < 8);
    iVar4 = 0;
    do {
      if (*psVar6 == -1) {
        *(ushort *)(param_3 + 0x14 + iVar4 * 2) = uVar1;
        break;
      }
      iVar4 = iVar4 + 1;
      psVar6 = psVar6 + 1;
    } while (iVar4 < 8);
    if (iVar4 == 8) {
      FUN_0048e0a0();
    }
  }
  FUN_004edbc0();
  return;
}

