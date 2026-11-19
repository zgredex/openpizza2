// rea decompile_all
// name: FUN_004d9ef0
// address: 0x4d9ef0
// body: available
// range: 0x4d9ef0-0x4d9ff4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004d9ef0(void *this,void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *this_00;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int local_c;
  int local_8;
  int local_4;
  
  iVar5 = 0;
  iVar4 = 0;
  piVar1 = (int *)((int)this + 0x10d4);
  do {
    if ((*(char *)((int)piVar1 + 0x11) != '\0') && (*piVar1 == *(int *)((int)param_1 + 0x3c))) {
      return;
    }
    iVar4 = iVar4 + 1;
    piVar1 = piVar1 + 6;
  } while (iVar4 < 5);
  iVar4 = 0;
  piVar1 = (int *)((int)this + 0x10d0);
  do {
    if ((*(char *)((int)piVar1 + 0x15) != '\0') && (*piVar1 == -1)) break;
    iVar4 = iVar4 + 1;
    piVar1 = piVar1 + 6;
  } while (iVar4 < 5);
  if (iVar4 != 5) {
    *(undefined4 *)((int)this + iVar4 * 0x18 + 0x10d0) = 1;
    *(undefined4 *)((int)this + iVar4 * 0x18 + 0x10d4) = *(undefined4 *)((int)param_1 + 0x3c);
    iVar2 = FUN_004db030(this,&local_4,&local_8,&local_c);
    *(int *)((int)this + iVar4 * 0x18 + 0x10d8) = iVar2;
    *(undefined1 *)((int)this + iVar4 * 0x18 + 0x10e4) = 0;
    *(undefined4 *)((int)this + (iVar4 * 3 + 0x21c) * 8) = 0;
    *(undefined4 *)((int)this + iVar4 * 0x18 + 0x10dc) = 0;
    this_00 = FUN_004d59c0(this,0x11,0,'\0');
    if ((int)this_00[5] < 1) {
      pvVar3 = param_1;
    }
    else {
      do {
        pvVar3 = (void *)IDMap_Lookup(this_00,iVar5,(int *)0x0);
        if (*(int *)((int)pvVar3 + 0xc) == iVar4) break;
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)this_00[5]);
    }
    FUN_004d9c00(this,0x1b,pvVar3,*(undefined4 *)((int)param_1 + 0x16f0),iVar4);
    if (this_00 != (undefined4 *)0x0) {
      (**(code **)*this_00)(1);
    }
  }
  return;
}

