// rea decompile_all
// name: FUN_0047ef30
// address: 0x47ef30
// body: available
// range: 0x47ef30-0x47f0f6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0047ef30(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  longlong lVar7;
  
  iVar3 = param_1 / 3;
  *(short *)((int)this + 0x16ec) = (short)*(undefined4 *)(DAT_0057c670 + 0x340);
  *(int *)((int)this + iVar3 * 4 + 5000) = *(short *)((int)this + 0x16c0) * 7;
  *(int *)((int)this + iVar3 * 4 + 0x13d0) = (int)*(short *)((int)this + 0x16d6);
  if (*(short *)((int)this + 0x16ec) == 0) {
    *(undefined4 *)((int)this + iVar3 * 4 + 0x1460) = 0;
    *(undefined4 *)((int)this + iVar3 * 4 + 0x1418) = 0;
  }
  else {
    *(int *)((int)this + iVar3 * 4 + 0x1460) =
         (1 - (int)*(short *)((int)this + 0x16e0) / (int)*(short *)((int)this + 0x16ec)) *
         (int)*(short *)((int)this + 0x16c0);
    *(int *)((int)this + iVar3 * 4 + 0x1418) =
         (1 - (int)*(short *)((int)this + 0x16dc) / (int)*(short *)((int)this + 0x16ec)) *
         (int)*(short *)((int)this + 0x16c0);
  }
  param_1 = 0;
  if (0 < *(int *)((int)this + 0x19ac)) {
    do {
      iVar1 = FUN_004017f0((void *)((int)this + 0x1998),param_1,(int *)0x0);
      if (*(int *)(iVar1 + 0x1c) != 0) {
        iVar5 = (*(int *)(iVar1 + 0xc) / 10 -
                *(int *)(&DAT_005675a0 + *(int *)((int)this + 0x38) * 4)) + -10 +
                *(int *)(iVar1 + 4);
        if (iVar5 < 0) {
          iVar5 = 0;
        }
        lVar7 = __ftol();
        if ((int)lVar7 < iVar5) {
          *(int *)(iVar1 + 4) = iVar5;
        }
        else {
          FUN_0047eb30(this,param_1);
        }
      }
      param_1 = param_1 + 1;
    } while (param_1 < *(int *)((int)this + 0x19ac));
  }
  uVar2 = iVar3 - 1U & 7;
  *(undefined1 *)((int)this + uVar2 * 0x34 + 0x154e) = 0;
  puVar4 = (undefined4 *)((int)this + 0x16bc);
  puVar6 = (undefined4 *)((int)this + uVar2 * 0x34 + 0x151c);
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  puVar4 = (undefined4 *)((int)this + 0x16bc);
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined1 *)((int)this + uVar2 * 0x34 + 0x154e) = 1;
  iVar3 = Game_CountFreeBuildingsByType(*(void **)((int)this + 0x16f0),0x1b);
  if (0 < iVar3) {
    FUN_00480900((int)this);
  }
  return;
}

