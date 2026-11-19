// rea decompile_all
// name: FUN_004f14a0
// address: 0x4f14a0
// body: available
// range: 0x4f14a0-0x4f1741 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_004f14a0(void)

{
  ushort uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  void *extraout_ECX;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ushort *puVar8;
  int *piVar9;
  uint *puVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined1 unaff_retaddr;
  uint uVar15;
  uint uStack00000004;
  int iStack00000008;
  void *pvStack0000000c;
  int *piStack00000010;
  uint uStack00000014;
  short *psStack0000001c;
  uint uStack00000020;
  uint uStack00000024;
  int iStack0000002c;
  int in_stack_00011970;
  int in_stack_00011974;
  ushort *in_stack_00011978;
  ushort uStack_7ffffffe;
  uint auStack_7ffffffc [536870905];
  
  FUN_0054f110(unaff_retaddr);
  uVar6 = (uint)*(ushort *)(in_stack_00011970 + 4);
  uVar1 = *(ushort *)(in_stack_00011974 + 4);
  puVar12 = (undefined4 *)((int)register0x00000010 + 0x5dec);
  for (iVar5 = 12000; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar12 = 0xffffffff;
    puVar12 = puVar12 + 1;
  }
  uStack00000004 = 1;
  pvStack0000000c = extraout_ECX;
  uStack00000024 = uVar6;
  iStack0000002c = uVar6;
  iVar5 = FUN_004edbd0(in_stack_00011970);
  if (iVar5 == 0) {
    return 0;
  }
  *(undefined4 *)((int)register0x00000010 + uVar6 * 8 + 0x5dec) = 0;
  *(undefined2 *)((int)register0x00000010 + uVar6 * 8 + 0x5df0) = 0;
  while( true ) {
    uVar15 = 0;
    if ((int)uStack00000004 < 1) break;
    piStack00000010 = &iStack0000002c;
    uStack00000020 = uStack00000004;
    do {
      pvVar2 = pvStack0000000c;
      uVar6 = uStack00000004;
      iVar5 = *piStack00000010;
      uStack00000014 = *(uint *)((int)register0x00000010 + iVar5 * 8 + 0x5dec);
      iVar3 = FUN_004f0cc0(pvStack0000000c,1,iVar5);
      if (*(char *)(iVar3 + 6) == '\x02') {
        iVar11 = *(int *)((int)pvVar2 + 0x130);
        iVar13 = 0;
        if (0 < iVar11) {
          puVar10 = (uint *)((int)&iStack0000002c + (uVar15 + uVar6) * 4);
          do {
            iVar4 = FUN_004017f0((void *)((int)pvVar2 + 0x11c),iVar13,(int *)0x0);
            if (iVar4 != iVar3) {
              uVar6 = (uint)*(ushort *)(iVar4 + 4);
              if (uStack00000014 + 1 < *(uint *)((int)register0x00000010 + uVar6 * 8 + 0x5dec)) {
                *(uint *)((int)register0x00000010 + uVar6 * 8 + 0x5dec) = uStack00000014 + 1;
                *(short *)((int)register0x00000010 + uVar6 * 8 + 0x5df0) = (short)iVar5;
                *puVar10 = uVar6;
                uVar15 = uVar15 + 1;
                puVar10 = puVar10 + 1;
              }
            }
            iVar13 = iVar13 + 1;
          } while (iVar13 < iVar11);
        }
      }
      psStack0000001c = (short *)(iVar3 + 0x14);
      iStack00000008 = 8;
      piVar9 = (int *)((int)&iStack0000002c + (uVar15 + uStack00000004) * 4);
      do {
        if (*psStack0000001c != -1) {
          iVar11 = (int)*psStack0000001c;
          uVar6 = *(uint *)((int)register0x00000010 + iVar11 * 8 + 0x5dec);
          if (uStack00000014 < uVar6) {
            iVar13 = FUN_004f0cc0(pvStack0000000c,1,iVar11);
            iVar13 = FUN_004ed500(pvStack0000000c,iVar3,iVar13);
            if (iVar13 + uStack00000014 < uVar6) {
              *(uint *)((int)register0x00000010 + iVar11 * 8 + 0x5dec) = iVar13 + uStack00000014;
              uVar15 = uVar15 + 1;
              *piVar9 = iVar11;
              *(short *)((int)register0x00000010 + iVar11 * 8 + 0x5df0) = (short)iVar5;
              piVar9 = piVar9 + 1;
            }
          }
        }
        psStack0000001c = psStack0000001c + 1;
        iStack00000008 = iStack00000008 + -1;
      } while (iStack00000008 != 0);
      piStack00000010 = piStack00000010 + 1;
      uStack00000020 = uStack00000020 - 1;
    } while (uStack00000020 != 0);
    uVar6 = uStack00000024;
    if (uVar15 == 0) break;
    puVar12 = (undefined4 *)((int)&iStack0000002c + uStack00000004 * 4);
    puVar14 = &iStack0000002c;
    for (uVar7 = uVar15 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar14 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar14 = puVar14 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar14 = *(undefined1 *)puVar12;
      puVar12 = (undefined4 *)((int)puVar12 + 1);
      puVar14 = (undefined4 *)((int)puVar14 + 1);
    }
    uStack00000004 = uVar15;
  }
  iVar3 = (uint)uVar1 * 8;
  iVar5 = *(int *)((int)register0x00000010 + iVar3 + 0x5dec);
  if (iVar5 == -1) {
    return 0;
  }
  if (in_stack_00011978 != (ushort *)0x0) {
    *in_stack_00011978 = uVar1;
    uVar1 = *(ushort *)((int)register0x00000010 + iVar3 + 0x5df0);
    uVar15 = (uint)uVar1;
    iVar5 = 2;
    in_stack_00011978[1] = uVar1;
    if (uVar15 != uVar6) {
      puVar8 = in_stack_00011978 + 2;
      do {
        if (399 < iVar5) {
          return iVar5;
        }
        iVar5 = iVar5 + 1;
        uVar1 = *(ushort *)((int)register0x00000010 + uVar15 * 8 + 0x5df0);
        uVar15 = (uint)uVar1;
        *puVar8 = uVar1;
        puVar8 = puVar8 + 1;
      } while (uVar15 != uVar6);
    }
  }
  return iVar5;
}

