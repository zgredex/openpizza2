// rea decompile_all
// name: FUN_004aab00
// address: 0x4aab00
// body: available
// range: 0x4aab00-0x4ab5fb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004aab00(void *param_1)

{
  char cVar1;
  void *this;
  uint uVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  char *pcVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  float local_1f8;
  int local_1f4;
  float local_1ec;
  float *local_1e8;
  int local_1e0;
  float local_1dc;
  int local_1d8;
  float local_1d4 [20];
  float local_184 [6];
  char local_16c [256];
  float local_6c [26];
  
  if (DAT_0057d5c8 == 0) {
    local_1f4 = -1;
  }
  else {
    local_1f4 = DAT_0057d5c8 + -1 + (DAT_00569354 - DAT_0057dfbc) * 4;
  }
  this = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  pfVar5 = local_6c;
  for (iVar4 = 0x19; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar5 = 0.0;
    pfVar5 = pfVar5 + 1;
  }
  pfVar5 = local_1d4;
  for (iVar4 = 0x1a; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar5 = 0.0;
    pfVar5 = pfVar5 + 1;
  }
  fVar10 = FUN_004e0df0((int)this,DAT_00569354,local_1f4);
  DAT_0057d574 = (float)fVar10;
  iVar4 = *(int *)((int)this + 0x15c);
  iVar6 = 0;
  if (0 < iVar4) {
    local_1e8 = (float *)&DAT_0057d578;
    do {
      local_1d8 = FUN_004017f0((void *)((int)this + 0x148),iVar6,(int *)0x0);
      fVar10 = FUN_00477fe0(local_1d8,-1,DAT_00569354,local_1f4);
      fVar11 = FUN_00478090(local_1d8,-1,DAT_00569354,local_1f4);
      uVar2 = FUN_004aaac0();
      if ((char)uVar2 != '\0') {
        fVar12 = FUN_00477fe0(local_1d8,-1,DAT_00569354,
                              (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10));
        fVar13 = FUN_00478090(local_1d8,-1,DAT_00569354,
                              (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10));
        DAT_0057d574 = (float)((float10)DAT_0057d574 + ((float10)(float)fVar12 - fVar13));
      }
      iVar6 = iVar6 + 1;
      *local_1e8 = (float)fVar10 - (float)fVar11;
      local_1e8 = local_1e8 + 1;
    } while (iVar6 < iVar4);
  }
  local_1f8 = 0.0;
  local_1ec = 0.0;
  if ((DAT_00569358 < 0) ||
     (local_1d8 = FUN_004017f0((void *)((int)this + 0x148),DAT_00569358,(int *)0x0), local_1d8 != 0)
     ) {
    iVar4 = 0;
    do {
      FUN_005316b0(param_1,*(int *)((int)&DAT_00569420 + iVar4));
      FUN_005316b0(param_1,*(int *)((int)&DAT_00569488 + iVar4));
      iVar4 = iVar4 + 4;
    } while (iVar4 < 0x54);
    if (DAT_00569358 == -1) {
      local_1e8 = (float *)0x0;
      local_1dc = 0.0;
      iVar6 = 0;
      iVar4 = *(int *)((int)this + 0x15c);
      do {
        fVar10 = FUN_004e0aa0((int)this,iVar6,DAT_00569354,local_1f4);
        local_6c[iVar6] = (float)fVar10;
        uVar2 = FUN_004aaac0();
        if (((char)uVar2 != '\0') && (iVar7 = 0, 0 < iVar4)) {
          do {
            iVar3 = FUN_004017f0((void *)((int)this + 0x148),iVar7,(int *)0x0);
            fVar10 = FUN_00478090(iVar3,iVar6,DAT_00569354,
                                  (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10));
            iVar7 = iVar7 + 1;
            local_6c[iVar6] = (float)(fVar10 + (float10)local_6c[iVar6]);
          } while (iVar7 < iVar4);
        }
        local_1ec = local_1ec + local_6c[iVar6];
        FUN_0054dd83(local_16c,(byte *)s___2f___005683d4,SUB84((double)local_6c[iVar6],0));
        FUN_0052f9b0(param_1,(&DAT_005693bc)[iVar6],local_16c);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0x19);
      piVar8 = &DAT_0056940c;
      do {
        FUN_005316b0(param_1,*piVar8);
        piVar8 = piVar8 + 1;
      } while ((int)piVar8 < 0x569420);
      FUN_005316b0(param_1,DAT_005693c8);
      FUN_005316b0(param_1,0x418);
      FUN_005316b0(param_1,0x43a);
      FUN_005316b0(param_1,0x43d);
      FUN_005316b0(param_1,0x1f44);
      FUN_005316b0(param_1,0x1f42);
      FUN_005316b0(param_1,0x43e);
      uVar2 = FUN_004aaac0();
      if ((char)uVar2 == '\0') {
        if (local_1f4 == -1) {
          local_1f4 = -2;
        }
        iVar4 = 0;
        do {
          iVar6 = FUN_004e0880(this,iVar4,DAT_00569354,local_1f4);
          FUN_0054dd83(local_16c,&DAT_005630d0,iVar6);
          FUN_0052f9b0(param_1,(&DAT_00569488)[iVar4],local_16c);
          fVar10 = FUN_004e09e0((int)this,iVar4,DAT_00569354,local_1f4);
          local_1d4[iVar4] = (float)fVar10;
          iVar6 = -1;
          pcVar9 = local_16c;
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            cVar1 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar1 != '\0');
          local_1f8 = (float)(fVar10 + (float10)local_1f8);
          if (iVar6 != -3) {
            FUN_0054dd83(local_16c,(byte *)s___2f___005683d4,SUB84((double)fVar10,0));
          }
          FUN_0052f9b0(param_1,(&DAT_00569420)[iVar4],local_16c);
          iVar4 = iVar4 + 1;
        } while (iVar4 < 0x14);
        iVar4 = 0x14;
        pfVar5 = local_184;
        do {
          fVar10 = FUN_004e09e0((int)this,iVar4,DAT_00569354,local_1f4);
          *pfVar5 = (float)fVar10;
          iVar4 = iVar4 + 1;
          pfVar5 = pfVar5 + 1;
          local_1f8 = (float)(fVar10 + (float10)local_1f8);
        } while (iVar4 < 0x1a);
      }
      else {
        iVar6 = 0;
        if (0 < iVar4) {
          do {
            iVar7 = FUN_004017f0((void *)((int)this + 0x148),iVar6,(int *)0x0);
            fVar10 = FUN_00477fe0(iVar7,-1,DAT_00569354,local_1f4);
            local_1d4[iVar6] = (float)fVar10;
            fVar11 = FUN_00477f50(iVar7,DAT_00569354,local_1f4);
            local_1e8 = (float *)((float)fVar10 + (float)local_1e8);
            local_1f8 = (float)fVar10 + local_1f8;
            fVar10 = FUN_00477fe0(iVar7,-1,DAT_00569354,
                                  (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10));
            local_1dc = (float)(fVar10 + (float10)local_1dc);
            FUN_0054dd83(local_16c,(byte *)s___2f___005683d4,SUB84((double)(float)fVar11,0));
            FUN_0052f9b0(param_1,(&DAT_00569420)[iVar6],local_16c);
            FUN_0052f9b0(param_1,(&DAT_00569488)[iVar6],iVar7 + 4);
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar4);
        }
        if (iVar4 < 0x14) {
          iVar6 = iVar4 * 4;
          do {
            UI_RemoveObjectByKey(param_1,*(int *)((int)&DAT_00569420 + iVar6));
            UI_RemoveObjectByKey(param_1,*(int *)((int)&DAT_00569488 + iVar6));
            iVar6 = iVar6 + 4;
          } while (iVar6 < 0x50);
        }
        iVar6 = 0;
        do {
          fVar10 = FUN_004e09e0((int)this,iVar6,DAT_00569354,local_1f4);
          iVar6 = iVar6 + 1;
          local_1dc = (float)(fVar10 + (float10)local_1dc);
        } while (iVar6 < 0x14);
        iVar6 = 0x14;
        local_1e0 = 0;
        do {
          fVar10 = FUN_004e09e0((int)this,iVar6,DAT_00569354,local_1f4);
          iVar7 = 0;
          *(float *)((int)local_184 + local_1e0) = (float)fVar10;
          if (0 < iVar4) {
            do {
              iVar3 = FUN_004017f0((void *)((int)this + 0x148),iVar7,(int *)0x0);
              fVar10 = FUN_00477fe0(iVar3,iVar6,DAT_00569354,
                                    (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10));
              iVar7 = iVar7 + 1;
              *(float *)((int)local_184 + local_1e0) =
                   (float)(fVar10 + (float10)*(float *)((int)local_184 + local_1e0));
            } while (iVar7 < iVar4);
          }
          local_1f8 = local_1f8 + *(float *)((int)local_184 + local_1e0);
          FUN_0054dd83(local_16c,(byte *)s___2f___005683d4,
                       SUB84((double)*(float *)((int)local_184 + local_1e0),0));
          FUN_0052f9b0(param_1,*(int *)((int)&DAT_00569470 + local_1e0),local_16c);
          local_1e0 = local_1e0 + 4;
          iVar6 = iVar6 + 1;
        } while (local_1e0 < 0x18);
        if (0.0 < local_1dc - (float)local_1e8) {
          local_184[0] = local_184[0] + (local_1dc - (float)local_1e8);
        }
      }
      FUN_0054dd83(local_16c,(byte *)s___2f___005683d4,SUB84((double)local_184[0],0));
      FUN_0052f9b0(param_1,DAT_00569470,local_16c);
      FUN_005316b0(param_1,DAT_00569484);
      FUN_005316b0(param_1,DAT_00569480);
      FUN_005316b0(param_1,0x4a4);
      FUN_005316b0(param_1,0x4a7);
      iVar4 = 0;
      do {
        FUN_0054dd83(local_16c,(byte *)s___2f___005683d4,
                     SUB84((double)*(float *)((int)local_184 + iVar4 + 4),0));
        FUN_0052f9b0(param_1,*(int *)((int)&DAT_00569474 + iVar4),local_16c);
        iVar4 = iVar4 + 4;
      } while (iVar4 < 0x14);
    }
    else {
      iVar4 = 0;
      do {
        fVar10 = FUN_00478090(local_1d8,iVar4,DAT_00569354,local_1f4);
        local_6c[iVar4] = (float)fVar10;
        local_1ec = (float)(fVar10 + (float10)local_1ec);
        FUN_0054dd83(local_16c,(byte *)s___2f___005683d4,SUB84((double)fVar10,0));
        FUN_0052f9b0(param_1,(&DAT_005693bc)[iVar4],local_16c);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0x14);
      UI_RemoveObjectByKey(param_1,DAT_005693c8);
      piVar8 = &DAT_0056940c;
      do {
        UI_RemoveObjectByKey(param_1,*piVar8);
        piVar8 = piVar8 + 1;
      } while ((int)piVar8 < 0x569420);
      UI_RemoveObjectByKey(param_1,0x418);
      UI_RemoveObjectByKey(param_1,0x43a);
      UI_RemoveObjectByKey(param_1,0x43d);
      UI_RemoveObjectByKey(param_1,0x1f44);
      UI_RemoveObjectByKey(param_1,0x1f42);
      UI_RemoveObjectByKey(param_1,0x43e);
      iVar4 = 0;
      do {
        fVar10 = FUN_00477fe0(local_1d8,iVar4,DAT_00569354,local_1f4);
        local_1f8 = (float)(fVar10 + (float10)local_1f8);
        FUN_0054dd83(local_16c,(byte *)s___2f___005683d4,SUB84((double)fVar10,0));
        FUN_0052f9b0(param_1,(&DAT_00569420)[iVar4],local_16c);
        FUN_0052f9b0(param_1,(&DAT_00569488)[iVar4],(&DAT_005834d4)[iVar4]);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 9);
      iVar4 = 0;
      do {
        UI_RemoveObjectByKey(param_1,*(int *)((int)&DAT_00569444 + iVar4));
        UI_RemoveObjectByKey(param_1,*(int *)((int)&DAT_005694ac + iVar4));
        iVar4 = iVar4 + 4;
      } while (iVar4 < 0x30);
      local_1e8 = (float *)0x15;
      iVar4 = 0;
      do {
        fVar10 = FUN_00477fe0(local_1d8,(int)local_1e8,DAT_00569354,local_1f4);
        *(float *)((int)local_184 + iVar4 + 4) = (float)fVar10;
        local_1f8 = (float)(fVar10 + (float10)local_1f8);
        FUN_0054dd83(local_16c,(byte *)s___2f___005683d4,SUB84((double)fVar10,0));
        FUN_0052f9b0(param_1,*(int *)((int)&DAT_00569474 + iVar4),local_16c);
        iVar4 = iVar4 + 4;
        local_1e8 = (float *)((int)local_1e8 + 1);
      } while (iVar4 < 0x14);
      UI_RemoveObjectByKey(param_1,0x4a4);
      UI_RemoveObjectByKey(param_1,0x4a7);
      UI_RemoveObjectByKey(param_1,DAT_00569484);
      UI_RemoveObjectByKey(param_1,DAT_00569480);
    }
    if (local_1ec <= local_1f8) {
      FUN_0054dd83(local_16c,(byte *)s___2f___005683d4,SUB84((double)(local_1f8 - local_1ec),0));
      FUN_0052f9b0(param_1,0x441,local_16c);
      FUN_0052f9b0(param_1,0x440,DAT_00582d8c);
      FUN_0052f910(param_1,0x441,0xa000);
      FUN_0052f910(param_1,0x440,0xa000);
      FUN_0052f9b0(param_1,0x4ab,DAT_00582e4c);
      FUN_0052f9b0(param_1,0x4aa,DAT_00582e4c);
      local_1ec = local_1f8;
    }
    else {
      FUN_0054dd83(local_16c,(byte *)s___2f___005683d4,SUB84((double)(local_1ec - local_1f8),0));
      FUN_0052f910(param_1,0x4ab,0xff);
      FUN_0052f910(param_1,0x4aa,0xff);
      FUN_0052f9b0(param_1,0x4ab,local_16c);
      FUN_0052f9b0(param_1,0x4aa,DAT_00582554);
      FUN_0052f9b0(param_1,0x440,DAT_00582e4c);
      FUN_0052f9b0(param_1,0x441,DAT_00582e4c);
    }
    FUN_0054dd83(local_16c,(byte *)s___2f___005683d4,SUB84((double)local_1ec,0));
    FUN_0052f9b0(param_1,0x4b1,local_16c);
    FUN_0052f9b0(param_1,0x4af,local_16c);
    FUN_004aa970(param_1,DAT_0057d5d4);
  }
  return;
}

