// rea decompile_all
// name: FUN_004dc760
// address: 0x4dc760
// body: available
// range: 0x4dc760-0x4dc98e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004dc760(void *this,uint param_1)

{
  void *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  int local_4;
  
  this_00 = *(void **)(DAT_0057c5cc + 0x2c3d4);
  iVar1 = *(int *)(DAT_0057c5cc + 0x2c41c + param_1 * 4);
  local_4 = iVar1;
  FUN_00534060(this_00,iVar1,&local_c,&local_8,&local_14,&local_10);
  Record_GetScreenRect48(this_00,iVar1,(int *)&local_14,(int *)&local_10);
  uVar4 = FUN_004034d0(0,3);
  switch(uVar4) {
  case 0:
    iVar1 = *(int *)((int)this + 0xfa8);
    iVar3 = *(int *)(iVar1 + 0x30);
    local_18 = (*(int *)(iVar1 + 0x2c) - local_c) - local_14;
    uVar4 = *(int *)(iVar1 + 0x38) + DAT_0057195c;
    uVar5 = FUN_004034d0(iVar3,uVar4);
    *(undefined4 *)(DAT_0057c670 + 0x36c + param_1 * 4) = 4;
    uVar4 = (((int)uVar5 <= (int)(uVar4 - iVar3) / 2 + iVar3) - 1 & 2) + 2;
    param_1 = uVar5;
    break;
  case 1:
    iVar1 = *(int *)((int)this + 0xfa8);
    iVar3 = *(int *)(iVar1 + 0x30);
    local_18 = *(int *)(iVar1 + 0x34) + DAT_00571958;
    uVar4 = *(int *)(iVar1 + 0x38) + DAT_0057195c;
    uVar5 = FUN_004034d0(iVar3,uVar4);
    *(undefined4 *)(DAT_0057c670 + 0x36c + param_1 * 4) = 3;
    uVar4 = ((int)uVar5 <= (int)(uVar4 - iVar3) / 2 + iVar3) - 1 & 6;
    param_1 = uVar5;
    break;
  case 2:
    iVar1 = *(int *)((int)this + 0xfa8);
    iVar3 = *(int *)(iVar1 + 0x30);
    iVar2 = *(int *)(iVar1 + 0x2c);
    uVar4 = *(int *)(iVar1 + 0x34) + DAT_00571958;
    local_18 = FUN_004034d0(iVar2,uVar4);
    *(undefined4 *)(DAT_0057c670 + 0x36c + param_1 * 4) = 1;
    uVar4 = (((int)local_18 <= (int)(uVar4 - iVar2) / 2 + iVar2) - 1 & 0xfffffffe) + 2;
    param_1 = (iVar3 - local_8) - local_10;
    break;
  case 3:
    iVar1 = *(int *)((int)this + 0xfa8);
    iVar3 = *(int *)(iVar1 + 0x2c);
    uVar5 = *(int *)(iVar1 + 0x38) + DAT_0057195c;
    uVar4 = *(int *)(iVar1 + 0x34) + DAT_00571958;
    local_18 = FUN_004034d0(iVar3,uVar4);
    *(undefined4 *)(DAT_0057c670 + 0x36c + param_1 * 4) = 2;
    uVar4 = (((int)local_18 <= (int)(uVar4 - iVar3) / 2 + iVar3) - 1 & 2) + 4;
    param_1 = uVar5;
    break;
  default:
    uVar4 = param_1;
  }
  iVar1 = local_4;
  FUN_00534320((int)this_00,local_4,SUB84((double)(int)local_18,0),
               (int)((ulonglong)(double)(int)local_18 >> 0x20),(double)(int)param_1);
  FUN_00533aa0(this_00,iVar1,uVar4);
  return;
}

