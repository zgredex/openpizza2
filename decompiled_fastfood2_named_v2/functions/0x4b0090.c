// rea decompile_all
// name: FUN_004b0090
// address: 0x4b0090
// body: available
// range: 0x4b0090-0x4b02c0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004b0090(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  undefined4 unaff_EDI;
  int iVar3;
  char local_40 [64];
  
  this = param_1;
  FUN_0048d530(DAT_0057c670,&DAT_0057d66c);
  FUN_00532310(param_1,&LAB_004b0000,0);
  if (DAT_0057d684 != 0) {
    FUN_005271d0(DAT_0057c5e0,DAT_0057d684);
  }
  DAT_0057d684 = FUN_00527090(DAT_0057c5e0,s_VERDANA10_fnt_00563e64);
  iVar3 = 0x401;
  param_1 = (void *)0x0;
  iVar2 = 0x3fa;
  do {
    iVar1 = FUN_00488be0(DAT_0057c670,iVar2 + -0x3fa);
    if (iVar1 == 0) {
      FUN_00531740(this,iVar2);
      FUN_00531740(this,iVar3);
      FUN_00531740(this,iVar3 + 1);
      FUN_00531740(this,iVar3 + 2);
      FUN_00531740(this,*(int *)((int)param_1 + 0x56a654));
      (&DAT_0056a24a)[iVar2] = 0;
    }
    else {
      FUN_005316b0(this,iVar2);
      FUN_005316b0(this,iVar3);
      FUN_005316b0(this,iVar3 + 1);
      FUN_005316b0(this,iVar3 + 2);
      FUN_005316b0(this,*(int *)((int)param_1 + 0x56a654));
      String_Format(local_40,(byte *)s_LOGOS__0_d_spr_00568eb8,*(int *)(iVar1 + 0x1e0) + 1);
      FUN_00531910(this,*(int *)((int)param_1 + 0x56a654),local_40);
      FUN_0052f9b0(this,iVar3,iVar1 + 8);
      FUN_0052ff50(this,iVar2,(uint)(byte)(&DAT_0056a24a)[iVar2]);
      String_Format(local_40,&DAT_005686f4,
                    *(undefined4 *)(*(int *)((int)param_1 + 0x57d66c) + 0x11c));
      FUN_0052f9b0(this,iVar3 + 2,local_40);
      FUN_0052f910(this,iVar3,*(undefined4 *)(iVar1 + 0x1dc));
      FUN_0052f910(this,iVar3 + 1,*(undefined4 *)(iVar1 + 0x1dc));
      FUN_0052f910(this,iVar3 + 2,*(undefined4 *)(iVar1 + 0x1dc));
    }
    iVar3 = iVar3 + 3;
    param_1 = (void *)((int)param_1 + 4);
    iVar1 = iVar2 + -0x3f9;
    iVar2 = iVar2 + 1;
  } while (iVar1 < 6);
  FUN_0052f800(this,0x1f41,1);
  String_Format(local_40,DAT_00582e4c,unaff_EDI);
  FUN_0052f9b0(this,0x414,local_40);
  FUN_0052f9b0(this,0x415,local_40);
  FUN_004b0300(this);
  FUN_004b02d0(this);
  return;
}

