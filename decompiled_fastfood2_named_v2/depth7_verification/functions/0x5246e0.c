// rea decompile_all
// name: FUN_005246e0
// address: 0x5246e0
// body: available
// range: 0x5246e0-0x5247ea inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_005246e0(void *this,uint *param_1,HDC param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (((*(int *)((int)this + 0x284) != 0) && (*(int *)((int)this + 0x1b4) == 0)) &&
     (*(char *)((int)DAT_0057c5c8 + 0x30) != '\0')) {
    if (*(int *)((int)this + 0x1bc) != 0) {
      FUN_00539930(DAT_0057c5c8,(int *)param_1);
      iVar1 = *(int *)((int)this + 0x1bc);
      FUN_00539980(DAT_0057c5c8,*(HWND *)((int)this + 0x8320),*(int *)(iVar1 + 0x18),*param_1,
                   (HDC)param_1[1],param_1[2] - *param_1,param_1[3] - (int)param_1[1],
                   *(int *)(iVar1 + 4),*(ushort **)(iVar1 + 8),param_2,-1,(ushort *)0xffffffff);
      return;
    }
    if ((*(int *)((int)this + 0x1c0) != 0) && (DAT_00584504 != 0)) {
      uVar3 = ((int)*param_1 < 0) - 1 & *param_1;
      uVar5 = ((int)param_1[1] < 0) - 1 & param_1[1];
      *param_1 = uVar3;
      param_1[1] = uVar5;
      uVar4 = param_1[2];
      if ((int)*(uint *)((int)this + 0x270) < (int)param_1[2]) {
        uVar4 = *(uint *)((int)this + 0x270);
      }
      param_1[2] = uVar4;
      uVar2 = *(uint *)((int)this + 0x274);
      if ((int)param_1[3] <= (int)*(uint *)((int)this + 0x274)) {
        uVar2 = param_1[3];
      }
      param_1[3] = uVar2;
      FUN_00538da0(DAT_0057c5c8,uVar3,uVar5,uVar4 - uVar3,uVar2 - uVar5,0,
                   *(int *)((int)this + 0x1c0));
    }
  }
  return;
}

