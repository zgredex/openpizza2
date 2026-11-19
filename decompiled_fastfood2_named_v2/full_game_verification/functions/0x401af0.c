// rea decompile_all
// name: Pak_Open
// address: 0x401af0
// body: available
// range: 0x401af0-0x401ce0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall Pak_Open(void *this,LPCSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  char local_6c [96];
  uint local_c;
  int local_8;
  int local_4;
  
  iVar1 = (int)this + 0x1688;
  CS_Enter(iVar1);
  if (0x13 < *(int *)((int)this + 0x1684)) {
    CS_Leave(iVar1);
    return 0;
  }
  puVar2 = (undefined4 *)(*(int *)((int)this + 0x1684) * 0x120 + 4 + (int)this);
  *(undefined4 *)((int)this + 0x1ac0) = 0;
  uVar5 = CRT_Fopen(param_1,&DAT_00563184);
  *puVar2 = uVar5;
  uVar8 = 0xffffffff;
  do {
    pcVar7 = param_1;
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    pcVar7 = param_1 + 1;
    cVar3 = *param_1;
    param_1 = pcVar7;
  } while (cVar3 != '\0');
  uVar8 = ~uVar8;
  pcVar7 = pcVar7 + -uVar8;
  pcVar11 = (char *)(puVar2 + 2);
  for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined4 *)pcVar11 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar11 = pcVar11 + 4;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *pcVar11 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar11 = pcVar11 + 1;
  }
  if ((int *)*puVar2 == (int *)0x0) {
    CS_Leave(iVar1);
    return 0;
  }
  puVar2[0x47] = 1;
  CRT_FreadLocked(local_6c,1,0x6c,(int *)*puVar2);
  uVar8 = 0xffffffff;
  pcVar7 = s_ResourceFile_ID_7654_0056316c;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar3 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar3 != '\0');
  iVar6 = _strncmp(local_6c,s_ResourceFile_ID_7654_0056316c,~uVar8 - 1);
  if (iVar6 != 0) {
    CS_Leave(iVar1);
    CRT_Fclose((FILE *)*puVar2);
    return 0;
  }
  if (100 < local_8) {
    CRT_Fclose((FILE *)*puVar2);
    CS_Leave(iVar1);
    return 0;
  }
  pcVar7 = operator_new(local_c);
  puVar2[1] = pcVar7;
  CRT_FreadLocked(pcVar7,1,local_c,(int *)*puVar2);
  if (local_4 != 0) {
    Pak_DecodeIndex(puVar2[1],local_c);
    piVar4 = (int *)puVar2[1];
    puVar2[0x43] = piVar4;
    puVar2[0x44] = piVar4 + 1;
    puVar2[0x45] = piVar4 + *piVar4 * 5 + 1;
  }
  iVar6 = 0;
  if (0 < *(int *)puVar2[0x43]) {
    iVar10 = 0;
    do {
      iVar6 = iVar6 + 1;
      *(int *)(iVar10 + 0x10 + puVar2[0x44]) = *(int *)(iVar10 + 0x10 + puVar2[0x44]) + puVar2[0x45]
      ;
      iVar10 = iVar10 + 0x14;
    } while (iVar6 < *(int *)puVar2[0x43]);
  }
  Pak_SortEntries((int *)puVar2[0x44],*(undefined4 **)puVar2[0x43]);
  *(int *)((int)this + 0x1684) = *(int *)((int)this + 0x1684) + 1;
  CS_Leave(iVar1);
  return 1;
}

