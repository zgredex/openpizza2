// rea decompile_all
// name: FUN_004fdbe0
// address: 0x4fdbe0
// body: available
// range: 0x4fdbe0-0x4fdce6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_004fdbe0(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_c8 [50];
  
  iVar7 = 0;
  iVar1 = FUN_00482720((int)DAT_0057c670);
  iVar6 = 0;
  iVar5 = *(int *)((int)this + param_1 * 0x168 + 0x70);
  if (0 < iVar1) {
    do {
      if (0x31 < iVar7) break;
      if ((((iVar6 != *(int *)((int)this + param_1 * 0x168 + 0x40)) &&
           (*(char *)(iVar6 + 0xac + iVar5) == '\0')) &&
          (iVar2 = FUN_00488be0(DAT_0057c670,iVar6),
          *(int *)((int)this + *(int *)(iVar2 + 0x4c) * 0x168 + 300) != 0x18)) &&
         (iVar2 = *(int *)(iVar2 + 0x15c) + 2, 0 < iVar2)) {
        piVar4 = local_c8 + iVar7;
        do {
          if (0x31 < iVar7) break;
          *piVar4 = iVar6;
          iVar7 = iVar7 + 1;
          piVar4 = piVar4 + 1;
          iVar2 = iVar2 + -1;
        } while (0 < iVar2);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar1);
    if (iVar7 != 0) {
      iVar5 = 0;
      do {
        uVar3 = FUN_004034d0(0,iVar7 - 1);
        iVar1 = local_c8[uVar3];
        uVar3 = Random_Mod(*(uint *)(*(int *)((int)this + iVar1 * 0x168 + 0x70) + 0x15c));
        iVar1 = Game_GetPlayerSubrecord(this,iVar1,uVar3,1);
        if (((iVar1 != 0) && (*(int *)(*(int *)(iVar1 + 0x16f0) + 0x38) == 0)) &&
           (*(int *)(iVar1 + 0x2c) == 0)) {
          return iVar1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 10);
    }
  }
  return 0;
}

