// rea decompile_all
// name: FUN_004d3cf0
// address: 0x4d3cf0
// body: available
// range: 0x4d3cf0-0x4d3e11 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004d3cf0(void *param_1)

{
  void *this;
  int iVar1;
  void *this_00;
  void *this_01;
  longlong lVar2;
  int iVar3;
  float fVar4;
  
  this_01 = (void *)0x0;
  this = (void *)FUN_004d3910((int)param_1);
  iVar3 = *(int *)((int)param_1 + 0x820);
  iVar1 = FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x81c));
  this_00 = (void *)FUN_004017f0((void *)(iVar1 + 0x148),iVar3,(int *)0x0);
  if (this_00 != (void *)0x0) {
    iVar3 = *(int *)((int)this_00 + 0x34);
    *(int *)((int)param_1 + 0x818) = iVar3;
    this_01 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),iVar3,(int *)0x0);
    switch(*(undefined1 *)((int)param_1 + 0x824)) {
    case 0:
      fVar4 = (float)*(int *)((int)param_1 + 0x3c);
      iVar3 = 6;
      break;
    case 1:
      fVar4 = (float)*(int *)((int)param_1 + 0x3c);
      iVar3 = 8;
      break;
    case 2:
      fVar4 = (float)*(int *)((int)param_1 + 0x3c);
      iVar3 = 7;
      break;
    case 3:
      fVar4 = (float)*(int *)((int)param_1 + 0x3c);
      iVar3 = 0xd;
      break;
    default:
      goto switchD_004d3d52_default;
    }
    FUN_00477e40(this_00,iVar3,fVar4,'\0',-1);
  }
switchD_004d3d52_default:
  *(undefined4 *)((int)param_1 + 0x81c) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x820) = 0xffffffff;
  lVar2 = Rating_GetCompositeTruncated((int)param_1);
  FUN_004d4160(param_1,(int)lVar2);
  if (this_01 == (void *)0x0) {
    FUN_004d3e30((int)param_1);
    return;
  }
  *(undefined4 *)((int)this + 0x78) = 0x10;
  if (*(int *)((int)this + 0x74) == 0) {
    FUN_00507550(this,0x13);
    FUN_00507a80((int)this);
    FUN_004d8610(this_01,param_1);
    return;
  }
  *(undefined1 *)((int)this + 0x81) = 1;
  FUN_00507550(this,0x13);
  FUN_004d8610(this_01,param_1);
  return;
}

