// rea decompile_all
// name: RecipeRankingPanel_Update
// address: 0x49bd90
// body: available
// range: 0x49bd90-0x49c0d6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl RecipeRankingPanel_Update(void *param_1,char param_2)

{
  void *this;
  undefined4 *puVar1;
  int iVar2;
  undefined4 unaff_EDI;
  int iVar3;
  
                    /* Fills the company recipe ranking popup and rating rows. */
  FUN_00532310(param_1,&LAB_0049b4c0,0);
  this = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  puVar1 = (undefined4 *)FUN_004ddde0((int)this);
  FUN_0054dd83(&DAT_0057ca4c,DAT_00582e4c,unaff_EDI);
  DAT_0057ca90 = -1;
  FUN_0049c110(puVar1);
  iVar2 = *(int *)(DAT_0057c670 + 0x98);
  if ((iVar2 != 0) && (*(char *)(iVar2 + 0x1dc) == '\x01')) {
    DAT_0057ca90 = FUN_004ddeb0(this,iVar2);
  }
  UI_ShowChildByID(param_1,0x428);
  UI_ShowChildByID(param_1,0x50c);
  UI_ShowChildByID(param_1,0x50d);
  UI_ShowChildByID(param_1,0x504);
  UI_ShowChildByID(param_1,0x510);
  UI_ShowChildByID(param_1,0x50f);
  UI_ShowChildByID(param_1,0x454);
  iVar2 = 0x51b;
  iVar3 = 0;
  do {
    UI_ShowChildByID(param_1,*(int *)((int)&DAT_005689f4 + iVar3));
    UI_ShowChildByID(param_1,*(int *)((int)&DAT_00568a14 + iVar3));
    UI_ShowChildByID(param_1,iVar2);
    iVar3 = iVar3 + 4;
    iVar2 = iVar2 + -1;
  } while (0x513 < iVar2);
  iVar2 = 0;
  DAT_0057ca40 = (undefined4 *)0x0;
  UI_ShowChildByID(param_1,0x505);
  if (param_2 != '\0') {
    UI_Group_Create(param_1,0,2,0x50c);
  }
  if (puVar1 == (undefined4 *)0x0) {
    iVar3 = 0x51b;
    do {
      FUN_00531740(param_1,*(int *)((int)&DAT_005689f4 + iVar2));
      FUN_00531740(param_1,iVar3);
      FUN_00531740(param_1,*(int *)((int)&DAT_00568a14 + iVar2));
      iVar3 = iVar3 + -1;
      iVar2 = iVar2 + 4;
    } while (0x513 < iVar3);
    FUN_00531740(param_1,0x428);
    FUN_00531740(param_1,0x50c);
    FUN_00531740(param_1,0x50d);
    FUN_00531740(param_1,0x504);
    FUN_00531740(param_1,0x510);
    FUN_00531740(param_1,0x50f);
    FUN_00531740(param_1,0x454);
    iVar2 = 0;
    do {
      Rating_UpdateBarByKey(param_1,0x4f5,iVar2,0,0);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
  }
  else {
    if ((int)puVar1 < 9) {
      FUN_00531740(param_1,0x428);
      iVar3 = 0;
      if (0 < 8 - (int)puVar1) {
        do {
          FUN_00531740(param_1,*(int *)((int)&DAT_00568a10 + iVar2));
          FUN_00531740(param_1,*(int *)((int)&DAT_00568a30 + iVar2));
          FUN_00531740(param_1,iVar3 + 0x514);
          iVar3 = iVar3 + 1;
          iVar2 = iVar2 + -4;
        } while (iVar3 < 8 - (int)puVar1);
      }
    }
    else {
      if (DAT_0057ca90 != -1) {
        DAT_0057ca40 = (undefined4 *)FUN_0049c0e0(DAT_0057ca90,(int)puVar1);
      }
      if ((int)puVar1 < (int)(DAT_0057ca40 + 2)) {
        DAT_0057ca40 = puVar1 + -2;
      }
      FUN_0052fd00(param_1,0x428,0,((int)puVar1 * 5 + -0x28) * 0x14,0);
      FUN_0052fd70(param_1,0x428,(int)DAT_0057ca40 * 100,0);
      FUN_0052fce0(param_1,0x428,1);
    }
    if (DAT_005689f0 == '\0') {
      iVar2 = 0x50c;
    }
    else {
      iVar2 = 0x50d;
    }
    FUN_0052ff50(param_1,iVar2,1);
    FUN_0049c300(param_1,(int)DAT_0057ca40);
  }
  if (*(int *)(DAT_0057c670 + 0x98) == 0) {
    iVar2 = 0;
    do {
      Rating_UpdateBarByKey(param_1,0x4f5,iVar2,0,0);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    return;
  }
  iVar2 = 0;
  do {
    iVar3 = FUN_004e3f00(this,iVar2);
    Rating_UpdateBarByKey(param_1,0x4f5,iVar2,iVar3,DAT_0058271c);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  return;
}

