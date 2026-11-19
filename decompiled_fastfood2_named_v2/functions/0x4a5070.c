// rea decompile_all
// name: FUN_004a5070
// address: 0x4a5070
// body: available
// range: 0x4a5070-0x4a52b2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004a5070(void *param_1,int param_2)

{
  int iVar1;
  void *this;
  int iVar2;
  int *piVar3;
  int local_8;
  int local_4;
  
  iVar1 = *(int *)(DAT_0057c670 + 0x218);
  this = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(iVar1 + 0x28),(int *)0x0);
  switch(param_2) {
  case 0:
    FUN_0052f9b0(param_1,0x1f67,DAT_00581d5c);
    FUN_0052f9b0(param_1,0x1f65,DAT_005824c0);
    FUN_0052f080(param_1,0x43a,(byte *)s__d__s_00568324,2);
    piVar3 = (int *)0x0;
    iVar2 = FUN_00482820(DAT_0057c670);
    param_2 = FUN_004d5dd0(this,iVar1,1,&local_4,&local_8,iVar2,piVar3);
    break;
  case 1:
    FUN_0052f9b0(param_1,0x1f67,DAT_00580bdc);
    FUN_0052f9b0(param_1,0x1f65,DAT_00582e10);
    FUN_0052f080(param_1,0x43a,(byte *)s__d__s_00568324,3);
    piVar3 = (int *)0x0;
    iVar2 = FUN_00482820(DAT_0057c670);
    param_2 = FUN_004d5dd0(this,iVar1,3,&local_4,&local_8,iVar2,piVar3);
    break;
  case 2:
    FUN_0052f9b0(param_1,0x1f67,DAT_00581bc0);
    FUN_0052f9b0(param_1,0x1f65,DAT_005827bc);
    FUN_0052f080(param_1,0x43a,(byte *)s__d__s_00568324,4);
    piVar3 = (int *)0x0;
    iVar2 = FUN_00482820(DAT_0057c670);
    param_2 = FUN_004d5dd0(this,iVar1,4,&local_4,&local_8,iVar2,piVar3);
    break;
  case 3:
    FUN_0052f9b0(param_1,0x1f67,DAT_00582954);
    FUN_0052f9b0(param_1,0x1f65,DAT_00581e98);
    FUN_0052f080(param_1,0x43a,(byte *)s__d__s_00568324,5);
    piVar3 = (int *)0x0;
    iVar2 = FUN_00482820(DAT_0057c670);
    param_2 = FUN_004d5dd0(this,iVar1,2,&local_4,&local_8,iVar2,piVar3);
    break;
  default:
  }
  _DAT_0057d268 = param_2 / 10;
  DAT_0057d26c = local_8;
  FUN_0052f080(param_1,0x439,&DAT_005686f4,local_8);
  FUN_0052f080(param_1,0x1f64,&DAT_005686f4,local_8 - param_2);
  FUN_0052f080(param_1,0x1f63,&DAT_005686f4,param_2);
  return;
}

