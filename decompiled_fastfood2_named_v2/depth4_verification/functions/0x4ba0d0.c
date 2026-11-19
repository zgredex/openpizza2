// rea decompile_all
// name: FUN_004ba0d0
// address: 0x4ba0d0
// body: available
// range: 0x4ba0d0-0x4ba245 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004ba0d0(void *param_1)

{
  void *pvVar1;
  longlong lVar2;
  int iVar3;
  
  FUN_00531470(param_1,0x411,0);
  FUN_00531470(param_1,0x412,0);
  FUN_00531470(param_1,0x413,0);
  FUN_00531470(param_1,0x414,0);
  FUN_00531470(param_1,0x415,0);
  DAT_0057d6e8 = *(int *)((int)DAT_0057c670 + 0x9c);
  Sound_StartSpeech(DAT_0057ba0c,DAT_0057d6e8);
  FUN_00532a30(param_1,0x3f5,0x131);
  FUN_00532a30(param_1,0x3f6,0x133);
  FUN_00532310(param_1,&LAB_004ba090,0);
  FUN_00532330(param_1,0,5,0x3fb);
  FUN_00488a10(DAT_0057c670,param_1);
  if (DAT_0057d6e8 != 0) {
    FUN_0052f9b0(param_1,0x40f,DAT_0057d6e8 + 4);
  }
  FUN_004a66d0(param_1,0x1f48,
               *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  FUN_0054bcc0(*(void **)((int)DAT_0057c670 + 0x2d9c),param_1,0x430);
  pvVar1 = DAT_0057c670;
  iVar3 = 0;
  lVar2 = __ftol();
  Sound_UpdateListener
            (*(void **)((int)pvVar1 + 0x2d9c),(uint)lVar2,(int)((ulonglong)lVar2 >> 0x20),iVar3);
  FUN_0048e6d0(param_1);
  if (*(int *)(*(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xac) + 0xd0) == 0) {
    FUN_00482f40(DAT_0057c670,'\x01');
  }
  return;
}

