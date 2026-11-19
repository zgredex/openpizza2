// rea decompile_all
// name: Filename_ToUpperStripExt
// address: 0x4e6420
// body: available
// range: 0x4e6420-0x4e64b5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl Filename_ToUpperStripExt(char *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  uint *puVar7;
  uint *puVar8;
  uint local_64 [25];
  
                    /* Uppercases a filename and strips its extension. */
  uVar3 = 0xffffffff;
  pcVar2 = param_1;
  do {
    pcVar5 = pcVar2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar2 = pcVar5 + -uVar3;
  puVar7 = local_64;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar7 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar7 = (uint *)((int)puVar7 + 4);
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(char *)puVar7 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    puVar7 = (uint *)((int)puVar7 + 1);
  }
  FUN_0054f775(local_64);
  pcVar2 = _strchr((char *)local_64,0x2e);
  if (pcVar2 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar5 = &DAT_0057ca0c;
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
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar2 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar2 = pcVar2 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar2 = pcVar2 + 1;
    }
  }
  uVar3 = 0xffffffff;
  puVar7 = local_64;
  do {
    puVar8 = puVar7;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    puVar8 = (uint *)((int)puVar7 + 1);
    uVar4 = *puVar7;
    puVar7 = puVar8;
  } while ((char)uVar4 != '\0');
  uVar3 = ~uVar3;
  pcVar2 = (char *)((int)puVar8 - uVar3);
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)param_1 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    param_1 = param_1 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *param_1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

