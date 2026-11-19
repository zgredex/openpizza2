// rea decompile_all
// name: UI_RefreshButtonSprites
// address: 0x52ac50
// body: available
// range: 0x52ac50-0x52ad5f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall UI_RefreshButtonSprites(void *this,int param_1)

{
  char cVar1;
  void *this_00;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  undefined4 *puVar8;
  char local_208 [260];
  char local_104 [260];
  
                    /* Reloads or releases an animated button's state sprites. */
  this_00 = *(void **)(*(int *)((int)this + 8) + 0x134);
  if ((0 < param_1) && (param_1 < 3)) {
    if (param_1 == 1) {
      piVar6 = (int *)((int)this + 0x454);
      iVar5 = 3;
      do {
        if (*piVar6 != 0) {
          FUN_005277d0(this_00,(byte *)(piVar6 + -0x10));
        }
        *piVar6 = 0;
        piVar6 = piVar6 + 0x11;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      return;
    }
    uVar3 = 0xffffffff;
    pcVar2 = (char *)((int)this + 0x348);
    do {
      pcVar7 = pcVar2;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar7;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar2 = pcVar7 + -uVar3;
    pcVar7 = local_208;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar7 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar7 = pcVar7 + 1;
    }
    pcVar2 = _strrchr(local_208,0x5f);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
    }
    if (param_1 == 2) {
      iVar5 = 0;
      puVar8 = (undefined4 *)((int)this + 0x414);
      do {
        if (puVar8[0x10] == 0) {
          FUN_0054dd83(local_104,(byte *)s__s__02d_spr_00573b9c,local_208);
          Window_LoadSpriteCached(this_00,local_104,(undefined4 *)(uint)(iVar5 < 2),puVar8);
        }
        iVar5 = iVar5 + 1;
        puVar8 = puVar8 + 0x11;
      } while (iVar5 < 3);
    }
  }
  return;
}

