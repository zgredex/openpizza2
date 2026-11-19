// rea decompile_all
// name: FUN_004080e0
// address: 0x4080e0
// body: available
// range: 0x4080e0-0x4082b9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004080e0(void *this,void *param_1,void *param_2)

{
  int iVar1;
  undefined1 uVar2;
  undefined3 extraout_var;
  void *this_00;
  undefined4 uVar3;
  int iVar4;
  
  uVar2 = FUN_00505e00((int)param_2);
  iVar1 = *(int *)((int)param_2 + 0x38);
  if (iVar1 != 0x1f) {
    if (CONCAT31(extraout_var,uVar2) == 0) {
      if (iVar1 == 0x18) {
        switch(*(undefined4 *)((int)param_2 + 0x30)) {
        case 0x2b:
          FUN_00509060(param_2,0);
          FUN_00548210(DAT_0057ba0c,(int)param_1,0x2b);
          FUN_0050e890(param_2,0x31);
          return;
        case 0x2c:
          FUN_00509060(param_2,1);
          FUN_00548210(DAT_0057ba0c,(int)param_1,0x2b);
          FUN_0050e890(param_2,0x31);
          return;
        case 0x2d:
          FUN_00509060(param_2,0);
          FUN_00548210(DAT_0057ba0c,(int)param_1,0x2d);
          FUN_0050e890(param_2,0x31);
          uVar3 = Game_GetDateField0C((int)this);
          *(undefined4 *)((int)param_2 + 0x98) = uVar3;
          return;
        case 0x2f:
          FUN_00509060(param_2,0);
          FUN_00548210(DAT_0057ba0c,(int)param_1,0x1c);
          FUN_0050e890(param_2,0x31);
          uVar3 = Game_GetDateField0C((int)this);
          *(undefined4 *)((int)param_2 + 0x98) = uVar3;
          FUN_0047f420(param_1,7);
          return;
        }
      }
      else if (((iVar1 == 0x31) && (iVar1 = *(int *)((int)param_2 + 0x30), 0x2a < iVar1)) &&
              (iVar1 < 0x2d)) {
        this_00 = (void *)IDMap_Lookup((void *)((int)this + 0x3c),*(int *)((int)param_2 + 0x10c),
                                       (int *)0x0);
        if (this_00 != (void *)0x0) {
          FUN_00480fb0((int)param_1);
          FUN_005090e0((int)this_00);
          FUN_0050e890(this_00,6);
          FUN_0050e850(this_00,0xffffffff);
        }
        FUN_0050e890(param_2,0x32);
        FUN_00509060(param_2,(iVar1 != 0x2b) + 2);
        return;
      }
    }
    else if ((iVar1 == 0x31) && (*(int *)((int)param_2 + 0x30) == 0x2d)) {
      iVar1 = *(int *)((int)param_2 + 0x98);
      iVar4 = Game_GetDateField0C((int)this);
      if (5 < iVar4 - iVar1) {
        FUN_005090e0((int)param_2);
        Object_SetFrame5(param_2,-1);
        FUN_005086e0((int)param_2);
        FUN_0050e890(param_2,0x1f);
        return;
      }
      FUN_0050b460(param_2,(int)param_1);
    }
  }
  return;
}

