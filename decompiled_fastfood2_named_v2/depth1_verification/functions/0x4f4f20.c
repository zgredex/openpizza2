// rea decompile_all
// name: Map_PickRandomSpawnCell
// address: 0x4f4f20
// body: available
// range: 0x4f4f20-0x4f50cd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Map_PickRandomSpawnCell(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_7dc;
  int local_7d8;
  int *local_7d4;
  int local_7d0 [500];
  
                    /* Depth-1 proposal batch 3/4. */
  iVar6 = 0;
  iVar7 = 0;
  local_7d8 = 0;
  if (param_1 == 1) {
    local_7dc = *(int *)((int)this + 0x20);
    if (0 < local_7dc) {
      do {
        iVar5 = *(int *)((int)this + 0x1c);
        iVar1 = iVar7;
        if (0 < iVar5) {
          piVar3 = local_7d0 + iVar6;
          iVar1 = iVar7 + iVar5;
          piVar4 = (int *)(*(int *)((int)this + 0x4c) + 8 + iVar7 * 0xc);
          do {
            iVar7 = *piVar4;
            if (((iVar7 != 0) && (*(int *)(iVar7 + 4) == 0x354)) && (*(short *)(iVar7 + 0x24) != -1)
               ) {
              iVar6 = local_7d8 + 1;
              *piVar3 = *(int *)((int)this + 0x9c) + *(short *)(iVar7 + 0x24) * 0x28;
              piVar3 = piVar3 + 1;
              local_7d8 = iVar6;
            }
            piVar4 = piVar4 + 3;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        local_7dc = local_7dc + -1;
        iVar7 = iVar1;
      } while (local_7dc != 0);
      if (0 < iVar6) {
        uVar2 = FUN_004034d0(0,iVar6 - 1);
        return local_7d0[uVar2];
      }
    }
  }
  else if ((param_1 == 2) && (local_7d8 = 0, 0 < *(int *)((int)this + 0x20))) {
    do {
      local_7dc = 0;
      if (0 < *(int *)((int)this + 0x1c)) {
        local_7d4 = local_7d0 + iVar6;
        iVar5 = iVar7 * 0xc;
        do {
          iVar1 = *(int *)(iVar5 + 8 + *(int *)((int)this + 0x4c));
          if (iVar1 != 0) {
            iVar1 = FUN_004f2aa0(*(int *)(iVar1 + 4));
            if (iVar1 != 0) {
              iVar1 = *(int *)((int)this + 0x4c);
              if (((*(int *)(*(int *)(iVar1 + 8 + (iVar7 - *(int *)((int)this + 0x1c)) * 0xc) + 4)
                    == -1) && (*(int *)(*(int *)(iVar5 + 8 + iVar1) + 0x10) == -1)) &&
                 (iVar1 = *(int *)(iVar1 + 8 + (*(int *)((int)this + 0x1c) + iVar7) * 0xc),
                 *(int *)(iVar1 + 0x10) == -1)) {
                iVar6 = iVar6 + 1;
                *local_7d4 = *(int *)((int)this + 0x9c) + *(short *)(iVar1 + 0x24) * 0x28;
                local_7d4 = local_7d4 + 1;
              }
            }
          }
          iVar7 = iVar7 + 1;
          iVar5 = iVar5 + 0xc;
          local_7dc = local_7dc + 1;
        } while (local_7dc < *(int *)((int)this + 0x1c));
      }
      local_7d8 = local_7d8 + 1;
    } while (local_7d8 < *(int *)((int)this + 0x20));
    if (0 < iVar6) {
      uVar2 = FUN_004034d0(0,iVar6 - 1);
      return local_7d0[uVar2];
    }
  }
  return 0;
}

