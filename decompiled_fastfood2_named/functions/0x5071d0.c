// rea decompile_all
// name: FUN_005071d0
// address: 0x5071d0
// body: available
// range: 0x5071d0-0x507513 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_005071d0(void *param_1)

{
  void *this;
  uint uVar1;
  int iVar2;
  undefined4 unaff_EDI;
  longlong lVar3;
  char *pcVar4;
  
  if (0 < *(int *)((int)param_1 + 0x44)) {
    *(int *)((int)param_1 + 0x44) = *(int *)((int)param_1 + 0x44) + -1;
  }
  if (*(void **)(DAT_0057c670 + 0x21c) == param_1) {
    if (*(int *)((int)param_1 + 0xfc) == 0) {
      FUN_0054a660(DAT_0057c1e0,0,(byte *)s_C__d__In__d__St__d__NULL_00572f80,
                   *(undefined4 *)((int)param_1 + 0x44));
    }
    else {
      FUN_0054a660(DAT_0057c1e0,0,(byte *)s_C__d__In__d__St__d___s_00572f68,
                   *(undefined4 *)((int)param_1 + 0x44));
    }
  }
  iVar2 = *(int *)((int)param_1 + 0x30);
  if (iVar2 == 0xf) {
    return;
  }
  if (iVar2 == 0x21) {
    return;
  }
  if (iVar2 == 0xb) {
    return;
  }
  switch(*(undefined2 *)((int)param_1 + 0x40)) {
  case 0:
    if (*(int *)((int)param_1 + 0x44) != 0) {
      lVar3 = FUN_00403850((float)*(int *)((int)param_1 + 0x44) /
                           ((float)*(int *)((int)param_1 + 0x48) * 0.0625));
      iVar2 = 0x29 - (int)lVar3;
      if (0x28 < iVar2) {
        iVar2 = 0x28;
      }
      FUN_005078b0(param_1,iVar2);
      return;
    }
    FUN_00504a90(param_1,2);
    FUN_00507550(param_1,1);
    *(undefined4 *)((int)param_1 + 0x4c) = 0;
    *(undefined4 *)((int)param_1 + 0x54) = 0;
    if (*(void **)(DAT_0057c670 + 0x21c) == param_1) {
      FUN_0054a660(DAT_0057c1e0,0,(byte *)s_Bricht_Suche_ab__00572f54,unaff_EDI);
    }
    uVar1 = FUN_00488d90(DAT_0057c670);
    iVar2 = FUN_00507ee0(param_1,uVar1);
    if (iVar2 == 0) {
      FUN_00507fd0(param_1);
      return;
    }
    break;
  case 1:
    if (*(int *)((int)param_1 + 0x44) == 0) {
      FUN_00507550(param_1,0xffff);
      FUN_00504a90(param_1,0);
      return;
    }
    break;
  case 0x11:
    if (*(int *)((int)param_1 + 0x44) == 0) {
      FUN_00504a90(param_1,9);
      FUN_00507550(param_1,0x16);
      *(undefined4 *)((int)param_1 + 0x4c) = 0;
      *(undefined4 *)((int)param_1 + 0x54) = 0;
      if (*(void **)((int)param_1 + 0xfc) != (void *)0x0) {
        FUN_004d2fa0(*(void **)((int)param_1 + 0xfc),*(void **)((int)param_1 + 0xc4),0x10);
        return;
      }
    }
    else {
      lVar3 = FUN_00403850((float)*(int *)((int)param_1 + 0x44) /
                           ((float)*(int *)((int)param_1 + 0x48) * 0.0625));
      iVar2 = 0x10 - (int)lVar3;
      if (0xf < iVar2) {
        iVar2 = 0xf;
      }
      if (*(void **)((int)param_1 + 0xfc) != (void *)0x0) {
        FUN_004d2fa0(*(void **)((int)param_1 + 0xfc),*(void **)((int)param_1 + 0xc4),(char)iVar2);
        return;
      }
    }
    break;
  case 0x16:
    if (*(int *)((int)param_1 + 0x44) == 0) {
      FUN_00507550(param_1,0xffff);
      FUN_0050e890(param_1,4);
      FUN_00504a90(param_1,0);
      if (*(void **)((int)param_1 + 0xfc) != (void *)0x0) {
        FUN_004d2d80(*(void **)((int)param_1 + 0xfc),*(void **)((int)param_1 + 0xc4),1);
        return;
      }
    }
    break;
  case 0xffff:
    if (*(int *)((int)param_1 + 0x44) != 0) {
      return;
    }
    if (*(int *)((int)param_1 + 0x38) == 4) {
      this = *(void **)((int)param_1 + 0xfc);
      if ((this == (void *)0x0) ||
         ((*(int *)((int)this + 4) != 0 && (*(int *)((int)this + 4) != 7)))) {
LAB_005074b2:
        FUN_0050ab70(param_1,*(void **)((int)param_1 + 0xfc));
        goto LAB_005074c0;
      }
      uVar1 = Random_Range(1,100);
      iVar2 = *(int *)((int)param_1 + 0x30);
      if ((iVar2 == 0xf) || (((iVar2 == 0xb || (iVar2 == 0x21)) || ((int)uVar1 < 0x33))))
      goto LAB_005074b2;
      FUN_004d2d10(this,*(void **)((int)param_1 + 0xc4),1);
      FUN_0050e890(param_1,0x1a);
      FUN_00507550(param_1,0x11);
      FUN_00504a90(param_1,8);
      if (*(void **)(DAT_0057c670 + 0x21c) != param_1) {
        return;
      }
      pcVar4 = s_Bestellt_telefonisch_Pizza__00572f38;
    }
    else {
LAB_005074c0:
      FUN_00507550(param_1,0);
      FUN_00504a90(param_1,1);
      *(undefined4 *)((int)param_1 + 0x4c) = 1;
      FUN_0050e890(param_1,1);
      FUN_00401440((int)param_1 + 0x130);
      if (*(void **)(DAT_0057c670 + 0x21c) != param_1) {
        return;
      }
      pcVar4 = s_Sucht_Pizzeria__00572f28;
    }
    FUN_0054a660(DAT_0057c1e0,0,(byte *)pcVar4,unaff_EDI);
  }
  return;
}

