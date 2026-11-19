// rea decompile_all
// name: FUN_004b9c90
// address: 0x4b9c90
// body: available
// range: 0x4b9c90-0x4b9e99 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004b9c90(void *param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int local_44;
  char local_3c [28];
  undefined1 local_20 [32];
  
  iVar2 = FUN_00488be0(DAT_0057c670,*(int *)(*(int *)((int)DAT_0057c670 + 0x9c) + 0x30));
  local_44 = 0x401;
  iVar7 = 0;
  iVar5 = 0x3f3;
  do {
    iVar3 = FUN_00488be0(DAT_0057c670,iVar5 + -0x3f3);
    if (iVar3 == 0) {
LAB_004b9de2:
      uVar6 = DAT_00582e4c;
      *(undefined4 *)((int)&DAT_0057d6d0 + iVar7) = 0;
      FUN_0052f9b0(param_1,*(int *)((int)&DAT_0056a950 + iVar7),uVar6);
      FUN_0052f9b0(param_1,local_44,DAT_00582e4c);
      FUN_0052f9b0(param_1,local_44 + -1,DAT_00582e4c);
      FUN_00531740(param_1,iVar5 + -6);
      FUN_00531740(param_1,iVar5);
    }
    else {
      iVar4 = FUN_00482820((int)DAT_0057c670);
      if (iVar5 + -0x3f3 == iVar4) goto LAB_004b9de2;
      if (iVar5 + -0x3f3 == *(int *)(iVar2 + 0x48)) {
        *(undefined4 *)((int)&DAT_0057d6d0 + iVar7) = 1;
      }
      else {
        *(undefined4 *)((int)&DAT_0057d6d0 + iVar7) = 0;
      }
      FUN_0052f9b0(param_1,*(int *)((int)&DAT_0056a950 + iVar7),iVar3 + 8);
      FUN_0052f910(param_1,*(int *)((int)&DAT_0056a950 + iVar7),*(undefined4 *)(iVar3 + 0x1dc));
      FUN_0054dd83(local_20,&DAT_0056a968,*(undefined4 *)(iVar3 + 0x54));
      FUN_0052f9b0(param_1,local_44,local_20);
      FUN_0052f910(param_1,local_44,*(undefined4 *)(iVar3 + 0x1dc));
      FUN_0052f910(param_1,local_44 + -1,*(undefined4 *)(iVar3 + 0x1dc));
      FUN_005316b0(param_1,iVar5 + -6);
      FUN_005316b0(param_1,iVar5);
      FUN_0054dd83(local_3c,(byte *)s_LOGOS__0_d_spr_00568eb8,*(int *)(iVar3 + 0x1e0) + 1);
      FUN_00531910(param_1,iVar5,local_3c);
      FUN_0052ff50(param_1,iVar5 + -6,(uint)(*(int *)((int)&DAT_0057d6d0 + iVar7) == 1));
    }
    iVar7 = iVar7 + 4;
    local_44 = local_44 + 3;
    iVar3 = iVar5 + -0x3f2;
    iVar5 = iVar5 + 1;
    if (5 < iVar3) {
      iVar5 = FUN_00482820((int)DAT_0057c670);
      pvVar1 = DAT_0057c670;
      (&DAT_0057d6d0)[iVar5] = 1;
      uVar6 = FUN_0048e060(pvVar1);
      if ((char)uVar6 == '\0') {
        FUN_005316b0(param_1,0x3f9);
        return;
      }
      FUN_00531740(param_1,0x3f9);
      return;
    }
  } while( true );
}

