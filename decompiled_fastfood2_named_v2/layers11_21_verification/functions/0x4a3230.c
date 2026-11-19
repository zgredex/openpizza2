// rea decompile_all
// name: FUN_004a3230
// address: 0x4a3230
// body: available
// range: 0x4a3230-0x4a348c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a3230(void *param_1)

{
  void *this;
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 unaff_EDI;
  undefined4 *puVar6;
  int *piVar7;
  char *pcVar8;
  
  cVar2 = 0 < DAT_0057d014;
  puVar6 = &DAT_0057d220;
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  FUN_0054dd83(&DAT_0057d020,&DAT_00579aec,unaff_EDI);
  uVar1 = (uint)(byte)cVar2;
  FUN_005316f0(param_1,0x1f9e,uVar1);
  FUN_005316f0(param_1,0x1f5d,uVar1);
  FUN_005316f0(param_1,0x1f9d,uVar1);
  if (0 < DAT_0057d014) {
    pcVar8 = &DAT_0057d020;
    piVar7 = &DAT_0057d220;
    this = *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    iVar5 = DAT_00568ef0;
    iVar3 = FUN_00488be0(DAT_0057c670,DAT_00568ef4);
    uVar4 = FUN_004e33a0(this,iVar3,iVar5,piVar7,pcVar8);
    cVar2 = (char)uVar4;
  }
  if (cVar2 == '\0') {
    Gadget_SetTextf(param_1,0x1f5a,&DAT_00568f00,unaff_EDI);
  }
  else {
    Gadget_SetTextf(param_1,0x1f5a,(byte *)s__d__d_00568ef8,DAT_0057d018);
    iVar5 = FUN_00488be0(DAT_0057c670,DAT_00568ef4);
    if (DAT_00568ef0 < 0x14) {
      DAT_0057d01c = FUN_004017f0((void *)(iVar5 + 0x148),DAT_00568ef0,(int *)0x0);
      Window_GadgetNotify_Text_SetText(param_1,0x1f9d,DAT_0057d01c + 4);
    }
    else if (DAT_00568ef0 < 0x27) {
      iVar5 = FUN_004017f0((void *)(iVar5 + 0x180),DAT_00568ef0 + -0x14,(int *)0x0);
      iVar5 = FUN_00513fc0(iVar5);
      Window_GadgetNotify_Text_SetText(param_1,0x1f9d,iVar5);
    }
    else {
      Gadget_SetTextf(param_1,0x1f9d,(byte *)s__s__s_00563314,DAT_00581c50);
    }
  }
  FUN_005316f0(param_1,0x1f5d,(uint)(DAT_0057d01c != 0));
  Gadget_SetTextf(param_1,0x1f71,&DAT_005686f4,DAT_0057d220);
  Gadget_SetTextf(param_1,0x1f6c,&DAT_005686f4,DAT_0057d228);
  Gadget_SetTextf(param_1,0x1f6d,&DAT_005686f4,DAT_0057d230);
  Gadget_SetTextf(param_1,0x1f6e,&DAT_005686f4,DAT_0057d238);
  Gadget_SetTextf(param_1,0x1f70,&DAT_005686f4,DAT_0057d224);
  Gadget_SetTextf(param_1,0x1f65,&DAT_005686f4,DAT_0057d22c);
  Gadget_SetTextf(param_1,0x1f67,&DAT_005686f4,DAT_0057d234);
  Gadget_SetTextf(param_1,0x1f69,&DAT_005686f4,DAT_0057d23c);
  Window_GadgetNotify_Text_SetText(param_1,0x1f9e,&DAT_0057d020);
  return;
}

