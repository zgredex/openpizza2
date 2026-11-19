// rea decompile_all
// name: FUN_00556a1e
// address: 0x556a1e
// body: available
// range: 0x556a1e-0x556b9f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl FUN_00556a1e(DWORD *param_1)

{
  bool bVar1;
  DWORD *pDVar2;
  uint uVar3;
  int iVar4;
  DWORD DVar5;
  DWORD extraout_ECX;
  int iVar6;
  code *pcVar7;
  DWORD *pDVar8;
  DWORD local_10;
  DWORD local_c;
  
  bVar1 = false;
  if (param_1 == (DWORD *)0x2) {
    pDVar8 = (DWORD *)&DAT_0058597c;
    pcVar7 = DAT_0058597c;
LAB_00556aa4:
    bVar1 = true;
    CRT_Lock(1);
    pDVar2 = param_1;
  }
  else {
    if (((param_1 != (DWORD *)0x4) && (param_1 != (DWORD *)0x8)) && (param_1 != (DWORD *)0xb)) {
      if (param_1 == (DWORD *)0xf) {
        pDVar8 = (DWORD *)&DAT_00585988;
        pcVar7 = DAT_00585988;
      }
      else if (param_1 == (DWORD *)0x15) {
        pDVar8 = (DWORD *)&DAT_00585980;
        pcVar7 = DAT_00585980;
      }
      else {
        if (param_1 != (DWORD *)0x16) {
          return 0xffffffff;
        }
        pDVar8 = (DWORD *)&DAT_00585984;
        pcVar7 = DAT_00585984;
      }
      goto LAB_00556aa4;
    }
    pDVar2 = CRT_GetThreadData();
    uVar3 = FUN_00556ba0((int)param_1,pDVar2[0x14]);
    pDVar8 = (DWORD *)(uVar3 + 8);
    pcVar7 = (code *)*pDVar8;
  }
  if (pcVar7 == (code *)0x1) {
    if (bVar1) {
      CS_LeaveIndexed(1);
      return 0;
    }
    return 0;
  }
  DVar5 = 0;
  if (pcVar7 == (code *)0x0) {
    if (bVar1) {
      CS_LeaveIndexed(1);
    }
    __exit(3);
    DVar5 = extraout_ECX;
  }
  if (((param_1 == (DWORD *)0x8) || (param_1 == (DWORD *)0xb)) || (param_1 == (DWORD *)0x4)) {
    local_c = pDVar2[0x15];
    pDVar2[0x15] = DVar5;
    if (param_1 == (DWORD *)0x8) {
      local_10 = pDVar2[0x16];
      pDVar2[0x16] = 0x8c;
      goto LAB_00556b18;
    }
  }
  else {
LAB_00556b18:
    if (param_1 == (DWORD *)0x8) {
      if (DAT_005770b8 < DAT_005770bc + DAT_005770b8) {
        iVar4 = DAT_005770b8 * 0xc;
        iVar6 = DAT_005770b8;
        do {
          iVar4 = iVar4 + 0xc;
          *(undefined4 *)((pDVar2[0x14] - 4) + iVar4) = 0;
          iVar6 = iVar6 + 1;
        } while (iVar6 < DAT_005770bc + DAT_005770b8);
      }
      goto LAB_00556b56;
    }
  }
  *pDVar8 = DVar5;
LAB_00556b56:
  if (bVar1) {
    CS_LeaveIndexed(1);
  }
  if (param_1 == (DWORD *)0x8) {
    (*pcVar7)(8,pDVar2[0x16]);
  }
  else {
    (*pcVar7)(param_1);
    if ((param_1 != (DWORD *)0xb) && (param_1 != (DWORD *)0x4)) {
      return 0;
    }
  }
  pDVar2[0x15] = local_c;
  if (param_1 == (DWORD *)0x8) {
    pDVar2[0x16] = local_10;
  }
  return 0;
}

