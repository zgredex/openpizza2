// rea decompile_all
// name: Game_ComputeCityScore
// address: 0x479620
// body: available
// range: 0x479620-0x479749 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Game_ComputeCityScore(void *this,int param_1,int param_2)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  int local_1c;
  int local_10;
  int local_c [3];
  
  iVar6 = param_1 / 3;
  iVar3 = 0;
  iVar5 = 0;
  local_1c = -1;
  iVar7 = 0;
  psVar2 = (short *)(param_2 + 4);
  param_2 = 0x50;
  do {
    piVar4 = local_c + iVar7;
    param_1 = 0x50;
    do {
      sVar1 = *psVar2;
      if ((sVar1 < -3) || ((-1 < sVar1 && (sVar1 != 9)))) {
        if (sVar1 != 0) {
          iVar3 = iVar3 + 1;
        }
        iVar5 = iVar5 + 1;
        if (iVar6 <= iVar5) {
          *piVar4 = iVar3;
          if (local_1c < iVar3) {
            local_1c = iVar3;
            local_10 = iVar7;
          }
          iVar7 = iVar7 + 1;
          piVar4 = piVar4 + 1;
          iVar3 = 0;
          iVar5 = 0;
        }
      }
      psVar2 = psVar2 + 4;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  piVar4 = (int *)((int)this + 0x185c);
  *piVar4 = 100;
  if (local_1c < 1) {
    *piVar4 = 0;
    Clamp_0_100(piVar4);
    return;
  }
  iVar6 = 0;
  do {
    if (iVar6 != local_10) {
      lVar8 = __ftol();
      iVar3 = (int)((ulonglong)((longlong)(100 - (int)lVar8) * -0x66666667) >> 0x20);
      *piVar4 = *piVar4 + ((iVar3 >> 1) - (iVar3 >> 0x1f));
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 3);
  Clamp_0_100(piVar4);
  return;
}

