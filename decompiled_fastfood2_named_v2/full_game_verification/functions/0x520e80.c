// rea decompile_all
// name: Dialog_WriteChildRecord
// address: 0x520e80
// body: available
// range: 0x520e80-0x520f2d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Dialog_WriteChildRecord(int *param_1)

{
  int iVar1;
  uint unaff_ESI;
  int *piVar2;
  int *unaff_retaddr;
  char local_458 [4];
  int local_454 [4];
  int local_444;
  int local_440;
  int local_43c;
  undefined4 local_434;
  undefined4 local_32c;
  int local_14;
  
  piVar2 = local_454;
  for (iVar1 = 0x115; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  local_444 = param_1[0xf];
  local_458[0] = 'T';
  local_458[1] = '\x04';
  local_458[2] = '\0';
  local_458[3] = '\0';
  local_454[0] = 0x454;
  local_454[3] = param_1[0xe];
  local_440 = param_1[0xc] - param_1[10];
  local_43c = param_1[0xd] - param_1[0xb];
  local_434 = 0xd;
  local_32c = 0xd;
  local_14 = param_1[1];
  local_454[1] = 0;
  (**(code **)(*param_1 + 8))(local_454);
  CRT_FwriteLocked(local_458 + -4,1,4,unaff_retaddr);
  CRT_FwriteLocked(local_458,1,unaff_ESI,unaff_retaddr);
  return;
}

