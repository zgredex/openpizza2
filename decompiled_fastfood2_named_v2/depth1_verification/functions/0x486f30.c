// rea decompile_all
// name: FUN_00486f30
// address: 0x486f30
// body: available
// range: 0x486f30-0x48719b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00486f30(void *this,undefined4 *param_1)

{
  int iVar1;
  void *this_00;
  int iVar2;
  void *this_01;
  void *pvVar3;
  void *this_02;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = param_1[0xb];
  pvVar3 = (void *)FUN_00488be0(this,param_1[0xc]);
  this_02 = (void *)FUN_004017f0((void *)((int)this + 4),param_1[0xd],(int *)0x0);
  this_00 = (void *)param_1[0x5bc];
  iVar2 = param_1[0xe];
  iVar4 = *(int *)((int)this_00 + 0x48);
  if ((-1 < iVar4) && (iVar4 < 4)) {
    iVar4 = *(int *)(&DAT_00568188 + iVar4 * 4);
  }
  this_01 = *(void **)((int)this + 0x25c);
  FUN_00486be0(this,1);
  FUN_0047c5e0(param_1,(uint)(iVar1 == 7));
  FUN_0047a920(param_1);
  FUN_004ddc10(pvVar3,(int)param_1);
  FUN_0047fd20(param_1);
  if (*(undefined4 **)((int)this + 0x9c) != param_1) goto LAB_00487059;
  if (*(int *)((int)this + 0x290) == 4) {
    Game_SetLockedField2FC(this,0);
    if (0 < *(int *)((int)pvVar3 + 0x15c)) {
      uVar5 = FUN_004017f0((void *)((int)pvVar3 + 0x148),0,(int *)0x0);
      *(undefined4 *)((int)this + 0x9c) = uVar5;
      Sound_SelectCurrentTrack(DAT_0057ba0c);
      FUN_00488de0(this,*(int *)((int)this + 0x9c));
      if (this_01 != (void *)0x0) {
        FUN_005301c0(this_01,-0x1869e,0x23,0);
      }
      goto LAB_00487059;
    }
    FUN_004850a0(this,1,0);
LAB_00487044:
    *(undefined4 *)((int)this + 0x9c) = 0;
  }
  else {
    if (*(int *)((int)pvVar3 + 0x15c) < 1) goto LAB_00487044;
    uVar5 = FUN_004017f0((void *)((int)pvVar3 + 0x148),0,(int *)0x0);
    *(undefined4 *)((int)this + 0x9c) = uVar5;
  }
  Sound_SelectCurrentTrack(DAT_0057ba0c);
LAB_00487059:
  if (((*(int *)((int)this + 0x2d8) == 0x1a) || (*(int *)((int)this + 0x2d8) == 0x15)) &&
     (*(int *)((int)this + 0x290) < 4)) {
    FUN_00482880((int)this);
    *(undefined4 *)((int)this + *(int *)((int)this + 0x290) * 4 + 0x2b8) =
         *(undefined4 *)((int)this + *(int *)((int)this + 0x290) * 4 + 0x298);
    *(undefined4 *)((int)this + *(int *)((int)this + 0x290) * 4 + 0x298) = 1;
    pvVar3 = FUN_00484650(this,(int *)0x1);
    FUN_00523d60(DAT_0057c5e0,(int)pvVar3);
  }
  FUN_00401320(*(int *)((int)this + 0x240));
  if (iVar1 == 7) {
    *(undefined4 *)((int)this_00 + 4) = 0x23;
    *(undefined4 *)((int)this_00 + 0x50) = 0;
    *(undefined4 *)((int)this_00 + 0x4c) = 0;
    *(undefined4 *)((int)this_00 + 0xc) = 0x12378d6;
  }
  else {
    FUN_004d2420(this_00,iVar2 + 0x14,iVar4 + 0x84c + iVar2 * 4);
  }
  *(undefined4 *)((int)this_00 + 0x74) = 0;
  FUN_004dc720(this_02,this_00,-1);
  *(undefined4 *)((int)this_00 + 0x2c) = 0xffffffff;
  if (iVar1 != 7) {
    *(undefined4 *)((int)this_00 + 0x4c) = 1;
  }
  FUN_00401340(*(int *)((int)this + 0x240));
  FUN_0048b600(this);
  Window_UnlockState((int)this);
  if (param_1 == (undefined4 *)0x0) {
    *(undefined4 *)(*(int *)((int)this_02 + 0xfa8) + 0xf4) = 1;
    return;
  }
  (**(code **)*param_1)(1);
  *(undefined4 *)(*(int *)((int)this_02 + 0xfa8) + 0xf4) = 1;
  return;
}

