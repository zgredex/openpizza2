// rea decompile_all
// name: FUN_004dae90
// address: 0x4dae90
// body: available
// range: 0x4dae90-0x4dafd8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004dae90(void *this,int param_1)

{
  int *piVar1;
  undefined4 *this_00;
  int iVar2;
  void *this_01;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int local_14 [5];
  
  iVar3 = 0;
  piVar1 = (int *)((int)this + 0xcb0);
  iVar5 = 6;
  do {
    iVar6 = *piVar1;
    piVar1 = piVar1 + 1;
    iVar3 = iVar3 + iVar6;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = 0;
  DAT_0057df98 = 999;
  _DAT_0057df9c = 999;
  _DAT_0057dfa0 = 999;
  _DAT_0057dfa4 = 999;
  _DAT_0057dfa8 = 999;
  do {
    local_14[iVar5] = iVar5;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 5);
  iVar5 = iVar3 >> 0x1f;
  iVar3 = iVar3 / 1000 + iVar5;
  if ((iVar3 == iVar5) && (param_1 != 0)) {
    iVar6 = *(int *)(param_1 + 0x48);
    if ((-1 < iVar6) && (iVar6 < 4)) {
      iVar6 = *(int *)(&DAT_00568188 + iVar6 * 4);
    }
    *(int *)(param_1 + 0x34) = iVar6 + 0x979;
  }
  this_00 = FUN_004d59c0(this,0x11,0,'\0');
  iVar6 = 0;
  if (0 < (int)this_00[5]) {
    puVar4 = &DAT_0057df98;
    do {
      iVar2 = FUN_004017f0(this_00,iVar6,(int *)0x0);
      iVar6 = iVar6 + 1;
      *puVar4 = *(undefined4 *)(iVar2 + 0xc);
      puVar4 = puVar4 + 1;
    } while (iVar6 < (int)this_00[5]);
  }
  FUN_0054ea8f(local_14,(undefined4 *)0x5,4,&LAB_004dafe0);
  iVar6 = 0;
  if (0 < (int)this_00[5]) {
    piVar1 = local_14;
    do {
      this_01 = (void *)FUN_004017f0(this_00,*piVar1,(int *)0x0);
      iVar2 = *(int *)((int)this_01 + 0x48);
      if (iVar6 < iVar3 - iVar5) {
        if ((-1 < iVar2) && (iVar2 < 4)) {
          iVar2 = *(int *)(&DAT_00568188 + iVar2 * 4);
        }
        iVar2 = iVar2 + 0x975;
      }
      else {
        if ((-1 < iVar2) && (iVar2 < 4)) {
          iVar2 = *(int *)(&DAT_00568188 + iVar2 * 4);
        }
        iVar2 = iVar2 + 0x979;
      }
      FUN_004d2420(this_01,0x11,iVar2);
      iVar6 = iVar6 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar6 < (int)this_00[5]);
  }
  if (this_00 != (undefined4 *)0x0) {
    (**(code **)*this_00)(1);
  }
  return;
}

