// rea decompile_all
// name: FUN_004f6e70
// address: 0x4f6e70
// body: available
// range: 0x4f6e70-0x4f6fa5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004f6e70(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  int local_8;
  
  iVar5 = 0;
  puVar6 = (uint *)(param_1 + 0x114);
  uVar1 = *(uint *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2f0) * 4 + 0x224);
  local_8 = 0x224;
  do {
    uVar2 = *(uint *)(local_8 + (int)DAT_0057c670);
    if (uVar2 == 0) {
      puVar6[1] = 0;
      *puVar6 = 0;
    }
    else {
      puVar4 = puVar6 + -0x36;
      for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      *puVar6 = (uint)(uVar2 != uVar1);
      *(undefined1 *)(puVar6 + 0x23) = 0;
      puVar6[2] = 0xffffffff;
      puVar6[3] = 0xffffffff;
      puVar6[-0x2a] = uVar2;
      uVar2 = FUN_00488be0(DAT_0057c670,*(int *)(uVar2 + 8));
      puVar6[-0x29] = uVar2;
      uVar2 = FUN_00482840(DAT_0057c670,iVar5);
      puVar6[-0x35] = uVar2;
      puVar6[0x22] = 50000;
      uVar2 = FUN_004034d0(DAT_0057bb24 * 6,DAT_0057bb24 * 9);
      puVar4 = puVar6 + -0x28;
      *(short *)(puVar6 + 5) = (short)uVar2;
      puVar7 = puVar4;
      for (iVar3 = 0x28; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      puVar7 = puVar6 + -0x34;
      for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      iVar3 = 10;
      do {
        puVar4[3] = 0;
        *puVar4 = 0xffffffff;
        puVar4 = puVar4 + 4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      puVar4 = puVar6 + 9;
      for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      puVar6[6] = 3;
      puVar6[1] = 1;
    }
    local_8 = local_8 + 4;
    iVar5 = iVar5 + 1;
    puVar6 = puVar6 + 0x5a;
  } while (local_8 < 0x23c);
  return;
}

