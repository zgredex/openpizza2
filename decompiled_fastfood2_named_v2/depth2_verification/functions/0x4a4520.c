// rea decompile_all
// name: FUN_004a4520
// address: 0x4a4520
// body: available
// range: 0x4a4520-0x4a46b0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a4520(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  
  this = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar4 = *(int *)((int)this + 0x48);
  iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  iVar1 = *(int *)((int)this + 100);
  iVar4 = *(int *)(iVar2 + 0xc20 + iVar4 * 4);
  FUN_0052f080(param_1,0x1f82,&DAT_005686f4,iVar1);
  puVar3 = FUN_004e25b0(this,0x17,0);
  FUN_0052f080(param_1,0x1f68,&DAT_005686f4,puVar3);
  puVar3 = FUN_004e25b0(this,0x17,1);
  FUN_0052f080(param_1,0x1f67,&DAT_005686f4,puVar3);
  puVar3 = FUN_004e25b0(this,0x17,2);
  FUN_0052f080(param_1,0x1f54,&DAT_005686f4,puVar3);
  if (iVar4 < 3) {
LAB_004a4611:
    UI_RemoveObjectByKey(param_1,0x1f7b);
    UI_RemoveObjectByKey(param_1,0x1f7c);
    UI_RemoveObjectByKey(param_1,0x1fdf);
    UI_RemoveObjectByKey(param_1,0x1f4d);
  }
  else {
    if (iVar1 == 2) {
      if (iVar4 < 4) goto LAB_004a4611;
    }
    else if (iVar1 == 3) goto LAB_004a4611;
    FUN_005316b0(param_1,0x1f7b);
    FUN_005316b0(param_1,0x1f7c);
    FUN_005316b0(param_1,0x1fdf);
    FUN_005316b0(param_1,0x1f4d);
  }
  FUN_0052f080(param_1,0x1fdf,(byte *)s__s__d_00568964,DAT_00581044);
  iVar4 = FUN_004e3610((int)this);
  if (*(int *)(*(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8) + 0x180) != 0) {
    iVar4 = (iVar4 * 0xf) / 10;
  }
  FUN_0052f080(param_1,0x1f7c,&DAT_005683a4,iVar4);
  return;
}

