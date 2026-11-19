// rea decompile_all
// name: FUN_00402b80
// address: 0x402b80
// body: available
// range: 0x402b80-0x402ce2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00402b80(void *this,char *param_1,uint *param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  char *pcVar8;
  
  if (param_1[1] == ':') {
    uVar3 = 0xffffffff;
    do {
      pcVar2 = param_1;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar2 = param_1 + 1;
      cVar1 = *param_1;
      param_1 = pcVar2;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    puVar6 = (uint *)(pcVar2 + -uVar3);
    puVar7 = param_2;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(char *)puVar7 = (char)*puVar6;
      puVar6 = (uint *)((int)puVar6 + 1);
      puVar7 = (uint *)((int)puVar7 + 1);
    }
    FUN_0054ee99(param_2);
    pcVar2 = _strchr((char *)param_2,0x2f);
    if (pcVar2 != (char *)0x0) {
      do {
        *pcVar2 = '\\';
        pcVar2 = _strchr((char *)param_2,0x2f);
      } while (pcVar2 != (char *)0x0);
      return;
    }
  }
  else {
    pcVar2 = _strrchr(param_1,0x2e);
    if (pcVar2 != (char *)0x0) {
      uVar3 = 0xffffffff;
      pcVar8 = pcVar2;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      if ((~uVar3 - 1 < 0x40) &&
         (pcVar2 = (char *)FUN_00402ad0(this,pcVar2 + 1), pcVar2 != (char *)0x0)) {
        uVar3 = 0xffffffff;
        do {
          pcVar8 = pcVar2;
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          pcVar8 = pcVar2 + 1;
          cVar1 = *pcVar2;
          pcVar2 = pcVar8;
        } while (cVar1 != '\0');
        uVar3 = ~uVar3;
        puVar6 = (uint *)(pcVar8 + -uVar3);
        puVar7 = param_2;
        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(char *)puVar7 = (char)*puVar6;
          puVar6 = (uint *)((int)puVar6 + 1);
          puVar7 = (uint *)((int)puVar7 + 1);
        }
        uVar3 = 0xffffffff;
        do {
          pcVar2 = param_1;
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          pcVar2 = param_1 + 1;
          cVar1 = *param_1;
          param_1 = pcVar2;
        } while (cVar1 != '\0');
        uVar3 = ~uVar3;
        iVar5 = -1;
        puVar6 = param_2;
        do {
          puVar7 = puVar6;
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          puVar7 = (uint *)((int)puVar6 + 1);
          uVar4 = *puVar6;
          puVar6 = puVar7;
        } while ((char)uVar4 != '\0');
        pcVar2 = pcVar2 + -uVar3;
        pcVar8 = (char *)((int)puVar7 + -1);
        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
          pcVar2 = pcVar2 + 4;
          pcVar8 = pcVar8 + 4;
        }
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *pcVar8 = *pcVar2;
          pcVar2 = pcVar2 + 1;
          pcVar8 = pcVar8 + 1;
        }
        FUN_0054ee99(param_2);
        pcVar2 = _strchr((char *)param_2,0x2f);
        if (pcVar2 == (char *)0x0) {
          return;
        }
        do {
          *pcVar2 = '\\';
          pcVar2 = _strchr((char *)param_2,0x2f);
        } while (pcVar2 != (char *)0x0);
        return;
      }
    }
    uVar3 = 0xffffffff;
    do {
      pcVar2 = param_1;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar2 = param_1 + 1;
      cVar1 = *param_1;
      param_1 = pcVar2;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    puVar6 = (uint *)(pcVar2 + -uVar3);
    puVar7 = param_2;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(char *)puVar7 = (char)*puVar6;
      puVar6 = (uint *)((int)puVar6 + 1);
      puVar7 = (uint *)((int)puVar7 + 1);
    }
    FUN_0054ee99(param_2);
    pcVar2 = _strchr((char *)param_2,0x2f);
    while (pcVar2 != (char *)0x0) {
      *pcVar2 = '\\';
      pcVar2 = _strchr((char *)param_2,0x2f);
    }
  }
  return;
}

