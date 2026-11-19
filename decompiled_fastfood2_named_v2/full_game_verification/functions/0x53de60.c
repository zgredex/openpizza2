// rea decompile_all
// name: Surface_DrawLine
// address: 0x53de60
// body: available
// range: 0x53de60-0x53e133 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl
Surface_DrawLine(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
                char param_7)

{
  bool bVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar3 = param_1;
  if (*(char *)(param_1 + 0x18) == '\0') {
    if (param_7 != '\0') {
      param_6 = (param_6 >> 0xd & 0x7c0 | param_6 & 0xf800) >> 6 | (param_6 & 0xf8) << 7;
    }
    _param_7 = (ushort)param_6;
  }
  else if (param_7 == '\0') {
    _param_7 = (ushort)param_6;
  }
  else {
    _param_7 = (ushort)((param_6 >> 0xe & 0x3e0 | param_6 & 0xfc00) >> 5) |
               (ushort)((param_6 & 0xf8) << 8);
  }
  if (param_2 == param_4) {
    if ((*(int *)(param_1 + 4) <= param_2) && (param_2 < *(int *)(param_1 + 8))) {
      iVar3 = param_5;
      if (param_5 < param_3) {
        iVar3 = param_3;
        param_3 = param_5;
      }
      iVar8 = *(int *)(param_1 + 0xc);
      if ((iVar8 <= iVar3) && (iVar5 = *(int *)(param_1 + 0x10), param_3 < iVar5)) {
        if (param_3 < iVar8) {
          param_3 = iVar8;
        }
        if (iVar5 <= iVar3) {
          iVar3 = iVar5 + -1;
        }
        puVar2 = (ushort *)
                 (*(int *)(param_1 + 0x20) * param_3 + *(int *)(param_1 + 0x28) + param_2 * 3);
        if (param_3 < iVar3) {
          iVar3 = iVar3 - param_3;
          do {
            *puVar2 = _param_7;
            puVar2 = (ushort *)((int)puVar2 + *(int *)(param_1 + 0x20));
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        *puVar2 = _param_7;
        return;
      }
    }
  }
  else if (param_3 == param_5) {
    if ((*(int *)(param_1 + 0xc) <= param_3) && (param_3 < *(int *)(param_1 + 0x10))) {
      iVar3 = param_2;
      if (param_4 < param_2) {
        iVar3 = param_4;
        param_4 = param_2;
      }
      iVar8 = *(int *)(param_1 + 4);
      if ((iVar8 <= param_4) && (iVar5 = *(int *)(param_1 + 8), iVar3 < iVar5)) {
        if (iVar3 < iVar8) {
          iVar3 = iVar8;
        }
        if (iVar5 <= param_4) {
          param_4 = iVar5 + -1;
        }
        puVar2 = (ushort *)
                 (*(int *)(param_1 + 0x20) * param_3 + *(int *)(param_1 + 0x28) + iVar3 * 3);
        if (iVar3 <= param_4) {
          iVar3 = (param_4 - iVar3) + 1;
          do {
            *puVar2 = _param_7;
            puVar2 = (ushort *)((int)puVar2 + 3);
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          return;
        }
      }
    }
  }
  else {
    uVar4 = param_4 - param_2 >> 0x1f;
    iVar8 = (param_4 - param_2 ^ uVar4) - uVar4;
    uVar4 = param_5 - param_3 >> 0x1f;
    iVar5 = (param_5 - param_3 ^ uVar4) - uVar4;
    if (param_2 < param_4) {
      param_6 = 1;
    }
    else {
      param_6 = (param_2 <= param_4) - 1;
    }
    if (param_3 < param_5) {
      param_5 = 1;
    }
    else {
      param_5 = (param_3 <= param_5) - 1;
    }
    bVar1 = iVar5 <= iVar8;
    iVar6 = iVar5;
    if (!bVar1) {
      iVar6 = iVar8;
      iVar8 = iVar5;
    }
    puVar2 = (ushort *)(*(int *)(param_1 + 0x20) * param_3 + *(int *)(param_1 + 0x28) + param_2 * 3)
    ;
    iVar5 = -iVar8;
    if ((((*(int *)(param_1 + 4) <= param_2) && (param_2 < *(int *)(param_1 + 8))) &&
        (*(int *)(param_1 + 0xc) <= param_3)) && (param_3 < *(int *)(param_1 + 0x10))) {
      *puVar2 = _param_7;
    }
    if (0 < iVar8) {
      param_1 = iVar8;
      do {
        iVar5 = iVar6 * 2 + iVar5;
        if (-1 < iVar5) {
          if (bVar1) {
            puVar2 = (ushort *)((int)puVar2 + *(int *)(iVar3 + 0x20) * param_5);
            param_3 = param_3 + param_5;
            iVar5 = iVar5 + iVar8 * -2;
          }
          else {
            puVar2 = (ushort *)((int)puVar2 + param_6 * 3);
            param_2 = param_2 + param_6;
            iVar5 = iVar5 + iVar8 * -2;
          }
        }
        if (bVar1) {
          iVar7 = param_6 * 3;
          param_2 = param_2 + param_6;
        }
        else {
          iVar7 = *(int *)(iVar3 + 0x20) * param_5;
          param_3 = param_3 + param_5;
        }
        puVar2 = (ushort *)((int)puVar2 + iVar7);
        if (((*(int *)(iVar3 + 4) <= param_2) && (param_2 < *(int *)(iVar3 + 8))) &&
           ((*(int *)(iVar3 + 0xc) <= param_3 && (param_3 < *(int *)(iVar3 + 0x10))))) {
          *puVar2 = _param_7;
        }
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
  }
  return;
}

