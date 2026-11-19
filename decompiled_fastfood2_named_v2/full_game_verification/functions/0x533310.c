// rea decompile_all
// name: Record_CopyTemplate98
// address: 0x533310
// body: available
// range: 0x533310-0x5333f1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Record_CopyTemplate98(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  longlong lVar9;
  
  uVar4 = 0xffffffff;
  pcVar2 = param_1;
  do {
    pcVar8 = pcVar2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar2 = pcVar8 + -uVar4;
  pcVar8 = (char *)(param_2 + 0x80);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar8 = pcVar8 + 1;
  }
  *(undefined4 *)(param_2 + 0x60) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(param_2 + 100) = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(param_1 + 0x7c);
  lVar9 = __ftol();
  *(char *)(param_2 + 0x90) = (char)lVar9;
  *(undefined4 *)(param_2 + 0x70) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(param_2 + 0x74) = *(undefined4 *)(param_1 + 0x8c);
  *(undefined4 *)(param_2 + 0x78) = *(undefined4 *)(param_1 + 0x90);
  *(undefined4 *)(param_2 + 0x7c) = *(undefined4 *)(param_1 + 0x94);
  iVar6 = param_2 + 5;
  pcVar2 = param_1 + 0x14;
  iVar7 = 6;
  do {
    *(undefined2 *)(iVar6 + -5) = *(undefined2 *)(pcVar2 + -4);
    *(undefined2 *)(iVar6 + -3) = *(undefined2 *)pcVar2;
    *(bool *)iVar6 = *(int *)(pcVar2 + 4) == 1;
    *(char *)(iVar6 + -1) = pcVar2[8];
    pcVar2 = pcVar2 + 0x10;
    iVar6 = iVar6 + 6;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar3 = (undefined1 *)(param_2 + 0x28);
  iVar6 = 10;
  do {
    *(undefined2 *)(puVar3 + -4) = 0xffff;
    *(undefined2 *)(puVar3 + -2) = 0;
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3 = puVar3 + 6;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return;
}

