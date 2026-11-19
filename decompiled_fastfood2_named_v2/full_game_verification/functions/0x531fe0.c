// rea decompile_all
// name: Dialog_SaveToFile
// address: 0x531fe0
// body: available
// range: 0x531fe0-0x5321e9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall Dialog_SaveToFile(void *this,LPCSTR param_1)

{
  char cVar1;
  FILE *pFVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  uint local_45c;
  int local_458;
  char local_454 [8];
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 local_438;
  undefined4 local_434;
  char local_430 [1036];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  pFVar2 = (FILE *)CRT_Fopen(param_1,&DAT_00563114);
  if (pFVar2 == (FILE *)0x0) {
    return 0;
  }
  local_458 = *(int *)((int)this + 0xf0) + 1;
  CRT_FwriteLocked((char *)&local_458,1,4,(int *)pFVar2);
  local_1c = *(undefined4 *)((int)this + 0x104);
  pcVar6 = local_454;
  for (iVar3 = 0x115; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = pcVar6 + 4;
  }
  local_20 = *(undefined4 *)((int)this + 0x100);
  local_454[0] = 'T';
  local_454[1] = '\x04';
  local_454[2] = '\0';
  local_454[3] = '\0';
  local_45c = 0x454;
  local_24 = *(undefined4 *)((int)this + 0xfc);
  local_18 = *(undefined4 *)((int)this + 0x108);
  if (*(int *)((int)this + 0x168) == 0) {
    if (*(int *)((int)this + 0x114) == 0) {
      if (*(int *)((int)this + 0x138) == 0) {
        if (*(int *)((int)this + 0x94) == 0) {
          local_44c = 1;
        }
        else {
          uVar4 = 0xffffffff;
          local_44c = 2;
          local_434 = 3;
          pcVar6 = *(char **)((int)this + 0xf8);
          do {
            pcVar7 = pcVar6;
            if (uVar4 == 0) break;
            uVar4 = uVar4 - 1;
            pcVar7 = pcVar6 + 1;
            cVar1 = *pcVar6;
            pcVar6 = pcVar7;
          } while (cVar1 != '\0');
          uVar4 = ~uVar4;
          pcVar6 = pcVar7 + -uVar4;
          pcVar7 = local_430;
          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
            pcVar6 = pcVar6 + 4;
            pcVar7 = pcVar7 + 4;
          }
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *pcVar7 = *pcVar6;
            pcVar6 = pcVar6 + 1;
            pcVar7 = pcVar7 + 1;
          }
        }
      }
      else {
        uVar4 = 0xffffffff;
        local_44c = 4;
        local_434 = 2;
        pcVar6 = *(char **)((int)this + 0xf8);
        do {
          pcVar7 = pcVar6;
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          pcVar7 = pcVar6 + 1;
          cVar1 = *pcVar6;
          pcVar6 = pcVar7;
        } while (cVar1 != '\0');
        uVar4 = ~uVar4;
        pcVar6 = pcVar7 + -uVar4;
        pcVar7 = local_430;
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
          pcVar6 = pcVar6 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar7 = *pcVar6;
          pcVar6 = pcVar6 + 1;
          pcVar7 = pcVar7 + 1;
        }
      }
    }
    else {
      local_44c = 0;
    }
  }
  else {
    uVar4 = 0xffffffff;
    local_44c = 3;
    local_434 = 0xc;
    pcVar6 = *(char **)((int)this + 0xf8);
    do {
      pcVar7 = pcVar6;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar7 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar7;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar6 = pcVar7 + -uVar4;
    pcVar7 = local_430;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar7 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
    }
  }
  local_444 = *(undefined4 *)((int)this + 0x2c);
  local_448 = *(undefined4 *)((int)this + 0x28);
  local_440 = *(undefined4 *)((int)this + 0x30);
  local_43c = *(undefined4 *)((int)this + 0x34);
  iVar3 = 0;
  local_438 = 0;
  CRT_FwriteLocked((char *)&local_45c,1,4,(int *)pFVar2);
  CRT_FwriteLocked(local_454,1,local_45c,(int *)pFVar2);
  if (0 < *(int *)((int)this + 0xf0)) {
    do {
      Dialog_WriteChildRecord(*(int **)(*(int *)((int)this + 0xec) + iVar3 * 8));
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)((int)this + 0xf0));
  }
  CRT_Fclose(pFVar2);
  return 1;
}

