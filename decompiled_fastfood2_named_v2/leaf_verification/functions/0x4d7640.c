// rea decompile_all
// name: FUN_004d7640
// address: 0x4d7640
// body: available
// range: 0x4d7640-0x4d7777 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall
FUN_004d7640(void *this,char param_1,uint param_2,int param_3,uint *param_4,int *param_5)

{
  uint uVar1;
  byte bVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  float10 fVar7;
  int local_8;
  uint local_4;
  
  puVar3 = param_4;
  iVar4 = 0;
  iVar6 = 0;
  bVar2 = (char)*(undefined4 *)(param_3 + 0xd0) - 1;
  local_4 = CONCAT31(local_4._1_3_,bVar2);
  local_8 = 0;
  uVar1 = Market_GetPriceDelta(this,local_4);
  param_4 = (uint *)0x0;
  *puVar3 = uVar1;
  uVar5 = param_2 & 0xff;
  param_2 = 6;
  puVar3 = (uint *)((int)this + uVar5 * 0x18 + 0xfe4);
  do {
    if (*puVar3 == (uint)bVar2) {
      param_4 = (uint *)((int)param_4 + 10);
    }
    puVar3 = puVar3 + 1;
    param_2 = param_2 - 1;
  } while (param_2 != 0);
  *param_5 = (int)param_4;
  if (param_1 != '\0') {
    iVar6 = (int)*(char *)(param_3 + 0xcd);
    switch(uVar5 - 2) {
    case 0:
    case 2:
      iVar6 = iVar6 * 5;
      break;
    case 1:
    case 4:
      iVar6 = iVar6 * -10;
      break;
    case 3:
    case 5:
      iVar6 = iVar6 * 10;
      break;
    default:
      iVar6 = 0;
    }
    switch(uVar5 - 2) {
    case 0:
    case 4:
      iVar4 = *(char *)(param_3 + 0xcc) * 5;
      break;
    default:
      iVar4 = 0;
      break;
    case 2:
    case 3:
      iVar4 = *(char *)(param_3 + 0xcc) * 10;
    }
    fVar7 = Rating_GetFloat((int)this,uVar5);
    if (fVar7 / ((float10)*(int *)(&DAT_0056ccec + uVar5 * 4) * (float10)0.01) <
        (float10)*(double *)(param_3 + 0xc0)) {
      local_8 = -1000;
    }
  }
  return (int)param_4 + iVar6 + iVar4 + local_8 + uVar1;
}

