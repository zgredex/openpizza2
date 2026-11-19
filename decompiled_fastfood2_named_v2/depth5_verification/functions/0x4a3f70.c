// rea decompile_all
// name: FUN_004a3f70
// address: 0x4a3f70
// body: available
// range: 0x4a3f70-0x4a418b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a3f70(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  this = param_1;
  iVar1 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  iVar3 = *(int *)(iVar1 + 0x1d8);
  iVar1 = FUN_004e2280(iVar1);
  FUN_005480c0(DAT_0057ba0c,0x1c,iVar1);
  iVar1 = FUN_00488be0(DAT_0057c670,*(int *)(iVar3 + 8));
  iVar3 = 0;
  do {
    iVar2 = FUN_00488be0(DAT_0057c670,iVar3);
    if (iVar2 == 0) {
      (&DAT_0057d240)[iVar3] = 0;
    }
    else {
      (&DAT_0057d240)[iVar3] = *(undefined1 *)(*(int *)(iVar1 + 0x48) + 0xac + iVar2);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 6);
  FUN_0052f9b0(param_1,0x51b,iVar1 + 8);
  FUN_004a66d0(param_1,0x23f0,iVar1);
  FUN_004a3d40(param_1);
  iVar1 = 0x23c8;
  do {
    FUN_00531740(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x23e0);
  iVar1 = 0x23f1;
  do {
    FUN_00531740(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x23f5);
  piVar4 = &DAT_00568f2c;
  do {
    iVar1 = 4;
    do {
      FUN_00531740(param_1,*piVar4);
      piVar4 = piVar4 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  } while ((int)piVar4 < 0x568f6c);
  FUN_00531740(param_1,0x23b4);
  DAT_0057d248 = 0;
  param_1 = (void *)0x0;
  iVar1 = 0;
  piVar4 = &DAT_0057d24c;
  do {
    iVar3 = FUN_00488be0(DAT_0057c670,iVar1);
    if (iVar3 == 0) {
      *piVar4 = 0;
    }
    else {
      iVar2 = FUN_00482820((int)DAT_0057c670);
      iVar3 = *(int *)(iVar3 + 0x94 + iVar2 * 4);
      *piVar4 = iVar3;
      if (0 < iVar3) {
        param_1 = (void *)((int)param_1 + 1);
      }
    }
    piVar4 = piVar4 + 1;
    iVar1 = iVar1 + 1;
  } while ((int)piVar4 < 0x57d264);
  if ((int)param_1 < 5) {
    iVar1 = 0;
    if (0 < (int)param_1) {
      piVar4 = &DAT_00568f2c;
      do {
        FUN_005316b0(this,iVar1 + 0x23f1);
        iVar3 = 4;
        do {
          FUN_005316b0(this,*piVar4);
          piVar4 = piVar4 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)param_1);
    }
  }
  else {
    iVar1 = 0;
    piVar4 = &DAT_00568f2c;
    do {
      FUN_005316b0(this,iVar1 + 0x23f1);
      iVar3 = 4;
      do {
        FUN_005316b0(this,*piVar4);
        piVar4 = piVar4 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar1 = iVar1 + 1;
    } while ((int)piVar4 < 0x568f6c);
    FUN_005316b0(this,0x23b4);
    FUN_0052fd00(this,0x23b4,0,200,0);
    FUN_0052fd70(this,0x23b4,DAT_0057d248,0);
    FUN_0052fce0(this,0x23b4,1);
  }
  FUN_004a3bc0(this,DAT_0057d248,(int)param_1);
  return;
}

