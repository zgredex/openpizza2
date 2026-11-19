// rea decompile_all
// name: FUN_00535180
// address: 0x535180
// body: available
// range: 0x535180-0x5354d2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


char * __thiscall
FUN_00535180(void *this,undefined4 param_1,void *param_2,LPCSTR param_3,undefined4 *param_4)

{
  uint *puVar1;
  short sVar2;
  FILE *pFVar3;
  byte *pbVar4;
  short *psVar5;
  char *pcVar6;
  int *piVar7;
  short *psVar8;
  int iVar9;
  uint local_4;
  
  local_4 = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  *(undefined4 *)((int)this + 0x460) = 0;
  if (param_2 == (void *)0x0) {
    pFVar3 = (FILE *)FUN_0054dfe0(param_3,&DAT_00563184);
    if (pFVar3 == (FILE *)0x0) {
      if (param_4 == (undefined4 *)0x0) {
        NoOp_Stub();
        return this;
      }
      *param_4 = 0x321;
      return this;
    }
    Set_Field9B8(this,0xffffff);
    FUN_0054e978(this,1,0xe0,(int *)pFVar3);
    pbVar4 = (byte *)((int)this + 0xe0);
    FUN_0054e978((char *)pbVar4,1,0xe0,(int *)pFVar3);
    do {
      if ((0x80 < pbVar4[-0xe0]) || (0x80 < *pbVar4)) {
        if (param_4 == (undefined4 *)0x0) {
          NoOp_Stub();
          return this;
        }
        *param_4 = 0x321;
        return this;
      }
      pbVar4 = pbVar4 + 1;
    } while ((int)(pbVar4 + (-0xe0 - (int)this)) < 0xe0);
    FUN_0054e978((char *)((int)this + 0x2a0),1,0xe0,(int *)pFVar3);
    FUN_0054e978((char *)((int)this + 0x380),1,0xe0,(int *)pFVar3);
    psVar8 = (short *)((int)this + 0x7e0);
    FUN_0054e978((char *)psVar8,1,0x1c0,(int *)pFVar3);
    FUN_0054e978((char *)((int)this + 0x1c0),1,0xe0,(int *)pFVar3);
    puVar1 = (uint *)((int)this + 0x9b0);
    FUN_0054e978((char *)puVar1,1,4,(int *)pFVar3);
    *(int *)((int)this + 0x9b4) = (int)*puVar1 >> 0x10;
    *puVar1 = *puVar1 & 0xffff;
    iVar9 = 0xe0;
    psVar5 = psVar8;
    do {
      sVar2 = *psVar5;
      psVar5 = psVar5 + 1;
      local_4 = local_4 + (int)sVar2;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    pcVar6 = operator_new(local_4);
    *(char **)((int)this + 0x460) = pcVar6;
    FUN_0054e978(pcVar6,1,local_4,(int *)pFVar3);
    FUN_0054dee4(pFVar3);
    piVar7 = (int *)((int)this + 0x464);
    iVar9 = 0xdf;
    do {
      sVar2 = *psVar8;
      psVar8 = psVar8 + 1;
      *piVar7 = piVar7[-1] + (int)sVar2;
      piVar7 = piVar7 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    iVar9 = *(int *)((int)this + 0x9b4);
  }
  else {
    piVar7 = FUN_00402290(param_2,param_3,0);
    if (piVar7 == (int *)0x0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 0x321;
        return this;
      }
      NoOp_Stub();
    }
    Set_Field9B8(this,0xffffff);
    FUN_00402750(param_2,this,0xe0,(int)piVar7);
    FUN_00402750(param_2,(char *)((int)this + 0xe0),0xe0,(int)piVar7);
    FUN_00402750(param_2,(char *)((int)this + 0x2a0),0xe0,(int)piVar7);
    FUN_00402750(param_2,(char *)((int)this + 0x380),0xe0,(int)piVar7);
    FUN_00402750(param_2,(char *)((int)this + 0x7e0),0x1c0,(int)piVar7);
    FUN_00402750(param_2,(char *)((int)this + 0x1c0),0xe0,(int)piVar7);
    puVar1 = (uint *)((int)this + 0x9b0);
    FUN_00402750(param_2,(char *)puVar1,4,(int)piVar7);
    *(int *)((int)this + 0x9b4) = (int)*puVar1 >> 0x10;
    *puVar1 = *puVar1 & 0xffff;
    psVar8 = (short *)((int)this + 0x7e0);
    iVar9 = 0xe0;
    do {
      sVar2 = *psVar8;
      psVar8 = psVar8 + 1;
      local_4 = local_4 + (int)sVar2;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    pcVar6 = operator_new(local_4);
    *(char **)((int)this + 0x460) = pcVar6;
    FUN_00402750(param_2,pcVar6,local_4,(int)piVar7);
    FUN_00402990(param_2,(int)piVar7);
    piVar7 = (int *)((int)this + 0x464);
    psVar8 = (short *)((int)this + 0x7e0);
    iVar9 = 0xdf;
    do {
      sVar2 = *psVar8;
      psVar8 = psVar8 + 1;
      *piVar7 = piVar7[-1] + (int)sVar2;
      piVar7 = piVar7 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    iVar9 = *(int *)((int)this + 0x9b4);
  }
  if (iVar9 == 0) {
    *(uint *)((int)this + 0x9b4) =
         (uint)*(byte *)((int)this + 0x3a9) + (uint)*(byte *)((int)this + 0x109);
  }
  return this;
}

