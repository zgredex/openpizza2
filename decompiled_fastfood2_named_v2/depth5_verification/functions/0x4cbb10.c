// rea decompile_all
// name: FUN_004cbb10
// address: 0x4cbb10
// body: available
// range: 0x4cbb10-0x4cbcc6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004cbb10(void *param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *this;
  int iVar5;
  BYTE *pBVar6;
  int *piVar7;
  char *pcVar8;
  int local_1a0;
  void *local_19c;
  char local_198 [64];
  CHAR local_158 [64];
  char local_118 [64];
  BYTE local_d8 [64];
  int local_98 [35];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558bfe;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = FUN_004cda50(&DAT_0057de38,DAT_0057bb40);
  FUN_0054dd83(local_158,(byte *)s__s_hi_00568368,puVar1);
  iVar2 = FUN_004cb950(local_158,local_d8);
  if (iVar2 == 0) {
    FUN_0054dd83(local_118,(byte *)s_names__s_txt_00568358,puVar1);
    local_19c = operator_new(0x18);
    local_4 = 0;
    if (local_19c == (void *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = FUN_00402cf0(local_19c,DAT_0057c5d8,local_118,&local_1a0);
    }
    local_4 = 0xffffffff;
    if (local_1a0 != 0) {
      puVar3 = (undefined4 *)0x0;
    }
    iVar5 = 30000;
    pBVar6 = local_d8;
    for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
      pBVar6[0] = '\0';
      pBVar6[1] = '\0';
      pBVar6[2] = '\0';
      pBVar6[3] = '\0';
      pBVar6 = pBVar6 + 4;
    }
    piVar7 = local_98;
    do {
      if (puVar3 == (undefined4 *)0x0) {
        pcVar8 = local_198;
        uVar4 = FUN_004034d0(0,1);
        this = DAT_0057ba10;
      }
      else {
        pcVar8 = local_198;
        uVar4 = FUN_004034d0(0,1);
        this = puVar3;
      }
      FUN_00403020(this,uVar4,pcVar8);
      FUN_0054dd83((undefined1 *)(piVar7 + -0x10),&DAT_005630d0,local_198);
      *piVar7 = iVar5;
      iVar5 = iVar5 + -10000;
      piVar7 = piVar7 + 0x11;
    } while (0 < iVar5);
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(1);
    }
    FUN_004cba60(local_158,local_d8);
  }
  piVar7 = local_98;
  iVar2 = 0x495;
  do {
    FUN_0052f9b0(param_1,iVar2 + -3,piVar7 + -0x10);
    FUN_0052f080(param_1,iVar2,&DAT_005686f4,*piVar7);
    piVar7 = piVar7 + 0x11;
    iVar5 = iVar2 + -0x494;
    iVar2 = iVar2 + 1;
  } while (iVar5 < 3);
  ExceptionList = local_c;
  return;
}

