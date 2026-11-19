// rea decompile_all
// name: Game_UpdateObject
// address: 0x4e6170
// body: available
// range: 0x4e6170-0x4e62f4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Game_UpdateObject(void *this,void *param_1)

{
  void *this_00;
  void *pvVar1;
  int *piVar2;
  int iVar3;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Updates a game object from its current state. */
  this_00 = *(void **)((int)param_1 + 0x14e0);
  if (this_00 != (void *)0x0) {
    pvVar1 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 0x74),*(int *)((int)this + 4),(int *)0x0);
    piVar2 = (int *)FUN_004ef4b0(this_00,*(int *)((int)this + 0x18),*(int *)((int)this + 0x1c));
    iVar3 = *(int *)(piVar2[2] + 0x10);
    if ((iVar3 < 0x5d) || (100 < iVar3)) {
      *(int *)((int)this + 0x14) = iVar3;
      local_28 = FUN_004e42c0(pvVar1,iVar3,*(int *)((int)this + 8));
      if (*(int *)((int)pvVar1 + 8) == 1) {
        iVar3 = local_28 + 0x5d;
        if (0x60 < iVar3) {
          iVar3 = 0x60;
        }
        FUN_00480d80(param_1,(int)this);
      }
      else if ((*(int *)((int)pvVar1 + 8) == 2) ||
              (FUN_004e4160(pvVar1,&local_2c,&local_24), local_2c == 4)) {
        iVar3 = local_28 + 0x61;
        if (100 < iVar3) {
          iVar3 = 100;
        }
      }
      else {
        iVar3 = local_28 + 0x5d;
        if (0x60 < iVar3) {
          iVar3 = 0x60;
        }
      }
      FUN_004e6300(this,0);
      FUN_004f5db0((int)piVar2);
      FUN_004ed330(this_00,(int)piVar2,iVar3,1);
      pvVar1 = (void *)FUN_004eab50(DAT_0057c5cc,*(int *)((int)this + 0x14));
      if (pvVar1 != (void *)0x0) {
        FUN_004ed780(this_00,piVar2,pvVar1,&local_20,&local_18);
        FUN_0053d100(pvVar1,&local_1c,&local_14);
        FUN_0053d090(pvVar1,&local_2c,&local_24);
        local_10 = local_1c + -10 + local_20;
        local_c = local_14 + -10 + local_18;
        local_8 = local_10 + 0x14 + local_2c;
        local_4 = local_c + 0x14 + local_24;
        FUN_00534e20(DAT_0058072c,&local_10);
      }
    }
  }
  return;
}

