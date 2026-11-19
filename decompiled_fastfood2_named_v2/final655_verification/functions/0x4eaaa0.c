// rea decompile_all
// name: FUN_004eaaa0
// address: 0x4eaaa0
// body: available
// range: 0x4eaaa0-0x4eaaf1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004eaaa0(void *this,void *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char local_34 [52];
  
  pcVar4 = (char *)((int)this + 0x25);
  iVar5 = 0x9c4;
  do {
    uVar2 = 0xffffffff;
    pcVar6 = pcVar4;
    do {
      pcVar7 = pcVar6;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar7 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar7;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar6 = pcVar7 + -uVar2;
    pcVar7 = local_34;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
    FUN_0054cc2b(param_1,local_34,0x32);
    pcVar4 = pcVar4 + 0x48;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return;
    }
  } while( true );
}

