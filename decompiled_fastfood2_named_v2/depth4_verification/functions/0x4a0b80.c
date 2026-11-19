// rea decompile_all
// name: FUN_004a0b80
// address: 0x4a0b80
// body: available
// range: 0x4a0b80-0x4a0d90 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_004a0b80(void)

{
  HCURSOR pHVar1;
  void *pvVar2;
  int iVar3;
  int *this;
  undefined4 local_100;
  undefined1 local_fc [240];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055882e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00406910(0);
  pHVar1 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
  SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar1);
  PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar1);
  pvVar2 = operator_new(0x5c);
  this = (int *)0x0;
  local_4 = 0;
  if (pvVar2 != (void *)0x0) {
    this = FUN_0054cc99();
  }
  local_4 = 0xffffffff;
  if ((*(byte *)(*(int *)(*this + 4) + 8 + (int)this) & 6) == 0) {
    DAT_0057cdac = 0;
    FUN_00548db0(DAT_0057ba0c);
    FUN_0054cbc1(this,local_fc,0xf0);
    FUN_00486be0(DAT_0057c670,1);
    FUN_00528160(DAT_0057c5e0);
    FUN_00401320(*(int *)((int)DAT_0057c670 + 0x240));
    iVar3 = FUN_00488110(DAT_0057c670,this,&DAT_0057cdac);
    if ((iVar3 == 0) || ((*(byte *)(*(int *)(*this + 4) + 8 + (int)this) & 6) != 0)) {
      local_100 = 0;
      FUN_00487310((int)DAT_0057c670);
    }
    else {
      local_100 = 1;
    }
    FUN_00401340(*(int *)((int)DAT_0057c670 + 0x240));
    *(undefined4 *)(*(int *)((int)DAT_0057c670 + 0x94) + 0x14) = 0xc35;
    FUN_00486e00((int)DAT_0057c670);
    if (this != (int *)0x0) {
      (*(code *)**(undefined4 **)(*(int *)(*this + 4) + (int)this))(1);
    }
    pHVar1 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar1);
    PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar1);
    FUN_00406a60();
  }
  else {
    pHVar1 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar1);
    PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar1);
    if (this != (int *)0x0) {
      (*(code *)**(undefined4 **)(*(int *)(*this + 4) + (int)this))(1);
    }
    FUN_00406a60();
    local_100 = 0;
  }
  ExceptionList = pvStack_c;
  return local_100;
}

