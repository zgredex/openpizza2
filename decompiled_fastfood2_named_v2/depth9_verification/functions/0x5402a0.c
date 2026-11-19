// rea decompile_all
// name: FUN_005402a0
// address: 0x5402a0
// body: available
// range: 0x5402a0-0x540380 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_005402a0(void *this,char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  char *pcVar7;
  uint *puVar8;
  char *pcVar9;
  
  pcVar2 = (char *)FUN_00540510(this,param_2);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = operator_new(0x54);
    uVar3 = 0xffffffff;
    do {
      pcVar7 = param_1;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = param_1 + 1;
      cVar1 = *param_1;
      param_1 = pcVar7;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar7 = pcVar7 + -uVar3;
    pcVar9 = pcVar2;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar9 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
    uVar3 = 0xffffffff;
    do {
      pcVar7 = param_2;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = param_2 + 1;
      cVar1 = *param_2;
      param_2 = pcVar7;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    puVar6 = (uint *)(pcVar7 + -uVar3);
    puVar8 = (uint *)(pcVar2 + 0x40);
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(char *)puVar8 = (char)*puVar6;
      puVar6 = (uint *)((int)puVar6 + 1);
      puVar8 = (uint *)((int)puVar8 + 1);
    }
    CRT_Strlwr((uint *)(pcVar2 + 0x40));
    *(undefined4 *)(pcVar2 + 0x50) = *(undefined4 *)((int)this + 0x628);
    *(char **)((int)this + 0x628) = pcVar2;
  }
  else {
    uVar3 = 0xffffffff;
    do {
      pcVar7 = param_1;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = param_1 + 1;
      cVar1 = *param_1;
      param_1 = pcVar7;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar7 = pcVar7 + -uVar3;
    pcVar9 = pcVar2;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar9 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  uVar3 = 0xffffffff;
  pcVar7 = pcVar2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  if (pcVar2[~uVar3 - 2] != '\\') {
    uVar3 = 0xffffffff;
    pcVar7 = &DAT_00563278;
    do {
      pcVar9 = pcVar7;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar9 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar5 = -1;
    do {
      pcVar7 = pcVar2;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar7 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar7;
    } while (cVar1 != '\0');
    pcVar2 = pcVar9 + -uVar3;
    pcVar7 = pcVar7 + -1;
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
  }
  return;
}

