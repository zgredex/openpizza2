// rea decompile_all
// name: Sound_PlayStatusAdvisory
// address: 0x548ed0
// body: available
// range: 0x548ed0-0x54906c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Removing unreachable block (ram,0x00548f15) */

void __fastcall Sound_PlayStatusAdvisory(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if ((((*(char *)((int)param_1 + 0xfc) != '\0') && (*(char *)((int)param_1 + 0x100) == '\0')) &&
      (DAT_0057c670 != 0)) && ((*(byte *)(*(int *)(DAT_0057c670 + 0x94) + 7) & 3) == 0)) {
    iVar5 = 0;
    iVar1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
    iVar2 = *(int *)(iVar1 + 0x15c);
    if (0 < iVar2) {
      this = (void *)(iVar1 + 0x148);
      do {
        iVar4 = IDMap_Lookup(this,iVar5,(int *)0x0);
        uVar3 = *(uint *)(iVar4 + 0x28);
        if ((uVar3 & 2) != 0) {
          Sound_PlaySpeechStatement(param_1,0x1c);
          return;
        }
        if ((uVar3 & 4) != 0) {
          Sound_PlaySpeechStatement(param_1,0x1b);
          return;
        }
        if ((uVar3 & 0x20) != 0) {
          Sound_PlaySpeechStatement(param_1,0x1e);
          return;
        }
        if ((uVar3 & 0x10) != 0) {
          Sound_PlaySpeechStatement(param_1,0x1f);
          return;
        }
        iVar4 = IDMap_Lookup(this,iVar5,(int *)0x0);
        if (*(int *)(iVar4 + 0x1a24) != 0) {
          Sound_PlaySpeechStatement(param_1,0x1d);
          return;
        }
        iVar4 = IDMap_Lookup(this,iVar5,(int *)0x0);
        iVar4 = Rating_GetInverse100(iVar4);
        if (iVar4 < 10) {
          Sound_PlaySpeechStatement(param_1,8);
          return;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar2);
    }
    iVar2 = *(int *)(iVar1 + 0x194);
    iVar5 = 0;
    if (0 < iVar2) {
      while (iVar4 = IDMap_Lookup((void *)(iVar1 + 0x180),iVar5,(int *)0x0),
            *(int *)(iVar4 + 0x30) != -1) {
        iVar5 = iVar5 + 1;
        if (iVar2 <= iVar5) {
          return;
        }
      }
      Sound_PlaySpeechStatement(param_1,0x20);
    }
  }
  return;
}

