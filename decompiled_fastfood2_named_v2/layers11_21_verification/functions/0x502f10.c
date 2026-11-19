// rea decompile_all
// name: FUN_00502f10
// address: 0x502f10
// body: available
// range: 0x502f10-0x50317a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00502f10(void *this,int param_1,int param_2,int param_3)

{
  void *this_00;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if ((param_1 < 0) || (param_1 == *(int *)((int)this + 0x48))) {
    this_00 = (void *)(DAT_0057c670 + 0x304);
    if (param_3 == -1) {
      if ((*(char *)((int)this + 0x60) != '\0') &&
         (iVar4 = *(int *)((int)this + 0x48), *(int *)((int)this + 8) == iVar4)) {
        if ((iVar4 == 0x14) || (iVar4 == 0x17)) {
          iVar4 = *(int *)((int)this + 0x84) - param_2;
          *(int *)((int)this + 0x84) = iVar4;
          if (0 < iVar4) {
            return;
          }
        }
        else {
          iVar4 = *(int *)((int)this + 0x7c);
          if (param_2 != -1) {
            iVar5 = 0;
            if (0 < iVar4) {
              do {
                iVar2 = FUN_004017f0((void *)((int)this + 0x68),iVar5,(int *)0x0);
                if (iVar2 == param_2) break;
                iVar5 = iVar5 + 1;
              } while (iVar5 < iVar4);
            }
            if (iVar5 == iVar4) {
              return;
            }
          }
          uVar3 = FUN_00502eb0((int)this);
          if ((char)uVar3 == '\0') {
            return;
          }
          iVar5 = *(int *)((int)this + 0x84);
          if (0 < iVar5) {
            if (*(int *)((int)this + 0x48) == 0x23) {
              if (iVar5 < iVar4) {
                FUN_0054acc0(this_00,*(int *)((int)this + 100),1);
                uVar1 = FUN_004034d0(0x13,0x1d);
                *(uint *)((int)this + 0x5c) = uVar1;
                *(undefined1 *)((int)this + 4) = 0;
                if ((*(int *)(DAT_0057c670 + 0x268) != 0) &&
                   (*(int *)(DAT_0057c670 + 0x278) == 0x11d7)) {
                  Game_CloseSelectionDialog(DAT_0057c670);
                }
                FUN_00503b20((int)this);
                FUN_0054a980(this_00,0x24,0,-1,-1,0,DAT_00581c14,(byte *)s__s__s_005729bc,
                             DAT_00582968);
                FUN_00503280((int)this);
              }
            }
            else if (iVar4 < iVar5) {
              return;
            }
          }
        }
        FUN_005032c0((int)this);
        FUN_0054acc0(this_00,*(int *)((int)this + 100),1);
        uVar1 = FUN_004034d0(0x13,0x1d);
        *(uint *)((int)this + 0x5c) = uVar1;
        FUN_0054a980(this_00,0x23,0,-1,-1,0,DAT_00582c08,(byte *)s__s__s_005729bc,DAT_00581218);
        FUN_00503280((int)this);
        if ((*(int *)(DAT_0057c670 + 0x268) != 0) && (*(int *)(DAT_0057c670 + 0x278) == 0x11d7)) {
          Game_CloseSelectionDialog(DAT_0057c670);
        }
      }
    }
    else if (*(char *)((int)this + 0x60) != '\0') {
      FUN_005032c0((int)this);
      FUN_0054acc0(this_00,*(int *)((int)this + 100),1);
      uVar1 = FUN_004034d0(0x13,0x1d);
      *(uint *)((int)this + 0x5c) = uVar1;
      FUN_0054a980(this_00,0x23,0,-1,-1,0,DAT_00582c08,(byte *)s__s__s_005729bc,DAT_00581218);
      FUN_00503280((int)this);
      if ((*(int *)(DAT_0057c670 + 0x268) != 0) && (*(int *)(DAT_0057c670 + 0x278) == 0x11d7)) {
        Game_CloseSelectionDialog(DAT_0057c670);
        return;
      }
    }
  }
  return;
}

