// rea decompile_all
// name: Object_SyncChildState
// address: 0x5094a0
// body: available
// range: 0x5094a0-0x509576 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Object_SyncChildState(void *this,int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
                    /* Updates cached child/state fields from param_1. */
  iVar2 = *(int *)(param_1 + 0x30);
  if (*(int *)((int)this + 0x58) == iVar2) {
    *(undefined4 *)((int)this + 0x58) = 0xffffffff;
  }
  if (param_2 < 0x60) {
    if (param_2 < 0x55) {
      if (param_2 < 0x4b) {
        if (param_2 < 0x41) {
          if (param_2 < 0x37) {
            if (0x2c < param_2) goto LAB_00509550;
            if (param_2 < 0x23) {
              if (param_2 < 0x19) {
                iVar3 = *(int *)((int)this + iVar2 * 4 + 0x5c);
                if (param_2 < 0xf) {
                  iVar3 = iVar3 + -0x14;
                }
                else {
                  iVar3 = iVar3 + -10;
                }
              }
              else {
                iVar3 = *(int *)((int)this + iVar2 * 4 + 0x5c) + -5;
              }
            }
            else {
              iVar3 = *(int *)((int)this + iVar2 * 4 + 0x5c) + -3;
            }
          }
          else {
            iVar3 = *(int *)((int)this + iVar2 * 4 + 0x5c) + 3;
          }
        }
        else {
          iVar3 = *(int *)((int)this + iVar2 * 4 + 0x5c) + 5;
        }
      }
      else {
        iVar3 = *(int *)((int)this + iVar2 * 4 + 0x5c) + 8;
      }
    }
    else {
      iVar3 = *(int *)((int)this + iVar2 * 4 + 0x5c) + 10;
    }
    *(int *)((int)this + iVar2 * 4 + 0x5c) = iVar3;
  }
  else {
    *(undefined4 *)((int)this + iVar2 * 4 + 0x5c) = 100;
    *(int *)((int)this + 0x58) = iVar2;
    iVar3 = 0;
    piVar1 = (int *)((int)this + 0x5c);
    do {
      if (iVar3 != iVar2) {
        *piVar1 = *piVar1 + -10;
      }
      iVar3 = iVar3 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar3 < 6);
  }
LAB_00509550:
  piVar1 = (int *)((int)this + 0x5c);
  iVar2 = 6;
  do {
    if (100 < *piVar1) {
      *piVar1 = 100;
    }
    if (*piVar1 < -100) {
      *piVar1 = -100;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

