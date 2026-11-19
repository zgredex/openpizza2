// rea decompile_all
// name: FUN_0050a580
// address: 0x50a580
// body: available
// range: 0x50a580-0x50a7d8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0050a580(void *param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  void *this;
  void *this_00;
  void *this_01;
  uint extraout_EDX;
  undefined4 unaff_EDI;
  void *local_4;
  
  local_4 = (void *)0x0;
  pvVar1 = *(void **)((int)param_1 + 0xfc);
  FUN_0050ab30(param_1,pvVar1);
  if (*(int *)(*(int *)((int)param_1 + 0xfc) + 0x94) != 0) {
    FUN_0050e310(param_1,extraout_EDX,0);
    return;
  }
  iVar2 = FUN_0050d750((int)param_1);
  if (iVar2 != 0) {
    FUN_0050e840((int)param_1);
  }
  if (*(int *)((int)param_1 + 0x30) == 0x1d) {
    FUN_0050e890(param_1,0x3a);
    iVar2 = *(int *)((int)pvVar1 + 8);
    iVar3 = FUN_00482820((int)DAT_0057c670);
    if ((iVar2 == iVar3) && (iVar2 = FUN_0048c020(DAT_0057c670,7,(int)pvVar1), iVar2 == 0)) {
      iVar2 = FUN_0048bf90((int)DAT_0057c670,4,4,2,10,(int)pvVar1,DAT_005828a8,DAT_00582188,
                           unaff_EDI);
      FUN_0048c040(DAT_0057c670,iVar2,7);
    }
  }
  iVar2 = 0;
  if (*(int *)((int)pvVar1 + 0x8c) < 1) {
    this = local_4;
  }
  else {
    do {
      this = (void *)FUN_004d2a60(pvVar1,iVar2);
      iVar3 = FUN_0050d750((int)this);
      if ((((iVar3 != 0) && (*(int *)((int)this + 0x38) != 0x3a)) &&
          (iVar3 = FUN_0050dbd0((int)this), iVar3 == 0)) &&
         (local_4 = (void *)((int)local_4 + 1), *(int *)((int)param_1 + 0x30) == 0x1d)) {
        FUN_0050e890(this,0x3b);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)pvVar1 + 0x8c));
  }
  if (*(int *)((int)param_1 + 0x30) == 0x1f) {
    this_00 = (void *)FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x110));
    if (0 < (int)local_4) {
      FUN_0050e890(param_1,0x2e);
      *(undefined4 *)((int)DAT_0057c670 + 0x368) = 1;
      FUN_004e21d0(this_00,*(int *)((int)param_1 + 0x164));
      FUN_004d2960(pvVar1,param_1,0);
      *(int *)((int)this_00 + 0x90) = *(int *)((int)this_00 + 0x90) + 1;
      iVar2 = FUN_00488be0(DAT_0057c670,*(int *)((int)pvVar1 + 8));
      iVar2 = FUN_004ddcc0(iVar2);
      *(int *)(iVar2 + 0x38) = *(int *)(iVar2 + 0x38) + 1;
      return;
    }
    pvVar1 = *(void **)((int)param_1 + 0xfc);
    this_01 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                   *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
    City_CreateExplosionEffect(this_01,2,0x2e,pvVar1);
    FUN_0048c220(*(int *)((int)this + 0xfc),1,param_1);
    *(int *)((int)param_1 + 0xcc) = *(int *)((int)param_1 + 0xfc);
    *(undefined4 *)(*(int *)((int)param_1 + 0xfc) + 0x94) = 1;
    *(undefined4 *)(*(int *)((int)param_1 + 0xfc) + 0xc) = 0x12378d6;
    FUN_0050a080(param_1,*(int *)((int)this_00 + 0x1d8));
    FUN_0050e4c0(param_1,0);
    *(int *)((int)this_00 + 0x88) = *(int *)((int)this_00 + 0x88) + 1;
    iVar2 = *(int *)((int)param_1 + 0x110);
    iVar3 = FUN_00482820((int)DAT_0057c670);
    if (iVar2 == iVar3) {
      pvVar1 = *(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xac);
      FUN_004f5fa0(pvVar1,0x14);
      FUN_004f5fa0(pvVar1,0x1d);
    }
  }
  return;
}

