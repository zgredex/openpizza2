// rea decompile_all
// name: AI_ComputeWeightedPath
// address: 0x4f1750
// body: available
// range: 0x4f1750-0x4f1aae inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 AI_ComputeWeightedPath(void)

{
  void *this;
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  void *extraout_ECX;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ushort *puVar8;
  int *piVar9;
  void *pvVar10;
  uint *puVar11;
  int iVar12;
  undefined4 *puVar13;
  int iVar14;
  undefined4 *puVar15;
  undefined1 unaff_retaddr;
  uint uVar16;
  void *pvStack00000004;
  ushort *puStack00000008;
  uint uStack0000000c;
  int iStack00000010;
  int *piStack0000001c;
  short *psStack00000020;
  uint uStack00000024;
  undefined4 uStack00000028;
  undefined2 uStack0000002c;
  ushort uStack0000002e;
  ushort uStack00000030;
  int in_stack_00011c90;
  int in_stack_00011c94;
  void *in_stack_00011c98;
  int in_stack_00011c9c;
  ushort uStack_7ffffffe;
  uint auStack_7ffffffc [536870905];
  
                    /* Depth-2 proposal batch 5. */
  FUN_0054f110(unaff_retaddr);
  if (in_stack_00011c90 == in_stack_00011c94) {
    FUN_0054b3c0((int)in_stack_00011c98 + 0x14);
    return 1;
  }
  puVar8 = (ushort *)(uint)*(ushort *)(in_stack_00011c90 + 4);
  uStack00000028 = CONCAT22(uStack00000028._2_2_,*(undefined2 *)(in_stack_00011c94 + 4));
  puVar13 = (undefined4 *)((int)register0x00000010 + 0x610c);
  for (iVar5 = 12000; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar13 = 0xffffffff;
    puVar13 = puVar13 + 1;
  }
  uStack0000000c = 1;
  pvStack00000004 = extraout_ECX;
  puStack00000008 = puVar8;
  iVar5 = FUN_004edbd0(in_stack_00011c90);
  if (iVar5 == 0) {
    FUN_0048e0a0();
    return 0;
  }
  *(undefined4 *)((int)register0x00000010 + (int)puVar8 * 8 + 0x610c) = 0;
  *(undefined2 *)((int)register0x00000010 + (int)puVar8 * 8 + 0x6110) = 0;
  pvVar10 = extraout_ECX;
  while( true ) {
    uVar16 = 0;
    if ((int)uStack0000000c < 1) break;
    piStack0000001c = (int *)((int)register0x00000010 + 0x34c);
    uStack00000024 = uStack0000000c;
    do {
      uVar6 = uStack0000000c;
      iVar5 = *piStack0000001c;
      uVar7 = *(uint *)((int)register0x00000010 + iVar5 * 8 + 0x610c);
      iVar2 = FUN_004f0cc0(pvVar10,in_stack_00011c9c,iVar5);
      if (*(char *)(iVar2 + 6) == '\x02') {
        iVar12 = *(int *)((int)pvVar10 + 0x130);
        iVar14 = 0;
        if (0 < iVar12) {
          puVar11 = (uint *)((int)register0x00000010 + (uVar16 + uVar6) * 4 + 0x34c);
          do {
            iVar3 = FUN_004017f0((void *)((int)pvVar10 + 0x11c),iVar14,(int *)0x0);
            if (iVar3 != iVar2) {
              uVar6 = (uint)*(ushort *)(iVar3 + 4);
              if (uVar7 + 1 < *(uint *)((int)register0x00000010 + uVar6 * 8 + 0x610c)) {
                *(uint *)((int)register0x00000010 + uVar6 * 8 + 0x610c) = uVar7 + 1;
                *(short *)((int)register0x00000010 + uVar6 * 8 + 0x6110) = (short)iVar5;
                *puVar11 = uVar6;
                uVar16 = uVar16 + 1;
                puVar11 = puVar11 + 1;
              }
            }
            iVar14 = iVar14 + 1;
          } while (iVar14 < iVar12);
        }
      }
      psStack00000020 = (short *)(iVar2 + 0x14);
      iStack00000010 = 8;
      piVar9 = (int *)((int)register0x00000010 + (uVar16 + uStack0000000c) * 4 + 0x34c);
      do {
        if (*psStack00000020 != -1) {
          iVar12 = (int)*psStack00000020;
          uVar6 = *(uint *)((int)register0x00000010 + iVar12 * 8 + 0x610c);
          if (uVar7 < uVar6) {
            iVar14 = FUN_004f0cc0(pvStack00000004,in_stack_00011c9c,iVar12);
            iVar14 = FUN_004ed500(pvStack00000004,iVar2,iVar14);
            if (iVar14 + uVar7 < uVar6) {
              *(uint *)((int)register0x00000010 + iVar12 * 8 + 0x610c) = iVar14 + uVar7;
              uVar16 = uVar16 + 1;
              *piVar9 = iVar12;
              *(short *)((int)register0x00000010 + iVar12 * 8 + 0x6110) = (short)iVar5;
              piVar9 = piVar9 + 1;
            }
          }
        }
        psStack00000020 = psStack00000020 + 1;
        iStack00000010 = iStack00000010 + -1;
      } while (iStack00000010 != 0);
      piStack0000001c = piStack0000001c + 1;
      uStack00000024 = uStack00000024 - 1;
      pvVar10 = pvStack00000004;
    } while (uStack00000024 != 0);
    puVar8 = puStack00000008;
    if (uVar16 == 0) break;
    puVar13 = (undefined4 *)((int)register0x00000010 + uStack0000000c * 4 + 0x34c);
    puVar15 = (undefined4 *)((int)register0x00000010 + 0x34c);
    for (uVar7 = uVar16 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar15 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar15 = puVar15 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar15 = *(undefined1 *)puVar13;
      puVar13 = (undefined4 *)((int)puVar13 + 1);
      puVar15 = (undefined4 *)((int)puVar15 + 1);
    }
    uStack0000000c = uVar16;
  }
  iVar5 = (uStack00000028 & 0xffff) * 8;
  if (*(int *)((int)register0x00000010 + iVar5 + 0x610c) == -1) {
    return 0;
  }
  uStack0000002c = (short)uStack00000028;
  uStack0000002e = *(ushort *)((int)register0x00000010 + iVar5 + 0x6110);
  puVar4 = (ushort *)(uint)uStack0000002e;
  iVar5 = 2;
  if (puVar4 != puVar8) {
    puStack00000008 = &uStack00000030;
    do {
      if (399 < iVar5) {
        FUN_0048e0a0();
      }
      iVar5 = iVar5 + 1;
      uVar1 = *(ushort *)((int)register0x00000010 + (int)puVar4 * 8 + 0x6110);
      puVar4 = (ushort *)(uint)uVar1;
      *puStack00000008 = uVar1;
      puStack00000008 = puStack00000008 + 1;
    } while (puVar4 != puVar8);
  }
  this = (void *)((int)in_stack_00011c98 + 0x14);
  FUN_0054b3c0((int)this);
  if (0 < iVar5) {
    puVar8 = (ushort *)((int)&uStack00000028 + iVar5 * 2 + 2);
    do {
      iVar2 = FUN_004f0cc0(pvVar10,in_stack_00011c9c,(uint)*puVar8);
      FUN_0054b3d0(this,iVar2);
      puVar8 = puVar8 + -1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  FUN_004f5c70(in_stack_00011c98,0);
  return 1;
}

