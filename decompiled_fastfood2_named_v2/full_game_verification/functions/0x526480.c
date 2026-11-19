// rea decompile_all
// name: UI_LoadSpriteSet
// address: 0x526480
// body: available
// range: 0x526480-0x526588 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall UI_LoadSpriteSet(void *this,undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iStack_118;
  void *pvStack_114;
  CHAR aCStack_110 [260];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055a79e;
  pvStack_c = ExceptionList;
  iVar2 = 8;
  piVar4 = (int *)((int)this + 0x250);
  piVar3 = piVar4;
  ExceptionList = &pvStack_c;
  do {
    if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar3)(1);
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 0;
  piVar3 = piVar4;
  while( true ) {
    String_Format(aCStack_110,(byte *)s__s__02d_spr_00573b9c,param_1);
    pvStack_114 = operator_new(0x50);
    uStack_4 = 0;
    if (pvStack_114 == (void *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = Sprite_Load(pvStack_114,*(void **)((int)this + 0xc),*(void **)((int)this + 0x10),
                           aCStack_110,&iStack_118,0,(void *)0x0,0);
    }
    *piVar3 = (int)puVar1;
    uStack_4 = 0xffffffff;
    if (iStack_118 != 0) break;
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
    if (7 < iVar2) {
      ExceptionList = pvStack_c;
      return 1;
    }
  }
  if (-1 < iVar2) {
    iVar2 = iVar2 + 1;
    do {
      if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar4)(1);
      }
      *piVar4 = 0;
      piVar4 = piVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  ExceptionList = pvStack_c;
  return 0;
}

