// rea decompile_all
// name: FUN_005577d5
// address: 0x5577d5
// body: available
// range: 0x5577d5-0x55795b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl FUN_005577d5(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  uint *lpName;
  byte *pbVar5;
  int *piVar6;
  bool bVar7;
  
  if (param_1 == (uint *)0x0) {
    return 0xffffffff;
  }
  puVar1 = (uint *)FUN_00557a1b((byte *)param_1,0x3d);
  if (puVar1 == (uint *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == puVar1) {
    return 0xffffffff;
  }
  bVar7 = *(byte *)((int)puVar1 + 1) == 0;
  if (DAT_00585630 == DAT_00585634) {
    DAT_00585630 = FUN_005579b4(DAT_00585630);
  }
  if (DAT_00585630 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_00585638 == (undefined4 *)0x0)) {
      if (bVar7) {
        return 0;
      }
      DAT_00585630 = _malloc(4);
      if (DAT_00585630 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_00585630 = 0;
      if (DAT_00585638 == (undefined4 *)0x0) {
        DAT_00585638 = _malloc(4);
        if (DAT_00585638 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_00585638 = 0;
      }
    }
    else {
      iVar2 = FUN_00557050();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar3 = DAT_00585630;
  iVar2 = FUN_0055795c((uchar *)param_1,(int)puVar1 - (int)param_1);
  if ((iVar2 < 0) || (*piVar3 == 0)) {
    if (bVar7) {
      return 0;
    }
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    piVar3 = FUN_00551e0e(piVar3,(uint *)(iVar2 * 4 + 8));
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar3[iVar2] = (int)param_1;
    piVar3[iVar2 + 1] = 0;
  }
  else {
    if (!bVar7) {
      piVar3[iVar2] = (int)param_1;
      goto LAB_00557909;
    }
    piVar6 = piVar3 + iVar2;
    FUN_00551005((LPVOID)piVar3[iVar2]);
    for (; *piVar6 != 0; piVar6 = piVar6 + 1) {
      iVar2 = iVar2 + 1;
      *piVar6 = piVar6[1];
    }
    piVar3 = FUN_00551e0e(piVar3,(uint *)(iVar2 << 2));
    if (piVar3 == (int *)0x0) goto LAB_00557909;
  }
  DAT_00585630 = piVar3;
LAB_00557909:
  if (param_2 != 0) {
    sVar4 = _strlen((char *)param_1);
    lpName = _malloc(sVar4 + 2);
    if (lpName != (uint *)0x0) {
      _strcpy(lpName,param_1);
      pbVar5 = (byte *)(((int)lpName - (int)param_1) + (int)puVar1);
      *pbVar5 = 0;
      SetEnvironmentVariableA((LPCSTR)lpName,(LPCSTR)(~-(uint)bVar7 & (uint)(pbVar5 + 1)));
      FUN_00551005(lpName);
    }
  }
  return 0;
}

