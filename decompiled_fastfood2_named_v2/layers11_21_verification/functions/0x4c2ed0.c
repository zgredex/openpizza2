// rea decompile_all
// name: FUN_004c2ed0
// address: 0x4c2ed0
// body: available
// range: 0x4c2ed0-0x4c2ffb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c2ed0(void *param_1)

{
  void *this;
  void *this_00;
  void *this_01;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  this = *(void **)(DAT_0057c670 + 0x9c);
  this_00 = *(void **)((int)this + 0x14e0);
  this_01 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 0x74),*(int *)((int)param_1 + 4),(int *)0x0
                                );
  if (((*(int *)((int)this_01 + 8) == 1) || (*(int *)((int)this_01 + 8) == 2)) &&
     (iVar1 = FUN_00489ea0(this,(int)param_1), iVar1 != 0)) {
    return;
  }
  *(undefined4 *)(DAT_0057c670 + 0x344) = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)(DAT_0057c670 + 0x354) = *(undefined4 *)((int)param_1 + 8);
  FUN_0047c5b0(this,(int)param_1);
  FUN_004e6340(param_1,this_00);
  iVar1 = *(int *)((int)this_00 + 0x4c) + *(int *)((int)param_1 + 0x20) * 0xc;
  FUN_004f5db0(iVar1);
  *(undefined4 *)((int)this_00 + 0x60) = 1;
  *(undefined4 *)((int)this_00 + 0x68) = *(undefined4 *)(*(int *)(iVar1 + 8) + 0x10);
  iVar2 = FUN_004e42c0(this_01,*(int *)(*(int *)(iVar1 + 8) + 0x10),*(int *)((int)param_1 + 8));
  *(int *)(DAT_0057c670 + 0x350) = iVar2;
  FUN_004ed330(this_00,iVar1,-1,1);
  *(undefined4 *)(DAT_0057c670 + 0x348) = *(undefined4 *)((int)param_1 + 0x18);
  *(undefined4 *)(DAT_0057c670 + 0x34c) = *(undefined4 *)((int)param_1 + 0x1c);
  *(undefined4 *)(DAT_0057c670 + 0x35c) = 1;
  puVar3 = FUN_004f2b60(this_00,(int)param_1);
  FUN_004f2fc0(this_00,0,puVar3);
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  FUN_004f2e50(this_00,(int)this);
  *(undefined4 *)((int)this_00 + 0xf4) = 1;
  return;
}

