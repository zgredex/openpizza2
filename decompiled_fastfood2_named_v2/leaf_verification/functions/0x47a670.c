// rea decompile_all
// name: FUN_0047a670
// address: 0x47a670
// body: available
// range: 0x47a670-0x47a787 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __thiscall FUN_0047a670(int param_1,undefined4 param_2,int param_3)

{
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  
  fVar1 = (float10)0.0;
  switch(param_2) {
  case 0:
    fVar1 = FUN_00478090(param_1,1,-1,param_3);
    return fVar1;
  case 1:
    fVar1 = FUN_00478090(param_1,6,-1,param_3);
    fVar5 = FUN_00478090(param_1,7,-1,param_3);
    fVar2 = FUN_00478090(param_1,8,-1,param_3);
    fVar3 = FUN_00478090(param_1,10,-1,param_3);
    fVar4 = FUN_00478090(param_1,0xd,-1,param_3);
    return fVar4 + (float10)(float)(fVar3 + (float10)(float)(fVar2 + (float10)(float)(fVar5 + (
                                                  float10)(float)fVar1)));
  case 2:
    fVar1 = FUN_00478090(param_1,0xc,-1,param_3);
    return fVar1;
  case 3:
    fVar1 = FUN_00478090(param_1,0x10,-1,param_3);
    fVar5 = FUN_00478090(param_1,0x11,-1,param_3);
    return fVar5 + (float10)(float)fVar1;
  case 4:
  case 5:
    break;
  case 6:
    fVar1 = FUN_00478090(param_1,0x13,-1,param_3);
    return fVar1;
  default:
    NoOp_Stub();
    fVar1 = (float10)(float)fVar1;
  }
  return fVar1;
}

