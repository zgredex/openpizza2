// rea decompile_all
// name: World_FindNameIndex
// address: 0x4eab80
// body: available
// range: 0x4eab80-0x4eabfe inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __thiscall World_FindNameIndex(void *this,uint *param_1)

{
  byte bVar1;
  byte *extraout_EAX;
  byte *extraout_EAX_00;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  uint *puVar6;
  bool bVar7;
  
                    /* Searches the world name pool for a string and returns its index. */
  FUN_0054f775(param_1);
  iVar2 = *(int *)((int)this + 0x20);
  uVar4 = 0;
  if (0 < iVar2) {
    puVar6 = (uint *)((int)this + 0x25);
    do {
      FUN_0054f775(puVar6);
      pbVar3 = extraout_EAX;
      pbVar5 = extraout_EAX_00;
      do {
        bVar1 = *pbVar3;
        bVar7 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_004eabd6:
          iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_004eabdb;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar7 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_004eabd6;
        pbVar3 = pbVar3 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar2 = 0;
LAB_004eabdb:
      if (iVar2 == 0) {
        return uVar4 & 0xffff;
      }
      iVar2 = *(int *)((int)this + 0x20);
      uVar4 = uVar4 + 1;
      puVar6 = puVar6 + 0x12;
    } while ((int)uVar4 < iVar2);
  }
  return CONCAT22((short)((uint)iVar2 >> 0x10),0xffff);
}

