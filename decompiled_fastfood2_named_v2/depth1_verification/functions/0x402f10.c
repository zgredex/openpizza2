// rea decompile_all
// name: NamePool_AddName
// address: 0x402f10
// body: available
// range: 0x402f10-0x402fdd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall NamePool_AddName(void *this,char *param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined4 *puVar10;
  char *pcVar11;
  
                    /* Depth-1 proposal batch 2. */
  if (param_2 == 0) {
    piVar7 = (int *)((int)this + 8);
    puVar6 = (ushort *)((int)this + 0x12);
  }
  else if (param_2 == 1) {
    piVar7 = (int *)((int)this + 4);
    puVar6 = (ushort *)((int)this + 0x10);
  }
  else {
    if (param_2 != 2) {
      return;
    }
    piVar7 = (int *)((int)this + 0xc);
    puVar6 = (ushort *)((int)this + 0x14);
  }
  uVar3 = 0xffffffff;
  pcVar9 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  if (0xf < ~uVar3 - 1) {
    param_1[0xf] = '\0';
  }
  if ((*puVar6 & 0x3f) == 0) {
    puVar2 = operator_new(((short)*puVar6 + 0x40) * 0x10);
    if ((undefined4 *)*piVar7 != (undefined4 *)0x0) {
      puVar8 = (undefined4 *)*piVar7;
      puVar10 = puVar2;
      for (iVar4 = ((int)(short)*puVar6 & 0xfffffffU) << 2; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      FUN_0054dd78((LPVOID)*piVar7);
    }
    *piVar7 = (int)puVar2;
  }
  uVar3 = 0xffffffff;
  do {
    pcVar9 = param_1;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar9 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar9;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar9 = pcVar9 + -uVar3;
  pcVar11 = (char *)((short)*puVar6 * 0x10 + *piVar7);
  for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
    pcVar9 = pcVar9 + 4;
    pcVar11 = pcVar11 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar11 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    pcVar11 = pcVar11 + 1;
  }
  *puVar6 = *puVar6 + 1;
  return;
}

