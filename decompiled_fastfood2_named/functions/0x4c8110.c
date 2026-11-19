// rea decompile_all
// name: FUN_004c8110
// address: 0x4c8110
// body: available
// range: 0x4c8110-0x4c82f6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_004c8110(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  iVar4 = 0;
  uVar3 = (uint)*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10);
  local_4 = 0;
  do {
    iVar1 = FUN_00488be0(DAT_0057c670,local_4);
    if (((iVar1 != 0) && ((&DAT_0056b250)[local_4] != '\0')) && (iVar5 = 0, uVar3 != 0)) {
      do {
        iVar2 = IDMap_Lookup((void *)(iVar1 + 0x19c),iVar5,(int *)0x0);
        switch(DAT_0056b270) {
        case 0:
          iVar2 = *(int *)(iVar2 + 300) + *(int *)(iVar2 + 0x128) + *(int *)(iVar2 + 0x124) +
                  *(int *)(iVar2 + 0x120);
          goto joined_r0x004c81e3;
        case 1:
          iVar2 = *(int *)(iVar2 + 0x13c) + *(int *)(iVar2 + 0x138) + *(int *)(iVar2 + 0x134) +
                  *(int *)(iVar2 + 0x130);
joined_r0x004c81e3:
          if (iVar2 <= iVar4) goto switchD_004c817c_default;
          goto LAB_004c82d2;
        case 2:
          iVar2 = *(int *)(iVar2 + 0x14c) + *(int *)(iVar2 + 0x148) + *(int *)(iVar2 + 0x144) +
                  *(int *)(iVar2 + 0x140);
          break;
        case 3:
          iVar2 = *(int *)(iVar2 + 0x19c) + *(int *)(iVar2 + 0x198) + *(int *)(iVar2 + 0x194) +
                  *(int *)(iVar2 + 400);
          break;
        case 4:
          iVar2 = *(int *)(iVar2 + 0x16c) + *(int *)(iVar2 + 0x168) + *(int *)(iVar2 + 0x164) +
                  *(int *)(iVar2 + 0x160);
          break;
        case 5:
          iVar2 = *(int *)(iVar2 + 0x17c) + *(int *)(iVar2 + 0x178) + *(int *)(iVar2 + 0x174) +
                  *(int *)(iVar2 + 0x170);
          break;
        case 6:
          iVar2 = *(int *)(iVar2 + 0x18c) + *(int *)(iVar2 + 0x188) + *(int *)(iVar2 + 0x184) +
                  *(int *)(iVar2 + 0x180);
          break;
        case 7:
          iVar2 = *(int *)(iVar2 + 0x15c) + *(int *)(iVar2 + 0x158) + *(int *)(iVar2 + 0x154) +
                  *(int *)(iVar2 + 0x150);
          break;
        case 0xffffffff:
          if (iVar4 < *(int *)(iVar2 + 0x11c)) {
            iVar4 = *(int *)(iVar2 + 0x11c);
          }
        default:
          goto switchD_004c817c_default;
        }
        if (iVar4 < iVar2) {
LAB_004c82d2:
          iVar4 = iVar2;
        }
switchD_004c817c_default:
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar3);
    }
    local_4 = local_4 + 1;
    if (5 < local_4) {
      return iVar4;
    }
  } while( true );
}

