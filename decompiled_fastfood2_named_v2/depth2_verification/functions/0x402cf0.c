// rea decompile_all
// name: FUN_00402cf0
// address: 0x402cf0
// body: available
// range: 0x402cf0-0x402eeb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall FUN_00402cf0(void *this,void *param_1,char *param_2,undefined4 *param_3)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  char *pcVar6;
  byte *pbVar7;
  bool bVar8;
  byte local_100 [256];
  
  *(undefined ***)this = &PTR_FUN_0055c2f4;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  *(undefined2 *)((int)this + 0x14) = 0;
  *(undefined2 *)((int)this + 0x12) = 0;
  *(undefined2 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  piVar2 = FUN_00402290(param_1,param_2,0);
  if (piVar2 == (int *)0x0) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0x2bd;
      return this;
    }
    FUN_0048e0a0();
  }
  iVar5 = -1;
LAB_00402d6f:
  do {
    while( true ) {
      do {
        iVar3 = FUN_00402840(param_1,local_100,0x100,(int)piVar2);
        if (iVar3 == -1) {
          FUN_00402990(param_1,(int)piVar2);
          if (((*(int *)((int)this + 4) == 0) || (*(int *)((int)this + 8) == 0)) ||
             (*(int *)((int)this + 0xc) == 0)) {
            if (param_3 != (undefined4 *)0x0) {
              *param_3 = 0x2be;
              return this;
            }
            FUN_0048e0a0();
          }
          CRT_QSort(*(int **)((int)this + 0xc),(undefined4 *)(int)*(short *)((int)this + 0x14),0x10,
                    _strcmp);
          return this;
        }
      } while (((local_100[0] == 0) || (local_100[0] == 0x5c)) || (local_100[0] == 0x2f));
      if (local_100[0] == 0x5b) break;
      FUN_00402f10(this,(char *)local_100,iVar5);
    }
    pcVar6 = s__SURNAME_FEMALE__005632d8;
    pbVar4 = local_100;
    do {
      bVar1 = *pbVar4;
      bVar8 = bVar1 < (byte)*pcVar6;
      if (bVar1 != *pcVar6) {
LAB_00402dda:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_00402ddf;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar8 = bVar1 < (byte)pcVar6[1];
      if (bVar1 != pcVar6[1]) goto LAB_00402dda;
      pbVar4 = pbVar4 + 2;
      pcVar6 = pcVar6 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_00402ddf:
    if (iVar3 == 0) {
      iVar5 = 0;
      goto LAB_00402d6f;
    }
    pcVar6 = s__SURNAME_MALE__005632c8;
    pbVar4 = local_100;
    do {
      bVar1 = *pbVar4;
      bVar8 = bVar1 < (byte)*pcVar6;
      if (bVar1 != *pcVar6) {
LAB_00402e14:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_00402e19;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar8 = bVar1 < (byte)pcVar6[1];
      if (bVar1 != pcVar6[1]) goto LAB_00402e14;
      pbVar4 = pbVar4 + 2;
      pcVar6 = pcVar6 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_00402e19:
    if (iVar3 == 0) {
      iVar5 = 1;
    }
    else {
      pbVar7 = &DAT_005632c0;
      pbVar4 = local_100;
      do {
        bVar1 = *pbVar4;
        bVar8 = bVar1 < *pbVar7;
        if (bVar1 != *pbVar7) {
LAB_00402e54:
          iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_00402e59;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar8 = bVar1 < pbVar7[1];
        if (bVar1 != pbVar7[1]) goto LAB_00402e54;
        pbVar4 = pbVar4 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_00402e59:
      if (iVar3 == 0) {
        iVar5 = 2;
      }
    }
  } while( true );
}

