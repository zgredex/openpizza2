// rea decompile_all
// name: FUN_00526700
// address: 0x526700
// body: available
// range: 0x526700-0x52682f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00526700(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  puVar1 = param_1;
  iVar2 = 0;
  iVar3 = *(int *)((int)this + 0x23c);
  if (0 < iVar3) {
    piVar4 = (int *)((int)this + 0x14);
    do {
      if ((undefined4 *)*piVar4 == param_1) break;
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar2 < iVar3);
  }
  if (iVar2 != iVar3) {
    if (param_1[0x13] != 0) {
      FUN_00532890(param_1,0);
      FUN_00525af0((int)this);
    }
    CS_Enter(*(int *)((int)this + 0x1c8));
    FUN_00526640(this,(int)puVar1);
    iVar3 = FUN_005260e0((int)puVar1);
    if (iVar3 == -1) {
      CS_Leave(*(int *)((int)this + 0x1c8));
      return;
    }
    UI_FindWindowByID(this,iVar3,(int *)&param_1);
    *(undefined4 *)((int)this + (int)param_1 * 4 + 0x14) = 0;
    iVar2 = (*(int *)((int)this + 0x23c) - (int)param_1) + -1;
    if (0 < iVar2) {
      FUN_0054e230((undefined4 *)((int)this + (int)param_1 * 4 + 0x14),
                   (undefined4 *)((int)this + (int)param_1 * 4 + 0x18),iVar2 * 4);
    }
    *(undefined4 *)((int)this + *(int *)((int)this + 0x23c) * 4 + 0x10) = 0;
    *(int *)((int)this + 0x23c) = *(int *)((int)this + 0x23c) + -1;
    FUN_00525b70(this,(int)puVar1);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    CS_Leave(*(int *)((int)this + 0x1c8));
    FUN_00527850((int)this);
    *(undefined4 *)((int)this + 0x83b8) = 1;
    *(undefined4 *)((int)this + 0x234) = 1;
    *(undefined4 *)((int)this + 0x238) = 1;
    FUN_0054a660(DAT_0057c1e0,0xff0000,(byte *)s_window__d__d__deleted_0057428c,iVar3);
  }
  return;
}

