// rea decompile_all
// name: FUN_00522dc0
// address: 0x522dc0
// body: available
// range: 0x522dc0-0x522e31 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00522dc0(void *this,int param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  undefined1 uVar3;
  undefined3 extraout_var;
  int iVar4;
  
  UI_SubtractOrigin(*(void **)((int)this + 8),&param_1,&param_2);
  pcVar2 = *(char **)((int)this + 0x6c);
  param_1 = param_1 - *(int *)((int)this + 0x38);
  iVar4 = 0;
  cVar1 = *pcVar2;
  while (cVar1 != '\0') {
    uVar3 = Font_GetCharWidth(*(void **)((int)this + 0x54),
                              CONCAT31((int3)((uint)pcVar2 >> 8),pcVar2[iVar4]));
    param_1 = param_1 - CONCAT31(extraout_var,uVar3);
    if (param_1 < 0) break;
    pcVar2 = *(char **)((int)this + 0x6c);
    iVar4 = iVar4 + 1;
    cVar1 = pcVar2[iVar4];
  }
  *(int *)((int)this + 0x80) = iVar4;
  *(undefined4 *)((int)this + 0x88) = 0xfffffc19;
  UI_ClipRect(*(void **)((int)this + 8),(int *)((int)this + 0x28),1);
  return;
}

