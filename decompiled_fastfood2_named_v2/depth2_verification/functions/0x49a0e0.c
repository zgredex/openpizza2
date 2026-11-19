// rea decompile_all
// name: FUN_0049a0e0
// address: 0x49a0e0
// body: available
// range: 0x49a0e0-0x49a1be inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0049a0e0(void)

{
  void *this;
  int iVar1;
  byte *pbVar2;
  char *pcVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055866b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00499be0();
  FUN_0049d280(*(void **)(DAT_0057c670 + 0x25c));
  this = operator_new(0x330);
  local_4 = 0;
  if (this == (void *)0x0) {
    DAT_0057cda0 = (byte *)0x0;
  }
  else {
    DAT_0057cda0 = (byte *)FUN_0050fc20(this,(int *)0x0,'\0');
  }
  local_4 = 0xffffffff;
  pbVar2 = DAT_0057cda0;
  pcVar3 = DAT_00582c6c;
  iVar1 = FUN_00482820(DAT_0057c670);
  FUN_00499f30(iVar1,pbVar2,pcVar3);
  FUN_004014b0((void *)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x110)
               ,DAT_0057cda0);
  *(byte **)(DAT_0057c670 + 0x98) = DAT_0057cda0;
  UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x25c),-0x1866a,0x23,1);
  ExceptionList = local_c;
  return;
}

