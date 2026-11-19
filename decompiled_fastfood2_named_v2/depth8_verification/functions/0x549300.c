// rea decompile_all
// name: FUN_00549300
// address: 0x549300
// body: available
// range: 0x549300-0x549866 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined ** __thiscall FUN_00549300(void *this,undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined *puVar2;
  
  if (param_2 == 0) {
    switch(param_1) {
    case 0:
      if (param_3 != (undefined4 *)0x0) {
        iVar1 = *(int *)((int)this + 0x1dc);
        if (iVar1 == 2) {
          *(undefined4 *)((int)this + 0x1dc) = 1;
        }
        else {
          *(int *)((int)this + 0x1dc) = iVar1 + 1;
        }
        if ((iVar1 == 1) || (puVar2 = &DAT_005762b4, iVar1 != 2)) {
          puVar2 = &DAT_005762b0;
        }
        *param_3 = puVar2;
      }
      return (undefined **)&DAT_005762a8;
    case 1:
      if (param_3 != (undefined4 *)0x0) {
        iVar1 = *(int *)((int)this + 0x1e0);
        if (iVar1 == 2) {
          *(undefined4 *)((int)this + 0x1e0) = 1;
        }
        else {
          *(int *)((int)this + 0x1e0) = iVar1 + 1;
        }
        if ((iVar1 == 1) || (puVar2 = &DAT_005762b4, iVar1 != 2)) {
          puVar2 = &DAT_005762b0;
        }
        *param_3 = puVar2;
      }
      return (undefined **)s_Teens_005762a0;
    case 2:
      if (param_3 != (undefined4 *)0x0) {
        iVar1 = *(int *)((int)this + 0x1e4);
        if (iVar1 == 2) {
          *(undefined4 *)((int)this + 0x1e4) = 1;
        }
        else {
          *(int *)((int)this + 0x1e4) = iVar1 + 1;
        }
        if ((iVar1 == 1) || (puVar2 = &DAT_005762b4, iVar1 != 2)) {
          puVar2 = &DAT_005762b0;
        }
        *param_3 = puVar2;
      }
      return (undefined **)s_Studies_00576298;
    case 3:
      if (param_3 != (undefined4 *)0x0) {
        iVar1 = *(int *)((int)this + 0x1e8);
        if (iVar1 == 2) {
          *(undefined4 *)((int)this + 0x1e8) = 1;
        }
        else {
          *(int *)((int)this + 0x1e8) = iVar1 + 1;
        }
        if ((iVar1 == 1) || (puVar2 = &DAT_005762b4, iVar1 != 2)) {
          puVar2 = &DAT_005762b0;
        }
        *param_3 = puVar2;
      }
      return (undefined **)s_Prolls_00576290;
    case 4:
      if (param_3 != (undefined4 *)0x0) {
        iVar1 = *(int *)((int)this + 0x1ec);
        if (iVar1 == 2) {
          *(undefined4 *)((int)this + 0x1ec) = 1;
        }
        else {
          *(int *)((int)this + 0x1ec) = iVar1 + 1;
        }
        if ((iVar1 == 1) || (puVar2 = &DAT_005762b4, iVar1 != 2)) {
          puVar2 = &DAT_005762b0;
        }
        *param_3 = puVar2;
      }
      return (undefined **)s_Yuppie_00576288;
    case 5:
      if (param_3 != (undefined4 *)0x0) {
        iVar1 = *(int *)((int)this + 0x1f0);
        if (iVar1 == 2) {
          *(undefined4 *)((int)this + 0x1f0) = 1;
        }
        else {
          *(int *)((int)this + 0x1f0) = iVar1 + 1;
        }
        if ((iVar1 == 1) || (puVar2 = &DAT_005762b4, iVar1 != 2)) {
          puVar2 = &DAT_005762b0;
        }
        *param_3 = puVar2;
      }
      return (undefined **)s_Bonzen_00576280;
    case 6:
      if (param_3 != (undefined4 *)0x0) {
        iVar1 = *(int *)((int)this + 500);
        if (iVar1 == 2) {
          *(undefined4 *)((int)this + 500) = 1;
        }
        else {
          *(int *)((int)this + 500) = iVar1 + 1;
        }
        if ((iVar1 == 1) || (puVar2 = &DAT_005762b4, iVar1 != 2)) {
          puVar2 = &DAT_005762b0;
        }
        *param_3 = puVar2;
      }
      return (undefined **)s_Grufties_00576274;
    case 7:
      if (param_3 != (undefined4 *)0x0) {
        iVar1 = *(int *)((int)this + 0x1f8);
        if (iVar1 == 2) {
          *(undefined4 *)((int)this + 0x1f8) = 1;
        }
        else {
          *(int *)((int)this + 0x1f8) = iVar1 + 1;
        }
        if ((iVar1 == 1) || (puVar2 = &DAT_005762b4, iVar1 != 2)) {
          puVar2 = &DAT_005762b0;
        }
        *param_3 = puVar2;
      }
      return (undefined **)s_Touris_0057626c;
    case 0xb:
      if (param_3 != (undefined4 *)0x0) {
        if ((*(int *)((int)this + 0x230) == 1) ||
           (puVar2 = &DAT_005762b4, *(int *)((int)this + 0x230) != 2)) {
          puVar2 = &DAT_005762b0;
        }
        *param_3 = puVar2;
      }
      return (undefined **)s_Fatman_00576260;
    case 0xf:
    case 0x21:
      if (param_3 != (undefined4 *)0x0) {
        iVar1 = *(int *)((int)this + 0x22c);
        if (iVar1 == 2) {
          *(undefined4 *)((int)this + 0x22c) = 1;
        }
        else {
          *(int *)((int)this + 0x22c) = iVar1 + 1;
        }
        if ((iVar1 == 1) || (puVar2 = &DAT_005762b4, iVar1 != 2)) {
          puVar2 = &DAT_005762b0;
        }
        *param_3 = puVar2;
      }
      return &PTR_BYTE_00576268;
    case 0x16:
      if (param_3 != (undefined4 *)0x0) {
        iVar1 = *(int *)((int)this + 0x21c);
        if (iVar1 == 2) {
          *(undefined4 *)((int)this + 0x21c) = 1;
        }
        else {
          *(int *)((int)this + 0x21c) = iVar1 + 1;
        }
        if ((iVar1 == 1) || (puVar2 = &DAT_005762b4, iVar1 != 2)) {
          puVar2 = &DAT_005762b0;
        }
        *param_3 = puVar2;
      }
      return (undefined **)&DAT_00576250;
    case 0x1f:
      if (param_3 != (undefined4 *)0x0) {
        iVar1 = *(int *)((int)this + 0x218);
        if (iVar1 == 2) {
          *(undefined4 *)((int)this + 0x218) = 1;
        }
        else {
          *(int *)((int)this + 0x218) = iVar1 + 1;
        }
        if ((iVar1 == 1) || (puVar2 = &DAT_005762b4, iVar1 != 2)) {
          puVar2 = &DAT_005762b0;
        }
        *param_3 = puVar2;
      }
      return (undefined **)s_Kurier_00576258;
    case 0x22:
      if (param_3 != (undefined4 *)0x0) {
        if ((*(int *)((int)this + 0x23c) == 1) ||
           (puVar2 = &DAT_005762b4, *(int *)((int)this + 0x23c) != 2)) {
          puVar2 = &DAT_005762b0;
        }
        *param_3 = puVar2;
      }
      return (undefined **)s_Junge_00576248;
    }
  }
  else if (param_2 != 1) goto switchD_0054967f_default;
  switch(param_1) {
  case 0x11:
    if (param_3 != (undefined4 *)0x0) {
      if ((*(int *)((int)this + 0x1fc) == 1) ||
         (puVar2 = &DAT_005762b4, *(int *)((int)this + 0x1fc) != 2)) {
        puVar2 = &DAT_005762b0;
      }
      *param_3 = puVar2;
    }
    return (undefined **)&DAT_00576240;
  case 0x12:
    if (param_3 != (undefined4 *)0x0) {
      puVar2 = FUN_00549930(this,10,1,1);
      *param_3 = puVar2;
    }
    return (undefined **)s_Manager_005725c0;
  case 0x13:
    if (param_3 != (undefined4 *)0x0) {
      if ((*(int *)((int)this + 0x200) == 1) ||
         (puVar2 = &DAT_005762b4, *(int *)((int)this + 0x200) != 2)) {
        puVar2 = &DAT_005762b0;
      }
      *param_3 = puVar2;
    }
    return (undefined **)s_Servicek_00576234;
  case 0x14:
    if (param_3 != (undefined4 *)0x0) {
      puVar2 = FUN_00549930(this,0xb,1,1);
      *param_3 = puVar2;
    }
    return (undefined **)s_Laufbursche_00576228;
  }
