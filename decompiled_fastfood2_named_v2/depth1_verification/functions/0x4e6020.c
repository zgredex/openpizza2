// rea decompile_all
// name: FUN_004e6020
// address: 0x4e6020
// body: available
// range: 0x4e6020-0x4e6163 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004e6020(void *this,void *param_1)

{
  short sVar1;
  void *this_00;
  char cVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  int local_4;
  
  this_00 = param_1;
  if (0 < *(int *)((int)this + 0xc)) {
    return;
  }
  piVar3 = (int *)FUN_004ef4b0(param_1,*(int *)((int)this + 0x18),*(int *)((int)this + 0x1c));
  FUN_004e6300(this,100);
  Map_SetTileFieldWithDefault(this_00,(int)piVar3,*(int *)((int)this + 0x14),1);
  pvVar4 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 0x74),*(int *)((int)this + 4),(int *)0x0);
  cVar2 = Game_GetPlayerByte8((int)this);
  if (cVar2 == '\x01') {
    iVar5 = FUN_004e42c0(pvVar4,*(int *)((int)this + 0x14),*(int *)((int)this + 8));
    if (iVar5 == 2) {
      sVar1 = *(short *)((int)pvVar4 + *(int *)((int)this + 8) * 0xc + 0x80);
    }
    else {
      if (iVar5 != 3) {
        *(undefined4 *)(piVar3[2] + 0x1c) = 0xffffffff;
        goto LAB_004e60c8;
      }
      sVar1 = *(short *)((int)pvVar4 + *(int *)((int)this + 8) * 0xc + 0x82);
    }
    *(int *)(piVar3[2] + 0x1c) = (int)sVar1;
  }
LAB_004e60c8:
  pvVar4 = (void *)FUN_004eab50(DAT_0057c5cc,*(int *)((int)this + 0x14));
  if (pvVar4 != (void *)0x0) {
    UI_AlignSpriteToRect(this_00,piVar3,pvVar4,(int *)&param_1,&local_20);
    FUN_0053d100(pvVar4,&local_24,&local_1c);
    FUN_0053d090(pvVar4,&local_18,&local_14);
    local_10 = local_24 + -10 + (int)param_1;
    local_c = local_1c + -10 + local_20;
    local_8 = local_10 + 0x14 + local_18;
    local_4 = local_c + 0x14 + local_14;
    Gfx_BlitRectList(DAT_0058072c,&local_10);
  }
  return;
}

