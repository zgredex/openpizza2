// rea decompile_all
// name: FUN_004dd130
// address: 0x4dd130
// body: available
// range: 0x4dd130-0x4dd267 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall FUN_004dd130(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  longlong lVar5;
  undefined4 *local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055926b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = operator_new(0x1c);
  iVar4 = 0;
  local_4 = 0;
  if (local_10 == (void *)0x0) {
    local_24 = (undefined4 *)0x0;
  }
  else {
    local_24 = List_Construct(local_10,0);
  }
  local_4 = 0xffffffff;
  FUN_004f34f0(*(void **)((int)this + 0xfa8),*(int *)(param_1 + 0x24),&local_20,&local_18);
  pvVar3 = *(void **)((int)this + 0xfc0);
  local_10 = pvVar3;
  if ((int)pvVar3 < 1) {
    ExceptionList = local_c;
    return local_24;
  }
  do {
    iVar1 = FUN_004017f0((void *)((int)this + 0xfac),iVar4,(int *)0x0);
    if (*(int *)(iVar1 + 4) == 0x1b) {
      piVar2 = operator_new(0xc);
      *piVar2 = iVar4;
      FUN_004f34f0(*(void **)((int)this + 0xfa8),*(int *)(iVar1 + 0x24),&local_1c,&local_14);
      lVar5 = __ftol();
      piVar2[1] = (int)lVar5;
      FUN_004014b0(local_24,piVar2);
      pvVar3 = local_10;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < (int)pvVar3);
  ExceptionList = local_c;
  return local_24;
}

