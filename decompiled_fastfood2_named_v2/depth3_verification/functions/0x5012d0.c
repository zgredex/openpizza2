// rea decompile_all
// name: Game_AssignPlanStepWeight
// address: 0x5012d0
// body: available
// range: 0x5012d0-0x501528 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Game_AssignPlanStepWeight(void *this,undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
                    /* Depth-3 proposal batch 2. */
  puVar2 = param_2;
  iVar6 = 0;
  uVar3 = (uint)*(ushort *)(param_2 + 2);
  param_2 = (undefined4 *)0x0;
  iVar1 = *(int *)(*(int *)((int)this + uVar3 * 0x168 + 0x70) + 0x15c);
  puVar2[3] = param_1;
  switch(param_1) {
  case 4:
    puVar2[1] = 0x50;
    return;
  case 5:
    param_2 = (undefined4 *)0x14;
    if (0 < iVar1) {
      do {
        FUN_00500e80(this,(uint)*(ushort *)(puVar2 + 2),iVar6,1);
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar1);
      puVar2[1] = 0x14;
      return;
    }
    break;
  case 6:
    if (0 < iVar1) {
      uVar4 = FUN_00501980(this,uVar3);
      *puVar2 = uVar4;
      puVar2[1] = iVar1 * 0x14;
      return;
    }
    break;
  case 7:
    puVar2[1] = 0;
    return;
  case 8:
    if (0 < iVar1) {
      while ((iVar5 = FUN_00500e80(this,(uint)*(ushort *)(puVar2 + 2),iVar6,1), iVar5 == 0 ||
             ((*(byte *)(iVar5 + 0x28) & 4) == 0))) {
        iVar6 = iVar6 + 1;
        if (iVar1 <= iVar6) {
          puVar2[1] = 0;
          return;
        }
      }
      *puVar2 = *(undefined4 *)(iVar5 + 0x3c);
      puVar2[1] = 100;
      return;
    }
    break;
  case 10:
    if (0 < iVar1) {
      while ((iVar5 = FUN_00500e80(this,(uint)*(ushort *)(puVar2 + 2),iVar6,1), iVar5 == 0 ||
             ((*(byte *)(iVar5 + 0x28) & 0x10) != 0))) {
        iVar6 = iVar6 + 1;
        if (iVar1 <= iVar6) {
          puVar2[1] = 0;
          return;
        }
      }
      *puVar2 = *(undefined4 *)(iVar5 + 0x3c);
      puVar2[1] = 200;
      return;
    }
    break;
  case 0xb:
    puVar2[1] = 0x28;
    return;
  case 0xc:
    if (0 < iVar1) {
      do {
        iVar5 = FUN_00500e80(this,(uint)*(ushort *)(puVar2 + 2),iVar6,1);
        if ((iVar5 != 0) && ((*(byte *)(iVar5 + 0x28) & 8) == 0)) {
          puVar2[1] = 200;
          return;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar1);
    }
  case 9:
  case 0xd:
  case 0xf:
    puVar2[1] = 0x14;
    return;
  case 0xe:
    if (0 < iVar1) {
      uVar4 = FUN_00501980(this,uVar3);
      *puVar2 = uVar4;
      puVar2[1] = iVar1 * 5;
      return;
    }
    break;
  case 0x10:
  case 0x11:
    puVar2[1] = 0x32;
    return;
  case 0x12:
    puVar2[1] = 10;
    return;
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
    puVar2[1] = 0x1e;
    return;
  default:
    FUN_00501580(param_1);
    FUN_0048e0a0();
  }
  puVar2[1] = param_2;
  return;
}

