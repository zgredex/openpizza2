// rea decompile_all
// name: FUN_0053a3f0
// address: 0x53a3f0
// body: available
// range: 0x53a3f0-0x53a775 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


bool __thiscall FUN_0053a3f0(void *this,ushort *param_1,int param_2,int param_3,uint *param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  bVar1 = *(byte *)((int)this + 4);
  if ((bVar1 & 4) != 0) {
    param_2 = param_2 - *(short *)((int)this + 10);
    param_3 = param_3 - *(short *)((int)this + 0xc);
  }
  if ((((-1 < param_2) && (-1 < param_3)) &&
      (iVar5 = (int)*(short *)((int)this + 6), param_2 < iVar5)) &&
     (iVar2 = (int)*(short *)((int)this + 8), param_3 < iVar2)) {
    iVar7 = iVar5 >> 1;
    if ((bVar1 & 2) == 0) {
      if (param_4 != (uint *)0x0) {
        if (0xe < *(byte *)((int)this + 5)) {
          *param_4 = (uint)param_1[iVar7 * param_3 + param_2];
          return true;
        }
        *param_4 = (uint)*(byte *)((int)param_1 + param_2 + iVar5 * param_3);
      }
      return true;
    }
    if (0xe < *(byte *)((int)this + 5)) {
      if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 1) == 0) {
          if (param_4 != (uint *)0x0) {
            *param_4 = (uint)param_1[iVar7 * param_3 + param_2];
          }
          return (uint)param_1[((int)*(short *)((int)this + 6) >> 1) * param_3 + param_2] !=
                 *(uint *)((int)this + 0x1c);
        }
        iVar6 = 0;
        puVar4 = param_1;
        if (0 < iVar2) {
          do {
            iVar3 = 0;
            if (0 < iVar7) {
              do {
                if ((iVar6 == param_3) && (iVar3 == param_2)) {
                  if (param_4 != (uint *)0x0) {
                    *param_4 = (uint)*puVar4;
                  }
                  return (uint)*puVar4 != *(uint *)((int)this + 0x1c);
                }
                if ((uint)*puVar4 == *(uint *)((int)this + 0x1c)) {
                  iVar3 = iVar3 + (uint)puVar4[1];
                  if ((iVar6 == param_3) && (param_2 < iVar3)) {
                    return false;
                  }
                  puVar4 = puVar4 + 2;
                }
                else {
                  puVar4 = puVar4 + 1;
                  iVar3 = iVar3 + 1;
                }
              } while (iVar3 < iVar7);
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar2);
        }
      }
      else {
        iVar6 = 0;
        puVar4 = param_1;
        if (0 < iVar2) {
          do {
            iVar3 = 0;
            if (0 < iVar7) {
              do {
                if ((iVar6 == param_3) && (iVar3 == param_2)) {
                  if (param_4 != (uint *)0x0) {
                    *param_4 = (uint)*puVar4;
                  }
                  return *puVar4 != 0;
                }
                if (*puVar4 == 0) {
                  iVar3 = iVar3 + (uint)puVar4[1];
                  if ((iVar6 == param_3) && (param_2 <= iVar3)) {
                    return false;
                  }
                }
                else {
                  iVar3 = iVar3 + 1;
                }
                puVar4 = puVar4 + 2;
              } while (iVar3 < iVar7);
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar2);
        }
      }
    }
    if (*(char *)((int)this + 5) == '\b') {
      if ((*(byte *)((int)this + 4) & 0x10) == 0) {
        if ((*(byte *)((int)this + 4) & 1) == 0) {
          if (param_4 != (uint *)0x0) {
            *param_4 = (uint)*(byte *)((int)param_1 + param_2 + iVar5 * param_3);
          }
          return (uint)*(byte *)((int)param_1 + param_2 + *(short *)((int)this + 6) * param_3) !=
                 *(uint *)((int)this + 0x1c);
        }
        iVar7 = 0;
        if (0 < iVar2) {
          do {
            iVar6 = 0;
            if (0 < iVar5) {
              do {
                if ((iVar7 == param_3) && (iVar6 == param_2)) {
                  if (param_4 != (uint *)0x0) {
                    *param_4 = (uint)(byte)*param_1;
                  }
                  return (uint)(byte)*param_1 != *(uint *)((int)this + 0x1c);
                }
                if ((uint)(byte)*param_1 == *(uint *)((int)this + 0x1c)) {
                  iVar6 = iVar6 + (uint)*(byte *)((int)param_1 + 1);
                  if ((iVar7 == param_3) && (param_2 <= iVar6)) {
                    return false;
                  }
                  param_1 = param_1 + 1;
                }
                else {
                  param_1 = (ushort *)((int)param_1 + 1);
                  iVar6 = iVar6 + 1;
                }
              } while (iVar6 < iVar5);
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar2);
        }
      }
      else {
        iVar7 = 0;
        if (0 < iVar2) {
          do {
            iVar6 = 0;
            if (0 < iVar5) {
              do {
                if ((iVar7 == param_3) && (iVar6 == param_2)) {
                  if (param_4 != (uint *)0x0) {
                    *param_4 = (uint)(byte)*param_1;
                  }
                  return (byte)*param_1 != 0;
                }
                if ((byte)*param_1 == 0) {
                  iVar6 = iVar6 + (uint)*(byte *)((int)param_1 + 1);
                  if ((iVar7 == param_3) && (param_2 <= iVar6)) {
                    return false;
                  }
                }
                else {
                  iVar6 = iVar6 + 1;
                }
                param_1 = param_1 + 1;
              } while (iVar6 < iVar5);
            }
            iVar7 = iVar7 + 1;
            if (iVar2 <= iVar7) {
              return false;
            }
          } while( true );
        }
      }
    }
  }
  return false;
}

