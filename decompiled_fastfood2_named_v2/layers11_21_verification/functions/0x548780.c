// rea decompile_all
// name: Sound_UpdateCityAmbience
// address: 0x548780
// body: available
// range: 0x548780-0x5489fe inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Sound_UpdateCityAmbience(void *this,int param_1,int param_2)

{
  bool bVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  longlong lVar8;
  float local_108;
  undefined1 local_104 [260];
  
                    /* Updates city music and random pass-by ambience effects. */
  if (*(char *)((int)this + 0xfc) == '\0') {
    return;
  }
  if (0 < *(int *)((int)this + 0x154)) {
    *(int *)((int)this + 0x154) = *(int *)((int)this + 0x154) + -1;
  }
  if (0 < *(int *)((int)this + 0x15c)) {
    *(int *)((int)this + 0x15c) = *(int *)((int)this + 0x15c) + -1;
  }
  if (0 < *(int *)((int)this + 0x158)) {
    *(int *)((int)this + 0x158) = *(int *)((int)this + 0x158) + -1;
  }
  bVar1 = true;
  if (0 < *(int *)((int)this + 0x150)) {
    iVar4 = *(int *)((int)this + 0x150) + -1;
    *(int *)((int)this + 0x150) = iVar4;
    if (iVar4 == 0) {
      *(undefined4 *)((int)this + 0x18) = 1000;
    }
    else {
      *(undefined4 *)((int)this + 0x18) = 0x3ec;
    }
    bVar1 = false;
  }
  if (*(char *)((int)this + 0x169) == '\0') {
    *(undefined4 *)((int)this + 0x1c) = 1000;
    return;
  }
  FUN_00548af0(this);
  if (bVar1) {
    if ((param_1 < 0x13) || (0x17 < param_1)) {
      if ((param_1 < 6) || (9 < param_1)) {
        *(undefined4 *)((int)this + 0x18) = 0x3e9;
        *(undefined1 *)((int)this + 0x168) = 0;
        goto LAB_0054885e;
      }
      iVar4 = 0x3eb;
    }
    else {
      iVar4 = 0x3ea;
    }
    if (*(int *)((int)this + 0x18) != iVar4) {
      *(undefined1 *)((int)this + 0x168) = 1;
    }
    *(int *)((int)this + 0x18) = iVar4;
  }
LAB_0054885e:
  iVar4 = *(int *)((int)this + 0x18);
  if (iVar4 == *(int *)((int)this + 0x1c)) goto LAB_005488a8;
  if (iVar4 == 0x3ec) {
    iVar4 = 0x3ec;
LAB_0054889b:
    FUN_00548680(this,iVar4);
  }
  else if (*(char *)((int)this + 0x168) == '\0') {
    if (*(int *)((int)this + 0x144) == 3) goto LAB_0054889b;
  }
  else {
    FUN_00548680(this,iVar4);
    *(undefined1 *)((int)this + 0x168) = 0;
  }
  *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)((int)this + 0x18);
LAB_005488a8:
  if (0 < *(int *)((int)this + 0x14c)) {
    *(int *)((int)this + 0x14c) = *(int *)((int)this + 0x14c) + -1;
    return;
  }
  fVar2 = (float)param_2 * 0.016666668;
  piVar3 = &DAT_0057529c;
  while (piVar5 = piVar3, piVar5 != (int *)&DAT_005752d8) {
    piVar7 = piVar5 + -3;
    bVar1 = false;
    if (((piVar5[-3] <= param_1) && (param_1 <= *piVar5 + -1)) ||
       (piVar3 = piVar5 + 3, &DAT_005752e4 <= piVar5 + 3)) goto LAB_0054890c;
  }
  piVar7 = &DAT_005752cc;
  piVar5 = &DAT_00575290;
  bVar1 = true;
LAB_0054890c:
  if (1.0 < fVar2) {
    fVar2 = 1.0;
  }
  iVar4 = *piVar7;
  if (bVar1) {
    iVar6 = (*piVar5 - iVar4) + 0x18;
  }
  else {
    iVar6 = *piVar5 - iVar4;
  }
  local_108 = (((float)piVar5[2] - (float)piVar7[2]) * ((fVar2 + (float)param_1) - (float)iVar4)) /
              (float)iVar6 + (float)piVar7[2];
  if (1.0 < local_108) {
    local_108 = 1.0;
  }
  *(float *)((int)this + 0x148) = local_108;
  lVar8 = __ftol();
  *(int *)((int)this + 0x14c) = (int)lVar8 + piVar7[1];
  iVar4 = FUN_00546fd0((void *)((int)this + 4),0,0xf);
  FUN_0054dd83(local_104,(byte *)s_Sfx__s_00576108,(&PTR_s_Sfx_City_Lkw_Pass1_wav_00575250)[iVar4]);
  FUN_00547340(this,local_104,1);
  return;
}

