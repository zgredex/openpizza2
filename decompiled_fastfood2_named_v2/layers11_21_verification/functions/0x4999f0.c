// rea decompile_all
// name: FUN_004999f0
// address: 0x4999f0
// body: available
// range: 0x4999f0-0x499bdb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004999f0(void *param_1,char param_2)

{
  void *this;
  int iVar1;
  int iVar2;
  
  DAT_00568914 = 0xffffffff;
  DAT_0057ca1c = 0;
  DAT_0057ca2c = 0;
  FUN_00532310(param_1,&LAB_004995b0,0);
  *(undefined4 *)(DAT_0057c5e0 + 0x831c) = 1;
  if (param_2 != '\0') {
    FUN_00532330(param_1,0,6,0x4eb);
  }
  Window_GadgetNotify_Button_SetState(param_1,(&DAT_00568914)[_DAT_00568910],1);
  if (param_2 != '\0') {
    FUN_00532330(param_1,1,0xc,0x4ed);
  }
  iVar2 = 0x509;
  do {
    FUN_00531470(param_1,iVar2,0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x515);
  iVar2 = 0;
  do {
    FUN_00531fb0(param_1,iVar2 + 0x4ed,1,(char *)0x0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xc);
  FUN_00531740(param_1,0x507);
  if (DAT_0057cda0 == 0) {
    Window_GadgetNotify_Text_SetText(param_1,0x448,DAT_00582d50);
    DAT_0057ca10 = 0;
  }
  else {
    Window_GadgetNotify_Text_SetText(param_1,0x448,DAT_0057cda0 + 4);
    DAT_0057ca10 = FUN_00510580(DAT_0057cda0);
    if (*(char *)(DAT_0057cda0 + 0x1dd) == '\x01') {
      FUN_005316b0(param_1,0x507);
    }
  }
  FUN_00499890(param_1);
  Gadget_SetText(param_1,0x4e8,DAT_00582cc4);
  this = *(void **)(DAT_0057c670 + 0x98);
  if (this == (void *)0x0) {
    iVar2 = 0;
    do {
      FUN_004a80e0(param_1,0x4df,iVar2,0,0);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    return;
  }
  iVar2 = 0;
  do {
    iVar1 = FUN_005104d0(this,iVar2);
    FUN_004a80e0(param_1,0x4df,iVar2,iVar1,DAT_0058155c);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  return;
}

