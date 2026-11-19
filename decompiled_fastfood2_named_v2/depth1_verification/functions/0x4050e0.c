// rea decompile_all
// name: FUN_004050e0
// address: 0x4050e0
// body: available
// range: 0x4050e0-0x405292 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_004050e0(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  undefined4 uVar10;
  
  iVar6 = 0;
  piVar1 = &DAT_0057b768;
  do {
    *piVar1 = iVar6;
    piVar1 = piVar1 + 1;
    iVar6 = iVar6 + 1;
  } while ((int)piVar1 < 0x57b788);
  iVar6 = 0;
  piVar1 = &DAT_0057c258;
  do {
    *piVar1 = iVar6;
    piVar1 = piVar1 + 1;
    iVar6 = iVar6 + 1;
  } while ((int)piVar1 < 0x57c278);
  uVar2 = FUN_004034d0(10,0x19);
  if (0 < (int)uVar2) {
    do {
      uVar3 = FUN_004034d0(0,7);
      uVar4 = FUN_004034d0(0,7);
      uVar10 = (&DAT_0057b768)[uVar3];
      (&DAT_0057b768)[uVar3] = (&DAT_0057b768)[uVar4];
      (&DAT_0057b768)[uVar4] = uVar10;
      uVar3 = FUN_004034d0(0,7);
      uVar4 = FUN_004034d0(0,7);
      uVar10 = (&DAT_0057c258)[uVar3];
      (&DAT_0057c258)[uVar3] = (&DAT_0057c258)[uVar4];
      uVar2 = uVar2 - 1;
      (&DAT_0057c258)[uVar4] = uVar10;
    } while (uVar2 != 0);
  }
  puVar8 = &DAT_0057bdc0;
  puVar5 = (undefined4 *)&DAT_0057bb20;
  for (iVar6 = 0x16e; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  DAT_0057bb20 = 0;
  DAT_0057bb54._0_1_ = 0;
  DAT_0057bd14 = 1;
  iVar6 = 0;
  do {
    uVar2 = FUN_004034d0(0,1);
    puVar8[-2] = uVar2;
    uVar2 = FUN_004034d0(0,DAT_0058557c - 1);
    iVar7 = DAT_00585580;
    puVar8[-1] = uVar2;
    uVar2 = FUN_004034d0(0,iVar7 - 1);
    iVar7 = DAT_00585584;
    *puVar8 = uVar2;
    uVar2 = FUN_004034d0(0,iVar7 - 1);
    puVar8[1] = uVar2;
    uVar4 = FUN_004034d0(0,DAT_00585588 - 1);
    uVar2 = *(uint *)((int)&DAT_0057b76c + iVar6);
    uVar3 = *(uint *)((int)&DAT_0057c25c + iVar6);
    puVar8[2] = uVar4;
    puVar8[3] = uVar2;
    puVar8[4] = uVar3;
    puVar8[-10] = 100;
    puVar8[-9] = 0;
    puVar9 = puVar8 + -8;
    for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    IDMap_GetRandomName(DAT_0057ba10,puVar8[-2],(char *)(puVar8 + -0x2a));
    uVar10 = 0;
    uVar2 = FUN_004034d0(0,0x29);
    FUN_0054dd83((undefined1 *)(puVar8 + -0x1a),*(byte **)(&DAT_00583bb0 + uVar2 * 4),uVar10);
    puVar8[5] = 1;
    iVar6 = iVar6 + 4;
    puVar8 = puVar8 + 0x30;
  } while (iVar6 < 0x14);
  puVar5 = &DAT_0057be94;
  do {
    *puVar5 = 0;
    puVar5 = puVar5 + 0x30;
  } while ((int)puVar5 < 0x57c194);
  return;
}

