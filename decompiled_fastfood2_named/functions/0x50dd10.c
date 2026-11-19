// rea decompile_all
// name: FUN_0050dd10
// address: 0x50dd10
// body: available
// range: 0x50dd10-0x50df2d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0050dd10(void *param_1)

{
  bool bVar1;
  void *pvVar2;
  int iVar3;
  undefined3 extraout_var;
  uint uVar4;
  int iVar5;
  void *this;
  
  iVar3 = *(int *)((int)param_1 + 0x108);
  if (iVar3 == 4) {
    *(undefined4 *)((int)param_1 + 0x108) = 0xffffffff;
    return;
  }
  if (iVar3 == 5) {
    *(undefined4 *)((int)param_1 + 0x108) = 0xffffffff;
    return;
  }
  if (iVar3 != 3) {
    iVar3 = FUN_0050dbf0((int)param_1);
    if (iVar3 != 0) {
      *(undefined4 *)((int)param_1 + 0x108) = 3;
      FUN_0050d440((int)param_1);
      return;
    }
    FUN_0050e850(param_1,0xffffffff);
    if (*(int *)((int)param_1 + 0x38) == 0x3a) {
      iVar3 = *(int *)((int)param_1 + 0x110);
      iVar5 = FUN_00482820((int)DAT_0057c670);
      if (iVar3 == iVar5) {
        FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0xb,-1,-1);
      }
      pvVar2 = *(void **)((int)param_1 + 0xfc);
      iVar3 = 0;
      if (0 < *(int *)((int)pvVar2 + 0x8c)) {
        do {
          pvVar2 = (void *)FUN_004d2a60(pvVar2,iVar3);
          if (*(int *)((int)pvVar2 + 0x30) == 0x1f) {
            FUN_0050e890(pvVar2,0x2e);
            *(undefined4 *)((int)DAT_0057c670 + 0x368) = 1;
            this = (void *)FUN_00488be0(DAT_0057c670,*(int *)((int)pvVar2 + 0x110));
            FUN_004e21d0(this,*(int *)((int)pvVar2 + 0x164));
            FUN_004d2960(*(void **)((int)param_1 + 0xfc),pvVar2,0);
          }
          pvVar2 = *(void **)((int)param_1 + 0xfc);
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)((int)pvVar2 + 0x8c));
      }
      iVar3 = FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x110));
      if (iVar3 != 0) {
        FUN_0050a080(param_1,*(int *)(iVar3 + 0x1d8));
        FUN_00506c00(param_1);
        return;
      }
    }
    else if (*(int *)((int)param_1 + 0x38) == 0x3b) {
      FUN_00506c00(param_1);
    }
    return;
  }
  *(undefined4 *)((int)param_1 + 0x108) = 0xffffffff;
  pvVar2 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 0x3c),*(int *)((int)param_1 + 0x8c),
                                (int *)0x0);
  if ((pvVar2 == (void *)0x0) || (iVar3 = FUN_0050dbd0((int)pvVar2), iVar3 != 0)) {
    *(undefined4 *)((int)param_1 + 0x8c) = 0xffffffff;
    return;
  }
  bVar1 = FUN_0050d5e0(param_1,(int)pvVar2,1);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if (*(int *)((int)param_1 + 0x30) == 0x1e) {
      return;
    }
    uVar4 = Random_Range(1,100);
    if ((int)uVar4 < 0x32) {
      *(undefined4 *)((int)param_1 + 0x108) = 5;
      return;
    }
    return;
  }
  *(undefined4 *)((int)pvVar2 + 0x108) = 4;
  FUN_0050d810(pvVar2,param_1,1);
  if (*(int *)((int)pvVar2 + 0xa8) < 1) {
    FUN_0050d930(pvVar2,(float)param_1,1);
    return;
  }
  if (*(int *)((int)param_1 + 0x30) == 0x1e) {
    return;
  }
  *(undefined4 *)((int)param_1 + 0x108) = 5;
  return;
}

