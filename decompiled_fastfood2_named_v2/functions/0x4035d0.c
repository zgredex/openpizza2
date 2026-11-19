// rea decompile_all
// name: FUN_004035d0
// address: 0x4035d0
// body: available
// range: 0x4035d0-0x403740 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_004035d0(void)

{
  char cVar1;
  int *piVar2;
  FILE *pFVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  undefined4 *puVar9;
  char *pcVar10;
  char *pcVar11;
  undefined1 local_res0;
  char cStack00000100;
  undefined4 uStack00000101;
  
  FUN_0054f110(local_res0);
  if (DAT_0057b558 != 0) {
    cStack00000100 = DAT_00579aec;
    puVar9 = &uStack00000101;
    for (iVar4 = 0x7ff; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    *(undefined2 *)puVar9 = 0;
    *(undefined1 *)((int)puVar9 + 2) = 0;
    iVar4 = 0;
    piVar2 = &DAT_00579b48;
    do {
      if (*piVar2 != 0) break;
      piVar2 = piVar2 + 1;
      iVar4 = iVar4 + 1;
    } while ((int)piVar2 < 0x579cd8);
    if (iVar4 != 100) {
      iVar4 = 0;
      do {
        if (*(int *)((int)&DAT_00579b48 + iVar4) != 0) {
          String_Format(&local_res0,(byte *)s____s___d_calls____ld_ms___ld_ave_005637c4,
                        *(undefined4 *)((int)&DAT_00579ffc + iVar4));
          uVar5 = 0xffffffff;
          pcVar8 = (char *)register0x00000010;
          do {
            pcVar11 = pcVar8;
            if (uVar5 == 0) break;
            uVar5 = uVar5 - 1;
            pcVar11 = pcVar8 + 1;
            cVar1 = *pcVar8;
            pcVar8 = pcVar11;
          } while (cVar1 != '\0');
          uVar5 = ~uVar5;
          iVar6 = -1;
          pcVar8 = &cStack00000100;
          do {
            pcVar10 = pcVar8;
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            pcVar10 = pcVar8 + 1;
            cVar1 = *pcVar8;
            pcVar8 = pcVar10;
          } while (cVar1 != '\0');
          pcVar8 = pcVar11 + -uVar5;
          pcVar11 = pcVar10 + -1;
          for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
            pcVar8 = pcVar8 + 4;
            pcVar11 = pcVar11 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pcVar11 = *pcVar8;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          }
          String_Format(&local_res0,(byte *)s___longest_call__d_ms___d_call__0056379c,
                        *(undefined4 *)((int)&DAT_0057b31c + iVar4));
          uVar5 = 0xffffffff;
          pcVar8 = (char *)register0x00000010;
          do {
            pcVar11 = pcVar8;
            if (uVar5 == 0) break;
            uVar5 = uVar5 - 1;
            pcVar11 = pcVar8 + 1;
            cVar1 = *pcVar8;
            pcVar8 = pcVar11;
          } while (cVar1 != '\0');
          uVar5 = ~uVar5;
          iVar6 = -1;
          pcVar8 = &cStack00000100;
          do {
            pcVar10 = pcVar8;
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            pcVar10 = pcVar8 + 1;
            cVar1 = *pcVar8;
            pcVar8 = pcVar10;
          } while (cVar1 != '\0');
          pcVar8 = pcVar11 + -uVar5;
          pcVar11 = pcVar10 + -1;
          for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
            pcVar8 = pcVar8 + 4;
            pcVar11 = pcVar11 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pcVar11 = *pcVar8;
            pcVar8 = pcVar8 + 1;
            pcVar11 = pcVar11 + 1;
          }
        }
        iVar4 = iVar4 + 4;
      } while (iVar4 < 400);
      MessageBoxA((HWND)0x0,&cStack00000100,s_Profile_Stat_s_0056378c,0x1000);
      pFVar3 = (FILE *)FUN_0054dfe0(s_profile_txt_0056377c,&DAT_00563788);
      if (pFVar3 != (FILE *)0x0) {
        FUN_0054df61(&cStack00000100,(int *)pFVar3);
        FUN_0054dee4(pFVar3);
      }
    }
  }
  return;
}

