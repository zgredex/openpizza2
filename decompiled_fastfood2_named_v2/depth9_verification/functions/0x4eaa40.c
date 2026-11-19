// rea decompile_all
// name: FUN_004eaa40
// address: 0x4eaa40
// body: available
// range: 0x4eaa40-0x4eaa9c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_004eaa40(void *this,byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  
  iVar4 = 0;
  pbVar6 = (byte *)((int)this + 0x25);
  do {
    pbVar2 = param_1;
    pbVar5 = pbVar6;
    do {
      bVar1 = *pbVar2;
      bVar7 = bVar1 < *pbVar5;
      if (bVar1 != *pbVar5) {
LAB_004eaa75:
        iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_004eaa7a;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar7 = bVar1 < pbVar5[1];
      if (bVar1 != pbVar5[1]) goto LAB_004eaa75;
      pbVar2 = pbVar2 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_004eaa7a:
    if (iVar3 == 0) {
      return iVar4;
    }
    iVar4 = iVar4 + 1;
    pbVar6 = pbVar6 + 0x48;
    if (0x9c3 < iVar4) {
      return -1;
    }
  } while( true );
}

