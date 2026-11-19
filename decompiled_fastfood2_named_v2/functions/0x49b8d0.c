// rea decompile_all
// name: FUN_0049b8d0
// address: 0x49b8d0
// body: available
// range: 0x49b8d0-0x49ba4e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


bool __cdecl FUN_0049b8d0(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *this;
  int iVar4;
  void *this_00;
  int local_54;
  void *local_50;
  undefined1 local_4c [64];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055871b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  String_Format(local_4c,(byte *)s_save_menu__s_men_00568a44,param_1);
  local_50 = operator_new(0x58);
  local_4 = 0;
  if (local_50 == (void *)0x0) {
    this = (int *)0x0;
  }
  else {
    this = FUN_0054d140();
  }
  local_4 = 0xffffffff;
  if ((*(byte *)(*(int *)(*this + 4) + 8 + (int)this) & 6) != 0) {
    if (this != (int *)0x0) {
      (*(code *)**(undefined4 **)(*(int *)(*this + 4) + (int)this))(1);
    }
    ExceptionList = local_c;
    return false;
  }
  iVar1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar2 = *(int *)(iVar1 + 0x124);
  local_54 = 0;
  param_1 = 0x2e;
  FUN_0054cc2b(this,&param_1,4);
  param_1 = 0;
  if (0 < iVar2) {
    do {
      iVar4 = IDMap_Lookup((void *)(iVar1 + 0x110),param_1,(int *)0x0);
      if (*(char *)(iVar4 + 0x1dc) == '\x01') {
        local_54 = local_54 + 1;
      }
      param_1 = param_1 + 1;
    } while (param_1 < iVar2);
  }
  FUN_0054cc2b(this,&local_54,4);
  param_1 = 0;
  if (0 < iVar2) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)(iVar1 + 0x110),param_1,(int *)0x0);
      if (*(char *)((int)this_00 + 0x1dc) == '\x01') {
        FUN_00510640(this_00,this,'\0');
      }
      param_1 = param_1 + 1;
    } while (param_1 < iVar2);
  }
  uVar3 = *(uint *)(*(int *)(*this + 4) + 8 + (int)this);
  if (this != (int *)0x0) {
    (*(code *)**(undefined4 **)(*(int *)(*this + 4) + (int)this))(1);
  }
  ExceptionList = local_c;
  return (bool)('\x01' - ((uVar3 & 6) != 0));
}

