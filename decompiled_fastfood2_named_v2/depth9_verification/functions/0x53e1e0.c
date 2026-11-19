// rea decompile_all
// name: FUN_0053e1e0
// address: 0x53e1e0
// body: available
// range: 0x53e1e0-0x53e59c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl
FUN_0053e1e0(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,uint param_7,
            char param_8)

{
  bool bVar1;
  char cVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ushort uVar8;
  int iVar9;
  int iVar10;
  
  cVar2 = param_8;
  _param_8 = (ushort)param_6;
  if (*(char *)(param_1 + 0x18) == '\0') {
    if (cVar2 != '\0') {
      _param_8 = (ushort)((param_6 >> 0xd & 0x7c0 | param_6 & 0xf800) >> 6) |
                 (ushort)((param_6 & 0xf8) << 7);
      param_7 = (param_7 >> 0xd & 0x7c0 | param_7 & 0xf800) >> 6 | (param_7 & 0xf8) << 7;
    }
    param_6._0_2_ = (ushort)param_7;
  }
  else if (cVar2 == '\0') {
    param_6._0_2_ = (ushort)param_7;
  }
  else {
    _param_8 = (ushort)((param_6 >> 0xe & 0x3e0 | param_6 & 0xfc00) >> 5) |
               (ushort)((param_6 & 0xf8) << 8);
    param_6._0_2_ =
         (ushort)((param_7 >> 0xe & 0x3e0 | param_7 & 0xfc00) >> 5) |
         (ushort)((param_7 & 0xf8) << 8);
  }
  if (param_2 == param_4) {
    if ((*(int *)(param_1 + 4) <= param_2) && (param_2 < *(int *)(param_1 + 8))) {
      iVar5 = param_3;
      uVar8 = _param_8;
      if (param_5 < param_3) {
        iVar5 = param_5;
        param_5 = param_3;
        uVar8 = (ushort)param_6;
        param_6._0_2_ = _param_8;
      }
      if ((*(int *)(param_1 + 0xc) <= param_5) && (iVar5 < *(int *)(param_1 + 0x10))) {
        if (iVar5 < *(int *)(param_1 + 0xc)) {
          iVar5 = *(int *)(param_1 + 0xc);
        }
        if (*(int *)(param_1 + 0x10) <= param_5) {
          param_5 = *(int *)(param_1 + 0x10) + -1;
        }
        puVar3 = (ushort *)
                 (iVar5 * *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x28) + param_2 * 3);
        iVar4 = (param_5 - iVar5 >> 1) + iVar5;
        for (; iVar5 < param_5; iVar5 = iVar5 + 1) {
          if (iVar5 < iVar4) {
            *puVar3 = uVar8;
          }
          else {
            *puVar3 = (ushort)param_6;
          }
          puVar3 = (ushort *)((int)puVar3 + *(int *)(param_1 + 0x20));
        }
        *puVar3 = uVar8;
        return;
      }
    }
  }
  else if (param_3 == param_5) {
    if ((*(int *)(param_1 + 0xc) <= param_3) && (param_3 < *(int *)(param_1 + 0x10))) {
      iVar5 = param_2;
      uVar8 = _param_8;
      if (param_4 < param_2) {
        iVar5 = param_4;
        param_4 = param_2;
        uVar8 = (ushort)param_6;
        param_6._0_2_ = _param_8;
      }
      iVar4 = *(int *)(param_1 + 4);
      if ((iVar4 <= param_4) && (iVar9 = *(int *)(param_1 + 8), iVar5 < iVar9)) {
        if (iVar5 < iVar4) {
          iVar5 = iVar4;
        }
        if (iVar9 <= param_4) {
          param_4 = iVar9 + -1;
        }
        puVar3 = (ushort *)
                 (*(int *)(param_1 + 0x20) * param_3 + *(int *)(param_1 + 0x28) + iVar5 * 3);
        iVar4 = (param_4 - iVar5 >> 1) + iVar5;
        if (iVar5 <= param_4) {
          do {
            if (iVar5 < iVar4) {
              *puVar3 = uVar8;
            }
            else {
              *puVar3 = (ushort)param_6;
            }
            puVar3 = (ushort *)((int)puVar3 + 3);
            iVar5 = iVar5 + 1;
          } while (iVar5 <= param_4);
          return;
        }
      }
    }
  }
  else {
    uVar6 = param_4 - param_2 >> 0x1f;
    iVar5 = (param_4 - param_2 ^ uVar6) - uVar6;
    uVar6 = param_5 - param_3 >> 0x1f;
    iVar4 = (param_5 - param_3 ^ uVar6) - uVar6;
    if (param_2 < param_4) {
      param_7 = 1;
    }
    else {
      param_7 = (param_2 <= param_4) - 1;
    }
    if (param_3 < param_5) {
      param_5 = 1;
    }
    else {
      param_5 = (param_3 <= param_5) - 1;
    }
    bVar1 = iVar4 <= iVar5;
    iVar9 = iVar4;
    if (!bVar1) {
      iVar9 = iVar5;
      iVar5 = iVar4;
    }
    puVar3 = (ushort *)(param_3 * *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x28) + param_2 * 3)
    ;
    iVar4 = -iVar5;
    if ((((*(int *)(param_1 + 4) <= param_2) && (param_2 < *(int *)(param_1 + 8))) &&
        (*(int *)(param_1 + 0xc) <= param_3)) && (param_3 < *(int *)(param_1 + 0x10))) {
      *puVar3 = _param_8;
    }
    if (0 < iVar5) {
      iVar10 = iVar5;
      do {
        iVar4 = iVar9 * 2 + iVar4;
        if (-1 < iVar4) {
          if (bVar1) {
            puVar3 = (ushort *)((int)puVar3 + param_5 * *(int *)(param_1 + 0x20));
            param_3 = param_3 + param_5;
            iVar4 = iVar4 + iVar5 * -2;
          }
          else {
            param_2 = param_2 + param_7;
            iVar4 = iVar4 + iVar5 * -2;
            puVar3 = (ushort *)(param_7 * 3 + (int)puVar3);
          }
        }
        if (bVar1) {
          iVar7 = param_7 * 3;
          param_2 = param_2 + param_7;
        }
        else {
          iVar7 = param_5 * *(int *)(param_1 + 0x20);
          param_3 = param_3 + param_5;
        }
        puVar3 = (ushort *)((int)puVar3 + iVar7);
        if (((*(int *)(param_1 + 4) <= param_2) && (param_2 < *(int *)(param_1 + 8))) &&
           ((*(int *)(param_1 + 0xc) <= param_3 && (param_3 < *(int *)(param_1 + 0x10))))) {
          if (iVar5 / 2 < iVar10) {
            *puVar3 = _param_8;
          }
          else {
            *puVar3 = (ushort)param_6;
          }
        }
        iVar10 = iVar10 + -1;
      } while (0 < iVar10);
    }
  }
  return;
}

