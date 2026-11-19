// rea decompile_all
// name: FUN_004f37d0
// address: 0x4f37d0
// body: available
// range: 0x4f37d0-0x4f3a87 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004f37d0(void *this,int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_b08;
  int *local_b04;
  int local_b00;
  int local_afc;
  undefined4 *local_af8;
  int local_af4 [100];
  int aiStack_964 [100];
  undefined4 auStack_7d4 [501];
  
  iVar6 = 0;
  iVar5 = 0;
  iVar8 = 0;
  local_b00 = 0;
  local_b08 = 0;
  local_afc = 0;
  if ((param_1 != 0) && (*(LPVOID *)((int)this + 0x110) != (LPVOID)0x0)) {
    FUN_0054dd78(*(LPVOID *)((int)this + 0x110));
  }
  if ((param_3 != 0) && (*(LPVOID *)((int)this + 0x114) != (LPVOID)0x0)) {
    FUN_0054dd78(*(LPVOID *)((int)this + 0x114));
  }
  if ((param_2 != 0) && (*(LPVOID *)((int)this + 0x118) != (LPVOID)0x0)) {
    FUN_0054dd78(*(LPVOID *)((int)this + 0x118));
  }
  if (0 < *(int *)((int)this + 0x20)) {
    local_af4[0] = *(int *)((int)this + 0x20);
    do {
      iVar7 = *(int *)((int)this + 0x1c);
      if (0 < iVar7) {
        piVar2 = aiStack_964 + iVar8 + 1;
        local_af8 = auStack_7d4 + local_b08 + 1;
        local_b04 = (int *)(*(int *)((int)this + 0x4c) + 8 + iVar6 * 0xc);
        iVar6 = local_afc + iVar7;
        piVar3 = local_af4 + iVar5 + 1;
        do {
          puVar1 = (undefined4 *)*local_b04;
          piVar4 = piVar3;
          if (puVar1 != (undefined4 *)0x0) {
            iVar8 = puVar1[1];
            if (iVar8 == 0x34d) {
              if ((param_1 != 0) && (*(short *)(puVar1 + 9) != -1)) {
                iVar5 = iVar5 + 1;
                piVar4 = piVar3 + 1;
                *piVar3 = *(int *)((int)this + 0x9c) + *(short *)(puVar1 + 9) * 0x28;
              }
            }
            else if (iVar8 == 0x34f) {
              if ((param_3 != 0) && (*(short *)(puVar1 + 9) != -1)) {
                local_b00 = local_b00 + 1;
                *piVar2 = *(int *)((int)this + 0x9c) + *(short *)(puVar1 + 9) * 0x28;
                piVar2 = piVar2 + 1;
              }
            }
            else if ((iVar8 == 0x352) && (param_2 != 0)) {
              *local_af8 = *puVar1;
              local_b08 = local_b08 + 1;
              local_af8 = local_af8 + 1;
            }
          }
          local_b04 = local_b04 + 3;
          iVar7 = iVar7 + -1;
          piVar3 = piVar4;
        } while (iVar7 != 0);
        iVar8 = local_b00;
        local_afc = iVar6;
      }
      local_af4[0] = local_af4[0] + -1;
    } while (local_af4[0] != 0);
  }
  if (param_1 != 0) {
    if (iVar5 < 1) {
      *(undefined4 *)((int)this + 0x110) = 0;
    }
    else {
      piVar2 = operator_new(iVar5 * 4 + 4);
      *(int **)((int)this + 0x110) = piVar2;
      *piVar2 = iVar5;
      if (0 < iVar5) {
        iVar6 = 4;
        do {
          iVar5 = iVar5 + -1;
          *(uint *)(iVar6 + *(int *)((int)this + 0x110)) =
               (uint)*(ushort *)(*(int *)((int)local_af4 + iVar6) + 4);
          iVar6 = iVar6 + 4;
        } while (iVar5 != 0);
      }
    }
  }
  if (param_3 != 0) {
    if (iVar8 < 1) {
      *(undefined4 *)((int)this + 0x114) = 0;
    }
    else {
      piVar2 = operator_new(iVar8 * 4 + 4);
      *(int **)((int)this + 0x114) = piVar2;
      *piVar2 = iVar8;
      if (0 < iVar8) {
        iVar6 = 4;
        do {
          iVar8 = iVar8 + -1;
          *(uint *)(iVar6 + *(int *)((int)this + 0x114)) =
               (uint)*(ushort *)(*(int *)((int)aiStack_964 + iVar6) + 4);
          iVar6 = iVar6 + 4;
        } while (iVar8 != 0);
      }
    }
  }
  if ((param_2 != 0) && (0 < local_b08)) {
    piVar2 = operator_new(local_b08 * 4 + 4);
    *(int **)((int)this + 0x118) = piVar2;
    *piVar2 = local_b08;
    if (0 < local_b08) {
      iVar8 = 4;
      do {
        *(undefined4 *)(*(int *)((int)this + 0x118) + iVar8) =
             *(undefined4 *)((int)auStack_7d4 + iVar8);
        iVar8 = iVar8 + 4;
        local_b08 = local_b08 + -1;
      } while (local_b08 != 0);
    }
  }
  return;
}

