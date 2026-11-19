// rea decompile_all
// name: FUN_005565a1
// address: 0x5565a1
// body: available
// range: 0x5565a1-0x55674d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl FUN_005565a1(int param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  BYTE *pBVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  _cpinfo local_1c;
  uint local_8;
  
  CRT_Lock(0x19);
  CodePage = FUN_0055674e(param_1);
  if (CodePage != DAT_005859ac) {
    if (CodePage != 0) {
      iVar12 = 0;
      pUVar5 = &DAT_00577218;
LAB_005565de:
      if (*pUVar5 != CodePage) goto code_r0x005565e2;
      local_8 = 0;
      puVar15 = &DAT_00585ac0;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      iVar12 = iVar12 * 0x30;
      *(undefined1 *)puVar15 = 0;
      pbVar13 = (byte *)(iVar12 + 0x577228);
      do {
        bVar3 = *pbVar13;
        pbVar11 = pbVar13;
        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
          uVar8 = (uint)*pbVar11;
          if (uVar8 <= bVar3) {
            bVar4 = (&DAT_00577210)[local_8];
            do {
              pbVar2 = (byte *)((int)&DAT_00585ac0 + uVar8 + 1);
              *pbVar2 = *pbVar2 | bVar4;
              uVar8 = uVar8 + 1;
            } while (uVar8 <= bVar3);
          }
          pbVar11 = pbVar11 + 2;
          bVar3 = *pbVar11;
        }
        local_8 = local_8 + 1;
        pbVar13 = pbVar13 + 8;
      } while (local_8 < 4);
      DAT_005859bc = 1;
      DAT_005859ac = CodePage;
      DAT_00585bc4 = FUN_00556798(CodePage);
      DAT_005859b0 = *(undefined4 *)(iVar12 + 0x57721c);
      DAT_005859b4 = *(undefined4 *)(iVar12 + 0x577220);
      DAT_005859b8 = *(undefined4 *)(iVar12 + 0x577224);
      goto LAB_00556732;
    }
    goto LAB_0055672d;
  }
  goto LAB_005565c8;
code_r0x005565e2:
  pUVar5 = pUVar5 + 0xc;
  iVar12 = iVar12 + 1;
  if (0x577307 < (int)pUVar5) goto code_r0x005565ed;
  goto LAB_005565de;
code_r0x005565ed:
  BVar6 = GetCPInfo(CodePage,&local_1c);
  uVar8 = 1;
  if (BVar6 == 1) {
    DAT_00585bc4 = 0;
    puVar15 = &DAT_00585ac0;
    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    *(undefined1 *)puVar15 = 0;
    if (local_1c.MaxCharSize < 2) {
      DAT_005859bc = 0;
      DAT_005859ac = CodePage;
    }
    else {
      DAT_005859ac = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar9;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            pbVar13 = (byte *)((int)&DAT_00585ac0 + uVar7 + 1);
            *pbVar13 = *pbVar13 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        pbVar13 = (byte *)((int)&DAT_00585ac0 + uVar8 + 1);
        *pbVar13 = *pbVar13 | 8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xff);
      DAT_00585bc4 = FUN_00556798(CodePage);
      DAT_005859bc = 1;
    }
    DAT_005859b0 = 0;
    DAT_005859b4 = 0;
    DAT_005859b8 = 0;
  }
  else {
    if (DAT_0058596c == 0) {
      uVar14 = 0xffffffff;
      goto LAB_0055673f;
    }
LAB_0055672d:
    FUN_005567cb();
  }
LAB_00556732:
  FUN_005567f4();
LAB_005565c8:
  uVar14 = 0;
LAB_0055673f:
  FUN_005539be(0x19);
  return uVar14;
}

