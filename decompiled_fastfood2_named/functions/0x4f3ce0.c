// rea decompile_all
// name: FUN_004f3ce0
// address: 0x4f3ce0
// body: available
// range: 0x4f3ce0-0x4f3e0a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int * __thiscall FUN_004f3ce0(void *this,void *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  void *this_00;
  int iVar6;
  int iVar7;
  int local_c;
  int local_8;
  int local_4;
  
LAB_004f3ce9:
  do {
    do {
      uVar3 = Random_Range(1,**(uint **)((int)this + 0x118));
      piVar1 = (int *)(*(int *)((int)this + 0x118) + uVar3 * 4);
    } while (piVar1 == (int *)0x0);
    iVar2 = *(int *)((int)this + 0x4c) + *piVar1 * 0xc;
  } while (((iVar2 == 0) || (*(short *)(*(int *)(iVar2 + 8) + 0x24) == -1)) ||
          (*(int *)(*(int *)(iVar2 + 8) + 0x28) == 0));
  local_4 = FUN_0047aac0(param_1,0xffffffff);
  iVar7 = 0;
  if (local_4 < 1) {
    return piVar1;
  }
  do {
    piVar4 = (int *)IDMap_Lookup((void *)((int)param_1 + 0x1500),iVar7,(int *)0x0);
    iVar5 = FUN_004d3910(*piVar4);
    if (*(void **)(iVar5 + 0xc4) == this) {
      piVar4 = *(int **)(iVar5 + 200);
      if (piVar4 == (int *)0x0) {
        iVar6 = -1;
        this_00 = (void *)0x0;
      }
      else {
        iVar6 = *piVar4;
        this_00 = (void *)piVar4[0x16];
      }
      FUN_00534370(this_00,iVar6,&local_8,&local_c);
      if (*(short *)(*(int *)(iVar5 + 200) + 0x28) == -1) {
        iVar5 = FUN_004ed5a0(this,*(int *)((int)this + 0xf8) + local_8,
                             *(int *)((int)this + 0xfc) + local_c,(int *)0x1,0);
      }
      else {
        iVar5 = FUN_00509bf0(iVar5);
        iVar5 = *(int *)((int)this + 0x4c) + *(int *)(iVar5 + 8) * 0xc;
      }
      if (iVar5 == iVar2) goto LAB_004f3ce9;
    }
    iVar7 = iVar7 + 1;
    if (local_4 <= iVar7) {
      return piVar1;
    }
  } while( true );
}

