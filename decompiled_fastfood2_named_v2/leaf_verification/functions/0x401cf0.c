// rea decompile_all
// name: FUN_00401cf0
// address: 0x401cf0
// body: available
// range: 0x401cf0-0x401f2d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00401cf0(void *this,LPCSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char cVar3;
  int *piVar4;
  HRSRC hResInfo;
  HGLOBAL hResData;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  char local_6c [96];
  uint local_c;
  int local_8;
  int local_4;
  
  iVar1 = (int)this + 0x1688;
  CS_Enter(iVar1);
  if (0x13 < *(int *)((int)this + 0x1684)) {
    NoOp_Stub();
    CS_Leave(iVar1);
    return 0;
  }
  puVar2 = (undefined4 *)(*(int *)((int)this + 0x1684) * 0x120 + 4 + (int)this);
  puVar5 = puVar2 + 2;
  for (iVar7 = 0x41; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  hResInfo = FindResourceA((HMODULE)0x0,param_1,s_ResourceFiles_005631d8);
  if (hResInfo == (HRSRC)0x0) {
    CS_Leave(iVar1);
    return 0;
  }
  hResData = LoadResource((HMODULE)0x0,hResInfo);
  if (hResData == (HGLOBAL)0x0) {
    CS_Leave(iVar1);
    return 0;
  }
  puVar5 = LockResource(hResData);
  puVar2[0x46] = puVar5;
  if (puVar5 == (undefined4 *)0x0) {
    CS_Leave(iVar1);
    return 0;
  }
  puVar2[0x47] = 0;
  *puVar2 = 0;
  puVar6 = puVar5;
  pcVar10 = local_6c;
  for (iVar7 = 0x1b; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined4 *)pcVar10 = *puVar6;
    puVar6 = puVar6 + 1;
    pcVar10 = pcVar10 + 4;
  }
  uVar8 = 0xffffffff;
  pcVar10 = s_ResourceFile_ID_7654_0056316c;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar3 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar3 != '\0');
  iVar7 = _strncmp(local_6c,s_ResourceFile_ID_7654_0056316c,~uVar8 - 1);
  if (iVar7 != 0) {
    CS_Leave(iVar1);
    return 0;
  }
  if (100 < local_8) {
    NoOp_Stub();
    CS_Leave(iVar1);
    return 0;
  }
  puVar6 = operator_new(local_c);
  puVar2[1] = puVar6;
  puVar5 = puVar5 + 0x1b;
  for (uVar8 = local_c >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  for (uVar8 = local_c & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  if (local_4 != 0) {
    Pak_DecodeIndex(puVar2[1],local_c);
    piVar4 = (int *)puVar2[1];
    puVar2[0x43] = piVar4;
    puVar2[0x44] = piVar4 + 1;
    puVar2[0x45] = piVar4 + *piVar4 * 5 + 1;
  }
  iVar7 = 0;
  if (0 < *(int *)puVar2[0x43]) {
    iVar9 = 0;
    do {
      iVar7 = iVar7 + 1;
      *(int *)(iVar9 + 0x10 + puVar2[0x44]) = *(int *)(iVar9 + 0x10 + puVar2[0x44]) + puVar2[0x45];
      iVar9 = iVar9 + 0x14;
    } while (iVar7 < *(int *)puVar2[0x43]);
  }
  FUN_00402240((int *)puVar2[0x44],*(undefined4 **)puVar2[0x43]);
  *(int *)((int)this + 0x1684) = *(int *)((int)this + 0x1684) + 1;
  CS_Leave(iVar1);
  return 1;
}

