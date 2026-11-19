// rea decompile_all
// name: FUN_004d5dd0
// address: 0x4d5dd0
// body: available
// range: 0x4d5dd0-0x4d6244 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall
FUN_004d5dd0(void *this,int param_1,int param_2,int *param_3,int *param_4,int param_5,int *param_6)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  int local_12c;
  int local_128;
  int local_124 [4];
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108 [65];
  
  iVar4 = 0;
  bVar2 = false;
  bVar1 = false;
  local_124[1] = 0;
  local_124[2] = 0x3ff00000;
  local_114 = 200;
  local_110 = 400;
  local_10c = 800;
  if (param_6 != (int *)0x0) {
    *param_6 = 0;
  }
  *param_3 = 0;
  *param_4 = 0;
  switch(param_2) {
  case 1:
    iVar3 = FUN_004d2e40(param_1);
    if (iVar3 != 0) {
      bVar2 = true;
      goto switchD_004d5e4d_default;
    }
    iVar4 = 5000;
    break;
  case 2:
    iVar4 = 6000;
    break;
  case 3:
    iVar3 = FUN_004d2e60(param_1);
    if (iVar3 != 0) {
      bVar2 = true;
      goto switchD_004d5e4d_default;
    }
    iVar4 = 4000;
    break;
  case 4:
    iVar4 = 3000;
    break;
  default:
    goto switchD_004d5e4d_default;
  }
  bVar1 = true;
switchD_004d5e4d_default:
  FUN_004d5cf0(this,param_1,&local_12c,local_124,&local_128);
  if (param_6 != (int *)0x0) {
    *param_6 = local_128;
  }
  if ((bVar1) && (iVar3 = FUN_004d2fd0(param_1), iVar3 != 0)) {
    if (param_2 == 2) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x3c);
      iVar3 = FUN_0048cdd0(DAT_0057c670,param_1,local_108);
      iVar4 = ((iVar3 + 6) * iVar4) / 0x14;
    }
    lVar5 = __ftol();
    *param_4 = iVar4 - (int)lVar5;
    lVar5 = __ftol();
    *param_4 = (int)lVar5;
    lVar6 = __ftol();
    iVar3 = (int)lVar6 + (int)lVar5;
    *param_4 = iVar3;
    lVar5 = __ftol();
    iVar4 = (int)lVar5;
    *param_4 = iVar3 + iVar4;
    iVar3 = FUN_00482820((int)DAT_0057c670);
    if (param_5 == iVar3) {
      lVar5 = __ftol();
      *param_4 = (int)lVar5;
      lVar5 = __ftol();
      iVar4 = (int)lVar5;
    }
  }
  if ((bVar2) && (*(int *)(param_1 + 0x4c) != 0)) {
    lVar5 = __ftol();
    *param_3 = (int)lVar5;
    if (*(int *)(param_1 + 0x4c) != 0) {
      lVar5 = __ftol();
      *param_3 = (int)lVar5;
    }
    iVar3 = *param_3;
    lVar5 = __ftol();
    *param_3 = (int)lVar5 + iVar3;
    iVar3 = FUN_00482820((int)DAT_0057c670);
    if (param_5 == iVar3) {
      iVar3 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
      if (*(int *)(iVar3 + 0x10c) != 0) {
        *param_3 = 0;
        return iVar4;
      }
      if (*(int *)(iVar3 + 0xfc) != 0) {
        *param_3 = *param_3 / 2;
        return iVar4;
      }
      if (*(int *)(iVar3 + 0x1e0) != 0) {
        *param_3 = (*param_3 * 0xf) / 10;
      }
    }
  }
  return iVar4;
}

