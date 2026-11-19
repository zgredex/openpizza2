// rea decompile_all
// name: IDMap_GetRandomName
// address: 0x403020
// body: available
// range: 0x403020-0x4030e8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall IDMap_GetRandomName(void *this,int param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  if (param_1 == 0) {
    uVar2 = Random_Mod((int)*(short *)((int)this + 0x10));
    iVar4 = *(int *)((int)this + 4);
  }
  else {
    uVar2 = Random_Mod((int)*(short *)((int)this + 0x12));
    iVar4 = *(int *)((int)this + 8);
  }
  uVar3 = 0xffffffff;
  pcVar5 = (char *)(uVar2 * 0x10 + iVar4);
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar6 + -uVar3;
  pcVar6 = param_2;
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  uVar2 = 0xffffffff;
  pcVar5 = DAT_00582e4c;
  do {
    pcVar6 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  iVar4 = -1;
  pcVar5 = param_2;
  do {
    pcVar7 = pcVar5;
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  pcVar5 = pcVar6 + -uVar2;
  pcVar6 = pcVar7 + -1;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  uVar2 = Random_Mod((int)*(short *)((int)this + 0x14));
  uVar3 = 0xffffffff;
  pcVar5 = (char *)(uVar2 * 0x10 + *(int *)((int)this + 0xc));
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  iVar4 = -1;
  do {
    pcVar5 = param_2;
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pcVar5 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar5;
  } while (cVar1 != '\0');
  pcVar6 = pcVar6 + -uVar3;
  pcVar5 = pcVar5 + -1;
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar5 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return;
}

