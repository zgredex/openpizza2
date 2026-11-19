// rea decompile_all
// name: FUN_0048e0b0
// address: 0x48e0b0
// body: available
// range: 0x48e0b0-0x48e19b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0048e0b0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar2 = Game_GetPlayerCity(*(int *)(param_1 + 0x200 + *(int *)(param_1 + 0x2ec) * 4));
  DAT_0057c1f8 = *(undefined4 *)(iVar2 + 0x3c);
  DAT_0057c1fc = *(undefined4 *)(iVar2 + 0x40);
  DAT_0057c200 = *(undefined4 *)(iVar2 + 0x44);
  DAT_0057c204 = *(undefined4 *)(iVar2 + 0x48);
  DAT_0057c208 = *(undefined4 *)(iVar2 + 0x4c);
  DAT_0057c20c = *(undefined4 *)(iVar2 + 0x50);
  DAT_0057c210 = *(undefined4 *)(iVar2 + 0x54);
  DAT_0057c214 = *(undefined4 *)(iVar2 + 0x58);
  DAT_0057c218 = *(undefined4 *)(iVar2 + 0x5c);
  DAT_0057c21c = *(undefined4 *)(iVar2 + 0x60);
  DAT_0057c220 = *(undefined4 *)(iVar2 + 100);
  DAT_0057c224 = *(undefined4 *)(iVar2 + 0x68);
  DAT_0057c240 = *(undefined4 *)(iVar2 + 0x2c);
  DAT_0057c244 = *(undefined4 *)(iVar2 + 0x30);
  DAT_0057c248 = *(undefined4 *)(*(int *)(iVar2 + 4) + 0x40);
  DAT_0057c24c._0_2_ = *(undefined2 *)(*(int *)(param_1 + 0x94) + 4);
  DAT_0057c24c._2_1_ = *(undefined1 *)(*(int *)(param_1 + 0x94) + 8);
  puVar3 = (undefined4 *)(iVar2 + 0x6c);
  _DAT_0057c250 = (uint)*(byte *)(*(int *)(param_1 + 0x94) + 7);
  puVar4 = &DAT_0057c228;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  } while ((int)puVar4 < 0x57c240);
  return;
}

