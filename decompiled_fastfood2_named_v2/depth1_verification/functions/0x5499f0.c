// rea decompile_all
// name: FUN_005499f0
// address: 0x5499f0
// body: available
// range: 0x5499f0-0x549de4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_005499f0(void *this,int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  bool bVar2;
  undefined **ppuVar3;
  undefined *local_108;
  undefined1 local_104 [260];
  
  local_108 = (undefined *)0x0;
  if (*(char *)((int)this + 0xfc) == '\0') {
    return;
  }
  switch(param_2) {
  case 0:
    if (((param_1 == 0x21) || (param_1 == 0xf)) && (param_3 == '\0')) {
      return;
    }
    ppuVar3 = &local_108;
    iVar1 = 0;
    goto LAB_00549d28;
  case 1:
    iVar1 = 1;
    if (param_1 != 0x14) goto LAB_00549d1d;
    local_108 = &DAT_0056421c;
    break;
  case 2:
    iVar1 = 1;
    if (param_1 != 0x14) goto LAB_00549da8;
LAB_00549a92:
    iVar1 = 1;
    local_108 = &DAT_00564dcc;
    break;
  case 3:
    if (param_1 != 0x14) goto LAB_00549a92;
LAB_00549ab0:
    iVar1 = 1;
    local_108 = &DAT_005762dc;
    break;
  case 4:
    if (param_1 != 0x14) goto LAB_00549ab0;
LAB_00549ace:
    iVar1 = 1;
    local_108 = &DAT_00564218;
    break;
  case 5:
    if (*(int *)(DAT_0057c670 + 0x290) != 4) {
      return;
    }
    if (0 < *(int *)((int)this + 0x154)) {
      return;
    }
    *(undefined4 *)((int)this + 0x154) = 7;
    if (param_1 != 0x14) goto LAB_00549ace;
LAB_00549b16:
    iVar1 = 1;
    local_108 = &DAT_005762d8;
    break;
  case 6:
    iVar1 = 1;
    if (param_1 != 0x14) goto LAB_00549b16;
    local_108 = &DAT_005762d4;
    break;
  case 7:
    iVar1 = 1;
    if (param_1 != 0x14) {
      return;
    }
    goto LAB_00549d1d;
  case 8:
    if (param_3 == '\0') {
      return;
    }
    if (*(int *)(DAT_0057c670 + 0x290) != 4) {
      return;
    }
    iVar1 = 0;
    switch(param_1) {
    case 0xd:
      iVar1 = 3;
      break;
    case 0x17:
      iVar1 = 0;
      break;
    case 0x1d:
      iVar1 = 2;
      break;
    case 0x1e:
      iVar1 = 1;
    }
    (**(code **)(**(int **)((int)this + 8) + 0x7c))
              (*(int **)((int)this + 8),*(undefined4 *)((int)this + iVar1 * 8 + 0x244),
               *(undefined4 *)((int)this + 0x1d8));
    (**(code **)(**(int **)((int)this + 8) + 0x5c))
              (*(int **)((int)this + 8),*(undefined4 *)((int)this + iVar1 * 8 + 0x244),0);
    return;
  case 9:
    if (param_3 == '\0') {
      return;
    }
    if (*(int *)(DAT_0057c670 + 0x290) != 4) {
      return;
    }
    iVar1 = 0;
    switch(param_1) {
    case 0xd:
      iVar1 = 3;
      break;
    case 0x17:
      iVar1 = 0;
      break;
    case 0x1d:
      iVar1 = 2;
      break;
    case 0x1e:
      iVar1 = 1;
    }
    (**(code **)(**(int **)((int)this + 8) + 0x7c))
              (*(int **)((int)this + 8),*(undefined4 *)((int)this + iVar1 * 8 + 0x248),
               *(undefined4 *)((int)this + 0x1d8));
    (**(code **)(**(int **)((int)this + 8) + 0x5c))
              (*(int **)((int)this + 8),*(undefined4 *)((int)this + iVar1 * 8 + 0x248),0);
    return;
  case 10:
    if (param_3 == '\0') {
      return;
    }
    iVar1 = 2;
    if (param_1 != 0xd) {
      return;
    }
    goto LAB_00549d1d;
  case 0xb:
    if (param_3 == '\0') {
      return;
    }
    if (*(int *)(DAT_0057c670 + 0x290) != 4) {
      return;
    }
    iVar1 = 3;
    if (param_1 != 10) {
      return;
    }
    goto LAB_00549d1d;
  case 0xc:
    if (param_3 == '\0') {
      return;
    }
    if (*(int *)(DAT_0057c670 + 0x290) != 4) {
      return;
    }
    iVar1 = 3;
    if (param_1 != 10) {
      return;
    }
    local_108 = &DAT_0056421c;
    break;
  case 0xd:
    if (param_3 == '\0') {
      return;
    }
    bVar2 = param_1 == 0x18;
LAB_00549d1b:
    iVar1 = 3;
    if (!bVar2) {
      return;
    }
    goto LAB_00549d1d;
  case 0xe:
    if (param_3 == '\0') {
      return;
    }
    iVar1 = 3;
    if (param_1 != 0x18) {
      return;
    }
LAB_00549da8:
    local_108 = &DAT_0056421c;
    break;
  case 0xf:
    if (param_3 == '\0') {
      return;
    }
    if (*(int *)(DAT_0057c670 + 0x290) != 4) {
      return;
    }
    iVar1 = 3;
    if (param_1 != 0x20) {
      bVar2 = param_1 == 0xe;
      goto LAB_00549d1b;
    }
LAB_00549d1d:
    local_108 = &DAT_005762b4;
    break;
  default:
    goto switchD_00549a28_default;
  }
  ppuVar3 = (undefined **)0x0;
LAB_00549d28:
  ppuVar3 = Employee_GetProfessionName(this,param_1,iVar1,ppuVar3);
  if (ppuVar3 != (undefined **)0x0) {
    iVar1 = (int)this + 0x174;
    if (DAT_00575090._1_1_ != '\0') {
      iVar1 = DAT_00582530;
    }
    FUN_0054dd83(local_104,(byte *)s_Speech__s__s__s__s_wav_005762b8,iVar1);
    Sound_PlayChannel(this,local_104,3);
  }
switchD_00549a28_default:
  return;
}

