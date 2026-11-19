// rea decompile_all
// name: FUN_0049a040
// address: 0x49a040
// body: available
// range: 0x49a040-0x49a0d5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __cdecl FUN_0049a040(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  bool bVar7;
  
  iVar6 = 0;
  iVar2 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  if ((int)*(uint *)(iVar2 + 0x124) < 1) {
    return *(uint *)(iVar2 + 0x124) & 0xffffff00;
  }
  do {
    iVar3 = FUN_004017f0((void *)(iVar2 + 0x110),iVar6,(int *)0x0);
    if (iVar3 != *(int *)(DAT_0057c670 + 0x98)) {
      pbVar4 = (byte *)(iVar3 + 4);
      pbVar5 = param_1;
      do {
        bVar1 = *pbVar4;
        bVar7 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_0049a0ad:
          iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_0049a0b2;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar7 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_0049a0ad;
        pbVar4 = pbVar4 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_0049a0b2:
      if (iVar3 == 0) {
        return 1;
      }
    }
    iVar6 = iVar6 + 1;
    if ((int)*(uint *)(iVar2 + 0x124) <= iVar6) {
      return *(uint *)(iVar2 + 0x124) & 0xffffff00;
    }
  } while( true );
}

