// rea decompile_all
// name: FUN_00522d40
// address: 0x522d40
// body: available
// range: 0x522d40-0x522dba inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00522d40(void *this,char *param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined3 extraout_var;
  uint uVar4;
  int iVar5;
  int extraout_ECX;
  char *pcVar6;
  int iVar7;
  
  _strncpy(*(char **)((int)this + 0x6c),param_1,*(size_t *)((int)this + 0x78));
  *(undefined1 *)(*(int *)((int)this + 0x6c) + *(int *)((int)this + 0x78)) = 0;
  iVar3 = Font_MeasureText(*(void **)((int)this + 0x54),*(char **)((int)this + 0x6c));
  uVar4 = 0xffffffff;
  pcVar6 = *(char **)((int)this + 0x6c);
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  iVar5 = ~uVar4 - 1;
  iVar7 = ~uVar4 - 2;
  for (; (-1 < iVar7 && (*(int *)((int)this + 0x84) <= iVar3));
      iVar3 = iVar3 - CONCAT31(extraout_var,uVar2)) {
    uVar2 = Font_GetCharWidth(*(void **)((int)this + 0x54),
                              CONCAT31((int3)((uint)iVar5 >> 8),
                                       *(undefined1 *)(*(int *)((int)this + 0x6c) + iVar7)));
    *(undefined1 *)(*(int *)((int)this + 0x6c) + iVar7) = 0;
    iVar7 = iVar7 + -1;
    iVar5 = extraout_ECX;
  }
  UI_ClipRect(*(void **)((int)this + 8),(int *)((int)this + 0x28),1);
  return;
}

