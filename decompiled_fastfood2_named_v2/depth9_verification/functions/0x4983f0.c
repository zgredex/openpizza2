// rea decompile_all
// name: FUN_004983f0
// address: 0x4983f0
// body: available
// range: 0x4983f0-0x4986b6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004983f0(int *param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int *this;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  this = param_1;
  FUN_00532310(param_1,&LAB_00498160,0);
  pvVar1 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  puVar2 = *(undefined4 **)((int)pvVar1 + 0x124);
  FUN_004986f0(puVar2);
  DAT_0057c9fc = FUN_004dde70(pvVar1,*(int *)(DAT_0057c670 + 0x98));
  if ((DAT_0057c9fc < 0) && (0 < (int)puVar2)) {
    uVar3 = FUN_004017f0((void *)((int)pvVar1 + 0x110),0,(int *)0x0);
    *(undefined4 *)(DAT_0057c670 + 0x98) = uVar3;
    DAT_0057c9fc = FUN_004dde70(pvVar1,*(int *)(DAT_0057c670 + 0x98));
  }
  uVar5 = (uint)(puVar2 != (undefined4 *)0x0);
  FUN_005316f0(param_1,0x428,uVar5);
  FUN_005316f0(param_1,0x454,uVar5);
  FUN_005316f0(param_1,0x455,uVar5);
  FUN_005316f0(param_1,0x4f9,uVar5);
  FUN_005316f0(param_1,0x4fa,uVar5);
  FUN_005316f0(param_1,0x4fb,uVar5);
  FUN_005316f0(param_1,0x44e,uVar5);
  FUN_005316f0(param_1,0x451,uVar5);
  FUN_005316f0(param_1,0x452,uVar5);
  DAT_0057ca00 = (undefined4 *)0x0;
  param_1 = &DAT_00568890;
  iVar6 = 0x505;
  do {
    FUN_005316f0(this,iVar6 + -0xa4,uVar5);
    FUN_005316f0(this,iVar6,uVar5);
    FUN_005316f0(this,*param_1,uVar5);
    param_1 = param_1 + 1;
    iVar7 = iVar6 + -0x504;
    iVar6 = iVar6 + 1;
  } while (iVar7 < 8);
  if (puVar2 == (undefined4 *)0x0) {
    iVar6 = 0;
    do {
      FUN_004a80e0(this,0x4f0,iVar6,0,0);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 8);
  }
  else {
    if ((int)puVar2 < 9) {
      FUN_00531740(this,0x428);
      iVar6 = 8 - (int)puVar2;
      if (0 < iVar6) {
        iVar7 = 0x50c;
        piVar4 = &DAT_005688ac;
        do {
          FUN_00531740(this,iVar7 + -0xa4);
          FUN_00531740(this,iVar7);
          FUN_00531740(this,*piVar4);
          iVar7 = iVar7 + -1;
          piVar4 = piVar4 + -1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
    }
    else {
      DAT_0057ca00 = (undefined4 *)FUN_004986c0(DAT_0057c9fc,(int)puVar2);
      if ((int)puVar2 < (int)(DAT_0057ca00 + 2)) {
        DAT_0057ca00 = puVar2 + -2;
      }
      FUN_0052fd00(this,0x428,0,((int)puVar2 * 5 + -0x28) * 0x14,0);
      FUN_0052fd70(this,0x428,(int)DAT_0057ca00 * 100,0);
      FUN_0052fce0(this,0x428,1);
    }
    FUN_00498180(this,(int)DAT_0057ca00);
    FUN_004982b0(this);
    pvVar1 = *(void **)(DAT_0057c670 + 0x98);
    if (pvVar1 == (void *)0x0) {
      iVar6 = 0;
      do {
        FUN_004a80e0(this,0x4f0,iVar6,0,0);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 8);
    }
    else {
      iVar6 = 0;
      do {
        iVar7 = FUN_005104d0(pvVar1,iVar6);
        FUN_004a80e0(this,0x4f0,iVar6,iVar7,DAT_0058155c);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 8);
    }
  }
  FUN_0052f9b0(this,0x44d,DAT_00581e34);
  return;
}

