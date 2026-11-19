// rea decompile_all
// name: FUN_004f4960
// address: 0x4f4960
// body: available
// range: 0x4f4960-0x4f4ad5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_004f4960(void *this,undefined4 param_1,undefined4 param_2,byte *param_3,int param_4)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  int local_4;
  
  iVar6 = 0;
  local_c = 0;
  iVar3 = (*(int *)((int)this + 0xc) * DAT_00571960 - *(int *)((int)this + 0x2c)) + -0x100 +
          *(int *)((int)this + 0x24);
  iVar4 = (*(int *)((int)this + 0x10) * DAT_00571964 - *(int *)((int)this + 0x30)) + -0x80 +
          *(int *)((int)this + 0x28);
  local_4 = *(int *)(param_3 + 4);
  local_18 = *(int *)(param_3 + 8);
  local_10 = local_4;
  if (iVar3 < 0) {
    local_10 = local_4 + iVar3;
    local_c = -iVar3;
    iVar3 = 0;
  }
  if (iVar4 < 0) {
    local_18 = local_18 + iVar4;
    iVar6 = -iVar4;
    iVar4 = 0;
  }
  iVar1 = *(int *)((int)this + 0x70);
  if (iVar1 == 0) {
    if (*(void **)((int)this + 0x74) == (void *)0x0) {
      pbVar2 = param_3;
    }
    else {
      FUN_0053d040(*(void **)((int)this + 0x74),&local_14,&local_8);
      iVar1 = FUN_0053d480(*(void **)((int)this + 0x74));
      pbVar2 = (byte *)(local_14 * iVar4 + iVar3 + iVar1);
    }
  }
  else {
    local_14 = *(uint *)(iVar1 + 4);
    local_8 = *(uint *)(iVar1 + 8);
    pbVar2 = (byte *)(local_14 * iVar4 + *(int *)(iVar1 + 0x18) + iVar3);
  }
  param_3 = (byte *)(iVar6 * local_4 + *(int *)(param_3 + 0x18) + local_c);
  if ((int)local_14 < local_10 + iVar3) {
    local_10 = local_14 - iVar3;
  }
  if ((int)local_8 < local_18 + iVar4) {
    local_18 = local_8 - iVar4;
  }
  if (0 < local_18) {
    local_c = local_18;
    do {
      if (0 < local_10) {
        pbVar5 = pbVar2;
        iVar4 = local_10;
        do {
          if (pbVar5[(int)param_3 - (int)pbVar2] < 0xff) {
            *pbVar5 = *(byte *)((uint)*pbVar5 +
                               param_4 + (uint)pbVar5[(int)param_3 - (int)pbVar2] * 0x100);
          }
          pbVar5 = pbVar5 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      param_3 = param_3 + local_4;
      pbVar2 = pbVar2 + local_14;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  return;
}

