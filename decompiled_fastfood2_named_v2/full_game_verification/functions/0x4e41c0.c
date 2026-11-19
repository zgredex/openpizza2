// rea decompile_all
// name: FurnitureType_InitTable
// address: 0x4e41c0
// body: available
// range: 0x4e41c0-0x4e42b3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FurnitureType_InitTable(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_ESI;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *local_10;
  int local_c;
  
  puVar6 = &DAT_0057dfdc;
                    /* Builds the furniture-type table and sprite-id mappings. */
  for (iVar2 = 0x9c4; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  if (DAT_0056d160 != 0xc) {
    local_10 = &DAT_0056d160;
    puVar6 = &DAT_00583770;
    do {
      puVar1 = operator_new(0xe8);
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = FurnitureType_Construct(puVar1);
      }
      piVar3 = local_10 + 0x1c;
      String_Format((undefined1 *)(local_10 + 4),(byte *)*puVar6,unaff_ESI);
      puVar6 = puVar6 + 1;
      local_c = 8;
      piVar4 = local_10;
      piVar7 = puVar1 + 2;
      for (iVar2 = 0x38; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar7 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar7 = piVar7 + 1;
      }
      do {
        iVar2 = 6;
        do {
          iVar5 = (int)(short)*piVar3;
          if (iVar5 != -1) {
            if (((undefined4 *)(&DAT_0057dfdc)[iVar5] != (undefined4 *)0x0) &&
               ((undefined4 *)(&DAT_0057dfdc)[iVar5] != puVar1)) {
              NoOp_Stub();
            }
            (&DAT_0057dfdc)[iVar5] = puVar1;
          }
          piVar3 = (int *)((int)piVar3 + 2);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        local_c = local_c + -1;
      } while (local_c != 0);
      List_Add((void *)(param_1 + 0x74),puVar1);
      local_10 = local_10 + 0x38;
    } while (*local_10 != 0xc);
  }
  return;
}

