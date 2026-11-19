// rea decompile_all
// name: FUN_00484650
// address: 0x484650
// body: available
// range: 0x484650-0x484879 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __thiscall FUN_00484650(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *local_4;
  
  *(undefined4 *)((int)this + 0x2d8) = 0;
  iVar3 = *(int *)((int)this + *(int *)((int)this + 0x290) * 4 + 0x298);
  if (((iVar3 == 8) || (iVar3 == 7)) && (*(int *)((int)this + 0x218) == 0)) {
    *(undefined4 *)((int)this + 700) = *(undefined4 *)((int)this + 0x29c);
    *(undefined4 *)((int)this + 0x29c) = 1;
  }
  iVar3 = *(int *)((int)this + 0x218);
  local_4 = this;
  if (iVar3 != 0) {
    if (*(int *)(iVar3 + 0x38) == 0) {
      iVar2 = *(int *)(iVar3 + 4);
      if (iVar2 == 0x1c) {
        iVar3 = FUN_00488be0(this,*(int *)(iVar3 + 8));
        iVar3 = FUN_004e2280(iVar3);
        iVar2 = 0x1c;
      }
      else {
        iVar3 = 0;
      }
    }
    else {
      iVar3 = 0;
      iVar2 = 0x1a;
    }
    FUN_005480c0(DAT_0057ba0c,iVar2,iVar3);
  }
  if (*(int *)((int)this + 0x268) != 0) {
    FUN_00482890((int)this);
  }
  switch(*(undefined4 *)((int)this + *(int *)((int)this + 0x290) * 4 + 0x298)) {
  case 1:
    piVar1 = FUN_0042caa0((int *)&local_4);
    FUN_004a6c20(piVar1);
    break;
  case 2:
    piVar1 = FUN_0042bde0((int *)&local_4);
    FUN_004a6990(piVar1);
    break;
  case 3:
    piVar1 = FUN_0042ad30((int *)&local_4);
    FUN_004a5420(piVar1);
    break;
  case 4:
    piVar1 = FUN_0042d990((int *)&local_4);
    FUN_004a7c30(piVar1,'\x01');
    break;
  case 5:
    piVar1 = FUN_0042b220((int *)&local_4);
    FUN_004a5bb0(piVar1);
    break;
  case 6:
    piVar1 = FUN_0042ddf0((int *)&local_4);
    FUN_004a81f0(piVar1);
    break;
  case 7:
    piVar1 = FUN_0045d3e0((int *)&local_4);
    FUN_004c2000(piVar1);
    break;
  case 8:
    piVar1 = FUN_0045c150((int *)&local_4);
    FUN_004c16e0(piVar1);
    break;
  default:
    piVar1 = param_1;
    break;
  case 10:
    local_4 = (void *)FUN_00483740(this,*(undefined4 *)((int)this + 0x2e4));
    piVar1 = (int *)FUN_00528040(DAT_0057c5e0,(int)local_4,(int *)0x0);
    break;
  case 0xb:
    piVar1 = FUN_0042d560((int *)&local_4);
    FUN_004a7180(piVar1,'\x01');
  }
  *(int **)((int)this + 0x264) = piVar1;
  if ((char)param_1 != '\0') {
    if (*(int *)((int)this + 0x290) == 1) {
      FUN_004cec60(*(void **)((int)this + 0x260));
      return local_4;
    }
    if (*(int *)((int)this + 0x290) == 2) {
      FUN_004cefe0(*(void **)((int)this + 0x260));
      return local_4;
    }
    FUN_004cf380(*(void **)((int)this + 0x260));
  }
  return local_4;
}

