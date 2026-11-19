// rea decompile_all
// name: FUN_004025e0
// address: 0x4025e0
// body: available
// range: 0x4025e0-0x402748 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


HANDLE __thiscall FUN_004025e0(void *this,char *param_1)

{
  char cVar1;
  HANDLE pvVar2;
  DWORD DVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  int local_210;
  int local_20c;
  char local_208 [260];
  undefined4 local_104;
  
  FUN_00402b80(this,param_1,&local_104);
  if (*(int *)((int)this + 0x1ab8) != 0) {
    if (local_104._1_1_ == ':') {
      local_208[0] = '\0';
    }
    else {
      uVar4 = 0xffffffff;
      pcVar7 = (char *)((int)this + 0x19b0);
      do {
        pcVar9 = pcVar7;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar7 = pcVar9 + -uVar4;
      pcVar9 = local_208;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
    }
    uVar4 = 0xffffffff;
    pcVar7 = (char *)&local_104;
    do {
      pcVar9 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar6 = -1;
    pcVar7 = local_208;
    do {
      pcVar8 = pcVar7;
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    pcVar7 = pcVar9 + -uVar4;
    pcVar9 = pcVar8 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
    pvVar2 = CreateFileA(local_208,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (pvVar2 != (HANDLE)0xffffffff) {
      return pvVar2;
    }
  }
  iVar6 = FUN_00402060(this,(byte *)&local_104,&local_210,&local_20c);
  if (((iVar6 != 0) && (*(int *)((local_210 * 9 + 9) * 0x20 + (int)this) != 0)) &&
     (pvVar2 = CreateFileA((LPCSTR)(local_210 * 0x120 + 0xc + (int)this),0x80000000,1,
                           (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0),
     pvVar2 != (HANDLE)0xffffffff)) {
    DVar3 = SetFilePointer(pvVar2,*(int *)(*(int *)(local_210 * 0x120 + 0x114 + (int)this) + 0xc +
                                          local_20c * 0x14) + 0x6c,(PLONG)0x0,0);
    if (DVar3 != 0xffffffff) {
      return pvVar2;
    }
    CloseHandle(pvVar2);
  }
  return (HANDLE)0xffffffff;
}

