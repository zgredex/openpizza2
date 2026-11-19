// rea decompile_all
// name: FUN_004ec4f0
// address: 0x4ec4f0
// body: available
// range: 0x4ec4f0-0x4ecb21 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004ec4f0(void *this,void *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  char *pcVar10;
  undefined1 local_7d;
  int local_7c;
  int local_78;
  int local_74;
  int local_70 [3];
  char local_64 [100];
  
  local_7d = 0;
  local_70[1] = 0x11;
  CRT_Ostream_Write(param_1,local_70 + 1,4);
  CRT_Ostream_Write(param_1,&param_2,4);
  CRT_Ostream_Write(param_1,(int)this + 0xc,4);
  CRT_Ostream_Write(param_1,(int)this + 0x10,4);
  CRT_Ostream_Write(param_1,(int)this + 0x14,4);
  CRT_Ostream_Write(param_1,(int)this + 0x18,4);
  CRT_Ostream_Write(param_1,(int)this + 0x1c,4);
  CRT_Ostream_Write(param_1,(int)this + 0x20,4);
  CRT_Ostream_Write(param_1,(int)this + 0x24,4);
  CRT_Ostream_Write(param_1,(int)this + 0x28,4);
  CRT_Ostream_Write(param_1,(int)this + 0x2c,4);
  CRT_Ostream_Write(param_1,(int)this + 0x30,4);
  CRT_Ostream_Write(param_1,(int)this + 0x34,4);
  CRT_Ostream_Write(param_1,(int)this + 0x38,4);
  CRT_Ostream_Write(param_1,(int)this + 0x3c,0x10);
  CRT_Ostream_Write(param_1,(int)this + 0x60,4);
  CRT_Ostream_Write(param_1,(int)this + 0x6c,4);
  CRT_Ostream_Write(param_1,(int)this + 0x7c,0x1e);
  CRT_Ostream_Write(param_1,(int)this + 0xba,2);
  CRT_Ostream_Write(param_1,(int)this + 0xf0,4);
  piVar9 = (int *)((int)this + 0xa4);
  CRT_Ostream_Write(param_1,piVar9,4);
  CRT_Ostream_Write(param_1,(int)this + 0xa8,4);
  iVar6 = 0;
  local_78 = 0;
  if (0 < *piVar9) {
    do {
      CRT_Ostream_Write(param_1,*(int *)((int)this + 0x9c) + iVar6,1);
      CRT_Ostream_Write(param_1,*(int *)((int)this + 0x9c) + 2 + iVar6,2);
      CRT_Ostream_Write(param_1,*(int *)((int)this + 0x9c) + 6 + iVar6,1);
      CRT_Ostream_Write(param_1,&local_7d,1);
      CRT_Ostream_Write(param_1,*(int *)((int)this + 0x9c) + 8 + iVar6,4);
      CRT_Ostream_Write(param_1,*(int *)((int)this + 0x9c) + 0xc + iVar6,4);
      CRT_Ostream_Write(param_1,*(int *)((int)this + 0x9c) + 0x10 + iVar6,4);
      CRT_Ostream_Write(param_1,*(int *)((int)this + 0x9c) + 0x14 + iVar6,0x10);
      CRT_Ostream_Write(param_1,*(int *)((int)this + 0x9c) + 0x24 + iVar6,1);
      local_78 = local_78 + 1;
      iVar6 = iVar6 + 0x28;
    } while (local_78 < *piVar9);
  }
  iVar6 = 0;
  if (0 < *(int *)((int)this + 0xa8)) {
    iVar7 = 0;
    do {
      CRT_Ostream_Write(param_1,iVar7 + *(int *)((int)this + 0xa0),1);
      CRT_Ostream_Write(param_1,iVar7 + 2 + *(int *)((int)this + 0xa0),2);
      CRT_Ostream_Write(param_1,iVar7 + 6 + *(int *)((int)this + 0xa0),1);
      CRT_Ostream_Write(param_1,&local_7d,1);
      CRT_Ostream_Write(param_1,iVar7 + 8 + *(int *)((int)this + 0xa0),4);
      CRT_Ostream_Write(param_1,iVar7 + 0xc + *(int *)((int)this + 0xa0),4);
      CRT_Ostream_Write(param_1,iVar7 + 0x10 + *(int *)((int)this + 0xa0),4);
      CRT_Ostream_Write(param_1,iVar7 + 0x14 + *(int *)((int)this + 0xa0),0x10);
      CRT_Ostream_Write(param_1,iVar7 + 0x24 + *(int *)((int)this + 0xa0),1);
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 0x28;
    } while (iVar6 < *(int *)((int)this + 0xa8));
  }
  iVar6 = 0;
  iVar7 = *(int *)((int)this + 0x20) * *(int *)((int)this + 0x1c);
  local_78 = 0;
  if (0 < iVar7) {
    do {
      local_74 = 0;
      if (iVar6 < iVar7) {
        piVar9 = (int *)(*(int *)((int)this + 0x4c) + 8 + iVar6 * 0xc);
        iVar5 = iVar6;
        do {
          iVar2 = *piVar9;
          if ((iVar2 != 0) &&
             (((*(int *)(iVar2 + 4) != -1 || (*(int *)(iVar2 + 0x10) != -1)) ||
              (*(int *)(iVar2 + 0x30) != -1)))) break;
          piVar9 = piVar9 + 3;
          local_74 = local_74 + 1;
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar7);
        if (local_74 < 1) goto LAB_004ec86f;
        local_7c = 1;
        CRT_Ostream_Write(param_1,&local_7c,4);
        CRT_Ostream_Write(param_1,&local_74,4);
        iVar6 = iVar6 + local_74;
        local_78 = iVar6;
      }
      else {
LAB_004ec86f:
        local_7c = 0;
        CRT_Ostream_Write(param_1,&local_7c,4);
      }
      if (local_7c == 0) {
        iVar7 = iVar6 * 0xc;
        local_70[2] = iVar7;
        CRT_Ostream_Write(param_1,*(undefined4 *)(iVar7 + 8 + *(int *)((int)this + 0x4c)),4);
        CRT_Ostream_Write(param_1,*(int *)(iVar7 + 8 + *(int *)((int)this + 0x4c)) + 0x24,2);
        CRT_Ostream_Write(param_1,*(int *)(iVar7 + 8 + *(int *)((int)this + 0x4c)) + 0x30,4);
        CRT_Ostream_Write(param_1,*(int *)(iVar7 + 8 + *(int *)((int)this + 0x4c)) + 0x34,4);
        CRT_Ostream_Write(param_1,*(int *)(iVar7 + 8 + *(int *)((int)this + 0x4c)) + 0x38,4);
        CRT_Ostream_Write(param_1,*(int *)(iVar7 + 8 + *(int *)((int)this + 0x4c)) + 0x28,4);
        CRT_Ostream_Write(param_1,*(int *)(iVar7 + 8 + *(int *)((int)this + 0x4c)) + 0x1c,4);
        CRT_Ostream_Write(param_1,*(int *)(iVar7 + 8 + *(int *)((int)this + 0x4c)) + 0x2c,1);
        CRT_Ostream_Write(param_1,*(int *)(iVar7 + 8 + *(int *)((int)this + 0x4c)) + 0x2d,1);
        CRT_Ostream_Write(param_1,*(int *)(iVar7 + 8 + *(int *)((int)this + 0x4c)) + 0x2e,1);
        CRT_Ostream_Write(param_1,*(int *)(iVar7 + 8 + *(int *)((int)this + 0x4c)) + 0x2f,1);
        if (param_2 == 0) {
          local_70[0] = *(int *)(*(int *)(iVar7 + 8 + *(int *)((int)this + 0x4c)) + 4);
          CRT_Ostream_Write(param_1,local_70,4);
          if (-1 < local_70[0]) {
            uVar3 = 0xffffffff;
            pcVar8 = (char *)(*(int *)((int)this + 4) + 0x25 + local_70[0] * 0x48);
            do {
              pcVar10 = pcVar8;
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              pcVar10 = pcVar8 + 1;
              cVar1 = *pcVar8;
              pcVar8 = pcVar10;
            } while (cVar1 != '\0');
            uVar3 = ~uVar3;
            pcVar8 = pcVar10 + -uVar3;
            pcVar10 = local_64;
            for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
              *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
              pcVar8 = pcVar8 + 4;
              pcVar10 = pcVar10 + 4;
            }
            for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
              *pcVar10 = *pcVar8;
              pcVar8 = pcVar8 + 1;
              pcVar10 = pcVar10 + 1;
            }
            CRT_Ostream_Write(param_1,local_64,0x32);
            iVar6 = local_78;
            iVar7 = local_70[2];
          }
        }
        else {
          CRT_Ostream_Write(param_1,*(int *)(iVar7 + 8 + *(int *)((int)this + 0x4c)) + 4,4);
        }
        if (param_2 == 0) {
          local_70[0] = *(int *)(*(int *)(iVar7 + 8 + *(int *)((int)this + 0x4c)) + 0x10);
          CRT_Ostream_Write(param_1,local_70,4);
          if (-1 < local_70[0]) {
            uVar3 = 0xffffffff;
            pcVar8 = (char *)(*(int *)((int)this + 4) + 0x25 + local_70[0] * 0x48);
            do {
              pcVar10 = pcVar8;
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              pcVar10 = pcVar8 + 1;
              cVar1 = *pcVar8;
              pcVar8 = pcVar10;
            } while (cVar1 != '\0');
            uVar3 = ~uVar3;
            pcVar8 = pcVar10 + -uVar3;
            pcVar10 = local_64;
            for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
              *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
              pcVar8 = pcVar8 + 4;
              pcVar10 = pcVar10 + 4;
            }
            for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
              *pcVar10 = *pcVar8;
              pcVar8 = pcVar8 + 1;
              pcVar10 = pcVar10 + 1;
            }
            CRT_Ostream_Write(param_1,local_64,0x32);
            iVar6 = local_78;
          }
        }
        else {
          CRT_Ostream_Write(param_1,*(int *)(iVar7 + 8 + *(int *)((int)this + 0x4c)) + 0x10,4);
        }
        iVar6 = iVar6 + 1;
        local_78 = iVar6;
      }
      iVar7 = *(int *)((int)this + 0x20) * *(int *)((int)this + 0x1c);
    } while (iVar6 < iVar7);
  }
  if (*(int *)((int)this + 0x118) == 0) {
    local_7c = 0;
    CRT_Ostream_Write(param_1,&local_7c,4);
    return;
  }
  local_7c = 1;
  CRT_Ostream_Write(param_1,&local_7c,4);
  local_7c = **(int **)((int)this + 0x118);
  CRT_Ostream_Write(param_1,&local_7c,4);
  iVar6 = 0;
  if (0 < local_7c + 1) {
    do {
      CRT_Ostream_Write(param_1,*(int *)((int)this + 0x118) + iVar6 * 4,4);
      iVar6 = iVar6 + 1;
    } while (iVar6 < local_7c + 1);
  }
  return;
}

