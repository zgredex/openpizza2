// rea decompile_all
// name: FUN_004dc1a0
// address: 0x4dc1a0
// body: available
// range: 0x4dc1a0-0x4dc325 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004dc1a0(void *this,int param_1,void *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  void *this_00;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *this_01;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char local_4c [64];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055922b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar3 = FUN_00513fd0(param_1);
  uVar2 = *(undefined4 *)(param_1 + 0x34);
  FUN_00401320(*(int *)((int)DAT_0057c670 + 0x240));
  FUN_00401320(*(int *)((int)DAT_0057c670 + 0x244));
  iVar7 = 0;
  if (0 < iVar3 + 1) {
    do {
      this_00 = operator_new(0x16c);
      this_01 = (char *)0x0;
      local_4 = 0;
      if (this_00 != (void *)0x0) {
        this_01 = (char *)FUN_00504610(this_00,0xc,*(int *)((int)this + 0xc1c),0,0,-1);
      }
      local_4 = 0xffffffff;
      iVar4 = FUN_00513fc0(param_1);
      FUN_0054dd83(local_4c,(byte *)s_Sup__s_0056d03c,iVar4);
      uVar5 = 0xffffffff;
      pcVar9 = local_4c;
      do {
        pcVar8 = pcVar9;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar8 = pcVar9 + 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar8;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      pcVar8 = pcVar8 + -uVar5;
      pcVar9 = this_01;
      for (uVar6 = uVar5 >> 2; pcVar9 = pcVar9 + 4, uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      Game_AddObjectToRegistry(DAT_0057c670,this_01);
      FUN_0050e730(this_01,param_2,1);
      *(void **)(this_01 + 0xcc) = param_2;
      uVar5 = FUN_004034d0(4,7);
      *(uint *)(this_01 + 0x98) = uVar5 * iVar7 + 1;
      FUN_0050e890(this_01,0x34);
      *(undefined4 *)(this_01 + 0x100) = uVar2;
      FUN_0050e4c0(this_01,0x10);
      FUN_0050e850(this_01,0x18);
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar3 + 1);
  }
  FUN_00401340(*(int *)((int)DAT_0057c670 + 0x244));
  FUN_00401340(*(int *)((int)DAT_0057c670 + 0x240));
  ExceptionList = local_c;
  return;
}

