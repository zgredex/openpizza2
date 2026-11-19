// rea decompile_all
// name: FUN_004be820
// address: 0x4be820
// body: available
// range: 0x4be820-0x4be974 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004be820(void *param_1,char param_2)

{
  void *this;
  int iVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  undefined1 local_80 [128];
  
  if (param_2 != '\0') {
    Sound_ProcessEvent(DAT_0057ba0c,0x17,0,'\x01');
  }
  iVar1 = *(int *)((int)DAT_0057c670 + 0x21c);
  this = (void *)FUN_00488be0(DAT_0057c670,*(int *)(iVar1 + 0x110));
  FUN_0052fd70(param_1,0x1f4f,*(undefined4 *)(iVar1 + 0xa8),0);
  if (*(int *)(iVar1 + 0xa4) == -1) {
    puVar3 = DAT_00580b7c;
  }
  else {
    iVar1 = FUN_004017f0((void *)((int)this + 0x148),*(int *)(iVar1 + 0x10c),(int *)0x0);
    if (iVar1 == 0) {
      puVar3 = DAT_00580b7c;
    }
    else {
      FUN_0054dd83(local_80,DAT_00580d18,iVar1 + 4);
      puVar3 = local_80;
    }
  }
  FUN_0052f9b0(param_1,0x1f52,puVar3);
  FUN_0052f9b0(param_1,0x1f78,(int)this + 8);
  FUN_004a66d0(param_1,0x1f83,(int)this);
  FUN_0052f080(param_1,0x1f7e,(byte *)s__s__d_00568964,DAT_00581044);
  puVar2 = FUN_004e25b0(this,0x17,0);
  FUN_0052f080(param_1,0x1f68,&DAT_005686f4,puVar2);
  puVar2 = FUN_004e25b0(this,0x17,1);
  FUN_0052f080(param_1,0x1f67,&DAT_005686f4,puVar2);
  puVar2 = FUN_004e25b0(this,0x17,2);
  FUN_0052f080(param_1,0x1f54,&DAT_005686f4,puVar2);
  return;
}

