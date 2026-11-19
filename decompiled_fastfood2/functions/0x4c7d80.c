// rea decompile_all
// name: FUN_004c7d80
// address: 0x4c7d80
// body: available
// range: 0x4c7d80-0x4c7f28 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004c7d80(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 local_10 [4];
  undefined1 local_c;
  undefined3 uStack_b;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_00547770((undefined4 *)local_10);
  FUN_0052fd00(param_1,8000,0,10000,0);
  FUN_0052fd70(param_1,8000,CONCAT31(uStack_b,local_c),0);
  FUN_0052fce0(param_1,8000,1);
  FUN_0052fd00(param_1,0x1f41,0,10000,0);
  FUN_0052fd70(param_1,0x1f41,local_8,0);
  FUN_0052fce0(param_1,0x1f41,1);
  FUN_0052fd00(param_1,0x1f42,0,10000,0);
  FUN_0052fd70(param_1,0x1f42,local_4,0);
  FUN_0052fce0(param_1,0x1f42,1);
  FUN_0052ff50(param_1,0x1f44,stack0xfffffff1 & 0xff);
  if (_DAT_0057b9dc < 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = _DAT_0057b9dc;
    if (3 < _DAT_0057b9dc) {
      iVar2 = 3;
    }
  }
  FUN_0052fd00(param_1,0x1f45,0,3,0);
  FUN_0052fce0(param_1,0x1f45,1);
  FUN_0052fd70(param_1,0x1f45,iVar2,0);
  FUN_0052f9b0(param_1,0x1f46,(&DAT_00583878)[iVar2]);
  FUN_0052fd00(param_1,0x1f47,0,10,0);
  iVar2 = 0;
  piVar1 = &DAT_00568d88;
  do {
    if (DAT_0057b9f0 == *piVar1) break;
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x568db4);
  if (iVar2 == 0xb) {
    iVar2 = 2;
  }
  FUN_0052fd70(param_1,0x1f47,iVar2,0);
  FUN_0052fce0(param_1,0x1f47,1);
  FUN_0052f080(param_1,0x1f48,(byte *)s__d__s_00568324,(&DAT_00568d88)[iVar2]);
  return;
}