switchD_0054967f_default:
  if ((param_2 == 0) || (param_2 == 2)) {
    switch(param_1) {
    case 0xd:
      if (param_3 != (undefined4 *)0x0) {
        puVar2 = FUN_00549930(this,0x11,1,1);
        *param_3 = puVar2;
      }
      return (undefined **)s_Polizei_00576200;
    case 0x17:
      if (param_3 != (undefined4 *)0x0) {
        puVar2 = FUN_00549930(this,0xc,1,2);
        *param_3 = puVar2;
      }
      return (undefined **)s_Wache_00576220;
    case 0x1d:
      if (param_3 != (undefined4 *)0x0) {
        puVar2 = FUN_00549930(this,0xe,1,2);
        *param_3 = puVar2;
      }
      return (undefined **)s_Gaengster_00576208;
    case 0x1e:
      if (param_3 != (undefined4 *)0x0) {
        puVar2 = FUN_00549930(this,0xd,1,2);
        *param_3 = puVar2;
      }
      return (undefined **)s_Schlaeger_00576214;
    }
  }
  if ((param_2 == 0) || (param_2 == 3)) {
    switch(param_1) {
    case 10:
      if (param_3 != (undefined4 *)0x0) {
        puVar2 = FUN_00549930(this,0x12,1,1);
        *param_3 = puVar2;
      }
      return (undefined **)s_Beamter_005761f8;
    case 0xe:
      if (param_3 != (undefined4 *)0x0) {
        puVar2 = FUN_00549930(this,0x17,1,1);
        *param_3 = puVar2;
      }
      return (undefined **)s_Reinigungst_005761d4;
    case 0x18:
      if (param_3 != (undefined4 *)0x0) {
        puVar2 = FUN_00549930(this,0x13,1,1);
        *param_3 = puVar2;
      }
      return (undefined **)s_Buergerm_005761ec;
    case 0x20:
      if (param_3 != (undefined4 *)0x0) {
        puVar2 = FUN_00549930(this,0x16,1,1);
        *param_3 = puVar2;
      }
      return (undefined **)s_Kammerjae_005761e0;
    }
  }
  return (undefined **)0x0;
}

