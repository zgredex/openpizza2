// rea decompile_all
// name: CRT_InternalCxxFrameHandler
// address: 0x552c74
// body: available
// range: 0x552c74-0x552d0e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl
CRT_InternalCxxFrameHandler
          (PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int *param_5,
          int param_6,PVOID param_7,char param_8)

{
  code *pcVar1;
  undefined4 uVar2;
  
                    /* Shared C++ exception dispatcher for search and unwind passes. */
  if (*param_5 != 0x19930520) {
    CRT_Inconsistency();
  }
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    if (param_5[3] != 0) {
      if (((param_1->ExceptionCode == 0xe06d7363) && (0x19930520 < param_1->ExceptionInformation[0])
          ) && (pcVar1 = *(code **)(param_1->ExceptionInformation[2] + 8), pcVar1 != (code *)0x0)) {
        uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar2;
      }
      CRT_CxxCatchSearch(param_1,param_2,param_3,param_4,(uint)param_5,param_8,param_6,param_7);
    }
  }
  else if ((param_5[1] != 0) && (param_6 == 0)) {
    CRT_FrameUnwindToState((int)param_2,param_4,(int)param_5,-1);
  }
  return 1;
}

