// rea decompile_all
// name: FUN_004f5660
// address: 0x4f5660
// body: available
// range: 0x4f5660-0x4f572f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004f5660(void *this,LPCSTR param_1)

{
  undefined4 *puVar1;
  int iStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055a0ab;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  if (*(undefined4 **)((int)this + 0x78) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)((int)this + 0x78))(1);
  }
  pvStack_10 = operator_new(0x50);
  uStack_4 = 0;
  if (pvStack_10 == (void *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = Sprite_Load(pvStack_10,DAT_0057c5c8,*(void **)(*(int *)((int)this + 4) + 0x2bf44),
                         param_1,&iStack_14,0,(void *)0x0,0);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 **)((int)this + 0x78) = puVar1;
  if (iStack_14 != 0) {
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    *(undefined4 *)((int)this + 0x78) = 0;
  }
  *(undefined4 *)((int)this + 0xf4) = 1;
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  ExceptionList = pvStack_c;
  return;
}

