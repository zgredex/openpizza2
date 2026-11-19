// rea decompile_all
// name: FUN_004c58f0
// address: 0x4c58f0
// body: available
// range: 0x4c58f0-0x4c5a54 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c58f0(void *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if (DAT_0057dcfc != 0) {
    if (*(int *)(DAT_0057dcfc + 0x4c) == 0) {
      uVar1 = *(undefined4 *)(DAT_0057dcfc + 0x44);
    }
    else {
      uVar1 = 0;
    }
    FUN_0052fd70(param_1,0x4cd,uVar1,0);
    iVar4 = 0;
    iVar3 = 0x4c1;
    do {
      iVar2 = FUN_00488be0(DAT_0057c670,iVar4);
      if (iVar2 != 0) {
        FUN_0052f080(param_1,(&DAT_0056afb8)[iVar4],&DAT_005686f4,
                     *(undefined4 *)(DAT_0057dcfc + 0x14c + *(int *)(iVar2 + 0x48) * 4));
        FUN_0052f080(param_1,(&DAT_0056afd0)[iVar4],&DAT_005686f4,
                     *(undefined4 *)(DAT_0057dcfc + 0xac + *(int *)(iVar2 + 0x48) * 4));
        iVar2 = *(int *)(DAT_0057dcfc + 0x5c + *(int *)(iVar2 + 0x48) * 4);
        if (iVar2 < 0) {
          FUN_0052fd70(param_1,iVar3 + -1,-iVar2,0);
          iVar2 = 0;
        }
        else {
          FUN_0052fd70(param_1,iVar3 + -1,0,0);
        }
        FUN_0052fd70(param_1,iVar3,iVar2,0);
      }
      iVar3 = iVar3 + 2;
      iVar4 = iVar4 + 1;
    } while (iVar3 < 0x4cd);
    iVar3 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    iVar4 = 0x439;
    do {
      FUN_00531740(param_1,iVar4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 1099);
    piVar5 = &DAT_0056afe8;
    iVar4 = 0xa0;
    do {
      iVar2 = *(int *)(iVar3 + (*(int *)(DAT_0057dcfc + 0x34) + iVar4) * 4);
      if (iVar2 == 0) {
        iVar2 = *piVar5 + 0xc;
      }
      else if (iVar2 == 1) {
        iVar2 = *piVar5;
      }
      else {
        iVar2 = *piVar5 + 6;
      }
      FUN_005316b0(param_1,iVar2);
      iVar4 = iVar4 + 8;
      piVar5 = piVar5 + 1;
    } while (iVar4 < 0xd0);
  }
  return;
}

