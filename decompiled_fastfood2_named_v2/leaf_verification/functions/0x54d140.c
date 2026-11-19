// rea decompile_all
// name: FUN_0054d140
// address: 0x54d140
// body: available
// range: 0x54d140-0x54d1f6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int * FUN_0054d140(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *extraout_ECX;
  int unaff_EBP;
  
  CRT_StackFrameStub();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0x14) != 0) {
    *extraout_ECX = (int)&DAT_0055cc88;
    FUN_0054d85d(extraout_ECX + 2);
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  puVar4 = operator_new(0x54);
  *(undefined4 **)(unaff_EBP + 0x14) = puVar4;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (puVar4 != (undefined4 *)0x0) {
    FUN_0054cd91(puVar4);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0054d7e9();
  iVar2 = *(int *)(*extraout_ECX + 4);
  uVar3 = *(uint *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  *(undefined ***)(iVar2 + (int)extraout_ECX) = &PTR_LAB_0055cc84;
  *(undefined4 *)(*(int *)(*extraout_ECX + 4) + 0x1c + (int)extraout_ECX) = 1;
  piVar5 = FUN_0054d950(*(void **)(*(int *)(*extraout_ECX + 4) + 4 + (int)extraout_ECX),
                        *(LPCSTR *)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc) | 2,uVar3);
  if (piVar5 == (int *)0x0) {
    puVar1 = (uint *)(*(int *)(*extraout_ECX + 4) + 8 + (int)extraout_ECX);
    *puVar1 = *puVar1 | 2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

