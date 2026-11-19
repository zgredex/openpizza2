// rea decompile_all
// name: Resource_Open
// address: 0x402290
// body: available
// range: 0x402290-0x4025d7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int * __thiscall Resource_Open(void *this,char *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  int local_210;
  int local_20c;
  char local_208 [260];
  undefined4 local_104;
  
                    /* Central resource opener: resolves a name through Pak_FindEntry or falls back
                       to a filesystem file. */
  iVar1 = (int)this + 0x1688;
  FUN_00401320(iVar1);
  FUN_00402b80(this,param_1,&local_104);
  piVar3 = (int *)ResourceHandle_Alloc((int)this);
  if (piVar3 == (int *)0x0) {
    FUN_00401340(iVar1);
    if (param_2 != 0) {
      FUN_0048e0a0();
    }
    return (int *)0x0;
  }
  if (*(int *)((int)this + 0x1ab8) != 0) {
    if (local_104._1_1_ == ':') {
      local_208[0] = '\0';
    }
    else {
      uVar5 = 0xffffffff;
      pcVar8 = (char *)((int)this + 0x19b0);
      do {
        pcVar10 = pcVar8;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar10 = pcVar8 + 1;
        cVar2 = *pcVar8;
        pcVar8 = pcVar10;
      } while (cVar2 != '\0');
      uVar5 = ~uVar5;
      pcVar8 = pcVar10 + -uVar5;
      pcVar10 = local_208;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar10 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar10 = pcVar10 + 1;
      }
    }
    uVar5 = 0xffffffff;
    pcVar8 = (char *)&local_104;
    do {
      pcVar10 = pcVar8;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar10 = pcVar8 + 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar10;
    } while (cVar2 != '\0');
    uVar5 = ~uVar5;
    *(undefined4 *)((int)this + 0x1ac0) = 0;
    iVar7 = -1;
    pcVar8 = local_208;
    do {
      pcVar9 = pcVar8;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar9 = pcVar8 + 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar9;
    } while (cVar2 != '\0');
    pcVar8 = pcVar10 + -uVar5;
    pcVar10 = pcVar9 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar10 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar10 = pcVar10 + 1;
    }
    piVar4 = (int *)FUN_0054dfe0(local_208,&DAT_00563184);
    if (piVar4 != (int *)0x0) {
      FUN_0054ede0(piVar4,0,2);
      iVar7 = FUN_0054ec5d((char *)piVar4);
      piVar3[2] = iVar7;
      FUN_0054ede0(piVar4,0,0);
      piVar3[3] = 0;
      *piVar3 = -1;
      piVar3[1] = -1;
      piVar3[4] = 0;
      piVar3[6] = (int)piVar4;
      piVar3[7] = 1;
      FUN_00401340(iVar1);
      return piVar3;
    }
  }
  iVar7 = Pak_FindEntry(this,(byte *)&local_104,&local_20c,&local_210);
  if (iVar7 != 0) {
    piVar3[2] = *(int *)(*(int *)(local_20c * 0x120 + 0x114 + (int)this) + 8 + local_210 * 0x14);
    piVar3[3] = *(int *)(*(int *)(local_20c * 0x120 + 0x114 + (int)this) + 0xc + local_210 * 0x14) +
                0x6c;
    *piVar3 = local_20c;
    piVar3[1] = local_210;
    piVar3[4] = 0;
    if (*(int *)((local_20c * 9 + 9) * 0x20 + (int)this) == 0) {
      piVar3[6] = 0;
      piVar3[7] = 2;
      piVar3[8] = *(int *)(local_20c * 0x120 + 0x11c + (int)this);
    }
    else {
      iVar7 = *(int *)(local_20c * 0x120 + 4 + (int)this);
      piVar3[7] = 0;
      piVar3[6] = iVar7;
      piVar3[8] = 0;
    }
    FUN_00401340(iVar1);
    return piVar3;
  }
  if (*(int *)((int)this + 0x1ab8) == 0) {
    if (local_104._1_1_ == ':') {
      local_208[0] = '\0';
    }
    else {
      uVar5 = 0xffffffff;
      pcVar8 = (char *)((int)this + 0x19b0);
      do {
        pcVar10 = pcVar8;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar10 = pcVar8 + 1;
        cVar2 = *pcVar8;
        pcVar8 = pcVar10;
      } while (cVar2 != '\0');
      uVar5 = ~uVar5;
      pcVar8 = pcVar10 + -uVar5;
      pcVar10 = local_208;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar10 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar10 = pcVar10 + 1;
      }
    }
    uVar5 = 0xffffffff;
    pcVar8 = (char *)&local_104;
    do {
      pcVar10 = pcVar8;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar10 = pcVar8 + 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar10;
    } while (cVar2 != '\0');
    uVar5 = ~uVar5;
    *(undefined4 *)((int)this + 0x1ac0) = 0;
    iVar7 = -1;
    pcVar8 = local_208;
    do {
      pcVar9 = pcVar8;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar9 = pcVar8 + 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar9;
    } while (cVar2 != '\0');
    pcVar8 = pcVar10 + -uVar5;
    pcVar10 = pcVar9 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar10 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar10 = pcVar10 + 1;
    }
    piVar4 = (int *)FUN_0054dfe0(local_208,&DAT_00563184);
    if (piVar4 != (int *)0x0) {
      FUN_0054ede0(piVar4,0,2);
      iVar7 = FUN_0054ec5d((char *)piVar4);
      piVar3[2] = iVar7;
      FUN_0054ede0(piVar4,0,0);
      piVar3[3] = 0;
      *piVar3 = -1;
      piVar3[1] = -1;
      piVar3[4] = 0;
      piVar3[6] = (int)piVar4;
      piVar3[7] = 1;
      FUN_00401340(iVar1);
      return piVar3;
    }
  }
  FUN_00401340(iVar1);
  piVar3[5] = 0;
  if (param_2 != 0) {
    FUN_0048e0a0();
  }
  return (int *)0x0;
}

