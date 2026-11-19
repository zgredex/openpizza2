// rea decompile_all
// name: FUN_0049fad0
// address: 0x49fad0
// body: available
// range: 0x49fad0-0x49fbe1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_0049fad0(void *param_1)

{
  void *pvVar1;
  undefined4 *this;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005587b6;
  local_c = ExceptionList;
  iVar4 = 0;
  if (0 < *(int *)(DAT_0057cd98 + 0x124)) {
    ExceptionList = &local_c;
    FUN_0052ff50(param_1,0x3fc,1);
    pvVar1 = operator_new(0x1c);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      this = (undefined4 *)0x0;
    }
    else {
      this = FUN_004013a0(pvVar1,0);
    }
    local_4 = 0xffffffff;
    if (0 < *(int *)(DAT_0057cd98 + 0x124)) {
      do {
        pvVar1 = operator_new(0x58);
        local_4 = 1;
        if (pvVar1 == (void *)0x0) {
          pcVar3 = (char *)0x0;
        }
        else {
          iVar5 = iVar4;
          iVar2 = FUN_004017f0((void *)(DAT_0057cd98 + 0x110),iVar4,(int *)0x0);
          pcVar3 = FUN_00403370(pvVar1,(char *)(iVar2 + 4),iVar5);
        }
        local_4 = 0xffffffff;
        FUN_004014b0(this,pcVar3);
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(DAT_0057cd98 + 0x124));
    }
    FUN_004835c0(DAT_0057c670,0xfffe798e,DAT_00582c34,DAT_00582c40,this,DAT_0057cd9c,param_1);
  }
  ExceptionList = local_c;
  return;
}

