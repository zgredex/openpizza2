// rea decompile_all
// name: FUN_0048b1b0
// address: 0x48b1b0
// body: available
// range: 0x48b1b0-0x48b3b5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0048b1b0(void *param_1,int param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  char *pcVar8;
  int local_258;
  undefined4 local_254;
  undefined4 local_250 [2];
  float local_248;
  int local_244;
  char local_240 [64];
  char local_200 [512];
  
  FUN_005314a0(param_1,param_2,local_250,&local_254);
  FUN_00531570(param_1,param_2,&local_258,&local_244);
  iVar6 = 0x31ce0;
  local_258 = local_258 >> 1;
  local_248 = (float)local_244 * 0.25;
  iVar4 = 0;
  do {
    FUN_0048d110(iVar4);
    String_Format(local_200,(byte *)s__d__s_00568324,*(undefined4 *)(param_3 + iVar4 * 4));
    iVar5 = *(int *)(param_3 + iVar4 * 4);
    if ((iVar5 != 0) &&
       (String_Format(local_240,(byte *)s__s_spr_005680ec,(&PTR_s_M_KIDS_00567ef4)[iVar4]),
       0 < iVar5)) {
      do {
        iVar1 = FUN_0052ff20(param_1,iVar6);
        if (iVar1 == 0) {
          pcVar8 = local_240;
          lVar7 = __ftol();
          iVar1 = (int)lVar7;
          lVar7 = __ftol();
          UI_AddSprite(param_1,iVar6,(int)lVar7,iVar1,pcVar8);
        }
        else {
          lVar7 = __ftol();
          iVar1 = (int)lVar7;
          lVar7 = __ftol();
          FUN_00531400(param_1,iVar6,(int)lVar7,iVar1);
          pbVar2 = (byte *)FUN_005319a0(param_1,iVar6);
          uVar3 = FUN_005570c0(local_240,pbVar2,(byte *)local_240);
          if (uVar3 != 0) {
            FUN_00531910(param_1,iVar6,local_240);
          }
        }
        FUN_00531f50(param_1,iVar6,local_200);
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  while (iVar4 = FUN_0052ff20(param_1,iVar6), iVar4 != 0) {
    FUN_005311a0(param_1,iVar6);
    iVar6 = iVar6 + 1;
  }
  return 1;
}

