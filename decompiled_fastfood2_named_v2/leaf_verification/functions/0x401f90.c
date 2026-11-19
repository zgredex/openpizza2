// rea decompile_all
// name: ResourceIterator_Next
// address: 0x401f90
// body: available
// range: 0x401f90-0x40205d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall ResourceIterator_Next(void *this,char *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  
                    /* Re-applied established leaf name. */
  iVar3 = *(int *)(param_1 + 0x114);
  if (*(int *)((int)this + 0x1684) <= iVar3) {
    return 0;
  }
  iVar4 = *(int *)(param_1 + 0x118);
  *(int *)(param_1 + 0x118) = iVar4 + 1;
  if (**(int **)(iVar3 * 0x120 + 0x110 + (int)this) <= iVar4 + 1) {
    param_1[0x118] = '\0';
    param_1[0x119] = '\0';
    param_1[0x11a] = '\0';
    param_1[0x11b] = '\0';
    *(int *)(param_1 + 0x114) = iVar3 + 1;
    if (*(int *)((int)this + 0x1684) <= iVar3 + 1) {
      return 0;
    }
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x114) * 0x120 + 0x114 + (int)this);
  puVar1 = (undefined4 *)(iVar3 + *(int *)(param_1 + 0x118) * 0x14);
  uVar5 = 0xffffffff;
  pcVar7 = *(char **)(iVar3 + 0x10 + *(int *)(param_1 + 0x118) * 0x14);
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  pcVar7 = pcVar8 + -uVar5;
  pcVar8 = param_1;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  *(undefined4 *)(param_1 + 0x104) = *puVar1;
  *(undefined4 *)(param_1 + 0x108) = puVar1[1];
  *(undefined4 *)(param_1 + 0x10c) = puVar1[2];
  *(undefined4 *)(param_1 + 0x110) = puVar1[3];
  return 1;
}

