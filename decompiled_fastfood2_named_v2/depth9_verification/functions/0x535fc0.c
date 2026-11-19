// rea decompile_all
// name: FUN_00535fc0
// address: 0x535fc0
// body: available
// range: 0x535fc0-0x536134 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
FUN_00535fc0(void *this,char *param_1,void *param_2,void *param_3,undefined4 *param_4,
            undefined *param_5)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  FILE *pFVar6;
  FILE local_104 [8];
  
  *(undefined ***)this = &PTR_FUN_0055c814;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  uVar4 = 0xffffffff;
  do {
    pcVar2 = param_1;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar2 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar2;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar2 = pcVar2 + -uVar4;
  pFVar6 = local_104;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    pFVar6->_ptr = *(char **)pcVar2;
    pcVar2 = pcVar2 + 4;
    pFVar6 = (FILE *)&pFVar6->_cnt;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(char *)&pFVar6->_ptr = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pFVar6 = (FILE *)((int)&pFVar6->_ptr + 1);
  }
  FUN_0054f775((uint *)local_104);
  pcVar2 = _strstr((char *)local_104,&DAT_00574688);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = _strstr((char *)local_104,&DAT_00574680);
    if (pcVar2 == (char *)0x0) {
      pcVar2 = _strstr((char *)local_104,&DAT_00574678);
      if (pcVar2 == (char *)0x0) goto LAB_005360d1;
      iVar3 = FullscreenImage_LoadBmp(this,param_2,local_104,param_3,param_5);
    }
    else {
      iVar3 = FUN_00536ab0(this,(int)param_2,(char *)local_104,param_3);
    }
  }
  else {
    iVar3 = FUN_00536350(this,(int)param_2,(char *)local_104,param_3,param_5);
  }
  if (iVar3 != 0) {
    if ((*(char *)((int)this + 0x11) == '\x02') && (param_2 != (void *)0x0)) {
      FUN_00539340(param_2,*(ushort **)((int)this + 0x18),
                   *(int *)((int)this + 8) * *(int *)((int)this + 4));
    }
    return this;
  }
LAB_005360d1:
  if (param_4 == (undefined4 *)0x0) {
    FUN_0048e0a0();
    return this;
  }
  *param_4 = 0x1f5;
  return this;
}

