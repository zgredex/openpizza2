// rea decompile_all
// name: FUN_004c7110
// address: 0x4c7110
// body: available
// range: 0x4c7110-0x4c7313 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004c7110(void *param_1)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uVar8;
  
  FUN_004c7320(param_1);
  FUN_0052f9b0(param_1,0x429,DAT_00582e4c);
  DAT_0057dda0 = DAT_0057b93c;
  DAT_0057ddfc = DAT_0057b940;
  DAT_0057ddb8 = DAT_0057b944;
  DAT_0057dda4 = DAT_0057b948;
  DAT_0057ddb0 = DAT_0057b8b0;
  DAT_0057ddac = DAT_0057b938;
  DAT_0057dd44 = _DAT_0057b8ac;
  if ((char)DAT_0057b8f8 == '\0') {
    FUN_00403020(DAT_0057ba10,DAT_0057b938,(char *)&DAT_0057dd60);
  }
  else {
    uVar3 = 0xffffffff;
    pcVar6 = (char *)&DAT_0057b8f8;
    do {
      pcVar7 = pcVar6;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = pcVar6 + 1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar7;
    } while (cVar2 != '\0');
    uVar3 = ~uVar3;
    pcVar6 = pcVar7 + -uVar3;
    pcVar7 = (char *)&DAT_0057dd60;
    for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
  }
  FUN_0052fbc0(param_1,0x40c,&DAT_0057dd60);
  if ((char)DAT_0057b8b8 == '\0') {
    uVar8 = 0;
    uVar3 = Random_Range(0,0x29);
    String_Format((undefined1 *)&DAT_0057ddbc,*(byte **)(&DAT_00583bb0 + uVar3 * 4),uVar8);
  }
  else {
    uVar3 = 0xffffffff;
    pcVar6 = (char *)&DAT_0057b8b8;
    do {
      pcVar7 = pcVar6;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = pcVar6 + 1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar7;
    } while (cVar2 != '\0');
    uVar3 = ~uVar3;
    pcVar6 = pcVar7 + -uVar3;
    pcVar7 = (char *)&DAT_0057ddbc;
    for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
  }
  FUN_0052fbc0(param_1,0x40a,&DAT_0057ddbc);
  FUN_00532330(param_1,0,2,0x43a);
  FUN_0052ff50(param_1,0x43b - DAT_0057ddac,1);
  FUN_0052f9b0(param_1,0x423,DAT_00582280);
  DAT_0057ddb4 = 0;
  iVar4 = 0;
  do {
    piVar1 = (int *)((int)&DAT_0057b94c + iVar4);
    *(int *)((int)&DAT_0057dd48 + iVar4) = *piVar1;
    iVar4 = iVar4 + 4;
    DAT_0057ddb4 = DAT_0057ddb4 - *piVar1;
  } while (iVar4 < 0x18);
  DAT_0057dda8 = DAT_0057b8b4;
  FUN_0052fd00(param_1,0x407,0,10,0);
  FUN_0052fd70(param_1,0x407,DAT_0057dda8,0);
  FUN_0052fce0(param_1,0x407,1);
  FUN_004c6f50(param_1);
  FUN_004c6f90(param_1);
  FUN_004c7040(param_1);
  FUN_00531740(param_1,0x406);
  FUN_00531740(param_1,0x407);
  FUN_00531740(param_1,0x408);
  return;
}

