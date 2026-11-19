// rea decompile_all
// name: FUN_00525a10
// address: 0x525a10
// body: available
// range: 0x525a10-0x525aec inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


longlong __thiscall FUN_00525a10(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  DWORD DVar5;
  uint extraout_EDX;
  longlong lVar6;
  LARGE_INTEGER local_10;
  LARGE_INTEGER local_8;
  
  DVar5 = GetCurrentThreadId();
  *(DWORD *)((int)this + 0x830c) = DVar5;
  FUN_00527b10(this);
  if (param_1 != 0) {
    QueryPerformanceCounter(&local_8);
  }
  iVar1 = *(int *)((int)this + 0x32b4);
  if (iVar1 != *(int *)((int)this + 0x32b8)) {
    uVar2 = *(uint *)((int)this + iVar1 * 0xc + 0x2b4);
    pvVar3 = *(void **)((int)this + (iVar1 * 3 + 0xae) * 4);
    uVar4 = *(uint *)((int)this + iVar1 * 0xc + 700);
    *(uint *)((int)this + 0x32b4) = iVar1 + 1U & 0x3ff;
    FUN_00525fd0(this,uVar2,pvVar3,uVar4);
    if (*(int *)((int)this + 0x1b8) != 0) {
      FUN_00526100(this);
      *(undefined4 *)((int)this + 0x1b8) = 0;
    }
  }
  FUN_00525af0((int)this);
  FUN_00526100(this);
  if (param_1 == 0) {
    return (ulonglong)extraout_EDX << 0x20;
  }
  QueryPerformanceCounter(&local_10);
  FUN_00527dc0((int)this,local_8.s.LowPart,local_8.s.HighPart,local_10.s.LowPart,local_10.s.HighPart
              );
  lVar6 = __ftol();
  return lVar6;
}

