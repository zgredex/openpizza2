// rea decompile_all
// name: FUN_0055438f
// address: 0x55438f
// body: available
// range: 0x55438f-0x5544b1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_0055438f(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int local_8;
  int local_4;
  
  uVar4 = 0xffffffff;
  FUN_0055395d(0x12);
  local_8 = 0;
  local_4 = 0;
  piVar3 = &DAT_00586c20;
  while (puVar2 = (undefined4 *)*piVar3, puVar1 = puVar2, puVar2 != (undefined4 *)0x0) {
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      if ((*(byte *)(puVar2 + 1) & 1) == 0) {
        if (puVar2[2] == 0) {
          FUN_0055395d(0x11);
          if (puVar2[2] == 0) {
            InitializeCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
            puVar2[2] = puVar2[2] + 1;
          }
          FUN_005539be(0x11);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
        if ((*(byte *)(puVar2 + 1) & 1) == 0) {
          *puVar2 = 0xffffffff;
          uVar4 = ((int)puVar2 - *piVar3) / 0x24 + local_4;
          if (uVar4 != 0xffffffff) goto LAB_005544a1;
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
      }
      puVar1 = (undefined4 *)*piVar3;
    }
    local_4 = local_4 + 0x20;
    piVar3 = piVar3 + 1;
    local_8 = local_8 + 1;
    if (0x586d1f < (int)piVar3) goto LAB_005544a1;
  }
  puVar2 = _malloc(0x480);
  if (puVar2 != (undefined4 *)0x0) {
    DAT_00586d20 = DAT_00586d20 + 0x20;
    (&DAT_00586c20)[local_8] = puVar2;
    puVar1 = puVar2;
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      puVar2[2] = 0;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar1 = (undefined4 *)(&DAT_00586c20)[local_8];
    }
    uVar4 = local_8 << 5;
    FUN_005545ef(uVar4);
  }
LAB_005544a1:
  FUN_005539be(0x12);
  return uVar4;
}

