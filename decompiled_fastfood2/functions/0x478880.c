// rea decompile_all
// name: FUN_00478880
// address: 0x478880
// body: available
// range: 0x478880-0x478ad1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00478880(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  longlong lVar10;
  char *local_1c;
  int *local_18;
  int local_14 [5];
  
  iVar8 = 0;
  iVar5 = *(int *)((int)param_1 + 0x1514);
  uVar6 = 0;
  local_1c = (char *)((int)param_1 + 0x1a08);
  local_14[4] = 0;
  local_14[0] = 0;
  local_14[1] = 0;
  local_14[2] = 0;
  local_14[3] = 0;
  do {
    if ((*local_1c != '\0') && (iVar7 = 0, 0 < iVar5)) {
      do {
        puVar2 = (undefined4 *)FUN_004017f0((void *)((int)param_1 + 0x1500),iVar7,(int *)0x0);
        FUN_00477120(param_1,(int *)*puVar2,uVar6);
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar5);
    }
    uVar6 = uVar6 + 1;
    local_1c = local_1c + 3;
  } while ((int)uVar6 < 8);
  lVar10 = __ftol();
  iVar7 = 0;
  FUN_0047e520(param_1);
  local_18 = (int *)0x0;
  if (0 < iVar5) {
    do {
      piVar3 = (int *)FUN_004017f0((void *)((int)param_1 + 0x1500),iVar7,(int *)0x0);
      iVar1 = *piVar3;
      if (*(char *)(iVar1 + 0x824) == '\x01') {
        local_18 = (int *)iVar1;
      }
      local_14[0] = local_14[0] + *(int *)(iVar1 + 4);
      iVar4 = FUN_004d3fc0(iVar1);
      local_14[1] = local_14[1] + iVar4;
      local_14[2] = local_14[2] + *(int *)(iVar1 + 0xc);
      iVar4 = FUN_004d3fe0(iVar1);
      iVar8 = iVar8 + *(int *)(iVar1 + 0x38);
      iVar7 = iVar7 + 1;
      local_14[3] = local_14[3] + iVar4;
    } while (iVar7 < iVar5);
    local_14[4] = iVar8;
  }
  *(int **)((int)param_1 + 0x14c4) = local_18;
  puVar2 = (undefined4 *)((int)param_1 + 0x17bc);
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  if (iVar7 != 0) {
    iVar5 = 5;
    piVar3 = local_14;
    do {
      iVar5 = iVar5 + -1;
      *piVar3 = *piVar3 / iVar7;
      piVar3 = piVar3 + 1;
    } while (iVar5 != 0);
    local_18 = local_14;
    piVar3 = &DAT_005675b8;
    do {
      piVar9 = (int *)((int)param_1 + 0x17bc);
      iVar8 = 8;
      iVar5 = *local_18;
      do {
        iVar7 = iVar5 - *piVar3;
        if (iVar7 < 0) {
          iVar7 = *piVar9 + (iVar7 >> 2) + 0x19;
        }
        else {
          iVar7 = *piVar9 + iVar7 / 5 + 0x19;
        }
        *piVar9 = iVar7;
        piVar3 = piVar3 + 1;
        piVar9 = piVar9 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      local_18 = local_18 + 1;
    } while ((int)piVar3 < 0x567638);
    piVar9 = &DAT_00567678;
    piVar3 = (int *)((int)param_1 + 0x17bc);
    do {
      uVar6 = local_14[4] - piVar9[-0x10] >> 0x1f;
      iVar8 = *piVar3 - ((local_14[4] - piVar9[-0x10] ^ uVar6) - uVar6);
      *piVar3 = iVar8;
      iVar5 = (int)lVar10 - *piVar9;
      if (iVar5 < 0) {
        *piVar3 = iVar8 + iVar5 * 3;
      }
      iVar5 = FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x30));
      iVar5 = *(int *)(iVar5 + 100);
      iVar8 = FUN_00480060((int)param_1);
      iVar5 = iVar8 * iVar5 - piVar9[-8];
      if (0 < iVar5) {
        *piVar3 = *piVar3 + iVar5 * -3;
      }
      iVar5 = FUN_0047aba0((int)param_1);
      piVar9 = piVar9 + 1;
      *piVar3 = *piVar3 + iVar5;
      piVar3 = piVar3 + 1;
    } while ((int)piVar9 < 0x567698);
  }
  return;
}

