// rea decompile_all
// name: FUN_004a3d40
// address: 0x4a3d40
// body: available
// range: 0x4a3d40-0x4a3f6c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a3d40(void *param_1)

{
  void *this;
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  float10 fVar7;
  
  pvVar1 = param_1;
  iVar3 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  FUN_0052f080(param_1,0x23e2,&DAT_005686f4,*(undefined4 *)(iVar3 + 0x70));
  FUN_0052f080(param_1,0x23e3,&DAT_005686f4,*(int *)(iVar3 + 0x88) + *(int *)(iVar3 + 0x74));
  FUN_0052f080(param_1,0x23ea,&DAT_005686f4,*(undefined4 *)(iVar3 + 0x78));
  FUN_0052f080(param_1,0x23eb,&DAT_005686f4,*(undefined4 *)(iVar3 + 0x7c));
  FUN_0052f080(param_1,0x23ee,&DAT_005686f4,*(undefined4 *)(iVar3 + 0x80));
  FUN_0052f080(param_1,0x23ef,&DAT_005686f4,*(undefined4 *)(iVar3 + 0x84));
  FUN_0052f080(param_1,0x2379,&DAT_005686f4,*(undefined4 *)(iVar3 + 0x15c));
  FUN_0052f080(param_1,0x23f6,&DAT_005686f4,*(undefined4 *)(iVar3 + 0x194));
  fVar7 = FUN_004e09e0(iVar3,-1,-1,-1);
  FUN_0052f080(param_1,0x237a,(byte *)s__0_2f___005688b0,SUB84((double)fVar7,0));
  iVar4 = *(int *)(iVar3 + 0x48);
  iVar5 = 0;
  iVar2 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  FUN_0052f080(param_1,0x2374,&DAT_005686f4,*(undefined4 *)(iVar2 + 0xc20 + iVar4 * 4));
  this = *(void **)(iVar3 + 0x1d8);
  if (this == (void *)0x0) {
    FUN_0052f080(param_1,0x2380,&DAT_005686f4,0);
    FUN_0052f080(param_1,0x2382,&DAT_005686f4,0);
    FUN_0052f080(param_1,0x2383,&DAT_005686f4,0);
  }
  else {
    iVar3 = FUN_004d2ae0(this,0x17);
    FUN_0052f080(param_1,0x2380,&DAT_005686f4,iVar3);
    iVar3 = FUN_004d2ae0(this,0x1e);
    FUN_0052f080(param_1,0x2382,&DAT_005686f4,iVar3);
    iVar3 = FUN_004d2ae0(this,0x1d);
    FUN_0052f080(param_1,0x2383,&DAT_005686f4,iVar3);
  }
  param_1 = (void *)0x0;
  piVar6 = &DAT_0057d24c;
  do {
    iVar3 = FUN_00488be0(DAT_0057c670,iVar5);
    if (iVar3 == 0) {
      *piVar6 = 0;
    }
    else {
      iVar4 = FUN_00482820((int)DAT_0057c670);
      iVar3 = *(int *)(iVar3 + 0x94 + iVar4 * 4);
      *piVar6 = iVar3;
      if (0 < iVar3) {
        param_1 = (void *)((int)param_1 + 1);
      }
    }
    piVar6 = piVar6 + 1;
    iVar5 = iVar5 + 1;
  } while ((int)piVar6 < 0x57d264);
  FUN_004a3bc0(pvVar1,DAT_0057d248,(int)param_1);
  return;
}

