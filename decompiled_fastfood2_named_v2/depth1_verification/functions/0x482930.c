// rea decompile_all
// name: FUN_00482930
// address: 0x482930
// body: available
// range: 0x482930-0x482b2c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00482930(void *this,undefined4 param_1)

{
  int iVar1;
  void *this_00;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int local_204;
  undefined1 local_200 [512];
  
  if (*(int *)((int)this + 0x268) == 0) {
    iVar1 = *(int *)(*(int *)((int)this + 0x224) + 0xa8);
    this_00 = FUN_0046d400(&local_204);
    *(void **)((int)this + 0x268) = this_00;
    FUN_0052f9b0(this_00,0x42d,DAT_0058213c);
    FUN_0054dd83(local_200,&DAT_005630d0,
                 *(undefined4 *)
                  (&DAT_00583c58 + (*(int *)(iVar1 + 0x44) + *(int *)(iVar1 + 0x58) * 4) * 4));
    FUN_0052f9b0(*(void **)((int)this + 0x268),0x42f,local_200);
    FUN_0054dd83(local_200,&DAT_005630d0,*(undefined4 *)(&DAT_00583d28 + *(int *)(iVar1 + 0x48) * 4)
                );
    FUN_0052f9b0(*(void **)((int)this + 0x268),0x436,local_200);
    FUN_0054dd83(local_200,&DAT_005630d0,*(undefined4 *)(&DAT_00583e10 + *(int *)(iVar1 + 0x50) * 4)
                );
    FUN_0052f9b0(*(void **)((int)this + 0x268),0x437,local_200);
    uVar4 = (uint)*(byte *)(*(int *)((int)this + 0x94) + 8);
    iVar2 = (uint)*(byte *)(*(int *)((int)this + 0x94) + 7) + *(int *)(iVar1 + 0x4c);
    if (0x18 < iVar2) {
      uVar3 = (iVar2 - 1U) / 0x18;
      do {
        uVar4 = uVar4 + 1;
        if (3 < (int)uVar4) {
          uVar4 = 0;
        }
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    FUN_0054dd83(local_200,(byte *)s__d___s__d__02d_00__s_005680bc,uVar4 + 1);
    FUN_0052f9b0(*(void **)((int)this + 0x268),0x439,local_200);
    *(undefined4 *)(iVar1 + 100) = param_1;
    *(undefined4 *)((int)this + 0x274) = param_1;
    *(undefined4 *)((int)this + 0x278) = 0x11d7;
    *(undefined4 *)((int)this + 0x270) = 0;
    *(undefined4 *)((int)this + 0x27c) = 0;
    *(undefined4 *)((int)this + 0x280) = 0;
    if (*(char *)(iVar1 + 0x60) != '\0') {
      FUN_00531740(*(void **)((int)this + 0x268),0x430);
      FUN_00531740(*(void **)((int)this + 0x268),0x435);
    }
    FUN_00523d60(DAT_0057c5e0,local_204);
    FUN_00532a30(*(void **)((int)this + 0x268),0x431,0xd);
    FUN_00532a30(*(void **)((int)this + 0x268),0x430,0x1b);
  }
  return;
}

