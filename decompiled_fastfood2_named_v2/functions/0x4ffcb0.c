// rea decompile_all
// name: FUN_004ffcb0
// address: 0x4ffcb0
// body: available
// range: 0x4ffcb0-0x4ffdfb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_004ffcb0(void)

{
  void *pvVar1;
  void *this;
  uint uVar2;
  undefined1 local_res0;
  undefined4 uStack00000004;
  undefined4 uStack00000008;
  undefined4 *puStack0000000c;
  undefined4 uStack00000010;
  undefined4 uStack00000014;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  void *in_stack_00001928;
  void *in_stack_00001938;
  int in_stack_0000193c;
  undefined1 uVar3;
  int local_8 [2];
  
  pvVar1 = ExceptionList;
  local_8[1] = 0xffffffff;
  uVar3 = SUB41(ExceptionList,0);
  ExceptionList = local_8 + -1;
  FUN_0054f110(uVar3);
  uStack00000004 = *(undefined4 *)((int)in_stack_00001938 + 0x38);
  uStack00000014 = 2;
  uStack00000018 = 2;
  uStack00000020 = *(undefined4 *)((int)in_stack_00001938 + 0x1a00);
  uStack00000010 = *(undefined4 *)((int)in_stack_00001938 + 0x14e0);
  uStack00000008 = 1;
  puStack0000000c = (undefined4 *)0x0;
  uStack0000001c = 0;
  uStack00000024 = uStack00000020;
  this = operator_new(0x1c);
  if (this == (void *)0x0) {
    puStack0000000c = (undefined4 *)0x0;
  }
  else {
    puStack0000000c = FUN_004013a0(this,0);
  }
  FUN_004f96e0((int)&local_res0);
  FUN_004fab10((int *)&local_res0,5,'-',in_stack_0000193c);
  FUN_004fb600(puStack0000000c,local_8 + 1,local_8 + -1);
  if (pvVar1 == (void *)0x0) {
    FUN_004fc0b0(puStack0000000c);
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00477e40(in_stack_00001938,4,(float)(int)pvVar1,'\x01',-1);
    uVar2 = uVar2 & 0xff;
    uStack0000001c = 1;
    if (uVar2 != 0) {
      FUN_004fbee0((int *)&local_res0,'\x01');
    }
  }
  ExceptionList = in_stack_00001928;
  return uVar2;
}

