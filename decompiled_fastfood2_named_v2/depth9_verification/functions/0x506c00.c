// rea decompile_all
// name: FUN_00506c00
// address: 0x506c00
// body: available
// range: 0x506c00-0x506d08 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00506c00(void *param_1)

{
  uint uVar1;
  undefined4 unaff_ESI;
  void *pvVar2;
  int iVar3;
  
  switch(*(undefined4 *)((int)param_1 + 0x30)) {
  default:
    if ((*(int *)((int)param_1 + 0xd0) != 0) &&
       ((iVar3 = *(int *)(*(int *)((int)param_1 + 0xd0) + 4), iVar3 == 6 || (iVar3 == 5)))) {
      FUN_0050e890(param_1,0x1d);
      return;
    }
    uVar1 = FUN_00488d90(DAT_0057c670);
    switch(uVar1) {
    case 0:
    case 1:
      pvVar2 = (void *)0x5a;
      break;
    case 2:
    case 6:
      pvVar2 = (void *)0x3c;
      break;
    case 3:
    case 5:
      pvVar2 = (void *)0x14;
      break;
    case 4:
      pvVar2 = (void *)0x28;
      break;
    case 7:
      pvVar2 = (void *)0x46;
      break;
    default:
      pvVar2 = param_1;
    }
    uVar1 = FUN_004034d0(1,100);
    if ((int)pvVar2 < (int)uVar1) goto switchD_00506c17_caseD_d;
  case 10:
  case 0xb:
  case 0xf:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x18:
  case 0x21:
  case 0x23:
    iVar3 = 4;
    break;
  case 0xd:
  case 0x10:
  case 0x16:
switchD_00506c17_caseD_d:
    iVar3 = 0x1d;
    break;
  case 0x17:
  case 0x1d:
  case 0x1e:
  case 0x1f:
    iVar3 = *(int *)(*(int *)((int)param_1 + 0xcc) + 4);
    if (iVar3 == 0x17) goto switchD_00506c17_caseD_d;
    if (iVar3 != 0x1c) goto LAB_00506cbd;
    iVar3 = 4;
  }
  FUN_0050e890(param_1,iVar3);
LAB_00506cbd:
  if (*(void **)(DAT_0057c670 + 0x21c) == param_1) {
    if (*(int *)((int)param_1 + 0x38) == 4) {
      DebugConsole_Printf(DAT_0057c1e0,0,(byte *)s_Status__Person_wartet__00572edc,unaff_ESI);
    }
    else if (*(int *)((int)param_1 + 0x38) == 0x1d) {
      DebugConsole_Printf(DAT_0057c1e0,0,&DAT_00572ef4,unaff_ESI);
      return;
    }
  }
  return;
}

