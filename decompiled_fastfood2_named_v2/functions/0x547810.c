// rea decompile_all
// name: FUN_00547810
// address: 0x547810
// body: available
// range: 0x547810-0x5478b9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00547810(int param_1)

{
  int iVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined4 *puVar4;
  undefined1 local_104 [260];
  
  ppuVar3 = &PTR_s_Sfx_Makepizza_Cut_Food_wav_005750a0;
  iVar2 = param_1 + 0x24;
  do {
    String_Format(local_104,(byte *)s_sfx__s_005760c8,*ppuVar3);
    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x28))(*(int **)(param_1 + 8),local_104,iVar2);
    if (iVar1 < 0) break;
    ppuVar3 = ppuVar3 + 1;
    iVar2 = iVar2 + 4;
  } while ((int)ppuVar3 < 0x57510c);
  ppuVar3 = &PTR_s_Sfx_Action_Bomb_Explo_wav_0057510c;
  puVar4 = (undefined4 *)(param_1 + 0x90);
  do {
    String_Format(local_104,(byte *)s_sfx__s_005760c8,*ppuVar3);
    iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x28))(*(int **)(param_1 + 8),local_104,puVar4);
    if (-1 < iVar2) {
      (**(code **)(**(int **)(param_1 + 8) + 0x9c))
                (*(int **)(param_1 + 8),*(undefined4 *)(param_1 + 0xf4),*puVar4);
    }
    ppuVar3 = ppuVar3 + 1;
    puVar4 = puVar4 + 1;
  } while ((int)ppuVar3 < 0x575170);
  return;
}

