// rea decompile_all
// name: FUN_004893a0
// address: 0x4893a0
// body: available
// range: 0x4893a0-0x4894c8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004893a0(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == 9) {
    if (((DAT_0057c670 != 0) && (*(int *)((int)this + 0x290) == 4)) &&
       ((*(int *)((int)this + 0x2a8) == 3 || (*(int *)((int)this + 0x2d8) == 0xb)))) {
      DAT_0057c640 = *(undefined4 *)(*(int *)((int)this + 0x2fc) + 0x24);
      DAT_0057c644 = *(undefined4 *)(*(int *)((int)this + 0x2fc) + 0x28);
      return 1;
    }
  }
  else if (((((param_1 == 10) && (DAT_0057c670 != 0)) && (*(int *)((int)this + 0x290) == 4)) &&
           ((*(int *)((int)this + 0x2a8) == 3 || (*(int *)((int)this + 0x2d8) == 0xb)))) &&
          (*(int *)((int)this + 0x344) != -1)) {
    iVar1 = IDMap_Lookup((void *)((int)this + 0x74),*(int *)((int)this + 0x344),(int *)0x0);
    uVar2 = DAT_0057c640 - *(int *)(*(int *)((int)this + 0x2fc) + 0x24);
    uVar3 = (int)uVar2 >> 0x1f;
    if (((int)((uVar2 ^ uVar3) - uVar3) < 10) &&
       (uVar2 = DAT_0057c644 - *(int *)(*(int *)((int)this + 0x2fc) + 0x28),
       uVar3 = (int)uVar2 >> 0x1f, (int)((uVar2 ^ uVar3) - uVar3) < 10)) {
      CS_Enter(*(int *)((int)this + 0x240));
      FUN_00489b60((int)this);
      *(int *)(*(int *)((int)this + 0x2fc) + 0x68) =
           (int)*(short *)(iVar1 + (*(int *)((int)this + 0x350) +
                                   (*(int *)((int)this + 0x354) + 10) * 6) * 2);
      CS_Leave(*(int *)((int)this + 0x240));
    }
    return 1;
  }
  return 0;
}

