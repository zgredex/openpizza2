// rea decompile_all
// name: FUN_0049f240
// address: 0x49f240
// body: available
// range: 0x49f240-0x49f3a0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_0049f240(void *param_1,undefined4 *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *this;
  int iVar5;
  int local_114;
  char local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055878e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (DAT_0057cda0 != (void *)0x0) {
    ExceptionList = &local_c;
    PlayerStats_Reset((int)DAT_0057cda0);
    iVar4 = FUN_00482820(DAT_0057c670);
    FUN_00512620(DAT_0057cda0,iVar4);
    FUN_0049d280(param_1);
  }
  if (param_2 == (undefined4 *)0x0) {
    this = operator_new(0x330);
    local_4 = 0;
    if (this == (void *)0x0) {
      param_2 = (undefined4 *)0x0;
    }
    else {
      param_2 = FUN_0050fc20(this,(int *)0x0,'\0');
    }
    local_4 = 0xffffffff;
  }
  iVar4 = param_2[0x17];
  local_114 = 0;
  DAT_0057cda0 = param_2;
  if (0 < iVar4) {
    do {
      iVar5 = FUN_004017f0(DAT_0057cda0 + 0x12,local_114,(int *)0x0);
      if (*(char *)(iVar5 + 0x11) == '\0') {
        bVar1 = *(byte *)(iVar5 + 0x10);
        iVar2 = *(int *)(iVar5 + 8);
        iVar3 = *(int *)(iVar5 + 0xc);
        FUN_0054dd83(local_10c,(byte *)s_zutaten_ZA_02dA__02d_spr_00568948,*(byte *)(iVar5 + 4) + 1)
        ;
        FUN_00531850(param_1,local_114 + 100000,iVar2,iVar3,local_10c);
        FUN_00531960(param_1,local_114 + 100000,(uint)bVar1);
        *(undefined4 *)((int)param_1 + 0xe0) = 1;
      }
      local_114 = local_114 + 1;
    } while (local_114 < iVar4);
    if (0 < iVar4) {
      *(undefined4 *)((int)param_1 + 0xe0) = 1;
    }
  }
  ExceptionList = local_c;
  return;
}

