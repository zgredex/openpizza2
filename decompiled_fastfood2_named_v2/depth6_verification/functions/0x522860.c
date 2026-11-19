// rea decompile_all
// name: FUN_00522860
// address: 0x522860
// body: available
// range: 0x522860-0x522b71 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00522860(void *this,uint param_1)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  uint uVar8;
  undefined4 *puVar9;
  
  iVar5 = FUN_005355f0(*(void **)((int)this + 0x54),*(char **)((int)this + 0x6c));
  if ((0x1f < (int)param_1) && ((int)param_1 < 0x100)) {
    iVar2 = *(int *)((int)this + 0x58);
    if ((iVar2 == 2) && (((int)param_1 < 0x30 || (0x39 < (int)param_1)))) {
      return 0;
    }
    if (iVar2 == 1) {
      if ((param_1 == 0x2b) || (param_1 == 0x2d)) {
        if (*(int *)((int)this + 0x80) != 0) {
          return 0;
        }
      }
      else if (((int)param_1 < 0x30) || (0x39 < (int)param_1)) {
        return 0;
      }
    }
    if ((iVar2 == 3) || (iVar2 == 4)) {
      uVar6 = FUN_0054f9e3(param_1);
      pcVar7 = _strchr(s_ABCDEFGHIJKLMNOPQRSTUVWXYZ012345_00573c6c,uVar6);
      if (pcVar7 == (char *)0x0) {
        return 0;
      }
      if ((*(int *)((int)this + 0x58) == 3) && (param_1 == 0x2e)) {
        return 0;
      }
    }
    if (*(int *)((int)this + 0x98) != 0) {
      uVar8 = *(int *)((int)this + 0x78) + 1;
      puVar9 = *(undefined4 **)((int)this + 0x6c);
      for (uVar6 = uVar8 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)puVar9 = 0;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      *(undefined4 *)((int)this + 0x80) = 0;
      *(undefined4 *)((int)this + 0x98) = 0;
      iVar5 = 0;
    }
    if (*(int *)((int)this + 0x7c) == 0) {
      uVar3 = FUN_00535650(*(void **)((int)this + 0x54),
                           (uint)*(byte *)(*(int *)((int)this + 0x80) + *(int *)((int)this + 0x6c)))
      ;
      uVar4 = FUN_00535650(*(void **)((int)this + 0x54),param_1);
      if (*(int *)((int)this + 0x84) <=
          (iVar5 - CONCAT31(extraout_var_00,uVar3)) + CONCAT31(extraout_var_01,uVar4)) {
        return 0;
      }
      uVar6 = 0xffffffff;
      pcVar7 = *(char **)((int)this + 0x6c);
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      if (*(uint *)((int)this + 0x78) <= ~uVar6) {
        return 0;
      }
      (*(char **)((int)this + 0x6c))[*(int *)((int)this + 0x80)] = (char)param_1;
LAB_005229f5:
      *(int *)((int)this + 0x80) = *(int *)((int)this + 0x80) + 1;
    }
    else {
      uVar3 = FUN_00535650(*(void **)((int)this + 0x54),param_1);
      if (*(int *)((int)this + 0x84) <= iVar5 + CONCAT31(extraout_var,uVar3)) {
        return 0;
      }
      uVar6 = 0xffffffff;
      pcVar7 = *(char **)((int)this + 0x6c);
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      if (*(uint *)((int)this + 0x78) <= ~uVar6) {
        return 0;
      }
      uVar6 = (*(uint *)((int)this + 0x78) - *(int *)((int)this + 0x80)) - 1;
      if (0 < (int)uVar6) {
        pcVar7 = *(char **)((int)this + 0x6c) + *(int *)((int)this + 0x80);
        FUN_0054e230((undefined4 *)(pcVar7 + 1),(undefined4 *)pcVar7,uVar6);
        *(char *)(*(int *)((int)this + 0x80) + *(int *)((int)this + 0x6c)) = (char)param_1;
        goto LAB_005229f5;
      }
    }
    *(undefined4 *)((int)this + 0x88) = 0xfffffc19;
    goto switchD_00522a7a_caseD_12d;
  }
  if (*(int *)((int)this + 0x98) == 0) goto switchD_00522a29_caseD_12d;
  switch(param_1) {
  case 300:
  case 0x138:
    uVar8 = *(int *)((int)this + 0x78) + 1;
    puVar9 = *(undefined4 **)((int)this + 0x6c);
    for (uVar6 = uVar8 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined1 *)puVar9 = 0;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    *(undefined4 *)((int)this + 0x80) = 0;
    *(undefined4 *)((int)this + 0x98) = 0;
    *(undefined4 *)((int)this + 0x88) = 0xfffffc19;
    break;
  case 0x12e:
  case 0x131:
  case 0x133:
  case 0x134:
    *(undefined4 *)((int)this + 0x98) = 0;
  default:
switchD_00522a29_caseD_12d:
  }
  switch(param_1) {
  case 300:
    iVar5 = *(int *)((int)this + 0x80);
    if (iVar5 != 0) {
      *(undefined4 *)((int)this + 0x88) = 0xfffffc19;
      uVar6 = *(int *)((int)this + 0x78) - iVar5;
      if (0 < (int)uVar6) {
        puVar9 = (undefined4 *)(iVar5 + *(int *)((int)this + 0x6c));
        FUN_0054e230((undefined4 *)((int)puVar9 + -1),puVar9,uVar6);
      }
      *(int *)((int)this + 0x80) = *(int *)((int)this + 0x80) + -1;
    }
  default:
    goto switchD_00522a7a_caseD_12d;
  case 0x12e:
    *(undefined4 *)((int)this + 0x80) = 0;
    break;
  case 0x131:
    if (0 < *(int *)((int)this + 0x80)) {
      *(int *)((int)this + 0x80) = *(int *)((int)this + 0x80) + -1;
    }
    break;
  case 0x133:
    if (*(char *)(*(int *)((int)this + 0x80) + *(int *)((int)this + 0x6c)) != '\0') {
      *(int *)((int)this + 0x80) = *(int *)((int)this + 0x80) + 1;
    }
    break;
  case 0x134:
    uVar6 = 0xffffffff;
    pcVar7 = *(char **)((int)this + 0x6c);
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    *(undefined4 *)((int)this + 0x88) = 0xfffffc19;
    *(uint *)((int)this + 0x80) = ~uVar6 - 1;
    goto switchD_00522a7a_caseD_12d;
  case 0x137:
    *(uint *)((int)this + 0x7c) = (uint)(*(int *)((int)this + 0x7c) == 0);
    break;
  case 0x138:
    iVar5 = *(int *)((int)this + 0x80);
    puVar9 = (undefined4 *)(iVar5 + *(int *)((int)this + 0x6c));
    if (*(char *)(iVar5 + *(int *)((int)this + 0x6c)) == '\0') goto switchD_00522a7a_caseD_12d;
    uVar6 = (*(int *)((int)this + 0x78) - iVar5) - 1;
    if (0 < (int)uVar6) {
      FUN_0054e230(puVar9,(undefined4 *)((int)puVar9 + 1),uVar6);
    }
  }
  *(undefined4 *)((int)this + 0x88) = 0xfffffc19;
switchD_00522a7a_caseD_12d:
  if (*(int *)((int)this + 0x88) == -999) {
    FUN_005321f0(*(void **)((int)this + 8),(int *)((int)this + 0x28),1);
  }
  return 1;
}

