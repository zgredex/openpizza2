// rea decompile_all
// name: UI_BuildListItem
// address: 0x52ad60
// body: available
// range: 0x52ad60-0x52ae16 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall UI_BuildListItem(void *this,int param_1)

{
  char cVar1;
  void *this_00;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
                    /* Depth-2 proposal batch 5. */
  this_00 = *(void **)(*(int *)((int)this + 8) + 0x134);
  if (*(int *)((int)this + 0x54) == 0) {
    if (*(int *)((int)this + 0xc0) == 0) {
      *(undefined4 *)(param_1 + 8) = 0x6e;
    }
    else {
      *(undefined4 *)(param_1 + 8) = 0x70;
    }
  }
  else if (*(int *)((int)this + 0xc0) == 0) {
    *(undefined4 *)(param_1 + 8) = 0x6d;
  }
  else {
    *(undefined4 *)(param_1 + 8) = 0x6f;
  }
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)((int)this + 0xb4);
  *(undefined4 *)(param_1 + 0x20) = 3;
  pcVar2 = (char *)FUN_00527810(this_00,(byte *)((int)this + 0x1ac));
  uVar3 = 0xffffffff;
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
  pcVar5 = (char *)(param_1 + 0x24);
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar5 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar5 = pcVar5 + 1;
  }
  *(undefined4 *)(param_1 + 0x430) = *(undefined4 *)((int)this + 0xd4);
  *(undefined4 *)(param_1 + 0x434) = *(undefined4 *)((int)this + 0xd8);
  *(undefined4 *)(param_1 + 0x438) = *(undefined4 *)((int)this + 0xdc);
  return;
}

