// rea decompile_all
// name: FUN_0049e270
// address: 0x49e270
// body: available
// range: 0x49e270-0x49e5a8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_0049e270(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  float10 fVar6;
  undefined8 uVar7;
  undefined1 local_20 [32];
  
  iVar1 = 0;
  DAT_0057cc34 = *(void **)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) +
                           0x1d4);
  piVar4 = &DAT_0057cadc;
  piVar3 = (int *)((int)DAT_0057cc34 + 100);
  do {
    if (*piVar3 != 0) {
      *piVar4 = iVar1;
      piVar4 = piVar4 + 1;
    }
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar1 < 0x56);
  DAT_0057cad8 = 0;
  FUN_00532520((int)param_1);
  FUN_00532330(param_1,0,2,0x1f41);
  FUN_005301c0(*(void **)(DAT_0057c670 + 0x25c),-0x18670,0x23,(int)DAT_0057cc34);
  if (DAT_00568b48 == 0) {
    uVar7 = 0x100001f42;
  }
  else {
    uVar7 = 0x100001f41;
  }
  FUN_0052ff50(param_1,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
  puVar2 = (undefined4 *)FUN_0050fe50((int)DAT_0057cc34);
  FUN_0049e5b0(puVar2);
  FUN_0050fec0((int)DAT_0057cc34);
  iVar1 = FUN_0050fe50((int)DAT_0057cc34);
  if (iVar1 == 0) {
    iVar1 = 0;
    do {
      FUN_00531740(param_1,*(int *)((int)&DAT_00568b4c + iVar1));
      FUN_00531740(param_1,*(int *)((int)&DAT_00568b78 + iVar1));
      iVar1 = iVar1 + 4;
    } while (iVar1 < 0x2c);
    FUN_00531740(param_1,0x428);
    FUN_00531740(param_1,0x440);
    FUN_00531740(param_1,0x4f0);
    FUN_00531740(param_1,0x507);
    FUN_00531740(param_1,0x452);
    FUN_00531740(param_1,0x1f41);
    FUN_00531740(param_1,0x1f42);
    FUN_00531740(param_1,0x1f43);
    FUN_00531740(param_1,0x1f44);
    iVar1 = 0;
    do {
      FUN_004a80e0(param_1,0x4e7,iVar1,0,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    return;
  }
  iVar1 = 0;
  do {
    FUN_005316b0(param_1,*(int *)((int)&DAT_00568b4c + iVar1));
    FUN_005316b0(param_1,*(int *)((int)&DAT_00568b78 + iVar1));
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x2c);
  FUN_005316b0(param_1,0x428);
  FUN_005316b0(param_1,0x440);
  FUN_005316b0(param_1,0x4f0);
  FUN_005316b0(param_1,0x1f41);
  FUN_005316b0(param_1,0x1f42);
  FUN_005316b0(param_1,0x1f43);
  FUN_005316b0(param_1,0x1f44);
  FUN_005316b0(param_1,0x452);
  iVar1 = FUN_0050fe50((int)DAT_0057cc34);
  if (iVar1 < 0xc) {
    FUN_00531740(param_1,0x428);
    iVar1 = 0xb - iVar1;
    if (0 < iVar1) {
      iVar5 = 0;
      do {
        FUN_00531740(param_1,*(int *)((int)&DAT_00568b74 + iVar5));
        FUN_00531740(param_1,*(int *)((int)&DAT_00568ba0 + iVar5));
        iVar5 = iVar5 + -4;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  else {
    if (iVar1 < DAT_0057cad8 + 0xb) {
      DAT_0057cad8 = iVar1 + -0xb;
    }
    FUN_0052fd00(param_1,0x428,0,(iVar1 * 5 + -0x37) * 0x14,0);
    FUN_0052fd70(param_1,0x428,DAT_0057cad8 * 100,0);
    FUN_0052fce0(param_1,0x428,1);
  }
  FUN_0049e160(param_1,DAT_0057cad8);
  fVar6 = FUN_0050fe70((int)DAT_0057cc34);
  FUN_0054dd83(local_20,(byte *)s__0_2f__005688b8,SUB84((double)fVar6,0));
  FUN_0052f9b0(param_1,0x4f0,local_20);
  iVar1 = 0;
  do {
    iVar5 = FUN_005104d0(DAT_0057cc34,iVar1);
    FUN_004a80e0(param_1,0x4e7,iVar1,iVar5,DAT_0058155c);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  return;
}

