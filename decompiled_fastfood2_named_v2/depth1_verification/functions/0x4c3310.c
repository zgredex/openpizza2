// rea decompile_all
// name: FUN_004c3310
// address: 0x4c3310
// body: available
// range: 0x4c3310-0x4c3600 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c3310(void *param_1)

{
  void *this;
  void *this_00;
  int iVar1;
  int iVar2;
  void *this_01;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 extraout_EDX;
  undefined4 uVar6;
  undefined4 extraout_EDX_00;
  longlong lVar7;
  int local_18;
  int local_14;
  int local_c;
  int local_4;
  
  this_00 = param_1;
  this = *(void **)((int)DAT_0057c670 + 0x9c);
  iVar1 = FUN_00488be0(DAT_0057c670,*(int *)((int)this + 0x30));
  iVar1 = FUN_004ddcc0(iVar1);
  local_c = 0;
  lVar7 = Stats_GetAverageSpend(this,0);
  FUN_0052fd70(param_1,0x5ce,(int)lVar7,0);
  iVar2 = FUN_004781b0((int)this);
  FUN_0052fd70(param_1,0x5cf,iVar2,0);
  iVar2 = Game_CountPlayersByByte(this,5);
  FUN_0052f080(param_1,0x5d2,(byte *)s__d__s_00568324,iVar2);
  local_18 = 0;
  local_14 = 0;
  DAT_0057d73c = FUN_0047d270(this,5);
  param_1 = (void *)0x0;
  if ((int)DAT_0057d73c[5] < 1) {
    this_01 = (void *)0x0;
  }
  else {
    do {
      this_01 = (void *)FUN_004017f0(DAT_0057d73c,(int)param_1,(int *)0x0);
      if (this_01 != (void *)0x0) {
        iVar2 = FUN_004017f0((void *)((int)DAT_0057c670 + 0x74),*(int *)((int)this_01 + 4),
                             (int *)0x0);
        iVar2 = Product_ComputeFreshness(iVar2);
        iVar2 = ((0xf - iVar2) * 10) / 3 + 100;
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        local_18 = local_18 + iVar2;
        iVar2 = FUN_004e5f40(this_01,iVar1,(int *)0x0);
        local_14 = local_14 + iVar2;
        local_c = local_c + *(int *)((int)this_01 + 0xc);
      }
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < (int)DAT_0057d73c[5]);
  }
  if (DAT_0057d73c[5] == 0) {
    local_18 = 0;
    local_c = 0;
  }
  else {
    local_c = local_c / (int)DAT_0057d73c[5];
  }
  FUN_0052f080(this_00,0x58b,&DAT_005686f4,local_18);
  local_18 = 0;
  iVar2 = Game_CountObjectsByType(this,0xffffffff);
  param_1 = (void *)0x0;
  if (0 < iVar2) {
    do {
      piVar3 = (int *)FUN_004017f0((void *)((int)this + 0x1500),(int)param_1,(int *)0x0);
      if (*(char *)(*piVar3 + 0x824) == '\0') {
        uVar4 = FUN_00488d90((int)DAT_0057c670);
        iVar5 = AI_IsDirectionOnRoute(this,(int *)*piVar3,uVar4);
        if (iVar5 != 0) {
          iVar5 = Rating_GetComposite(*piVar3);
          local_18 = local_18 + iVar5;
        }
      }
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < iVar2);
  }
  FUN_0052f080(this_00,0x58d,&DAT_005686f4,local_18);
  iVar2 = FUN_004017f0((void *)((int)DAT_0057c670 + 0x74),*(int *)((int)DAT_0057d734 + 4),(int *)0x0
                      );
  iVar5 = FUN_004ddcc0(*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200)
                      );
  Game_ComputePrice(iVar2,iVar5);
  lVar7 = __ftol();
  FUN_0052f080(this_00,0x58f,&DAT_005683a4,(int)lVar7);
  iVar1 = FUN_004e5f40(DAT_0057d734,iVar1,&local_4);
  FUN_0052f080(this_00,0x591,&DAT_005683a4,local_4);
  FUN_0052f080(this_00,0x595,&DAT_005683a4,iVar1);
  FUN_0052f080(this_00,0x5ca,&DAT_005683a4,local_14);
  FUN_0052fd70(this_00,0x5c6,local_c,0);
  FUN_0052fd70(this_00,0x586,*(undefined4 *)((int)this_01 + 0xc),0);
  iVar1 = 0;
  uVar6 = extraout_EDX;
  do {
    iVar2 = FUN_00478be0(this,uVar6,iVar1);
    FUN_004a80e0(this_00,0x559,iVar1,iVar2,DAT_00582320);
    iVar1 = iVar1 + 1;
    uVar6 = extraout_EDX_00;
  } while (iVar1 < 8);
  return;
}

