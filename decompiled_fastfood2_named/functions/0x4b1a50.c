// rea decompile_all
// name: FUN_004b1a50
// address: 0x4b1a50
// body: available
// range: 0x4b1a50-0x4b1e7a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004b1a50(void *param_1,int param_2,int param_3,char param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined1 local_20 [32];
  
  iVar1 = IDMap_Lookup((void *)(param_2 + 0x148),param_3,(int *)0x0);
  piVar2 = (int *)IDMap_Lookup((void *)(iVar1 + 0x1500),param_5,(int *)0x0);
  if (param_4 == '\0') {
    iVar3 = FUN_004d3930(*piVar2);
    FUN_0052f9b0(param_1,0x52b,iVar3);
    String_Format(local_20,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x38));
    FUN_0052f9b0(param_1,0x52e,local_20);
    FUN_0052f9b0(param_1,0x52d,*(undefined4 *)(&DAT_005832a8 + (uint)*(byte *)(*piVar2 + 0x824) * 4)
                );
    iVar3 = FUN_004d4000(*piVar2);
    String_Format(local_20,&DAT_005686f4,iVar3);
    FUN_0052f9b0(param_1,0x52a,local_20);
    String_Format(local_20,&DAT_005686f4,*(undefined4 *)(*piVar2 + 0x3c));
    FUN_0052f9b0(param_1,0x529,local_20);
  }
  FUN_0052f9b0(param_1,0x472,*(undefined4 *)(&DAT_005832d4 + (uint)*(byte *)(*piVar2 + 0x824) * 4));
  if (param_4 != '\0') {
    FUN_0052f9b0(param_1,0x578,*(undefined4 *)(&DAT_005832d4 + (uint)*(byte *)(*piVar2 + 0x824) * 4)
                );
  }
  if (*(char *)(*piVar2 + 0x824) == '\x03') {
    FUN_00531740(param_1,0x480);
    FUN_0052ff50(param_1,5000,(uint)(*(char *)(*piVar2 + 0x825) == '\x01'));
    FUN_005316b0(param_1,5000);
    FUN_005316b0(param_1,0x1389);
  }
  else {
    FUN_005316b0(param_1,0x480);
    FUN_00531740(param_1,5000);
    FUN_00531740(param_1,0x1389);
  }
  uVar6 = -(uint)(param_4 != '\x01') & 0x1ed6;
  FUN_0052fd00(param_1,uVar6 + 0x453,0,100,0);
  FUN_0052fd00(param_1,uVar6 + 0x455,0,100,0);
  FUN_0052fd00(param_1,uVar6 + 0x457,0,100,0);
  FUN_0052fd00(param_1,uVar6 + 0x459,0,100,0);
  FUN_0052fd00(param_1,uVar6 + 0x452,0,100,0);
  FUN_0052fd00(param_1,uVar6 + 0x454,0,100,0);
  FUN_0052fd00(param_1,uVar6 + 0x456,0,100,0);
  FUN_0052fd00(param_1,uVar6 + 0x458,0,100,0);
  uVar7 = 0;
  iVar3 = *piVar2;
  iVar4 = FUN_004d3f90(iVar3);
  FUN_0052fd70(param_1,uVar6 + 0x453,iVar4,uVar7);
  uVar7 = 0;
  iVar4 = FUN_004d3fc0(iVar3);
  FUN_0052fd70(param_1,uVar6 + 0x455,iVar4,uVar7);
  FUN_0052fd70(param_1,uVar6 + 0x457,*(undefined4 *)(iVar3 + 0xc),0);
  uVar7 = 0;
  iVar4 = FUN_004d3fe0(iVar3);
  FUN_0052fd70(param_1,uVar6 + 0x459,iVar4,uVar7);
  iVar4 = *(int *)(iVar3 + 0x14);
  uVar7 = 0;
  iVar5 = FUN_004d3f90(iVar3);
  FUN_0052fd70(param_1,uVar6 + 0x452,iVar5 + iVar4,uVar7);
  iVar4 = *(int *)(iVar3 + 0x18);
  uVar7 = 0;
  iVar5 = FUN_004d3fc0(iVar3);
  FUN_0052fd70(param_1,uVar6 + 0x454,iVar5 + iVar4,uVar7);
  FUN_0052fd70(param_1,uVar6 + 0x456,*(int *)(iVar3 + 0x1c) + *(int *)(iVar3 + 0xc),0);
  iVar4 = *(int *)(iVar3 + 0x20);
  uVar7 = 0;
  iVar5 = FUN_004d3fe0(iVar3);
  FUN_0052fd70(param_1,uVar6 + 0x458,iVar5 + iVar4,uVar7);
  if (param_4 == '\0') {
    FUN_0054bb00(param_1,0x2332,iVar3);
    iVar3 = 0x2332;
  }
  else {
    FUN_0054bb00(param_1,0x1f53,iVar3);
    iVar3 = 0x1f53;
  }
  FUN_00531470(param_1,iVar3,1);
  uVar6 = FUN_004d42f0(*piVar2);
  if ((char)uVar6 == '\0') {
    FUN_00531740(param_1,0x480);
    FUN_00531740(param_1,0x483);
    FUN_00531740(param_1,0x485);
  }
  else {
    if (*(char *)(*piVar2 + 0x824) != '\x03') {
      FUN_005316b0(param_1,0x480);
    }
    FUN_005316b0(param_1,0x483);
    FUN_005316b0(param_1,0x485);
  }
  iVar3 = *(int *)(param_2 + 0x48);
  iVar1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(iVar1 + 0x34),(int *)0x0);
  if (*(int *)(iVar1 + 0xc20 + iVar3 * 4) < 2) {
    FUN_00531740(param_1,0x480);
    FUN_00531740(param_1,0x483);
    FUN_00531740(param_1,0x484);
    FUN_00531740(param_1,0x485);
  }
  return;
}

