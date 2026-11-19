// rea decompile_all
// name: CRT_CxxCatchAllSearch
// address: 0x552ec2
// body: available
// range: 0x552ec2-0x552f6b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl
CRT_CxxCatchAllSearch
          (PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,uint param_5,
          int param_6,int param_7,PVOID param_8)

{
  DWORD *pDVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint local_c;
  uint local_8;
  
                    /* Offers the exception to the SEH translator and catch-all clauses. */
  pDVar1 = CRT_GetThreadData();
  if ((pDVar1[0x1a] != 0) &&
     (iVar2 = CRT_InvokeSeTranslator
                        (&param_1->ExceptionCode,param_2,param_3,param_4,param_5,param_7,param_8),
     iVar2 != 0)) {
    return;
  }
  piVar3 = (int *)CRT_FindTryBlockRange(param_5,param_7,param_6,&local_8,&local_c);
  for (; local_8 < local_c; local_8 = local_8 + 1) {
    if ((*piVar3 <= param_6) && (param_6 <= piVar3[1])) {
      iVar4 = piVar3[3] * 0x10 + piVar3[4];
      iVar2 = *(int *)(iVar4 + -0xc);
      if ((iVar2 == 0) || (*(char *)(iVar2 + 8) == '\0')) {
        CRT_CatchIt(param_1,param_2,param_3,param_4,param_5,(byte *)(iVar4 + -0x10),(byte *)0x0,
                    piVar3,param_7,param_8);
      }
    }
    piVar3 = piVar3 + 5;
  }
  return;
}

