// rea decompile_all
// name: FUN_004da880
// address: 0x4da880
// body: available
// range: 0x4da880-0x4daae5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_004da880(void *this,char param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_90;
  int local_88 [34];
  
  local_88[4] = 10;
  local_88[0xe] = 10;
  local_88[0] = 0x21;
  local_88[1] = 4;
  local_88[2] = 8;
  local_88[3] = 1;
  local_88[5] = 0xc;
  local_88[6] = 1;
  local_88[7] = 3;
  local_88[8] = 5;
  local_88[9] = 3;
  local_88[10] = 4;
  local_88[0xb] = 4;
  local_88[0xc] = 8;
  local_88[0xd] = 2;
  local_88[0xf] = 0xc;
  local_88[0x10] = 1;
  local_88[0x11] = 9;
  local_88[0x12] = 0xd;
  local_88[0x13] = 0xe;
  local_88[0x14] = 4;
  local_88[0x15] = 0;
  local_88[0x16] = 0x21;
  local_88[0x17] = 5;
  local_88[0x18] = 6;
  local_88[0x19] = 4;
  local_88[0x1a] = 4;
  local_88[0x1b] = 3;
  local_88[0x1c] = 4;
  local_88[0x1d] = 4;
  local_88[0x1e] = 4;
  local_88[0x1f] = 3;
  local_88[0x20] = 0x14;
  local_88[0x21] = 1;
  if (param_1 == '\0') {
    local_90 = Random_Range(3,6);
    if (0 < (int)local_90) {
      do {
        uVar1 = Random_Range(0,3);
        iVar5 = local_88[uVar1];
        iVar4 = local_88[uVar1 + 6];
        uVar2 = Random_Range(0,3);
        local_88[uVar1] = local_88[uVar2];
        local_88[uVar2] = iVar5;
        local_88[uVar1 + 6] = local_88[uVar2 + 6];
        local_88[uVar2 + 6] = iVar4;
        local_90 = local_90 - 1;
      } while (local_90 != 0);
    }
    iVar5 = 6;
  }
  else {
    local_90 = Random_Range(4,7);
    if (0 < (int)local_90) {
      do {
        uVar1 = Random_Range(0,8);
        iVar5 = local_88[uVar1 + 0xc];
        iVar4 = local_88[uVar1 + 0x17];
        uVar2 = Random_Range(0,8);
        local_88[uVar1 + 0xc] = local_88[uVar2 + 0xc];
        local_88[uVar2 + 0xc] = iVar5;
        local_88[uVar1 + 0x17] = local_88[uVar2 + 0x17];
        local_88[uVar2 + 0x17] = iVar4;
        local_90 = local_90 - 1;
      } while (local_90 != 0);
    }
    iVar5 = 0xb;
  }
  iVar4 = 0;
  if (iVar5 != 0) {
    do {
      if (param_1 == '\0') {
        iVar3 = FUN_004d8780(this,local_88[iVar4]);
        if (iVar3 < local_88[iVar4 + 6]) {
          return local_88[iVar4];
        }
      }
      else {
        iVar3 = FUN_004d8780(this,local_88[iVar4 + 0xc]);
        if (iVar3 < local_88[iVar4 + 0x17]) {
          return local_88[iVar4 + 0xc];
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar5);
  }
  if (param_1 == '\0') {
    uVar1 = Random_Range(0,iVar5 - 1);
    return local_88[uVar1];
  }
  uVar1 = Random_Range(0,iVar5 - 1);
  return local_88[uVar1 + 0xc];
}

