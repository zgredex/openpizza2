// rea decompile_all
// name: FUN_004d2e80
// address: 0x4d2e80
// body: available
// range: 0x4d2e80-0x4d2eb4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall FUN_004d2e80(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  switch(*(undefined4 *)(param_1 + 0x20)) {
  case 0x81c:
  case 0x81d:
  case 0x81e:
  case 0x81f:
  case 0x834:
  case 0x835:
  case 0x836:
  case 0x837:
  case 0x840:
  case 0x841:
  case 0x842:
  case 0x843:
  case 0x84c:
  case 0x84d:
  case 0x84e:
  case 0x84f:
  case 0x858:
  case 0x859:
  case 0x85a:
  case 0x85b:
    return 0;
  case 0x820:
  case 0x821:
  case 0x822:
  case 0x823:
  case 0x838:
  case 0x839:
  case 0x83a:
  case 0x83b:
  case 0x844:
  case 0x845:
  case 0x846:
  case 0x847:
  case 0x850:
  case 0x851:
  case 0x852:
  case 0x853:
  case 0x85c:
  case 0x85d:
  case 0x85e:
  case 0x85f:
    return 1;
  case 0x824:
  case 0x825:
  case 0x826:
  case 0x827:
  case 0x83c:
  case 0x83d:
  case 0x83e:
  case 0x83f:
  case 0x848:
  case 0x849:
  case 0x84a:
  case 0x84b:
  case 0x854:
  case 0x855:
  case 0x856:
  case 0x857:
  case 0x860:
  case 0x861:
  case 0x862:
  case 0x863:
    return 2;
  case 0x828:
  case 0x829:
  case 0x82a:
  case 0x82b:
  case 0x82c:
  case 0x82d:
  case 0x82e:
  case 0x82f:
  case 0x830:
  case 0x831:
  case 0x832:
  case 0x833:
    uVar1 = 3;
  }
  return uVar1;
}

