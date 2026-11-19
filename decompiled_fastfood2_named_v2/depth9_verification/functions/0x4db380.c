// rea decompile_all
// name: FUN_004db380
// address: 0x4db380
// body: available
// range: 0x4db380-0x4db42a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004db380(int param_1,int *param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  FUN_004db2e0(param_1,param_2);
  iVar3 = 0;
  cVar2 = *(char *)(*param_2 + param_1);
  if (cVar2 != '\"') {
    while (((cVar2 != ' ' && (cVar2 = *(char *)(*param_2 + param_1), cVar2 != '\t')) &&
           (cVar2 != ','))) {
      if (iVar3 < param_4 + -1) {
        *(char *)(iVar3 + (int)param_3) = cVar2;
        *(undefined1 *)(iVar3 + 1 + (int)param_3) = 0;
      }
      iVar4 = *param_2;
      iVar3 = iVar3 + 1;
      *param_2 = iVar4 + 1;
      cVar2 = *(char *)(iVar4 + 1 + param_1);
    }
    return;
  }
  iVar3 = *param_2 + 1;
  cVar2 = *(char *)(iVar3 + param_1);
  iVar4 = iVar3;
  while ((cVar2 != '\0' && (cVar2 != '\"'))) {
    iVar1 = iVar4 + 1;
    iVar4 = iVar4 + 1;
    cVar2 = *(char *)(iVar1 + param_1);
  }
  uVar6 = param_4 - 1;
  uVar5 = iVar4 - iVar3;
  if ((iVar4 - iVar3 < (int)uVar6) || (uVar5 = uVar6, SBORROW4(uVar6,uVar6))) {
  }
  puVar7 = (undefined4 *)(iVar3 + param_1);
  puVar8 = param_3;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  }
  *(undefined1 *)(uVar5 + (int)param_3) = 0;
  return;
}

